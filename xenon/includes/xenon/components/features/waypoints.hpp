#pragma once

#include <xenon/components/component.hpp>

#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>
#include <xenon/models/waypoint.hpp>

#include <imgui/imgui.h>

/**
 * @class CWaypoints
 * @brief A class that manages and renders waypoints in both world space and radar view.
 *
 * The CWaypoints class extends from CComponent and provides functionality for storing,
 * rendering, and interacting with waypoints in a game or application. It supports both
 * world and radar views, allowing waypoints to be set in 2D or 3D space.
 */
class CWaypoints : public CComponent {
public:

    /**
     * @brief Sets a waypoint with a title, position, and color in 2D space.
     * @param title The title of the waypoint.
     * @param pos The 2D position of the waypoint.
     * @param color The color of the waypoint.
     *
     * This method adds a 2D waypoint with the specified attributes to the waypoint list.
     */
    void SetWaypoint(std::string title, const Vec2& pos, ImColor color);

    /**
     * @brief Sets a waypoint with a title, position, and color in 3D space.
     * @param title The title of the waypoint.
     * @param pos The 3D position of the waypoint.
     * @param color The color of the waypoint.
     *
     * This method adds a 3D waypoint with the specified attributes to the waypoint list.
     */
    void SetWaypoint(std::string title, const Vec3& pos, ImColor color);

    /**
     * @brief Retrieves the list of all set waypoints.
     * @return A vector containing all waypoints.
     *
     * This method returns a list of all the waypoints that have been set and stored.
     */
    std::vector<Waypoint> GetWaypoints();

    /**
     * @brief Clears all the waypoints.
     *
     * This method removes all waypoints from the list, effectively clearing the stored waypoints.
     */
    void ClearWaypoints();

    /**
     * @brief Renders the waypoints in the world space.
     *
     * This method is responsible for drawing the waypoints within the game world, making them
     * visible in 3D or 2D depending on the context.
     */
    void RenderInWorld();

    /**
     * @brief Renders the waypoints on the radar, using 2D positions.
     * @param fnIsPointInRadar A function that checks if a given point is within the radar's view.
     * @param localPos The 2D position of the waypoints relative to the radar's center.
     * @param defaultScale The default scale of the waypoints on the radar.
     * @param radarSize The size of the radar.
     * @param zoomFactor The current zoom level of the radar.
     * @param radarCenter The center of the radar view.
     *
     * This method draws the waypoints on the radar view in 2D, considering zoom and radar size.
     */
    void RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec2 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter);

    /**
     * @brief Renders the waypoints on the radar, using 3D positions.
     * @param fnIsPointInRadar A function that checks if a given point is within the radar's view.
     * @param localPos The 3D position of the waypoints relative to the radar's center.
     * @param defaultScale The default scale of the waypoints on the radar.
     * @param radarSize The size of the radar.
     * @param zoomFactor The current zoom level of the radar.
     * @param radarCenter The center of the radar view.
     *
     * This method draws the waypoints on the radar view in 3D, considering zoom and radar size.
     */
    void RenderInRadar(std::function<bool(ImVec2)> fnIsPointInRadar, Vec3 localPos, float defaultScale, float radarSize, float zoomFactor, ImVec2 radarCenter);

    /**
     * @brief Updates the waypoints during each game cycle.
     *
     * This method updates the waypoints, checking for any changes that need to be applied
     * to the waypoints or their rendering state.
     */
    void Update() override;

private:
    /**
     * @brief A vector of all waypoints stored by the system.
     */
    std::vector<Waypoint> m_vWaypoints;
};
