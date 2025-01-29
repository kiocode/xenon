#ifndef XENON_COMPONENTS_AIMBOT_HPP
#define XENON_COMPONENTS_AIMBOT_HPP

#include <xenon/components/component.hpp>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>

class Aimbot : public CComponent {
public:

    bool IsTargetEmpty() const;
    void SetTarget(Vec2& pos);
    bool IsTargetReached() const;
    void ResetTarget();

    void AimTarget();
    void AimTargetWithPrediction(Vec2& vel);

    void Update() override;

private:
    Vec2 m_vTarget;

};

#endif // XENON_COMPONENTS_AIMBOT_HPP
