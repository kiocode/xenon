#pragma once

#include <functional>
#include <imgui/imgui.h>

/**
 * @class AimConfig
 * @brief Configuration for the aimbot settings and behavior.
 *
 * This class defines the various settings related to the aimbot system, including properties
 * for aim smoothness, field of view (FOV), recoil handling, spinbot behavior, and custom aim
 * functionality. It also includes a color setting for the FOV display in the UI.
 */
class AimConfig {
public:

    /**
     * @brief The maximum distance at which the aimbot can lock onto a target.
     * Default is 500 units.
     */
    float m_fNearest = 500;

    /**
     * @brief The smoothness factor for the aimbot's movement when aiming.
     * Default is 10.
     */
    float m_fSmooth = 10;

    /**
     * @brief The field of view (FOV) for the aimbot to search for targets.
     * Default is 40 degrees.
     */
    float m_fFov = 60;

    /**
     * @brief The speed at which the aimbot compensates for recoil tilt.
     * Default is 0 (no recoil tilt compensation).
     */
    float m_fRecoilTiltSpeed = 0;

    /**
     * @brief The strength of the recoil tilt applied by the aimbot.
     * Default is 0 (no recoil tilt).
     */
    float m_fRecoilTiltStrength = 0;

    /**
     * @brief The vertical strength of the recoil applied by the aimbot.
     * Default is 0 (no vertical recoil compensation).
     */
    float m_fRecoilVerticalStrength = 0;

    /**
     * @brief The speed of the spinbot, which automatically rotates the player model.
     * Default is 10 units.
     */
    float m_fSpinbotSpeed = 10;

    /**
     * @brief The radius within which the spinbot will rotate the player model.
     * Default is 100 units.
     */
    float m_fSpinbotRadius = 100;

    /**
     * @brief The depth of the spinbot's movement, affecting how much it moves vertically.
     * Default is 5 units.
     */
    float m_fSpinbotDepth = 5;

    float m_fDistanceScale = 1;

    int m_nMouseInputMode = 0;

    int m_nAimTo = 0;

    /**
     * @brief The color used to render the FOV circle in the UI.
     * Default is white with full opacity (255, 255, 255, 255).
     */
    ImColor m_cFov = ImColor(255, 255, 255, 255);

    /**
     * @brief A custom function for the aimbot's targeting behavior.
     * This function receives the target position as input and adjusts the aim accordingly.
     */
    std::function<void(const Vec2&)> m_fnCustomAim;

    /**
     * @brief A function that returns the custom aim position.
     * This function allows the aimbot to aim based on external logic or custom calculations.
     * @return The custom aim position as a Vec2 object.
     */
    std::function<Vec2()> m_fnGetCustomAim;
};
