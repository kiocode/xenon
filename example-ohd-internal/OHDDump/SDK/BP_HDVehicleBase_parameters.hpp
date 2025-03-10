#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_HDVehicleBase

#include "Basic.hpp"

#include "InputCore_structs.hpp"
#include "ArcVehicles_structs.hpp"


namespace SDK::Params
{

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.ExecuteUbergraph_BP_HDVehicleBase
// 0x00E0 (0x00E0 - 0x0000)
struct BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FKey                                   K2Node_InputActionEvent_Key;                       // 0x0008(0x0018)(HasGetValueTypeHash)
	float                                         K2Node_InputAxisEvent_AxisValue_1;                 // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         K2Node_InputAxisEvent_AxisValue;                   // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FKey                                   K2Node_InputActionEvent_Key_2;                     // 0x0028(0x0018)(HasGetValueTypeHash)
	class AActor*                                 K2Node_Event_Invoker;                              // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FKey                                   Temp_struct_Variable;                              // 0x0048(0x0018)(HasGetValueTypeHash)
	class ABP_HDPlayerCharacterBase_C*            K2Node_DynamicCast_AsBP_HDPlayer_Character_Base;   // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_69[0x7];                                       // 0x0069(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AController*                            CallFunc_GetController_ReturnValue;                // 0x0070(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABP_HDPlayerControllerBase_C*           K2Node_DynamicCast_AsBP_HDPlayer_Controller_Base;  // 0x0078(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0080(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_81[0x7];                                       // 0x0081(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FKey                                   K2Node_InputActionEvent_Key_1;                     // 0x0088(0x0018)(HasGetValueTypeHash)
	bool                                          CallFunc_HasAuthority_ReturnValue;                 // 0x00A0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_A1[0x7];                                       // 0x00A1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerState*                           K2Node_Event_Player;                               // 0x00A8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UArcVehicleSeatConfig*                  K2Node_Event_ToSeat;                               // 0x00B0(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UArcVehicleSeatConfig*                  K2Node_Event_FromSeat;                             // 0x00B8(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EArcVehicleSeatChangeType                     K2Node_Event_SeatChangeEvent;                      // 0x00C0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x00C1(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_C2[0x6];                                       // 0x00C2(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UArcVehicleSeatConfig*                  CallFunc_GetDriverSeat_ReturnValue;                // 0x00C8(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ObjectObject_ReturnValue;      // 0x00D0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_D1[0x3];                                       // 0x00D1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         K2Node_Event_DeltaSeconds;                         // 0x00D4(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetEngineRotationSpeed_ReturnValue;       // 0x00D8(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase) == 0x000008, "Wrong alignment on BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase");
static_assert(sizeof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase) == 0x0000E0, "Wrong size on BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, EntryPoint) == 0x000000, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::EntryPoint' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_InputActionEvent_Key) == 0x000008, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_InputActionEvent_Key' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_InputAxisEvent_AxisValue_1) == 0x000020, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_InputAxisEvent_AxisValue_1' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_InputAxisEvent_AxisValue) == 0x000024, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_InputAxisEvent_AxisValue' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_InputActionEvent_Key_2) == 0x000028, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_InputActionEvent_Key_2' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_Event_Invoker) == 0x000040, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_Event_Invoker' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, Temp_struct_Variable) == 0x000048, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::Temp_struct_Variable' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_DynamicCast_AsBP_HDPlayer_Character_Base) == 0x000060, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_DynamicCast_AsBP_HDPlayer_Character_Base' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_DynamicCast_bSuccess) == 0x000068, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, CallFunc_GetController_ReturnValue) == 0x000070, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::CallFunc_GetController_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_DynamicCast_AsBP_HDPlayer_Controller_Base) == 0x000078, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_DynamicCast_AsBP_HDPlayer_Controller_Base' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_DynamicCast_bSuccess_1) == 0x000080, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_InputActionEvent_Key_1) == 0x000088, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_InputActionEvent_Key_1' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, CallFunc_HasAuthority_ReturnValue) == 0x0000A0, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::CallFunc_HasAuthority_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_Event_Player) == 0x0000A8, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_Event_Player' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_Event_ToSeat) == 0x0000B0, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_Event_ToSeat' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_Event_FromSeat) == 0x0000B8, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_Event_FromSeat' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_Event_SeatChangeEvent) == 0x0000C0, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_Event_SeatChangeEvent' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_SwitchEnum_CmpSuccess) == 0x0000C1, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_SwitchEnum_CmpSuccess' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, CallFunc_GetDriverSeat_ReturnValue) == 0x0000C8, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::CallFunc_GetDriverSeat_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, CallFunc_EqualEqual_ObjectObject_ReturnValue) == 0x0000D0, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::CallFunc_EqualEqual_ObjectObject_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, K2Node_Event_DeltaSeconds) == 0x0000D4, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::K2Node_Event_DeltaSeconds' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase, CallFunc_GetEngineRotationSpeed_ReturnValue) == 0x0000D8, "Member 'BP_HDVehicleBase_C_ExecuteUbergraph_BP_HDVehicleBase::CallFunc_GetEngineRotationSpeed_ReturnValue' has a wrong offset!");

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.ReceiveTick
// 0x0004 (0x0004 - 0x0000)
struct BP_HDVehicleBase_C_ReceiveTick final
{
public:
	float                                         DeltaSeconds;                                      // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_ReceiveTick) == 0x000004, "Wrong alignment on BP_HDVehicleBase_C_ReceiveTick");
static_assert(sizeof(BP_HDVehicleBase_C_ReceiveTick) == 0x000004, "Wrong size on BP_HDVehicleBase_C_ReceiveTick");
static_assert(offsetof(BP_HDVehicleBase_C_ReceiveTick, DeltaSeconds) == 0x000000, "Member 'BP_HDVehicleBase_C_ReceiveTick::DeltaSeconds' has a wrong offset!");

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.NotifyPlayerSeatChangeEvent
// 0x0020 (0x0020 - 0x0000)
struct BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent final
{
public:
	class APlayerState*                           Player;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UArcVehicleSeatConfig*                  ToSeat;                                            // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UArcVehicleSeatConfig*                  FromSeat;                                          // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EArcVehicleSeatChangeType                     SeatChangeEvent;                                   // 0x0018(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent) == 0x000008, "Wrong alignment on BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent");
static_assert(sizeof(BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent) == 0x000020, "Wrong size on BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent");
static_assert(offsetof(BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent, Player) == 0x000000, "Member 'BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent::Player' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent, ToSeat) == 0x000008, "Member 'BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent::ToSeat' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent, FromSeat) == 0x000010, "Member 'BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent::FromSeat' has a wrong offset!");
static_assert(offsetof(BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent, SeatChangeEvent) == 0x000018, "Member 'BP_HDVehicleBase_C_NotifyPlayerSeatChangeEvent::SeatChangeEvent' has a wrong offset!");

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.Used
// 0x0008 (0x0008 - 0x0000)
struct BP_HDVehicleBase_C_Used final
{
public:
	class AActor*                                 Invoker;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_Used) == 0x000008, "Wrong alignment on BP_HDVehicleBase_C_Used");
static_assert(sizeof(BP_HDVehicleBase_C_Used) == 0x000008, "Wrong size on BP_HDVehicleBase_C_Used");
static_assert(offsetof(BP_HDVehicleBase_C_Used, Invoker) == 0x000000, "Member 'BP_HDVehicleBase_C_Used::Invoker' has a wrong offset!");

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.InpAxisEvt_MoveRight_K2Node_InputAxisEvent_1
// 0x0004 (0x0004 - 0x0000)
struct BP_HDVehicleBase_C_InpAxisEvt_MoveRight_K2Node_InputAxisEvent_1 final
{
public:
	float                                         AxisValue;                                         // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_InpAxisEvt_MoveRight_K2Node_InputAxisEvent_1) == 0x000004, "Wrong alignment on BP_HDVehicleBase_C_InpAxisEvt_MoveRight_K2Node_InputAxisEvent_1");
static_assert(sizeof(BP_HDVehicleBase_C_InpAxisEvt_MoveRight_K2Node_InputAxisEvent_1) == 0x000004, "Wrong size on BP_HDVehicleBase_C_InpAxisEvt_MoveRight_K2Node_InputAxisEvent_1");
static_assert(offsetof(BP_HDVehicleBase_C_InpAxisEvt_MoveRight_K2Node_InputAxisEvent_1, AxisValue) == 0x000000, "Member 'BP_HDVehicleBase_C_InpAxisEvt_MoveRight_K2Node_InputAxisEvent_1::AxisValue' has a wrong offset!");

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.InpAxisEvt_MoveForward_K2Node_InputAxisEvent_0
// 0x0004 (0x0004 - 0x0000)
struct BP_HDVehicleBase_C_InpAxisEvt_MoveForward_K2Node_InputAxisEvent_0 final
{
public:
	float                                         AxisValue;                                         // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_InpAxisEvt_MoveForward_K2Node_InputAxisEvent_0) == 0x000004, "Wrong alignment on BP_HDVehicleBase_C_InpAxisEvt_MoveForward_K2Node_InputAxisEvent_0");
static_assert(sizeof(BP_HDVehicleBase_C_InpAxisEvt_MoveForward_K2Node_InputAxisEvent_0) == 0x000004, "Wrong size on BP_HDVehicleBase_C_InpAxisEvt_MoveForward_K2Node_InputAxisEvent_0");
static_assert(offsetof(BP_HDVehicleBase_C_InpAxisEvt_MoveForward_K2Node_InputAxisEvent_0, AxisValue) == 0x000000, "Member 'BP_HDVehicleBase_C_InpAxisEvt_MoveForward_K2Node_InputAxisEvent_0::AxisValue' has a wrong offset!");

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.InpActEvt_Use_K2Node_InputActionEvent_0
// 0x0018 (0x0018 - 0x0000)
struct BP_HDVehicleBase_C_InpActEvt_Use_K2Node_InputActionEvent_0 final
{
public:
	struct FKey                                   Key;                                               // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_InpActEvt_Use_K2Node_InputActionEvent_0) == 0x000008, "Wrong alignment on BP_HDVehicleBase_C_InpActEvt_Use_K2Node_InputActionEvent_0");
static_assert(sizeof(BP_HDVehicleBase_C_InpActEvt_Use_K2Node_InputActionEvent_0) == 0x000018, "Wrong size on BP_HDVehicleBase_C_InpActEvt_Use_K2Node_InputActionEvent_0");
static_assert(offsetof(BP_HDVehicleBase_C_InpActEvt_Use_K2Node_InputActionEvent_0, Key) == 0x000000, "Member 'BP_HDVehicleBase_C_InpActEvt_Use_K2Node_InputActionEvent_0::Key' has a wrong offset!");

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.InpActEvt_Jump_K2Node_InputActionEvent_1
// 0x0018 (0x0018 - 0x0000)
struct BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_1 final
{
public:
	struct FKey                                   Key;                                               // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_1) == 0x000008, "Wrong alignment on BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_1");
static_assert(sizeof(BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_1) == 0x000018, "Wrong size on BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_1");
static_assert(offsetof(BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_1, Key) == 0x000000, "Member 'BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_1::Key' has a wrong offset!");

// Function BP_HDVehicleBase.BP_HDVehicleBase_C.InpActEvt_Jump_K2Node_InputActionEvent_2
// 0x0018 (0x0018 - 0x0000)
struct BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_2 final
{
public:
	struct FKey                                   Key;                                               // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
};
static_assert(alignof(BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_2) == 0x000008, "Wrong alignment on BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_2");
static_assert(sizeof(BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_2) == 0x000018, "Wrong size on BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_2");
static_assert(offsetof(BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_2, Key) == 0x000000, "Member 'BP_HDVehicleBase_C_InpActEvt_Jump_K2Node_InputActionEvent_2::Key' has a wrong offset!");

}

