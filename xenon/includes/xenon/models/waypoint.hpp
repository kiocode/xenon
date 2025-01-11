#pragma once
#include <string>
#include <xenon/utility/vec2.hpp>
#include <imgui/imgui.h>

class Waypoint {
public:
	std::string m_strName;
	Vec2 m_vPos2D;
	Vec3 m_vPos3D;
	ImColor m_cColor;

	Waypoint(std::string sName, Vec2 vPos, ImColor cColor) {
		m_strName = sName;
		m_vPos2D = vPos;
		m_cColor = cColor;
	}
	Waypoint(std::string sName, Vec3 vPos, ImColor cColor) {
		m_strName = sName;
		m_vPos3D = vPos;
		m_cColor = cColor;
	}
};