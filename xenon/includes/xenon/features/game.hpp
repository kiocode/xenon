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

	Vec2 GetScreenResolution();
	Vec2 GetScreenCenter();
	void Update();

private:

	std::shared_ptr<GameConfig> m_pConfigs;
	std::shared_ptr<Aimbot> m_pAimbot;
	std::shared_ptr<AimService> m_pAimService;
	std::shared_ptr<System> m_pSystem;

	void GetDesktopResolution(int& horizontal, int& vertical);
};
