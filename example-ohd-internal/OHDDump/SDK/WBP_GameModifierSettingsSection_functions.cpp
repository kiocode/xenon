#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_GameModifierSettingsSection

#include "Basic.hpp"

#include "WBP_GameModifierSettingsSection_classes.hpp"
#include "WBP_GameModifierSettingsSection_parameters.hpp"


namespace SDK
{

// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.OnActivated__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UWBP_GameModifierSettingsSection_C::OnActivated__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "OnActivated__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.OnDeactivated__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UWBP_GameModifierSettingsSection_C::OnDeactivated__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "OnDeactivated__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.ExecuteUbergraph_WBP_GameModifierSettingsSection
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_GameModifierSettingsSection_C::ExecuteUbergraph_WBP_GameModifierSettingsSection(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "ExecuteUbergraph_WBP_GameModifierSettingsSection");

	Params::WBP_GameModifierSettingsSection_C_ExecuteUbergraph_WBP_GameModifierSettingsSection Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.BndEvt__SectionActiveToggleChkBox_K2Node_ComponentBoundEvent_0_OnCheckBoxComponentStateChanged__DelegateSignature
// (BlueprintEvent)
// Parameters:
// bool                                    bIsChecked                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_GameModifierSettingsSection_C::BndEvt__SectionActiveToggleChkBox_K2Node_ComponentBoundEvent_0_OnCheckBoxComponentStateChanged__DelegateSignature(bool bIsChecked)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "BndEvt__SectionActiveToggleChkBox_K2Node_ComponentBoundEvent_0_OnCheckBoxComponentStateChanged__DelegateSignature");

	Params::WBP_GameModifierSettingsSection_C_BndEvt__SectionActiveToggleChkBox_K2Node_ComponentBoundEvent_0_OnCheckBoxComponentStateChanged__DelegateSignature Parms{};

	Parms.bIsChecked = bIsChecked;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.BndEvt__SectionExpansionToggleBtn_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature
// (BlueprintEvent)

void UWBP_GameModifierSettingsSection_C::BndEvt__SectionExpansionToggleBtn_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "BndEvt__SectionExpansionToggleBtn_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_GameModifierSettingsSection_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "PreConstruct");

	Params::WBP_GameModifierSettingsSection_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.SetTitleText
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             InTitleText                                            (BlueprintVisible, BlueprintReadOnly, Parm)

void UWBP_GameModifierSettingsSection_C::SetTitleText(const class FText& InTitleText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "SetTitleText");

	Params::WBP_GameModifierSettingsSection_C_SetTitleText Parms{};

	Parms.InTitleText = std::move(InTitleText);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.SetExpansionState
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bExpanded_0                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_GameModifierSettingsSection_C::SetExpansionState(bool bExpanded_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "SetExpansionState");

	Params::WBP_GameModifierSettingsSection_C_SetExpansionState Parms{};

	Parms.bExpanded_0 = bExpanded_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.SetIsActive
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bActive_0                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_GameModifierSettingsSection_C::SetIsActive(bool bActive_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "SetIsActive");

	Params::WBP_GameModifierSettingsSection_C_SetIsActive Parms{};

	Parms.bActive_0 = bActive_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.GetTitleText
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FText                             TitleText_0                                            (Parm, OutParm)

void UWBP_GameModifierSettingsSection_C::GetTitleText(class FText* TitleText_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "GetTitleText");

	Params::WBP_GameModifierSettingsSection_C_GetTitleText Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (TitleText_0 != nullptr)
		*TitleText_0 = std::move(Parms.TitleText_0);
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.IsExpanded
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    bExpanded_0                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_GameModifierSettingsSection_C::IsExpanded(bool* bExpanded_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "IsExpanded");

	Params::WBP_GameModifierSettingsSection_C_IsExpanded Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (bExpanded_0 != nullptr)
		*bExpanded_0 = Parms.bExpanded_0;
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.IsActive
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    bActive_0                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_GameModifierSettingsSection_C::IsActive(bool* bActive_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "IsActive");

	Params::WBP_GameModifierSettingsSection_C_IsActive Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (bActive_0 != nullptr)
		*bActive_0 = Parms.bActive_0;
}


// Function WBP_GameModifierSettingsSection.WBP_GameModifierSettingsSection_C.InternalRecursiveSetContentIsEnabled
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bInIsEnabled                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_GameModifierSettingsSection_C::InternalRecursiveSetContentIsEnabled(bool bInIsEnabled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_GameModifierSettingsSection_C", "InternalRecursiveSetContentIsEnabled");

	Params::WBP_GameModifierSettingsSection_C_InternalRecursiveSetContentIsEnabled Parms{};

	Parms.bInIsEnabled = bInIsEnabled;

	UObject::ProcessEvent(Func, &Parms);
}

}

