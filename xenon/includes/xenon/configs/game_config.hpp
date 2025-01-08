#pragma once

#include <winuser.rh>

#include <xenon/models/rendering_hook_types.hpp>

class GameConfig {
public:
	bool m_bUseUpdate;
	bool m_bUseUICustom;
	bool m_bUseAimbot;
	bool m_bUseESPSnapline;
	bool m_bUseESPBox2D;
	bool m_bUseESPBox3D;
	bool m_bUseESPSkeleton;
	bool m_bUseRecoil;
	bool m_bUse2DSpinbot;
	bool m_bUse3DSpinbot;

	RenderingHookTypes m_bRenderingType;

	int m_nToggleUIKey = VK_INSERT;

};
