#pragma once

#include <xenon/components/component.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>

class CAimbot : public CComponent {
public:

    void Init() override {
        nearestDistance = g_pXenonConfigs->g_pAimConfig->m_nNearest;
    }

    bool IsTargetEmpty() const;

    void SetTarget(Vec2& pos);

    bool IsTargetReached() const;

    void ResetTarget();

    void AimTarget();

    void AimTargetWithPrediction(Vec2& vel);

    void Update() override;

private:

    Vec2 m_vTarget;

    float nearestDistance = 0;
    TargetProfile lockedTarget;
    TargetProfile nearestTarget;
    bool hasLockedTarget = false;

};
