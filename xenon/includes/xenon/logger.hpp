#pragma once

#include <xenon/interfaces/logger_interface.hpp>

class Logger : public ILogger {
public:
	void LogInfo(const char* message);

};

