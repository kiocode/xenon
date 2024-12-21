#pragma once

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
	bool m_bNoRecoil;
	bool m_bNoSpread;
	bool m_bNearest;

	float m_fSmooth = 10;
	float m_fFov = 20;
	float m_fRecoilTiltSpeed = 0;
	float m_fRecoilTiltStrength = 0;
	float m_fRecoilVerticalStrength = 0;
};
