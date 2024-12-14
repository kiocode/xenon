#include <iostream>
#include <di_manager.hpp>
#include <aimbot.hpp>
#include <logger.hpp>
#include <memory>

int main()
{

	DIManager container;
	container.AddSingleton<ILogger, Logger>();
	container.AddSingleton<IAimbot>([&container]() { return std::make_shared<Aimbot>(container.GetService<ILogger>()); });

	std::shared_ptr<IAimbot> aimbot = container.GetService<IAimbot>();
	aimbot->Aim();

	return 0;
}