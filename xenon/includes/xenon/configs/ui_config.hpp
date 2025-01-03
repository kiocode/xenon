#pragma once

#include <functional>
#include <xenon/models/quickactions/quickactions.hpp>

class UIConfig {
public:
	bool m_bUseUINotification;
	bool m_bUseUIMenu;
	bool m_bUseUIRadar;
	bool m_bUseUIRenderWindows;
	bool m_bUseUIRenderOverlays;
	bool m_bUseUIQuickActions;

	bool m_bWatermark;

	std::function<void()> m_fnCustomTheme;
	std::function<void()> m_fnCustomNotification;
	std::function<void()> m_fnCustomMenu;
	std::function<void()> m_fnCustomRadar;
	std::vector<std::function<void()>> m_vFnWindows{};
	std::vector<std::function<void()>> m_vFnOverlays{};
	QuickActions* m_qActions = new QuickActions();
};