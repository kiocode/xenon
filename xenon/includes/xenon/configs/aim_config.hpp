#pragma once

#include <functional>
#include <imgui/imgui.h>

class AimConfig {
public:
	bool m_bStartFromCenter;
	bool m_bSilent;
	bool m_bVisibleCheck;
	bool m_bAutoShoot;
	bool m_bAutoScope;
	bool m_bSmooth;
	bool m_bHumanize;
	bool m_bFov;
	bool m_bCrosshair;
	bool m_bNoRecoil;
	bool m_bNoSpread;
	bool m_bNearest;

	float m_fNearest;
	float m_fSmooth = 10;
	float m_fFov = 20;
	float m_fRecoilTiltSpeed = 0;
	float m_fRecoilTiltStrength = 0;
	float m_fRecoilVerticalStrength = 0;
	float m_fSpinbotSpeed = 10;
	float m_fSpinbotRadius = 100;
	float m_fSpinbotDepth = 5;
	float m_fCrosshair;

	int m_nCrosshairType = 0;

	ImColor m_cFov = ImColor(255, 255, 255, 255);
	ImColor m_cCrosshair = ImColor(255, 255, 255, 255);

	std::function<void(const Vec2&)> m_fnCustomAim;
};
