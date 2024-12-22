#pragma once

#include <memory>
#include <vector>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/core/system.hpp>

class AimService {
public:

	void KeepRecoil();
	void Aim(Vec2& target);

    AimService(
        std::shared_ptr<AimConfig> configs,
        std::shared_ptr<System> system
    ) : m_pConfigs(configs), m_pSystem(system) { }

private:
    std::shared_ptr<AimConfig> m_pConfigs;
    std::shared_ptr<System> m_pSystem;

    void SetMouseTo(Vec2 pos);
    void MoveMouseTo(Vec2 pos);
    void TrackMouse();
    void Humanize(Vec2& target);
    void SmoothMoveToTarget(Vec2& target);
    std::vector<Vec2> GenerateBezierControlPoints(const Vec2& start, const Vec2& target);
    Vec2 CalculateBezierPoint(float t, const std::vector<Vec2>& points);
};