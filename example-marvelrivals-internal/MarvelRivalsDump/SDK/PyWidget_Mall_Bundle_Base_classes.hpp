#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_Mall_Bundle_Base

#include "Basic.hpp"

#include "Marvel_structs.hpp"
#include "PyMarvelUserWidget_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_Mall_Bundle_Base.PyWidget_Mall_Bundle_Base
// 0x0000 (0x05F0 - 0x05F0)
#pragma pack(push, 0x1)
class alignas(0x08) UPyWidget_Mall_Bundle_Base : public UPyMarvelUserWidget
{
public:
	EStoreRowCardType                             WindowType;                                        // 0x05E9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_Mall_Bundle_Base">();
	}
	static class UPyWidget_Mall_Bundle_Base* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_Mall_Bundle_Base>();
	}
};
#pragma pack(pop)
static_assert(alignof(UPyWidget_Mall_Bundle_Base) == 0x000008, "Wrong alignment on UPyWidget_Mall_Bundle_Base");
static_assert(sizeof(UPyWidget_Mall_Bundle_Base) == 0x0005F0, "Wrong size on UPyWidget_Mall_Bundle_Base");
static_assert(offsetof(UPyWidget_Mall_Bundle_Base, WindowType) == 0x0005E9, "Member 'UPyWidget_Mall_Bundle_Base::WindowType' has a wrong offset!");

}

