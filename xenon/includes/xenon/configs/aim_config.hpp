#pragma once

#include <functional>
#include <imgui/imgui.h>

class AimConfig {
public:

    int m_nLimitDistance = 0;
    int m_nNearest = 500;
    float m_fSmooth = 10;
    float m_fFov = 60;
    float m_fRecoilTiltSpeed = 0;
    float m_fRecoilTiltStrength = 0;
    float m_fRecoilVerticalStrength = 0;
    float m_fSpinbotSpeed = 10;
    float m_fSpinbotRadius = 100;
    float m_fSpinbotDepth = 5;
    float m_fDistanceScale = 1;
    int m_nMouseInputMode = 3;
    int m_nAimTo = 0;

    bool m_bOnlyVisible = false;

    ImColor m_cFov = ImColor(255, 255, 255, 255);

    std::function<void(const Vec2&)> m_fnCustomAim;

    std::function<Vec2()> m_fnGetCustomAim;
};
