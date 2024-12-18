#include <xenon/services/aim_service.hpp>
#include <spdlog/spdlog.h>


void AimService::Aim(Vec2* target) {

    if (target == nullptr) {
        spdlog::error("Impossible to use aim if target is null");
        return;
    }

    if (m_pConfigs->m_bSmooth) {
        SmoothMoveToTarget(target);
    }
    else if (m_pConfigs->m_bHumanize) {
        Humanize(target);
    }
    else {
        MoveDirectlyToTarget(target);
    }

    spdlog::debug("Aiming at {}, {}", target->x, target->y);

    if (IsTargetReached()) {
        ResetTarget();
    }
}
