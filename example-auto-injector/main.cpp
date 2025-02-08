#include <spdlog/spdlog.h>

#include <xenon/xenon.hpp>
#include <xenon/components/services/injection_service.hpp>

int main()
{

	Builder builder("Custom RedMatch2 Injector");

	builder.SetDebugLogLevel();

	std::string exePath = "D:\\Steam\\steamapps\\common\\Redmatch 2\\Redmatch 2.exe";
	std::string launchOptions = "";
	std::string dllPath = "E:\\Projects\\xenon\\example-redmatch2-internal\\build\\example-redmatch2-internal.dll";
	spdlog::info("Game Path: {}", exePath);
	spdlog::info("DLL Path: {}", dllPath);

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