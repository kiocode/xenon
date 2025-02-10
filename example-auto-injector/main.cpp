#include <spdlog/spdlog.h>

#include <xenon/xenon.hpp>
#include <xenon/components/services/injection_service.hpp>

void Inject(std::string dllPath, std::string exePath, std::string launchOptions) {
	Builder builder("Custom Injector");

	builder.SetDebugLogLevel();

	spdlog::info("Game Path: {}", exePath);
	spdlog::info("DLL Path: {}", dllPath);

	HANDLE hProcess, hThread;
	if (!builder.xenon->g_cInjectionService->OpenGame(&hProcess, &hThread, exePath, launchOptions))
	{
		spdlog::error("Failed to open game process.");

		system("pause");
		return;
	}

	builder.xenon->g_cInjectionService->Inject(hProcess, dllPath, InjectionType::LoadLibraryDLL);

	Sleep(3000);
	ResumeThread(hThread);
	CloseHandle(hProcess);
}


int main()
{

	//Inject("E:\\Projects\\xenon\\example-redmatch2-internal\\build\\example-redmatch2-internal.dll", "D:\\Steam\\steamapps\\common\\Redmatch 2\\Redmatch 2.exe", "");
	Inject("E:\\Projects\\xenon\\example-amongus-internal\\build\\example-amongus-internal.dll", "D:\\Among Us\\Among Us.exe", "");


	return 0;
}