#pragma once

#include <imgui/imgui.h>

class ESPConfig {
public:
	int m_nSnaplineType = 0;
	ImColor m_cSnapline = ImColor(255, 255, 255, 255);
	ImColor m_cBox2D = ImColor(255, 255, 255, 255);
	ImColor m_cBox3D = ImColor(255, 255, 255, 255);
	ImColor m_cSkeleton = ImColor(255, 255, 255, 255);
};