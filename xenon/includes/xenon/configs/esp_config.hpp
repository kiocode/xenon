#pragma once

#include <functional>
#include <imgui/imgui.h>

/**
 * @class EspConfig
 * @brief Configuration for the ESP (Extra Sensory Perception) feature, controlling the visual rendering of enemy information.
 *
 * This class defines the settings for rendering visual elements such as snaplines, 2D and 3D boxes, health bars, and skeletons.
 * It also includes color settings for each visual element and custom functionality for obtaining bone screen positions.
 */
class EspConfig {
public:

    /**
     * @brief The type of snapline to be drawn at the start (0: None, 1: Horizontal, 2: Vertical).
     * Default is 0 (No snapline).
     */
    int m_nSnaplineTypeStart = 0;

    /**
     * @brief The type of snapline to be drawn at the end (0: None, 1: Horizontal, 2: Vertical).
     * Default is 2 (Vertical snapline).
     */
    int m_nSnaplineTypeEnd = 2;

    /**
     * @brief The type of 2D box to be drawn (0: Simple, 1: Filled).
     * Default is 0 (Simple 2D box).
     */
    int m_nBox2DType = 0;

    /**
     * @brief Whether to display the distance inside the 2D box.
     * Default is true (distance shown inside the box).
     */
    bool m_bDistanceInBox = true;

    /**
     * @brief Whether to display the health bar.
     * Default is true (health bar displayed).
     */
    bool m_bHealthBar = true;

    /**
     * @brief Whether to display text inside the health bar.
     * Default is true (text inside health bar).
     */
    bool m_bTextInHealthBar = true;

    /**
     * @brief The length of the health bar.
     * Default is 25 units.
     */
    float m_fHealthBarWidth = 25;

    /**
     * @brief The color of the snapline.
     * Default is white with full opacity (255, 255, 255, 255).
     */
    ImColor m_cSnapline = ImColor(255, 255, 255, 255);

    /**
     * @brief The color of the 2D box.
     * Default is white with full opacity (255, 255, 255, 255).
     */
    ImColor m_cBox2D = ImColor(255, 255, 255, 255);

    /**
     * @brief The color of the distance text inside the 2D box.
     * Default is black with full opacity (0, 0, 0, 255).
     */
    ImColor m_cBox2DDistance = ImColor(0, 0, 0, 255);

    /**
     * @brief The color of the 3D box.
     * Default is white with full opacity (255, 255, 255, 255).
     */
    ImColor m_cBox3D = ImColor(255, 255, 255, 255);

    /**
     * @brief The color of the skeleton (player bones).
     * Default is white with full opacity (255, 255, 255, 255).
     */
    ImColor m_cSkeleton = ImColor(255, 255, 255, 255);

    /**
     * @brief The background color of the health bar.
     * Default is black with full opacity (0, 0, 0, 255).
     */
    ImColor m_cHealthBarBg = ImColor(0, 0, 0, 255);

    /**
     * @brief The color of the filled portion of the health bar.
     * Default is green with full opacity (0, 255, 0, 255).
     */
    ImColor m_cHealthBarFilled = ImColor(0, 255, 0, 255);

    /**
     * @brief The color of the text inside the health bar.
     * Default is red with full opacity (255, 0, 0, 255).
     */
    ImColor m_cHealthBarText = ImColor(255, 0, 0, 255);

    /**
     * @brief A list of bone pairs used for drawing the skeleton.
     * Each pair defines the start and end bones of a line segment to be drawn.
     */
    std::vector<std::pair<int, int>> m_tBonePairs;

    /**
     * @brief A function that retrieves the screen position of a bone from its index.
     * @param index The bone index.
     * @return The screen position of the bone as a Vec2 object.
     */
    std::function<Vec2(int)> m_fnGetBoneScreenPosFromIndex;
};
