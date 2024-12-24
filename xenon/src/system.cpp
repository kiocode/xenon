#include <chrono>

#include <xenon/core/system.hpp>
#include <wtypes.h>

float System::GetPlayTime() const {
	return std::chrono::steady_clock::now().time_since_epoch().count() - g_fStartPlayTime;
}

Vec2 System::GetScreenResolution() {
	int width, height;
	GetDesktopResolution(width, height);

	Vec2 resolution{ static_cast<double>(width), static_cast<double>(height) };

	//spdlog::debug("Screen resolution: {}x{}", resolution.x, resolution.y);

	return resolution;
}

Vec2 System::GetScreenCenter() {
	int width, height;
	GetDesktopResolution(width, height);

	Vec2 center{ static_cast<double>(width / 2), static_cast<double>(height / 2) };

	//spdlog::debug("Screen center: {}, {}", center.x, center.y);

	return center;
}


#pragma region System:Private

void System::GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;

	const HWND hDesktop = GetDesktopWindow();

	GetWindowRect(hDesktop, &desktop);

	horizontal = desktop.right;
	vertical = desktop.bottom;
}

#pragma endregion