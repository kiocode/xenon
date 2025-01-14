#include <xenon/features/radar.hpp>
#include <imgui/imgui.h>
#include <spdlog/spdlog.h>

void Radar::Render() {
    if (m_pConfigs->m_fnCustomRadar) {
        m_pConfigs->m_fnCustomRadar();
        return;
    }

    bool is3D = m_pSystem->GetGameDimension() == GameDimensions::DIMENSION_3D;

    switch (m_pConfigs->m_nType) {
        case 0: RenderRadarBase(RadarShapes::CIRCULAR, is3D); break;
        case 1: RenderRadarBase(RadarShapes::RECTANGULAR, is3D); break;
        default:
            spdlog::error("Invalid radar type: {}", m_pConfigs->m_nType);
            break;
    }
}

void Radar::RenderRadarBase(RadarShapes shape, bool is3D) {
    ImGui::Begin("Radar", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    {
        ImDrawList* drawlist = ImGui::GetWindowDrawList();
        ImVec2 pos = ImGui::GetWindowPos();

        const float radarSize = m_pConfigs->m_fSize;
        const float centerOffset = radarSize / 2.0f;
        const ImVec2 radarCenter = ImVec2(pos.x + centerOffset, pos.y + centerOffset);

        ImGui::SetWindowSize(ImVec2(radarSize, radarSize));

        switch (shape) {
            case RadarShapes::CIRCULAR:
                drawlist->AddCircleFilled(radarCenter, radarSize / 2.0f - 5, ImColor(25, 25, 25, 150));
                drawlist->AddCircle(radarCenter, radarSize / 2.0f - 5, ImColor(83, 83, 83, 255));
                break;
            case RadarShapes::RECTANGULAR:
                drawlist->AddRectFilled(ImVec2(pos.x + 5, pos.y + 5),
                    ImVec2(pos.x + radarSize - 5, pos.y + radarSize - 5),
                    ImColor(25, 25, 25, 150), 8.f);
                drawlist->AddRect(ImVec2(pos.x + 5, pos.y + 5),
                    ImVec2(pos.x + radarSize - 5, pos.y + radarSize - 5),
                    ImColor(83, 83, 83, 255), 8.f);
                break;
        }

        drawlist->AddCircleFilled(radarCenter, m_pConfigs->m_fLocalSize * m_pConfigs->m_fZoom, ImColor(170, 170, 170, 255));

        auto isPointInRadar = [&](ImVec2 point) -> bool {
            if (shape == RadarShapes::CIRCULAR) {
                Vec2 pointConverted = { point.x, point.y };
                Vec2 radarCenterConverted = { radarCenter.x, radarCenter.y };
                float distance = pointConverted.Distance(radarCenterConverted);
                return distance <= (radarSize / 2.0f - 5);
            }
            else if (shape == RadarShapes::RECTANGULAR) {
                return point.x >= (pos.x + 5) && point.x <= (pos.x + radarSize - 5) &&
                    point.y >= (pos.y + 5) && point.y <= (pos.y + radarSize - 5);
            }
            return false;
        };

        const float zoomFactor = m_pConfigs->m_fZoom > 0.0f ? m_pConfigs->m_fZoom : 1.0f;

        if (is3D) {
            const Vec3& localPlayerPos = m_pGameVariables->g_vLocal.m_vPos3D;
            for (const auto& target : m_pGameVariables->g_vTargets) {
                const float relativeX = target.m_vPos3D.x - localPlayerPos.x;
                const float relativeY = target.m_vPos3D.z - localPlayerPos.z;

                const float scaledX = (relativeX / m_pConfigs->m_fDefaultScale) * radarSize * zoomFactor;
                const float scaledY = (relativeY / m_pConfigs->m_fDefaultScale) * radarSize * zoomFactor;

                ImVec2 targetPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

                if (isPointInRadar(targetPos)) {
                    float targetSize = m_pConfigs->m_fTargetsSize * zoomFactor;
                    drawlist->AddCircleFilled(targetPos, targetSize, ImColor(255, 0, 0, 255));

                    if (m_pConfigs->m_bTargetsName && !target.m_strName.empty()) {
						drawlist->AddText(ImVec2(targetPos.x - (ImGui::CalcTextSize(target.m_strName.c_str()).x / 2), targetPos.y + 5), ImColor(255, 255, 255, 255), target.m_strName.c_str());
					}
                }
            }

            if (m_pWaypointsConfig->m_bRenderInRadar)
            {
                m_pWaypoints->RenderInRadar(isPointInRadar, localPlayerPos, m_pConfigs->m_fDefaultScale, radarSize, zoomFactor, radarCenter);
            }

        } else {
            const Vec2& localPlayerPos = m_pGameVariables->g_vLocal.m_vPos2D;
            for (const auto& target : m_pGameVariables->g_vTargets) {
                const float relativeX = target.m_vPos2D.x - localPlayerPos.x;
                const float relativeY = target.m_vPos2D.y - localPlayerPos.y;

                const float scaledX = (relativeX / m_pConfigs->m_fDefaultScale) * radarSize * zoomFactor;
                const float scaledY = (relativeY / m_pConfigs->m_fDefaultScale) * radarSize * zoomFactor;

                ImVec2 targetPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

                if (isPointInRadar(targetPos)) {
                    float targetSize = m_pConfigs->m_fTargetsSize * zoomFactor;
                    drawlist->AddCircleFilled(targetPos, targetSize, ImColor(255, 0, 0, 255));

                    if (m_pConfigs->m_bTargetsName && !target.m_strName.empty()) {
                        drawlist->AddText(ImVec2(targetPos.x - (ImGui::CalcTextSize(target.m_strName.c_str()).x / 2), targetPos.y + 5), ImColor(255, 255, 255, 255), target.m_strName.c_str());
                    }
                }
            }

            if (m_pWaypointsConfig->m_bRenderInRadar)
            {
                m_pWaypoints->RenderInRadar(isPointInRadar, localPlayerPos, m_pConfigs->m_fDefaultScale, radarSize, zoomFactor, radarCenter);
            }
        }
    }
    ImGui::End();
}
