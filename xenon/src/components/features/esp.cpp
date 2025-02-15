#include <xenon/components/features/esp.hpp>

#include <xenon/utility/imgui_helper.hpp>
#include <spdlog/spdlog.h>
#include <xenon/core/system.hpp>

void CEsp::UpdateCurrentTarget(TargetProfile* target) {
	if (!g_pXenonVariables->g_bEsp) return;

	if (g_pXenonVariables->g_bSnapline) {
		RenderSnapline(target);
	}

	if (g_pXenonVariables->g_bBox2D) {
		Render2DBox(target);
	}

	if (g_pXenonVariables->g_bBox3D) {
		Render3DBox(target);
	}

	if (g_pXenonVariables->g_bSkeleton) {
		RenderSkeleton(target);
	}

	if (g_pXenonVariables->g_bHealthBar) {
		RenderHealthBar(target);
	}

}

void CEsp::RenderSnapline(TargetProfile* target) const {

	float screenHeight = g_pXenon->g_pSystem->GetScreenResolution().y;
	float centerX = g_pXenon->g_pSystem->GetScreenCenter().x;
	ImVec2 center = ImVec2(centerX, g_pXenon->g_pSystem->GetScreenCenter().y);

	Vec2 targetScreenPos = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vPos2D);
	Vec2 targetHeadScreenPos = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vHeadPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vHeadPos2D);
	Vec2 targetFeetScreenPos = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vFeetPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vFeetPos2D);

	ImVec2 targetPos = ImVec2(targetScreenPos.x, targetScreenPos.y);
	ImVec2 startPoint = center;

	switch (g_pXenonConfigs->g_pEspConfig->m_nSnaplineTypeStart)
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

	switch (g_pXenonConfigs->g_pEspConfig->m_nSnaplineTypeEnd) {
		case 0: // head
			targetPos = ImVec2(targetHeadScreenPos.x, targetHeadScreenPos.y);
			break;
		case 1: // body
			targetPos = ImVec2(targetScreenPos.x, targetScreenPos.y);
			break;
		case 2: // feet
			targetPos = ImVec2(targetFeetScreenPos.x, targetFeetScreenPos.y);
			break;
	}

	ImGui::GetBackgroundDrawList()->AddLine(startPoint, targetPos, g_pXenonConfigs->g_pEspConfig->m_cSnapline, 1.0f);

}

