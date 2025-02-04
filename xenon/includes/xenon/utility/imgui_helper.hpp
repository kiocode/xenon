#pragma once

#include <string>
#include <sstream>
#include <wtypes.h>

#include <imgui/imgui.h>
#include <xenon/models/hotkey.hpp>

/// @brief Subtracts two ImVec2 vectors.
/// @param lhs The left-hand side vector.
/// @param rhs The right-hand side vector.
/// @return The result of the subtraction.
inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) {
    return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

/// @brief Divides an ImVec2 vector by a scalar.
/// @param lhs The vector to be divided.
/// @param rhs The scalar divisor.
/// @return The result of the division.
inline ImVec2 operator/(const ImVec2& lhs, float rhs) {
    return ImVec2(lhs.x / rhs, lhs.y / rhs);
}

/// @brief Multiplies an ImVec2 vector by a scalar.
/// @param lhs The vector to be multiplied.
/// @param rhs The scalar multiplier.
/// @return The result of the multiplication.
inline ImVec2 operator*(const ImVec2& lhs, float rhs) {
    return ImVec2(lhs.x * rhs, lhs.y * rhs);
}

/// @brief Adds two ImVec2 vectors.
/// @param lhs The left-hand side vector.
/// @param rhs The right-hand side vector.
/// @return The result of the addition.
inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) {
    return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

namespace ImGuiHelper {

    /// @brief Centers the text within the specified rectangle.
    /// @param min The top-left corner of the rectangle.
    /// @param max The bottom-right corner of the rectangle.
    /// @param text The text to be centered.
    /// @return The position where the text should be placed to be centered.
    static ImVec2 CenterText(ImVec2 min, ImVec2 max, const char* text) {
        return min + (max - min) / 2.0f - ImGui::CalcTextSize(text) / 2.0f;
    }

    /// @brief Displays a help marker icon and shows a tooltip with the description when hovered.
    /// @param desc The description to show in the tooltip.
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

    /// @brief Adds text to the screen at a specified position with a given color.
    /// @param pos The position to draw the text.
    /// @param text The text to be drawn.
    /// @param color The color of the text.
    static void AddText(ImVec2 pos, char* text, ImColor color) {
        auto DrawList = ImGui::GetForegroundDrawList();
        auto wText = text;

        auto Size = ImGui::CalcTextSize(wText);
        pos.x -= Size.x / 2.f;
        pos.y -= Size.y / 2.f;

        DrawList->AddText(ImVec2(pos.x + 1, pos.y + 1), ImColor(0, 0, 0, 255), wText);
        DrawList->AddText(ImVec2(pos.x, pos.y), color, wText);
    }

    /// @brief Draws outlined text on the background draw list with an optional center alignment.
    /// @param pFont The font used to render the text.
    /// @param pos The position to draw the text.
    /// @param size The font size.
    /// @param color The color of the text.
    /// @param center If true, the text will be center-aligned.
    /// @param text The formatted text to be drawn.
    /// @return The y-coordinate after the text is drawn.
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

    /// @brief Draws outlined text on the foreground draw list with an optional center alignment.
    /// @param pFont The font used to render the text.
    /// @param pos The position to draw the text.
    /// @param size The font size.
    /// @param color The color of the text.
    /// @param center If true, the text will be center-aligned.
    /// @param text The formatted text to be drawn.
    /// @return The y-coordinate after the text is drawn.
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

}
