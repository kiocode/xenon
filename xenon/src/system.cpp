#include <chrono>

#include <xenon/core/system.hpp>

float System::GetPlayTime() const {
	return std::chrono::steady_clock::now().time_since_epoch().count() - g_fStartPlayTime;
}
