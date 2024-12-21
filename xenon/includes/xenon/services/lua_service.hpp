#pragma once

#include <string>

#include <lua/lua.hpp>
#include <sol/sol.hpp>

class LuaService {
public:

	LuaService() {
		RegisterBinds();
	}

	void ExecuteScript(std::string script);
	void ExecuteScriptFile(std::string path);

private:
	sol::state lua;

	void RegisterBinds();

};