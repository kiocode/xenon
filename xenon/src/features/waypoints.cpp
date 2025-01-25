#include <xenon/components/features/waypoints.hpp>

#include <xenon/models/enums/game_dimensions.hpp>

#include <xenon/core/system.hpp>

void Waypoints::Update() {
	if (g_pXenonConfigs->g_pWaypointsConfig->m_bRenderInWorld) {
		RenderInWorld();
	}
}

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

void Waypoints::RenderInWorld() {
	for (auto& waypoint : m_vWaypoints) {
		Vec2* waypointInScreen = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(waypoint.m_vPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(waypoint.m_vPos2D);

		if (!waypointInScreen) continue;

		float size = g_pXenonConfigs->g_pWaypointsConfig->m_fSizeInWorld;

		ImVec2 top(waypointInScreen->x, waypointInScreen->y - size);
		ImVec2 right(waypointInScreen->x + (size / 1.5), waypointInScreen->y);
		ImVec2 bottom(waypointInScreen->x, waypointInScreen->y + size);
		ImVec2 left(waypointInScreen->x - (size / 1.5), waypointInScreen->y);

		ImGui::GetBackgroundDrawList()->AddQuadFilled(top, right, bottom, left, waypoint.m_cColor);

		if (g_pXenonConfigs->g_pWaypointsConfig->m_bNamesInWorld && !waypoint.m_strName.empty()) {
			ImGui::GetBackgroundDrawList()->AddText(ImVec2(waypointInScreen->x - (ImGui::CalcTextSize(waypoint.m_strName.c_str()).x / 2), waypointInScreen->y + size + 5), ImColor(255, 255, 255, 255), waypoint.m_strName.c_str());
		}
	}
}

void Waypoints::RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec2 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter) {
	for (const Waypoint& waypoint : m_vWaypoints) {
		const float relativeX = waypoint.m_vPos2D.x - localPos.x;
		const float relativeY = waypoint.m_vPos2D.y - localPos.y;

		const float scaledX = (relativeX / defaultScale) * radarSize * zoomFactor;
		const float scaledY = (relativeY / defaultScale) * radarSize * zoomFactor;

		ImVec2 waypointPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

		if (fnIsPointInRadar(waypointPos)) {
			float waypointSize = g_pXenonConfigs->g_pWaypointsConfig->m_fSizeInRadar * zoomFactor;
			ImGui::GetBackgroundDrawList()->AddCircleFilled(waypointPos, waypointSize, waypoint.m_cColor);

			if (g_pXenonConfigs->g_pWaypointsConfig->m_bNamesInRadar && !waypoint.m_strName.empty()) {
				ImGui::GetBackgroundDrawList()->AddText(ImVec2(waypointPos.x - (ImGui::CalcTextSize(waypoint.m_strName.c_str()).x / 2), waypointPos.y + 5), ImColor(255, 255, 255, 255), waypoint.m_strName.c_str());
			}
		}
	}
}

void Waypoints::RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec3 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter) {
	for (const Waypoint& waypoint : m_vWaypoints) {
		const float relativeX = waypoint.m_vPos3D.x - localPos.x;
		const float relativeY = waypoint.m_vPos3D.z - localPos.z;

		const float scaledX = (relativeX / defaultScale) * radarSize * zoomFactor;
		const float scaledY = (relativeY / defaultScale) * radarSize * zoomFactor;

		ImVec2 waypointPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

		if (fnIsPointInRadar(waypointPos)) {
			float waypointSize = g_pXenonConfigs->g_pWaypointsConfig->m_fSizeInRadar * zoomFactor;
			ImGui::GetBackgroundDrawList()->AddCircleFilled(waypointPos, waypointSize, waypoint.m_cColor);

			if (g_pXenonConfigs->g_pWaypointsConfig->m_bNamesInRadar && !waypoint.m_strName.empty()) {
				ImGui::GetBackgroundDrawList()->AddText(ImVec2(waypointPos.x - (ImGui::CalcTextSize(waypoint.m_strName.c_str()).x / 2), waypointPos.y + 5), ImColor(255, 255, 255, 255), waypoint.m_strName.c_str());
			}
		}
	}
}