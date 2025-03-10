#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_HitIndicator

#include "Basic.hpp"

#include "Marvel_classes.hpp"
#include "PyMarvelUserWidget_classes.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK
{

// PythonClass PyWidget_HitIndicator.PyWidget_HitSpecialBuff
// 0x0000 (0x0468 - 0x0468)
class UPyWidget_HitSpecialBuff : public UMarvelSimpleUserWidget
{
public:
	void OnAnimationFinished(const class UWidgetAnimation* Animation);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_HitSpecialBuff">();
	}
	static class UPyWidget_HitSpecialBuff* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_HitSpecialBuff>();
	}
};
static_assert(alignof(UPyWidget_HitSpecialBuff) == 0x000008, "Wrong alignment on UPyWidget_HitSpecialBuff");
static_assert(sizeof(UPyWidget_HitSpecialBuff) == 0x000468, "Wrong size on UPyWidget_HitSpecialBuff");

// PythonClass PyWidget_HitIndicator.PyWidget_HitIndicator
// 0x00F0 (0x06E0 - 0x05F0)
class UPyWidget_HitIndicator : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x3];                                      // 0x05E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         TotalDamageBrokenTime;                             // 0x05EC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         TotalDamageTime;                                   // 0x05F0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5F4[0x4];                                      // 0x05F4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<int32, bool>                             LastHitCritical;                                   // 0x05F8(0x0050)(BlueprintVisible, NativeAccessSpecifierPublic)
	struct FGameplayTagContainer                  SpecialBuffTags;                                   // 0x0648(0x0068)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	class UAkAudioEvent*                          AkEvent_OnHeadHit;                                 // 0x06B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UAkAudioEvent*                          AkEvent_OnBodyHit;                                 // 0x06B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UAkAudioEvent*                          AkEvent_OnDamageImmunized;                         // 0x06C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MinRegularHookLengthScale;                         // 0x06C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxRegularHookLengthScale;                         // 0x06CC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MinHeadHookLengthScale;                            // 0x06D0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxHeadHookLengthScale;                            // 0x06D4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MinBrokenHookLengthScale;                          // 0x06D8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxBrokenHookLengthScale;                          // 0x06DC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnDamageImmunized(const struct FGameplayTagContainer& ImmunitySpecTags);
	void OnApplyDamageOnDestruction(class AActor* InSourceAvatar, class AActor* InTargetAvatar, float RealDeltaValue);
	void OnApplyDamageByField(class AActor* InSourceAvatar, class AActor* InTargetAvatar, float RealDeltaValue);
	void ApplyDamageEffect(class AActor* InSourceAvatar, class AActor* InTargetAvatar, const struct FAttributeModifierHandle& ParameterHandle);
	void OnApplyDamage(class AActor* InSourceAvatar, class AActor* InTargetAvatar, const struct FAttributeModifierHandle& ModifierHandle);
	void OnApplyTreat(class AActor* InSourceAvatar, class AActor* InTargetAvatar, const struct FAttributeModifierHandle& ModifierHandle);
	void SetCharacter(class AMarvelBaseCharacter* ViewingCharacter);
	void OnViewingTargetChanged(class AActor* InActor);
	void Destruct();
	void Construct();
	void OnInitialized();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_HitIndicator">();
	}
	static class UPyWidget_HitIndicator* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_HitIndicator>();
	}
};
static_assert(alignof(UPyWidget_HitIndicator) == 0x000008, "Wrong alignment on UPyWidget_HitIndicator");
static_assert(sizeof(UPyWidget_HitIndicator) == 0x0006E0, "Wrong size on UPyWidget_HitIndicator");
static_assert(offsetof(UPyWidget_HitIndicator, TotalDamageBrokenTime) == 0x0005EC, "Member 'UPyWidget_HitIndicator::TotalDamageBrokenTime' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, TotalDamageTime) == 0x0005F0, "Member 'UPyWidget_HitIndicator::TotalDamageTime' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, LastHitCritical) == 0x0005F8, "Member 'UPyWidget_HitIndicator::LastHitCritical' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, SpecialBuffTags) == 0x000648, "Member 'UPyWidget_HitIndicator::SpecialBuffTags' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, AkEvent_OnHeadHit) == 0x0006B0, "Member 'UPyWidget_HitIndicator::AkEvent_OnHeadHit' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, AkEvent_OnBodyHit) == 0x0006B8, "Member 'UPyWidget_HitIndicator::AkEvent_OnBodyHit' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, AkEvent_OnDamageImmunized) == 0x0006C0, "Member 'UPyWidget_HitIndicator::AkEvent_OnDamageImmunized' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, MinRegularHookLengthScale) == 0x0006C8, "Member 'UPyWidget_HitIndicator::MinRegularHookLengthScale' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, MaxRegularHookLengthScale) == 0x0006CC, "Member 'UPyWidget_HitIndicator::MaxRegularHookLengthScale' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, MinHeadHookLengthScale) == 0x0006D0, "Member 'UPyWidget_HitIndicator::MinHeadHookLengthScale' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, MaxHeadHookLengthScale) == 0x0006D4, "Member 'UPyWidget_HitIndicator::MaxHeadHookLengthScale' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, MinBrokenHookLengthScale) == 0x0006D8, "Member 'UPyWidget_HitIndicator::MinBrokenHookLengthScale' has a wrong offset!");
static_assert(offsetof(UPyWidget_HitIndicator, MaxBrokenHookLengthScale) == 0x0006DC, "Member 'UPyWidget_HitIndicator::MaxBrokenHookLengthScale' has a wrong offset!");

// PythonClass PyWidget_HitIndicator.PyWidget_HitFeedBack
// 0x0000 (0x05F0 - 0x05F0)
class UPyWidget_HitFeedBack : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x3];                                      // 0x05E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         HitAnimSpeed;                                      // 0x05EC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInitialized();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_HitFeedBack">();
	}
	static class UPyWidget_HitFeedBack* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_HitFeedBack>();
	}
};
static_assert(alignof(UPyWidget_HitFeedBack) == 0x000008, "Wrong alignment on UPyWidget_HitFeedBack");
static_assert(sizeof(UPyWidget_HitFeedBack) == 0x0005F0, "Wrong size on UPyWidget_HitFeedBack");
static_assert(offsetof(UPyWidget_HitFeedBack, HitAnimSpeed) == 0x0005EC, "Member 'UPyWidget_HitFeedBack::HitAnimSpeed' has a wrong offset!");

// PythonClass PyWidget_HitIndicator.PyWidget_Healing
// 0x0000 (0x05F0 - 0x05F0)
class UPyWidget_Healing : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x3];                                      // 0x05E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         UninterruptibleTime;                               // 0x05EC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnAnimationFinished(const class UWidgetAnimation* Animation);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_Healing">();
	}
	static class UPyWidget_Healing* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_Healing>();
	}
};
static_assert(alignof(UPyWidget_Healing) == 0x000008, "Wrong alignment on UPyWidget_Healing");
static_assert(sizeof(UPyWidget_Healing) == 0x0005F0, "Wrong size on UPyWidget_Healing");
static_assert(offsetof(UPyWidget_Healing, UninterruptibleTime) == 0x0005EC, "Member 'UPyWidget_Healing::UninterruptibleTime' has a wrong offset!");

}

