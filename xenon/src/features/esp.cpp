#include <xenon/features/esp.hpp>

#include <xenon/utility/imgui_helper.hpp>
#include <spdlog/spdlog.h>

void ESP::RenderSnapline() {

	float screenHeight = static_cast<float>(m_pSystem->GetScreenResolution().y);
	float centerX = static_cast<float>(m_pSystem->GetScreenCenter().x);
	ImVec2 center = ImVec2(centerX, static_cast<float>(m_pSystem->GetScreenCenter().y));

	for (auto& target : m_pGameVariables->g_vTargetsScreen) {
		ImVec2 targetPos = ImVec2(static_cast<float>(target.x), static_cast<float>(target.y));

		switch (m_pConfigs->m_nSnaplineType)
		{
			case 0:
				ImGui::GetBackgroundDrawList()->AddLine(center, targetPos, m_pConfigs->m_cSnapline, 1.0f);
				break;
			case 1:
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(centerX, 0), targetPos, m_pConfigs->m_cSnapline, 1.0f);
				break;
			case 2:
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(centerX, screenHeight), targetPos, m_pConfigs->m_cSnapline, 1.0f);
				break;
		}

	}

}

void ESP::Render2DBox() {

	for (auto& target : m_pGameVariables->g_vTargetsScreen) {

		float targetX = static_cast<float>(target.x);
		float targetY = static_cast<float>(target.y);

		ImVec2 head = ImVec2(targetX, targetY);
		ImVec2 feet = ImVec2(targetX, targetY + 64);

		ImVec2 minBottomLeft = ImVec2(feet.x - 32, feet.y);
		ImVec2 maxTopRight = ImVec2(head.x + 32, head.y);

		ImColor colorAlpha = m_pConfigs->m_cBox2D;
		colorAlpha.Value.w = 0.5f;

		switch (m_pConfigs->m_nBox2DType) {
			case 0: // regular
				ImGui::GetBackgroundDrawList()->AddRectFilled(minBottomLeft, maxTopRight, colorAlpha, 0, 0);
				ImGui::GetBackgroundDrawList()->AddRect(minBottomLeft, maxTopRight, m_pConfigs->m_cBox2D, 0, 0);
				break;
			case 1: // cornered

				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(minBottomLeft.x, minBottomLeft.y), ImVec2(minBottomLeft.x + 5, minBottomLeft.y), m_pConfigs->m_cBox2D, 1.0f);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(minBottomLeft.x, minBottomLeft.y), ImVec2(minBottomLeft.x, minBottomLeft.y - 5), m_pConfigs->m_cBox2D, 1.0f);

				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(maxTopRight.x, maxTopRight.y), ImVec2(maxTopRight.x - 5, maxTopRight.y), m_pConfigs->m_cBox2D, 1.0f);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(maxTopRight.x, maxTopRight.y), ImVec2(maxTopRight.x, maxTopRight.y + 5), m_pConfigs->m_cBox2D, 1.0f);

				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(minBottomLeft.x, maxTopRight.y), ImVec2(minBottomLeft.x + 5, maxTopRight.y), m_pConfigs->m_cBox2D, 1.0f);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(minBottomLeft.x, maxTopRight.y), ImVec2(minBottomLeft.x, maxTopRight.y + 5), m_pConfigs->m_cBox2D, 1.0f);

				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(maxTopRight.x, minBottomLeft.y), ImVec2(maxTopRight.x - 5, minBottomLeft.y), m_pConfigs->m_cBox2D, 1.0f);
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(maxTopRight.x, minBottomLeft.y), ImVec2(maxTopRight.x, minBottomLeft.y - 5), m_pConfigs->m_cBox2D, 1.0f);

				break;

		}

	}

}

void ESP::Render3DBox() {

}

void ESP::RenderSkeleton() {

	if (!m_pConfigs->m_tBonePairs.empty() || !m_pConfigs->m_fnGetBoneScreenPosFromIndex) {
		spdlog::error("No bone pairs or bone getter function set");
	}

	for (auto& target : m_pGameVariables->g_vTargetsScreen) {

		for (const std::pair<int, int>& pair : m_pConfigs->m_tBonePairs)
		{
			const int bone1Index = pair.first;
			const int bone2Index = pair.second;

			const Vec2 boneLoc1 = m_pConfigs->m_fnGetBoneScreenPosFromIndex(bone1Index);
			const Vec2 boneLoc2 = m_pConfigs->m_fnGetBoneScreenPosFromIndex(bone2Index);

			float bone1X = static_cast<float>(boneLoc1.x);
			float bone1Y = static_cast<float>(boneLoc1.y);
			float bone2X = static_cast<float>(boneLoc2.x);
			float bone2Y = static_cast<float>(boneLoc2.y);

			ImGui::GetBackgroundDrawList()->AddLine(
				ImVec2(bone1X, bone1Y),
				ImVec2(bone2X, bone2Y),
				m_pConfigs->m_cSkeleton,
				1.0f
			);
		}

	}
}

void ESP::RenderHealthbar() {
}