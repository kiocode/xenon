#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_401609

#include "Basic.hpp"

#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyAbility_401609.PyCue_Ability_Loop_40160901
// 0x00A0 (0x0EF0 - 0x0E50)
class APyCue_Ability_Loop_40160901 : public AMarvelCueNotify_Ability
{
public:
	TMap<class FName, class UMaterialInstance*>   SlotSuffixMaterialsEnemy;                          // 0x0E50(0x0050)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	TMap<class FName, class UMaterialInstance*>   SlotSuffixMaterialsAlly;                           // 0x0EA0(0x0050)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)

public:
	void OnRemoveFX(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);
	void WhileActiveFX(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);
	void AfterRebornResetMaterials();
	void K2_UpdateTeamVisualEffect(const struct FTeamVisual& NewTeamVisual);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Ability_Loop_40160901">();
	}
	static class APyCue_Ability_Loop_40160901* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyCue_Ability_Loop_40160901>();
	}
};
static_assert(alignof(APyCue_Ability_Loop_40160901) == 0x000008, "Wrong alignment on APyCue_Ability_Loop_40160901");
static_assert(sizeof(APyCue_Ability_Loop_40160901) == 0x000EF0, "Wrong size on APyCue_Ability_Loop_40160901");
static_assert(offsetof(APyCue_Ability_Loop_40160901, SlotSuffixMaterialsEnemy) == 0x000E50, "Member 'APyCue_Ability_Loop_40160901::SlotSuffixMaterialsEnemy' has a wrong offset!");
static_assert(offsetof(APyCue_Ability_Loop_40160901, SlotSuffixMaterialsAlly) == 0x000EA0, "Member 'APyCue_Ability_Loop_40160901::SlotSuffixMaterialsAlly' has a wrong offset!");

}

