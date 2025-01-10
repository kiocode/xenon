#pragma once

#include <functional>
#include <string>

#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>

class TargetProfile {
public:
	Vec2 m_vPos2D;
	Vec3 m_vPos3D;

	float m_fHealth;
	std::string m_strName;
};