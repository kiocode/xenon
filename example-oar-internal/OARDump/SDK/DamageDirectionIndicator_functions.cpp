#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DamageDirectionIndicator

#include "Basic.hpp"

#include "DamageDirectionIndicator_classes.hpp"
#include "DamageDirectionIndicator_parameters.hpp"


namespace SDK
{

// Function DamageDirectionIndicator.DamageDirectionIndicator_C.ExecuteUbergraph_DamageDirectionIndicator
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDamageDirectionIndicator_C::ExecuteUbergraph_DamageDirectionIndicator(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DamageDirectionIndicator_C", "ExecuteUbergraph_DamageDirectionIndicator");

	Params::DamageDirectionIndicator_C_ExecuteUbergraph_DamageDirectionIndicator Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function DamageDirectionIndicator.DamageDirectionIndicator_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UDamageDirectionIndicator_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DamageDirectionIndicator_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function DamageDirectionIndicator.DamageDirectionIndicator_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UDamageDirectionIndicator_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("DamageDirectionIndicator_C", "Tick");

	Params::DamageDirectionIndicator_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}

}

