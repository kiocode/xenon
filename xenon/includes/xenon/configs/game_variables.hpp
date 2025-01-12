#pragma once

#include <vector>
#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>
#include <xenon/models/profiles/target_profile.hpp>

class GameVariables {
public:
	std::vector<TargetProfile> g_vTargets;
	TargetProfile g_vLocal;
};