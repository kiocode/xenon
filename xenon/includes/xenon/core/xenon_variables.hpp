#pragma once

#include <xenon/models/enums/rendering_hook_types.hpp>

#include <winuser.rh>

class XenonVariables {
public:

	// System
	int g_nToggleUIKey = VK_INSERT;
	bool g_bUpdate;
	bool g_bShowMenu;
	RenderingHookTypes g_renderingType = RenderingHookTypes::RENDERHOOK_NONE;

	// UI
	bool g_bRenderUI;
	bool g_bWatermark;
	bool g_bRenderMouse;
	bool g_bRenderWindows;
	bool g_bRenderOverlays;
	bool g_bRenderQuickActions;
	bool g_bMenu;
	bool g_bLuaEditor;
	bool g_bNotifications;
	bool g_bRadar;
	bool g_bWaypoints;

	// ESP
	bool g_bEsp;

	bool g_bSnapline;
	bool g_bBox2D;
	bool g_bBox3D;
	bool g_bSkeleton;
	bool g_bHealthBar;

	// Aimbot
	bool g_bAimbot;

	bool g_bStartFromCenter;
	bool g_bSilent;
	bool g_bVisibleCheck;
	bool g_bAutoShoot;
	bool g_bAutoScope;
	bool g_bSmooth;
	bool g_bHumanize;
	bool g_bNoSpread;
	bool g_bAimNearest;
	bool g_bNoRecoil;
	bool g_bFov;

	// Features
	bool g_bCrosshair;
	bool g_bSpinbot2D;
	bool g_bSpinbot3D;

};