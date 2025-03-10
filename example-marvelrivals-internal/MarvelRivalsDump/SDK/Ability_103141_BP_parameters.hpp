#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Ability_103141_BP

#include "Basic.hpp"


namespace SDK::Params
{

// Function Ability_103141_BP.Ability_103141_BP_C.ExecuteUbergraph_Ability_103141_BP
// 0x0030 (0x0030 - 0x0000)
struct Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UUserWidget*                            K2Node_Event_InExtraWidget;                        // 0x0008(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class UUserWidget*                            K2Node_Event_InUserWidget;                         // 0x0010(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class AMarvelBaseCharacter*                   CallFunc_AE_GetCharacterActor_ReturnValue;         // 0x0018(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UMarvelAbilityTask_ModifyAmmo*          CallFunc_ApplyMakeUpToMaxAmmo_ReturnValue;         // 0x0020(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP) == 0x000008, "Wrong alignment on Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP");
////static_assert(sizeof(Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP) == 0x000030, "Wrong size on Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP");
////static_assert(offsetof(Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP, EntryPoint) == 0x000000, "Member 'Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP::EntryPoint' has a wrong offset!");
////static_assert(offsetof(Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP, K2Node_Event_InExtraWidget) == 0x000008, "Member 'Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP::K2Node_Event_InExtraWidget' has a wrong offset!");
////static_assert(offsetof(Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP, K2Node_Event_InUserWidget) == 0x000010, "Member 'Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP::K2Node_Event_InUserWidget' has a wrong offset!");
////static_assert(offsetof(Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP, CallFunc_AE_GetCharacterActor_ReturnValue) == 0x000018, "Member 'Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP::CallFunc_AE_GetCharacterActor_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP, CallFunc_ApplyMakeUpToMaxAmmo_ReturnValue) == 0x000020, "Member 'Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP::CallFunc_ApplyMakeUpToMaxAmmo_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP, CallFunc_IsValid_ReturnValue) == 0x000028, "Member 'Ability_103141_BP_C_ExecuteUbergraph_Ability_103141_BP::CallFunc_IsValid_ReturnValue' has a wrong offset!");

// Function Ability_103141_BP.Ability_103141_BP_C.SetAbilityExtraWidget_1
// 0x0008 (0x0008 - 0x0000)
struct Ability_103141_BP_C_SetAbilityExtraWidget_1 final
{
public:
	class UUserWidget*                            InExtraWidget;                                     // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_103141_BP_C_SetAbilityExtraWidget_1) == 0x000008, "Wrong alignment on Ability_103141_BP_C_SetAbilityExtraWidget_1");
////static_assert(sizeof(Ability_103141_BP_C_SetAbilityExtraWidget_1) == 0x000008, "Wrong size on Ability_103141_BP_C_SetAbilityExtraWidget_1");
////static_assert(offsetof(Ability_103141_BP_C_SetAbilityExtraWidget_1, InExtraWidget) == 0x000000, "Member 'Ability_103141_BP_C_SetAbilityExtraWidget_1::InExtraWidget' has a wrong offset!");

// Function Ability_103141_BP.Ability_103141_BP_C.SetAbilityStatusWidget_1
// 0x0008 (0x0008 - 0x0000)
struct Ability_103141_BP_C_SetAbilityStatusWidget_1 final
{
public:
	class UUserWidget*                            InUserWidget;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_103141_BP_C_SetAbilityStatusWidget_1) == 0x000008, "Wrong alignment on Ability_103141_BP_C_SetAbilityStatusWidget_1");
////static_assert(sizeof(Ability_103141_BP_C_SetAbilityStatusWidget_1) == 0x000008, "Wrong size on Ability_103141_BP_C_SetAbilityStatusWidget_1");
////static_assert(offsetof(Ability_103141_BP_C_SetAbilityStatusWidget_1, InUserWidget) == 0x000000, "Member 'Ability_103141_BP_C_SetAbilityStatusWidget_1::InUserWidget' has a wrong offset!");

}

