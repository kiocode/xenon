#pragma once

#include "interfaces/logger_interface.hpp"

class Logger : public ILogger {
public:
	void LogInfo(const char* message);

};

