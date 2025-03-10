#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Ability_105223_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass Ability_105223_BP.Ability_105223_BP_C
// 0x2638 (0x4C30 - 0x25F8)
class UAbility_105223_BP_C final : public UMarvelAbility_SelectTarget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x25F8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	TArray<struct FDashAbilityInfo>               Dash_Info;                                         // 0x2600(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          Get_Masked;                                        // 0x2610(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2611[0x7];                                     // 0x2611(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FMarvelTraceRule                       Trace_Rule;                                        // 0x2618(0x0390)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FDashAbilityInfo                       Attach_Dash;                                       // 0x29A8(0x0BA8)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FSelectTaskParam                       ___p;                                              // 0x3550(0x10A0)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference)
	struct FMarvelTraceRule                       Target_Class;                                      // 0x45F0(0x0390)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayEventData                     Local_Event_Data;                                  // 0x4980(0x0290)(Edit, BlueprintVisible, DisableEditOnInstance)
	class AActor*                                 TargetActor;                                       // 0x4C10(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class UGATask_ApplyDash*                      Attach_Dash_Task;                                  // 0x4C18(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class UGATask_ApplyDash*                      Normal_Dash_Task;                                  // 0x4C20(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void AE_OnAbilityInitialized();
	bool CanActivate();
	void ExecuteUbergraph_Ability_105223_BP(int32 EntryPoint);
	void K2_ActivateAbilityFromEvent(const struct FGameplayEventData& EventData);
	void MissileEventNotify();
	bool TryMakeTriggerContext(struct FGameplayEventData& EventData);
	void _dDashTask__();
	void ____();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Ability_105223_BP_C">();
	}
	static class UAbility_105223_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAbility_105223_BP_C>();
	}
};
////static_assert(alignof(UAbility_105223_BP_C) == 0x000010, "Wrong alignment on UAbility_105223_BP_C");
////static_assert(sizeof(UAbility_105223_BP_C) == 0x004C30, "Wrong size on UAbility_105223_BP_C");
////static_assert(offsetof(UAbility_105223_BP_C, UberGraphFrame) == 0x0025F8, "Member 'UAbility_105223_BP_C::UberGraphFrame' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, Dash_Info) == 0x002600, "Member 'UAbility_105223_BP_C::Dash_Info' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, Get_Masked) == 0x002610, "Member 'UAbility_105223_BP_C::Get_Masked' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, Trace_Rule) == 0x002618, "Member 'UAbility_105223_BP_C::Trace_Rule' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, Attach_Dash) == 0x0029A8, "Member 'UAbility_105223_BP_C::Attach_Dash' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, ___p) == 0x003550, "Member 'UAbility_105223_BP_C::___p' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, Target_Class) == 0x0045F0, "Member 'UAbility_105223_BP_C::Target_Class' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, Local_Event_Data) == 0x004980, "Member 'UAbility_105223_BP_C::Local_Event_Data' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, TargetActor) == 0x004C10, "Member 'UAbility_105223_BP_C::TargetActor' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, Attach_Dash_Task) == 0x004C18, "Member 'UAbility_105223_BP_C::Attach_Dash_Task' has a wrong offset!");
////static_assert(offsetof(UAbility_105223_BP_C, Normal_Dash_Task) == 0x004C20, "Member 'UAbility_105223_BP_C::Normal_Dash_Task' has a wrong offset!");

}

