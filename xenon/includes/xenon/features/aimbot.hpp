#pragma once

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/services/aim_service.hpp>
#include <xenon/features/feature.hpp>

class Aimbot : public Feature {
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
