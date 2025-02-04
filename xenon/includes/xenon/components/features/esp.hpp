#pragma once

#include <xenon/components/component.hpp>

/**
 * @class Esp
 * @brief A class responsible for rendering various ESP (Extra Sensory Perception) elements in the Xenon framework.
 *
 * The Esp class extends from CComponent and provides methods to render various in-game elements, such as snaplines, boxes,
 * skeletons, and health bars. These visual aids are commonly used in cheats to enhance player awareness and targeting.
 */
class Esp : public CComponent {
public:

    /**
     * @brief Renders a snapline to the target.
     *
     * This method draws a line from the player's view to the target, commonly used in ESP for easier targeting.
     */
    void RenderSnapline() const;

    /**
     * @brief Renders a 2D bounding box around the target.
     *
     * This method draws a 2D box around the target, giving a visual representation of the target's position on the screen.
     */
    void Render2DBox() const;

    /**
     * @brief Renders a 3D bounding box around the target.
     *
     * This method draws a 3D box around the target to represent its boundaries in the 3D world space.
     */
    void Render3DBox() const;

    /**
     * @brief Renders the skeleton of the target.
     *
     * This method draws the skeleton of the target, often used for detecting and tracking the player's body parts.
     */
    void RenderSkeleton() const;

    /**
     * @brief Renders a health bar above the target.
     *
     * This method draws a health bar above the target to represent the target's current health status visually.
     */
    void RenderHealthBar() const;

    /**
     * @brief Updates the ESP rendering elements.
     *
     * This method is called to update the ESP elements on the screen, such as re-drawing or updating their positions.
     */
    void Update() override;
};
