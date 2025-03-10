#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_Common_NavigationBar_Info

#include "Basic.hpp"

#include "PyWidget_Common_NavigationBar_Info_classes.hpp"
#include "PyWidget_Common_NavigationBar_Info_parameters.hpp"


namespace SDK
{

// DelegateFunction PyWidget_Common_NavigationBar_Info.PyWidget_Common_NavigationBar_InfoBase.OnNavClicked__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// int32                                   Index_0                                                (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_Common_NavigationBar_InfoBase::OnNavClicked__DelegateSignature(int32 Index_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_Common_NavigationBar_InfoBase", "OnNavClicked__DelegateSignature");

	Params::PyWidget_Common_NavigationBar_InfoBase_OnNavClicked__DelegateSignature Parms{};

	Parms.Index_0 = Index_0;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_Common_NavigationBar_Info.PyWidget_Common_NavigationBar_InfoBase.OnNavHovered__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// int32                                   Index_0                                                (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_Common_NavigationBar_InfoBase::OnNavHovered__DelegateSignature(int32 Index_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_Common_NavigationBar_InfoBase", "OnNavHovered__DelegateSignature");

	Params::PyWidget_Common_NavigationBar_InfoBase_OnNavHovered__DelegateSignature Parms{};

	Parms.Index_0 = Index_0;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_Common_NavigationBar_Info.PyWidget_Common_NavigationBar_InfoBase.OnNavCreated__DelegateSignature
// (MulticastDelegate, Public, Delegate)

void UPyWidget_Common_NavigationBar_InfoBase::OnNavCreated__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_Common_NavigationBar_InfoBase", "OnNavCreated__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// PythonFunction PyWidget_Common_NavigationBar_Info.PyWidget_Common_NavigationBar_InfoBase.OnInitialized
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_Common_NavigationBar_InfoBase::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_Common_NavigationBar_InfoBase", "OnInitialized");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_Common_NavigationBar_Info.PyWidget_Common_NavigationBar_InfoBase.PreConstruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_Common_NavigationBar_InfoBase::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_Common_NavigationBar_InfoBase", "PreConstruct");

	Params::PyWidget_Common_NavigationBar_InfoBase_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_Common_NavigationBar_Info.PyWidget_Common_NavigationBar_SecondInfo.OnInitialized
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_Common_NavigationBar_SecondInfo::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_Common_NavigationBar_SecondInfo", "OnInitialized");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_Common_NavigationBar_Info.PyWidget_Common_NavigationBar_SecondInfo.Destruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_Common_NavigationBar_SecondInfo::Destruct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_Common_NavigationBar_SecondInfo", "Destruct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}

}

