#include <Windows.h>
#include <spdlog/spdlog.h>

#include "manual-mapping.hpp"

enum class InjectionType
{
	LoadLibraryDLL,
	ManualMap
};

bool LoadLibraryDLL(HANDLE hProc, const std::string& dllpath)
{
	HMODULE hKernel = GetModuleHandle("kernel32.dll");
	if (hKernel == NULL)
	{
		spdlog::error("Failed to get kernel32.dll module address.");
		return false;
	}

	LPVOID pLoadLibrary = (LPVOID)GetProcAddress(hKernel, "LoadLibraryA");
	if (pLoadLibrary == NULL)
	{
		spdlog::error("Failed to get LoadLibraryA address.");
		return false;
	}

	LPVOID pDLLPath = VirtualAllocEx(hProc, NULL, strlen(dllpath.c_str()) + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (pDLLPath == NULL)
	{
		spdlog::error("Failed to allocate memory for DLLPath in target process.");
		return false;
	}

	BOOL writeResult = WriteProcessMemory(hProc, pDLLPath, dllpath.c_str(), strlen(dllpath.c_str()), NULL);
	if (writeResult == FALSE)
	{
		spdlog::error("Failed to write remote process memory.");
		return false;
	}

	HANDLE hThread = CreateRemoteThread(hProc, NULL, NULL, (LPTHREAD_START_ROUTINE)pLoadLibrary, (LPVOID)pDLLPath, NULL, NULL);
	if (hThread == NULL)
	{
		spdlog::error("Failed to create remote thread.");
		VirtualFreeEx(hProc, pDLLPath, 0, MEM_RELEASE);
		return false;
	}

	if (WaitForSingleObject(hThread, 2000) == WAIT_OBJECT_0)
	{
		VirtualFreeEx(hProc, pDLLPath, 0, MEM_RELEASE);
	}

	CloseHandle(hThread);

	spdlog::info("Successfully injected DLL using LoadLibrary.");
	return true;
}

void Inject(HANDLE hProcess, const std::string& dllPath, InjectionType type)
{
	switch (type)
	{
	case InjectionType::LoadLibraryDLL:
		if (!LoadLibraryDLL(hProcess, dllPath))
			spdlog::error("Failed to inject DLL using LoadLibrary.");
		break;
	case InjectionType::ManualMap:
		if (!ManualMapDLL(hProcess, dllPath))
			spdlog::error("Failed to inject DLL using ManualMap.");
		break;
	default:
		if (!LoadLibraryDLL(hProcess, dllPath))
			spdlog::error("Failed to inject DLL using LoadLibrary.");
		break;
	}
}

std::string GetLastErrorAsString(DWORD errorId)
{
	auto errorMessageID = errorId == 0 ? GetLastError() : errorId;
	if (errorMessageID == 0)
		return std::string();

	LPSTR messageBuffer = nullptr;
	auto size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	std::string message(messageBuffer, size);
	LocalFree(messageBuffer);
	return message;
}

bool OpenGame(HANDLE* phProcess, HANDLE* phThread, std::string exePath, std::string launchOptions)
{
	STARTUPINFOA si{};
	PROCESS_INFORMATION pi{};

	auto procName = exePath.substr(exePath.find_last_of("\\") + 1);
	auto cmdLine = exePath + " " + launchOptions;

	if (!CreateProcess(exePath.c_str(), (LPSTR)cmdLine.c_str(), nullptr, nullptr, FALSE, CREATE_SUSPENDED, nullptr, nullptr, &si, &pi))
	{
		spdlog::error("CreateProcess failed: {}", GetLastErrorAsString(0));
		return false;
	}

	*phProcess = pi.hProcess;
	*phThread = pi.hThread;

	return true;
}

int main()
{
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	std::string exePath = "D:\\Among Us\\Among Us.exe";
	std::string launchOptions = "";
	std::string dllPath = "E:\\Projects\\xenon\\example-amongus-internal\\build\\example-amongus-internal.dll";
	spdlog::info("Game Path: {}", exePath);
	spdlog::info("DLL Path: {}", dllPath);

	CoUninitialize();

	HANDLE hProcess, hThread;
	if (!OpenGame(&hProcess, &hThread, exePath, launchOptions))
	{
		spdlog::error("Failed to open game process.");

		system("pause");
		return 1;
	}

	Inject(hProcess, dllPath, InjectionType::LoadLibraryDLL);

	Sleep(3000);
	ResumeThread(hThread);
	CloseHandle(hProcess);
	return 0;
}