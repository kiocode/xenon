#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_ServerListModifierSetting_FilterRule

#include "Basic.hpp"

#include "HDMain_structs.hpp"
#include "SlateCore_structs.hpp"


namespace SDK::Params
{

// Function WBP_ServerListModifierSetting_FilterRule.WBP_ServerListModifierSetting_FilterRule_C.OnDropdownSettingChanged__DelegateSignature
// 0x0010 (0x0010 - 0x0000)
struct WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature final
{
public:
	class UClass*                                 Rule_0;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FHDFilterRuleParams                    RuleParams_0;                                      // 0x0008(0x0002)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature) == 0x000008, "Wrong alignment on WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature");
static_assert(sizeof(WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature) == 0x000010, "Wrong size on WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature, Rule_0) == 0x000000, "Member 'WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature::Rule_0' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature, RuleParams_0) == 0x000008, "Member 'WBP_ServerListModifierSetting_FilterRule_C_OnDropdownSettingChanged__DelegateSignature::RuleParams_0' has a wrong offset!");

// Function WBP_ServerListModifierSetting_FilterRule.WBP_ServerListModifierSetting_FilterRule_C.ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule
// 0x0028 (0x0028 - 0x0000)
struct WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_IsDesignTime;                         // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 K2Node_ComponentBoundEvent_SelectedItem;           // 0x0008(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	ESelectInfo                                   K2Node_ComponentBoundEvent_SelectionType;          // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NotEqual_ByteByte_ReturnValue;            // 0x0019(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1A[0x2];                                       // 0x001A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_GetSelectedIndex_ReturnValue;             // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         CallFunc_Conv_IntToByte_ReturnValue;               // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         CallFunc_GetValidValue_ReturnValue;                // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FHDFilterRuleParams                    K2Node_MakeStruct_HDFilterRuleParams;              // 0x0022(0x0002)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule) == 0x000008, "Wrong alignment on WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule");
static_assert(sizeof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule) == 0x000028, "Wrong size on WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, EntryPoint) == 0x000000, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::EntryPoint' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, K2Node_Event_IsDesignTime) == 0x000004, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::K2Node_Event_IsDesignTime' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, K2Node_ComponentBoundEvent_SelectedItem) == 0x000008, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::K2Node_ComponentBoundEvent_SelectedItem' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, K2Node_ComponentBoundEvent_SelectionType) == 0x000018, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::K2Node_ComponentBoundEvent_SelectionType' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, CallFunc_NotEqual_ByteByte_ReturnValue) == 0x000019, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::CallFunc_NotEqual_ByteByte_ReturnValue' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, CallFunc_GetSelectedIndex_ReturnValue) == 0x00001C, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::CallFunc_GetSelectedIndex_ReturnValue' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, CallFunc_Conv_IntToByte_ReturnValue) == 0x000020, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::CallFunc_Conv_IntToByte_ReturnValue' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, CallFunc_GetValidValue_ReturnValue) == 0x000021, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::CallFunc_GetValidValue_ReturnValue' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule, K2Node_MakeStruct_HDFilterRuleParams) == 0x000022, "Member 'WBP_ServerListModifierSetting_FilterRule_C_ExecuteUbergraph_WBP_ServerListModifierSetting_FilterRule::K2Node_MakeStruct_HDFilterRuleParams' has a wrong offset!");

// Function WBP_ServerListModifierSetting_FilterRule.WBP_ServerListModifierSetting_FilterRule_C.BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature
// 0x0018 (0x0018 - 0x0000)
struct WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature final
{
public:
	class FString                                 SelectedItem;                                      // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
	ESelectInfo                                   SelectionType;                                     // 0x0010(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature) == 0x000008, "Wrong alignment on WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature");
static_assert(sizeof(WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature) == 0x000018, "Wrong size on WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature, SelectedItem) == 0x000000, "Member 'WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature::SelectedItem' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature, SelectionType) == 0x000010, "Member 'WBP_ServerListModifierSetting_FilterRule_C_BndEvt__FilterSetting_K2Node_ComponentBoundEvent_0_OnSelectionChanged__DelegateSignature::SelectionType' has a wrong offset!");

// Function WBP_ServerListModifierSetting_FilterRule.WBP_ServerListModifierSetting_FilterRule_C.PreConstruct
// 0x0001 (0x0001 - 0x0000)
struct WBP_ServerListModifierSetting_FilterRule_C_PreConstruct final
{
public:
	bool                                          IsDesignTime;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WBP_ServerListModifierSetting_FilterRule_C_PreConstruct) == 0x000001, "Wrong alignment on WBP_ServerListModifierSetting_FilterRule_C_PreConstruct");
