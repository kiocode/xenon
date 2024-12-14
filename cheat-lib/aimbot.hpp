#pragma once

#include "interfaces/aimbot_interface.hpp"
#include "interfaces/logger_interface.hpp"

#include <memory>

class Aimbot : public IAimbot {
public:

	Aimbot(std::shared_ptr<ILogger> logger) : _logger(logger) { }

	void Aim() override;
	void Humanize() override;

private:

	std::shared_ptr<ILogger> _logger;
};