#pragma once

#include <xenon/utility/vec2.hpp>

#include <string>

class Game {
public:
	Vec2 g_vScreenCenter;
	Vec2 g_vScreenResolution;

	void SetGameAbsolutePath(std::string path);

private:

	std::string m_strGameAbsolutePath;

};
