#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <windows.h>

#include <xenon/di_manager.hpp>
#include <xenon/features/aimbot.hpp>
#include <xenon/builder.hpp>

static float randomFloat(double min, double max) {
	return min + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (max - min)));
}

int main()
{

	Builder builder;
	//builder.m_services.AddSingleton<IAimbot>([&container]() { return std::make_shared<Aimbot>(container.GetService<ILogger>()); });
	builder.Services.AddSingleton<IAimbot, Aimbot>();

	std::shared_ptr<IAimbot> c_pAimbot = builder.Services.GetService<IAimbot>();

	while (true) 
	{

		if (GetAsyncKeyState(VK_ESCAPE) && 1) {
			break;
		}

		Vec2 randomPos{ randomFloat(0,1080), randomFloat(0, 1920)};

		c_pAimbot->SetTarget(randomPos);
		c_pAimbot->Aim();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	return 0;
}