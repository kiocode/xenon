#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Instructioncomponent

#include "Basic.hpp"

#include "Instructioncomponent_classes.hpp"
#include "Instructioncomponent_parameters.hpp"


namespace SDK
{

// Function Instructioncomponent.Instructioncomponent_C.ExecuteUbergraph_Instructioncomponent
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UInstructioncomponent_C::ExecuteUbergraph_Instructioncomponent(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Instructioncomponent_C", "ExecuteUbergraph_Instructioncomponent");

	Params::Instructioncomponent_C_ExecuteUbergraph_Instructioncomponent Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Instructioncomponent.Instructioncomponent_C.NewInstructionMulti
// (Net, NetReliable, NetMulticast, BlueprintCallable, BlueprintEvent)

void UInstructioncomponent_C::NewInstructionMulti()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Instructioncomponent_C", "NewInstructionMulti");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Instructioncomponent.Instructioncomponent_C.OverrideInstruction
// (Public, BlueprintCallable, BlueprintEvent)

void UInstructioncomponent_C::OverrideInstruction()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Instructioncomponent_C", "OverrideInstruction");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Instructioncomponent.Instructioncomponent_C.NewInstruction
// (Public, BlueprintCallable, BlueprintEvent)

void UInstructioncomponent_C::NewInstruction()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Instructioncomponent_C", "NewInstruction");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Instructioncomponent.Instructioncomponent_C.AnnounceNewInstructionWidget
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Title                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void UInstructioncomponent_C::AnnounceNewInstructionWidget(const class FString& Title)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Instructioncomponent_C", "AnnounceNewInstructionWidget");

	Params::Instructioncomponent_C_AnnounceNewInstructionWidget Parms{};

	Parms.Title = std::move(Title);

	UObject::ProcessEvent(Func, &Parms);
}


// Function Instructioncomponent.Instructioncomponent_C.GetCurrentInstruction
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FInstructionStruct               Instruction                                            (Parm, OutParm, ZeroConstructor, HasGetValueTypeHash)

void UInstructioncomponent_C::GetCurrentInstruction(struct FInstructionStruct* Instruction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Instructioncomponent_C", "GetCurrentInstruction");

	Params::Instructioncomponent_C_GetCurrentInstruction Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Instruction != nullptr)
		*Instruction = std::move(Parms.Instruction);
}

}

