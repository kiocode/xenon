#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_DropDownList_ListView_Item

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "CoreUObject_classes.hpp"
#include "PyWidget_Button_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_DropDownList_ListView_Item.PyWidget_DropDownList_ItemData
// 0x0078 (0x00A8 - 0x0030)
class UPyWidget_DropDownList_ItemData : public UObject
{
public:
	class UUserWidget*                            MainPanel;                                         // 0x0030(0x0008)(Edit, BlueprintVisible, ExportObject, ZeroConstructor, DisableEditOnInstance, InstancedReference, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         ItemId;                                            // 0x0038(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_3C[0x4];                                       // 0x003C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   ItemText;                                          // 0x0040(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	bool                                          IsShowColorImg;                                    // 0x0058(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_59[0x7];                                       // 0x0059(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UTexture2D*                             ItemIcon;                                          // 0x0060(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         ItemHeroID;                                        // 0x0068(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLinearColor                           ItemColor;                                         // 0x006C(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLinearColor                           ItemLeftColor;                                     // 0x007C(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_8C[0x4];                                       // 0x008C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 ItemCustomeTag;                                    // 0x0090(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         ItemPlatformID;                                    // 0x00A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_DropDownList_ItemData">();
	}
	static class UPyWidget_DropDownList_ItemData* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_DropDownList_ItemData>();
	}
};
static_assert(alignof(UPyWidget_DropDownList_ItemData) == 0x000008, "Wrong alignment on UPyWidget_DropDownList_ItemData");
static_assert(sizeof(UPyWidget_DropDownList_ItemData) == 0x0000A8, "Wrong size on UPyWidget_DropDownList_ItemData");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, MainPanel) == 0x000030, "Member 'UPyWidget_DropDownList_ItemData::MainPanel' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, ItemId) == 0x000038, "Member 'UPyWidget_DropDownList_ItemData::ItemId' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, ItemText) == 0x000040, "Member 'UPyWidget_DropDownList_ItemData::ItemText' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, IsShowColorImg) == 0x000058, "Member 'UPyWidget_DropDownList_ItemData::IsShowColorImg' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, ItemIcon) == 0x000060, "Member 'UPyWidget_DropDownList_ItemData::ItemIcon' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, ItemHeroID) == 0x000068, "Member 'UPyWidget_DropDownList_ItemData::ItemHeroID' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, ItemColor) == 0x00006C, "Member 'UPyWidget_DropDownList_ItemData::ItemColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, ItemLeftColor) == 0x00007C, "Member 'UPyWidget_DropDownList_ItemData::ItemLeftColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, ItemCustomeTag) == 0x000090, "Member 'UPyWidget_DropDownList_ItemData::ItemCustomeTag' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ItemData, ItemPlatformID) == 0x0000A0, "Member 'UPyWidget_DropDownList_ItemData::ItemPlatformID' has a wrong offset!");

// PythonClass PyWidget_DropDownList_ListView_Item.PyWidget_DropDownList_ListView_Item
// 0x0040 (0x0790 - 0x0750)
class UPyWidget_DropDownList_ListView_Item : public UPyWidget_Button
{
public:
	class UObject*                                ItemObject;                                        // 0x0750(0x0008)(BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UNamedSlot*                             Slot_NewReddot;                                    // 0x0758(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnItemClicked;                                     // 0x0760(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnItemHovered;                                     // 0x0770(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnItemPressed;                                     // 0x0780(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnItemClicked__DelegateSignature(class UObject* ItemData);
	void OnItemHovered__DelegateSignature(bool IsHover_0, float ItemId);
	void OnItemPressed__DelegateSignature(bool IsPressed, float ItemId);
	void OnInitialized();
	void Destruct();
	void PreConstruct(bool IsDesignTime);
	void SetBtnIsPressed(bool IsBtnPressed_0);
	void SetIsHover(bool IsHover_0);
	void SetItemData(class UObject* ListItemObject);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_DropDownList_ListView_Item">();
	}
	static class UPyWidget_DropDownList_ListView_Item* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_DropDownList_ListView_Item>();
	}
};
static_assert(alignof(UPyWidget_DropDownList_ListView_Item) == 0x000008, "Wrong alignment on UPyWidget_DropDownList_ListView_Item");
static_assert(sizeof(UPyWidget_DropDownList_ListView_Item) == 0x000790, "Wrong size on UPyWidget_DropDownList_ListView_Item");
static_assert(offsetof(UPyWidget_DropDownList_ListView_Item, ItemObject) == 0x000750, "Member 'UPyWidget_DropDownList_ListView_Item::ItemObject' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ListView_Item, Slot_NewReddot) == 0x000758, "Member 'UPyWidget_DropDownList_ListView_Item::Slot_NewReddot' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ListView_Item, OnItemClicked) == 0x000760, "Member 'UPyWidget_DropDownList_ListView_Item::OnItemClicked' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ListView_Item, OnItemHovered) == 0x000770, "Member 'UPyWidget_DropDownList_ListView_Item::OnItemHovered' has a wrong offset!");
static_assert(offsetof(UPyWidget_DropDownList_ListView_Item, OnItemPressed) == 0x000780, "Member 'UPyWidget_DropDownList_ListView_Item::OnItemPressed' has a wrong offset!");

}

