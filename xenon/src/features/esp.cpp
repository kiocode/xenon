#include <xenon/features/esp.hpp>

#include <xenon/utility/imgui_helper.hpp>

void ESP::RenderSnapline() {

	for (auto& target : m_pGameVariables->g_vTargetsScreen) {

		switch (m_pConfigs->m_nSnaplineType)
		{
			case 0:
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(m_pSystem->GetScreenCenter().x, m_pSystem->GetScreenCenter().y), ImVec2(target.x, target.y), m_pConfigs->m_cSnapline, 1.0f);
				break;
			case 1:
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(m_pSystem->GetScreenCenter().x, 0), ImVec2(target.x, target.y), m_pConfigs->m_cSnapline, 1.0f);
				break;
			case 2:
				ImGui::GetBackgroundDrawList()->AddLine(ImVec2(m_pSystem->GetScreenCenter().x, m_pSystem->GetScreenResolution().y), ImVec2(target.x, target.y), m_pConfigs->m_cSnapline, 1.0f);
				break;
		}

	}

}

void ESP::Render2DBox() {

	for (auto& target : m_pGameVariables->g_vTargetsScreen) {

		ImVec2 head = ImVec2(target.x, target.y);
		ImVec2 feet = ImVec2(target.x, target.y + 64);

		ImVec2 minBottomLeft = ImVec2(feet.x - 32, feet.y);
		ImVec2 maxTopRight = ImVec2(head.x + 32, head.y);

		ImColor colorAlpha = m_pConfigs->m_cBox2D;
		colorAlpha.Value.w = 0.5f;

		ImGui::GetBackgroundDrawList()->AddRectFilled(minBottomLeft, maxTopRight, colorAlpha, 0, 0);
		ImGui::GetBackgroundDrawList()->AddRect(minBottomLeft, maxTopRight, m_pConfigs->m_cBox2D, 0, 0);

	}

}

void ESP::Render3DBox() {

}

void ESP::RenderSkeleton() {

}

void ESP::RenderHealthbar() {
}