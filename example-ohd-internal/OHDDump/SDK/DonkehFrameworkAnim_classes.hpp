#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DonkehFrameworkAnim

#include "Basic.hpp"

#include "DonkehFramework_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "DonkehFrameworkAnim_structs.hpp"


namespace SDK
{

// Class DonkehFrameworkAnim.AnimNotify_PlayFootstepFX
// 0x0118 (0x0150 - 0x0038)
class alignas(0x10) UAnimNotify_PlayFootstepFX final : public UAnimNotify
{
public:
	TMap<EPhysicalSurface, struct FPerspectiveSound> SoundsToPlay;                                      // 0x0038(0x0050)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	float                                         VolumeMultiplier;                                  // 0x0088(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PitchMultiplier;                                   // 0x008C(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         bAttachSound : 1;                                  // 0x0090(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         bPlaySoundsWithPerspMeshOnly : 1;                  // 0x0090(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_91[0x7];                                       // 0x0091(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<EPhysicalSurface, class UFXSystemAsset*> EffectsToSpawn;                                    // 0x0098(0x0050)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	uint8                                         bAttachEffect : 1;                                 // 0x00E8(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_E9[0x3];                                       // 0x00E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                EffectLocationOffset;                              // 0x00EC(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FRotator                               EffectRotationOffset;                              // 0x00F8(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_104[0x1C];                                     // 0x0104(0x001C)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                EffectScale;                                       // 0x0120(0x000C)(Edit, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         bSpawnEffectsWithPerspMeshOnly : 1;                // 0x012C(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	EFootstepVariant                              FootstepVariant;                                   // 0x012D(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_12E[0x2];                                      // 0x012E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   FootstepVariantParamName;                          // 0x0130(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   FootBoneName;                                      // 0x0138(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         FootTraceOffset;                                   // 0x0140(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         bDebug : 1;                                        // 0x0144(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic))
	uint8                                         Pad_145[0xB];                                      // 0x0145(0x000B)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	static bool EqualProps(const struct FFootstepFXSettings& Props, const struct FFootstepFXSettings& OtherProps);

	struct FFootstepFXSettings GetFootstepNotifyProps() const;
	void SetFootstepNotifyProps(const struct FFootstepFXSettings& PropsToUse) const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"AnimNotify_PlayFootstepFX">();
	}
	static class UAnimNotify_PlayFootstepFX* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAnimNotify_PlayFootstepFX>();
	}
};
static_assert(alignof(UAnimNotify_PlayFootstepFX) == 0x000010, "Wrong alignment on UAnimNotify_PlayFootstepFX");
static_assert(sizeof(UAnimNotify_PlayFootstepFX) == 0x000150, "Wrong size on UAnimNotify_PlayFootstepFX");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, SoundsToPlay) == 0x000038, "Member 'UAnimNotify_PlayFootstepFX::SoundsToPlay' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, VolumeMultiplier) == 0x000088, "Member 'UAnimNotify_PlayFootstepFX::VolumeMultiplier' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, PitchMultiplier) == 0x00008C, "Member 'UAnimNotify_PlayFootstepFX::PitchMultiplier' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, EffectsToSpawn) == 0x000098, "Member 'UAnimNotify_PlayFootstepFX::EffectsToSpawn' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, EffectLocationOffset) == 0x0000EC, "Member 'UAnimNotify_PlayFootstepFX::EffectLocationOffset' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, EffectRotationOffset) == 0x0000F8, "Member 'UAnimNotify_PlayFootstepFX::EffectRotationOffset' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, EffectScale) == 0x000120, "Member 'UAnimNotify_PlayFootstepFX::EffectScale' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, FootstepVariant) == 0x00012D, "Member 'UAnimNotify_PlayFootstepFX::FootstepVariant' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, FootstepVariantParamName) == 0x000130, "Member 'UAnimNotify_PlayFootstepFX::FootstepVariantParamName' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, FootBoneName) == 0x000138, "Member 'UAnimNotify_PlayFootstepFX::FootBoneName' has a wrong offset!");
static_assert(offsetof(UAnimNotify_PlayFootstepFX, FootTraceOffset) == 0x000140, "Member 'UAnimNotify_PlayFootstepFX::FootTraceOffset' has a wrong offset!");

