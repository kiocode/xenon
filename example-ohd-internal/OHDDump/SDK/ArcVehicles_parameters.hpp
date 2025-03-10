#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ArcVehicles

#include "Basic.hpp"

#include "ArcVehicles_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function ArcVehicles.ArcVehiclePawn.GetOwningVehicle
// 0x0008 (0x0008 - 0x0000)
struct ArcVehiclePawn_GetOwningVehicle final
{
public:
	class AArcBaseVehicle*                        ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehiclePawn_GetOwningVehicle) == 0x000008, "Wrong alignment on ArcVehiclePawn_GetOwningVehicle");
static_assert(sizeof(ArcVehiclePawn_GetOwningVehicle) == 0x000008, "Wrong size on ArcVehiclePawn_GetOwningVehicle");
static_assert(offsetof(ArcVehiclePawn_GetOwningVehicle, ReturnValue) == 0x000000, "Member 'ArcVehiclePawn_GetOwningVehicle::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehiclePawn.GetSeatConfig
// 0x0008 (0x0008 - 0x0000)
struct ArcVehiclePawn_GetSeatConfig final
{
public:
	class UArcVehicleSeatConfig*                  ReturnValue;                                       // 0x0000(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehiclePawn_GetSeatConfig) == 0x000008, "Wrong alignment on ArcVehiclePawn_GetSeatConfig");
static_assert(sizeof(ArcVehiclePawn_GetSeatConfig) == 0x000008, "Wrong size on ArcVehiclePawn_GetSeatConfig");
static_assert(offsetof(ArcVehiclePawn_GetSeatConfig, ReturnValue) == 0x000000, "Member 'ArcVehiclePawn_GetSeatConfig::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehiclePawn.NotifyPlayerSeatChangeEvent
// 0x0020 (0x0020 - 0x0000)
struct ArcVehiclePawn_NotifyPlayerSeatChangeEvent final
{
public:
	class APlayerState*                           Player;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UArcVehicleSeatConfig*                  ToSeat;                                            // 0x0008(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UArcVehicleSeatConfig*                  FromSeat;                                          // 0x0010(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EArcVehicleSeatChangeType                     SeatChangeEvent;                                   // 0x0018(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(ArcVehiclePawn_NotifyPlayerSeatChangeEvent) == 0x000008, "Wrong alignment on ArcVehiclePawn_NotifyPlayerSeatChangeEvent");
static_assert(sizeof(ArcVehiclePawn_NotifyPlayerSeatChangeEvent) == 0x000020, "Wrong size on ArcVehiclePawn_NotifyPlayerSeatChangeEvent");
static_assert(offsetof(ArcVehiclePawn_NotifyPlayerSeatChangeEvent, Player) == 0x000000, "Member 'ArcVehiclePawn_NotifyPlayerSeatChangeEvent::Player' has a wrong offset!");
static_assert(offsetof(ArcVehiclePawn_NotifyPlayerSeatChangeEvent, ToSeat) == 0x000008, "Member 'ArcVehiclePawn_NotifyPlayerSeatChangeEvent::ToSeat' has a wrong offset!");
static_assert(offsetof(ArcVehiclePawn_NotifyPlayerSeatChangeEvent, FromSeat) == 0x000010, "Member 'ArcVehiclePawn_NotifyPlayerSeatChangeEvent::FromSeat' has a wrong offset!");
static_assert(offsetof(ArcVehiclePawn_NotifyPlayerSeatChangeEvent, SeatChangeEvent) == 0x000018, "Member 'ArcVehiclePawn_NotifyPlayerSeatChangeEvent::SeatChangeEvent' has a wrong offset!");

// Function ArcVehicles.ArcVehiclePlayerSeatComponent.BP_OnRep_StoredPlayerState
// 0x0008 (0x0008 - 0x0000)
struct ArcVehiclePlayerSeatComponent_BP_OnRep_StoredPlayerState final
{
public:
	class APlayerState*                           InPreviousPlayerState;                             // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehiclePlayerSeatComponent_BP_OnRep_StoredPlayerState) == 0x000008, "Wrong alignment on ArcVehiclePlayerSeatComponent_BP_OnRep_StoredPlayerState");
static_assert(sizeof(ArcVehiclePlayerSeatComponent_BP_OnRep_StoredPlayerState) == 0x000008, "Wrong size on ArcVehiclePlayerSeatComponent_BP_OnRep_StoredPlayerState");
static_assert(offsetof(ArcVehiclePlayerSeatComponent_BP_OnRep_StoredPlayerState, InPreviousPlayerState) == 0x000000, "Member 'ArcVehiclePlayerSeatComponent_BP_OnRep_StoredPlayerState::InPreviousPlayerState' has a wrong offset!");

// Function ArcVehicles.ArcVehiclePlayerSeatComponent.OnRep_SeatConfig
// 0x0010 (0x0010 - 0x0000)
struct ArcVehiclePlayerSeatComponent_OnRep_SeatConfig final
{
public:
	struct FArcVehicleSeatReference               InPreviousSeatConfig;                              // 0x0000(0x0010)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehiclePlayerSeatComponent_OnRep_SeatConfig) == 0x000008, "Wrong alignment on ArcVehiclePlayerSeatComponent_OnRep_SeatConfig");
static_assert(sizeof(ArcVehiclePlayerSeatComponent_OnRep_SeatConfig) == 0x000010, "Wrong size on ArcVehiclePlayerSeatComponent_OnRep_SeatConfig");
static_assert(offsetof(ArcVehiclePlayerSeatComponent_OnRep_SeatConfig, InPreviousSeatConfig) == 0x000000, "Member 'ArcVehiclePlayerSeatComponent_OnRep_SeatConfig::InPreviousSeatConfig' has a wrong offset!");

// Function ArcVehicles.ArcVehiclePlayerSeatComponent.OnRep_StoredPlayerState
// 0x0008 (0x0008 - 0x0000)
struct ArcVehiclePlayerSeatComponent_OnRep_StoredPlayerState final
{
public:
	class APlayerState*                           InPreviousPlayerState;                             // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehiclePlayerSeatComponent_OnRep_StoredPlayerState) == 0x000008, "Wrong alignment on ArcVehiclePlayerSeatComponent_OnRep_StoredPlayerState");
static_assert(sizeof(ArcVehiclePlayerSeatComponent_OnRep_StoredPlayerState) == 0x000008, "Wrong size on ArcVehiclePlayerSeatComponent_OnRep_StoredPlayerState");
static_assert(offsetof(ArcVehiclePlayerSeatComponent_OnRep_StoredPlayerState, InPreviousPlayerState) == 0x000000, "Member 'ArcVehiclePlayerSeatComponent_OnRep_StoredPlayerState::InPreviousPlayerState' has a wrong offset!");

// Function ArcVehicles.ArcVehiclePlayerSeatComponent.OnSeatChangeEvent
// 0x0001 (0x0001 - 0x0000)
struct ArcVehiclePlayerSeatComponent_OnSeatChangeEvent final
{
public:
	EArcVehicleSeatChangeType                     SeatChangeType;                                    // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehiclePlayerSeatComponent_OnSeatChangeEvent) == 0x000001, "Wrong alignment on ArcVehiclePlayerSeatComponent_OnSeatChangeEvent");
static_assert(sizeof(ArcVehiclePlayerSeatComponent_OnSeatChangeEvent) == 0x000001, "Wrong size on ArcVehiclePlayerSeatComponent_OnSeatChangeEvent");
static_assert(offsetof(ArcVehiclePlayerSeatComponent_OnSeatChangeEvent, SeatChangeType) == 0x000000, "Member 'ArcVehiclePlayerSeatComponent_OnSeatChangeEvent::SeatChangeType' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.GetAllSeats
// 0x0010 (0x0010 - 0x0000)
struct ArcBaseVehicle_GetAllSeats final
{
public:
	TArray<class UArcVehicleSeatConfig*>          Seats;                                             // 0x0000(0x0010)(Parm, OutParm, ZeroConstructor, ContainsInstancedReference, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcBaseVehicle_GetAllSeats) == 0x000008, "Wrong alignment on ArcBaseVehicle_GetAllSeats");
static_assert(sizeof(ArcBaseVehicle_GetAllSeats) == 0x000010, "Wrong size on ArcBaseVehicle_GetAllSeats");
static_assert(offsetof(ArcBaseVehicle_GetAllSeats, Seats) == 0x000000, "Member 'ArcBaseVehicle_GetAllSeats::Seats' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.GetDriverSeat
// 0x0008 (0x0008 - 0x0000)
struct ArcBaseVehicle_GetDriverSeat final
{
public:
	class UArcVehicleSeatConfig*                  ReturnValue;                                       // 0x0000(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcBaseVehicle_GetDriverSeat) == 0x000008, "Wrong alignment on ArcBaseVehicle_GetDriverSeat");
static_assert(sizeof(ArcBaseVehicle_GetDriverSeat) == 0x000008, "Wrong size on ArcBaseVehicle_GetDriverSeat");
static_assert(offsetof(ArcBaseVehicle_GetDriverSeat, ReturnValue) == 0x000000, "Member 'ArcBaseVehicle_GetDriverSeat::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.GetNearestExitTransform
// 0x0060 (0x0060 - 0x0000)
struct ArcBaseVehicle_GetNearestExitTransform final
{
public:
	struct FTransform                             InputLocation;                                     // 0x0000(0x0030)(Parm, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	struct FTransform                             ReturnValue;                                       // 0x0030(0x0030)(Parm, OutParm, ReturnParm, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcBaseVehicle_GetNearestExitTransform) == 0x000010, "Wrong alignment on ArcBaseVehicle_GetNearestExitTransform");
static_assert(sizeof(ArcBaseVehicle_GetNearestExitTransform) == 0x000060, "Wrong size on ArcBaseVehicle_GetNearestExitTransform");
static_assert(offsetof(ArcBaseVehicle_GetNearestExitTransform, InputLocation) == 0x000000, "Member 'ArcBaseVehicle_GetNearestExitTransform::InputLocation' has a wrong offset!");
static_assert(offsetof(ArcBaseVehicle_GetNearestExitTransform, ReturnValue) == 0x000030, "Member 'ArcBaseVehicle_GetNearestExitTransform::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.RequestEnterAnySeat
// 0x0008 (0x0008 - 0x0000)
struct ArcBaseVehicle_RequestEnterAnySeat final
{
public:
	class APlayerState*                           InPlayerState;                                     // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcBaseVehicle_RequestEnterAnySeat) == 0x000008, "Wrong alignment on ArcBaseVehicle_RequestEnterAnySeat");
static_assert(sizeof(ArcBaseVehicle_RequestEnterAnySeat) == 0x000008, "Wrong size on ArcBaseVehicle_RequestEnterAnySeat");
static_assert(offsetof(ArcBaseVehicle_RequestEnterAnySeat, InPlayerState) == 0x000000, "Member 'ArcBaseVehicle_RequestEnterAnySeat::InPlayerState' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.RequestEnterSeat
// 0x0010 (0x0010 - 0x0000)
struct ArcBaseVehicle_RequestEnterSeat final
{
public:
	class APlayerState*                           InPlayerState;                                     // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         RequestedSeatIndex;                                // 0x0008(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bIgnoreRestrictions;                               // 0x000C(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(ArcBaseVehicle_RequestEnterSeat) == 0x000008, "Wrong alignment on ArcBaseVehicle_RequestEnterSeat");
static_assert(sizeof(ArcBaseVehicle_RequestEnterSeat) == 0x000010, "Wrong size on ArcBaseVehicle_RequestEnterSeat");
static_assert(offsetof(ArcBaseVehicle_RequestEnterSeat, InPlayerState) == 0x000000, "Member 'ArcBaseVehicle_RequestEnterSeat::InPlayerState' has a wrong offset!");
static_assert(offsetof(ArcBaseVehicle_RequestEnterSeat, RequestedSeatIndex) == 0x000008, "Member 'ArcBaseVehicle_RequestEnterSeat::RequestedSeatIndex' has a wrong offset!");
static_assert(offsetof(ArcBaseVehicle_RequestEnterSeat, bIgnoreRestrictions) == 0x00000C, "Member 'ArcBaseVehicle_RequestEnterSeat::bIgnoreRestrictions' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.RequestLeaveVehicle
// 0x0008 (0x0008 - 0x0000)
struct ArcBaseVehicle_RequestLeaveVehicle final
{
public:
	class APlayerState*                           InPlayerState;                                     // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcBaseVehicle_RequestLeaveVehicle) == 0x000008, "Wrong alignment on ArcBaseVehicle_RequestLeaveVehicle");
static_assert(sizeof(ArcBaseVehicle_RequestLeaveVehicle) == 0x000008, "Wrong size on ArcBaseVehicle_RequestLeaveVehicle");
static_assert(offsetof(ArcBaseVehicle_RequestLeaveVehicle, InPlayerState) == 0x000000, "Member 'ArcBaseVehicle_RequestLeaveVehicle::InPlayerState' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.SetupSeat
// 0x0008 (0x0008 - 0x0000)
struct ArcBaseVehicle_SetupSeat final
{
public:
	class UArcVehicleSeatConfig*                  SeatConfig;                                        // 0x0000(0x0008)(Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcBaseVehicle_SetupSeat) == 0x000008, "Wrong alignment on ArcBaseVehicle_SetupSeat");
static_assert(sizeof(ArcBaseVehicle_SetupSeat) == 0x000008, "Wrong size on ArcBaseVehicle_SetupSeat");
static_assert(offsetof(ArcBaseVehicle_SetupSeat, SeatConfig) == 0x000000, "Member 'ArcBaseVehicle_SetupSeat::SeatConfig' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.GetSortedExitPoints
// 0x0040 (0x0040 - 0x0000)
struct ArcBaseVehicle_GetSortedExitPoints final
{
public:
	struct FTransform                             InputLocation;                                     // 0x0000(0x0030)(Parm, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	TArray<struct FTransform>                     OutTransformArray;                                 // 0x0030(0x0010)(Parm, OutParm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcBaseVehicle_GetSortedExitPoints) == 0x000010, "Wrong alignment on ArcBaseVehicle_GetSortedExitPoints");
static_assert(sizeof(ArcBaseVehicle_GetSortedExitPoints) == 0x000040, "Wrong size on ArcBaseVehicle_GetSortedExitPoints");
static_assert(offsetof(ArcBaseVehicle_GetSortedExitPoints, InputLocation) == 0x000000, "Member 'ArcBaseVehicle_GetSortedExitPoints::InputLocation' has a wrong offset!");
static_assert(offsetof(ArcBaseVehicle_GetSortedExitPoints, OutTransformArray) == 0x000030, "Member 'ArcBaseVehicle_GetSortedExitPoints::OutTransformArray' has a wrong offset!");

// Function ArcVehicles.ArcBaseVehicle.IsValidSeatIndex
// 0x0008 (0x0008 - 0x0000)
struct ArcBaseVehicle_IsValidSeatIndex final
{
public:
	int32                                         InSeatIndex;                                       // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(ArcBaseVehicle_IsValidSeatIndex) == 0x000004, "Wrong alignment on ArcBaseVehicle_IsValidSeatIndex");
static_assert(sizeof(ArcBaseVehicle_IsValidSeatIndex) == 0x000008, "Wrong size on ArcBaseVehicle_IsValidSeatIndex");
static_assert(offsetof(ArcBaseVehicle_IsValidSeatIndex, InSeatIndex) == 0x000000, "Member 'ArcBaseVehicle_IsValidSeatIndex::InSeatIndex' has a wrong offset!");
static_assert(offsetof(ArcBaseVehicle_IsValidSeatIndex, ReturnValue) == 0x000004, "Member 'ArcBaseVehicle_IsValidSeatIndex::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehicleBPFunctionLibrary.GetVehicleFromSeatConfig
// 0x0018 (0x0018 - 0x0000)
struct ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig final
{
public:
	struct FArcVehicleSeatReference               SeatRef;                                           // 0x0000(0x0010)(Parm, NoDestructor, NativeAccessSpecifierPublic)
	class AArcBaseVehicle*                        ReturnValue;                                       // 0x0010(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig) == 0x000008, "Wrong alignment on ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig");
static_assert(sizeof(ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig) == 0x000018, "Wrong size on ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig");
static_assert(offsetof(ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig, SeatRef) == 0x000000, "Member 'ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig::SeatRef' has a wrong offset!");
static_assert(offsetof(ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig, ReturnValue) == 0x000010, "Member 'ArcVehicleBPFunctionLibrary_GetVehicleFromSeatConfig::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehicleBPFunctionLibrary.GetVehicleSeatConfigFromRef
// 0x0018 (0x0018 - 0x0000)
struct ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef final
{
public:
	struct FArcVehicleSeatReference               SeatRef;                                           // 0x0000(0x0010)(Parm, NoDestructor, NativeAccessSpecifierPublic)
	class UArcVehicleSeatConfig*                  ReturnValue;                                       // 0x0010(0x0008)(ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef) == 0x000008, "Wrong alignment on ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef");
static_assert(sizeof(ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef) == 0x000018, "Wrong size on ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef");
static_assert(offsetof(ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef, SeatRef) == 0x000000, "Member 'ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef::SeatRef' has a wrong offset!");
static_assert(offsetof(ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef, ReturnValue) == 0x000010, "Member 'ArcVehicleBPFunctionLibrary_GetVehicleSeatConfigFromRef::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehicleBPFunctionLibrary.IsSeatRefValid
// 0x0018 (0x0018 - 0x0000)
struct ArcVehicleBPFunctionLibrary_IsSeatRefValid final
{
public:
	struct FArcVehicleSeatReference               SeatRef;                                           // 0x0000(0x0010)(Parm, NoDestructor, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(ArcVehicleBPFunctionLibrary_IsSeatRefValid) == 0x000008, "Wrong alignment on ArcVehicleBPFunctionLibrary_IsSeatRefValid");
static_assert(sizeof(ArcVehicleBPFunctionLibrary_IsSeatRefValid) == 0x000018, "Wrong size on ArcVehicleBPFunctionLibrary_IsSeatRefValid");
static_assert(offsetof(ArcVehicleBPFunctionLibrary_IsSeatRefValid, SeatRef) == 0x000000, "Member 'ArcVehicleBPFunctionLibrary_IsSeatRefValid::SeatRef' has a wrong offset!");
static_assert(offsetof(ArcVehicleBPFunctionLibrary_IsSeatRefValid, ReturnValue) == 0x000010, "Member 'ArcVehicleBPFunctionLibrary_IsSeatRefValid::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehicleSeatConfig.AttachPlayerToSeat
// 0x0008 (0x0008 - 0x0000)
struct ArcVehicleSeatConfig_AttachPlayerToSeat final
{
public:
	class APlayerState*                           Player;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleSeatConfig_AttachPlayerToSeat) == 0x000008, "Wrong alignment on ArcVehicleSeatConfig_AttachPlayerToSeat");
static_assert(sizeof(ArcVehicleSeatConfig_AttachPlayerToSeat) == 0x000008, "Wrong size on ArcVehicleSeatConfig_AttachPlayerToSeat");
static_assert(offsetof(ArcVehicleSeatConfig_AttachPlayerToSeat, Player) == 0x000000, "Member 'ArcVehicleSeatConfig_AttachPlayerToSeat::Player' has a wrong offset!");

// Function ArcVehicles.ArcVehicleSeatConfig.BP_AttachPlayerToSeat
// 0x0008 (0x0008 - 0x0000)
struct ArcVehicleSeatConfig_BP_AttachPlayerToSeat final
{
public:
	class APlayerState*                           Player;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleSeatConfig_BP_AttachPlayerToSeat) == 0x000008, "Wrong alignment on ArcVehicleSeatConfig_BP_AttachPlayerToSeat");
static_assert(sizeof(ArcVehicleSeatConfig_BP_AttachPlayerToSeat) == 0x000008, "Wrong size on ArcVehicleSeatConfig_BP_AttachPlayerToSeat");
static_assert(offsetof(ArcVehicleSeatConfig_BP_AttachPlayerToSeat, Player) == 0x000000, "Member 'ArcVehicleSeatConfig_BP_AttachPlayerToSeat::Player' has a wrong offset!");

// Function ArcVehicles.ArcVehicleSeatConfig.BP_UnAttachPlayerFromSeat
// 0x0008 (0x0008 - 0x0000)
struct ArcVehicleSeatConfig_BP_UnAttachPlayerFromSeat final
{
public:
	class APlayerState*                           Player;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleSeatConfig_BP_UnAttachPlayerFromSeat) == 0x000008, "Wrong alignment on ArcVehicleSeatConfig_BP_UnAttachPlayerFromSeat");
static_assert(sizeof(ArcVehicleSeatConfig_BP_UnAttachPlayerFromSeat) == 0x000008, "Wrong size on ArcVehicleSeatConfig_BP_UnAttachPlayerFromSeat");
static_assert(offsetof(ArcVehicleSeatConfig_BP_UnAttachPlayerFromSeat, Player) == 0x000000, "Member 'ArcVehicleSeatConfig_BP_UnAttachPlayerFromSeat::Player' has a wrong offset!");

// Function ArcVehicles.ArcVehicleSeatConfig.UnAttachPlayerFromSeat
// 0x0008 (0x0008 - 0x0000)
struct ArcVehicleSeatConfig_UnAttachPlayerFromSeat final
{
public:
	class APlayerState*                           Player;                                            // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleSeatConfig_UnAttachPlayerFromSeat) == 0x000008, "Wrong alignment on ArcVehicleSeatConfig_UnAttachPlayerFromSeat");
static_assert(sizeof(ArcVehicleSeatConfig_UnAttachPlayerFromSeat) == 0x000008, "Wrong size on ArcVehicleSeatConfig_UnAttachPlayerFromSeat");
static_assert(offsetof(ArcVehicleSeatConfig_UnAttachPlayerFromSeat, Player) == 0x000000, "Member 'ArcVehicleSeatConfig_UnAttachPlayerFromSeat::Player' has a wrong offset!");

// Function ArcVehicles.ArcVehicleSeatConfig.GetVehicleOwner
// 0x0008 (0x0008 - 0x0000)
struct ArcVehicleSeatConfig_GetVehicleOwner final
{
public:
	class AArcBaseVehicle*                        ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleSeatConfig_GetVehicleOwner) == 0x000008, "Wrong alignment on ArcVehicleSeatConfig_GetVehicleOwner");
static_assert(sizeof(ArcVehicleSeatConfig_GetVehicleOwner) == 0x000008, "Wrong size on ArcVehicleSeatConfig_GetVehicleOwner");
static_assert(offsetof(ArcVehicleSeatConfig_GetVehicleOwner, ReturnValue) == 0x000000, "Member 'ArcVehicleSeatConfig_GetVehicleOwner::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehicleSeatConfig.IsDriverSeat
// 0x0001 (0x0001 - 0x0000)
struct ArcVehicleSeatConfig_IsDriverSeat final
{
public:
	bool                                          ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleSeatConfig_IsDriverSeat) == 0x000001, "Wrong alignment on ArcVehicleSeatConfig_IsDriverSeat");
static_assert(sizeof(ArcVehicleSeatConfig_IsDriverSeat) == 0x000001, "Wrong size on ArcVehicleSeatConfig_IsDriverSeat");
static_assert(offsetof(ArcVehicleSeatConfig_IsDriverSeat, ReturnValue) == 0x000000, "Member 'ArcVehicleSeatConfig_IsDriverSeat::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehicleSeatConfig.IsOpenSeat
// 0x0001 (0x0001 - 0x0000)
struct ArcVehicleSeatConfig_IsOpenSeat final
{
public:
	bool                                          ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleSeatConfig_IsOpenSeat) == 0x000001, "Wrong alignment on ArcVehicleSeatConfig_IsOpenSeat");
static_assert(sizeof(ArcVehicleSeatConfig_IsOpenSeat) == 0x000001, "Wrong size on ArcVehicleSeatConfig_IsOpenSeat");
static_assert(offsetof(ArcVehicleSeatConfig_IsOpenSeat, ReturnValue) == 0x000000, "Member 'ArcVehicleSeatConfig_IsOpenSeat::ReturnValue' has a wrong offset!");

// Function ArcVehicles.ArcVehicleSeatConfig_SeatPawn.OnRep_SeatPawn
// 0x0008 (0x0008 - 0x0000)
struct ArcVehicleSeatConfig_SeatPawn_OnRep_SeatPawn final
{
public:
	class AArcVehiclePawn*                        OldSeatPawn;                                       // 0x0000(0x0008)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleSeatConfig_SeatPawn_OnRep_SeatPawn) == 0x000008, "Wrong alignment on ArcVehicleSeatConfig_SeatPawn_OnRep_SeatPawn");
static_assert(sizeof(ArcVehicleSeatConfig_SeatPawn_OnRep_SeatPawn) == 0x000008, "Wrong size on ArcVehicleSeatConfig_SeatPawn_OnRep_SeatPawn");
static_assert(offsetof(ArcVehicleSeatConfig_SeatPawn_OnRep_SeatPawn, OldSeatPawn) == 0x000000, "Member 'ArcVehicleSeatConfig_SeatPawn_OnRep_SeatPawn::OldSeatPawn' has a wrong offset!");

// Function ArcVehicles.ArcVehicleTurretMovementComp.Server_ServerMove
// 0x000C (0x000C - 0x0000)
struct ArcVehicleTurretMovementComp_Server_ServerMove final
{
public:
	struct FRotator                               FullRotation;                                      // 0x0000(0x000C)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
};
static_assert(alignof(ArcVehicleTurretMovementComp_Server_ServerMove) == 0x000004, "Wrong alignment on ArcVehicleTurretMovementComp_Server_ServerMove");
static_assert(sizeof(ArcVehicleTurretMovementComp_Server_ServerMove) == 0x00000C, "Wrong size on ArcVehicleTurretMovementComp_Server_ServerMove");
static_assert(offsetof(ArcVehicleTurretMovementComp_Server_ServerMove, FullRotation) == 0x000000, "Member 'ArcVehicleTurretMovementComp_Server_ServerMove::FullRotation' has a wrong offset!");

}

