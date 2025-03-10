#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Hero_1052

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"
#include "GameplayAbilities_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// Class Hero_1052.Ability_105221
// 0x0010 (0x2590 - 0x2580)
class UAbility_105221 : public UMarvelGameplayAbility
{
public:
	bool                                          bIsFloating;                                       // 0x2580(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_2581[0xF];                                     // 0x2581(0x000F)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void EndFloating();
	void OnMoveForwardReceive(float ScaleValue);
	void OnMoveRightReceive(float ScaleValue);
	void StartFloating();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"Ability_105221">();
	}
	static class UAbility_105221* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAbility_105221>();
	}
};
static_assert(alignof(UAbility_105221) == 0x000008, "Wrong alignment on UAbility_105221");
static_assert(sizeof(UAbility_105221) == 0x002590, "Wrong size on UAbility_105221");
static_assert(offsetof(UAbility_105221, bIsFloating) == 0x002580, "Member 'UAbility_105221::bIsFloating' has a wrong offset!");

// Class Hero_1052.Config_105211
// 0x0008 (0x00C8 - 0x00C0)
class UConfig_105211 final : public UMarvelAbilityConfig_DoubleJump
{
public:
	bool                                          bEnterCD;                                          // 0x00C0(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bRecoverEnergy;                                    // 0x00C1(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_C2[0x6];                                       // 0x00C2(0x0006)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"Config_105211">();
	}
	static class UConfig_105211* GetDefaultObj()
	{
		return GetDefaultObjImpl<UConfig_105211>();
	}
};
static_assert(alignof(UConfig_105211) == 0x000008, "Wrong alignment on UConfig_105211");
static_assert(sizeof(UConfig_105211) == 0x0000C8, "Wrong size on UConfig_105211");
static_assert(offsetof(UConfig_105211, bEnterCD) == 0x0000C0, "Member 'UConfig_105211::bEnterCD' has a wrong offset!");
static_assert(offsetof(UConfig_105211, bRecoverEnergy) == 0x0000C1, "Member 'UConfig_105211::bRecoverEnergy' has a wrong offset!");

// Class Hero_1052.Ability_105231
// 0x0010 (0x2590 - 0x2580)
class UAbility_105231 : public UMarvelGameplayAbility
{
public:
	uint8                                         Pad_2580[0x8];                                     // 0x2580(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	class AMarvelBaseCharacter*                   InstigatorCharacter;                               // 0x2588(0x0008)(ZeroConstructor, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)

public:
	void OnBlockedSucceed(float BlockValue);

	void K2_OnImmunityBlockGameplayEffect(float Magnitude) const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"Ability_105231">();
	}
	static class UAbility_105231* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAbility_105231>();
	}
};
static_assert(alignof(UAbility_105231) == 0x000008, "Wrong alignment on UAbility_105231");
static_assert(sizeof(UAbility_105231) == 0x002590, "Wrong size on UAbility_105231");
static_assert(offsetof(UAbility_105231, InstigatorCharacter) == 0x002588, "Member 'UAbility_105231::InstigatorCharacter' has a wrong offset!");

// Class Hero_1052.NotTreatShield_105241
// 0x0068 (0x1160 - 0x10F8)
class UNotTreatShield_105241 final : public UMarvelEffectGameplayAbility
{
public:
	float                                         AdditionSpeed;                                     // 0x10F8(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Interval;                                          // 0x10FC(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MaxAttribute;                                      // 0x1100(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1104[0x4];                                     // 0x1104(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayAttribute                     Attribute;                                         // 0x1108(0x0040)(Edit, BlueprintVisible, BlueprintReadOnly, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FTimerHandle                           UpdateTimerHandle;                                 // 0x1148(0x0018)(Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)

public:
	void AddAttributeValue();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"NotTreatShield_105241">();
	}
	static class UNotTreatShield_105241* GetDefaultObj()
	{
		return GetDefaultObjImpl<UNotTreatShield_105241>();
	}
};
static_assert(alignof(UNotTreatShield_105241) == 0x000008, "Wrong alignment on UNotTreatShield_105241");
static_assert(sizeof(UNotTreatShield_105241) == 0x001160, "Wrong size on UNotTreatShield_105241");
static_assert(offsetof(UNotTreatShield_105241, AdditionSpeed) == 0x0010F8, "Member 'UNotTreatShield_105241::AdditionSpeed' has a wrong offset!");
static_assert(offsetof(UNotTreatShield_105241, Interval) == 0x0010FC, "Member 'UNotTreatShield_105241::Interval' has a wrong offset!");
static_assert(offsetof(UNotTreatShield_105241, MaxAttribute) == 0x001100, "Member 'UNotTreatShield_105241::MaxAttribute' has a wrong offset!");
static_assert(offsetof(UNotTreatShield_105241, Attribute) == 0x001108, "Member 'UNotTreatShield_105241::Attribute' has a wrong offset!");
static_assert(offsetof(UNotTreatShield_105241, UpdateTimerHandle) == 0x001148, "Member 'UNotTreatShield_105241::UpdateTimerHandle' has a wrong offset!");

