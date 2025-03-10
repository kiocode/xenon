#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyCue_Weapon_Loop_102301

#include "Basic.hpp"

#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyCue_Weapon_Loop_102301.PyCue_Weapon_Loop_102301
// 0x0000 (0x10A8 - 0x10A8)
class APyCue_Weapon_Loop_102301 final : public AMarvelCueNotify_Weapon_Loop
{
public:
	void HandleWeaponOnEquipEvent();
	void OnGenericHandleWeaponState(const struct FGameplayTag& Tag, int32 Count);
	bool WhileActive(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Weapon_Loop_102301">();
	}
	static class APyCue_Weapon_Loop_102301* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyCue_Weapon_Loop_102301>();
	}
};
static_assert(alignof(APyCue_Weapon_Loop_102301) == 0x000008, "Wrong alignment on APyCue_Weapon_Loop_102301");
static_assert(sizeof(APyCue_Weapon_Loop_102301) == 0x0010A8, "Wrong size on APyCue_Weapon_Loop_102301");

}

