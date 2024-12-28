#pragma once

#include <string>

#include <xenon/utility/vec2.hpp>

class System {
public:

	float g_fStartPlayTime;
	float g_fDeltaTime;

	float GetPlayTime() const;

	Vec2 GetScreenResolution();
	Vec2 GetScreenCenter();

	void SetAppTitle(std::string title) {
		m_strAppTitle = title;
	}

	std::string GetAppTitle() {
		return m_strAppTitle;
	}

private:
	std::string m_strAppTitle;

	void GetDesktopResolution(int& horizontal, int& vertical);

};