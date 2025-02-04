#pragma once

#include <functional>

/**
 * @class RadarConfig
 * @brief Configuration settings for the radar system.
 *
 * This class holds various parameters for customizing the radar,
 * including size, zoom level, and target display options.
 */
class RadarConfig {
public:
    /**
     * @brief The radar type identifier.
     */
    int m_nType;

    /**
     * @brief The overall size of the radar.
     */
    float m_fSize = 200;

    /**
     * @brief The size of target indicators on the radar.
     */
    float m_fTargetsSize = 6;

    /**
     * @brief The size of the local player indicator on the radar.
     */
    float m_fLocalSize = 5;

    /**
     * @brief The default scale of the radar.
     */
    float m_fDefaultScale = 1000;

    /**
     * @brief The zoom factor for the radar display.
     */
    float m_fZoom = 1;

    /**
     * @brief Whether to display target names on the radar.
     */
    bool m_bTargetsName = true;

    /**
     * @brief A custom function for rendering or modifying the radar.
     */
    std::function<void()> m_fnCustomRadar;
};
