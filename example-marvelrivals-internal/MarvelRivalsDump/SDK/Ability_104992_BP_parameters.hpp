#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Ability_104992_BP

#include "Basic.hpp"

#include "GameplayTags_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function Ability_104992_BP.Ability_104992_BP_C.ExecuteUbergraph_Ability_104992_BP
// 0x0158 (0x0158 - 0x0000)
struct Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           Temp_struct_Variable;                              // 0x0004(0x000C)(NoDestructor, HasGetValueTypeHash)
	TArray<int32>                                 K2Node_MakeArray_Array;                            // 0x0010(0x0010)(ReferenceParm)
	bool                                          GameplayTagsK2Node_SwitchGameplayTag_CmpSuccess;   // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_21[0x7];                                       // 0x0021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGATask_PlayTimeline*                   CallFunc_PlayTimelineByIndex_ReturnValue;          // 0x0028(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(int32 NewStackCount, int32 OldStackCount)> K2Node_CreateDelegate_OutputDelegate;              // 0x0030(0x0014)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0044(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_45[0x3];                                       // 0x0045(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_4; // 0x0048(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_4; // 0x004C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable;                                 // 0x0050(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_1;                               // 0x0054(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGATask_WaitBuffEvent*                  CallFunc_WaitBuffEvent_ReturnValue;                // 0x0058(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(int32 NewStackCount, int32 OldStackCount)> K2Node_CreateDelegate_OutputDelegate_1;            // 0x0060(0x0014)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0074(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_75[0x3];                                       // 0x0075(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_3; // 0x0078(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_3; // 0x007C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_2; // 0x0080(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_2; // 0x0084(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(int32 NewStackCount, int32 OldStackCount)> K2Node_CreateDelegate_OutputDelegate_2;            // 0x0088(0x0014)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_2;                               // 0x009C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_3;                               // 0x00A0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_A4[0x4];                                       // 0x00A4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGATask_WaitBuffEvent*                  CallFunc_WaitBuffEvent_ReturnValue_1;              // 0x00A8(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(int32 NewStackCount, int32 OldStackCount)> K2Node_CreateDelegate_OutputDelegate_3;            // 0x00B0(0x0014)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_2;                    // 0x00C4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C5[0x3];                                       // 0x00C5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_1; // 0x00C8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_1; // 0x00CC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_4;                               // 0x00D0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_5;                               // 0x00D4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGATask_WaitBuffEvent*                  CallFunc_WaitBuffEvent_ReturnValue_2;              // 0x00D8(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(int32 NewStackCount, int32 OldStackCount)> K2Node_CreateDelegate_OutputDelegate_4;            // 0x00E0(0x0014)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_3;                    // 0x00F4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F5[0x3];                                       // 0x00F5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount; // 0x00F8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount; // 0x00FC(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_6;                               // 0x0100(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_7;                               // 0x0104(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGATask_WaitBuffEvent*                  CallFunc_WaitBuffEvent_ReturnValue_3;              // 0x0108(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           K2Node_CustomEvent_TriggerNotifyTagEventDelegate__DelegateSignature_EventTag; // 0x0110(0x000C)(NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_4;                    // 0x011C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_11D[0x3];                                      // 0x011D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UMarvelBaseAbilitySystemComponent*      CallFunc_GetAbilitySystemComponent_ReturnValue;    // 0x0120(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CallFunc_GetBuffInstigator_ReturnValue;            // 0x0128(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class AMarvelBaseCharacter*                   CallFunc_AE_GetCharacterActor_ReturnValue;         // 0x0130(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class AMarvelBaseCharacter*                   CallFunc_AE_GetCharacterActor_ReturnValue_1;       // 0x0138(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(const struct FGameplayTag& EventTag)> K2Node_CreateDelegate_OutputDelegate_5;            // 0x0140(0x0014)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_5;                    // 0x0154(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP) == 0x000008, "Wrong alignment on Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP");
