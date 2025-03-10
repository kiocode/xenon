#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_MainMenu

#include "Basic.hpp"

#include "WBP_MainMenu_classes.hpp"
#include "WBP_MainMenu_parameters.hpp"


namespace SDK
{

// Function WBP_MainMenu.WBP_MainMenu_C.ExecuteUbergraph_WBP_MainMenu
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::ExecuteUbergraph_WBP_MainMenu(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "ExecuteUbergraph_WBP_MainMenu");

	Params::WBP_MainMenu_C_ExecuteUbergraph_WBP_MainMenu Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.BndEvt__PauseExitGameNavBtn_K2Node_ComponentBoundEvent_0_ButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UWBP_MainMenu_NavBarButton_C*     ClickedBtn                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::BndEvt__PauseExitGameNavBtn_K2Node_ComponentBoundEvent_0_ButtonClicked__DelegateSignature(class UWBP_MainMenu_NavBarButton_C* ClickedBtn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "BndEvt__PauseExitGameNavBtn_K2Node_ComponentBoundEvent_0_ButtonClicked__DelegateSignature");

	Params::WBP_MainMenu_C_BndEvt__PauseExitGameNavBtn_K2Node_ComponentBoundEvent_0_ButtonClicked__DelegateSignature Parms{};

	Parms.ClickedBtn = ClickedBtn;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.BndEvt__ExitGameNavBtn_K2Node_ComponentBoundEvent_4_ButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UWBP_MainMenu_NavBarButton_C*     ClickedBtn                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::BndEvt__ExitGameNavBtn_K2Node_ComponentBoundEvent_4_ButtonClicked__DelegateSignature(class UWBP_MainMenu_NavBarButton_C* ClickedBtn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "BndEvt__ExitGameNavBtn_K2Node_ComponentBoundEvent_4_ButtonClicked__DelegateSignature");

	Params::WBP_MainMenu_C_BndEvt__ExitGameNavBtn_K2Node_ComponentBoundEvent_4_ButtonClicked__DelegateSignature Parms{};

	Parms.ClickedBtn = ClickedBtn;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.OnInitialized
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWBP_MainMenu_C::OnInitialized()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "OnInitialized");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.BndEvt__ShootingRangeNavBtn_K2Node_ComponentBoundEvent_2_ButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UWBP_MainMenu_NavBarButton_C*     ClickedBtn                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::BndEvt__ShootingRangeNavBtn_K2Node_ComponentBoundEvent_2_ButtonClicked__DelegateSignature(class UWBP_MainMenu_NavBarButton_C* ClickedBtn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "BndEvt__ShootingRangeNavBtn_K2Node_ComponentBoundEvent_2_ButtonClicked__DelegateSignature");

	Params::WBP_MainMenu_C_BndEvt__ShootingRangeNavBtn_K2Node_ComponentBoundEvent_2_ButtonClicked__DelegateSignature Parms{};

	Parms.ClickedBtn = ClickedBtn;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.OnPauseMenuPressed
// (BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::OnPauseMenuPressed()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "OnPauseMenuPressed");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.OnSubNavBtnClicked
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWBP_MenuSubNavSelectionListEntry_C*ClickedBtn                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::OnSubNavBtnClicked(class UWBP_MenuSubNavSelectionListEntry_C* ClickedBtn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "OnSubNavBtnClicked");

	Params::WBP_MainMenu_C_OnSubNavBtnClicked Parms{};

	Parms.ClickedBtn = ClickedBtn;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.BndEvt__ReturnToMenuNavBtn_K2Node_ComponentBoundEvent_12_ButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UWBP_MainMenu_NavBarButton_C*     ClickedBtn                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::BndEvt__ReturnToMenuNavBtn_K2Node_ComponentBoundEvent_12_ButtonClicked__DelegateSignature(class UWBP_MainMenu_NavBarButton_C* ClickedBtn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "BndEvt__ReturnToMenuNavBtn_K2Node_ComponentBoundEvent_12_ButtonClicked__DelegateSignature");

	Params::WBP_MainMenu_C_BndEvt__ReturnToMenuNavBtn_K2Node_ComponentBoundEvent_12_ButtonClicked__DelegateSignature Parms{};

	Parms.ClickedBtn = ClickedBtn;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_MainMenu_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "PreConstruct");

	Params::WBP_MainMenu_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.BndEvt__ResumeNavBtn_K2Node_ComponentBoundEvent_11_ButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UWBP_MainMenu_NavBarButton_C*     ClickedBtn                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::BndEvt__ResumeNavBtn_K2Node_ComponentBoundEvent_11_ButtonClicked__DelegateSignature(class UWBP_MainMenu_NavBarButton_C* ClickedBtn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "BndEvt__ResumeNavBtn_K2Node_ComponentBoundEvent_11_ButtonClicked__DelegateSignature");

	Params::WBP_MainMenu_C_BndEvt__ResumeNavBtn_K2Node_ComponentBoundEvent_11_ButtonClicked__DelegateSignature Parms{};

	Parms.ClickedBtn = ClickedBtn;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.OnNavBtnClicked
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWBP_MainMenu_NavBarButton_C*     ClickedBtn                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::OnNavBtnClicked(class UWBP_MainMenu_NavBarButton_C* ClickedBtn)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "OnNavBtnClicked");

	Params::WBP_MainMenu_C_OnNavBtnClicked Parms{};

	Parms.ClickedBtn = ClickedBtn;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWBP_MainMenu_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.InitMenuState
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bIsDesignTime                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_MainMenu_C::InitMenuState(bool bIsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "InitMenuState");

	Params::WBP_MainMenu_C_InitMenuState Parms{};

	Parms.bIsDesignTime = bIsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.SetupMenuBackgroundWidget
