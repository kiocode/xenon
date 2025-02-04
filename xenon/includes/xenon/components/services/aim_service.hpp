#pragma once

#include <xenon/components/component.hpp>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/models/profiles/target_profile.hpp>

/**
 * @class AimService
 * @brief A class responsible for handling the aiming and recoil control in the Xenon framework.
 *
 * The AimService class extends from CComponent and provides functionality for aiming at targets,
 * handling recoil, and performing various aiming-related operations like smoothing and humanizing the
 * movement of the cursor.
 */
class AimService : public CComponent {
public:

    /**
     * @brief Keeps the recoil effect under control.
     *
     * This method is responsible for managing recoil, ensuring the weapon stays on target
     * despite the natural recoil forces.
     */
    void KeepRecoil();

    /**
     * @brief Aims at a specified target position.
     * @param target The position of the target to aim at.
     *
     * This method moves the aim to the given target position.
     */
    void Aim(Vec2& target);

    /**
     * @brief Spins the aim in 2D space.
     *
     * This method continuously spins the aim in a 2D space, usually for features like
     * aimbot or targeting adjustments.
     */
    void Spin2D();

    /**
     * @brief Spins the aim in 3D space.
     *
     * This method continuously spins the aim in a 3D space, used for more complex aiming adjustments.
     */
    void Spin3D();

    /**
     * @brief Retrieves the nearest target position from a list of targets.
     * @param targets A list of targets to check.
     * @param local The local player or the origin from which to calculate the nearest target.
     * @return The position of the nearest target.
     *
     * This method checks all the provided targets and returns the position of the one that is closest
     * to the local player or origin.
     */
    Vec2* GetNearestPos(std::vector<TargetProfile> targets, TargetProfile local);

    /**
     * @brief Retrieves the nearest target position with a maximum distance limit.
     * @param targets A list of targets to check.
     * @param local The local player or the origin from which to calculate the nearest target.
     * @param maxdist The maximum allowable distance to the target.
     * @return The position of the nearest target, within the specified distance.
     *
     * This method checks all the provided targets and returns the position of the one that is closest
     * to the local player or origin, while ensuring the target is within the specified maximum distance.
     */
    Vec2* GetNearestPos(std::vector<TargetProfile> targets, TargetProfile local, float maxdist);

    /**
     * @brief Updates the aiming system during each game cycle.
     *
     * This method is responsible for updating the aim system, performing necessary checks
     * and adjustments to the aim or recoil state as the game progresses.
     */
    void Update() override;

private:
    /**
     * @brief Sets the aim position.
     * @param pos The position to set the aim to.
     *
     * This method adjusts the aim to the specified position.
     */
    void SetAimPos(Vec2 pos);

    /**
     * @brief Moves the mouse cursor to a specific position.
     * @param pos The position to move the mouse to.
     *
     * This method moves the mouse cursor to the given screen position.
     */
    void SetMouseTo(Vec2 pos);

    /**
     * @brief Moves the mouse cursor smoothly to a target position.
     * @param pos The position to move the mouse to.
     *
     * This method ensures the mouse cursor moves to the specified position smoothly,
     * potentially applying acceleration or deceleration for a more human-like movement.
     */
    void MoveMouseTo(Vec2 pos);

    /**
     * @brief Tracks the mouse movement.
     *
     * This method continuously tracks the movement of the mouse and applies adjustments
     * as necessary for the aiming system.
     */
    void TrackMouse();

    /**
     * @brief Humanizes the aim movement.
     * @param target The target position to humanize.
     *
     * This method adjusts the target movement to simulate human-like aiming behavior
     * to make the system less detectable or unnatural.
     */
    void Humanize(Vec2& target);

    /**
     * @brief Smoothly moves the aim to a target position.
     * @param target The target position to move the aim to.
     *
     * This method smooths out the aiming process to prevent erratic movements and ensure
     * more fluid aiming.
     */
    void SmoothMoveToTarget(Vec2& target);

    /**
     * @brief Generates Bezier control points for smooth movement.
     * @param start The starting position of the movement.
     * @param target The target position to move towards.
     * @return A vector of control points used to generate the Bezier curve.
     *
     * This method generates the control points required for a Bezier curve to smooth the movement.
     */
    std::vector<Vec2> GenerateBezierControlPoints(const Vec2& start, const Vec2& target);

    /**
     * @brief Calculates a specific point on a Bezier curve.
     * @param t A value between 0 and 1 representing the position on the curve.
     * @param points The control points for the Bezier curve.
     * @return The calculated point on the curve.
     *
     * This method computes the position of a point on the Bezier curve for the given time parameter t.
     */
    Vec2 CalculateBezierPoint(float t, const std::vector<Vec2>& points);
};
