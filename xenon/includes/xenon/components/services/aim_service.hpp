#pragma once

#include <xenon/components/component.hpp>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/models/profiles/target_profile.hpp>

class CAimService : public CComponent {
public:

    void KeepRecoil();

    void Aim(Vec2& target);

    void Spin2D();

    void Spin3D();

    void Update() override;

private:

    void SetAimPos(Vec2 pos);

    void MouseMove(float tarx, float tary, float X, float Y, int smooth);

    void SetMouseTo(Vec2 pos);

    void MoveMouseTo(Vec2 pos);

    void TrackMouse();

    void Humanize(Vec2& target);

    void SmoothMoveToTarget(Vec2& target);

    std::vector<Vec2> GenerateBezierControlPoints(const Vec2& start, const Vec2& target);

    Vec2 CalculateBezierPoint(float t, const std::vector<Vec2>& points);
};
