#pragma once

#include <functional>

class UIConfig {
public:
	std::function<void()> m_fnCustomTheme;
	std::function<void()> m_fnCustomMenu;
};