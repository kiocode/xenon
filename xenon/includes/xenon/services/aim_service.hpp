#pragma once

#include <memory>
#include <vector>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>

class AimService {
public:
    AimService(
        std::shared_ptr<AimConfig> configs
    ) : m_pConfigs(configs) { }

	void KeepRecoil(double offset);
	void Aim(Vec2& target);

private:
    std::shared_ptr<AimConfig> m_pConfigs;

    void TrackMouse();
    void Humanize(Vec2& target);
    void SmoothMoveToTarget(Vec2& target);
    std::vector<Vec2> GenerateBezierControlPoints(const Vec2& start, const Vec2& target);
    Vec2 CalculateBezierPoint(float t, const std::vector<Vec2>& points);
};