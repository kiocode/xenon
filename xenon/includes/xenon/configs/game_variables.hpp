#pragma once

#include <vector>
#include <xenon/models/profiles/target_profile.hpp>

/**
 * @class GameVariables
 * @brief Stores game-related variables for managing targets and the local player.
 *
 * This class holds information about available targets and the local player,
 * as well as a reference to the nearest target.
 */
class GameVariables {
public:
    /**
     * @brief A vector containing all currently available targets in the game.
     */
    std::vector<TargetProfile> g_vTargets;

    /**
     * @brief The local player's profile.
     */
    TargetProfile g_vLocal;

    /**
     * @brief Pointer to the nearest available target.
     *
     * If no valid target is found, this pointer will be `nullptr`.
     */
    TargetProfile* g_vNearestTarget = nullptr;
};
