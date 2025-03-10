#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_103961

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"
#include "Hero_1039_structs.hpp"
#include "Hero_1039_classes.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK
{

// PythonClass PyAbility_103961.PyConfig_103961
// 0x2340 (0x23F0 - 0x00B0)
class UPyConfig_103961 final : public UConfig_103961
{
public:
	struct FDashAbilityInfo                       RiseDashInfo;                                      // 0x00B0(0x0BA8)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FDashAbilityInfo                       DropDashInfo;                                      // 0x0C58(0x0BA8)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FDashAbilityInfo                       PreDropDashInfo;                                   // 0x1800(0x0BA8)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FPreArrivedInfo                        RisePreArrivedInfo;                                // 0x23A8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, NativeAccessSpecifierPublic)
	struct FPreArrivedInfo                        DropPreArrivedInfo;                                // 0x23B0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, NativeAccessSpecifierPublic)
	TArray<int32>                                 CustomBuffIds;                                     // 0x23B8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	int32                                         CustomScopeID;                                     // 0x23C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         FlyDuration;                                       // 0x23CC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FAbilitySection_103961>         CueSections;                                       // 0x23D0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	TArray<EAbilityInputBinds>                    BlockInputBinds;                                   // 0x23E0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyConfig_103961">();
	}
	static class UPyConfig_103961* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyConfig_103961>();
	}
};
static_assert(alignof(UPyConfig_103961) == 0x000008, "Wrong alignment on UPyConfig_103961");
static_assert(sizeof(UPyConfig_103961) == 0x0023F0, "Wrong size on UPyConfig_103961");
static_assert(offsetof(UPyConfig_103961, RiseDashInfo) == 0x0000B0, "Member 'UPyConfig_103961::RiseDashInfo' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, DropDashInfo) == 0x000C58, "Member 'UPyConfig_103961::DropDashInfo' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, PreDropDashInfo) == 0x001800, "Member 'UPyConfig_103961::PreDropDashInfo' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, RisePreArrivedInfo) == 0x0023A8, "Member 'UPyConfig_103961::RisePreArrivedInfo' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, DropPreArrivedInfo) == 0x0023B0, "Member 'UPyConfig_103961::DropPreArrivedInfo' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, CustomBuffIds) == 0x0023B8, "Member 'UPyConfig_103961::CustomBuffIds' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, CustomScopeID) == 0x0023C8, "Member 'UPyConfig_103961::CustomScopeID' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, FlyDuration) == 0x0023CC, "Member 'UPyConfig_103961::FlyDuration' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, CueSections) == 0x0023D0, "Member 'UPyConfig_103961::CueSections' has a wrong offset!");
static_assert(offsetof(UPyConfig_103961, BlockInputBinds) == 0x0023E0, "Member 'UPyConfig_103961::BlockInputBinds' has a wrong offset!");

// PythonClass PyAbility_103961.PyAbility_103961
// 0x1B58 (0x40E0 - 0x2588)
class UPyAbility_103961 : public UAbility_103961
{
public:
	uint8                                         Pad_2588[0x8];                                     // 0x2588(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FMarvelAbilityTraceContext             TraceContext;                                      // 0x2590(0x0F90)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FDashAbilityInfo                       RiseDashInfo;                                      // 0x3520(0x0BA8)(Transient, NativeAccessSpecifierPublic)
	int32                                         RepState;                                          // 0x40C8(0x0004)(BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_40CC[0x4];                                     // 0x40CC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             AbilityStateDispatcher;                            // 0x40D0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void AbilityStateDispatcher__DelegateSignature(int32 ST);
	void BeginPlay();
	void K2_ActivateAbility();
	void BreakEventNotify();
	void NativeOnMontageCompleted(const class FString& Tag);
	void K2_OnEndAbility(bool bWasCancelled);
	void NativeOnMontageEvent(const class FString& Tag);
	void EndPlay();
	void OnRep_State(int32 ST);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyAbility_103961">();
	}
	static class UPyAbility_103961* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyAbility_103961>();
	}
};
static_assert(alignof(UPyAbility_103961) == 0x000010, "Wrong alignment on UPyAbility_103961");
static_assert(sizeof(UPyAbility_103961) == 0x0040E0, "Wrong size on UPyAbility_103961");
static_assert(offsetof(UPyAbility_103961, TraceContext) == 0x002590, "Member 'UPyAbility_103961::TraceContext' has a wrong offset!");
static_assert(offsetof(UPyAbility_103961, RiseDashInfo) == 0x003520, "Member 'UPyAbility_103961::RiseDashInfo' has a wrong offset!");
static_assert(offsetof(UPyAbility_103961, RepState) == 0x0040C8, "Member 'UPyAbility_103961::RepState' has a wrong offset!");
static_assert(offsetof(UPyAbility_103961, AbilityStateDispatcher) == 0x0040D0, "Member 'UPyAbility_103961::AbilityStateDispatcher' has a wrong offset!");