void CEsp::Render2DBox(TargetProfile* target) const {
	float distance = g_pXenon->g_pSystem->Is3DGame() ?
		target->m_vPos3D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos3D) :
		target->m_vPos2D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos2D);

	float scaleFactor = g_pXenon->g_pSystem->Is3DGame() ? 1.0f / (distance * g_pXenonConfigs->g_pAimConfig->m_fDistanceScale) : 1;
	float boxWidth = target->m_fWidth * scaleFactor;

	Vec2 targetScreenHeadPos = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vHeadPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vHeadPos2D);
	Vec2 targetScreenFeetPos = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vFeetPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vFeetPos2D);

	ImVec2 minBottomLeft = ImVec2(targetScreenFeetPos.x - boxWidth / 2, targetScreenFeetPos.y);
	ImVec2 maxTopRight = ImVec2(targetScreenFeetPos.x + boxWidth / 2, targetScreenHeadPos.y);

	ImColor colorAlpha = g_pXenonConfigs->g_pEspConfig->m_cBox2D;
	colorAlpha.Value.w = 0.3f;

	//// head
	//ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(g_pXenon->g_pSystem->m_fnW2S3D(target->m_vHeadPos3D).x, g_pXenon->g_pSystem->m_fnW2S3D(target->m_vHeadPos3D).y), 5, IM_COL32(255, 255, 0, 255), 12, 1.0f);
	//// feet
	//ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(g_pXenon->g_pSystem->m_fnW2S3D(target->m_vFeetPos3D).x, g_pXenon->g_pSystem->m_fnW2S3D(target->m_vFeetPos3D).y), 5, IM_COL32(0, 255, 255, 255), 12, 1.0f);

	switch (g_pXenonConfigs->g_pEspConfig->m_nBox2DType) {
		case 0: // regular
			ImGui::GetBackgroundDrawList()->AddRectFilled(minBottomLeft, maxTopRight, colorAlpha, 0, 0);
			ImGui::GetBackgroundDrawList()->AddRect(minBottomLeft, maxTopRight, g_pXenonConfigs->g_pEspConfig->m_cBox2D, 0, 0);
			break;
		case 1: // cornered			
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(minBottomLeft.x, minBottomLeft.y), ImVec2(minBottomLeft.x + 5, minBottomLeft.y), g_pXenonConfigs->g_pEspConfig->m_cBox2D, 1.0f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(minBottomLeft.x, minBottomLeft.y), ImVec2(minBottomLeft.x, minBottomLeft.y - 5), g_pXenonConfigs->g_pEspConfig->m_cBox2D, 1.0f);

			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(maxTopRight.x, maxTopRight.y), ImVec2(maxTopRight.x - 5, maxTopRight.y), g_pXenonConfigs->g_pEspConfig->m_cBox2D, 1.0f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(maxTopRight.x, maxTopRight.y), ImVec2(maxTopRight.x, maxTopRight.y + 5), g_pXenonConfigs->g_pEspConfig->m_cBox2D, 1.0f);

			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(minBottomLeft.x, maxTopRight.y), ImVec2(minBottomLeft.x + 5, maxTopRight.y), g_pXenonConfigs->g_pEspConfig->m_cBox2D, 1.0f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(minBottomLeft.x, maxTopRight.y), ImVec2(minBottomLeft.x, maxTopRight.y + 5), g_pXenonConfigs->g_pEspConfig->m_cBox2D, 1.0f);

			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(maxTopRight.x, minBottomLeft.y), ImVec2(maxTopRight.x - 5, minBottomLeft.y), g_pXenonConfigs->g_pEspConfig->m_cBox2D, 1.0f);
			ImGui::GetBackgroundDrawList()->AddLine(ImVec2(maxTopRight.x, minBottomLeft.y), ImVec2(maxTopRight.x, minBottomLeft.y - 5), g_pXenonConfigs->g_pEspConfig->m_cBox2D, 1.0f);
			break;
	}

	if (g_pXenonConfigs->g_pEspConfig->m_bDistanceInBox) {
		char distanceStr[32];
		sprintf_s(distanceStr, "%d", static_cast<int>(distance));
		ImGui::GetBackgroundDrawList()->AddText(ImVec2(minBottomLeft.x + 5, minBottomLeft.y - 15), g_pXenonConfigs->g_pEspConfig->m_cBox2DDistance, distanceStr);
	}

	if (g_pXenonConfigs->g_pEspConfig->m_bNameInBox) {
		ImGui::GetBackgroundDrawList()->AddText(ImVec2(minBottomLeft.x + 5, minBottomLeft.y + 5), g_pXenonConfigs->g_pEspConfig->m_cBox2DName, target->m_strName.c_str());
	}
}

void CEsp::Render3DBox(TargetProfile* target) const {


}

void CEsp::RenderSkeleton(TargetProfile* target) const {

	if (!g_pXenonConfigs->g_pEspConfig->m_tBonePairs.empty() || !g_pXenonConfigs->g_pEspConfig->m_fnGetBoneScreenPosFromIndex) {
		spdlog::error("No bone pairs or bone getter function set");
		return;
	}

	for (const std::pair<int, int>& pair : g_pXenonConfigs->g_pEspConfig->m_tBonePairs)
	{
		const int bone1Index = pair.first;
		const int bone2Index = pair.second;

		const Vec2 boneLoc1 = g_pXenonConfigs->g_pEspConfig->m_fnGetBoneScreenPosFromIndex(bone1Index);
		const Vec2 boneLoc2 = g_pXenonConfigs->g_pEspConfig->m_fnGetBoneScreenPosFromIndex(bone2Index);

		float bone1X = boneLoc1.x;
		float bone1Y = boneLoc1.y;
		float bone2X = boneLoc2.x;
		float bone2Y = boneLoc2.y;

		ImGui::GetBackgroundDrawList()->AddLine(
			ImVec2(bone1X, bone1Y),
			ImVec2(bone2X, bone2Y),
			g_pXenonConfigs->g_pEspConfig->m_cSkeleton,
			1.0f
		);
	}

}

