#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_MallPropConfirm

#include "Basic.hpp"

#include "PyMarvelUserWidget_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_MallPropConfirm.PyWidget_MallPropConfirm
// 0x0000 (0x05F0 - 0x05F0)
class UPyWidget_MallPropConfirm final : public UPyMarvelUserWidget
{
public:
	void OnInitialized();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_MallPropConfirm">();
	}
	static class UPyWidget_MallPropConfirm* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_MallPropConfirm>();
	}
};
static_assert(alignof(UPyWidget_MallPropConfirm) == 0x000008, "Wrong alignment on UPyWidget_MallPropConfirm");
static_assert(sizeof(UPyWidget_MallPropConfirm) == 0x0005F0, "Wrong size on UPyWidget_MallPropConfirm");

}

