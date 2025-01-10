#pragma once

#include <vector>
#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>
#include <xenon/models/profiles/target_profile.hpp>

class GameVariables {
public:
	//std::vector<Vec2> g_vTargets2DWorld;
	//std::vector<Vec3> g_vTargets3DWorld;
	//std::vector<Vec2> g_vTargetsCustom;
	//std::vector<Vec2> g_vTargetsScreen;
	std::vector<TargetProfile> g_vTargets;
	TargetProfile g_vLocal;
};