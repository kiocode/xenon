#pragma once

#include <string>

#include <lua/lua.hpp>
#include <sol/sol.hpp>
#include <spdlog/spdlog.h>

#include <xenon/components/component.hpp>
#include <ImGuiColorTextEdit/TextEditor.h>

/**
 * @class CLuaService
 * @brief A service for handling Lua script execution and binding in the Xenon framework.
 *
 * The CLuaService class extends from CComponent and allows for the execution of Lua scripts
 * and binding Lua functions to the Xenon framework, providing a scripting interface for
 * game modifications and automation.
 */
class CLuaService : public CComponent {
public:

    /**
     * @brief Constructor for the CLuaService class.
     *
     * Initializes the Lua environment, sets up an exception handler for Lua errors, and
     * registers the necessary bindings for Lua scripting functionality.
     */
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
        auto lang = TextEditor::LanguageDefinition::Lua();

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

    /**
     * @brief Executes a Lua script from a string.
     * @param script The Lua script to execute.
     *
     * This method allows the execution of Lua scripts that are passed as a string.
     * Any errors will be caught and logged via the exception handler.
     */
    void ExecuteScript(std::string script);

    /**
     * @brief Executes a Lua script from a file.
     * @param path The path to the Lua script file.
     *
     * This method executes a Lua script loaded from a file. The file path is provided
     * as a string. Any errors encountered during execution will be caught and logged.
     */
    void ExecuteScriptFile(std::string path);

    void Update() override;

private:
    sol::state lua; ///< The Lua state for managing Lua execution.

    TextEditor editor;
    /**
     * @brief Registers Lua bindings for Xenon framework functions.
     *
     * This method binds Xenon framework functions and variables to the Lua scripting
     * environment, enabling Lua scripts to interact with the core functionality of the framework.
     */
    void RegisterBinds();

	void RenderLuaEditor();
};
