#pragma once

#include <string>
#include <chrono>

#include <xenon/utility/vec2.hpp>
#include <spdlog/spdlog.h>
#include <xenon/services/aim_service.hpp>
#include <xenon/features/aimbot.hpp>
#include <xenon/configs/game_config.hpp>

class Game {
public:

	Game(
		std::shared_ptr<GameConfig> configs, 
		std::shared_ptr<Aimbot> aimbot, 
		std::shared_ptr<AimService> aimService, 
		std::shared_ptr<System> system
	) : m_pConfigs(configs), m_pAimbot(aimbot), m_pAimService(aimService), m_pSystem(system) {}

	void Update();

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
	std::shared_ptr<Aimbot> m_pAimbot;
	std::shared_ptr<AimService> m_pAimService;
	std::shared_ptr<System> m_pSystem;

};
