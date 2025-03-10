#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_CommonItemPanel

#include "Basic.hpp"

#include "PyWidget_CommonItemPanel_classes.hpp"
#include "PyWidget_CommonItemPanel_parameters.hpp"


namespace SDK
{

// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnShowItemChange__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// class FString                           ItemId                                                 (Parm, ZeroConstructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnShowItemChange__DelegateSignature(const class FString& ItemId)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnShowItemChange__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnShowItemChange__DelegateSignature Parms{};

	Parms.ItemId = std::move(ItemId);

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnHeroDataChange__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// int32                                   HeroID                                                 (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   SkinID                                                 (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ShapeID                                                (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnHeroDataChange__DelegateSignature(int32 HeroID, int32 SkinID, int32 ShapeID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnHeroDataChange__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnHeroDataChange__DelegateSignature Parms{};

	Parms.HeroID = HeroID;
	Parms.SkinID = SkinID;
	Parms.ShapeID = ShapeID;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnItemVisibleChange__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// bool                                    IsVisible_0                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnItemVisibleChange__DelegateSignature(bool IsVisible_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnItemVisibleChange__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnItemVisibleChange__DelegateSignature Parms{};

	Parms.IsVisible_0 = IsVisible_0;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnIsAppreciateChange__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// bool                                    IsAppreciate                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnIsAppreciateChange__DelegateSignature(bool IsAppreciate)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnIsAppreciateChange__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnIsAppreciateChange__DelegateSignature Parms{};

	Parms.IsAppreciate = IsAppreciate;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnSwitchHeroSkinCamera__DelegateSignature
// (MulticastDelegate, Public, Delegate)

void UPyWidget_CommonItemPanel::OnSwitchHeroSkinCamera__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnSwitchHeroSkinCamera__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnRotationHeroSkin__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// bool                                    IsRotation                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnRotationHeroSkin__DelegateSignature(bool IsRotation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnRotationHeroSkin__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnRotationHeroSkin__DelegateSignature Parms{};

	Parms.IsRotation = IsRotation;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnRotationItem__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// bool                                    IsRotation                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnRotationItem__DelegateSignature(bool IsRotation)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnRotationItem__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnRotationItem__DelegateSignature Parms{};

	Parms.IsRotation = IsRotation;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnHoveredHeroSkin__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// bool                                    IsHovered_0                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnHoveredHeroSkin__DelegateSignature(bool IsHovered_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnHoveredHeroSkin__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnHoveredHeroSkin__DelegateSignature Parms{};

	Parms.IsHovered_0 = IsHovered_0;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnHoveredItem__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// bool                                    IsHovered_0                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnHoveredItem__DelegateSignature(bool IsHovered_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnHoveredItem__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnHoveredItem__DelegateSignature Parms{};

	Parms.IsHovered_0 = IsHovered_0;

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnAnalogRotationItem__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// struct FVector2D                        Value                                                  (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnAnalogRotationItem__DelegateSignature(const struct FVector2D& Value)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnAnalogRotationItem__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnAnalogRotationItem__DelegateSignature Parms{};

	Parms.Value = std::move(Value);

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnSetShowLobbyItemID__DelegateSignature
// (MulticastDelegate, Public, Delegate)
// Parameters:
// class FString                           LobbyItemID                                            (Parm, ZeroConstructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::OnSetShowLobbyItemID__DelegateSignature(const class FString& LobbyItemID)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnSetShowLobbyItemID__DelegateSignature");

	Params::PyWidget_CommonItemPanel_OnSetShowLobbyItemID__DelegateSignature Parms{};

	Parms.LobbyItemID = std::move(LobbyItemID);

	UObject::ProcessEvent(Func, &Parms);
}


// DelegateFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnResetShowLobbyItemID__DelegateSignature
// (MulticastDelegate, Public, Delegate)

void UPyWidget_CommonItemPanel::OnResetShowLobbyItemID__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnResetShowLobbyItemID__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// PythonFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.OnInitialized
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_CommonItemPanel::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "OnInitialized");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.PreConstruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_CommonItemPanel::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "PreConstruct");

	Params::PyWidget_CommonItemPanel_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.Construct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_CommonItemPanel::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "Construct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_CommonItemPanel.PyWidget_CommonItemPanel.Destruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_CommonItemPanel::Destruct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_CommonItemPanel", "Destruct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}

}

