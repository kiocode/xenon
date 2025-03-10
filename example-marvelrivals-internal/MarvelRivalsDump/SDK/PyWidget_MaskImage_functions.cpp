#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_MaskImage

#include "Basic.hpp"

#include "PyWidget_MaskImage_classes.hpp"
#include "PyWidget_MaskImage_parameters.hpp"


namespace SDK
{

// PythonFunction PyWidget_MaskImage.PyWidget_MaskImage.OnSoftTextureLoad
// (Native, Public, BlueprintCallable)
// Parameters:
// class UObject*                          Texture_0                                              (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_MaskImage::OnSoftTextureLoad(class UObject* Texture_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_MaskImage", "OnSoftTextureLoad");

	Params::PyWidget_MaskImage_OnSoftTextureLoad Parms{};

	Parms.Texture_0 = Texture_0;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_MaskImage.PyWidget_MaskImage.SetTexture
// (Native, Public, BlueprintCallable)
// Parameters:
// class UTexture2D*                       Texture_0                                              (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_MaskImage::SetTexture(class UTexture2D* Texture_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_MaskImage", "SetTexture");

	Params::PyWidget_MaskImage_SetTexture Parms{};

	Parms.Texture_0 = Texture_0;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_MaskImage.PyWidget_MaskImage.PreConstruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_MaskImage::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_MaskImage", "PreConstruct");

	Params::PyWidget_MaskImage_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_MaskImage.PyWidget_MaskImage.Construct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_MaskImage::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_MaskImage", "Construct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_MaskImage.PyWidget_MaskImage.OnInitialized
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_MaskImage::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_MaskImage", "OnInitialized");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// DelegateFunction PyWidget_MaskImage.PyWidget_MaskImage.OnPictureLoadCompleted__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// class UTexture2D*                       Picture                                                (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_MaskImage::OnPictureLoadCompleted__DelegateSignature(class UTexture2D* Picture)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_MaskImage", "OnPictureLoadCompleted__DelegateSignature");

	Params::PyWidget_MaskImage_OnPictureLoadCompleted__DelegateSignature Parms{};

	Parms.Picture = Picture;

	UObject::ProcessEvent(Func, &Parms);
}

}

