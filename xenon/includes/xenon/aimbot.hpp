#pragma once

#include <xenon/interfaces/aimbot_interface.hpp>
#include <xenon/interfaces/logger_interface.hpp>

#include <memory>

class Aimbot : public IAimbot {
public:

	Aimbot() { }

	void Aim() override;
	void Humanize() override;

private:

};