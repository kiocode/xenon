#pragma once

#include <xenon/features/feature.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/configs/esp_config.hpp>
#include <xenon/core/system.hpp>
#include <xenon/configs/game_variables.hpp>

class ESP : public Feature {
public:

	ESP(
		std::shared_ptr<ESPConfig> configs,
		std::shared_ptr<System> system,
		std::shared_ptr<GameVariables> gameVariables
	) : m_pConfigs(configs), m_pSystem(system), m_pGameVariables(gameVariables) { }

	void RenderSnapline();
	void Render2DBox();
	void Render3DBox();
	void RenderSkeleton();
	void RenderHealthbar();

private:
	std::shared_ptr<ESPConfig> m_pConfigs;
	std::shared_ptr<System> m_pSystem;
	std::shared_ptr<GameVariables> m_pGameVariables;
};