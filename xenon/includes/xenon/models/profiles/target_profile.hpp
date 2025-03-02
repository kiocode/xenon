#pragma once

#include <functional>
#include <string>

#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>

class TargetProfile {
public:
	intptr_t m_pOriginalAddress;

	// 2D
	Vec2 m_vHeadPos2D;
	Vec2 m_vFeetPos2D;
	Vec2 m_vPos2D;
	Vec2 m_vVelocity2D;

	// 3D
	Vec3 m_vHeadPos3D;
	Vec3 m_vFeetPos3D;
	Vec3 m_vPos3D;
	Vec3 m_vVelocity3D;

	bool m_bTemmate;
	bool m_bVisible = true;
	float m_fWidth;
	float m_fHealth;
	float m_fMaxHealth = 100;
	std::string m_strName;
	std::string m_strTag;

	float GetHeight3D() {
		return abs(m_vHeadPos3D.y - m_vFeetPos3D.y);
	}
	
	float GetHeight2D() {
		return abs(m_vHeadPos2D.y - m_vFeetPos2D.y);
	}
};