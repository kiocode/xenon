#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PySubVoMgr_Escort

#include "Basic.hpp"

#include "PySubVoMgr_Escort_classes.hpp"
#include "PySubVoMgr_Escort_parameters.hpp"


namespace SDK
{

// PythonFunction PySubVoMgr_Escort.PySubVoMgr_Escort.OnPayloadOwnerSideChanged
// (Native, Public, BlueprintCallable)
// Parameters:
// class AActor*                           Control_base                                           (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// EOwnershipType                          Owner_side                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPySubVoMgr_Escort::OnPayloadOwnerSideChanged(class AActor* Control_base, EOwnershipType Owner_side)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PySubVoMgr_Escort", "OnPayloadOwnerSideChanged");

	Params::PySubVoMgr_Escort_OnPayloadOwnerSideChanged Parms{};

	Parms.Control_base = Control_base;
	Parms.Owner_side = Owner_side;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}

