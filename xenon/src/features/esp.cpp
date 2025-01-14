#include <xenon/features/esp.hpp>

#include <xenon/utility/imgui_helper.hpp>
#include <spdlog/spdlog.h>

void ESP::RenderSnapline() {

	if (!m_pSystem->m_fnW2S3D && !m_pSystem->m_fnW2S2D) {
		throw std::runtime_error("No world to screen function set");
		return;
	}

	float screenHeight = m_pSystem->GetScreenResolution().y;
	float centerX = m_pSystem->GetScreenCenter().x;
	ImVec2 center = ImVec2(centerX, m_pSystem->GetScreenCenter().y);

	for (auto& target : m_pGameVariables->g_vTargets) {

		Vec2* targetScreenPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vPos3D) : m_pSystem->m_fnW2S2D(target.m_vPos2D));
		Vec2* targetHeadScreenPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vHeadPos3D) : m_pSystem->m_fnW2S2D(target.m_vHeadPos2D));
		Vec2* targetFeetScreenPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vFeetPos3D) : m_pSystem->m_fnW2S2D(target.m_vFeetPos2D));

		ImVec2 targetPos = ImVec2(targetScreenPos->x, targetScreenPos->y);
		ImVec2 startPoint = center;

		switch (m_pConfigs->m_nSnaplineTypeStart)
		{
			case 0: // center
				startPoint = center;
				break;
			case 1: // top
				startPoint = ImVec2(centerX, 0);
				break;
			case 2: // bottom
				startPoint = ImVec2(centerX, screenHeight);
				break;
		}

		switch (m_pConfigs->m_nSnaplineTypeEnd) {
			case 0: // head
				targetPos = ImVec2(targetHeadScreenPos->x, targetHeadScreenPos->y);
				break;
			case 1: // body
				targetPos = ImVec2(targetScreenPos->x, targetScreenPos->y);
			case 2: // feet
				targetPos = ImVec2(targetFeetScreenPos->x, targetFeetScreenPos->y);
		}

		ImGui::GetBackgroundDrawList()->AddLine(startPoint, targetPos, m_pConfigs->m_cSnapline, 1.0f);
	}

}

void ESP::Render2DBox() {

	if (!m_pSystem->m_fnW2S3D && !m_pSystem->m_fnW2S2D) {
		throw std::runtime_error("No world to screen function set");
		return;
	}

	for (auto& target : m_pGameVariables->g_vTargets) {

		Vec2* targetScreenPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vPos3D) : m_pSystem->m_fnW2S2D(target.m_vPos2D));
		Vec2* targetScreenHeadPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vHeadPos3D) : m_pSystem->m_fnW2S2D(target.m_vHeadPos2D));
		Vec2* targetScreenFeetPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vFeetPos3D) : m_pSystem->m_fnW2S2D(target.m_vFeetPos2D));

		ImVec2 head = ImVec2(targetScreenHeadPos->x, targetScreenHeadPos->y);
		ImVec2 feet = ImVec2(targetScreenFeetPos->x, targetScreenFeetPos->y);
		ImVec2 pos = ImVec2(targetScreenPos->x, targetScreenPos->y);

		float height = abs(head.y - feet.y);

		ImVec2 minBottomLeft = ImVec2(feet.x - target.m_fWidth / 2, feet.y);
		ImVec2 maxTopRight = ImVec2(feet.x + target.m_fWidth / 2, head.y);

		ImColor colorAlpha = m_pConfigs->m_cBox2D;
		colorAlpha.Value.w = 0.3f;

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

		if (m_pConfigs->m_bDistanceInBox) {
			if(m_pSystem->Is3DGame()) {
				int distance3D = static_cast<int>(target.m_vPos3D.Distance(m_pGameVariables->g_vLocal.m_vPos3D));
				char distance3DStr[100];
				sprintf_s(distance3DStr, "%dpx", distance3D);
				ImGui::GetBackgroundDrawList()->AddText(ImVec2(minBottomLeft.x + 5, minBottomLeft.y - 15), m_pConfigs->m_cBox2DDistance, distance3DStr);
			} else {
				int distance2D = static_cast<int>(target.m_vPos2D.Distance(m_pGameVariables->g_vLocal.m_vPos2D));
				char distance2DStr[32];
				sprintf_s(distance2DStr, "%dpx", distance2D);
				ImGui::GetBackgroundDrawList()->AddText(ImVec2(minBottomLeft.x + 5, minBottomLeft.y - 15), m_pConfigs->m_cBox2DDistance, distance2DStr);
			}
		}

	}

}

