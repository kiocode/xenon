#pragma once

#include <xenon/components/component.hpp>

class Esp : public CComponent {
public:

	void RenderSnapline() const;
	void Render2DBox() const;
	void Render3DBox() const;
	void RenderSkeleton() const;
	void RenderHealthBar() const;

};