////static_assert(sizeof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP) == 0x000158, "Wrong size on Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, EntryPoint) == 0x000000, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::EntryPoint' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_struct_Variable) == 0x000004, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_struct_Variable' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_MakeArray_Array) == 0x000010, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_MakeArray_Array' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, GameplayTagsK2Node_SwitchGameplayTag_CmpSuccess) == 0x000020, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::GameplayTagsK2Node_SwitchGameplayTag_CmpSuccess' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_PlayTimelineByIndex_ReturnValue) == 0x000028, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_PlayTimelineByIndex_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CreateDelegate_OutputDelegate) == 0x000030, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_IsValid_ReturnValue) == 0x000044, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_IsValid_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_4) == 0x000048, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_4' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_4) == 0x00004C, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_4' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_int_Variable) == 0x000050, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_int_Variable' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_int_Variable_1) == 0x000054, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_int_Variable_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_WaitBuffEvent_ReturnValue) == 0x000058, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_WaitBuffEvent_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CreateDelegate_OutputDelegate_1) == 0x000060, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CreateDelegate_OutputDelegate_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_IsValid_ReturnValue_1) == 0x000074, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_3) == 0x000078, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_3' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_3) == 0x00007C, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_3' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_2) == 0x000080, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_2' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_2) == 0x000084, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_2' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CreateDelegate_OutputDelegate_2) == 0x000088, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CreateDelegate_OutputDelegate_2' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_int_Variable_2) == 0x00009C, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_int_Variable_2' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_int_Variable_3) == 0x0000A0, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_int_Variable_3' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_WaitBuffEvent_ReturnValue_1) == 0x0000A8, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_WaitBuffEvent_ReturnValue_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CreateDelegate_OutputDelegate_3) == 0x0000B0, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CreateDelegate_OutputDelegate_3' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_IsValid_ReturnValue_2) == 0x0000C4, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_IsValid_ReturnValue_2' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_1) == 0x0000C8, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_1) == 0x0000CC, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_int_Variable_4) == 0x0000D0, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_int_Variable_4' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_int_Variable_5) == 0x0000D4, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_int_Variable_5' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_WaitBuffEvent_ReturnValue_2) == 0x0000D8, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_WaitBuffEvent_ReturnValue_2' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CreateDelegate_OutputDelegate_4) == 0x0000E0, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CreateDelegate_OutputDelegate_4' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_IsValid_ReturnValue_3) == 0x0000F4, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_IsValid_ReturnValue_3' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount) == 0x0000F8, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_NewStackCount' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount) == 0x0000FC, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_OnBuffUpdateDelegate__DelegateSignature_OldStackCount' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_int_Variable_6) == 0x000100, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_int_Variable_6' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, Temp_int_Variable_7) == 0x000104, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::Temp_int_Variable_7' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_WaitBuffEvent_ReturnValue_3) == 0x000108, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_WaitBuffEvent_ReturnValue_3' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CustomEvent_TriggerNotifyTagEventDelegate__DelegateSignature_EventTag) == 0x000110, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CustomEvent_TriggerNotifyTagEventDelegate__DelegateSignature_EventTag' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_IsValid_ReturnValue_4) == 0x00011C, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_IsValid_ReturnValue_4' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_GetAbilitySystemComponent_ReturnValue) == 0x000120, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_GetAbilitySystemComponent_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_GetBuffInstigator_ReturnValue) == 0x000128, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_GetBuffInstigator_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_AE_GetCharacterActor_ReturnValue) == 0x000130, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_AE_GetCharacterActor_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_AE_GetCharacterActor_ReturnValue_1) == 0x000138, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_AE_GetCharacterActor_ReturnValue_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, K2Node_CreateDelegate_OutputDelegate_5) == 0x000140, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::K2Node_CreateDelegate_OutputDelegate_5' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP, CallFunc_IsValid_ReturnValue_5) == 0x000154, "Member 'Ability_104992_BP_C_ExecuteUbergraph_Ability_104992_BP::CallFunc_IsValid_ReturnValue_5' has a wrong offset!");

