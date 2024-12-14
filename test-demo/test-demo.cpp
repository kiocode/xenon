#include <iostream>
#include <di_manager.hpp>
#include <aimbot.hpp>

int main()
{

	DIManager manager;
	manager.AddSingleton<IAimbot, Aimbot>();

	auto aimbot = manager.GetService<IAimbot>();

	return 0;
}