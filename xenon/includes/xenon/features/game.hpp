#pragma once

#include <xenon/utility/vec2.hpp>

#include <string>
#include <chrono>

class Game {
public:
	Vec2 g_vScreenCenter;
	Vec2 g_vScreenResolution;
	bool g_bUseUpdate;
	float g_fStartPlayTime;
	float g_fDeltaTime;

	void SetGameAbsolutePath(std::string path);
	void Update();

	float GetPlayTime() const {
		return std::chrono::steady_clock::now().time_since_epoch().count() - g_fStartPlayTime;
	}

private:

	std::string m_strGameAbsolutePath;

};
