#pragma once

#include <string>

#include <lua/lua.hpp>
#include <sol/sol.hpp>
#include <spdlog/spdlog.h>

#include <xenon/components/component.hpp>

/**
 * @class LuaService
 * @brief A service for handling Lua script execution and binding in the Xenon framework.
 *
 * The LuaService class extends from CComponent and allows for the execution of Lua scripts
 * and binding Lua functions to the Xenon framework, providing a scripting interface for
 * game modifications and automation.
 */
class LuaService : public CComponent {
public:

    /**
     * @brief Constructor for the LuaService class.
     *
     * Initializes the Lua environment, sets up an exception handler for Lua errors, and
     * registers the necessary bindings for Lua scripting functionality.
     */
    LuaService() {
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

    /**
     * @brief Triggers the `OnUpdate` event in Lua scripting.
     *
     * This method is used to trigger a custom update event, allowing Lua scripts to
     * be executed in sync with the game's update cycle.
     */
    void TriggerOnUpdate();

private:
    sol::state lua; ///< The Lua state for managing Lua execution.

    /**
     * @brief Registers Lua bindings for Xenon framework functions.
     *
     * This method binds Xenon framework functions and variables to the Lua scripting
     * environment, enabling Lua scripts to interact with the core functionality of the framework.
     */
    void RegisterBinds();
};
