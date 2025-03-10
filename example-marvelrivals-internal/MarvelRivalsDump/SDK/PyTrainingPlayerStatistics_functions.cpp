#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyTrainingPlayerStatistics

#include "Basic.hpp"

#include "PyTrainingPlayerStatistics_classes.hpp"
#include "PyTrainingPlayerStatistics_parameters.hpp"


namespace SDK
{

// PythonFunction PyTrainingPlayerStatistics.PyTrainingPlayerStatistics.Initialize
// (Native, Public, BlueprintCallable)
// Parameters:
// class AMarvelPlayerState*               Player_state                                           (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyTrainingPlayerStatistics::Initialize(class AMarvelPlayerState* Player_state)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyTrainingPlayerStatistics", "Initialize");

	Params::PyTrainingPlayerStatistics_Initialize Parms{};

	Parms.Player_state = Player_state;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyTrainingPlayerStatistics.PyTrainingPlayerStatistics.Shutdown
// (Native, Public, BlueprintCallable)

void UPyTrainingPlayerStatistics::Shutdown()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyTrainingPlayerStatistics", "Shutdown");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}

}

