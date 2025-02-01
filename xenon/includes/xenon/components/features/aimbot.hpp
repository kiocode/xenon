#pragma once

#include <xenon/components/component.hpp>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>

class Aimbot : public CComponent {
public:

    void Init() override {
        nearestDistance = g_pXenonConfigs->g_pAimConfig->m_fNearest;
    }

    bool IsTargetEmpty() const;
    void SetTarget(Vec2& pos);
    bool IsTargetReached() const;
    void ResetTarget();

    void AimTarget();
    void AimTargetWithPrediction(Vec2& vel);

    void UpdateCurrentTarget(TargetProfile* target) override;

private:
    Vec2 m_vTarget;

    float nearestDistance = 0;
};