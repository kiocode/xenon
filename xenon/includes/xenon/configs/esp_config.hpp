#pragma once

#include <functional>
#include <imgui/imgui.h>

class EspConfig {
public:

    int m_nLimitDistance = 0;

    int m_nSnaplineTypeStart = 0;
    int m_nSnaplineTypeEnd = 2;

    int m_nBox2DType = 0;
    bool m_bDistanceInBox = true;
    bool m_bNameInBox = true;

    bool m_bHealthBar = true;
    bool m_bTextInHealthBar = true;
    float m_fHealthBarWidth = 25;

    ImColor m_cSnapline = ImColor(255, 255, 255, 255);
    ImColor m_cBox2D = ImColor(255, 255, 255, 255);
    ImColor m_cBox2DDistance = ImColor(0, 0, 0, 255);
    ImColor m_cBox2DName = ImColor(0, 0, 0, 255);
    ImColor m_cBox3D = ImColor(255, 255, 255, 255);
    ImColor m_cBox3DDistance = ImColor(0, 0, 0, 255);
    ImColor m_cBox3DName = ImColor(0, 0, 0, 255);
    ImColor m_cSkeleton = ImColor(255, 255, 255, 255);
    ImColor m_cHealthBarBg = ImColor(0, 0, 0, 255);
    ImColor m_cHealthBarFilled = ImColor(0, 255, 0, 255);
    ImColor m_cHealthBarText = ImColor(255, 0, 0, 255);

    std::vector<std::pair<int, int>> m_tBonePairs;
    std::function<Vec3(int)> m_fnGetBoneScreenPosFromIndex3D;
    std::function<Vec2(int)> m_fnGetBoneScreenPosFromIndex2D;
};
