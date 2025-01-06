#include <xenon/features/radar.hpp>
#include <imgui/imgui.h>
#include <spdlog/spdlog.h>

void Radar::RenderRadar() {
    if (m_pConfigs->m_fnCustomRadar) {
        m_pConfigs->m_fnCustomRadar();
        return;
    }

    bool is3D = false;

    switch (m_pConfigs->m_nType) {
    case 0: RenderRadarBase("Circular Radar", RadarShapes::Circular, is3D); break;
    case 1: RenderRadarBase("Rectangular Radar", RadarShapes::Rectangular, is3D); break;
    default:
        spdlog::error("Invalid radar type: {}", m_pConfigs->m_nType);
        break;
    }
}
void Radar::RenderRadarBase(const char* title, RadarShapes shape, bool is3D) {
    ImGui::Begin(title, nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
    {
        ImDrawList* drawlist = ImGui::GetWindowDrawList();
        ImVec2 pos = ImGui::GetWindowPos();

        const float radarSize = m_pConfigs->m_fSize;
        const float centerOffset = radarSize / 2.0f;
        const ImVec2 radarCenter = ImVec2(pos.x + centerOffset, pos.y + centerOffset);

        ImGui::SetWindowSize(ImVec2(radarSize, radarSize));

        switch (shape) {
            case RadarShapes::Circular:
                drawlist->AddCircleFilled(radarCenter, radarSize / 2.0f - 5, ImColor(25, 25, 25, 150));
                drawlist->AddCircle(radarCenter, radarSize / 2.0f - 5, ImColor(83, 83, 83, 255));
                break;
            case RadarShapes::Rectangular:
                drawlist->AddRectFilled(ImVec2(pos.x + 5, pos.y + 5),
                    ImVec2(pos.x + radarSize - 5, pos.y + radarSize - 5),
                    ImColor(25, 25, 25, 150), 8.f);
                drawlist->AddRect(ImVec2(pos.x + 5, pos.y + 5),
                    ImVec2(pos.x + radarSize - 5, pos.y + radarSize - 5),
                    ImColor(83, 83, 83, 255), 8.f);
                break;
        }

        drawlist->AddCircleFilled(radarCenter, 6.f * m_pConfigs->m_fZoom, ImColor(170, 170, 170, 255));

        auto isPointInRadar = [&](ImVec2 point) -> bool {
            if (shape == RadarShapes::Circular) {
                float distance = sqrtf(powf(point.x - radarCenter.x, 2) + powf(point.y - radarCenter.y, 2));
                return distance <= (radarSize / 2.0f - 5);
            }
            else if (shape == RadarShapes::Rectangular) {
                return point.x >= (pos.x + 5) && point.x <= (pos.x + radarSize - 5) &&
                    point.y >= (pos.y + 5) && point.y <= (pos.y + radarSize - 5);
            }
            return false;
        };

        const float zoomFactor = m_pConfigs->m_fZoom > 0.0f ? m_pConfigs->m_fZoom : 1.0f;

        if (is3D) {
            const auto& localPlayer = m_pGameVariables->g_vLocalPos3DWorld;
            for (const auto& target : m_pGameVariables->g_vTargets3DWorld) {
                const float relativeX = target.x - localPlayer.x;
                const float relativeY = target.z - localPlayer.z;

                const float scaledX = (relativeX / m_pConfigs->m_fDefaultScale) * radarSize * zoomFactor;
                const float scaledY = (relativeY / m_pConfigs->m_fDefaultScale) * radarSize * zoomFactor;

                ImVec2 targetPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

                if (isPointInRadar(targetPos)) {
                    float targetSize = 4.f * zoomFactor;
                    drawlist->AddCircleFilled(targetPos, targetSize, ImColor(255, 0, 0, 255));
                }
            }
        }
        else {
            const Vec2& localPlayer = m_pGameVariables->g_vLocalPos2DWorld;
            for (const auto& target : m_pGameVariables->g_vTargets2DWorld) {
                const float relativeX = target.x - localPlayer.x;
                const float relativeY = target.y - localPlayer.y;

                const float scaledX = (relativeX / m_pConfigs->m_fDefaultScale) * radarSize * zoomFactor;
                const float scaledY = (relativeY / m_pConfigs->m_fDefaultScale) * radarSize * zoomFactor;

                ImVec2 targetPos = ImVec2(radarCenter.x + scaledX, radarCenter.y + scaledY);

                if (isPointInRadar(targetPos)) {
                    float targetSize = 4.f * zoomFactor;
                    drawlist->AddCircleFilled(targetPos, targetSize, ImColor(255, 0, 0, 255));
                }
            }
        }
    }
    ImGui::End();
}
