#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyMarvelGameInstance

#include "Basic.hpp"

#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyMarvelGameInstance.PyMarvelGameInstance
// 0x0058 (0x0540 - 0x04E8)
class UPyMarvelGameInstance : public UMarvelGameInstance
{
public:
	int32                                         LobbyConnectionID;                                 // 0x04E8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_4EC[0x4];                                      // 0x04EC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 PlayerName;                                        // 0x04F0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         ModeID;                                            // 0x0500(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_504[0x4];                                      // 0x0504(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 LoginKey;                                          // 0x0508(0x0010)(BlueprintVisible, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UObject*                                ColorManager;                                      // 0x0518(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnReceiveDemoPlaybackFailure;                      // 0x0520(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnSystemSwitchChanged;                             // 0x0530(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnReceiveDemoPlaybackFailure__DelegateSignature(const class FString& Error);
	void OnSystemSwitchChanged__DelegateSignature(int32 Switch_Key, bool Is_enabled);
	int32 GetClientPort();
	void ReceiveInit();
	void UpdateReplayEnv();
	void OnHandShakeMsg(const class FString& SMsg);
	void OnUELoginMsg(const class FString& SMsg);
	void OnUEConnectionTimeOut(const int32 State, const class FString& Msg);
	void CallEngineQuit(const class FString& SReason);
	void ReceiveOnStart();
	void OnFrameEnd(float FrameTime);
	void FakeTick();
	void ReceiveOnLoadComplete(const float LoadTime, const class FString& MapName);
	void ReceiveShutdown();
	void ReceiveDemoPlaybackFailure(const class FString& Error);
	void ReceiveSwitchEnvFailure(const class FString& Error);
	void OnDDosChecked(const class FString& Error);
	void ReceiveNetworkReplayVersion(const class FString& Error);
	class FString WriteReplayLoadingInfo();
	void ProcessReplayLoadingInfo(const class FString& SpecificData, class FString* Error);
	void UploadDrpfData(const class FString& DrpfType, const class FString& DrpfData);
	void ReqServerBuildSettings();
	void ReceiveOnAfterForkInChild();
	void OnPostGC();
	void OnPreGarbageCollect();
	bool PyIsSystemSwitchOpenedByID(int32 RowID);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyMarvelGameInstance">();
	}
	static class UPyMarvelGameInstance* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyMarvelGameInstance>();
	}
};
static_assert(alignof(UPyMarvelGameInstance) == 0x000008, "Wrong alignment on UPyMarvelGameInstance");
static_assert(sizeof(UPyMarvelGameInstance) == 0x000540, "Wrong size on UPyMarvelGameInstance");
static_assert(offsetof(UPyMarvelGameInstance, LobbyConnectionID) == 0x0004E8, "Member 'UPyMarvelGameInstance::LobbyConnectionID' has a wrong offset!");
static_assert(offsetof(UPyMarvelGameInstance, PlayerName) == 0x0004F0, "Member 'UPyMarvelGameInstance::PlayerName' has a wrong offset!");
static_assert(offsetof(UPyMarvelGameInstance, ModeID) == 0x000500, "Member 'UPyMarvelGameInstance::ModeID' has a wrong offset!");
static_assert(offsetof(UPyMarvelGameInstance, LoginKey) == 0x000508, "Member 'UPyMarvelGameInstance::LoginKey' has a wrong offset!");
static_assert(offsetof(UPyMarvelGameInstance, ColorManager) == 0x000518, "Member 'UPyMarvelGameInstance::ColorManager' has a wrong offset!");
static_assert(offsetof(UPyMarvelGameInstance, OnReceiveDemoPlaybackFailure) == 0x000520, "Member 'UPyMarvelGameInstance::OnReceiveDemoPlaybackFailure' has a wrong offset!");
static_assert(offsetof(UPyMarvelGameInstance, OnSystemSwitchChanged) == 0x000530, "Member 'UPyMarvelGameInstance::OnSystemSwitchChanged' has a wrong offset!");

}

