#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Ability_104821_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Ability_104821_BP.Ability_104821_BP_C
// 0x03A8 (0x2A40 - 0x2698)
class UAbility_104821_BP_C final : public UAbility_106
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x2698(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	bool                                          HasValidHit;                                       // 0x26A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_26A1[0x7];                                     // 0x26A1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FMarvelTraceRule                       Trace_Rule;                                        // 0x26A8(0x0390)(Edit, BlueprintVisible, DisableEditOnInstance)
	int32                                         HitCount;                                          // 0x2A38(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         BuffCount;                                         // 0x2A3C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Ability_104821_BP(int32 EntryPoint);
	void OnGameplayAbilityHit(const TArray<struct FHitResult>& HitResults);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Ability_104821_BP_C">();
	}
	static class UAbility_104821_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAbility_104821_BP_C>();
	}
};
//static_assert(alignof(UAbility_104821_BP_C) == 0x000008, "Wrong alignment on UAbility_104821_BP_C");
//static_assert(sizeof(UAbility_104821_BP_C) == 0x002A40, "Wrong size on UAbility_104821_BP_C");
//static_assert(offsetof(UAbility_104821_BP_C, UberGraphFrame) == 0x002698, "Member 'UAbility_104821_BP_C::UberGraphFrame' has a wrong offset!");
//static_assert(offsetof(UAbility_104821_BP_C, HasValidHit) == 0x0026A0, "Member 'UAbility_104821_BP_C::HasValidHit' has a wrong offset!");
//static_assert(offsetof(UAbility_104821_BP_C, Trace_Rule) == 0x0026A8, "Member 'UAbility_104821_BP_C::Trace_Rule' has a wrong offset!");
//static_assert(offsetof(UAbility_104821_BP_C, HitCount) == 0x002A38, "Member 'UAbility_104821_BP_C::HitCount' has a wrong offset!");
//static_assert(offsetof(UAbility_104821_BP_C, BuffCount) == 0x002A3C, "Member 'UAbility_104821_BP_C::BuffCount' has a wrong offset!");

}

