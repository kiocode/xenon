#pragma once

#include <xenon/features/feature.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>
#include <xenon/models/waypoint.hpp>

#include <imgui/imgui.h>
#include <xenon/core/system.hpp>
#include <xenon/configs/waypoints_config.hpp>

class Waypoints : public Feature {
public:
	Waypoints(std::shared_ptr<WaypointsConfig> pConfigs, std::shared_ptr<System> pSystem) : m_pConfigs(pConfigs), m_pSystem(pSystem) {}

	void SetWaypoint(std::string title, const Vec2& pos, ImColor color);
	void SetWaypoint(std::string title, const Vec3& pos, ImColor color);

	std::vector<Waypoint> GetWaypoints();

	void ClearWaypoints();

	void RenderInWorld();
	void RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec3 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter);
	void RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec2 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter);

private:
	std::shared_ptr<WaypointsConfig> m_pConfigs;
	std::shared_ptr<System> m_pSystem;

	std::vector<Waypoint> m_vWaypoints;

};