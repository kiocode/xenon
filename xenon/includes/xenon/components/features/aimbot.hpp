#pragma once

#include <xenon/components/component.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>

/**
 * @class Aimbot
 * @brief A class responsible for managing and controlling the aimbot functionality in the Xenon framework.
 *
 * The Aimbot class extends from CComponent and provides various methods for targeting and aiming mechanics,
 * including target selection, aim prediction, and target resetting.
 */
class Aimbot : public CComponent {
public:

    /**
     * @brief Initializes the aimbot with the nearest distance configuration.
     *
     * This method retrieves the nearest targeting distance from the configuration and sets it.
     */
    void Init() override {
        nearestDistance = g_pXenonConfigs->g_pAimConfig->m_fNearest;
    }

    /**
     * @brief Checks if the current target is empty.
     * @return True if no target is set, otherwise false.
     */
    bool IsTargetEmpty() const;

    /**
     * @brief Sets the position of the current target.
     * @param pos The target position as a Vec2 object.
     */
    void SetTarget(Vec2& pos);

    /**
     * @brief Checks if the current target has been reached.
     * @return True if the target has been reached, otherwise false.
     */
    bool IsTargetReached() const;

    /**
     * @brief Resets the current target to an empty state.
     */
    void ResetTarget();

    /**
     * @brief Aims at the current target.
     *
     * This method performs the aiming operation at the current target, without considering prediction.
     */
    void AimTarget();

    /**
     * @brief Aims at the current target with prediction based on velocity.
     * @param vel The velocity of the target as a Vec2 object.
     */
    void AimTargetWithPrediction(Vec2& vel);

    /**
     * @brief Updates the current target based on the provided target profile.
     * @param target The target profile to update the current target.
     */
    void UpdateCurrentTarget(TargetProfile* target) override;

private:
    /**
     * @brief The current target position as a 2D vector.
     */
    Vec2 m_vTarget;

    /**
     * @brief The nearest distance used for target selection, initialized from configuration.
     */
    float nearestDistance = 0;
};
