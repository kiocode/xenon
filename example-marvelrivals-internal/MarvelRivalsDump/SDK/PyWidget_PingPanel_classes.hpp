#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_PingPanel

#include "Basic.hpp"

#include "PyMarvelUserWidget_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_PingPanel.PyWidget_PingPanel
// 0x0008 (0x05F8 - 0x05F0)
class UPyWidget_PingPanel : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x7];                                      // 0x05E9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UPyDataAsset_Ping*                      PingInfoDataAsset;                                 // 0x05F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_PingPanel">();
	}
	static class UPyWidget_PingPanel* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_PingPanel>();
	}
};
static_assert(alignof(UPyWidget_PingPanel) == 0x000008, "Wrong alignment on UPyWidget_PingPanel");
static_assert(sizeof(UPyWidget_PingPanel) == 0x0005F8, "Wrong size on UPyWidget_PingPanel");
static_assert(offsetof(UPyWidget_PingPanel, PingInfoDataAsset) == 0x0005F0, "Member 'UPyWidget_PingPanel::PingInfoDataAsset' has a wrong offset!");

}