// (Protected, BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::SetupMenuBackgroundWidget()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "SetupMenuBackgroundWidget");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.SetupNavBarClickEvents
// (Private, BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::SetupNavBarClickEvents()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "SetupNavBarClickEvents");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.SetActiveMenu
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   NewIndex                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UClass*                           NewOptionMenuClass                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_MainMenu_C::SetActiveMenu(int32 NewIndex, class UClass* NewOptionMenuClass, bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "SetActiveMenu");

	Params::WBP_MainMenu_C_SetActiveMenu Parms{};

	Parms.NewIndex = NewIndex;
	Parms.NewOptionMenuClass = NewOptionMenuClass;
	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.SetupCopyrightNotice
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::SetupCopyrightNotice()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "SetupCopyrightNotice");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.GetNavBtnCount
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// int32                                   Count                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::GetNavBtnCount(int32* Count)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "GetNavBtnCount");

	Params::WBP_MainMenu_C_GetNavBtnCount Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Count != nullptr)
		*Count = Parms.Count;
}


// Function WBP_MainMenu.WBP_MainMenu_C.SetOptionMenu
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UClass*                           NewOptionMenuClass                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_MainMenu_C::SetOptionMenu(class UClass* NewOptionMenuClass, bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "SetOptionMenu");

	Params::WBP_MainMenu_C_SetOptionMenu Parms{};

	Parms.NewOptionMenuClass = NewOptionMenuClass;
	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.GetNavBarHBox
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UHorizontalBox*                   HBoxToUse                                              (Parm, OutParm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_MainMenu_C::GetNavBarHBox(class UHorizontalBox** HBoxToUse)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "GetNavBarHBox");

	Params::WBP_MainMenu_C_GetNavBarHBox Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (HBoxToUse != nullptr)
		*HBoxToUse = Parms.HBoxToUse;
}


// Function WBP_MainMenu.WBP_MainMenu_C.UpdateSubNavBarOptions
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// TScriptInterface<class IBPI_OptionMenu_C>NewOptionMenu                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_MainMenu_C::UpdateSubNavBarOptions(TScriptInterface<class IBPI_OptionMenu_C> NewOptionMenu)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "UpdateSubNavBarOptions");

	Params::WBP_MainMenu_C_UpdateSubNavBarOptions Parms{};

	Parms.NewOptionMenu = NewOptionMenu;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.ClearSubNavBarOptions
// (Private, BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::ClearSubNavBarOptions()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "ClearSubNavBarOptions");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.PopulateSubNavBar
// (Private, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<struct FFSubMenuOption>          SubMenuOptions                                         (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, HasGetValueTypeHash)

void UWBP_MainMenu_C::PopulateSubNavBar(TArray<struct FFSubMenuOption>& SubMenuOptions)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "PopulateSubNavBar");

	Params::WBP_MainMenu_C_PopulateSubNavBar Parms{};

	Parms.SubMenuOptions = std::move(SubMenuOptions);

	UObject::ProcessEvent(Func, &Parms);

	SubMenuOptions = std::move(Parms.SubMenuOptions);
}


// Function WBP_MainMenu.WBP_MainMenu_C.ClearCurrentOptionMenu
// (Private, BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::ClearCurrentOptionMenu()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "ClearCurrentOptionMenu");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.ToggleSubNavBar
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bNewVisible                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWBP_MainMenu_C::ToggleSubNavBar(bool bNewVisible)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "ToggleSubNavBar");

	Params::WBP_MainMenu_C_ToggleSubNavBar Parms{};

	Parms.bNewVisible = bNewVisible;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_MainMenu.WBP_MainMenu_C.SetupSubNavBarClickEvents
// (Private, BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::SetupSubNavBarClickEvents()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "SetupSubNavBarClickEvents");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.TeardownSubNavBarClickEvents
// (Private, BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::TeardownSubNavBarClickEvents()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "TeardownSubNavBarClickEvents");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_MainMenu.WBP_MainMenu_C.OnMouseButtonDown
// (BlueprintCosmetic, Event, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UWBP_MainMenu_C::OnMouseButtonDown(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "OnMouseButtonDown");

	Params::WBP_MainMenu_C_OnMouseButtonDown Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WBP_MainMenu.WBP_MainMenu_C.OnMouseWheel
// (BlueprintCosmetic, Event, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UWBP_MainMenu_C::OnMouseWheel(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "OnMouseWheel");

	Params::WBP_MainMenu_C_OnMouseWheel Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WBP_MainMenu.WBP_MainMenu_C.PlayMenuMusic
// (Protected, BlueprintCallable, BlueprintEvent)

void UWBP_MainMenu_C::PlayMenuMusic()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_MainMenu_C", "PlayMenuMusic");

	UObject::ProcessEvent(Func, nullptr);
}

}

