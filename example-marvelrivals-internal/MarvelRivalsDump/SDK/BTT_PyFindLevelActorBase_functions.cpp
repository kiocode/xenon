#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BTT_PyFindLevelActorBase

#include "Basic.hpp"

#include "BTT_PyFindLevelActorBase_classes.hpp"
#include "BTT_PyFindLevelActorBase_parameters.hpp"


namespace SDK
{

// PythonFunction BTT_PyFindLevelActorBase.BTT_PyFindLevelActorBase.ReceiveExecuteAI
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AAIController*                    OwnerController                                        (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class APawn*                            ControlledPawn                                         (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UBTT_PyFindLevelActorBase::ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BTT_PyFindLevelActorBase", "ReceiveExecuteAI");

	Params::BTT_PyFindLevelActorBase_ReceiveExecuteAI Parms{};

	Parms.OwnerController = OwnerController;
	Parms.ControlledPawn = ControlledPawn;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}

