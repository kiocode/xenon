#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <windows.h>

#include <xenon/core/di_manager.hpp>
#include <xenon/features/aimbot.hpp>
#include <xenon/core/builder.hpp>
#include <xenon/utility/random.hpp>
#include <xenon/services/aim_service.hpp>

int main()
{

	Builder core;
    core.SetDebugLogLevel();

	//core.SetGameAbsolutePath("D:\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");

	// maybe centralize in Built class
	core.UseUpdate();
	core.UseRecoil();

	#pragma region Register Configurations

	std::shared_ptr<AimConfig> pAimbotConfig = core.Services.GetConfiguration<AimConfig>();
	//pAimbotConfig->m_bHumanize = true;
	//pAimbotConfig->m_bStartFromCenter = true;
	//pAimbotConfig->m_bSmooth = true;
	//pAimbotConfig->m_fSmooth = 30;
	//pAimbotConfig->m_fRecoilTiltStrength = 0;
	pAimbotConfig->m_fRecoilVerticalStrength = 60;
	
	#pragma endregion

	#pragma region Register Services

	//builder.m_services.AddSingleton<IAimbot>([]() { return std::make_shared<Aimbot>(container.GetService<ILogger>()); });

	#pragma endregion

	ExternalCheat cheat = core.BuildExternal();

	cheat.Run();

	#pragma region Tests

	//std::shared_ptr<Aimbot> c_pAimbot = builder.Services.GetService<Aimbot>();
	//std::shared_ptr<AimService> c_pAimService = builder.Services.GetService<AimService>();

	//auto previousTime = std::chrono::steady_clock::now();
	//builder.GameManager->g_fStartPlayTime = previousTime.time_since_epoch().count();
	//while (true) 
	//{
	//	auto currentTime = std::chrono::steady_clock::now();
	//	builder.GameManager->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count() * 100;
	//	previousTime = currentTime;


	//	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	//}

	#pragma endregion

	return 0;
}
