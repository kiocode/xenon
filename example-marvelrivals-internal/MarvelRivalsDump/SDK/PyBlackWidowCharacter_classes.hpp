#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyBlackWidowCharacter

#include "Basic.hpp"

#include "Hero_1033_classes.hpp"
#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyBlackWidowCharacter.PyBlackWidowCharacter
// 0x0020 (0x1890 - 0x1870)
class APyBlackWidowCharacter : public ABlackWidowCharacter
{
public:
	float                                         ReplicateCapsuleRadiusScale;                       // 0x1870(0x0004)(BlueprintVisible, Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1874[0x4];                                     // 0x1874(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnNeedTryPullBullet;                               // 0x1878(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnNeedTryPullBullet__DelegateSignature();
	void ReceiveBeginPlay();
	void OnRep_ReplicateCapsuleRadiusScale();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyBlackWidowCharacter">();
	}
	static class APyBlackWidowCharacter* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyBlackWidowCharacter>();
	}
};
static_assert(alignof(APyBlackWidowCharacter) == 0x000010, "Wrong alignment on APyBlackWidowCharacter");
static_assert(sizeof(APyBlackWidowCharacter) == 0x001890, "Wrong size on APyBlackWidowCharacter");
static_assert(offsetof(APyBlackWidowCharacter, ReplicateCapsuleRadiusScale) == 0x001870, "Member 'APyBlackWidowCharacter::ReplicateCapsuleRadiusScale' has a wrong offset!");
static_assert(offsetof(APyBlackWidowCharacter, OnNeedTryPullBullet) == 0x001878, "Member 'APyBlackWidowCharacter::OnNeedTryPullBullet' has a wrong offset!");

// PythonClass PyBlackWidowCharacter.PyBlackWidowChildActor
// 0x0000 (0x0A60 - 0x0A60)
class APyBlackWidowChildActor final : public AMarvelCharacterChildActor
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyBlackWidowChildActor">();
	}
	static class APyBlackWidowChildActor* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyBlackWidowChildActor>();
	}
};
static_assert(alignof(APyBlackWidowChildActor) == 0x000008, "Wrong alignment on APyBlackWidowChildActor");
static_assert(sizeof(APyBlackWidowChildActor) == 0x000A60, "Wrong size on APyBlackWidowChildActor");

}

