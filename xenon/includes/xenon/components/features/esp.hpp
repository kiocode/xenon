#pragma once

#include <xenon/components/component.hpp>

class CEsp : public CComponent {
public:

    void RenderSnapline(TargetProfile* target) const;
    void Render2DBox(TargetProfile* target) const;
    void Render3DBox(TargetProfile* target) const;
    void RenderSkeleton(TargetProfile* target) const;
    void RenderHealthBar(TargetProfile* target) const;

    void UpdateCurrentTarget(TargetProfile* target) override;
};
