#pragma once

#include <xenon/components/component.hpp>

#include <xenon/utility/vec2.hpp>
#include <xenon/models/enums/radar_shape.hpp>

/**
 * @class Radar
 * @brief A class responsible for rendering and updating radar components in the Xenon framework.
 *
 * The Radar class extends from CComponent and provides functionality for rendering radar visuals
 * with different shapes and in 3D space, as well as updating the radar elements during each game cycle.
 */
class Radar : public CComponent {
public:

    /**
     * @brief Renders the radar.
     *
     * This method is responsible for rendering the radar interface, which may include displaying the radar
     * elements like targets and other relevant information.
     */
    void Render();

    /**
     * @brief Renders the base of the radar with a specified shape and dimensionality.
     * @param shape The shape of the radar (e.g., circular, square, etc.).
     * @param is3D Whether to render the radar in 3D space (true) or 2D (false).
     *
     * This method draws the radar's base, which can be customized based on the shape and the dimensional view.
     */
    void RenderRadarBase(RadarShape shape, bool is3D);

    /**
     * @brief Updates the radar components during each game cycle.
     *
     * This method is responsible for updating the radar's state, including the position of elements
     * and any visual or dynamic changes that need to occur each frame.
     */
    void Update() override;
};