static_assert(sizeof(WBP_ServerListModifierSetting_FilterRule_C_PreConstruct) == 0x000001, "Wrong size on WBP_ServerListModifierSetting_FilterRule_C_PreConstruct");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_PreConstruct, IsDesignTime) == 0x000000, "Member 'WBP_ServerListModifierSetting_FilterRule_C_PreConstruct::IsDesignTime' has a wrong offset!");

// Function WBP_ServerListModifierSetting_FilterRule.WBP_ServerListModifierSetting_FilterRule_C.SetRuleParams
// 0x0008 (0x0008 - 0x0000)
struct WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams final
{
public:
	struct FHDFilterRuleParams                    NewParams;                                         // 0x0000(0x0002)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2[0x2];                                        // 0x0002(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Conv_ByteToInt_ReturnValue;               // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams) == 0x000004, "Wrong alignment on WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams");
static_assert(sizeof(WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams) == 0x000008, "Wrong size on WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams, NewParams) == 0x000000, "Member 'WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams::NewParams' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams, CallFunc_Conv_ByteToInt_ReturnValue) == 0x000004, "Member 'WBP_ServerListModifierSetting_FilterRule_C_SetRuleParams::CallFunc_Conv_ByteToInt_ReturnValue' has a wrong offset!");

// Function WBP_ServerListModifierSetting_FilterRule.WBP_ServerListModifierSetting_FilterRule_C.GetRuleParams
// 0x0002 (0x0002 - 0x0000)
struct WBP_ServerListModifierSetting_FilterRule_C_GetRuleParams final
{
public:
	struct FHDFilterRuleParams                    Params_0;                                          // 0x0000(0x0002)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WBP_ServerListModifierSetting_FilterRule_C_GetRuleParams) == 0x000001, "Wrong alignment on WBP_ServerListModifierSetting_FilterRule_C_GetRuleParams");
static_assert(sizeof(WBP_ServerListModifierSetting_FilterRule_C_GetRuleParams) == 0x000002, "Wrong size on WBP_ServerListModifierSetting_FilterRule_C_GetRuleParams");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_GetRuleParams, Params_0) == 0x000000, "Member 'WBP_ServerListModifierSetting_FilterRule_C_GetRuleParams::Params_0' has a wrong offset!");

// Function WBP_ServerListModifierSetting_FilterRule.WBP_ServerListModifierSetting_FilterRule_C.GetFilterRulePair
// 0x0010 (0x0010 - 0x0000)
struct WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair final
{
public:
	class UClass*                                 Rule_0;                                            // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FHDFilterRuleParams                    RuleParams_0;                                      // 0x0008(0x0002)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair) == 0x000008, "Wrong alignment on WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair");
static_assert(sizeof(WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair) == 0x000010, "Wrong size on WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair, Rule_0) == 0x000000, "Member 'WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair::Rule_0' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair, RuleParams_0) == 0x000008, "Member 'WBP_ServerListModifierSetting_FilterRule_C_GetFilterRulePair::RuleParams_0' has a wrong offset!");

// Function WBP_ServerListModifierSetting_FilterRule.WBP_ServerListModifierSetting_FilterRule_C.IsFilterEnabled
// 0x0002 (0x0002 - 0x0000)
struct WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled final
{
public:
	bool                                          bActive;                                           // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_GetIsEnabled_ReturnValue;                 // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled) == 0x000001, "Wrong alignment on WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled");
static_assert(sizeof(WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled) == 0x000002, "Wrong size on WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled, bActive) == 0x000000, "Member 'WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled::bActive' has a wrong offset!");
static_assert(offsetof(WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled, CallFunc_GetIsEnabled_ReturnValue) == 0x000001, "Member 'WBP_ServerListModifierSetting_FilterRule_C_IsFilterEnabled::CallFunc_GetIsEnabled_ReturnValue' has a wrong offset!");

}