// Class Hero_1052.Ability_105232
// 0x00A8 (0x2628 - 0x2580)
class UAbility_105232 : public UMarvelGameplayAbility
{
public:
	struct FPredictionKey                         PlayTimelineKey;                                   // 0x2580(0x00A0)(HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class UMarvelAbilityTask_PlayMontageAndWaitForEvent* PlayTimelineTask;                                  // 0x2620(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)

public:
	void CallServerPlayTimeline(int32 TimelineIndex, const struct FHitResult& InHitResult, bool BlockDash, const struct FVector& ClientTargetLocation);
	void K2_OnPlayTimeline(int32 TimelineIndex, const struct FHitResult& InHitResult, bool BlockDash, const struct FVector& ClientTargetLocation);
	void OnServerReceivePlayTimeline(int32 TimelineIndex, const struct FHitResult& InHitResult, bool BlockDash, const struct FVector& ClientTargetLocation);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"Ability_105232">();
	}
	static class UAbility_105232* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAbility_105232>();
	}
};
static_assert(alignof(UAbility_105232) == 0x000008, "Wrong alignment on UAbility_105232");
static_assert(sizeof(UAbility_105232) == 0x002628, "Wrong size on UAbility_105232");
static_assert(offsetof(UAbility_105232, PlayTimelineKey) == 0x002580, "Member 'UAbility_105232::PlayTimelineKey' has a wrong offset!");
static_assert(offsetof(UAbility_105232, PlayTimelineTask) == 0x002620, "Member 'UAbility_105232::PlayTimelineTask' has a wrong offset!");

// Class Hero_1052.LinLieAnimInstance
// 0x0070 (0x0980 - 0x0910)
class ULinLieAnimInstance final : public UMarvelAnimInstance
{
public:
	bool                                          bIsOnTheWall;                                      // 0x0910(0x0001)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          bIsRunLeft;                                        // 0x0911(0x0001)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          bShouldUseAO;                                      // 0x0912(0x0001)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_913[0x5];                                      // 0x0913(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                StartVelocity;                                     // 0x0918(0x0018)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          IsDoubleJumpingFlag;                               // 0x0930(0x0001)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	bool                                          IsJumpIndexChange;                                 // 0x0931(0x0001)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_932[0x2];                                      // 0x0932(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         JumpIndex;                                         // 0x0934(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_938[0x48];                                     // 0x0938(0x0048)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"LinLieAnimInstance">();
	}
	static class ULinLieAnimInstance* GetDefaultObj()
	{
		return GetDefaultObjImpl<ULinLieAnimInstance>();
	}
};
static_assert(alignof(ULinLieAnimInstance) == 0x000010, "Wrong alignment on ULinLieAnimInstance");
static_assert(sizeof(ULinLieAnimInstance) == 0x000980, "Wrong size on ULinLieAnimInstance");
static_assert(offsetof(ULinLieAnimInstance, bIsOnTheWall) == 0x000910, "Member 'ULinLieAnimInstance::bIsOnTheWall' has a wrong offset!");
static_assert(offsetof(ULinLieAnimInstance, bIsRunLeft) == 0x000911, "Member 'ULinLieAnimInstance::bIsRunLeft' has a wrong offset!");
static_assert(offsetof(ULinLieAnimInstance, bShouldUseAO) == 0x000912, "Member 'ULinLieAnimInstance::bShouldUseAO' has a wrong offset!");
static_assert(offsetof(ULinLieAnimInstance, StartVelocity) == 0x000918, "Member 'ULinLieAnimInstance::StartVelocity' has a wrong offset!");
static_assert(offsetof(ULinLieAnimInstance, IsDoubleJumpingFlag) == 0x000930, "Member 'ULinLieAnimInstance::IsDoubleJumpingFlag' has a wrong offset!");
static_assert(offsetof(ULinLieAnimInstance, IsJumpIndexChange) == 0x000931, "Member 'ULinLieAnimInstance::IsJumpIndexChange' has a wrong offset!");
static_assert(offsetof(ULinLieAnimInstance, JumpIndex) == 0x000934, "Member 'ULinLieAnimInstance::JumpIndex' has a wrong offset!");

// Class Hero_1052.LinLieCharacter
// 0x0050 (0x1860 - 0x1810)
class ALinLieCharacter : public AMarvelBaseCharacter
{
public:
	bool                                          bIsRunLeft;                                        // 0x1810(0x0001)(BlueprintVisible, Net, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1811[0x7];                                     // 0x1811(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnJumpIndexUpdatedDelegate;                        // 0x1818(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, NativeAccessSpecifierPublic)
	int32                                         JumpIndex;                                         // 0x1828(0x0004)(BlueprintVisible, Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_182C[0x4];                                     // 0x182C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class ULinLieMoveLogicBaseComponent*          LinLieMoveLogic;                                   // 0x1830(0x0008)(Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_1838[0x28];                                    // 0x1838(0x0028)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	int32 GetShareComboState();
	void ResetShareComboState();
	void SetJumpIndex(int32 NewIndex);
	void SetRunLeft(bool NewState);
	void SetShareComboState(int32 NewState, int32 ComboSectionNum, float ComboTimeout);

