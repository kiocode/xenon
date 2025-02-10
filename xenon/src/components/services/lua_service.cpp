#include <xenon/components/services/lua_service.hpp>
#include <xenon/components/services/memory_service.hpp>

void CLuaService::Update() {
	#pragma region Trigger Update In Lua Scripts
	sol::function on_update = lua["onUpdate"];
    if (on_update.valid()) {
        sol::protected_function_result result = on_update();

        if (!result.valid()) {
            sol::error err = result;
            std::cerr << "Lua error occurred in OnUpdate: " << err.what() << std::endl;
        }
    }
	#pragma endregion

    if (g_pXenonVariables->g_bShowMenu && g_pXenonVariables->g_bLuaEditor) {
	    RenderLuaEditor();
    }

}

void CLuaService::RegisterBinds() {
    lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::string, sol::lib::table, sol::lib::math, sol::lib::os, sol::lib::io);

    lua.set_function("beginWindow", [](const char* title) { ImGui::Begin(title); });
    lua.set_function("endWindow", []() { ImGui::End(); });
    lua.set_function("setCursorPos", [](float x, float y) { ImGui::SetCursorPos(ImVec2(x, y)); });
    lua.set_function("sameLine", []() { ImGui::SameLine(); });

    lua.set_function("drawText", [](const char* text) { ImGui::Text("%s", text); });
    lua.set_function("drawTextWrapped", [](const char* text) { ImGui::TextWrapped("%s", text); });

    lua.set_function("createButton", [](const char* label) { return ImGui::Button(label); });

    lua.new_usertype<ImVec2>("ImVec2",
        sol::constructors<ImVec2(float, float)>(),
        "x", &ImVec2::x,
        "y", &ImVec2::y
    );

    lua.new_usertype<ImColor>("ImColor",
        sol::constructors<ImColor(), ImColor(int, int, int, int), ImColor(float, float, float, float)>(),
        "toU32", &ImColor::operator ImU32,
        "toVec4", &ImColor::operator ImVec4
    );

    lua.new_usertype<ImDrawList>("ImDrawList",
        "drawLine", &ImDrawList::AddLine,
        "drawRect", &ImDrawList::AddRect,
        "drawRectFilled", &ImDrawList::AddRectFilled,
        "drawQuad", &ImDrawList::AddQuad,
        "drawQuadFilled", &ImDrawList::AddQuadFilled,
        "drawTriangle", &ImDrawList::AddTriangle,
        "drawTriangleFilled", &ImDrawList::AddTriangleFilled,
        "drawCircle", &ImDrawList::AddCircle,
        "drawCircleFilled", &ImDrawList::AddCircleFilled,
        "drawNgon", &ImDrawList::AddNgon,
        "drawNgonFilled", &ImDrawList::AddNgonFilled,
        "drawPolyline", &ImDrawList::AddPolyline,
        "drawConvexPolyFilled", &ImDrawList::AddConvexPolyFilled,
        "drawBezierCubic", &ImDrawList::AddBezierCubic,
        "drawBezierQuadratic", &ImDrawList::AddBezierQuadratic,
        "drawImage", &ImDrawList::AddImage,
        "drawImageQuad", &ImDrawList::AddImageQuad,
        "drawImageRounded", &ImDrawList::AddImageRounded,
        "pathClear", &ImDrawList::PathClear,
        "pathLineTo", &ImDrawList::PathLineTo,
        "pathLineToMergeDuplicate", &ImDrawList::PathLineToMergeDuplicate,
        "pathFillConvex", &ImDrawList::PathFillConvex,
        "pathStroke", &ImDrawList::PathStroke,
        "pathArcTo", &ImDrawList::PathArcTo,
        "pathArcToFast", &ImDrawList::PathArcToFast,
        "pathBezierCubicCurveTo", &ImDrawList::PathBezierCubicCurveTo,
        "pathBezierQuadraticCurveTo", &ImDrawList::PathBezierQuadraticCurveTo,
        "pathRect", &ImDrawList::PathRect
    );

    lua.set_function("getDrawList", []() { return ImGui::GetBackgroundDrawList(); });

    spdlog::debug("CLuaService::RegisterBinds() - Binds registered");
}

sol::protected_function_result CLuaService::ExecuteScript(std::string script) {
    sol::protected_function_result result = lua.script(script);

	spdlog::debug("CLuaService::ExecuteScript() - Script executed");

    return result;
}

void CLuaService::ExecuteScriptFile(std::string path) {

}

void CLuaService::RenderLuaEditor() {

    if (ImGui::IsKeyPressed(ImGuiKey_LeftShift) || ImGui::IsKeyPressed(ImGuiKey_RightShift)) {
        ImGui::GetIO().WantTextInput = false;
    }

    auto cpos = editor.GetCursorPosition();

    ImGui::Begin("Lua Script Editor", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Execute")) {
                auto script = editor.GetText();
                ExecuteScript(script);
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit")) {
            bool ro = editor.IsReadOnly();
            if (ImGui::MenuItem("Read-only mode", nullptr, &ro))
                editor.SetReadOnly(ro);
            ImGui::Separator();

            if (ImGui::MenuItem("Undo", "Ctrl-Z", nullptr, !ro && editor.CanUndo()))
                editor.Undo();
            if (ImGui::MenuItem("Redo", "Ctrl-Y", nullptr, !ro && editor.CanRedo()))
                editor.Redo();

            ImGui::Separator();

            if (ImGui::MenuItem("Copy", "Ctrl-C", nullptr, editor.HasSelection()))
                editor.Copy();
            if (ImGui::MenuItem("Cut", "Ctrl-X", nullptr, !ro && editor.HasSelection()))
                editor.Cut();
            if (ImGui::MenuItem("Delete", "Del", nullptr, !ro && editor.HasSelection()))
                editor.Delete();
            if (ImGui::MenuItem("Paste", "Ctrl-V", nullptr, !ro && ImGui::GetClipboardText() != nullptr))
                editor.Paste();

            ImGui::Separator();

            if (ImGui::MenuItem("Select all", nullptr, nullptr))
                editor.SetSelection(TextEditor::Coordinates(), TextEditor::Coordinates(editor.GetTotalLines(), 0));

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("View")) {
            if (ImGui::MenuItem("Dark palette"))
                editor.SetPalette(TextEditor::GetDarkPalette());
            if (ImGui::MenuItem("Light palette"))
                editor.SetPalette(TextEditor::GetLightPalette());
            if (ImGui::MenuItem("Retro blue palette"))
                editor.SetPalette(TextEditor::GetRetroBluePalette());
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::Text("%6d/%-6d %6d lines  | %s | %s | %s",
        cpos.mLine + 1, cpos.mColumn + 1, editor.GetTotalLines(),
        editor.IsOverwrite() ? "Ovr" : "Ins",
        editor.CanUndo() ? "*" : " ",
        editor.GetLanguageDefinition().mName.c_str());

    editor.Render("LuaEditor");

    ImGui::End();
}
