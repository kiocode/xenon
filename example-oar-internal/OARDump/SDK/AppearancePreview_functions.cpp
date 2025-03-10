#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AppearancePreview

#include "Basic.hpp"

#include "AppearancePreview_classes.hpp"
#include "AppearancePreview_parameters.hpp"


namespace SDK
{

// Function AppearancePreview.AppearancePreview_C.Remove
// (Public, BlueprintCallable, BlueprintEvent)

void AAppearancePreview_C::Remove()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "Remove");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AppearancePreview.AppearancePreview_C.RemoveloadoutCategory
// (Public, BlueprintCallable, BlueprintEvent)

void AAppearancePreview_C::RemoveloadoutCategory()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "RemoveloadoutCategory");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AppearancePreview.AppearancePreview_C.ChangeCategory
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// EShopItemCategory                       Category                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAppearancePreview_C::ChangeCategory(EShopItemCategory Category)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "ChangeCategory");

	Params::AppearancePreview_C_ChangeCategory Parms{};

	Parms.Category = Category;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AppearancePreview.AppearancePreview_C.DragItemFromCategory
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// EShopItemCategory                       Category                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAppearancePreview_C::DragItemFromCategory(EShopItemCategory Category)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "DragItemFromCategory");

	Params::AppearancePreview_C_DragItemFromCategory Parms{};

	Parms.Category = Category;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AppearancePreview.AppearancePreview_C.CancelDrag
// (Public, BlueprintCallable, BlueprintEvent)

void AAppearancePreview_C::CancelDrag()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "CancelDrag");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AppearancePreview.AppearancePreview_C.PreviewItem
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UClass*                           ItemInfo                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   SalePrice                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAppearancePreview_C::PreviewItem(class UClass* ItemInfo, int32 SalePrice)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "PreviewItem");

	Params::AppearancePreview_C_PreviewItem Parms{};

	Parms.ItemInfo = ItemInfo;
	Parms.SalePrice = SalePrice;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AppearancePreview.AppearancePreview_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AAppearancePreview_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AppearancePreview.AppearancePreview_C.UpdateAppearance
// (BlueprintCallable, BlueprintEvent)

void AAppearancePreview_C::UpdateAppearance()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "UpdateAppearance");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AppearancePreview.AppearancePreview_C.RefreshInventory
// (Public, BlueprintCallable, BlueprintEvent)

void AAppearancePreview_C::RefreshInventory()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "RefreshInventory");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AppearancePreview.AppearancePreview_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAppearancePreview_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "ReceiveTick");

	Params::AppearancePreview_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function AppearancePreview.AppearancePreview_C.LoadController
// (BlueprintCallable, BlueprintEvent)

void AAppearancePreview_C::LoadController()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "LoadController");

	UObject::ProcessEvent(Func, nullptr);
}


// Function AppearancePreview.AppearancePreview_C.ExecuteUbergraph_AppearancePreview
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void AAppearancePreview_C::ExecuteUbergraph_AppearancePreview(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AppearancePreview_C", "ExecuteUbergraph_AppearancePreview");

	Params::AppearancePreview_C_ExecuteUbergraph_AppearancePreview Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}

