#pragma once

#include <string>

#include <lua/lua.hpp>
#include <sol/sol.hpp>
#include <spdlog/spdlog.h>

class LuaService {
public:

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

	void ExecuteScript(std::string script);
	void ExecuteScriptFile(std::string path);

	void TriggerOnUpdate();

private:
	sol::state lua;

	void RegisterBinds();

};