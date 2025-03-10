#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_105203

#include "Basic.hpp"

#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyAbility_105203.PyConfig_105203
// 0x03A0 (0x0438 - 0x0098)
class UPyConfig_105203 final : public UMarvelAbilityConfig
{
public:
	int32                                         ShieldBuffID;                                      // 0x0098(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         AddShieldValueOnce;                                // 0x009C(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxNotTreatShieldValue;                            // 0x00A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_A4[0x4];                                       // 0x00A4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FMarvelTraceRule                       TargetFilter;                                      // 0x00A8(0x0390)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyConfig_105203">();
	}
	static class UPyConfig_105203* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyConfig_105203>();
	}
};
static_assert(alignof(UPyConfig_105203) == 0x000008, "Wrong alignment on UPyConfig_105203");
static_assert(sizeof(UPyConfig_105203) == 0x000438, "Wrong size on UPyConfig_105203");
static_assert(offsetof(UPyConfig_105203, ShieldBuffID) == 0x000098, "Member 'UPyConfig_105203::ShieldBuffID' has a wrong offset!");
static_assert(offsetof(UPyConfig_105203, AddShieldValueOnce) == 0x00009C, "Member 'UPyConfig_105203::AddShieldValueOnce' has a wrong offset!");
static_assert(offsetof(UPyConfig_105203, MaxNotTreatShieldValue) == 0x0000A0, "Member 'UPyConfig_105203::MaxNotTreatShieldValue' has a wrong offset!");
static_assert(offsetof(UPyConfig_105203, TargetFilter) == 0x0000A8, "Member 'UPyConfig_105203::TargetFilter' has a wrong offset!");

// PythonClass PyAbility_105203.PyAbility_105203
// 0x0000 (0x2580 - 0x2580)
class UPyAbility_105203 : public UMarvelGameplayAbility
{
public:
	void BeginPlay();
	void EndPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyAbility_105203">();
	}
	static class UPyAbility_105203* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyAbility_105203>();
	}
};
static_assert(alignof(UPyAbility_105203) == 0x000008, "Wrong alignment on UPyAbility_105203");
static_assert(sizeof(UPyAbility_105203) == 0x002580, "Wrong size on UPyAbility_105203");

}

