#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Hero_1050

#include "Basic.hpp"

#include "Hero_1050_classes.hpp"
#include "Hero_1050_parameters.hpp"


namespace SDK
{

// Function Hero_1050.Ability_105001.OnSkillEnergyAttrRegen
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   NewValue                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// float                                   OldValue                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UAbility_105001::OnSkillEnergyAttrRegen(float NewValue, float OldValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ability_105001", "OnSkillEnergyAttrRegen");

	Params::Ability_105001_OnSkillEnergyAttrRegen Parms{};

	Parms.NewValue = NewValue;
	Parms.OldValue = OldValue;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Hero_1050.Ability_105001.SetTargetInBattleState
// (Final, Native, Public, BlueprintCallable, Const)
// Parameters:
// class AActor*                           InTarget                                               (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    bIsBattling                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UAbility_105001::SetTargetInBattleState(class AActor* InTarget, bool bIsBattling) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ability_105001", "SetTargetInBattleState");

	Params::Ability_105001_SetTargetInBattleState Parms{};

	Parms.InTarget = InTarget;
	Parms.bIsBattling = bIsBattling;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Summoned_1050_Base.InitSummonedHealth
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// float                                   NewValue                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void ASummoned_1050_Base::InitSummonedHealth(float NewValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Summoned_1050_Base", "InitSummonedHealth");

	Params::Summoned_1050_Base_InitSummonedHealth Parms{};

	Parms.NewValue = NewValue;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Summoned_1050_Base.MulticastResetSummonedLifeSpan
// (Net, NetReliable, Native, Event, NetMulticast, Public, BlueprintCallable)
// Parameters:
// float                                   InLifeTime                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void ASummoned_1050_Base::MulticastResetSummonedLifeSpan(float InLifeTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Summoned_1050_Base", "MulticastResetSummonedLifeSpan");

	Params::Summoned_1050_Base_MulticastResetSummonedLifeSpan Parms{};

	Parms.InLifeTime = InLifeTime;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Summoned_1050_Base.SetSummonedAttributeValue
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// EMarvelAttributeType                    InAttributeType                                        (ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// float                                   NewValue                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void ASummoned_1050_Base::SetSummonedAttributeValue(const EMarvelAttributeType InAttributeType, float NewValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Summoned_1050_Base", "SetSummonedAttributeValue");

	Params::Summoned_1050_Base_SetSummonedAttributeValue Parms{};

	Parms.InAttributeType = InAttributeType;
	Parms.NewValue = NewValue;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Summoned_1050_Base.GetSummonedSphereRadius
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// float                                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

float ASummoned_1050_Base::GetSummonedSphereRadius() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Summoned_1050_Base", "GetSummonedSphereRadius");

	Params::Summoned_1050_Base_GetSummonedSphereRadius Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function Hero_1050.Summoned_1050_Base.SetSummonedSphereRadius
// (Final, Native, Public, BlueprintCallable, Const)
// Parameters:
// float                                   NewValue                                               (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void ASummoned_1050_Base::SetSummonedSphereRadius(float NewValue) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Summoned_1050_Base", "SetSummonedSphereRadius");

	Params::Summoned_1050_Base_SetSummonedSphereRadius Parms{};

	Parms.NewValue = NewValue;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Ability_OffBattleBuffMgr.TryApplyBuff
// (Final, Native, Protected)

void UAbility_OffBattleBuffMgr::TryApplyBuff()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ability_OffBattleBuffMgr", "TryApplyBuff");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Ability_105071.NetSyncEndAbility
// (Final, Native, Protected, BlueprintCallable)

void UAbility_105071::NetSyncEndAbility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ability_105071", "NetSyncEndAbility");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Ability_105071.OnSync
// (Final, Native, Protected)

void UAbility_105071::OnSync()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Ability_105071", "OnSync");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.NotTreatShield_NonOverflow.OnGenerateAttribute
// (Final, Native, Protected)

void UNotTreatShield_NonOverflow::OnGenerateAttribute()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NotTreatShield_NonOverflow", "OnGenerateAttribute");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.NotTreatShield_NonOverflow.ShouldExecuteNotTreatShield
// (Final, Native, Public, HasOutParams, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// float                                   OutMagnitude                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UNotTreatShield_NonOverflow::ShouldExecuteNotTreatShield(float* OutMagnitude) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NotTreatShield_NonOverflow", "ShouldExecuteNotTreatShield");

