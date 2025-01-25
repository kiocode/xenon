#pragma once

#include <xenon/components/component.hpp>

#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>
#include <xenon/models/waypoint.hpp>

#include <imgui/imgui.h>

class Waypoints : public CComponent {
public:

	void SetWaypoint(std::string title, const Vec2& pos, ImColor color);
	void SetWaypoint(std::string title, const Vec3& pos, ImColor color);

	std::vector<Waypoint> GetWaypoints();

	void ClearWaypoints();

	void RenderInWorld();
	void RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec2 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter);
	void RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec3 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter);

	void Update() override;
private:
	std::vector<Waypoint> m_vWaypoints;

};