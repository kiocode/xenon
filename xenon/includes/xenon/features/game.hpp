#pragma once

#include <string>
#include <chrono>

#include <xenon/utility/vec2.hpp>
#include <spdlog/spdlog.h>
#include <xenon/services/aim_service.hpp>
#include <xenon/features/aimbot.hpp>
#include <xenon/features/radar.hpp>
#include <xenon/features/esp.hpp>
#include <xenon/configs/game_config.hpp>
#include <xenon/utility/vec3.hpp>
#include <xenon/services/lua_service.hpp>
#include <xenon/configs/game_variables.hpp>
#include <xenon/configs/ui_config.hpp>
#include <xenon/services/ui_service.hpp>

class Game {
public:

	Game(
		std::shared_ptr<GameConfig> configs, 
		std::shared_ptr<GameVariables> variables, 
		std::shared_ptr<UIConfig> uiConfig,
		std::shared_ptr<AimConfig> aimConfig,
		std::shared_ptr<AimService> aimService, 
		std::shared_ptr<UIService> uiService,
		std::shared_ptr<LuaService> luaService,
		std::shared_ptr<Aimbot> aimbot, 
		std::shared_ptr<ESP> esp,
		std::shared_ptr<Radar> radar,
		std::shared_ptr<System> system,
		std::shared_ptr<WaypointsConfig> pWaypointsConfig,
		std::shared_ptr<Waypoints> pWaypoints
	) : m_pConfigs(configs), 
		m_pVariables(variables), 
		m_pAimbot(aimbot), 
		m_pAimService(aimService),
		m_pSystem(system), 
		m_pAimConfigs(aimConfig), 
		m_pUIService(uiService), 
		m_pESP(esp), 
		m_pLuaService(luaService), 
		m_pRadar(radar), 
		m_pUIConfig(uiConfig),
		m_pWaypointsConfig(pWaypointsConfig),
		m_pWaypoints(pWaypoints) {}


	void EnableUpdate();

    void OnEvent(const std::string& eventName, const std::function<void()>& callback) {
        eventCallbacks[eventName].push_back(callback);
    }

    void TriggerEvent(const std::string& eventName) {
        if (eventCallbacks.find(eventName) != eventCallbacks.end()) {
            for (const auto& callback : eventCallbacks[eventName]) {
                callback();
            }
        }
    }

    void ClearEvent(const std::string& eventName) {
        eventCallbacks.erase(eventName);
    }

private:
    std::unordered_map<std::string, std::vector<std::function<void()>>> eventCallbacks;

	std::shared_ptr<GameConfig> m_pConfigs;
	std::shared_ptr<GameVariables> m_pVariables;
	std::shared_ptr<Aimbot> m_pAimbot;
	std::shared_ptr<AimService> m_pAimService;
	std::shared_ptr<AimConfig> m_pAimConfigs;
	std::shared_ptr<System> m_pSystem;
	std::shared_ptr<UIService> m_pUIService;
	std::shared_ptr<ESP> m_pESP;
	std::shared_ptr<LuaService> m_pLuaService;
	std::shared_ptr<Radar> m_pRadar;
	std::shared_ptr<UIConfig> m_pUIConfig;
	std::shared_ptr<WaypointsConfig> m_pWaypointsConfig;
	std::shared_ptr<Waypoints> m_pWaypoints;

    bool m_bInit = false;

    void Update();
	void HandleShortcuts(); 

    static HRESULT __stdcall hkPresentWrapper(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
        return DIManager::GetInstance().GetService<Game>()->BindForInternal(pSwapChain, SyncInterval, Flags);
    }
    HRESULT __stdcall BindForInternal(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
    void BindForExternal();

};
