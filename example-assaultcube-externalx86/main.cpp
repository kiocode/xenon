#include <iostream>

#include <xenon/xenon.hpp>
#include <xenon/core/builder.hpp>
#include <xenon/models/enums/game_dimensions.hpp>

struct offsets {
	uintptr_t staticFovAddr = 0x18A7CC;
	uintptr_t staticPlayersCountAddr = 0x18AC0C;
	uintptr_t staticEntityListAddr = 0x18AC04;

	uintptr_t staticLocalPlayerAddr = 0x195404;
	uintptr_t playerAmmoOffset = 0x140;

};

struct offsets offsets;

int main()
{

	Builder builder("AssaultCube external");
	builder.SystemVariables->IsInternal(false);
	builder.SystemVariables->SetGameDimension(GameDimension::DIM_3D);
	builder.SetConsoleEnabled();
	builder.SetDebugLogLevel();

	builder.MemoryManager->AttachGame("D:\\AssaultCube 1.3.0.2\\bin_win32\\ac_client.exe");
	//uintptr_t fovAddr = builder.MemoryManager->ReadPointer(offsets.staticFovAddr);
	//uintptr_t playersCountAddr = builder.MemoryManager->ReadPointer(offsets.staticPlayersCountAddr);
	//uintptr_t entityListAddr = builder.MemoryManager->ReadPointer(offsets.staticEntityListAddr);
	uintptr_t localPlayerAddr = builder.MemoryManager->ReadPointer(offsets.staticLocalPlayerAddr)- 0x200000000;

	if (!localPlayerAddr){// || !fovAddr || !playersCountAddr || !entityListAddr) {
		spdlog::error("Failed to find fov, players count, local player or entity list address");
		return 1;
	}

	builder.GameManager->OnEvent("Update", [builder, localPlayerAddr]() {
		spdlog::info("Ammo: {}", builder.MemoryManager->Read<int>(localPlayerAddr + offsets.playerAmmoOffset));
	});

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom();
	cheat.UseUIMenu();

	/*builder.SystemVariables->m_fnW2S3D = [builder](Vec3 pos) -> Vec2* {
		return new Vec2(0,0);
	};*/

	cheat.Run();
}