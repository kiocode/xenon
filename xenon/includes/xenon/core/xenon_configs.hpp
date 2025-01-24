#pragma once

#include <memory>

#include <xenon/configs/game_variables.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/configs/esp_config.hpp>
#include <xenon/configs/radar_config.hpp>
#include <xenon/configs/ui_config.hpp>
#include <xenon/configs/waypoints_config.hpp>

//class AimConfig;
//class EspConfig;
//class GameVariables;
//class RadarConfig;
//class UIConfig;
//class WaypointsConfig;

class XenonConfigs {
public:

	std::shared_ptr<AimConfig> g_pAimConfig;
	std::shared_ptr<EspConfig> g_pEspConfig;
	std::shared_ptr<GameVariables> g_pGameVariables;
	std::shared_ptr<RadarConfig> g_pRadarConfig;
	std::shared_ptr<UIConfig> g_pUIConfig;
	std::shared_ptr<WaypointsConfig> g_pWaypointsConfig;

};