void ESP::Render3DBox() {

	if (!m_pSystem->m_fnW2S3D && !m_pSystem->m_fnW2S2D) {
		throw std::runtime_error("No world to screen function set");
		return;
	}

}

void ESP::RenderSkeleton() {

	if (!m_pSystem->m_fnW2S3D && !m_pSystem->m_fnW2S2D) {
		throw std::runtime_error("No world to screen function set");
		return;
	}

	if (!m_pConfigs->m_tBonePairs.empty() || !m_pConfigs->m_fnGetBoneScreenPosFromIndex) {
		spdlog::error("No bone pairs or bone getter function set");
	}

	for (auto& target : m_pGameVariables->g_vTargets) {

		for (const std::pair<int, int>& pair : m_pConfigs->m_tBonePairs)
		{
			const int bone1Index = pair.first;
			const int bone2Index = pair.second;

			const Vec2 boneLoc1 = m_pConfigs->m_fnGetBoneScreenPosFromIndex(bone1Index);
			const Vec2 boneLoc2 = m_pConfigs->m_fnGetBoneScreenPosFromIndex(bone2Index);

			float bone1X = boneLoc1.x;
			float bone1Y = boneLoc1.y;
			float bone2X = boneLoc2.x;
			float bone2Y = boneLoc2.y;

			ImGui::GetBackgroundDrawList()->AddLine(
				ImVec2(bone1X, bone1Y),
				ImVec2(bone2X, bone2Y),
				m_pConfigs->m_cSkeleton,
				1.0f
			);
		}

	}
}

void ESP::RenderHealthBar() {

	if (!m_pSystem->m_fnW2S3D && !m_pSystem->m_fnW2S2D) {
		throw std::runtime_error("No world to screen function set");
		return;
	}

	for (auto& target : m_pGameVariables->g_vTargets) {
		float healthPercentage = target.m_fHealth / target.m_fMaxHealth;
		if (healthPercentage <= 0.0f) healthPercentage = 0;

		Vec2* targetScreenPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vPos3D) : m_pSystem->m_fnW2S2D(target.m_vPos2D));
		Vec2* targetScreenFeetPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vFeetPos3D) : m_pSystem->m_fnW2S2D(target.m_vFeetPos2D));
		Vec2* targetScreenHeadPos = (m_pSystem->Is3DGame() ? m_pSystem->m_fnW2S3D(target.m_vHeadPos3D) : m_pSystem->m_fnW2S2D(target.m_vHeadPos2D));

		ImVec2 head = ImVec2(targetScreenHeadPos->x, targetScreenHeadPos->y);
		ImVec2 feet = ImVec2(targetScreenFeetPos->x, targetScreenFeetPos->y);
		ImVec2 pos = ImVec2(targetScreenPos->x, targetScreenPos->y);

		float height = abs(head.y - feet.y);

		float currentHeight = height;
		float targetWidth = target.m_fWidth;

		currentHeight *= healthPercentage;

		int barWidth = m_pConfigs->m_fHealthBarLength;
		int margin = 3;

		ImVec2 minBottomLeftBg = ImVec2(feet.x - (targetWidth / 2) - barWidth, feet.y);
		ImVec2 maxTopRightBg = ImVec2(feet.x - (targetWidth / 2), head.y);

		ImVec2 minBottomLeftFilled = ImVec2(feet.x - (targetWidth / 2) - barWidth + margin, feet.y - margin);
		ImVec2 maxTopRightFilled = ImVec2(feet.x - (targetWidth / 2) - margin, (feet.y + margin) - currentHeight);

		ImGui::GetBackgroundDrawList()->AddRectFilled(minBottomLeftBg, maxTopRightBg, m_pConfigs->m_cHealthBarBg, 0, 0);
		ImGui::GetBackgroundDrawList()->AddRectFilled(minBottomLeftFilled, maxTopRightFilled, m_pConfigs->m_cHealthBarFilled, 0, 0);
			
		ImVec2 center = ImVec2(minBottomLeftBg.x + barWidth / 2, maxTopRightBg.y + height / 2);

		if (m_pConfigs->m_bTextInHealthBar) {
			char healthStr[100];
			sprintf_s(healthStr, "%d", static_cast<int>(target.m_fHealth));

			center.x -= ImGui::CalcTextSize(healthStr).x / 2.0f;

			ImGui::GetBackgroundDrawList()->AddText(center, m_pConfigs->m_cHealthBarText, healthStr);
		}

	}

}