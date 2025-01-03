#pragma once

#include <winuser.rh>

#include <xenon/models/render_types.hpp>

class GameConfig {
public:
	bool m_bUseUpdate;
	bool m_bUseUICustom;
	bool m_bUseAimbot;
	bool m_bUseRecoil;
	bool m_bUse2DSpinbot;
	bool m_bUse3DSpinbot;

	RenderingTypes m_bRenderingType;

	int m_nToggleUIKey = VK_INSERT;
};
