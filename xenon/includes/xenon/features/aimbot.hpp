#pragma once

#include <xenon/interfaces/aimbot_interface.hpp>

#include <memory>

class Aimbot : public IAimbot {
public:

	void SetTarget(Vec2 pos) override;
	void Humanize() override;
	void Aim() override;

private:
	Vec2 m_vTarget;
};