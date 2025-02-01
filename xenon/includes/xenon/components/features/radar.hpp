#pragma once

#include <xenon/components/component.hpp>

#include <xenon/utility/vec2.hpp>
#include <xenon/models/enums/radar_shape.hpp>

class Radar : public CComponent {
public:
	
	void Render();

	void RenderRadarBase(RadarShape shape, bool is3D);

	void Update() override;

};