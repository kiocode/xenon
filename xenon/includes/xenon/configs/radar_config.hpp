#pragma once

#include <functional>
#include <xenon/utility/vec2.hpp>

class RadarConfig {
public:
	int m_nType;
	float m_fSize = 200;
	float m_fTargetsSize = 6;
	float m_fLocalSize = 5;
	float m_fDefaultScale = 1;
	float m_fZoom = 1;
	bool m_bTargetsName = true;
	bool m_bShowWaypointsNames = true;
	bool m_bShowWaypoints = true;
	float m_fWaypointsSize = 3;

	std::function<void()> m_fnCustomRadar;
};