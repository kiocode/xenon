#pragma once

#include <string>
#include <sstream>
#include <wtypes.h>

#include <imgui/imgui.h>
#include <xenon/models/hotkey.hpp>

inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) {
	return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline ImVec2 operator/(const ImVec2& lhs, float rhs) {
	return ImVec2(lhs.x / rhs, lhs.y / rhs);
}

inline ImVec2 operator*(const ImVec2& lhs, float rhs) {
	return ImVec2(lhs.x * rhs, lhs.y * rhs);
}

inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) {
	return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

namespace ImGuiHelper {

	static ImFont* g_pGameFont;

	static void RenderHotkeyEditor(Hotkey* hotkey, bool* isEditing) {

		//if(hotkey == nullptr) return;
		//if(isEditing == nullptr) return;

		//if (isEditing) {
		//	ImGui::Text("Press the combination...");
		//	if (ImGui::IsKeyDown(ImGuiKey_Escape)) {
		//		*isEditing = false;
		//	}
		//	for (int key = 0; key < IM_ARRAYSIZE(ImGui::GetIO().KeysDown); ++key) {
		//		if (ImGui::IsKeyDown((ImGuiKey)key)) {
		//			hotkey->key = key;
		//			hotkey->modifiers.clear();
		//			if (ImGui::GetIO().KeyCtrl) hotkey->modifiers.push_back(ImGuiKey_LeftCtrl);
		//			if (ImGui::GetIO().KeyAlt) hotkey->modifiers.push_back(ImGuiKey_LeftAlt);
		//			if (ImGui::GetIO().KeyShift) hotkey->modifiers.push_back(ImGuiKey_LeftShift);
		//			*isEditing = false;
		//			break;
		//		}
		//	}
		//}
		//else {
		//	std::string hotkeyText = "Key: " + std::to_string(hotkey->key);
		//	if (!hotkey->modifiers.empty()) hotkeyText += " + Modifers";
		//	if (ImGui::Button(hotkeyText.c_str())) {
		//		*isEditing = true;
		//	}
		//}
	}

	static void HelpMarker(const char* desc) {
		ImGui::TextDisabled("[?]");
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
			ImGui::TextUnformatted(desc);
			ImGui::PopTextWrapPos();
			ImGui::EndTooltip();
		}
	}

	static void AddText(ImVec2 pos, char* text, ImColor color) {
		auto DrawList = ImGui::GetForegroundDrawList();
		auto wText = text;

		auto Size = ImGui::CalcTextSize(wText);
		pos.x -= Size.x / 2.f;
		pos.y -= Size.y / 2.f;

		//	ImGui::PushFont(m_font);

		DrawList->AddText(ImVec2(pos.x + 1, pos.y + 1), ImColor(0, 0, 0, 255), wText);
		DrawList->AddText(ImVec2(pos.x, pos.y), color, wText);

		//	ImGui::PopFont();
	}

	static float DrawOutlinedText(ImFont* pFont, const ImVec2& pos, float size, ImU32 color, bool center, const char* text, ...) {
		va_list(args);
		va_start(args, text);

		CHAR wbuffer[256] = { };
		vsprintf_s(wbuffer, text, args);

		va_end(args);

		auto DrawList = ImGui::GetBackgroundDrawList();

		std::stringstream stream(text);
		std::string line;

		float y = 0.0f;
		int i = 0;

		while (std::getline(stream, line))
		{
			ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, wbuffer);

			if (center)
			{
				DrawList->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);

				DrawList->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), ImGui::GetColorU32(color), wbuffer);
			}
			else
			{
				DrawList->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);

				DrawList->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * i), ImGui::GetColorU32(color), wbuffer);
			}

			y = pos.y + textSize.y * (i + 1);
			i++;
		}
		return y;
	}
	static float DrawOutlinedTextForeground(ImFont* pFont, const ImVec2& pos, float size, ImU32 color, bool center, const char* text, ...) {

		va_list(args);
		va_start(args, text);

		CHAR wbuffer[256] = { };
		vsprintf_s(wbuffer, text, args);

		va_end(args);

		auto DrawList = ImGui::GetForegroundDrawList();

		std::stringstream stream(text);
		std::string line;

		float y = 0.0f;
		int i = 0;

		while (std::getline(stream, line))
		{
			ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, wbuffer);

			if (center)
			{
				DrawList->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);

				DrawList->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), ImGui::GetColorU32(color), wbuffer);
			}
			else
			{
				DrawList->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);
				DrawList->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), wbuffer);

				DrawList->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * i), ImGui::GetColorU32(color), wbuffer);
			}

			y = pos.y + textSize.y * (i + 1);
			i++;
		}
		return y;
	}

	//static void HealthBar(float x, float y, float w, float h, int phealth, ImColor col) {
	//	auto vList = ImGui::GetBackgroundDrawList();

	//	int healthValue = max(0, min(phealth, 100));

	//	int barColor = ImColor(min(510 * (100 - healthValue) / 100, 255), min(510 * healthValue / 100, 255), 25, 255);
	//	vList->AddRect(ImVec2(x - 1, y - 1), ImVec2(x + w + 1, y + h + 1), col);
	//	RectFilled(x, y, x + w, y + (((float)h / 100.0f) * (float)phealth), barColor, 0.0f, 0);
	//}
}

