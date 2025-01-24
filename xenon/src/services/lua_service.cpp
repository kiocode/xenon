#include <xenon/components/services/lua_service.hpp>
#include <xenon/components/services/memory_service.hpp>
#include <xenon/core/di_manager.hpp>

void LuaService::RegisterBinds() {

	lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::string, sol::lib::table, sol::lib::math, sol::lib::os, sol::lib::io);

    lua.set("memoryService", DIManager::GetInstance().GetService<MemoryService>());

	//spdlog::info("LuaService::RegisterBinds() - Binds registered");
}

void LuaService::ExecuteScript(std::string script) {	
	lua.script(script);

	spdlog::info("LuaService::ExecuteScript() - Script executed");
}

void LuaService::ExecuteScriptFile(std::string path) {

}

void LuaService::TriggerOnUpdate() {
	sol::function on_update = lua["OnUpdate"];
	if (!on_update.valid()) return;

	on_update();
}