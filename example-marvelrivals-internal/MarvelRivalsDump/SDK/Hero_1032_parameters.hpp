#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Hero_1032

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "Marvel_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK::Params
{

// Function Hero_1032.Summoned_V2_10325101.GetAbilityConfig
// 0x0008 (0x0008 - 0x0000)
struct Summoned_V2_10325101_GetAbilityConfig final
{
public:
	class UConfig_103251*                         ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(Summoned_V2_10325101_GetAbilityConfig) == 0x000008, "Wrong alignment on Summoned_V2_10325101_GetAbilityConfig");
static_assert(sizeof(Summoned_V2_10325101_GetAbilityConfig) == 0x000008, "Wrong size on Summoned_V2_10325101_GetAbilityConfig");
static_assert(offsetof(Summoned_V2_10325101_GetAbilityConfig, ReturnValue) == 0x000000, "Member 'Summoned_V2_10325101_GetAbilityConfig::ReturnValue' has a wrong offset!");

// Function Hero_1032.Summoned_V2_10325101.IsWallClimbing
// 0x0178 (0x0178 - 0x0000)
struct Summoned_V2_10325101_IsWallClimbing final
{
public:
	struct FHitResult                             Hit;                                               // 0x0000(0x0170)(ConstParm, Parm, OutParm, ReferenceParm, ContainsInstancedReference, NativeAccessSpecifierPublic)
	bool                                          ReturnValue;                                       // 0x0170(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_171[0x7];                                      // 0x0171(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(Summoned_V2_10325101_IsWallClimbing) == 0x000008, "Wrong alignment on Summoned_V2_10325101_IsWallClimbing");
static_assert(sizeof(Summoned_V2_10325101_IsWallClimbing) == 0x000178, "Wrong size on Summoned_V2_10325101_IsWallClimbing");
static_assert(offsetof(Summoned_V2_10325101_IsWallClimbing, Hit) == 0x000000, "Member 'Summoned_V2_10325101_IsWallClimbing::Hit' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_IsWallClimbing, ReturnValue) == 0x000170, "Member 'Summoned_V2_10325101_IsWallClimbing::ReturnValue' has a wrong offset!");

// Function Hero_1032.Summoned_V2_10325101.MovementModeChange
// 0x0010 (0x0010 - 0x0000)
struct Summoned_V2_10325101_MovementModeChange final
{
public:
	class ACharacter*                             Character;                                         // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EMovementMode                                 PrevMovementMode;                                  // 0x0008(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         PreviousCustomMode;                                // 0x0009(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_A[0x6];                                        // 0x000A(0x0006)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(Summoned_V2_10325101_MovementModeChange) == 0x000008, "Wrong alignment on Summoned_V2_10325101_MovementModeChange");
static_assert(sizeof(Summoned_V2_10325101_MovementModeChange) == 0x000010, "Wrong size on Summoned_V2_10325101_MovementModeChange");
static_assert(offsetof(Summoned_V2_10325101_MovementModeChange, Character) == 0x000000, "Member 'Summoned_V2_10325101_MovementModeChange::Character' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_MovementModeChange, PrevMovementMode) == 0x000008, "Member 'Summoned_V2_10325101_MovementModeChange::PrevMovementMode' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_MovementModeChange, PreviousCustomMode) == 0x000009, "Member 'Summoned_V2_10325101_MovementModeChange::PreviousCustomMode' has a wrong offset!");

// Function Hero_1032.Summoned_V2_10325101.OnSquirrelHit
// 0x0198 (0x0198 - 0x0000)
struct Summoned_V2_10325101_OnSquirrelHit final
{
public:
	class AActor*                                 SelfActor;                                         // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 OtherActor;                                        // 0x0008(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector                                NormalImpulse;                                     // 0x0010(0x0018)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FHitResult                             Hit;                                               // 0x0028(0x0170)(ConstParm, Parm, OutParm, ReferenceParm, ContainsInstancedReference, NativeAccessSpecifierPublic)
};
static_assert(alignof(Summoned_V2_10325101_OnSquirrelHit) == 0x000008, "Wrong alignment on Summoned_V2_10325101_OnSquirrelHit");
static_assert(sizeof(Summoned_V2_10325101_OnSquirrelHit) == 0x000198, "Wrong size on Summoned_V2_10325101_OnSquirrelHit");
static_assert(offsetof(Summoned_V2_10325101_OnSquirrelHit, SelfActor) == 0x000000, "Member 'Summoned_V2_10325101_OnSquirrelHit::SelfActor' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_OnSquirrelHit, OtherActor) == 0x000008, "Member 'Summoned_V2_10325101_OnSquirrelHit::OtherActor' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_OnSquirrelHit, NormalImpulse) == 0x000010, "Member 'Summoned_V2_10325101_OnSquirrelHit::NormalImpulse' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_OnSquirrelHit, Hit) == 0x000028, "Member 'Summoned_V2_10325101_OnSquirrelHit::Hit' has a wrong offset!");

// Function Hero_1032.Summoned_V2_10325101.OnSummonedKillOther
// 0x0028 (0x0028 - 0x0000)
struct Summoned_V2_10325101_OnSummonedKillOther final
{
public:
	class AActor*                                 InSourceAvatar;                                    // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 InTargetAvatar;                                    // 0x0008(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FAttributeModifierHandle               ModifierParameterHandle;                           // 0x0010(0x0018)(ConstParm, Parm, OutParm, ReferenceParm, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(Summoned_V2_10325101_OnSummonedKillOther) == 0x000008, "Wrong alignment on Summoned_V2_10325101_OnSummonedKillOther");
static_assert(sizeof(Summoned_V2_10325101_OnSummonedKillOther) == 0x000028, "Wrong size on Summoned_V2_10325101_OnSummonedKillOther");
static_assert(offsetof(Summoned_V2_10325101_OnSummonedKillOther, InSourceAvatar) == 0x000000, "Member 'Summoned_V2_10325101_OnSummonedKillOther::InSourceAvatar' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_OnSummonedKillOther, InTargetAvatar) == 0x000008, "Member 'Summoned_V2_10325101_OnSummonedKillOther::InTargetAvatar' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_OnSummonedKillOther, ModifierParameterHandle) == 0x000010, "Member 'Summoned_V2_10325101_OnSummonedKillOther::ModifierParameterHandle' has a wrong offset!");

// Function Hero_1032.Summoned_V2_10325101.SquirrelClimbingWall
// 0x0170 (0x0170 - 0x0000)
struct Summoned_V2_10325101_SquirrelClimbingWall final
{
public:
	struct FHitResult                             Hit;                                               // 0x0000(0x0170)(ConstParm, Parm, OutParm, ReferenceParm, ContainsInstancedReference, NativeAccessSpecifierPublic)
};
static_assert(alignof(Summoned_V2_10325101_SquirrelClimbingWall) == 0x000008, "Wrong alignment on Summoned_V2_10325101_SquirrelClimbingWall");
static_assert(sizeof(Summoned_V2_10325101_SquirrelClimbingWall) == 0x000170, "Wrong size on Summoned_V2_10325101_SquirrelClimbingWall");
static_assert(offsetof(Summoned_V2_10325101_SquirrelClimbingWall, Hit) == 0x000000, "Member 'Summoned_V2_10325101_SquirrelClimbingWall::Hit' has a wrong offset!");

// Function Hero_1032.Summoned_V2_10325101.SquirrelTurn
// 0x0178 (0x0178 - 0x0000)
struct Summoned_V2_10325101_SquirrelTurn final
{
public:
	struct FHitResult                             Hit;                                               // 0x0000(0x0170)(ConstParm, Parm, OutParm, ReferenceParm, ContainsInstancedReference, NativeAccessSpecifierPublic)
	float                                         Angle;                                             // 0x0170(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ForceTurn;                                         // 0x0174(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(Summoned_V2_10325101_SquirrelTurn) == 0x000008, "Wrong alignment on Summoned_V2_10325101_SquirrelTurn");
static_assert(sizeof(Summoned_V2_10325101_SquirrelTurn) == 0x000178, "Wrong size on Summoned_V2_10325101_SquirrelTurn");
static_assert(offsetof(Summoned_V2_10325101_SquirrelTurn, Hit) == 0x000000, "Member 'Summoned_V2_10325101_SquirrelTurn::Hit' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_SquirrelTurn, Angle) == 0x000170, "Member 'Summoned_V2_10325101_SquirrelTurn::Angle' has a wrong offset!");
static_assert(offsetof(Summoned_V2_10325101_SquirrelTurn, ForceTurn) == 0x000174, "Member 'Summoned_V2_10325101_SquirrelTurn::ForceTurn' has a wrong offset!");

// Function Hero_1032.Ability_103251.OnWaitTaskCancel_ThreadSafe
// 0x0004 (0x0004 - 0x0000)
struct Ability_103251_OnWaitTaskCancel_ThreadSafe final
{
public:
	float                                         TimeWaited;                                        // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(Ability_103251_OnWaitTaskCancel_ThreadSafe) == 0x000004, "Wrong alignment on Ability_103251_OnWaitTaskCancel_ThreadSafe");
static_assert(sizeof(Ability_103251_OnWaitTaskCancel_ThreadSafe) == 0x000004, "Wrong size on Ability_103251_OnWaitTaskCancel_ThreadSafe");
static_assert(offsetof(Ability_103251_OnWaitTaskCancel_ThreadSafe, TimeWaited) == 0x000000, "Member 'Ability_103251_OnWaitTaskCancel_ThreadSafe::TimeWaited' has a wrong offset!");

// Function Hero_1032.Ability_103251.OnWaitTaskConfirm
// 0x0004 (0x0004 - 0x0000)
struct Ability_103251_OnWaitTaskConfirm final
{
public:
	float                                         TimeWaited;                                        // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(Ability_103251_OnWaitTaskConfirm) == 0x000004, "Wrong alignment on Ability_103251_OnWaitTaskConfirm");
static_assert(sizeof(Ability_103251_OnWaitTaskConfirm) == 0x000004, "Wrong size on Ability_103251_OnWaitTaskConfirm");
static_assert(offsetof(Ability_103251_OnWaitTaskConfirm, TimeWaited) == 0x000000, "Member 'Ability_103251_OnWaitTaskConfirm::TimeWaited' has a wrong offset!");

// Function Hero_1032.Cue_Buff_Loop_10328101.OnBuffOwnerDeath
// 0x0028 (0x0028 - 0x0000)
struct Cue_Buff_Loop_10328101_OnBuffOwnerDeath final
{
public:
	class AActor*                                 InSourceAvatar;                                    // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 InTargetAvatar;                                    // 0x0008(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FAttributeModifierHandle               ModifierParameterHandle;                           // 0x0010(0x0018)(ConstParm, Parm, OutParm, ReferenceParm, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(Cue_Buff_Loop_10328101_OnBuffOwnerDeath) == 0x000008, "Wrong alignment on Cue_Buff_Loop_10328101_OnBuffOwnerDeath");
static_assert(sizeof(Cue_Buff_Loop_10328101_OnBuffOwnerDeath) == 0x000028, "Wrong size on Cue_Buff_Loop_10328101_OnBuffOwnerDeath");
static_assert(offsetof(Cue_Buff_Loop_10328101_OnBuffOwnerDeath, InSourceAvatar) == 0x000000, "Member 'Cue_Buff_Loop_10328101_OnBuffOwnerDeath::InSourceAvatar' has a wrong offset!");
static_assert(offsetof(Cue_Buff_Loop_10328101_OnBuffOwnerDeath, InTargetAvatar) == 0x000008, "Member 'Cue_Buff_Loop_10328101_OnBuffOwnerDeath::InTargetAvatar' has a wrong offset!");
static_assert(offsetof(Cue_Buff_Loop_10328101_OnBuffOwnerDeath, ModifierParameterHandle) == 0x000010, "Member 'Cue_Buff_Loop_10328101_OnBuffOwnerDeath::ModifierParameterHandle' has a wrong offset!");

// Function Hero_1032.Cue_Buff_Loop_10328101.OnBuffOwnerReborn
// 0x0740 (0x0740 - 0x0000)
struct Cue_Buff_Loop_10328101_OnBuffOwnerReborn final
{
public:
	class AActor*                                 InSourceActor;                                     // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_8[0x8];                                        // 0x0008(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FCharacterRebornParam                  RebornParam;                                       // 0x0010(0x0730)(ConstParm, Parm, OutParm, ReferenceParm, ContainsInstancedReference, NativeAccessSpecifierPublic)
};
static_assert(alignof(Cue_Buff_Loop_10328101_OnBuffOwnerReborn) == 0x000010, "Wrong alignment on Cue_Buff_Loop_10328101_OnBuffOwnerReborn");
static_assert(sizeof(Cue_Buff_Loop_10328101_OnBuffOwnerReborn) == 0x000740, "Wrong size on Cue_Buff_Loop_10328101_OnBuffOwnerReborn");
static_assert(offsetof(Cue_Buff_Loop_10328101_OnBuffOwnerReborn, InSourceActor) == 0x000000, "Member 'Cue_Buff_Loop_10328101_OnBuffOwnerReborn::InSourceActor' has a wrong offset!");
static_assert(offsetof(Cue_Buff_Loop_10328101_OnBuffOwnerReborn, RebornParam) == 0x000010, "Member 'Cue_Buff_Loop_10328101_OnBuffOwnerReborn::RebornParam' has a wrong offset!");

// Function Hero_1032.Cue_Buff_Loop_10328101.OnGameplayTagUpdate
// 0x0010 (0x0010 - 0x0000)
struct Cue_Buff_Loop_10328101_OnGameplayTagUpdate final
{
public:
	struct FGameplayTag                           Tag;                                               // 0x0000(0x000C)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          TagExists;                                         // 0x000C(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(Cue_Buff_Loop_10328101_OnGameplayTagUpdate) == 0x000004, "Wrong alignment on Cue_Buff_Loop_10328101_OnGameplayTagUpdate");
static_assert(sizeof(Cue_Buff_Loop_10328101_OnGameplayTagUpdate) == 0x000010, "Wrong size on Cue_Buff_Loop_10328101_OnGameplayTagUpdate");
static_assert(offsetof(Cue_Buff_Loop_10328101_OnGameplayTagUpdate, Tag) == 0x000000, "Member 'Cue_Buff_Loop_10328101_OnGameplayTagUpdate::Tag' has a wrong offset!");
static_assert(offsetof(Cue_Buff_Loop_10328101_OnGameplayTagUpdate, TagExists) == 0x00000C, "Member 'Cue_Buff_Loop_10328101_OnGameplayTagUpdate::TagExists' has a wrong offset!");

// Function Hero_1032.Cue_Buff_Loop_10328101.SetAnimPlaying
// 0x0001 (0x0001 - 0x0000)
struct Cue_Buff_Loop_10328101_SetAnimPlaying final
{
public:
	bool                                          bIsPlaying;                                        // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(Cue_Buff_Loop_10328101_SetAnimPlaying) == 0x000001, "Wrong alignment on Cue_Buff_Loop_10328101_SetAnimPlaying");
static_assert(sizeof(Cue_Buff_Loop_10328101_SetAnimPlaying) == 0x000001, "Wrong size on Cue_Buff_Loop_10328101_SetAnimPlaying");
static_assert(offsetof(Cue_Buff_Loop_10328101_SetAnimPlaying, bIsPlaying) == 0x000000, "Member 'Cue_Buff_Loop_10328101_SetAnimPlaying::bIsPlaying' has a wrong offset!");

// Function Hero_1032.Cue_Buff_Loop_10328101.SetMontageSection
// 0x000C (0x000C - 0x0000)
struct Cue_Buff_Loop_10328101_SetMontageSection final
{
public:
	class FName                                   SectionName;                                       // 0x0000(0x000C)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(Cue_Buff_Loop_10328101_SetMontageSection) == 0x000004, "Wrong alignment on Cue_Buff_Loop_10328101_SetMontageSection");
static_assert(sizeof(Cue_Buff_Loop_10328101_SetMontageSection) == 0x00000C, "Wrong size on Cue_Buff_Loop_10328101_SetMontageSection");
static_assert(offsetof(Cue_Buff_Loop_10328101_SetMontageSection, SectionName) == 0x000000, "Member 'Cue_Buff_Loop_10328101_SetMontageSection::SectionName' has a wrong offset!");

// Function Hero_1032.EpicMomentAction_1032.OnGameplayEffectAppliedToTarget
// 0x0018 (0x0018 - 0x0000)
struct EpicMomentAction_1032_OnGameplayEffectAppliedToTarget final
{
public:
	class UAbilitySystemComponent*                ASC;                                               // 0x0000(0x0008)(Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FGameplayEffectSpecStackHandle         GameplayEffectSpecHandle;                          // 0x0008(0x0008)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
	struct FActiveGameplayEffectHandle            ActiveGameplayEffectHandle;                        // 0x0010(0x0008)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EpicMomentAction_1032_OnGameplayEffectAppliedToTarget) == 0x000008, "Wrong alignment on EpicMomentAction_1032_OnGameplayEffectAppliedToTarget");
static_assert(sizeof(EpicMomentAction_1032_OnGameplayEffectAppliedToTarget) == 0x000018, "Wrong size on EpicMomentAction_1032_OnGameplayEffectAppliedToTarget");
static_assert(offsetof(EpicMomentAction_1032_OnGameplayEffectAppliedToTarget, ASC) == 0x000000, "Member 'EpicMomentAction_1032_OnGameplayEffectAppliedToTarget::ASC' has a wrong offset!");
static_assert(offsetof(EpicMomentAction_1032_OnGameplayEffectAppliedToTarget, GameplayEffectSpecHandle) == 0x000008, "Member 'EpicMomentAction_1032_OnGameplayEffectAppliedToTarget::GameplayEffectSpecHandle' has a wrong offset!");
static_assert(offsetof(EpicMomentAction_1032_OnGameplayEffectAppliedToTarget, ActiveGameplayEffectHandle) == 0x000010, "Member 'EpicMomentAction_1032_OnGameplayEffectAppliedToTarget::ActiveGameplayEffectHandle' has a wrong offset!");

// Function Hero_1032.EpicMomentAction_1032.OnSummonerBegin
// 0x0060 (0x0060 - 0x0000)
struct EpicMomentAction_1032_OnSummonerBegin final
{
public:
	class AActor*                                 SourceActor;                                       // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UMarvelGameplayAbility*                 SourceAbility;                                     // 0x0008(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class AActor*                                 Summoned;                                          // 0x0010(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FMarvelTargetActorGenerateInfo         GenerateInfo;                                      // 0x0018(0x0048)(ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)
};
static_assert(alignof(EpicMomentAction_1032_OnSummonerBegin) == 0x000008, "Wrong alignment on EpicMomentAction_1032_OnSummonerBegin");
static_assert(sizeof(EpicMomentAction_1032_OnSummonerBegin) == 0x000060, "Wrong size on EpicMomentAction_1032_OnSummonerBegin");
static_assert(offsetof(EpicMomentAction_1032_OnSummonerBegin, SourceActor) == 0x000000, "Member 'EpicMomentAction_1032_OnSummonerBegin::SourceActor' has a wrong offset!");
static_assert(offsetof(EpicMomentAction_1032_OnSummonerBegin, SourceAbility) == 0x000008, "Member 'EpicMomentAction_1032_OnSummonerBegin::SourceAbility' has a wrong offset!");
static_assert(offsetof(EpicMomentAction_1032_OnSummonerBegin, Summoned) == 0x000010, "Member 'EpicMomentAction_1032_OnSummonerBegin::Summoned' has a wrong offset!");
static_assert(offsetof(EpicMomentAction_1032_OnSummonerBegin, GenerateInfo) == 0x000018, "Member 'EpicMomentAction_1032_OnSummonerBegin::GenerateInfo' has a wrong offset!");

// Function Hero_1032.EpicMomentAction_1032.OnSummonerEnd
// 0x0008 (0x0008 - 0x0000)
struct EpicMomentAction_1032_OnSummonerEnd final
{
public:
	class AActor*                                 InActor;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(EpicMomentAction_1032_OnSummonerEnd) == 0x000008, "Wrong alignment on EpicMomentAction_1032_OnSummonerEnd");
static_assert(sizeof(EpicMomentAction_1032_OnSummonerEnd) == 0x000008, "Wrong size on EpicMomentAction_1032_OnSummonerEnd");
static_assert(offsetof(EpicMomentAction_1032_OnSummonerEnd, InActor) == 0x000000, "Member 'EpicMomentAction_1032_OnSummonerEnd::InActor' has a wrong offset!");

// Function Hero_1032.TippyToeAnimInstance.AbilityMontageBlendingOut
// 0x0010 (0x0010 - 0x0000)
struct TippyToeAnimInstance_AbilityMontageBlendingOut final
{
public:
	class UAnimMontage*                           Montage;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bInterrupted;                                      // 0x0008(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_9[0x7];                                        // 0x0009(0x0007)(Fixing Struct Size After Last Property [ Dumper-7 ])
};
static_assert(alignof(TippyToeAnimInstance_AbilityMontageBlendingOut) == 0x000008, "Wrong alignment on TippyToeAnimInstance_AbilityMontageBlendingOut");
static_assert(sizeof(TippyToeAnimInstance_AbilityMontageBlendingOut) == 0x000010, "Wrong size on TippyToeAnimInstance_AbilityMontageBlendingOut");
static_assert(offsetof(TippyToeAnimInstance_AbilityMontageBlendingOut, Montage) == 0x000000, "Member 'TippyToeAnimInstance_AbilityMontageBlendingOut::Montage' has a wrong offset!");
static_assert(offsetof(TippyToeAnimInstance_AbilityMontageBlendingOut, bInterrupted) == 0x000008, "Member 'TippyToeAnimInstance_AbilityMontageBlendingOut::bInterrupted' has a wrong offset!");

// Function Hero_1032.TippyToeAnimInstance.AbilityMontageStarted
// 0x0008 (0x0008 - 0x0000)
struct TippyToeAnimInstance_AbilityMontageStarted final
{
public:
	class UAnimMontage*                           Montage;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(TippyToeAnimInstance_AbilityMontageStarted) == 0x000008, "Wrong alignment on TippyToeAnimInstance_AbilityMontageStarted");
static_assert(sizeof(TippyToeAnimInstance_AbilityMontageStarted) == 0x000008, "Wrong size on TippyToeAnimInstance_AbilityMontageStarted");
static_assert(offsetof(TippyToeAnimInstance_AbilityMontageStarted, Montage) == 0x000000, "Member 'TippyToeAnimInstance_AbilityMontageStarted::Montage' has a wrong offset!");

// Function Hero_1032.SquirrelGirlCharacter.SetSquirrelGirlJump
// 0x0001 (0x0001 - 0x0000)
struct SquirrelGirlCharacter_SetSquirrelGirlJump final
{
public:
	bool                                          NewState;                                          // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(SquirrelGirlCharacter_SetSquirrelGirlJump) == 0x000001, "Wrong alignment on SquirrelGirlCharacter_SetSquirrelGirlJump");
static_assert(sizeof(SquirrelGirlCharacter_SetSquirrelGirlJump) == 0x000001, "Wrong size on SquirrelGirlCharacter_SetSquirrelGirlJump");
static_assert(offsetof(SquirrelGirlCharacter_SetSquirrelGirlJump, NewState) == 0x000000, "Member 'SquirrelGirlCharacter_SetSquirrelGirlJump::NewState' has a wrong offset!");

// Function Hero_1032.SquirrelGirlChildActor.DeactivatePhysicalAnimation
// 0x001C (0x001C - 0x0000)
struct SquirrelGirlChildActor_DeactivatePhysicalAnimation final
{
public:
	bool                                          bNeedPhysics;                                      // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   InBoneName1;                                       // 0x0004(0x000C)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   InBoneName2;                                       // 0x0010(0x000C)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(SquirrelGirlChildActor_DeactivatePhysicalAnimation) == 0x000004, "Wrong alignment on SquirrelGirlChildActor_DeactivatePhysicalAnimation");
static_assert(sizeof(SquirrelGirlChildActor_DeactivatePhysicalAnimation) == 0x00001C, "Wrong size on SquirrelGirlChildActor_DeactivatePhysicalAnimation");
static_assert(offsetof(SquirrelGirlChildActor_DeactivatePhysicalAnimation, bNeedPhysics) == 0x000000, "Member 'SquirrelGirlChildActor_DeactivatePhysicalAnimation::bNeedPhysics' has a wrong offset!");
static_assert(offsetof(SquirrelGirlChildActor_DeactivatePhysicalAnimation, InBoneName1) == 0x000004, "Member 'SquirrelGirlChildActor_DeactivatePhysicalAnimation::InBoneName1' has a wrong offset!");
static_assert(offsetof(SquirrelGirlChildActor_DeactivatePhysicalAnimation, InBoneName2) == 0x000010, "Member 'SquirrelGirlChildActor_DeactivatePhysicalAnimation::InBoneName2' has a wrong offset!");

// Function Hero_1032.SquirrelGirlChildActor.SetPhysicalAnimation
// 0x0020 (0x0020 - 0x0000)
struct SquirrelGirlChildActor_SetPhysicalAnimation final
{
public:
	class FName                                   InBoneName1;                                       // 0x0000(0x000C)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         InPhysicsBlendWeight1;                             // 0x000C(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   InBoneName2;                                       // 0x0010(0x000C)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PhysicsBlendWeight2_0;                             // 0x001C(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(SquirrelGirlChildActor_SetPhysicalAnimation) == 0x000004, "Wrong alignment on SquirrelGirlChildActor_SetPhysicalAnimation");
static_assert(sizeof(SquirrelGirlChildActor_SetPhysicalAnimation) == 0x000020, "Wrong size on SquirrelGirlChildActor_SetPhysicalAnimation");
static_assert(offsetof(SquirrelGirlChildActor_SetPhysicalAnimation, InBoneName1) == 0x000000, "Member 'SquirrelGirlChildActor_SetPhysicalAnimation::InBoneName1' has a wrong offset!");
static_assert(offsetof(SquirrelGirlChildActor_SetPhysicalAnimation, InPhysicsBlendWeight1) == 0x00000C, "Member 'SquirrelGirlChildActor_SetPhysicalAnimation::InPhysicsBlendWeight1' has a wrong offset!");
static_assert(offsetof(SquirrelGirlChildActor_SetPhysicalAnimation, InBoneName2) == 0x000010, "Member 'SquirrelGirlChildActor_SetPhysicalAnimation::InBoneName2' has a wrong offset!");
static_assert(offsetof(SquirrelGirlChildActor_SetPhysicalAnimation, PhysicsBlendWeight2_0) == 0x00001C, "Member 'SquirrelGirlChildActor_SetPhysicalAnimation::PhysicsBlendWeight2_0' has a wrong offset!");

}

