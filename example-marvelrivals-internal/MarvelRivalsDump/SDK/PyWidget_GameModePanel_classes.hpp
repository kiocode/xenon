#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_GameModePanel

#include "Basic.hpp"

#include "UMG_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_GameModePanel.PyWidget_GameModePanel
// 0x0000 (0x03B8 - 0x03B8)
class UPyWidget_GameModePanel : public UUserWidget
{
public:
	void OnInitialized();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_GameModePanel">();
	}
	static class UPyWidget_GameModePanel* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_GameModePanel>();
	}
};
static_assert(alignof(UPyWidget_GameModePanel) == 0x000008, "Wrong alignment on UPyWidget_GameModePanel");
static_assert(sizeof(UPyWidget_GameModePanel) == 0x0003B8, "Wrong size on UPyWidget_GameModePanel");

}

