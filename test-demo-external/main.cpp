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
#include <memory/memory.h>

static void AddConfigurations(Builder& builder) {

	std::shared_ptr<AimConfig> pAimConfig = builder.Services.GetConfiguration<AimConfig>();
	//pAimbotConfig->m_bHumanize = true;
	//pAimbotConfig->m_bStartFromCenter = true;
	//pAimbotConfig->m_bSmooth = true;
	//pAimbotConfig->m_fSmooth = 30;
	//pAimbotConfig->m_fRecoilTiltStrength = 0;
	//pAimbotConfig->m_fRecoilVerticalStrength = 175; // ash
	//pAimbotConfig->m_fRecoilVerticalStrength = 185; // castle
	//pAimbotConfig->m_fRecoilVerticalStrength = 165; // dokkaebi
	//pAimbotConfig->m_fRecoilVerticalStrength = 165; // thermite
	pAimConfig->m_fRecoilVerticalStrength = 130; // mira
	pAimConfig->m_fSpinbotRadius = 100; 
	pAimConfig->m_fSpinbotSpeed = 10; 

}

static void AddServices(Builder& builder) {
	//builder.Services.AddSingleton<Aimbot>([]() { return std::make_shared<Aimbot>(); });
}

static void Test(Builder& builder) {
	/*std::shared_ptr<Aimbot> c_pAimbot = builder.Services.GetService<Aimbot>();
	std::shared_ptr<AimService> c_pAimService = builder.Services.GetService<AimService>();

	auto previousTime = std::chrono::steady_clock::now();
	builder.GameManager->g_fStartPlayTime = previousTime.time_since_epoch().count();
	while (true)
	{
		auto currentTime = std::chrono::steady_clock::now();
		builder.GameManager->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count() * 100;
		previousTime = currentTime;

		 c_pAimbot->SetTarget

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}*/
}

int main()
{
	#pragma region Offsets

	struct offsets {
		uintptr_t staticServerAddr = 0x5ABBA0;
		uintptr_t idLocalPlayer = 0x1450;
		uintptr_t onlinePlayers = 0x1454;
		uintptr_t gametick = 0x147C + 0x0;
		uintptr_t playerPos = 0x147C + 0xE8 + 0x0;
	};

	offsets offsets;

	#pragma endregion

	Builder builder;
	builder.SetDebugLogLevel();

	builder.MemoryManager->AttachGame("D:\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");
	uintptr_t baseAddr = builder.MemoryManager->GetModuleAddress();
	uintptr_t serverAddr = builder.MemoryManager->Read<uintptr_t>(baseAddr + offsets.staticServerAddr);

	AddConfigurations(builder);
	AddServices(builder);

	builder.GameManager->OnEvent("Update", [builder, offsets, serverAddr]() {

		// initialize a class with online players and players etc
		std::cout << "Online Players: " << builder.MemoryManager->Read<int>(serverAddr + offsets.onlinePlayers) << std::endl;
		std::cout << "Game Tick: " << builder.MemoryManager->Read<int>(serverAddr + offsets.gametick) << std::endl;
		std::cout << "Player Pos X: " << builder.MemoryManager->Read<float>(serverAddr + offsets.playerPos) << std::endl;
		std::cout << "Player Pos X: " << builder.MemoryManager->Read<float>(serverAddr + offsets.playerPos + 0x4) << std::endl;

	});

	ExternalCheat cheat = builder.BuildExternal();

	cheat.UseUpdate();
	//cheat.UseAimbot();
	//cheat.UseRecoil();
	//cheat.Use2DSpinbot();

	//builder.MemoryManager->DeattachGame();

	cheat.Run();

	Test(builder);

	return 0;
}
