#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPFL_HDComms

#include "Basic.hpp"

#include "SlateCore_structs.hpp"


namespace SDK::Params
{

// Function BPFL_HDComms.BPFL_HDComms_C.GetValidCommsComponentForPlayer
// 0x0038 (0x0038 - 0x0000)
struct BPFL_HDComms_C_GetValidCommsComponentForPlayer final
{
public:
	class APlayerController*                      Player;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UObject*                                __WorldContext;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UDFPlayerCommsComponent*                PlayerCommsComp;                                   // 0x0010(0x0008)(Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UDFCommWorldSubsystem*                  CallFunc_GetWorldSubsystem_ReturnValue;            // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UDFPlayerCommsComponent*                CallFunc_FindCommsComponentByPlayer_OutPlayerCommsComp; // 0x0020(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_FindCommsComponentByPlayer_ReturnValue;   // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UDFPlayerCommsComponent*                CallFunc_InitPlayerComms_ReturnValue;              // 0x0030(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BPFL_HDComms_C_GetValidCommsComponentForPlayer) == 0x000008, "Wrong alignment on BPFL_HDComms_C_GetValidCommsComponentForPlayer");
static_assert(sizeof(BPFL_HDComms_C_GetValidCommsComponentForPlayer) == 0x000038, "Wrong size on BPFL_HDComms_C_GetValidCommsComponentForPlayer");
static_assert(offsetof(BPFL_HDComms_C_GetValidCommsComponentForPlayer, Player) == 0x000000, "Member 'BPFL_HDComms_C_GetValidCommsComponentForPlayer::Player' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetValidCommsComponentForPlayer, __WorldContext) == 0x000008, "Member 'BPFL_HDComms_C_GetValidCommsComponentForPlayer::__WorldContext' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetValidCommsComponentForPlayer, PlayerCommsComp) == 0x000010, "Member 'BPFL_HDComms_C_GetValidCommsComponentForPlayer::PlayerCommsComp' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetValidCommsComponentForPlayer, CallFunc_GetWorldSubsystem_ReturnValue) == 0x000018, "Member 'BPFL_HDComms_C_GetValidCommsComponentForPlayer::CallFunc_GetWorldSubsystem_ReturnValue' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetValidCommsComponentForPlayer, CallFunc_FindCommsComponentByPlayer_OutPlayerCommsComp) == 0x000020, "Member 'BPFL_HDComms_C_GetValidCommsComponentForPlayer::CallFunc_FindCommsComponentByPlayer_OutPlayerCommsComp' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetValidCommsComponentForPlayer, CallFunc_FindCommsComponentByPlayer_ReturnValue) == 0x000028, "Member 'BPFL_HDComms_C_GetValidCommsComponentForPlayer::CallFunc_FindCommsComponentByPlayer_ReturnValue' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetValidCommsComponentForPlayer, CallFunc_InitPlayerComms_ReturnValue) == 0x000030, "Member 'BPFL_HDComms_C_GetValidCommsComponentForPlayer::CallFunc_InitPlayerComms_ReturnValue' has a wrong offset!");

