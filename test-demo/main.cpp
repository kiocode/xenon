#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <windows.h>

#include <xenon/di_manager.hpp>
#include <xenon/features/aimbot.hpp>
#include <xenon/builder.hpp>
#include <xenon/utility/random.hpp>
#include <xenon/services/aim_service.hpp>

int main()
{

	Builder builder;
    builder.SetDebugLogLevel();
	builder.DisableUpdate();

	builder.GameManager->SetGameAbsolutePath("D:\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");

	#pragma region Register Configurations

	std::shared_ptr<AimConfig> pAimbotConfig = builder.Services.GetConfiguration<AimConfig>();
	//pAimbotConfig->m_bHumanize = true;
	//pAimbotConfig->m_bStartFromCenter = true;
	//pAimbotConfig->m_bSmooth = true;
	//pAimbotConfig->m_fSmooth = 30;

	#pragma endregion

	#pragma region Register Services

	//builder.m_services.AddSingleton<IAimbot>([]() { return std::make_shared<Aimbot>(container.GetService<ILogger>()); });

	#pragma endregion

	builder.BuildAndRun();

	#pragma region Tests

	std::shared_ptr<Aimbot> c_pAimbot = builder.Services.GetService<Aimbot>();
	std::shared_ptr<AimService> c_pAimService = builder.Services.GetService<AimService>();

	while (true) 
	{

		if (GetAsyncKeyState(VK_ESCAPE)) {
			continue; 
		}

		/*if (c_pAimbot->IsTargetEmpty()) {
			Vec2 randomPos{ round(Random::randomFloat(0, builder.GameManager->g_vScreenResolution.x - 1)),  round(Random::randomFloat(0, builder.GameManager->g_vScreenResolution.y - 1))};
			c_pAimbot->SetTarget(randomPos);
		}
		c_pAimbot->AimTarget();*/

		if (GetAsyncKeyState(VK_RBUTTON)) {
			c_pAimService->KeepRecoil(0, 10);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	#pragma endregion

	return 0;
}
