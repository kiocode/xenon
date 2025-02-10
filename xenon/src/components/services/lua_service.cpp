#include <xenon/components/services/lua_service.hpp>
#include <xenon/components/services/memory_service.hpp>

void CLuaService::RegisterBinds() {

	lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::string, sol::lib::table, sol::lib::math, sol::lib::os, sol::lib::io);

    //lua.set("memoryService", DIManager::GetInstance().GetService<CMemoryService>());
	lua.set_function("drawLine", []() {
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(100, 100), ImVec2(200, 200), IM_COL32(255, 0, 0, 255), 2.0f);
	});

	//spdlog::info("CLuaService::RegisterBinds() - Binds registered");
}

void CLuaService::ExecuteScript(std::string script) {	
	lua.script(script);

	spdlog::info("CLuaService::ExecuteScript() - Script executed");
}

void CLuaService::ExecuteScriptFile(std::string path) {

}

void CLuaService::TriggerOnUpdate() {
	sol::function on_update = lua["OnUpdate"];
	if (!on_update.valid()) return;

	on_update();
}