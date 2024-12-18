#pragma once

#include <xenon/utility/vec2.hpp>

#include <string>

class Game {
public:
	Vec2 g_vScreenCenter;
	Vec2 g_vScreenResolution;
	bool g_bUseUpdate;

	void SetGameAbsolutePath(std::string path);
	void Update();

private:

	std::string m_strGameAbsolutePath;

};
