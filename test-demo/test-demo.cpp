#include <iostream>
#include <xenon/di_manager.hpp>
#include <xenon/aimbot.hpp>
#include <xenon/logger.hpp>
#include <memory>

int main()
{

	DIManager container;
	//container.AddSingleton<IAimbot>([&container]() { return std::make_shared<Aimbot>(container.GetService<ILogger>()); });
	container.AddSingleton<IAimbot, Aimbot>();

	std::shared_ptr<IAimbot> aimbot = container.GetService<IAimbot>();
	aimbot->Aim();

	return 0;
}