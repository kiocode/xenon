#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_DeveloperLetter

#include "Basic.hpp"

#include "PyWidget_ModuleMainPanel_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_DeveloperLetter.PyWidget_DeveloperLetter
// 0x0000 (0x0618 - 0x0618)
class UPyWidget_DeveloperLetter final : public UPyWidget_ModuleMainPanel
{
public:
	void OnInitialized();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_DeveloperLetter">();
	}
	static class UPyWidget_DeveloperLetter* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_DeveloperLetter>();
	}
};
static_assert(alignof(UPyWidget_DeveloperLetter) == 0x000008, "Wrong alignment on UPyWidget_DeveloperLetter");
static_assert(sizeof(UPyWidget_DeveloperLetter) == 0x000618, "Wrong size on UPyWidget_DeveloperLetter");

}

