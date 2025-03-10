#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: RestrictedAreaVolume

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass RestrictedAreaVolume.RestrictedAreaVolume_C
// 0x0020 (0x0240 - 0x0220)
class ARestrictedAreaVolume_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UBoxComponent*                          Box;                                               // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	bool                                          ArrestWarning_;                                    // 0x0238(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)

public:
	void ExecuteUbergraph_RestrictedAreaVolume(int32 EntryPoint);
	void ReceiveBeginPlay();
	void ReceiveActorEndOverlap(class AActor* OtherActor);
	void ReceiveActorBeginOverlap(class AActor* OtherActor);
	void IsInSuperRestricted_(class APlayerCharacter_C* Player, bool* Arrest_, bool* In_restricted_);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"RestrictedAreaVolume_C">();
	}
	static class ARestrictedAreaVolume_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ARestrictedAreaVolume_C>();
	}
};
static_assert(alignof(ARestrictedAreaVolume_C) == 0x000008, "Wrong alignment on ARestrictedAreaVolume_C");
static_assert(sizeof(ARestrictedAreaVolume_C) == 0x000240, "Wrong size on ARestrictedAreaVolume_C");
static_assert(offsetof(ARestrictedAreaVolume_C, UberGraphFrame) == 0x000220, "Member 'ARestrictedAreaVolume_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ARestrictedAreaVolume_C, Box) == 0x000228, "Member 'ARestrictedAreaVolume_C::Box' has a wrong offset!");
static_assert(offsetof(ARestrictedAreaVolume_C, DefaultSceneRoot) == 0x000230, "Member 'ARestrictedAreaVolume_C::DefaultSceneRoot' has a wrong offset!");
static_assert(offsetof(ARestrictedAreaVolume_C, ArrestWarning_) == 0x000238, "Member 'ARestrictedAreaVolume_C::ArrestWarning_' has a wrong offset!");

}

