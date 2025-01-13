#include <xenon/features/waypoints.hpp>
#include <xenon/models/enums/game_dimensions.hpp>

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
		Vec2* waypointInScreen = m_pSystem->GetGameDimension() == GameDimensions::DIMENSION_3D ? m_pSystem->m_fnW2S3D(waypoint.m_vPos3D) : m_pSystem->m_fnW2S2D(waypoint.m_vPos2D);

		ImVec2 prismaPoints[4];
		prismaPoints[0] = ImVec2(waypointInScreen->x, waypointInScreen->y + 5);
		prismaPoints[1] = ImVec2(waypointInScreen->x - 5, waypointInScreen->y);
		prismaPoints[2] = ImVec2(waypointInScreen->x + 5, waypointInScreen->y);
		prismaPoints[3] = ImVec2(waypointInScreen->x, waypointInScreen->y - 5);

		ImGui::GetBackgroundDrawList()->AddPolyline(prismaPoints, sizeof(prismaPoints), ImColor(0,0,0), 0, 2);
	}
}

void Waypoints::RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec3 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter) {
	for (const Waypoint& waypoint : m_vWaypoints) {
		const float relativeX = waypoint.m_vPos2D.x - localPos.x;
		const float relativeY = waypoint.m_vPos2D.y - localPos.y;

		const float scaledX = (relativeX / defaultScale) * radarSize * zoomFactor;
		const float scaledY = (relativeY / defaultScale) * radarSize * zoomFactor;

		ImVec2 waypointPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

		if (fnIsPointInRadar(waypointPos)) {
			float waypointSize = m_pConfigs->m_fSizeInRadar * zoomFactor;
			ImGui::GetBackgroundDrawList()->AddCircleFilled(waypointPos, waypointSize, waypoint.m_cColor);

			if (m_pConfigs->m_bNamesInRadar && !waypoint.m_strName.empty()) {
				ImGui::GetBackgroundDrawList()->AddText(ImVec2(waypointPos.x - (ImGui::CalcTextSize(waypoint.m_strName.c_str()).x / 2), waypointPos.y + 5), ImColor(255, 255, 255, 255), waypoint.m_strName.c_str());
			}
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
			float waypointSize = m_pConfigs->m_fSizeInRadar * zoomFactor;
			ImGui::GetBackgroundDrawList()->AddCircleFilled(waypointPos, waypointSize, waypoint.m_cColor);

			if (m_pConfigs->m_bNamesInRadar && !waypoint.m_strName.empty()) {
				ImGui::GetBackgroundDrawList()->AddText(ImVec2(waypointPos.x - (ImGui::CalcTextSize(waypoint.m_strName.c_str()).x / 2), waypointPos.y + 5), ImColor(255, 255, 255, 255), waypoint.m_strName.c_str());
			}
		}
	}
}