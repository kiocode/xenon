#pragma once

#include <xenon/features/feature.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>
#include <imgui/imgui.h>

class Waypoints : public Feature {
public:
	void SetWaypoint(std::string title, const Vec2& pos, ImColor color);
	void SetWaypoint(std::string title, const Vec3& pos, ImColor color);

	std::vector<std::tuple<std::string, const Vec3&, ImColor>>& GetWaypoints();

	void ClearWaypoints();

private:
	std::vector<std::tuple<std::string, const Vec3&, ImColor>> m_vWaypoints;

};