	Params::NotTreatShield_NonOverflow_ShouldExecuteNotTreatShield Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (OutMagnitude != nullptr)
		*OutMagnitude = Parms.OutMagnitude;

	return Parms.ReturnValue;
}


// Function Hero_1050.CueNotify_Buff_105002.OnMaterialChanged
// (Final, Native, Public)

void ACueNotify_Buff_105002::OnMaterialChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("CueNotify_Buff_105002", "OnMaterialChanged");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.EpicMomentAction_1050.OnScopeBegin
// (Final, Native, Public, HasOutParams)
// Parameters:
// class AActor*                           SourceActor                                            (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class UMarvelGameplayAbility*           SourceAbility                                          (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class AActor*                           Scope                                                  (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FMarvelTargetActorGenerateInfo   GenerateInfo                                           (ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)

void UEpicMomentAction_1050::OnScopeBegin(class AActor* SourceActor, class UMarvelGameplayAbility* SourceAbility, class AActor* Scope, const struct FMarvelTargetActorGenerateInfo& GenerateInfo)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EpicMomentAction_1050", "OnScopeBegin");

	Params::EpicMomentAction_1050_OnScopeBegin Parms{};

	Parms.SourceActor = SourceActor;
	Parms.SourceAbility = SourceAbility;
	Parms.Scope = Scope;
	Parms.GenerateInfo = std::move(GenerateInfo);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.EpicMomentAction_1050.OnScopeEnd
// (Final, Native, Public)
// Parameters:
// class AActor*                           InActor                                                (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UEpicMomentAction_1050::OnScopeEnd(class AActor* InActor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("EpicMomentAction_1050", "OnScopeEnd");

	Params::EpicMomentAction_1050_OnScopeEnd Parms{};

	Parms.InActor = InActor;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Projectile_10503101.OnRep_HasReturnCompleted
// (Final, Native, Protected)

void AProjectile_10503101::OnRep_HasReturnCompleted()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Projectile_10503101", "OnRep_HasReturnCompleted");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Scope_105071_Manager.Get
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UObject*                          WorldContextObject                                     (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class UScope_105071_Manager*            ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

class UScope_105071_Manager* UScope_105071_Manager::Get(class UObject* WorldContextObject)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("Scope_105071_Manager", "Get");

	Params::Scope_105071_Manager_Get Parms{};

	Parms.WorldContextObject = WorldContextObject;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function Hero_1050.Scope_105071_Manager.CheckCanReleaseScope
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class AActor*                           InActor                                                (ConstParm, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UScope_105071_Manager::CheckCanReleaseScope(const class AActor* InActor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Scope_105071_Manager", "CheckCanReleaseScope");

	Params::Scope_105071_Manager_CheckCanReleaseScope Parms{};

	Parms.InActor = InActor;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function Hero_1050.Stealth_105002.OnAbilityActivateFailed
// (Final, Native, Public, HasOutParams)
// Parameters:
// class UGameplayAbility*                 Ability                                                (ConstParm, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// struct FGameplayTagContainer            GameplayTags                                           (ConstParm, Parm, OutParm, ReferenceParm, NativeAccessSpecifierPublic)

void UStealth_105002::OnAbilityActivateFailed(const class UGameplayAbility* Ability, const struct FGameplayTagContainer& GameplayTags)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Stealth_105002", "OnAbilityActivateFailed");

	Params::Stealth_105002_OnAbilityActivateFailed Parms{};

	Parms.Ability = Ability;
	Parms.GameplayTags = std::move(GameplayTags);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function Hero_1050.Stealth_105002.OnCharacterBattleStateChanged
// (Final, Native, Public)
// Parameters:
// bool                                    bValue                                                 (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UStealth_105002::OnCharacterBattleStateChanged(bool bValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Stealth_105002", "OnCharacterBattleStateChanged");

	Params::Stealth_105002_OnCharacterBattleStateChanged Parms{};

	Parms.bValue = bValue;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}

