#pragma once

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/services/aim_service.hpp>

class Aimbot {
public:
    Aimbot(
        std::shared_ptr<AimConfig> configs,
        std::shared_ptr<AimService> aimService
    ) : m_pConfigs(configs), m_pAimService(aimService) { }

    bool IsTargetEmpty() const;
    void SetTarget(Vec2& pos);
    bool IsTargetReached() const;
    void ResetTarget();

    void AimTarget();
    void AimTargetWithPrediction(Vec2& vel);

private:
    std::shared_ptr<AimConfig> m_pConfigs;
    std::shared_ptr<AimService> m_pAimService;
    Vec2 m_vTarget;

};
