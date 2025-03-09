#include <string>
#include <functional>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

#include <xenon/utility/imgui_helper.hpp>

class Notification {
public:

	Notification(int index, std::string strTitle, std::string strMessage) : m_nIndex(index), m_strTitle(strTitle), m_strMessage(strMessage) { }

	void Render(ImFont* imFont, ImFont* imLogo){//, ImFont* imLogoBigger) {
		if(!imFont || !imLogo)// || !imLogoBigger)
			return;

		ImGui::Begin("Notification", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove);
		{
			if (m_bShowNotification && 1)
			{
				m_bShouldMove = false;

				m_fTimer += 2.f * ImGui::GetIO().DeltaTime;

				if (m_fTimer > 10.f)
					m_bShouldMove = true;

				if (m_fTimer > 20.0f)
				{
					m_fTimer = 0.f;
					m_bShowNotification = false;
				}
			}

			ImGuiContext& g = *GImGui;
			m_fAnim = ImLerp(m_fAnim, m_bShouldMove ? 0.f : 800.f, g.IO.DeltaTime * 6.f);
			if (m_fAnim <= 799.f)
				m_bShouldResize = true;
			else
				m_bShouldResize = false;

			m_fResizeAnim = ImLerp(m_fResizeAnim, m_bShouldResize ? 0.f : 310.f, g.IO.DeltaTime * 5.f);

			//sizing + pos
			ImGui::SetWindowSize(ImVec2(80 + m_fResizeAnim, 80));
			ImGui::SetWindowPos(ImVec2(20, -780 + m_fAnim + (85 * 0)));

			//helpers def
			ImVec2 startPos = ImGui::GetWindowPos() + ImVec2(5, 5);

			//main draws
			ImGui::GetWindowDrawList()->AddRectFilled(startPos, ImVec2(startPos.x + 70 + m_fResizeAnim, startPos.y + 50), ImColor(0, 79, 65, 255), 20.f); //bg
			ImGui::GetWindowDrawList()->AddRect(startPos, ImVec2(startPos.x + 70 + m_fResizeAnim, startPos.y + 50), ImColor(0, 229, 189, 255), 20.f, 0, 1.5f); //rect

			////m_imLogo
			//ImGui::PushFont(imLogo);
			//ImGui::SetCursorPos(ImVec2(15, 7));
			//ImGui::TextColored(ImColor(255, 255, 255, 255), "A");
			//ImGui::SetCursorPos(ImVec2(15, 7));
			//ImGui::TextColored(ImColor(0, 229, 189), "B");
			//ImGui::SetCursorPos(ImVec2(15, 7));
			//ImGui::TextColored(ImColor(0, 229, 189), "C");
			//ImGui::PopFont();

			//render notifts
			ImGui::PushFont(imFont);
			ImGui::SetCursorPos(ImVec2(25, 13));
			ImGui::TextColored(ImColor(255, 255, 255, 255), m_strTitle.c_str());
			ImGui::PopFont();

			ImGui::SetCursorPos(ImVec2(25, 32));
			ImGui::TextColored(ImColor(255, 255, 255, 255), m_strMessage.c_str());
		}
		ImGui::End();
	}


private:
	int m_nIndex;

	std::string m_strTitle;
	std::string m_strMessage;

	bool m_bShowNotification = true;
	bool m_bShouldMove = true;
	bool m_bShouldResize = true;
	float m_fAnim = 0.f;
	float m_fResizeAnim = 0.f;
	float m_fTimer = 0.f;
};