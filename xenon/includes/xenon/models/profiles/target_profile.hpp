#pragma once

#include <functional>
#include <string>

#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>

class TargetProfile {
public:
	Vec2 m_vHeadPos2D;
	Vec2 m_vFeetPos2D;
	Vec2 m_vPos2D;
	Vec3 m_vHeadPos3D;
	Vec3 m_vFeetPos3D;
	Vec3 m_vPos3D;

	float m_fWidth;
	float m_fHealth;
	float m_fMaxHealth = 100;
	std::string m_strName;
	std::string m_strTag;
};