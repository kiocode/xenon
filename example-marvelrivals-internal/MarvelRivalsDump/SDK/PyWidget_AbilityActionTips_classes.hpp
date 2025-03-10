#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_AbilityActionTips

#include "Basic.hpp"

#include "DeclarativeUnreal_structs.hpp"
#include "Marvel_classes.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK
{

// PythonClass PyWidget_AbilityActionTips.PyWidget_CommonAbilityActionTip
// 0x0000 (0x05B8 - 0x05B8)
class UPyWidget_CommonAbilityActionTip : public UWidget_AbilityActionTip
{
public:
	void Construct();
	void SetHintText(const class FText& InText);
	void SetStyle(const struct FWidget_ActionTip& Style);
	void SetAction(const class FString& InActionName);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_CommonAbilityActionTip">();
	}
	static class UPyWidget_CommonAbilityActionTip* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_CommonAbilityActionTip>();
	}
};
static_assert(alignof(UPyWidget_CommonAbilityActionTip) == 0x000008, "Wrong alignment on UPyWidget_CommonAbilityActionTip");
static_assert(sizeof(UPyWidget_CommonAbilityActionTip) == 0x0005B8, "Wrong size on UPyWidget_CommonAbilityActionTip");

// PythonClass PyWidget_AbilityActionTips.PyWidget_CommonAbilityActionTips
// 0x0040 (0x05F8 - 0x05B8)
class UPyWidget_CommonAbilityActionTips : public UWidget_AbilityActionTips
{
public:
	class UMarvelKeyUIAsset*                      UIKeyAsset;                                        // 0x05B8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FGameplayTag                           Tag_UseOuterLeftActionTip;                         // 0x05C0(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FGameplayTag                           Tag_UseOuterRightActionTip;                        // 0x05CC(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FDeclarationHolder                     ViewingCharacterHolder;                            // 0x05D8(0x0010)(NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnTipAdded;                                        // 0x05E8(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnTipAdded__DelegateSignature();
	void OnInitialized();
	void OnViewTargetInputTypeChanged();
	void Reset();
	void SetVisible(bool bVisible_0);
	void AddTips(const int32 InAbilityId, const struct FWidget_ActionTip& Tips);
	void RemoveTips(const int32 InAbilityId);
	void RemoveOnlyTips(const int32 InAbilityId, const struct FWidget_ActionTip& Tips);
	void AddTipsByActionTipsParam(const int32 IndexID, const struct FActionTipsParam& Tips);
	void RemoveOnlyTipsByActionTipsParam(const int32 IndexID, const struct FActionTipsParam& Tips);
	void Update();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_CommonAbilityActionTips">();
	}
	static class UPyWidget_CommonAbilityActionTips* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_CommonAbilityActionTips>();
	}
};
static_assert(alignof(UPyWidget_CommonAbilityActionTips) == 0x000008, "Wrong alignment on UPyWidget_CommonAbilityActionTips");
static_assert(sizeof(UPyWidget_CommonAbilityActionTips) == 0x0005F8, "Wrong size on UPyWidget_CommonAbilityActionTips");
static_assert(offsetof(UPyWidget_CommonAbilityActionTips, UIKeyAsset) == 0x0005B8, "Member 'UPyWidget_CommonAbilityActionTips::UIKeyAsset' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonAbilityActionTips, Tag_UseOuterLeftActionTip) == 0x0005C0, "Member 'UPyWidget_CommonAbilityActionTips::Tag_UseOuterLeftActionTip' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonAbilityActionTips, Tag_UseOuterRightActionTip) == 0x0005CC, "Member 'UPyWidget_CommonAbilityActionTips::Tag_UseOuterRightActionTip' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonAbilityActionTips, ViewingCharacterHolder) == 0x0005D8, "Member 'UPyWidget_CommonAbilityActionTips::ViewingCharacterHolder' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonAbilityActionTips, OnTipAdded) == 0x0005E8, "Member 'UPyWidget_CommonAbilityActionTips::OnTipAdded' has a wrong offset!");

}

