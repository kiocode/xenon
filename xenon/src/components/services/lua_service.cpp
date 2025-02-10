#include <xenon/components/services/lua_service.hpp>
#include <xenon/components/services/memory_service.hpp>

void CLuaService::Update() {
	#pragma region Trigger Update In Lua Scripts
	sol::function on_update = lua["OnUpdate"];
    if (on_update.valid()) {
	    on_update();
    }
	#pragma endregion

    if (g_pXenonVariables->g_bShowMenu && g_pXenonVariables->g_bLuaEditor) {
	    RenderLuaEditor();
    }

}

void CLuaService::RegisterBinds() {

	lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::string, sol::lib::table, sol::lib::math, sol::lib::os, sol::lib::io);

    // Window-related bindings
    lua.set_function("beginWindow", [](const char* title) {
        ImGui::Begin(title);
        });

    lua.set_function("endWindow", []() {
        ImGui::End();
        });

    lua.set_function("setCursorPos", [](float x, float y) {
        ImGui::SetCursorPos(ImVec2(x, y));
        });

    lua.set_function("sameLine", []() {
        ImGui::SameLine();
        });

    // Text rendering
    lua.set_function("drawText", [](const char* text) {
        ImGui::Text("%s", text);
        });

    lua.set_function("drawTextWrapped", [](const char* text) {
        ImGui::TextWrapped("%s", text);
        });

    // Button
    lua.set_function("createButton", [](const char* label) {
        return ImGui::Button(label);
        });

    // Line drawing
    lua.set_function("drawLine", [](float x1, float y1, float x2, float y2, int r, int g, int b, int a, float thickness = 1) {
        ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImColor(r, g, b, a), thickness);
        });

    // Rectangle drawing
    lua.set_function("drawRect", [](float x1, float y1, float x2, float y2, int r, int g, int b, int a, float rounding = 0, int rounding_corners_flags = 0, float thickness = 1) {
        ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x1, y1), ImVec2(x2, y2), ImColor(r, g, b, a), rounding, rounding_corners_flags, thickness);
        });

    // Filled rectangle drawing
    lua.set_function("drawRectFilled", [](float x1, float y1, float x2, float y2, int r, int g, int b, int a, float rounding = 0, int rounding_corners_flags = 0) {
        ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImColor(r, g, b, a), rounding, rounding_corners_flags);
        });

    // Circle drawing
    lua.set_function("drawCircle", [](float x, float y, float radius, int r, int g, int b, int a, int num_segments = 12, float thickness = 1) {
        ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(x, y), radius, ImColor(r, g, b, a), num_segments, thickness);
        });

    // Filled circle drawing
    lua.set_function("drawCircleFilled", [](float x, float y, float radius, int r, int g, int b, int a, int num_segments = 12) {
        ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImColor(r, g, b, a), num_segments);
        });

    // Triangle drawing
    lua.set_function("drawTriangle", [](float x1, float y1, float x2, float y2, float x3, float y3, int r, int g, int b, int a, float thickness = 1) {
        ImGui::GetBackgroundDrawList()->AddTriangle(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImColor(r, g, b, a), thickness);
        });

    // Filled triangle drawing
    lua.set_function("drawTriangleFilled", [](float x1, float y1, float x2, float y2, float x3, float y3, int r, int g, int b, int a) {
        ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), ImColor(r, g, b, a));
        });

    // Polygon drawing
    lua.set_function("drawPolygon", [](const std::vector<ImVec2>& points, int r, int g, int b, int a, float thickness = 1) {
        ImGui::GetBackgroundDrawList()->AddPolyline(&points[0], points.size(), ImColor(r, g, b, a), true, thickness);
        });

    // Filled polygon drawing
    lua.set_function("drawPolygonFilled", [](const std::vector<ImVec2>& points, int r, int g, int b, int a) {
        ImGui::GetBackgroundDrawList()->AddConvexPolyFilled(&points[0], points.size(), ImColor(r, g, b, a));
        });


	spdlog::debug("CLuaService::RegisterBinds() - Binds registered");
}

void CLuaService::ExecuteScript(std::string script) {	
	lua.script(script);

	spdlog::debug("CLuaService::ExecuteScript() - Script executed");
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
