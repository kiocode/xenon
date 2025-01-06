#pragma once

#include <xenon/features/feature.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/core/system.hpp>
#include <xenon/configs/radar_config.hpp>
#include <xenon/configs/game_variables.hpp>
#include <xenon/models/radar_shapes.hpp>

class Radar : public Feature {
public:
	
	Radar(
		std::shared_ptr<RadarConfig> pConfigs,
		std::shared_ptr<GameVariables> pGameVariables
	) : m_pConfigs(pConfigs), m_pGameVariables(pGameVariables) { }

	void RenderRadar();

	void RenderRadarBase(const char* title, RadarShapes shape, bool is3D);

private:
	std::shared_ptr<RadarConfig> m_pConfigs;
	std::shared_ptr<GameVariables> m_pGameVariables;

};