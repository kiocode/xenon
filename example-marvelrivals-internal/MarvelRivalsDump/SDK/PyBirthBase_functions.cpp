#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyBirthBase

#include "Basic.hpp"

#include "PyBirthBase_classes.hpp"
#include "PyBirthBase_parameters.hpp"


namespace SDK
{

// PythonFunction PyBirthBase.PyBirthBase.ReceiveBeginPlay
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void APyBirthBase::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "ReceiveBeginPlay");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.ReceiveEndPlay
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// EEndPlayReason                          EndPlayReason                                          (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APyBirthBase::ReceiveEndPlay(EEndPlayReason EndPlayReason)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "ReceiveEndPlay");

	Params::PyBirthBase_ReceiveEndPlay Parms{};

	Parms.EndPlayReason = EndPlayReason;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.K2_OnReset
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void APyBirthBase::K2_OnReset()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "K2_OnReset");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.RewindForReplayPy
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void APyBirthBase::RewindForReplayPy()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "RewindForReplayPy");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.Activate
// (Native, Public, BlueprintCallable)

void APyBirthBase::Activate()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "Activate");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.SWITCH
// (Native, Public, BlueprintCallable)

void APyBirthBase::SWITCH()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "SWITCH");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.Deactivate
// (Native, Public, BlueprintCallable)

void APyBirthBase::Deactivate()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "Deactivate");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.DispatchOnActiveChanged
// (Native, Public, BlueprintCallable)
// Parameters:
// class UObject*                          TaskOwner                                              (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// int64                                   Magnitude                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APyBirthBase::DispatchOnActiveChanged(class UObject* TaskOwner, int64 Magnitude)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "DispatchOnActiveChanged");

	Params::PyBirthBase_DispatchOnActiveChanged Parms{};

	Parms.TaskOwner = TaskOwner;
	Parms.Magnitude = Magnitude;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.OnRep_State
// (Native, Public, BlueprintCallable)

void APyBirthBase::OnRep_State()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "OnRep_State");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.SwitchEnd
// (Native, Public, BlueprintCallable)

void APyBirthBase::SwitchEnd()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "SwitchEnd");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.OpenDoors
// (Native, Public, BlueprintCallable)

void APyBirthBase::OpenDoors()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "OpenDoors");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.CloseDoors
// (Native, Public, BlueprintCallable)

void APyBirthBase::CloseDoors()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "CloseDoors");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyBirthBase.PyBirthBase.GetActive
// (Native, Public, HasOutParams, BlueprintCallable, BlueprintPure)
// Parameters:
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

bool APyBirthBase::GetActive()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "GetActive");

	Params::PyBirthBase_GetActive Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// PythonFunction PyBirthBase.PyBirthBase.SrvSetForceUpdateTransCache
// (Native, Public, BlueprintCallable)
// Parameters:
// bool                                    Force                                                  (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void APyBirthBase::SrvSetForceUpdateTransCache(bool Force)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyBirthBase", "SrvSetForceUpdateTransCache");

	Params::PyBirthBase_SrvSetForceUpdateTransCache Parms{};

	Parms.Force = Force;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}

}