// PythonClass PyAbility_103961.PySkillEnergyFastRegenAbility_103961
// 0x0080 (0x1178 - 0x10F8)
class UPySkillEnergyFastRegenAbility_103961 : public UMarvelEffectGameplayAbility
{
public:
	float                                         RegenRatio;                                        // 0x10F8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_10FC[0x4];                                     // 0x10FC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  CustomEffectSkillEnergyRegen;                      // 0x1100(0x0068)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FGameplayTag                           HeroAttributeData;                                 // 0x1168(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void BeginPlay();
	bool CanActivate();
	void K2_ActivateAbility();
	void K2_OnEndAbility(bool bWasCancelled);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PySkillEnergyFastRegenAbility_103961">();
	}
	static class UPySkillEnergyFastRegenAbility_103961* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPySkillEnergyFastRegenAbility_103961>();
	}
};
static_assert(alignof(UPySkillEnergyFastRegenAbility_103961) == 0x000008, "Wrong alignment on UPySkillEnergyFastRegenAbility_103961");
static_assert(sizeof(UPySkillEnergyFastRegenAbility_103961) == 0x001178, "Wrong size on UPySkillEnergyFastRegenAbility_103961");
static_assert(offsetof(UPySkillEnergyFastRegenAbility_103961, RegenRatio) == 0x0010F8, "Member 'UPySkillEnergyFastRegenAbility_103961::RegenRatio' has a wrong offset!");
static_assert(offsetof(UPySkillEnergyFastRegenAbility_103961, CustomEffectSkillEnergyRegen) == 0x001100, "Member 'UPySkillEnergyFastRegenAbility_103961::CustomEffectSkillEnergyRegen' has a wrong offset!");
static_assert(offsetof(UPySkillEnergyFastRegenAbility_103961, HeroAttributeData) == 0x001168, "Member 'UPySkillEnergyFastRegenAbility_103961::HeroAttributeData' has a wrong offset!");

// PythonClass PyAbility_103961.PyCue_Ability_Loop_10396101
// 0x0008 (0x0E80 - 0x0E78)
class APyCue_Ability_Loop_10396101 final : public ACue_Ability_Loop_10396101
{
public:
	class UMarterialAnimHandlerComponent*         MarterialAnimHandler;                              // 0x0E78(0x0008)(Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, EditConst, InstancedReference, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	bool WhileActive(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);
	bool OnRemove(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);
	class USkeletalMeshComponent* K2_GetOwnerMesh();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Ability_Loop_10396101">();
	}
	static class APyCue_Ability_Loop_10396101* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyCue_Ability_Loop_10396101>();
	}
};
static_assert(alignof(APyCue_Ability_Loop_10396101) == 0x000008, "Wrong alignment on APyCue_Ability_Loop_10396101");
static_assert(sizeof(APyCue_Ability_Loop_10396101) == 0x000E80, "Wrong size on APyCue_Ability_Loop_10396101");
static_assert(offsetof(APyCue_Ability_Loop_10396101, MarterialAnimHandler) == 0x000E78, "Member 'APyCue_Ability_Loop_10396101::MarterialAnimHandler' has a wrong offset!");

