#pragma once

/**
 * @class WaypointsConfig
 * @brief Configuration settings for rendering waypoints in the world and radar.
 *
 * This class provides customizable options for waypoint rendering,
 * including visibility, size, and whether names should be displayed.
 */
class WaypointsConfig {
public:
    /**
     * @brief Determines if waypoints should be rendered in the 3D world.
     */
    bool m_bRenderInWorld = true;

    /**
     * @brief Determines if waypoint names should be displayed in the 3D world.
     */
    bool m_bNamesInWorld = true;

    /**
     * @brief Size of waypoints in the 3D world.
     */
    float m_fSizeInWorld = 30;

    /**
     * @brief Determines if waypoints should be rendered in the radar.
     */
    bool m_bRenderInRadar = true;

    /**
     * @brief Determines if waypoint names should be displayed in the radar.
     */
    bool m_bNamesInRadar = true;

    /**
     * @brief Size of waypoints in the radar.
     */
    float m_fSizeInRadar = 3;
};
