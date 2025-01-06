#pragma once

#include <vector>
#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>

class GameVariables {
public:
	std::vector<Vec2> g_vTargets2DWorld;
	std::vector<Vec3> g_vTargets3DWorld;
	std::vector<Vec2> g_vTargetsCustom;
	std::vector<Vec2> g_vTargetsScreen;
	Vec2 g_vLocalPos2DWorld;
	Vec3 g_vLocalPos3DWorld;
};