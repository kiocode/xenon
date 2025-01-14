#pragma once

#include <memory>
#include <vector>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/core/system.hpp>
#include <xenon/models/profiles/target_profile.hpp>

class AimService {
public:

    AimService(
        std::shared_ptr<AimConfig> configs,
        std::shared_ptr<System> system
    ) : m_pConfigs(configs), m_pSystem(system) { }

    void KeepRecoil();
    void Aim(Vec2& target);
    void Spin2D();
    void Spin3D();

    Vec2* GetNearestPos(std::vector<TargetProfile> targets, TargetProfile local);
    Vec2* GetNearestPos(std::vector<TargetProfile> targets, TargetProfile local, float maxdist);

private:
    std::shared_ptr<AimConfig> m_pConfigs;
    std::shared_ptr<System> m_pSystem;

    void SetAimPos(Vec2 pos);
    void SetMouseTo(Vec2 pos);
    void MoveMouseTo(Vec2 pos);
    void TrackMouse();
    void Humanize(Vec2& target);
    void SmoothMoveToTarget(Vec2& target);
    std::vector<Vec2> GenerateBezierControlPoints(const Vec2& start, const Vec2& target);
    Vec2 CalculateBezierPoint(float t, const std::vector<Vec2>& points);
};