	void OnRep_JumpIndex() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"LinLieCharacter">();
	}
	static class ALinLieCharacter* GetDefaultObj()
	{
		return GetDefaultObjImpl<ALinLieCharacter>();
	}
};
static_assert(alignof(ALinLieCharacter) == 0x000010, "Wrong alignment on ALinLieCharacter");
static_assert(sizeof(ALinLieCharacter) == 0x001860, "Wrong size on ALinLieCharacter");
static_assert(offsetof(ALinLieCharacter, bIsRunLeft) == 0x001810, "Member 'ALinLieCharacter::bIsRunLeft' has a wrong offset!");
static_assert(offsetof(ALinLieCharacter, OnJumpIndexUpdatedDelegate) == 0x001818, "Member 'ALinLieCharacter::OnJumpIndexUpdatedDelegate' has a wrong offset!");
static_assert(offsetof(ALinLieCharacter, JumpIndex) == 0x001828, "Member 'ALinLieCharacter::JumpIndex' has a wrong offset!");
static_assert(offsetof(ALinLieCharacter, LinLieMoveLogic) == 0x001830, "Member 'ALinLieCharacter::LinLieMoveLogic' has a wrong offset!");

// Class Hero_1052.LinLieMoveLogicBaseComponent
// 0x0000 (0x03F0 - 0x03F0)
class ULinLieMoveLogicBaseComponent final : public UMarvelMoveLogicBaseComponent
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"LinLieMoveLogicBaseComponent">();
	}
	static class ULinLieMoveLogicBaseComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<ULinLieMoveLogicBaseComponent>();
	}
};
static_assert(alignof(ULinLieMoveLogicBaseComponent) == 0x000008, "Wrong alignment on ULinLieMoveLogicBaseComponent");
static_assert(sizeof(ULinLieMoveLogicBaseComponent) == 0x0003F0, "Wrong size on ULinLieMoveLogicBaseComponent");

// Class Hero_1052.LinLieMovementComponent
// 0x0FC0 (0x3F90 - 0x2FD0)
class ULinLieMovementComponent final : public UCharacterWallRunningComponent
{
public:
	float                                         MaxGroundSlop;                                     // 0x2FD0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bTraceDestructible;                                // 0x2FD4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bTraceSceneCommoned;                               // 0x2FD5(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bTraceAirWall;                                     // 0x2FD6(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_2FD7[0x1];                                     // 0x2FD7(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         MinWallHeight;                                     // 0x2FD8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         WallZSpeed;                                        // 0x2FDC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FMarvelAbilityTraceContext             EffectiveTraceContext;                             // 0x2FE0(0x0F90)(Edit, BlueprintVisible, ContainsInstancedReference, NativeAccessSpecifierPublic)
	class ALinLieCharacter*                       LinLieCharacter;                                   // 0x3F70(0x0008)(ZeroConstructor, Transient, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_3F78[0x18];                                    // 0x3F78(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"LinLieMovementComponent">();
	}
	static class ULinLieMovementComponent* GetDefaultObj()
	{
		return GetDefaultObjImpl<ULinLieMovementComponent>();
	}
};
static_assert(alignof(ULinLieMovementComponent) == 0x000010, "Wrong alignment on ULinLieMovementComponent");
static_assert(sizeof(ULinLieMovementComponent) == 0x003F90, "Wrong size on ULinLieMovementComponent");
static_assert(offsetof(ULinLieMovementComponent, MaxGroundSlop) == 0x002FD0, "Member 'ULinLieMovementComponent::MaxGroundSlop' has a wrong offset!");
static_assert(offsetof(ULinLieMovementComponent, bTraceDestructible) == 0x002FD4, "Member 'ULinLieMovementComponent::bTraceDestructible' has a wrong offset!");
static_assert(offsetof(ULinLieMovementComponent, bTraceSceneCommoned) == 0x002FD5, "Member 'ULinLieMovementComponent::bTraceSceneCommoned' has a wrong offset!");
static_assert(offsetof(ULinLieMovementComponent, bTraceAirWall) == 0x002FD6, "Member 'ULinLieMovementComponent::bTraceAirWall' has a wrong offset!");
static_assert(offsetof(ULinLieMovementComponent, MinWallHeight) == 0x002FD8, "Member 'ULinLieMovementComponent::MinWallHeight' has a wrong offset!");
static_assert(offsetof(ULinLieMovementComponent, WallZSpeed) == 0x002FDC, "Member 'ULinLieMovementComponent::WallZSpeed' has a wrong offset!");
static_assert(offsetof(ULinLieMovementComponent, EffectiveTraceContext) == 0x002FE0, "Member 'ULinLieMovementComponent::EffectiveTraceContext' has a wrong offset!");
static_assert(offsetof(ULinLieMovementComponent, LinLieCharacter) == 0x003F70, "Member 'ULinLieMovementComponent::LinLieCharacter' has a wrong offset!");

}

