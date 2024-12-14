#include "logger.hpp"

#include <iostream>

void Logger::LogInfo(const char* message)
{
	std::cout << message << std::endl;
}
