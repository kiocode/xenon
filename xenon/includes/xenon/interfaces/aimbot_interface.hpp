#pragma once
#include <xenon/utility/vec2.hpp>

__interface IAimbot
{
	virtual bool IsTargetEmpty() = 0;
	//virtual bool IsTargetReached() = 0;
	virtual void SetTarget(Vec2 pos) = 0;
	virtual void Aim() = 0;
	virtual void Humanize() = 0;
};