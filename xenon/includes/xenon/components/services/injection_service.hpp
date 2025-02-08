#pragma once

#include <Windows.h>

#include <fstream>

#include <xenon/components/component.hpp>
#include <xenon/models/enums/injection_type.hpp>
#include <xenon/models/structs/manual_mapping_data.hpp>

#ifdef _WIN64
#define CURRENT_ARCH IMAGE_FILE_MACHINE_AMD64
#else
#define CURRENT_ARCH IMAGE_FILE_MACHINE_I386
#endif

#define RELOC_FLAG32(RelInfo) ((RelInfo >> 0x0C) == IMAGE_REL_BASED_HIGHLOW)
#define RELOC_FLAG64(RelInfo) ((RelInfo >> 0x0C) == IMAGE_REL_BASED_DIR64)

#ifdef _WIN64
#define RELOC_FLAG RELOC_FLAG64
#else
#define RELOC_FLAG RELOC_FLAG32
#endif

class CInjectionService : public CComponent {
public:
	bool LoadLibraryDLL(HANDLE hProc, const std::string& dllpath);
	void Inject(HANDLE hProcess, const std::string& dllPath, InjectionType type);
	bool OpenGame(HANDLE* phProcess, HANDLE* phThread, std::string exePath, std::string launchOptions);
	bool ManualMapDLL(HANDLE hProc, const std::string& filepath);
private:
	static void __stdcall Shellcode(ManualMappingData* pData);
	std::string GetLastErrorAsString(DWORD errorId);
	bool ManualMapDLL(HANDLE hProc, BYTE* pSrcData, SIZE_T FileSize, bool ClearHeader, bool ClearNonNeededSections, bool AdjustProtections, bool SEHExceptionSupport, DWORD fdwReason);

};