// Function BPFL_HDComms.BPFL_HDComms_C.GetColorForCommChannel
// 0x0120 (0x0120 - 0x0000)
struct BPFL_HDComms_C_GetColorForCommChannel final
{
public:
	class UDFCommChannel*                         Channel;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UObject*                                __WorldContext;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSlateColor                            ChannelColor;                                      // 0x0010(0x0028)(Parm, OutParm)
	struct FSlateColor                            CommandChannelGroupColor;                          // 0x0038(0x0028)(Edit, BlueprintVisible)
	struct FSlateColor                            SquadChannelGroupColor;                            // 0x0060(0x0028)(Edit, BlueprintVisible)
	struct FSlateColor                            TeamChannelColor;                                  // 0x0088(0x0028)(Edit, BlueprintVisible)
	struct FSlateColor                            LocalChannelGroupColor;                            // 0x00B0(0x0028)(Edit, BlueprintVisible)
	bool                                          Temp_bool_Variable;                                // 0x00D8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_D9[0x3];                                       // 0x00D9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   CallFunc_GetChannelName_ReturnValue;               // 0x00DC(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_InstancesChannelWithGroup_ReturnValue;    // 0x00E4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_E5[0x3];                                       // 0x00E5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   K2Node_Select_Default;                             // 0x00E8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchName_CmpSuccess;                      // 0x00F0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_F1[0x7];                                       // 0x00F1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateColor                            K2Node_MakeStruct_SlateColor;                      // 0x00F8(0x0028)()
};
static_assert(alignof(BPFL_HDComms_C_GetColorForCommChannel) == 0x000008, "Wrong alignment on BPFL_HDComms_C_GetColorForCommChannel");
static_assert(sizeof(BPFL_HDComms_C_GetColorForCommChannel) == 0x000120, "Wrong size on BPFL_HDComms_C_GetColorForCommChannel");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, Channel) == 0x000000, "Member 'BPFL_HDComms_C_GetColorForCommChannel::Channel' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, __WorldContext) == 0x000008, "Member 'BPFL_HDComms_C_GetColorForCommChannel::__WorldContext' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, ChannelColor) == 0x000010, "Member 'BPFL_HDComms_C_GetColorForCommChannel::ChannelColor' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, CommandChannelGroupColor) == 0x000038, "Member 'BPFL_HDComms_C_GetColorForCommChannel::CommandChannelGroupColor' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, SquadChannelGroupColor) == 0x000060, "Member 'BPFL_HDComms_C_GetColorForCommChannel::SquadChannelGroupColor' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, TeamChannelColor) == 0x000088, "Member 'BPFL_HDComms_C_GetColorForCommChannel::TeamChannelColor' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, LocalChannelGroupColor) == 0x0000B0, "Member 'BPFL_HDComms_C_GetColorForCommChannel::LocalChannelGroupColor' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, Temp_bool_Variable) == 0x0000D8, "Member 'BPFL_HDComms_C_GetColorForCommChannel::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, CallFunc_GetChannelName_ReturnValue) == 0x0000DC, "Member 'BPFL_HDComms_C_GetColorForCommChannel::CallFunc_GetChannelName_ReturnValue' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, CallFunc_InstancesChannelWithGroup_ReturnValue) == 0x0000E4, "Member 'BPFL_HDComms_C_GetColorForCommChannel::CallFunc_InstancesChannelWithGroup_ReturnValue' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, K2Node_Select_Default) == 0x0000E8, "Member 'BPFL_HDComms_C_GetColorForCommChannel::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, K2Node_SwitchName_CmpSuccess) == 0x0000F0, "Member 'BPFL_HDComms_C_GetColorForCommChannel::K2Node_SwitchName_CmpSuccess' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetColorForCommChannel, K2Node_MakeStruct_SlateColor) == 0x0000F8, "Member 'BPFL_HDComms_C_GetColorForCommChannel::K2Node_MakeStruct_SlateColor' has a wrong offset!");

