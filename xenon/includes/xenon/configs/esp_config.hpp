#pragma once

#include <imgui/imgui.h>

class ESPConfig {
public:
	int m_nSnaplineType = 0;
	int m_nBox2DType = 0;
	bool m_bDistanceInBox = true;
	bool m_bHealthBar = true;
	ImColor m_cSnapline = ImColor(255, 255, 255, 255);
	ImColor m_cBox2D = ImColor(255, 255, 255, 255);
	ImColor m_cBox2DDistance = ImColor(0, 0, 0, 255);
	ImColor m_cBox3D = ImColor(255, 255, 255, 255);
	ImColor m_cSkeleton = ImColor(255, 255, 255, 255);
	ImColor m_cHealthBarBg = ImColor(0, 0, 0, 255);
	ImColor m_cHealthBarFilled = ImColor(0, 255, 0, 255);

	std::vector<std::pair<int, int>> m_tBonePairs;

	std::function<Vec2(int)> m_fnGetBoneScreenPosFromIndex;
};