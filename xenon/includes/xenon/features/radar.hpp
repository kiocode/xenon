#pragma once

#include <xenon/features/feature.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/core/system.hpp>
#include <xenon/configs/radar_config.hpp>
#include <xenon/configs/game_variables.hpp>
#include <xenon/models/enums/radar_shapes.hpp>
#include <xenon/features/waypoints.hpp>

class Radar : public Feature {
public:
	
	Radar(
		std::shared_ptr<RadarConfig> pConfigs,
		std::shared_ptr<GameVariables> pGameVariables,
		std::shared_ptr<System> pSystem,
		std::shared_ptr<Waypoints> pWaypoints
	) : m_pConfigs(pConfigs), m_pGameVariables(pGameVariables), m_pSystem(pSystem), m_pWaypoints(pWaypoints) { }

	void RenderRadar();

	void RenderRadarBase(const char* title, RadarShapes shape, bool is3D);

private:
	std::shared_ptr<RadarConfig> m_pConfigs;
	std::shared_ptr<GameVariables> m_pGameVariables;
	std::shared_ptr<System> m_pSystem;
	std::shared_ptr<Waypoints> m_pWaypoints;

};