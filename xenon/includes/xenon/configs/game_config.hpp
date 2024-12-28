#pragma once
#include <winuser.rh>

class GameConfig {
public:
	bool m_bUseUpdate;
	bool m_bUseCustomUI;
	bool m_bUseAimbot;
	bool m_bUseRecoil;
	bool m_bUse2DSpinbot;
	bool m_bUse3DSpinbot;

	int m_nToggleUIKey = VK_INSERT;
};