// Class DonkehFrameworkAnim.DFCharacterAnimInstance
// 0x0050 (0x02C0 - 0x0270)
#pragma pack(push, 0x1)
class alignas(0x10) UDFCharacterAnimInstance : public UAnimInstance
{
public:
	uint8                                         bPreviewAnimInstance : 1;                          // 0x0268(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnTemplate, Transient, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate))
	uint8                                         Pad_269[0x7];                                      // 0x0269(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APawn*                                  CachedPawnOwner;                                   // 0x0270(0x0008)(ZeroConstructor, Transient, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class ADFBaseCharacter*                       DFCharOwner;                                       // 0x0278(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class AController*                            ControllerOwner;                                   // 0x0280(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	class ADFBaseItem*                            EquippedWeapon;                                    // 0x0288(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)
	EMovementMode                                 MoveMode;                                          // 0x0290(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	ECharacterStance                              MoveStance;                                        // 0x0291(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         Pad_292[0x2];                                      // 0x0292(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                MoveVelocity;                                      // 0x0294(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         MoveSpeed;                                         // 0x02A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	float                                         MoveDirectionDeg;                                  // 0x02A4(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected)
	uint8                                         bMoving : 1;                                       // 0x02A8(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected))
	uint8                                         bInAir : 1;                                        // 0x02A8(0x0001)(BitIndex: 0x01, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected))
	uint8                                         bJumped : 1;                                       // 0x02A8(0x0001)(BitIndex: 0x02, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected))
	uint8                                         bSprinting : 1;                                    // 0x02A8(0x0001)(BitIndex: 0x03, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected))
	uint8                                         bAiming : 1;                                       // 0x02A8(0x0001)(BitIndex: 0x04, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected))
	uint8                                         bLeaning : 1;                                      // 0x02A8(0x0001)(BitIndex: 0x05, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, HasGetValueTypeHash, NativeAccessSpecifierProtected))
	struct FDFCharStanceContext                   StandState;                                        // 0x02A9(0x0001)(Edit, BlueprintVisible, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, NativeAccessSpecifierProtected)
	struct FDFCharStanceContext                   CrouchState;                                       // 0x02AA(0x0001)(Edit, BlueprintVisible, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, NativeAccessSpecifierProtected)
	struct FDFCharStanceContext                   ProneState;                                        // 0x02AB(0x0001)(Edit, BlueprintVisible, DisableEditOnTemplate, Transient, EditConst, NoDestructor, Protected, NativeAccessSpecifierProtected)
	struct FRotator                               AimOffsets;                                        // 0x02AC(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, Protected, NativeAccessSpecifierProtected)

public:
	void BlueprintUpdateControllerOwnerRefs(class AController* NewC);
	void BlueprintUpdateEquippedWeaponRefs(class ADFBaseItem* NewWeap);
	void BlueprintUpdatePawnOwnerRefs(class APawn* NewPawn);
	void EquippedWeaponChanged(class ADFBaseCharacter* Character, class ADFBaseItem* NewEquippedWeap, class ADFBaseItem* PrevEquippedWeap);

	class AController* TryGetControllerOwner() const;
	class ADFBaseItem* TryGetOwnerWeapon() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"DFCharacterAnimInstance">();
	}
	static class UDFCharacterAnimInstance* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDFCharacterAnimInstance>();
	}
};
#pragma pack(pop)
static_assert(alignof(UDFCharacterAnimInstance) == 0x000010, "Wrong alignment on UDFCharacterAnimInstance");
static_assert(sizeof(UDFCharacterAnimInstance) == 0x0002C0, "Wrong size on UDFCharacterAnimInstance");
static_assert(offsetof(UDFCharacterAnimInstance, CachedPawnOwner) == 0x000270, "Member 'UDFCharacterAnimInstance::CachedPawnOwner' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, DFCharOwner) == 0x000278, "Member 'UDFCharacterAnimInstance::DFCharOwner' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, ControllerOwner) == 0x000280, "Member 'UDFCharacterAnimInstance::ControllerOwner' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, EquippedWeapon) == 0x000288, "Member 'UDFCharacterAnimInstance::EquippedWeapon' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, MoveMode) == 0x000290, "Member 'UDFCharacterAnimInstance::MoveMode' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, MoveStance) == 0x000291, "Member 'UDFCharacterAnimInstance::MoveStance' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, MoveVelocity) == 0x000294, "Member 'UDFCharacterAnimInstance::MoveVelocity' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, MoveSpeed) == 0x0002A0, "Member 'UDFCharacterAnimInstance::MoveSpeed' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, MoveDirectionDeg) == 0x0002A4, "Member 'UDFCharacterAnimInstance::MoveDirectionDeg' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, StandState) == 0x0002A9, "Member 'UDFCharacterAnimInstance::StandState' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, CrouchState) == 0x0002AA, "Member 'UDFCharacterAnimInstance::CrouchState' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, ProneState) == 0x0002AB, "Member 'UDFCharacterAnimInstance::ProneState' has a wrong offset!");
static_assert(offsetof(UDFCharacterAnimInstance, AimOffsets) == 0x0002AC, "Member 'UDFCharacterAnimInstance::AimOffsets' has a wrong offset!");

// Class DonkehFrameworkAnim.DFWeaponAnimInstance
// 0x0010 (0x0280 - 0x0270)
#pragma pack(push, 0x1)
class alignas(0x10) UDFWeaponAnimInstance : public UAnimInstance
{
public:
	uint8                                         bPreviewAnimInstance : 1;                          // 0x0268(0x0001)(BitIndex: 0x00, PropSize: 0x0001 (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnTemplate, Transient, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate))
	uint8                                         Pad_269[0x7];                                      // 0x0269(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ADFBaseWeapon*                          WeaponOwner;                                       // 0x0270(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, EditConst, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPrivate)

public:
	void BlueprintUpdateWeaponOwnerRefs(class ADFBaseWeapon* NewWeap);

	class ADFBaseWeapon* TryGetWeaponOwner() const;

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"DFWeaponAnimInstance">();
	}
	static class UDFWeaponAnimInstance* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDFWeaponAnimInstance>();
	}
};
#pragma pack(pop)
static_assert(alignof(UDFWeaponAnimInstance) == 0x000010, "Wrong alignment on UDFWeaponAnimInstance");
static_assert(sizeof(UDFWeaponAnimInstance) == 0x000280, "Wrong size on UDFWeaponAnimInstance");
static_assert(offsetof(UDFWeaponAnimInstance, WeaponOwner) == 0x000270, "Member 'UDFWeaponAnimInstance::WeaponOwner' has a wrong offset!");

}

