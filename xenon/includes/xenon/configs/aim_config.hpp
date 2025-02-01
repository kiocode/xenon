#pragma once

#include <functional>
#include <imgui/imgui.h>

class AimConfig {
public:

	float m_fNearest = 500;
	float m_fSmooth = 10;
	float m_fFov = 40;
	float m_fRecoilTiltSpeed = 0;
	float m_fRecoilTiltStrength = 0;
	float m_fRecoilVerticalStrength = 0;
	float m_fSpinbotSpeed = 10;
	float m_fSpinbotRadius = 100;
	float m_fSpinbotDepth = 5;

	ImColor m_cFov = ImColor(255, 255, 255, 255);

	std::function<void(const Vec2&)> m_fnCustomAim;
	std::function<Vec2()> m_fnGetCustomAim;
};
