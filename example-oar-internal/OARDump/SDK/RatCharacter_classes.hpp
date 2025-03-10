#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: RatCharacter

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "AIModule_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass RatCharacter.RatCharacter_C
// 0x0030 (0x04F0 - 0x04C0)
class ARatCharacter_C final : public ACharacter
{
public:
	uint8                                         Pad_4B8[0x8];                                      // 0x04B8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x04C0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UAudioComponent*                        Audio;                                             // 0x04C8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USteamAchievementComponent_C*           SteamAchievementComponent;                         // 0x04D0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UDamageComponent_C*                     DamageComponent;                                   // 0x04D8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	struct FVector                                RatStart;                                          // 0x04E0(0x000C)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Dead_;                                             // 0x04EC(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void OnFail_0484E22F4AB33247A63833A3CC3FE8A3(EPathFollowingResult MovementResult);
	void OnSuccess_0484E22F4AB33247A63833A3CC3FE8A3(EPathFollowingResult MovementResult);
	void ReceiveBeginPlay();
	void RatMove();
	void RatDie();
	void BndEvt__RatCharacter_DamageComponent_K2Node_ComponentBoundEvent_0_Damage__DelegateSignature(int32 Amount, class FName Bone, const struct FVector& HitLocation, const struct FVector& StartLocation, class AActor* Instigator_0);
	void ExecuteUbergraph_RatCharacter(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"RatCharacter_C">();
	}
	static class ARatCharacter_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ARatCharacter_C>();
	}
};
static_assert(alignof(ARatCharacter_C) == 0x000010, "Wrong alignment on ARatCharacter_C");
static_assert(sizeof(ARatCharacter_C) == 0x0004F0, "Wrong size on ARatCharacter_C");
static_assert(offsetof(ARatCharacter_C, UberGraphFrame) == 0x0004C0, "Member 'ARatCharacter_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ARatCharacter_C, Audio) == 0x0004C8, "Member 'ARatCharacter_C::Audio' has a wrong offset!");
static_assert(offsetof(ARatCharacter_C, SteamAchievementComponent) == 0x0004D0, "Member 'ARatCharacter_C::SteamAchievementComponent' has a wrong offset!");
static_assert(offsetof(ARatCharacter_C, DamageComponent) == 0x0004D8, "Member 'ARatCharacter_C::DamageComponent' has a wrong offset!");
static_assert(offsetof(ARatCharacter_C, RatStart) == 0x0004E0, "Member 'ARatCharacter_C::RatStart' has a wrong offset!");
static_assert(offsetof(ARatCharacter_C, Dead_) == 0x0004EC, "Member 'ARatCharacter_C::Dead_' has a wrong offset!");

}

