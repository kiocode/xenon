#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_WeaponStatus

#include "Basic.hpp"

#include "PyWidget_WeaponStatus_classes.hpp"
#include "PyWidget_WeaponStatus_parameters.hpp"


namespace SDK
{

// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponAmmo.SetShowAmmoMax
// (Native, Public, BlueprintCallable)
// Parameters:
// bool                                    ShowAmmoMax_0                                          (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponAmmo::SetShowAmmoMax(bool ShowAmmoMax_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponAmmo", "SetShowAmmoMax");

	Params::PyWidget_WeaponAmmo_SetShowAmmoMax Parms{};

	Parms.ShowAmmoMax_0 = ShowAmmoMax_0;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponAmmo.SetIsInfinite
// (Native, Public, BlueprintCallable)
// Parameters:
// bool                                    IsInfinite_0                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponAmmo::SetIsInfinite(bool IsInfinite_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponAmmo", "SetIsInfinite");

	Params::PyWidget_WeaponAmmo_SetIsInfinite Parms{};

	Parms.IsInfinite_0 = IsInfinite_0;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponAmmo.SetAmmoCurrent
// (Native, Public, BlueprintCallable)
// Parameters:
// int32                                   AmmoCurrent_0                                          (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponAmmo::SetAmmoCurrent(int32 AmmoCurrent_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponAmmo", "SetAmmoCurrent");

	Params::PyWidget_WeaponAmmo_SetAmmoCurrent Parms{};

	Parms.AmmoCurrent_0 = AmmoCurrent_0;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponAmmo.SetAmmoMax
// (Native, Public, BlueprintCallable)
// Parameters:
// int32                                   AmmoMax_0                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponAmmo::SetAmmoMax(int32 AmmoMax_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponAmmo", "SetAmmoMax");

	Params::PyWidget_WeaponAmmo_SetAmmoMax Parms{};

	Parms.AmmoMax_0 = AmmoMax_0;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponAmmo.PreConstruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponAmmo::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponAmmo", "PreConstruct");

	Params::PyWidget_WeaponAmmo_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatusPanel.Destruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_WeaponStatusPanel::Destruct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatusPanel", "Destruct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatusPanel.SetMode
// (Native, Public, BlueprintCallable)
// Parameters:
// EHeroWeaponUIType                       InMode                                                 (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatusPanel::SetMode(EHeroWeaponUIType InMode)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatusPanel", "SetMode");

	Params::PyWidget_WeaponStatusPanel_SetMode Parms{};

	Parms.InMode = InMode;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatusPanel.RemoveWeaponWidget
// (Native, Public, BlueprintCallable)
// Parameters:
// class UPyWidget_WeaponStatus*           InWidget                                               (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatusPanel::RemoveWeaponWidget(class UPyWidget_WeaponStatus* InWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatusPanel", "RemoveWeaponWidget");

	Params::PyWidget_WeaponStatusPanel_RemoveWeaponWidget Parms{};

	Parms.InWidget = InWidget;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatusPanel.AddWeaponWidget
// (Native, Public, BlueprintCallable)
// Parameters:
// int32                                   InPriority                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UUserWidget*                      InWidget                                               (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatusPanel::AddWeaponWidget(int32 InPriority, class UUserWidget* InWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatusPanel", "AddWeaponWidget");

	Params::PyWidget_WeaponStatusPanel_AddWeaponWidget Parms{};

