#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: RobberGI

#include "Basic.hpp"

#include "SteamCore_structs.hpp"
#include "Engine_structs.hpp"
#include "OnlineSubsystemUtils_structs.hpp"
#include "AdvancedSessions_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass RobberGI.RobberGI_C
// 0x0080 (0x02A8 - 0x0228)
class URobberGI_C final : public UAdvancedFriendsGameInstance
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0228(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	int32                                         ConnectedPlayers;                                  // 0x0230(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_234[0x4];                                      // 0x0234(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 LobbyType;                                         // 0x0238(0x0010)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	class FString                                 Map;                                               // 0x0248(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	struct FSteamID                               Steam_IDLobby;                                     // 0x0258(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	FMulticastInlineDelegateProperty_             SessionUpdated;                                    // 0x0260(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             PublicSessionFound;                                // 0x0270(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	TArray<struct FBlueprintSessionResult>        Results;                                           // 0x0280(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FString                                 AlteredSave;                                       // 0x0290(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	class UClass*                                 SelectedMap;                                       // 0x02A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void SessionUpdated__DelegateSignature();
	void PublicSessionFound__DelegateSignature(const struct FBlueprintSessionResult& Session, bool FoundSession_);
	void ExecuteUbergraph_RobberGI(int32 EntryPoint);
	void SetSessionSearching(bool Searching_);
	void RetryFindSessions();
	void FindRandomPublicSession();
	void CreateSteamLobby(ESteamLobbyType LobbyType_0);
	void ReceiveShutdown();
	void HandleNetworkError(ENetworkFailure FailureType, bool bIsServer);
	void MessagePopup(const class FString& Message);
	void UpdateMap(class UClass* Map_0);
	void UpdateLobbyManager();
	void UpdateSession(bool AllowJoinInProgress_);
	void Invited(const struct FLobbyInviteData& Data);
	void ReceiveInit();
	void OnSessionInviteAccepted(int32 LocalPlayerNum, const struct FBPUniqueNetId& PersonInvited, const struct FBlueprintSessionResult& SessionToJoin);
	void JoinGame(const struct FBlueprintSessionResult& Result);
	void HostGame(class FName Map_0);
	void NewChat();
	void OnSuccess_A110421C4837192EE5791EA86298FC0A(const TArray<struct FBlueprintSessionResult>& Results_0);
	void OnFailure_A110421C4837192EE5791EA86298FC0A(const TArray<struct FBlueprintSessionResult>& Results_0);
	void OnSuccess_BC37CD5D4644656903F524BAD936F3B4();
	void OnFailure_BC37CD5D4644656903F524BAD936F3B4();
	void OnSuccess_7BBB03BC4A1765E9DE1E50A77D6BA9CF();
	void OnFailure_7BBB03BC4A1765E9DE1E50A77D6BA9CF();
	void OnCallback_D0E7F30247E9855852002CA389609FEF(const struct FCreateLobbyData& Data, bool bWasSuccessful);
	void OnSuccess_3712E50F4916203E9846888DFCC067FA();
	void OnFailure_3712E50F4916203E9846888DFCC067FA();
	void OnSuccess_84F741E54A2E82BA08D936B9D6DBA183();
	void OnFailure_84F741E54A2E82BA08D936B9D6DBA183();
	void OnSuccess_1FA9A5214F6702DEF08981BF01CD27D6();
	void OnFailure_1FA9A5214F6702DEF08981BF01CD27D6();
	void OnSuccess_40CC732343607C4A3B0198893B9834D6(const TArray<struct FBPFriendInfo>& Results_0);
	void OnFailure_40CC732343607C4A3B0198893B9834D6(const TArray<struct FBPFriendInfo>& Results_0);
	void OnSuccess_78FA565041BAAB35AADC149A01C49716();
	void OnFailure_78FA565041BAAB35AADC149A01C49716();
	void OnSuccess_B0A4F92B40F1E53E052C46B57FB3CE1A();
	void OnFailure_B0A4F92B40F1E53E052C46B57FB3CE1A();
	void OnSuccess_E2CCFF9E4B22F409F39555A57235A5C4();
	void OnFailure_E2CCFF9E4B22F409F39555A57235A5C4();
	void SwitchLobbyType();
	void SetLobbyType(const class FString& Lobby_type, bool AllowJoin_);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"RobberGI_C">();
	}
	static class URobberGI_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<URobberGI_C>();
	}
};
static_assert(alignof(URobberGI_C) == 0x000008, "Wrong alignment on URobberGI_C");
static_assert(sizeof(URobberGI_C) == 0x0002A8, "Wrong size on URobberGI_C");
static_assert(offsetof(URobberGI_C, UberGraphFrame) == 0x000228, "Member 'URobberGI_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(URobberGI_C, ConnectedPlayers) == 0x000230, "Member 'URobberGI_C::ConnectedPlayers' has a wrong offset!");
static_assert(offsetof(URobberGI_C, LobbyType) == 0x000238, "Member 'URobberGI_C::LobbyType' has a wrong offset!");
static_assert(offsetof(URobberGI_C, Map) == 0x000248, "Member 'URobberGI_C::Map' has a wrong offset!");
static_assert(offsetof(URobberGI_C, Steam_IDLobby) == 0x000258, "Member 'URobberGI_C::Steam_IDLobby' has a wrong offset!");
static_assert(offsetof(URobberGI_C, SessionUpdated) == 0x000260, "Member 'URobberGI_C::SessionUpdated' has a wrong offset!");
static_assert(offsetof(URobberGI_C, PublicSessionFound) == 0x000270, "Member 'URobberGI_C::PublicSessionFound' has a wrong offset!");
static_assert(offsetof(URobberGI_C, Results) == 0x000280, "Member 'URobberGI_C::Results' has a wrong offset!");
static_assert(offsetof(URobberGI_C, AlteredSave) == 0x000290, "Member 'URobberGI_C::AlteredSave' has a wrong offset!");
static_assert(offsetof(URobberGI_C, SelectedMap) == 0x0002A0, "Member 'URobberGI_C::SelectedMap' has a wrong offset!");

}

