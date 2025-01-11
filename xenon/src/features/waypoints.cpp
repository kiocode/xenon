#include <xenon/features/waypoints.hpp>

void Waypoints::SetWaypoint(std::string title, const Vec2& pos, ImColor color) {
	m_vWaypoints.push_back(Waypoint(title, pos, color));
}

void Waypoints::SetWaypoint(std::string title, const Vec3& pos, ImColor color) {
	m_vWaypoints.push_back(Waypoint(title, pos, color));
}

std::vector<Waypoint> Waypoints::GetWaypoints() {
	return m_vWaypoints;
}

void Waypoints::ClearWaypoints() {
	m_vWaypoints.clear();
}
