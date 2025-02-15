#include <xenon/components/services/injection_service.hpp>

#include <spdlog/spdlog.h>

bool CInjectionService::ManualMapDLL(HANDLE hProc, const std::string& filepath)
{
	std::ifstream file(filepath, std::ios::in | std::ios::binary | std::ios::ate);
	if (!file.is_open())
	{
		spdlog::error("Error while reading DLL file!");
		return false;
	}

	std::streampos size = file.tellg();
	auto memblock = new char[size];
	file.seekg(0, std::ios::beg);
	file.read(memblock, size);
	file.close();

	BYTE* fileContent = (BYTE*)memblock;

	bool result = ManualMapDLL(hProc, fileContent, size, true, true, false, false, DLL_PROCESS_ATTACH);

	delete[] memblock;

	return result;
}

bool CInjectionService::LoadLibraryDLL(HANDLE hProc, const std::string& dllpath)
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

void CInjectionService::Inject(HANDLE hProcess, const std::string& dllPath, InjectionType type)
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
	}
}

bool CInjectionService::OpenGame(HANDLE* phProcess, HANDLE* phThread, std::string exePath, std::string launchOptions)
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

#pragma region CInjectionService::Private

std::string CInjectionService::GetLastErrorAsString(DWORD errorId)
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

#pragma runtime_checks( "", off )
#pragma optimize( "", off )
void __stdcall CInjectionService::Shellcode(ManualMappingData* pData)
{
	if (!pData)
	{
		pData->hMod = (HINSTANCE)0x404040;
		return;
	}

	BYTE* pBase = pData->pbase;
	auto* pOpt = &reinterpret_cast<IMAGE_NT_HEADERS*>(pBase + reinterpret_cast<IMAGE_DOS_HEADER*>((uintptr_t)pBase)->e_lfanew)->OptionalHeader;

	auto _LoadLibraryA = pData->pLoadLibraryA;
	auto _GetProcAddress = pData->pGetProcAddress;
#ifdef _WIN64
	auto _RtlAddFunctionTable = pData->pRtlAddFunctionTable;
#endif
	auto _DllMain = reinterpret_cast<f_DLL_ENTRY_POINT>(pBase + pOpt->AddressOfEntryPoint);

	BYTE* LocationDelta = pBase - pOpt->ImageBase;
	if (LocationDelta)
	{
		if (pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size)
		{
			auto* pRelocData = reinterpret_cast<IMAGE_BASE_RELOCATION*>(pBase + pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
			const auto* pRelocEnd = reinterpret_cast<IMAGE_BASE_RELOCATION*>(reinterpret_cast<uintptr_t>(pRelocData) + pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size);
			while (pRelocData < pRelocEnd && pRelocData->SizeOfBlock)
			{
				UINT AmountOfEntries = (pRelocData->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
				WORD* pRelativeInfo = reinterpret_cast<WORD*>(pRelocData + 1);

				for (UINT i = 0; i != AmountOfEntries; ++i, ++pRelativeInfo)
				{
					if (RELOC_FLAG(*pRelativeInfo))
					{
						UINT_PTR* pPatch = reinterpret_cast<UINT_PTR*>(pBase + pRelocData->VirtualAddress + ((*pRelativeInfo) & 0xFFF));
						*pPatch += reinterpret_cast<UINT_PTR>(LocationDelta);
					}
				}
				pRelocData = reinterpret_cast<IMAGE_BASE_RELOCATION*>(reinterpret_cast<BYTE*>(pRelocData) + pRelocData->SizeOfBlock);
			}
		}
	}

	if (pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
	{
		auto* pImportDescr = reinterpret_cast<IMAGE_IMPORT_DESCRIPTOR*>(pBase + pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
		while (pImportDescr->Name)
		{
			char* szMod = reinterpret_cast<char*>(pBase + pImportDescr->Name);
			HINSTANCE hDll = _LoadLibraryA(szMod);

			ULONG_PTR* pThunkRef = reinterpret_cast<ULONG_PTR*>(pBase + pImportDescr->OriginalFirstThunk);
			ULONG_PTR* pFuncRef = reinterpret_cast<ULONG_PTR*>(pBase + pImportDescr->FirstThunk);

			if (!pThunkRef)
				pThunkRef = pFuncRef;

			for (; *pThunkRef; ++pThunkRef, ++pFuncRef)
			{
				if (IMAGE_SNAP_BY_ORDINAL(*pThunkRef))
				{
					*pFuncRef = (ULONG_PTR)_GetProcAddress(hDll, reinterpret_cast<char*>(*pThunkRef & 0xFFFF));
				}
				else
				{
					auto* pImport = reinterpret_cast<IMAGE_IMPORT_BY_NAME*>(pBase + (*pThunkRef));
					*pFuncRef = (ULONG_PTR)_GetProcAddress(hDll, pImport->Name);
				}
			}
			++pImportDescr;
		}
	}

	if (pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size)
	{
		auto* pTLS = reinterpret_cast<IMAGE_TLS_DIRECTORY*>(pBase + pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress);
		auto* pCallback = reinterpret_cast<PIMAGE_TLS_CALLBACK*>(pTLS->AddressOfCallBacks);
		for (; pCallback && *pCallback; ++pCallback)
			(*pCallback)(pBase, DLL_PROCESS_ATTACH, nullptr);
	}

	bool ExceptionSupportFailed = false;

#ifdef _WIN64

	if (pData->SEHSupport)
	{
		auto excep = pOpt->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXCEPTION];
		if (excep.Size)
		{
			if (!_RtlAddFunctionTable(
				reinterpret_cast<IMAGE_RUNTIME_FUNCTION_ENTRY*>(pBase + excep.VirtualAddress),
				excep.Size / sizeof(IMAGE_RUNTIME_FUNCTION_ENTRY), (DWORD64)pBase))
			{
				ExceptionSupportFailed = true;
			}
		}
	}

#endif

	_DllMain(pBase, pData->fdwReasonParam, nullptr);

	if (ExceptionSupportFailed)
		pData->hMod = reinterpret_cast<HINSTANCE>(0x505050);
	else
		pData->hMod = reinterpret_cast<HINSTANCE>(pBase);
}

bool CInjectionService::ManualMapDLL(HANDLE hProc, BYTE* pSrcData, SIZE_T FileSize, bool ClearHeader, bool ClearNonNeededSections, bool AdjustProtections, bool SEHExceptionSupport, DWORD fdwReason)
{
	IMAGE_NT_HEADERS* pOldNtHeader = nullptr;
	IMAGE_OPTIONAL_HEADER* pOldOptHeader = nullptr;
	IMAGE_FILE_HEADER* pOldFileHeader = nullptr;
	BYTE* pTargetBase = nullptr;

	if (reinterpret_cast<IMAGE_DOS_HEADER*>(pSrcData)->e_magic != 0x5A4D)
	{ //"MZ"
		spdlog::error("Invalid file.");
		return false;
	}

	pOldNtHeader = reinterpret_cast<IMAGE_NT_HEADERS*>(pSrcData + reinterpret_cast<IMAGE_DOS_HEADER*>(pSrcData)->e_lfanew);
	pOldOptHeader = &pOldNtHeader->OptionalHeader;
	pOldFileHeader = &pOldNtHeader->FileHeader;

	if (pOldFileHeader->Machine != CURRENT_ARCH)
	{
		spdlog::error("Invalid platform.");
		return false;
	}

	pTargetBase = reinterpret_cast<BYTE*>(VirtualAllocEx(hProc, nullptr, pOldOptHeader->SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE));
	if (!pTargetBase)
	{
		spdlog::error("Failed to allocate memory in target process.");
		return false;
	}

	DWORD oldp = 0;
	VirtualProtectEx(hProc, pTargetBase, pOldOptHeader->SizeOfImage, PAGE_EXECUTE_READWRITE, &oldp);

	ManualMappingData data{ 0 };
	data.pLoadLibraryA = LoadLibraryA;
	data.pGetProcAddress = GetProcAddress;
#ifdef _WIN64
	data.pRtlAddFunctionTable = (f_RtlAddFunctionTable)RtlAddFunctionTable;
#else 
	SEHExceptionSupport = false;
#endif
	data.pbase = pTargetBase;
	data.fdwReasonParam = fdwReason;
	data.SEHSupport = SEHExceptionSupport;

	//File header
	if (!WriteProcessMemory(hProc, pTargetBase, pSrcData, 0x1000, nullptr))
	{ //only first 0x1000 bytes for the header
		spdlog::error("Failed to write file header.");

		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		return false;
	}

	IMAGE_SECTION_HEADER* pSectionHeader = IMAGE_FIRST_SECTION(pOldNtHeader);
	for (UINT i = 0; i != pOldFileHeader->NumberOfSections; ++i, ++pSectionHeader)
	{
		if (pSectionHeader->SizeOfRawData)
		{
			if (!WriteProcessMemory(hProc, pTargetBase + pSectionHeader->VirtualAddress, pSrcData + pSectionHeader->PointerToRawData, pSectionHeader->SizeOfRawData, nullptr))
			{
				spdlog::error("Failed to write section data.");
				VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
				return false;
			}
		}
	}

	//Mapping params
	BYTE* MappingDataAlloc = reinterpret_cast<BYTE*>(VirtualAllocEx(hProc, nullptr, sizeof(ManualMappingData), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE));
	if (!MappingDataAlloc)
	{
		spdlog::error("Failed to allocate memory for mapping data in target process.");
		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		return false;
	}

	if (!WriteProcessMemory(hProc, MappingDataAlloc, &data, sizeof(ManualMappingData), nullptr))
	{
		spdlog::error("Failed to write mapping data.");

		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		VirtualFreeEx(hProc, MappingDataAlloc, 0, MEM_RELEASE);
		return false;
	}

	//Shell code
	void* pShellcode = VirtualAllocEx(hProc, nullptr, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!pShellcode)
	{
		spdlog::error("Failed to allocate memory for shellcode in target process.");

		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		VirtualFreeEx(hProc, MappingDataAlloc, 0, MEM_RELEASE);
		return false;
	}

	if (!WriteProcessMemory(hProc, pShellcode, Shellcode, 0x1000, nullptr))
	{
		spdlog::error("Failed to write shellcode.");
		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		VirtualFreeEx(hProc, MappingDataAlloc, 0, MEM_RELEASE);
		VirtualFreeEx(hProc, pShellcode, 0, MEM_RELEASE);
		return false;
	}

	spdlog::info("Mapped DLL at {0:x}", reinterpret_cast<uintptr_t>(pTargetBase));
	spdlog::info("Mapping info at {0:x}", reinterpret_cast<uintptr_t>(MappingDataAlloc));
	spdlog::info("Shellcode at {0:x}", reinterpret_cast<uintptr_t>(pShellcode));

	spdlog::info("Data allocated");

	HANDLE hThread = CreateRemoteThread(hProc, nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(pShellcode), MappingDataAlloc, 0, nullptr);
	if (!hThread)
	{
		spdlog::error("Failed to create remote thread.");
		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		VirtualFreeEx(hProc, MappingDataAlloc, 0, MEM_RELEASE);
		VirtualFreeEx(hProc, pShellcode, 0, MEM_RELEASE);
		return false;
	}
	CloseHandle(hThread);

	HINSTANCE hCheck = NULL;
	while (!hCheck)
	{
		DWORD exitcode = 0;
		GetExitCodeProcess(hProc, &exitcode);
		if (exitcode != STILL_ACTIVE)
		{
			spdlog::error("Process crashed, exit code: {0:x}", exitcode);
			return false;
		}

		ManualMappingData data_checked{ 0 };
		ReadProcessMemory(hProc, MappingDataAlloc, &data_checked, sizeof(data_checked), nullptr);
		hCheck = data_checked.hMod;

		if (hCheck == (HINSTANCE)0x404040)
		{
			spdlog::error("Wrong mapping ptr.");
			VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
			VirtualFreeEx(hProc, MappingDataAlloc, 0, MEM_RELEASE);
			VirtualFreeEx(hProc, pShellcode, 0, MEM_RELEASE);
			return false;
		}
		else if (hCheck == (HINSTANCE)0x505050)
		{
			spdlog::error("Exception support failed.");
		}

		Sleep(10);
	}

	BYTE* emptyBuffer = (BYTE*)malloc(1024 * 1024 * 20);
	if (emptyBuffer == nullptr)
	{
		spdlog::error("Failed to allocate memory for empty buffer.");
		return false;
	}
	memset(emptyBuffer, 0, 1024 * 1024 * 20);

	//CLEAR PE HEAD
	if (ClearHeader)
	{
		if (!WriteProcessMemory(hProc, pTargetBase, emptyBuffer, 0x1000, nullptr))
		{
			spdlog::warn("Failed to clear header.");
		}
	}
	//END CLEAR PE HEAD


	if (ClearNonNeededSections)
	{
		pSectionHeader = IMAGE_FIRST_SECTION(pOldNtHeader);
		for (UINT i = 0; i != pOldFileHeader->NumberOfSections; ++i, ++pSectionHeader)
		{
			if (pSectionHeader->Misc.VirtualSize)
			{
				if ((SEHExceptionSupport ? 0 : strcmp((char*)pSectionHeader->Name, ".pdata") == 0) ||
					strcmp((char*)pSectionHeader->Name, ".rsrc") == 0 ||
					strcmp((char*)pSectionHeader->Name, ".reloc") == 0)
				{

					if (!WriteProcessMemory(hProc, pTargetBase + pSectionHeader->VirtualAddress, emptyBuffer, pSectionHeader->Misc.VirtualSize, nullptr))
					{
						spdlog::error("Failed to clear section");
					}
				}
			}
		}
	}

	if (AdjustProtections)
	{
		pSectionHeader = IMAGE_FIRST_SECTION(pOldNtHeader);
		for (UINT i = 0; i != pOldFileHeader->NumberOfSections; ++i, ++pSectionHeader)
		{
			if (pSectionHeader->Misc.VirtualSize)
			{
				DWORD old = 0;
				DWORD newP = PAGE_READONLY;

				if ((pSectionHeader->Characteristics & IMAGE_SCN_MEM_WRITE) > 0)
				{
					newP = PAGE_READONLY;
				}
				else if ((pSectionHeader->Characteristics & IMAGE_SCN_MEM_EXECUTE) > 0)
				{
					newP = PAGE_READONLY;
				}
				if (VirtualProtectEx(hProc, pTargetBase + pSectionHeader->VirtualAddress, pSectionHeader->Misc.VirtualSize, newP, &old))
				{
					//spdlog::info("Section {0} set as {1:x}", pSectionHeader->Name, newP);
				}
				else
				{
					//spdlog::error("Failed to set section {0} as {1:x}", pSectionHeader->Name, newP);
				}
			}
		}
		DWORD old = 0;
		VirtualProtectEx(hProc, pTargetBase, IMAGE_FIRST_SECTION(pOldNtHeader)->VirtualAddress, PAGE_READONLY, &old);
	}

	if (!WriteProcessMemory(hProc, pShellcode, emptyBuffer, 0x1000, nullptr))
	{
		spdlog::warn("Failed to clear shellcode.");
	}
	if (!VirtualFreeEx(hProc, pShellcode, 0, MEM_RELEASE))
	{
		spdlog::warn("Failed to release shellcode memory.");
	}
	if (!VirtualFreeEx(hProc, MappingDataAlloc, 0, MEM_RELEASE))
	{
		spdlog::warn("Failed to release mapping data memory.");
	}

	return true;
}

#pragma endregion