#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_Secondary_Loading

#include "Basic.hpp"

#include "PyMarvelUserWidget_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_Secondary_Loading.PyWidget_Secondary_Loading
// 0x0000 (0x05F0 - 0x05F0)
class UPyWidget_Secondary_Loading final : public UPyMarvelUserWidget
{
public:
	void Destruct();
	void Construct();
	void OnInitialized();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_Secondary_Loading">();
	}
	static class UPyWidget_Secondary_Loading* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_Secondary_Loading>();
	}
};
static_assert(alignof(UPyWidget_Secondary_Loading) == 0x000008, "Wrong alignment on UPyWidget_Secondary_Loading");
static_assert(sizeof(UPyWidget_Secondary_Loading) == 0x0005F0, "Wrong size on UPyWidget_Secondary_Loading");

}