// Function BPFL_HDComms.BPFL_HDComms_C.SetupNewTeamChannel
// 0x0028 (0x0028 - 0x0000)
struct BPFL_HDComms_C_SetupNewTeamChannel final
{
public:
	class UDFCommChannel*                         CreatedChannel;                                    // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AHDTeamState*                           TeamToAssociate;                                   // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UObject*                                __WorldContext;                                    // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UHDTeamCommChannelState*                K2Node_DynamicCast_AsHDTeam_Comm_Channel_State;    // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BPFL_HDComms_C_SetupNewTeamChannel) == 0x000008, "Wrong alignment on BPFL_HDComms_C_SetupNewTeamChannel");
static_assert(sizeof(BPFL_HDComms_C_SetupNewTeamChannel) == 0x000028, "Wrong size on BPFL_HDComms_C_SetupNewTeamChannel");
static_assert(offsetof(BPFL_HDComms_C_SetupNewTeamChannel, CreatedChannel) == 0x000000, "Member 'BPFL_HDComms_C_SetupNewTeamChannel::CreatedChannel' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_SetupNewTeamChannel, TeamToAssociate) == 0x000008, "Member 'BPFL_HDComms_C_SetupNewTeamChannel::TeamToAssociate' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_SetupNewTeamChannel, __WorldContext) == 0x000010, "Member 'BPFL_HDComms_C_SetupNewTeamChannel::__WorldContext' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_SetupNewTeamChannel, K2Node_DynamicCast_AsHDTeam_Comm_Channel_State) == 0x000018, "Member 'BPFL_HDComms_C_SetupNewTeamChannel::K2Node_DynamicCast_AsHDTeam_Comm_Channel_State' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_SetupNewTeamChannel, K2Node_DynamicCast_bSuccess) == 0x000020, "Member 'BPFL_HDComms_C_SetupNewTeamChannel::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function BPFL_HDComms.BPFL_HDComms_C.SetupNewSquadChannel
// 0x0028 (0x0028 - 0x0000)
struct BPFL_HDComms_C_SetupNewSquadChannel final
{
public:
	class UDFCommChannel*                         CreatedChannel;                                    // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AHDSquadState*                          SquadToAssociate;                                  // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UObject*                                __WorldContext;                                    // 0x0010(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UHDSQCommChannelState*                  K2Node_DynamicCast_AsHDSQComm_Channel_State;       // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BPFL_HDComms_C_SetupNewSquadChannel) == 0x000008, "Wrong alignment on BPFL_HDComms_C_SetupNewSquadChannel");
static_assert(sizeof(BPFL_HDComms_C_SetupNewSquadChannel) == 0x000028, "Wrong size on BPFL_HDComms_C_SetupNewSquadChannel");
static_assert(offsetof(BPFL_HDComms_C_SetupNewSquadChannel, CreatedChannel) == 0x000000, "Member 'BPFL_HDComms_C_SetupNewSquadChannel::CreatedChannel' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_SetupNewSquadChannel, SquadToAssociate) == 0x000008, "Member 'BPFL_HDComms_C_SetupNewSquadChannel::SquadToAssociate' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_SetupNewSquadChannel, __WorldContext) == 0x000010, "Member 'BPFL_HDComms_C_SetupNewSquadChannel::__WorldContext' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_SetupNewSquadChannel, K2Node_DynamicCast_AsHDSQComm_Channel_State) == 0x000018, "Member 'BPFL_HDComms_C_SetupNewSquadChannel::K2Node_DynamicCast_AsHDSQComm_Channel_State' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_SetupNewSquadChannel, K2Node_DynamicCast_bSuccess) == 0x000020, "Member 'BPFL_HDComms_C_SetupNewSquadChannel::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function BPFL_HDComms.BPFL_HDComms_C.GetTextChatIconForCommChannel
// 0x0058 (0x0058 - 0x0000)
struct BPFL_HDComms_C_GetTextChatIconForCommChannel final
{
public:
	class UDFCommChannel*                         Channel;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UObject*                                __WorldContext;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             ChannelChatIcon;                                   // 0x0010(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             CommandChannelIcon;                                // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             SquadChannelIcon;                                  // 0x0020(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             TeamChannelIcon;                                   // 0x0028(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             GlobalChannelIcon;                                 // 0x0030(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x3];                                       // 0x0039(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   CallFunc_GetChannelName_ReturnValue;               // 0x003C(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_InstancesChannelWithGroup_ReturnValue;    // 0x0044(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_45[0x3];                                       // 0x0045(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   K2Node_Select_Default;                             // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchName_CmpSuccess;                      // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BPFL_HDComms_C_GetTextChatIconForCommChannel) == 0x000008, "Wrong alignment on BPFL_HDComms_C_GetTextChatIconForCommChannel");
static_assert(sizeof(BPFL_HDComms_C_GetTextChatIconForCommChannel) == 0x000058, "Wrong size on BPFL_HDComms_C_GetTextChatIconForCommChannel");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, Channel) == 0x000000, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::Channel' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, __WorldContext) == 0x000008, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::__WorldContext' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, ChannelChatIcon) == 0x000010, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::ChannelChatIcon' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, CommandChannelIcon) == 0x000018, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::CommandChannelIcon' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, SquadChannelIcon) == 0x000020, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::SquadChannelIcon' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, TeamChannelIcon) == 0x000028, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::TeamChannelIcon' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, GlobalChannelIcon) == 0x000030, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::GlobalChannelIcon' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, Temp_bool_Variable) == 0x000038, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, CallFunc_GetChannelName_ReturnValue) == 0x00003C, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::CallFunc_GetChannelName_ReturnValue' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, CallFunc_InstancesChannelWithGroup_ReturnValue) == 0x000044, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::CallFunc_InstancesChannelWithGroup_ReturnValue' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, K2Node_Select_Default) == 0x000048, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(BPFL_HDComms_C_GetTextChatIconForCommChannel, K2Node_SwitchName_CmpSuccess) == 0x000050, "Member 'BPFL_HDComms_C_GetTextChatIconForCommChannel::K2Node_SwitchName_CmpSuccess' has a wrong offset!");

}

