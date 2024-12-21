#include <xenon/services/lua_service.hpp>

void LuaService::RegisterBinds() {
	//lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::string, sol::lib::table, sol::lib::math, sol::lib::os, sol::lib::io);

	lua.set_function("test", [] { std::cout << "Works" << std::endl; });

}

void LuaService::ExecuteScript(std::string script) {	
	lua.script(script);
}

void LuaService::ExecuteScriptFile(std::string path) {

}