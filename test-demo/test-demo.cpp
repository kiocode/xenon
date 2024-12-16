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

	#pragma region Register Configurations

	std::shared_ptr<AimbotConfig> pAimbotConfig = builder.Services.AddConfiguration<AimbotConfig>();
	pAimbotConfig->m_vScreenCenter = { 1080, 1920 };
	pAimbotConfig->m_bStartFromCenter = true;

	std::shared_ptr<AimbotConfig> pAimbotConfig2 = builder.Services.GetConfiguration<AimbotConfig>();

	#pragma endregion

	#pragma region Register Services

	//builder.m_services.AddSingleton<IAimbot>([&container]() { return std::make_shared<Aimbot>(container.GetService<ILogger>()); });
	builder.Services.AddSingleton<IAimbot>([&builder]() {
		return std::make_shared<Aimbot>(builder.Services.GetConfiguration<AimbotConfig>());
	});

	#pragma endregion

	#pragma region Tests

	std::shared_ptr<IAimbot> c_pAimbot = builder.Services.GetService<IAimbot>();

	while (true) 
	{

		if (GetAsyncKeyState(VK_ESCAPE) && 1) {
			break;
		}

		if (c_pAimbot->IsTargetEmpty()) {
			Vec2 randomPos{ randomFloat(0,1080), randomFloat(0, 1920)};
			c_pAimbot->SetTarget(randomPos);
		}
		c_pAimbot->Aim();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	#pragma endregion

	return 0;
}