	Parms.InPriority = InPriority;
	Parms.InWidget = InWidget;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatusPanel.Reset
// (Native, Public, BlueprintCallable)

void UPyWidget_WeaponStatusPanel::Reset()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatusPanel", "Reset");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatusPanel.OnInitialized
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_WeaponStatusPanel::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatusPanel", "OnInitialized");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatusPanel.Construct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_WeaponStatusPanel::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatusPanel", "Construct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponIcon.Destruct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_WeaponIcon::Destruct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponIcon", "Destruct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponIcon.Construct
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_WeaponIcon::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponIcon", "Construct");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponIcon.OnInitialized
// (BlueprintCosmetic, Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_WeaponIcon::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponIcon", "OnInitialized");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetWeaponAction
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FUIActionData                    InWeapinAction                                         (Parm)

void UPyWidget_WeaponStatus::SetWeaponAction(const struct FUIActionData& InWeapinAction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetWeaponAction");

	Params::PyWidget_WeaponStatus_SetWeaponAction Parms{};

	Parms.InWeapinAction = std::move(InWeapinAction);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetEquipAction
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             InEquipAction                                          (ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetEquipAction(const class FName InEquipAction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetEquipAction");

	Params::PyWidget_WeaponStatus_SetEquipAction Parms{};

	Parms.InEquipAction = InEquipAction;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetIsPrimary
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bInPrimary                                             (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetIsPrimary(bool bInPrimary)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetIsPrimary");

	Params::PyWidget_WeaponStatus_SetIsPrimary Parms{};

	Parms.bInPrimary = bInPrimary;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetInfinite
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bInInfinite                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetInfinite(bool bInInfinite)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetInfinite");

	Params::PyWidget_WeaponStatus_SetInfinite Parms{};

	Parms.bInInfinite = bInInfinite;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetAbility
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UMarvelGameplayAbility*           InAbility                                              (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetAbility(class UMarvelGameplayAbility* InAbility)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetAbility");

	Params::PyWidget_WeaponStatus_SetAbility Parms{};

	Parms.InAbility = InAbility;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.OnIconLoaded
// (Native, Public, BlueprintCallable)
// Parameters:
// class UObject*                          Icon                                                   (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::OnIconLoaded(class UObject* Icon)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "OnIconLoaded");

	Params::PyWidget_WeaponStatus_OnIconLoaded Parms{};

	Parms.Icon = Icon;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetWeaponIconFromSoftObject
// (Native, Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TSoftObjectPtr<class UTexture2D>        WeaponIcon                                             (ConstParm, Parm, OutParm, ReferenceParm, UObjectWrapper, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetWeaponIconFromSoftObject(const TSoftObjectPtr<class UTexture2D>& WeaponIcon)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetWeaponIconFromSoftObject");

	Params::PyWidget_WeaponStatus_SetWeaponIconFromSoftObject Parms{};

	Parms.WeaponIcon = WeaponIcon;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetWeaponIcon
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UTexture2D*                       WeaponIcon                                             (Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetWeaponIcon(class UTexture2D* WeaponIcon)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetWeaponIcon");

	Params::PyWidget_WeaponStatus_SetWeaponIcon Parms{};

	Parms.WeaponIcon = WeaponIcon;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetUsable
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bInUsable                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetUsable(bool bInUsable)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetUsable");

	Params::PyWidget_WeaponStatus_SetUsable Parms{};

	Parms.bInUsable = bInUsable;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetEquiping
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bInEquiping                                            (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetEquiping(bool bInEquiping)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetEquiping");

	Params::PyWidget_WeaponStatus_SetEquiping Parms{};

	Parms.bInEquiping = bInEquiping;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetAmmoMax
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   InAmmoMax                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetAmmoMax(int32 InAmmoMax)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetAmmoMax");

	Params::PyWidget_WeaponStatus_SetAmmoMax Parms{};

	Parms.InAmmoMax = InAmmoMax;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.SetAmmoCur
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   InAmmoCur                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UPyWidget_WeaponStatus::SetAmmoCur(int32 InAmmoCur)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "SetAmmoCur");

	Params::PyWidget_WeaponStatus_SetAmmoCur Parms{};

	Parms.InAmmoCur = InAmmoCur;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// PythonFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.Reset
// (Native, Event, Protected, BlueprintCallable, BlueprintEvent)

void UPyWidget_WeaponStatus::Reset()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "Reset");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// DelegateFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.OnUsableUpdate__DelegateSignature
// (MulticastDelegate, Public, Delegate)

void UPyWidget_WeaponStatus::OnUsableUpdate__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "OnUsableUpdate__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// DelegateFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.OnEquipingUpdate__DelegateSignature
// (MulticastDelegate, Public, Delegate)

void UPyWidget_WeaponStatus::OnEquipingUpdate__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "OnEquipingUpdate__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// DelegateFunction PyWidget_WeaponStatus.PyWidget_WeaponStatus.OnAmmoUpdate__DelegateSignature
// (MulticastDelegate, Public, Delegate)

void UPyWidget_WeaponStatus::OnAmmoUpdate__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("PyWidget_WeaponStatus", "OnAmmoUpdate__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}

}

