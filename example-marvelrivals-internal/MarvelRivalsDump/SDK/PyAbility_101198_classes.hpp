#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_101198

#include "Basic.hpp"

#include "Hero_Synergy_classes.hpp"
#include "Hero_1011_classes.hpp"


namespace SDK
{

// PythonClass PyAbility_101198.PyConfig_101198
// 0x0000 (0x00C8 - 0x00C8)
class UPyConfig_101198 final : public UConfig_100016
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyConfig_101198">();
	}
	static class UPyConfig_101198* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyConfig_101198>();
	}
};
static_assert(alignof(UPyConfig_101198) == 0x000008, "Wrong alignment on UPyConfig_101198");
static_assert(sizeof(UPyConfig_101198) == 0x0000C8, "Wrong size on UPyConfig_101198");

// PythonClass PyAbility_101198.PyAbility_101198
// 0x0000 (0x25F8 - 0x25F8)
class UPyAbility_101198 : public UAbility_101198
{
public:
	void BeginPlay();
	bool CanActivate();
	void K2_ActivateAbility();
	void K2_TriggerGameplay(float HoldTime);
	void K2_MaxHoldTimeGameplay(float HoldTime);
	void K2_OnEndAbility(bool bWasCancelled);
	void NativeOnMontageCompleted(const class FString& Tag);
	void NativeOnMontageCancelled(const class FString& Tag);
	void NativeOnMontageInterrupted(const class FString& Tag);
	void MissileEventNotify();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyAbility_101198">();
	}
	static class UPyAbility_101198* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyAbility_101198>();
	}
};
static_assert(alignof(UPyAbility_101198) == 0x000008, "Wrong alignment on UPyAbility_101198");
static_assert(sizeof(UPyAbility_101198) == 0x0025F8, "Wrong size on UPyAbility_101198");

}

