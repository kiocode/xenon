#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_HitIndicator

#include "Basic.hpp"

#include "PyWidget_HitIndicator_classes.hpp"
#include "PyWidget_HitIndicator_parameters.hpp"


namespace SDK
{

// PythonFunction PyWidget_HitIndicator.PyWidget_HitSpecialBuff.OnAnimationFinished
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWidgetAnimation*                 Animation                                              (ConstParm, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_HitSpecialBuff::OnAnimationFinished(const class UWidgetAnimation* Animation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitSpecialBuff", "OnAnimationFinished");

	Params::PyWidget_HitSpecialBuff_OnAnimationFinished Parms{};

	Parms.Animation = Animation;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.OnDamageImmunized
// (Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// struct FGameplayTagContainer            ImmunitySpecTags                                       (ConstParm, Parm, OutParm, ReferenceParm)

void UPyWidget_HitIndicator::OnDamageImmunized(const struct FGameplayTagContainer& ImmunitySpecTags)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "OnDamageImmunized");

	Params::PyWidget_HitIndicator_OnDamageImmunized Parms{};

	Parms.ImmunitySpecTags = std::move(ImmunitySpecTags);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.OnApplyDamageOnDestruction
// (Native, Public, BlueprintCallable)
// Parameters:
// class AActor*                           InSourceAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class AActor*                           InTargetAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// float                                   RealDeltaValue                                         (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_HitIndicator::OnApplyDamageOnDestruction(class AActor* InSourceAvatar, class AActor* InTargetAvatar, float RealDeltaValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "OnApplyDamageOnDestruction");

	Params::PyWidget_HitIndicator_OnApplyDamageOnDestruction Parms{};

	Parms.InSourceAvatar = InSourceAvatar;
	Parms.InTargetAvatar = InTargetAvatar;
	Parms.RealDeltaValue = RealDeltaValue;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.OnApplyDamageByField
// (Native, Event, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           InSourceAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class AActor*                           InTargetAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// float                                   RealDeltaValue                                         (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_HitIndicator::OnApplyDamageByField(class AActor* InSourceAvatar, class AActor* InTargetAvatar, float RealDeltaValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "OnApplyDamageByField");

	Params::PyWidget_HitIndicator_OnApplyDamageByField Parms{};

	Parms.InSourceAvatar = InSourceAvatar;
	Parms.InTargetAvatar = InTargetAvatar;
	Parms.RealDeltaValue = RealDeltaValue;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.ApplyDamageEffect
// (Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// class AActor*                           InSourceAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class AActor*                           InTargetAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// struct FAttributeModifierHandle         ParameterHandle                                        (ConstParm, Parm, OutParm, ReferenceParm, HasGetValueTypeHash)

void UPyWidget_HitIndicator::ApplyDamageEffect(class AActor* InSourceAvatar, class AActor* InTargetAvatar, const struct FAttributeModifierHandle& ParameterHandle)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "ApplyDamageEffect");

	Params::PyWidget_HitIndicator_ApplyDamageEffect Parms{};

	Parms.InSourceAvatar = InSourceAvatar;
	Parms.InTargetAvatar = InTargetAvatar;
	Parms.ParameterHandle = std::move(ParameterHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.OnApplyDamage
// (Native, Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                           InSourceAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class AActor*                           InTargetAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// struct FAttributeModifierHandle         ModifierHandle                                         (ConstParm, Parm, OutParm, ReferenceParm, HasGetValueTypeHash)

void UPyWidget_HitIndicator::OnApplyDamage(class AActor* InSourceAvatar, class AActor* InTargetAvatar, const struct FAttributeModifierHandle& ModifierHandle)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "OnApplyDamage");

	Params::PyWidget_HitIndicator_OnApplyDamage Parms{};

	Parms.InSourceAvatar = InSourceAvatar;
	Parms.InTargetAvatar = InTargetAvatar;
	Parms.ModifierHandle = std::move(ModifierHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.OnApplyTreat
// (Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// class AActor*                           InSourceAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class AActor*                           InTargetAvatar                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// struct FAttributeModifierHandle         ModifierHandle                                         (ConstParm, Parm, OutParm, ReferenceParm, HasGetValueTypeHash)

void UPyWidget_HitIndicator::OnApplyTreat(class AActor* InSourceAvatar, class AActor* InTargetAvatar, const struct FAttributeModifierHandle& ModifierHandle)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "OnApplyTreat");

	Params::PyWidget_HitIndicator_OnApplyTreat Parms{};

	Parms.InSourceAvatar = InSourceAvatar;
	Parms.InTargetAvatar = InTargetAvatar;
	Parms.ModifierHandle = std::move(ModifierHandle);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.SetCharacter
// (Native, Public, BlueprintCallable)
// Parameters:
// class AMarvelBaseCharacter*             ViewingCharacter                                       (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_HitIndicator::SetCharacter(class AMarvelBaseCharacter* ViewingCharacter)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "SetCharacter");

	Params::PyWidget_HitIndicator_SetCharacter Parms{};

	Parms.ViewingCharacter = ViewingCharacter;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.OnViewingTargetChanged
// (Native, Public, BlueprintCallable)
// Parameters:
// class AActor*                           InActor                                                (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_HitIndicator::OnViewingTargetChanged(class AActor* InActor)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "OnViewingTargetChanged");

	Params::PyWidget_HitIndicator_OnViewingTargetChanged Parms{};

	Parms.InActor = InActor;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.Destruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_HitIndicator::Destruct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "Destruct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.Construct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_HitIndicator::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "Construct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitIndicator.OnInitialized
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_HitIndicator::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitIndicator", "OnInitialized");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_HitFeedBack.OnInitialized
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_HitFeedBack::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_HitFeedBack", "OnInitialized");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_HitIndicator.PyWidget_Healing.OnAnimationFinished
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWidgetAnimation*                 Animation                                              (ConstParm, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_Healing::OnAnimationFinished(const class UWidgetAnimation* Animation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_Healing", "OnAnimationFinished");

	Params::PyWidget_Healing_OnAnimationFinished Parms{};

	Parms.Animation = Animation;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}

