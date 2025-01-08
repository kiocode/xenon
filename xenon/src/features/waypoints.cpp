#include <xenon/features/waypoints.hpp>

void Waypoints::SetWaypoint(std::string title, const Vec2& pos, ImColor color) {
	m_vWaypoints.push_back(std::make_tuple(title, Vec3(pos.x, pos.y, 0), color));
}

void Waypoints::SetWaypoint(std::string title, const Vec3& pos, ImColor color) {
	m_vWaypoints.push_back(std::make_tuple(title, pos, color));
}

std::vector<std::tuple<std::string, const Vec3&, ImColor>>& Waypoints::GetWaypoints() {
	return m_vWaypoints;
}

void Waypoints::ClearWaypoints() {
	m_vWaypoints.clear();
}
