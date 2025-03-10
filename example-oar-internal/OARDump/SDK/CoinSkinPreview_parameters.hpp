#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CoinSkinPreview

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function CoinSkinPreview.CoinSkinPreview_C.ExecuteUbergraph_CoinSkinPreview
// 0x0030 (0x0030 - 0x0000)
struct CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_IsDesignTime;                         // 0x0004(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerController*                      CallFunc_GetPlayerController_ReturnValue;          // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ARobberController_C*                    K2Node_DynamicCast_AsRobber_Controller;            // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsLocalController_ReturnValue;            // 0x0019(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Array_Contains_ReturnValue;               // 0x001A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1B[0x5];                                       // 0x001B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue;                // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_1;              // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview) == 0x000008, "Wrong alignment on CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview");
static_assert(sizeof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview) == 0x000030, "Wrong size on CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, EntryPoint) == 0x000000, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::EntryPoint' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, K2Node_Event_IsDesignTime) == 0x000004, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::K2Node_Event_IsDesignTime' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, CallFunc_GetPlayerController_ReturnValue) == 0x000008, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::CallFunc_GetPlayerController_ReturnValue' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, K2Node_DynamicCast_AsRobber_Controller) == 0x000010, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::K2Node_DynamicCast_AsRobber_Controller' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, CallFunc_IsLocalController_ReturnValue) == 0x000019, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::CallFunc_IsLocalController_ReturnValue' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, CallFunc_Array_Contains_ReturnValue) == 0x00001A, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::CallFunc_Array_Contains_ReturnValue' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, CallFunc_PlayAnimation_ReturnValue) == 0x000020, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::CallFunc_PlayAnimation_ReturnValue' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview, CallFunc_PlayAnimation_ReturnValue_1) == 0x000028, "Member 'CoinSkinPreview_C_ExecuteUbergraph_CoinSkinPreview::CallFunc_PlayAnimation_ReturnValue_1' has a wrong offset!");

// Function CoinSkinPreview.CoinSkinPreview_C.PreConstruct
// 0x0001 (0x0001 - 0x0000)
struct CoinSkinPreview_C_PreConstruct final
{
public:
	bool                                          IsDesignTime;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CoinSkinPreview_C_PreConstruct) == 0x000001, "Wrong alignment on CoinSkinPreview_C_PreConstruct");
static_assert(sizeof(CoinSkinPreview_C_PreConstruct) == 0x000001, "Wrong size on CoinSkinPreview_C_PreConstruct");
static_assert(offsetof(CoinSkinPreview_C_PreConstruct, IsDesignTime) == 0x000000, "Member 'CoinSkinPreview_C_PreConstruct::IsDesignTime' has a wrong offset!");

// Function CoinSkinPreview.CoinSkinPreview_C.GetText_0
// 0x0058 (0x0058 - 0x0000)
struct CoinSkinPreview_C_GetText_0 final
{
public:
	class FText                                   ReturnValue;                                       // 0x0000(0x0018)(Parm, OutParm, ReturnParm)
	bool                                          Temp_bool_Variable;                                // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 Temp_string_Variable;                              // 0x0020(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 K2Node_Select_Default;                             // 0x0030(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x0040(0x0018)()
};
static_assert(alignof(CoinSkinPreview_C_GetText_0) == 0x000008, "Wrong alignment on CoinSkinPreview_C_GetText_0");
static_assert(sizeof(CoinSkinPreview_C_GetText_0) == 0x000058, "Wrong size on CoinSkinPreview_C_GetText_0");
static_assert(offsetof(CoinSkinPreview_C_GetText_0, ReturnValue) == 0x000000, "Member 'CoinSkinPreview_C_GetText_0::ReturnValue' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetText_0, Temp_bool_Variable) == 0x000018, "Member 'CoinSkinPreview_C_GetText_0::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetText_0, Temp_string_Variable) == 0x000020, "Member 'CoinSkinPreview_C_GetText_0::Temp_string_Variable' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetText_0, K2Node_Select_Default) == 0x000030, "Member 'CoinSkinPreview_C_GetText_0::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetText_0, CallFunc_Conv_StringToText_ReturnValue) == 0x000040, "Member 'CoinSkinPreview_C_GetText_0::CallFunc_Conv_StringToText_ReturnValue' has a wrong offset!");

// Function CoinSkinPreview.CoinSkinPreview_C.GetBrush_0
// 0x0170 (0x0170 - 0x0000)
struct CoinSkinPreview_C_GetBrush_0 final
{
public:
	struct FSlateBrush                            ReturnValue;                                       // 0x0000(0x0088)(Parm, OutParm, ReturnParm)
	bool                                          Temp_bool_Variable;                                // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_89[0x3];                                       // 0x0089(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           Temp_struct_Variable;                              // 0x008C(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           Temp_struct_Variable_1;                            // 0x009C(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           K2Node_Select_Default;                             // 0x00AC(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_BC[0x4];                                       // 0x00BC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateColor                            K2Node_MakeStruct_SlateColor;                      // 0x00C0(0x0028)()
	struct FSlateBrush                            K2Node_MakeStruct_SlateBrush;                      // 0x00E8(0x0088)()
};
static_assert(alignof(CoinSkinPreview_C_GetBrush_0) == 0x000008, "Wrong alignment on CoinSkinPreview_C_GetBrush_0");
static_assert(sizeof(CoinSkinPreview_C_GetBrush_0) == 0x000170, "Wrong size on CoinSkinPreview_C_GetBrush_0");
static_assert(offsetof(CoinSkinPreview_C_GetBrush_0, ReturnValue) == 0x000000, "Member 'CoinSkinPreview_C_GetBrush_0::ReturnValue' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetBrush_0, Temp_bool_Variable) == 0x000088, "Member 'CoinSkinPreview_C_GetBrush_0::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetBrush_0, Temp_struct_Variable) == 0x00008C, "Member 'CoinSkinPreview_C_GetBrush_0::Temp_struct_Variable' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetBrush_0, Temp_struct_Variable_1) == 0x00009C, "Member 'CoinSkinPreview_C_GetBrush_0::Temp_struct_Variable_1' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetBrush_0, K2Node_Select_Default) == 0x0000AC, "Member 'CoinSkinPreview_C_GetBrush_0::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetBrush_0, K2Node_MakeStruct_SlateColor) == 0x0000C0, "Member 'CoinSkinPreview_C_GetBrush_0::K2Node_MakeStruct_SlateColor' has a wrong offset!");
static_assert(offsetof(CoinSkinPreview_C_GetBrush_0, K2Node_MakeStruct_SlateBrush) == 0x0000E8, "Member 'CoinSkinPreview_C_GetBrush_0::K2Node_MakeStruct_SlateBrush' has a wrong offset!");

}