// PythonClass PyAbility_103961.PyCue_Ability_Loop_10396103
// 0x0010 (0x0E60 - 0x0E50)
class APyCue_Ability_Loop_10396103 final : public AMarvelCueNotify_Ability
{
public:
	TArray<struct FVector>                        EndPosParam;                                       // 0x0E50(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)

public:
	void WhileActiveFX(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Ability_Loop_10396103">();
	}
	static class APyCue_Ability_Loop_10396103* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyCue_Ability_Loop_10396103>();
	}
};
static_assert(alignof(APyCue_Ability_Loop_10396103) == 0x000008, "Wrong alignment on APyCue_Ability_Loop_10396103");
static_assert(sizeof(APyCue_Ability_Loop_10396103) == 0x000E60, "Wrong size on APyCue_Ability_Loop_10396103");
static_assert(offsetof(APyCue_Ability_Loop_10396103, EndPosParam) == 0x000E50, "Member 'APyCue_Ability_Loop_10396103::EndPosParam' has a wrong offset!");

// PythonClass PyAbility_103961.PyCue_Ability_Loop_10396104
// 0x0048 (0x0E98 - 0x0E50)
class APyCue_Ability_Loop_10396104 final : public AMarvelCueNotify_Ability
{
public:
	TArray<class UFXSystemAsset*>                 FirstFx;                                           // 0x0E50(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	TArray<class FName>                           FirstSockets;                                      // 0x0E60(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	TArray<class UFXSystemAsset*>                 SecondFx;                                          // 0x0E70(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	TArray<class FName>                           SecondSockets;                                     // 0x0E80(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	float                                         SecondFxPlayTime;                                  // 0x0E90(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void WhileActiveFX(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);
	void OnRemoveFX(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Ability_Loop_10396104">();
	}
	static class APyCue_Ability_Loop_10396104* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyCue_Ability_Loop_10396104>();
	}
};
static_assert(alignof(APyCue_Ability_Loop_10396104) == 0x000008, "Wrong alignment on APyCue_Ability_Loop_10396104");
static_assert(sizeof(APyCue_Ability_Loop_10396104) == 0x000E98, "Wrong size on APyCue_Ability_Loop_10396104");
static_assert(offsetof(APyCue_Ability_Loop_10396104, FirstFx) == 0x000E50, "Member 'APyCue_Ability_Loop_10396104::FirstFx' has a wrong offset!");
static_assert(offsetof(APyCue_Ability_Loop_10396104, FirstSockets) == 0x000E60, "Member 'APyCue_Ability_Loop_10396104::FirstSockets' has a wrong offset!");
static_assert(offsetof(APyCue_Ability_Loop_10396104, SecondFx) == 0x000E70, "Member 'APyCue_Ability_Loop_10396104::SecondFx' has a wrong offset!");
static_assert(offsetof(APyCue_Ability_Loop_10396104, SecondSockets) == 0x000E80, "Member 'APyCue_Ability_Loop_10396104::SecondSockets' has a wrong offset!");
static_assert(offsetof(APyCue_Ability_Loop_10396104, SecondFxPlayTime) == 0x000E90, "Member 'APyCue_Ability_Loop_10396104::SecondFxPlayTime' has a wrong offset!");

// PythonClass PyAbility_103961.PyUIController_103961
// 0x0018 (0x0C78 - 0x0C60)
class UPyUIController_103961 final : public UUIC_Ability
{
public:
	EAbilityState_103961                          ActivateStage;                                     // 0x0C60(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	EAbilityState_103961                          DeactivateStage;                                   // 0x0C61(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_C62[0x6];                                      // 0x0C62(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FWidget_ActionTip>              ActionTips;                                        // 0x0C68(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)

public:
	void OnInit();
	void OnAbilityStateChange(int32 ST);
	void OnDestruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyUIController_103961">();
	}
	static class UPyUIController_103961* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyUIController_103961>();
	}
};
static_assert(alignof(UPyUIController_103961) == 0x000008, "Wrong alignment on UPyUIController_103961");
static_assert(sizeof(UPyUIController_103961) == 0x000C78, "Wrong size on UPyUIController_103961");
static_assert(offsetof(UPyUIController_103961, ActivateStage) == 0x000C60, "Member 'UPyUIController_103961::ActivateStage' has a wrong offset!");
static_assert(offsetof(UPyUIController_103961, DeactivateStage) == 0x000C61, "Member 'UPyUIController_103961::DeactivateStage' has a wrong offset!");
static_assert(offsetof(UPyUIController_103961, ActionTips) == 0x000C68, "Member 'UPyUIController_103961::ActionTips' has a wrong offset!");

}