void CEsp::RenderHealthBar(TargetProfile* target) const {

	float healthPercentage = target->m_fHealth / target->m_fMaxHealth;
	if (healthPercentage <= 0.0f) healthPercentage = 0;

	Vec2 targetScreenPos = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vPos2D);
	Vec2 targetScreenFeetPos = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vFeetPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vFeetPos2D);
	Vec2 targetScreenHeadPos = g_pXenon->g_pSystem->Is3DGame() ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vHeadPos3D) : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vHeadPos2D);

	float height = abs(targetScreenHeadPos.y - targetScreenFeetPos.y);

	float currentHeight = height;
	float distance = g_pXenon->g_pSystem->Is3DGame() ?
		target->m_vPos3D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos3D) :
		target->m_vPos2D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos2D);

	float scaleFactor = g_pXenon->g_pSystem->Is3DGame() ? 1.0f / (distance * g_pXenonConfigs->g_pAimConfig->m_fDistanceScale) : 1;
	float targetWidth = target->m_fWidth * scaleFactor;

	currentHeight *= healthPercentage;

	float barWidth = g_pXenonConfigs->g_pEspConfig->m_fHealthBarWidth * scaleFactor;
	int margin = 3;

	//ImVec2 minBottomLeftBg = ImVec2(targetScreenFeetPos.x - (targetWidth / 2) - barWidth, targetScreenFeetPos.y);
	//ImVec2 maxTopRightBg = ImVec2(targetScreenHeadPos.x - (targetWidth / 2), targetScreenHeadPos.y);

	//ImVec2 minBottomLeftFilled = ImVec2(targetScreenFeetPos.x - (targetWidth / 2) - barWidth + margin, targetScreenFeetPos.y - margin);
	//ImVec2 maxTopRightFilled = ImVec2(targetScreenHeadPos.x - (targetWidth / 2) - margin, (targetScreenFeetPos.y + margin) - currentHeight);

	ImVec2 minBottomLeftBg = ImVec2(targetScreenFeetPos.x - (targetWidth / 2) - barWidth, targetScreenFeetPos.y);
	ImVec2 maxTopRightBg = ImVec2(minBottomLeftBg.x + barWidth, targetScreenHeadPos.y);

	ImVec2 minBottomLeftFilled = ImVec2(minBottomLeftBg.x + margin, targetScreenFeetPos.y - margin);
	ImVec2 maxTopRightFilled = ImVec2(minBottomLeftBg.x + barWidth - margin, (targetScreenFeetPos.y + margin) - currentHeight);

	ImGui::GetBackgroundDrawList()->AddRectFilled(minBottomLeftBg, maxTopRightBg, g_pXenonConfigs->g_pEspConfig->m_cHealthBarBg);
	ImGui::GetBackgroundDrawList()->AddRectFilled(minBottomLeftFilled, maxTopRightFilled, g_pXenonConfigs->g_pEspConfig->m_cHealthBarFilled);

	ImVec2 center = ImVec2(minBottomLeftBg.x + barWidth / 2, maxTopRightBg.y + height / 2);

	if (g_pXenonConfigs->g_pEspConfig->m_bTextInHealthBar) {
		char healthStr[100];
		sprintf_s(healthStr, "%d", static_cast<int>(target->m_fHealth));

		center.x -= ImGui::CalcTextSize(healthStr).x / 2.0f;

		ImGui::GetBackgroundDrawList()->AddText(center, g_pXenonConfigs->g_pEspConfig->m_cHealthBarText, healthStr);
	}

}