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

	std::shared_ptr<AimbotConfig> pAimbotConfig = builder.Services.AddConfiguration<AimbotConfig>();
	pAimbotConfig->m_bHumanize = true;
	//pAimbotConfig->m_bStartFromCenter = true;
	//pAimbotConfig->m_bSmooth = true;
	//pAimbotConfig->m_fSmooth = 30;

	#pragma endregion

	#pragma region Register Services

	//builder.m_services.AddSingleton<IAimbot>([&container]() { return std::make_shared<Aimbot>(container.GetService<ILogger>()); });
	builder.Services.AddSingleton<Aimbot>([&builder]() {
		return std::make_shared<Aimbot>(builder.Services.GetConfiguration<AimbotConfig>(), builder.Services.GetService<Game>(), builder.Services.GetService<AimService>());
	});	

	#pragma endregion

	builder.BuildAndRun();

	#pragma region Tests

	std::shared_ptr<Aimbot> c_pAimbot = builder.Services.GetService<Aimbot>();

	while (true) 
	{

		if (GetAsyncKeyState(VK_ESCAPE)) {
			continue; 
		}

		//if (c_pAimbot->IsTargetEmpty()) {
		//	Vec2 randomPos{ round(Random::randomFloat(0, builder.GameManager->g_vScreenResolution.x - 1)),  round(Random::randomFloat(0, builder.GameManager->g_vScreenResolution.y - 1))};
		//	c_pAimbot->SetTarget(randomPos);
		//}
		//c_pAimbot->AimTarget();


		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	#pragma endregion

	return 0;
}
