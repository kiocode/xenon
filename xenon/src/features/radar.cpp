#include <xenon/components/features/radar.hpp>

#include <imgui/imgui.h>
#include <spdlog/spdlog.h>

#include <xenon/core/system.hpp>
#include <xenon/components/features/waypoints.hpp>

void Radar::Update() {
    if (g_pXenonVariables->g_bRadar) {
        Render();
    }
}

void Radar::Render() {
    
    if (g_pXenonConfigs->g_pRadarConfig->m_fnCustomRadar) {
        g_pXenonConfigs->g_pRadarConfig->m_fnCustomRadar();
        return;
    }

    switch (g_pXenonConfigs->g_pRadarConfig->m_nType) {
        case 0: RenderRadarBase(RadarShapes::CIRCULAR, g_pXenon->g_pSystem->Is3DGame()); break;
        case 1: RenderRadarBase(RadarShapes::RECTANGULAR, g_pXenon->g_pSystem->Is3DGame()); break;
        default:
            spdlog::error("Invalid radar type: {}", g_pXenonConfigs->g_pRadarConfig->m_nType);
            break;
    }
}

void Radar::RenderRadarBase(RadarShapes shape, bool is3D) {
    ImGui::Begin("Radar", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    {
        ImDrawList* drawlist = ImGui::GetWindowDrawList();
        ImVec2 pos = ImGui::GetWindowPos();

        const float radarSize = g_pXenonConfigs->g_pRadarConfig->m_fSize;
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

        drawlist->AddCircleFilled(radarCenter, g_pXenonConfigs->g_pRadarConfig->m_fLocalSize * g_pXenonConfigs->g_pRadarConfig->m_fZoom, ImColor(170, 170, 170, 255));

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

        const float zoomFactor = g_pXenonConfigs->g_pRadarConfig->m_fZoom > 0.0f ? g_pXenonConfigs->g_pRadarConfig->m_fZoom : 1.0f;

        if (is3D) {
            const Vec3& localPlayerPos = g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos3D;
            for (const auto& target : g_pXenonConfigs->g_pGameVariables->g_vTargets) {
                const float relativeX = target.m_vPos3D.x - localPlayerPos.x;
                const float relativeY = target.m_vPos3D.z - localPlayerPos.z;

                const float scaledX = (relativeX / g_pXenonConfigs->g_pRadarConfig->m_fDefaultScale) * radarSize * zoomFactor;
                const float scaledY = (relativeY / g_pXenonConfigs->g_pRadarConfig->m_fDefaultScale) * radarSize * zoomFactor;

                ImVec2 targetPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

                if (isPointInRadar(targetPos)) {
                    float targetSize = g_pXenonConfigs->g_pRadarConfig->m_fTargetsSize * zoomFactor;
                    drawlist->AddCircleFilled(targetPos, targetSize, ImColor(255, 0, 0, 255));

                    if (g_pXenonConfigs->g_pRadarConfig->m_bTargetsName && !target.m_strName.empty()) {
						drawlist->AddText(ImVec2(targetPos.x - (ImGui::CalcTextSize(target.m_strName.c_str()).x / 2), targetPos.y + 5), ImColor(255, 255, 255, 255), target.m_strName.c_str());
					}
                }
            }

            if (g_pXenonConfigs->g_pWaypointsConfig->m_bRenderInRadar)
            {
                g_pXenon->g_cWaypoints->RenderInRadar(isPointInRadar, localPlayerPos, g_pXenonConfigs->g_pRadarConfig->m_fDefaultScale, radarSize, zoomFactor, radarCenter);
            }

        } else {
            const Vec2& localPlayerPos = g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos2D;
            for (const auto& target : g_pXenonConfigs->g_pGameVariables->g_vTargets) {
                const float relativeX = target.m_vPos2D.x - localPlayerPos.x;
                const float relativeY = target.m_vPos2D.y - localPlayerPos.y;

                const float scaledX = (relativeX / g_pXenonConfigs->g_pRadarConfig->m_fDefaultScale) * radarSize * zoomFactor;
                const float scaledY = (relativeY / g_pXenonConfigs->g_pRadarConfig->m_fDefaultScale) * radarSize * zoomFactor;

                ImVec2 targetPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

                if (isPointInRadar(targetPos)) {
                    float targetSize = g_pXenonConfigs->g_pRadarConfig->m_fTargetsSize * zoomFactor;
                    drawlist->AddCircleFilled(targetPos, targetSize, ImColor(255, 0, 0, 255));

                    if (g_pXenonConfigs->g_pRadarConfig->m_bTargetsName && !target.m_strName.empty()) {
                        drawlist->AddText(ImVec2(targetPos.x - (ImGui::CalcTextSize(target.m_strName.c_str()).x / 2), targetPos.y + 5), ImColor(255, 255, 255, 255), target.m_strName.c_str());
                    }
                }
            }

            if (g_pXenonConfigs->g_pWaypointsConfig->m_bRenderInRadar)
            {
                g_pXenon->g_cWaypoints->RenderInRadar(isPointInRadar, localPlayerPos, g_pXenonConfigs->g_pRadarConfig->m_fDefaultScale, radarSize, zoomFactor, radarCenter);
            }
        }
    }
    ImGui::End();
}
