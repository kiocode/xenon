#include <spdlog/spdlog.h>

#include <xenon/xenon.hpp>
#include <xenon/components/services/injection_service.hpp>

int main()
{

	Builder builder("Custom AmongUs Injector");

	builder.SetDebugLogLevel();

	//CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	std::string exePath = "D:\\Among Us\\Among Us.exe";
	std::string launchOptions = "";
	std::string dllPath = "E:\\Projects\\xenon\\example-amongus-internal\\build\\example-amongus-internal.dll";
	spdlog::info("Game Path: {}", exePath);
	spdlog::info("DLL Path: {}", dllPath);

	//CoUninitialize();

	HANDLE hProcess, hThread;
	if (!builder.xenon->g_cInjectionService->OpenGame(&hProcess, &hThread, exePath, launchOptions))
	{
		spdlog::error("Failed to open game process.");

		system("pause");
		return 1;
	}

	builder.xenon->g_cInjectionService->Inject(hProcess, dllPath, InjectionType::LoadLibraryDLL);

	Sleep(3000);
	ResumeThread(hThread);
	CloseHandle(hProcess);
	return 0;
}