// Function Ability_104992_BP.Ability_104992_BP_C.OnApplied_20C6A51D42174647FAD3479BA72394A5
// 0x0008 (0x0008 - 0x0000)
struct Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5 final
{
public:
	int32                                         OnBuffUpdateDelegate__DelegateSignature_NewStackCount; // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         OnBuffUpdateDelegate__DelegateSignature_OldStackCount; // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5) == 0x000004, "Wrong alignment on Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5");
////static_assert(sizeof(Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5) == 0x000008, "Wrong size on Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5");
////static_assert(offsetof(Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5, OnBuffUpdateDelegate__DelegateSignature_NewStackCount) == 0x000000, "Member 'Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5::OnBuffUpdateDelegate__DelegateSignature_NewStackCount' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5, OnBuffUpdateDelegate__DelegateSignature_OldStackCount) == 0x000004, "Member 'Ability_104992_BP_C_OnApplied_20C6A51D42174647FAD3479BA72394A5::OnBuffUpdateDelegate__DelegateSignature_OldStackCount' has a wrong offset!");

// Function Ability_104992_BP.Ability_104992_BP_C.OnApplied_733CDA0E49E984DA9573728C1490B764
// 0x0008 (0x0008 - 0x0000)
struct Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764 final
{
public:
	int32                                         OnBuffUpdateDelegate__DelegateSignature_NewStackCount; // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         OnBuffUpdateDelegate__DelegateSignature_OldStackCount; // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764) == 0x000004, "Wrong alignment on Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764");
////static_assert(sizeof(Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764) == 0x000008, "Wrong size on Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764");
////static_assert(offsetof(Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764, OnBuffUpdateDelegate__DelegateSignature_NewStackCount) == 0x000000, "Member 'Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764::OnBuffUpdateDelegate__DelegateSignature_NewStackCount' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764, OnBuffUpdateDelegate__DelegateSignature_OldStackCount) == 0x000004, "Member 'Ability_104992_BP_C_OnApplied_733CDA0E49E984DA9573728C1490B764::OnBuffUpdateDelegate__DelegateSignature_OldStackCount' has a wrong offset!");

// Function Ability_104992_BP.Ability_104992_BP_C.OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B
// 0x0008 (0x0008 - 0x0000)
struct Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B final
{
public:
	int32                                         OnBuffUpdateDelegate__DelegateSignature_NewStackCount; // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         OnBuffUpdateDelegate__DelegateSignature_OldStackCount; // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B) == 0x000004, "Wrong alignment on Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B");
////static_assert(sizeof(Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B) == 0x000008, "Wrong size on Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B");
////static_assert(offsetof(Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B, OnBuffUpdateDelegate__DelegateSignature_NewStackCount) == 0x000000, "Member 'Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B::OnBuffUpdateDelegate__DelegateSignature_NewStackCount' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B, OnBuffUpdateDelegate__DelegateSignature_OldStackCount) == 0x000004, "Member 'Ability_104992_BP_C_OnRemoved_33DBAEF743BFA93ADC1F1CAEF9BFCD6B::OnBuffUpdateDelegate__DelegateSignature_OldStackCount' has a wrong offset!");

// Function Ability_104992_BP.Ability_104992_BP_C.OnRemoved_733CDA0E49E984DA9573728C1490B764
// 0x0008 (0x0008 - 0x0000)
struct Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764 final
{
public:
	int32                                         OnBuffUpdateDelegate__DelegateSignature_NewStackCount; // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         OnBuffUpdateDelegate__DelegateSignature_OldStackCount; // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764) == 0x000004, "Wrong alignment on Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764");
////static_assert(sizeof(Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764) == 0x000008, "Wrong size on Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764");
////static_assert(offsetof(Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764, OnBuffUpdateDelegate__DelegateSignature_NewStackCount) == 0x000000, "Member 'Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764::OnBuffUpdateDelegate__DelegateSignature_NewStackCount' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764, OnBuffUpdateDelegate__DelegateSignature_OldStackCount) == 0x000004, "Member 'Ability_104992_BP_C_OnRemoved_733CDA0E49E984DA9573728C1490B764::OnBuffUpdateDelegate__DelegateSignature_OldStackCount' has a wrong offset!");

// Function Ability_104992_BP.Ability_104992_BP_C.OnRemoved_FDEEC98B4647EED13749F98550213A2B
// 0x0008 (0x0008 - 0x0000)
struct Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B final
{
public:
	int32                                         OnBuffUpdateDelegate__DelegateSignature_NewStackCount; // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         OnBuffUpdateDelegate__DelegateSignature_OldStackCount; // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B) == 0x000004, "Wrong alignment on Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B");
////static_assert(sizeof(Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B) == 0x000008, "Wrong size on Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B");
////static_assert(offsetof(Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B, OnBuffUpdateDelegate__DelegateSignature_NewStackCount) == 0x000000, "Member 'Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B::OnBuffUpdateDelegate__DelegateSignature_NewStackCount' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B, OnBuffUpdateDelegate__DelegateSignature_OldStackCount) == 0x000004, "Member 'Ability_104992_BP_C_OnRemoved_FDEEC98B4647EED13749F98550213A2B::OnBuffUpdateDelegate__DelegateSignature_OldStackCount' has a wrong offset!");

// Function Ability_104992_BP.Ability_104992_BP_C.OnRep_AttachToChar
// 0x0410 (0x0410 - 0x0000)
struct Ability_104992_BP_C_OnRep_AttachToChar final
{
public:
	struct FGameplayTagContainer                  CallFunc_MakeLiteralGameplayTagContainer_ReturnValue; // 0x0000(0x0068)()
	struct FGameplayTagContainer                  CallFunc_MakeLiteralGameplayTagContainer_ReturnValue_1; // 0x0068(0x0068)()
	class UMarvelBaseAbilitySystemComponent*      CallFunc_GetAbilitySystemComponent_ReturnValue;    // 0x00D0(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class UMarvelBaseAbilitySystemComponent*      CallFunc_GetAbilitySystemComponent_ReturnValue_1;  // 0x00D8(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class AMarvelBaseCharacter*                   CallFunc_AE_GetCharacterActor_ReturnValue;         // 0x00E0(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CallFunc_GetAttachParentActor_ReturnValue;         // 0x00E8(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class AMarvelBaseCharacter*                   CallFunc_AE_GetCharacterActor_ReturnValue_1;       // 0x00F0(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x00F8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_F9[0x7];                                       // 0x00F9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UCharacterMovementComponent*            CallFunc_GetComponentByClass_ReturnValue;          // 0x0100(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class AMarvelBaseCharacter*                   CallFunc_AE_GetCharacterActor_ReturnValue_2;       // 0x0108(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UCharacterMovementComponent*            CallFunc_GetComponentByClass_ReturnValue_1;        // 0x0110(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0118(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_119[0x7];                                      // 0x0119(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AMarvelBaseCharacter*                   CallFunc_AE_GetCharacterActor_ReturnValue_3;       // 0x0120(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FHitResult                             CallFunc_K2_SetActorRelativeRotation_SweepHitResult; // 0x0128(0x0170)(ContainsInstancedReference)
	struct FHitResult                             CallFunc_K2_SetActorRelativeLocation_SweepHitResult; // 0x0298(0x0170)(ContainsInstancedReference)
	bool                                          CallFunc_K2_AttachToActor_ReturnValue;             // 0x0408(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_104992_BP_C_OnRep_AttachToChar) == 0x000008, "Wrong alignment on Ability_104992_BP_C_OnRep_AttachToChar");
////static_assert(sizeof(Ability_104992_BP_C_OnRep_AttachToChar) == 0x000410, "Wrong size on Ability_104992_BP_C_OnRep_AttachToChar");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_MakeLiteralGameplayTagContainer_ReturnValue) == 0x000000, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_MakeLiteralGameplayTagContainer_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_MakeLiteralGameplayTagContainer_ReturnValue_1) == 0x000068, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_MakeLiteralGameplayTagContainer_ReturnValue_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_GetAbilitySystemComponent_ReturnValue) == 0x0000D0, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_GetAbilitySystemComponent_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_GetAbilitySystemComponent_ReturnValue_1) == 0x0000D8, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_GetAbilitySystemComponent_ReturnValue_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_AE_GetCharacterActor_ReturnValue) == 0x0000E0, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_AE_GetCharacterActor_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_GetAttachParentActor_ReturnValue) == 0x0000E8, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_GetAttachParentActor_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_AE_GetCharacterActor_ReturnValue_1) == 0x0000F0, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_AE_GetCharacterActor_ReturnValue_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_IsValid_ReturnValue) == 0x0000F8, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_IsValid_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_GetComponentByClass_ReturnValue) == 0x000100, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_GetComponentByClass_ReturnValue' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_AE_GetCharacterActor_ReturnValue_2) == 0x000108, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_AE_GetCharacterActor_ReturnValue_2' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_GetComponentByClass_ReturnValue_1) == 0x000110, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_GetComponentByClass_ReturnValue_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_IsValid_ReturnValue_1) == 0x000118, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_AE_GetCharacterActor_ReturnValue_3) == 0x000120, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_AE_GetCharacterActor_ReturnValue_3' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_K2_SetActorRelativeRotation_SweepHitResult) == 0x000128, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_K2_SetActorRelativeRotation_SweepHitResult' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_K2_SetActorRelativeLocation_SweepHitResult) == 0x000298, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_K2_SetActorRelativeLocation_SweepHitResult' has a wrong offset!");
////static_assert(offsetof(Ability_104992_BP_C_OnRep_AttachToChar, CallFunc_K2_AttachToActor_ReturnValue) == 0x000408, "Member 'Ability_104992_BP_C_OnRep_AttachToChar::CallFunc_K2_AttachToActor_ReturnValue' has a wrong offset!");

// Function Ability_104992_BP.Ability_104992_BP_C.OnTriggerEvent_6652776B49CB6AD6273A8582D31B00B8
// 0x000C (0x000C - 0x0000)
struct Ability_104992_BP_C_OnTriggerEvent_6652776B49CB6AD6273A8582D31B00B8 final
{
public:
	struct FGameplayTag                           TriggerNotifyTagEventDelegate__DelegateSignature_EventTag; // 0x0000(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
};
////static_assert(alignof(Ability_104992_BP_C_OnTriggerEvent_6652776B49CB6AD6273A8582D31B00B8) == 0x000004, "Wrong alignment on Ability_104992_BP_C_OnTriggerEvent_6652776B49CB6AD6273A8582D31B00B8");
////static_assert(sizeof(Ability_104992_BP_C_OnTriggerEvent_6652776B49CB6AD6273A8582D31B00B8) == 0x00000C, "Wrong size on Ability_104992_BP_C_OnTriggerEvent_6652776B49CB6AD6273A8582D31B00B8");
////static_assert(offsetof(Ability_104992_BP_C_OnTriggerEvent_6652776B49CB6AD6273A8582D31B00B8, TriggerNotifyTagEventDelegate__DelegateSignature_EventTag) == 0x000000, "Member 'Ability_104992_BP_C_OnTriggerEvent_6652776B49CB6AD6273A8582D31B00B8::TriggerNotifyTagEventDelegate__DelegateSignature_EventTag' has a wrong offset!");

}

