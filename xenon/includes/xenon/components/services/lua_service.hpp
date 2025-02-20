#pragma once

#include <string>

#include <lua/lua.hpp>
#include <sol/sol.hpp>
#include <spdlog/spdlog.h>

#include <xenon/components/component.hpp>
#include <ImGuiColorTextEdit/TextEditor.h>

class CLuaService : public CComponent {
public:

    CLuaService() {
        lua.set_exception_handler([](lua_State* L, sol::optional<const std::exception&> maybe_exception, sol::string_view description) {
            std::string error_message = "Lua exception: ";
            if (maybe_exception) {
                error_message += maybe_exception->what();
            }
            else {
                error_message += std::string(description);
            }

            spdlog::error(error_message);  
            return sol::stack::push(L, error_message);
        });

        RegisterBinds();
    }


    void Init() override {
        TextEditor::LanguageDefinition lang = TextEditor::LanguageDefinition::Lua();

        static const char* identifiers[] = { "print", "pairs", "ipairs", "next", "table", "string", "math", "io", "os" };
        static const char* idecls[] = {
            "print(...) -> Prints to the console",
            "pairs(t) -> Iterator for tables",
            "ipairs(t) -> Ordered iterator for arrays",
            "next(table, key) -> Returns the next key",
            "Lua table library",
            "Lua string library",
            "Lua math library",
            "Lua io library",
            "Lua os library"
        };

        for (int i = 0; i < sizeof(identifiers) / sizeof(identifiers[0]); ++i) {
            TextEditor::Identifier id;
            id.mDeclaration = idecls[i];
            lang.mIdentifiers.insert(std::make_pair(std::string(identifiers[i]), id));
        }

        editor.SetLanguageDefinition(lang);

        editor.SetText("-- Write your Lua script here\nprint('Hello, Lua!')");

    }

    sol::protected_function_result ExecuteScript(std::string script);

    void ExecuteScriptFile(std::string path);

    void Update() override;

private:
    sol::state lua;

    TextEditor editor;

    void RegisterBinds();

	void RenderLuaEditor();
};
