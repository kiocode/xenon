#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_SelectHero_HeroListBtn

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "PyWidget_Button_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_SelectHero_HeroListBtn.PyWidget_SelectHero_HeroListBtn
// 0x00C8 (0x0818 - 0x0750)
class UPyWidget_SelectHero_HeroListBtn : public UPyWidget_Button
{
public:
	int32                                         HeroID;                                            // 0x0750(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsPreview;                                         // 0x0754(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsSelected;                                        // 0x0755(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsUnlock;                                          // 0x0756(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsSelectable;                                      // 0x0757(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsTeamSelected;                                    // 0x0758(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsBaned;                                           // 0x0759(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsPicked;                                          // 0x075A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          CanInteract;                                       // 0x075B(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BtnNormalOpacity;                                  // 0x075C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BtnSelectedOpacity;                                // 0x0760(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BtnLockAndTeamSelectedOpacity;                     // 0x0764(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BtnUnSelectableOpacity;                            // 0x0768(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_76C[0x4];                                      // 0x076C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UTexture2D*                             Btn_Default_Bg;                                    // 0x0770(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Hover_Bg;                                      // 0x0778(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Select_Bg;                                     // 0x0780(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Select_BanPick_Bg;                             // 0x0788(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Confirm_Bg;                                    // 0x0790(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Hover_Frame;                                   // 0x0798(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Select_Frame;                                  // 0x07A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Select_Ban_Frame;                              // 0x07A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Select_Pick_Frame;                             // 0x07B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Confirm_Frame;                                 // 0x07B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_TeammateConfirm_Frame;                         // 0x07C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Locked_Frame;                                  // 0x07C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Pick_Frame;                                    // 0x07D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             Btn_Ban_Frame;                                     // 0x07D8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FMargin                                NormalBtnOffset;                                   // 0x07E0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	struct FMargin                                PreviewBtnOffset;                                  // 0x07F0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	class UAkAudioEvent*                          AkEvent_OnHovered;                                 // 0x0800(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnIsPreview;                                       // 0x0808(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnAnimationFinished(const class UWidgetAnimation* Animation);
	void SetBtnIsPressed(bool IsBtnPressed_0);
	void SetIsHover(bool IsHover_0);
	void SetCanInteract(bool CanInteract_0);
	void SetIsPicked(bool IsPicked_0);
	void SetIsBaned(bool IsBaned_0);
	void SetIsUnlock(bool IsUnlock_0);
	void SetIsTeamSelected(bool IsTeamSelected_0);
	void SetIsSelectable(bool IsSelectable_0);
	void SetIsSelected(bool IsSelected_0);
	void SetIsPreview(bool IsPreview_0);
	void SetBtnState(bool IsPreview_0, bool IsSelected_0);
	void SetHeroID(int32 HeroID_0);
	void PreConstruct(bool IsDesignTime);
	void OnInitialized();
	void OnIsPreview__DelegateSignature(bool IsPreview_0);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_SelectHero_HeroListBtn">();
	}
	static class UPyWidget_SelectHero_HeroListBtn* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_SelectHero_HeroListBtn>();
	}
};
static_assert(alignof(UPyWidget_SelectHero_HeroListBtn) == 0x000008, "Wrong alignment on UPyWidget_SelectHero_HeroListBtn");
static_assert(sizeof(UPyWidget_SelectHero_HeroListBtn) == 0x000818, "Wrong size on UPyWidget_SelectHero_HeroListBtn");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, HeroID) == 0x000750, "Member 'UPyWidget_SelectHero_HeroListBtn::HeroID' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, IsPreview) == 0x000754, "Member 'UPyWidget_SelectHero_HeroListBtn::IsPreview' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, IsSelected) == 0x000755, "Member 'UPyWidget_SelectHero_HeroListBtn::IsSelected' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, IsUnlock) == 0x000756, "Member 'UPyWidget_SelectHero_HeroListBtn::IsUnlock' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, IsSelectable) == 0x000757, "Member 'UPyWidget_SelectHero_HeroListBtn::IsSelectable' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, IsTeamSelected) == 0x000758, "Member 'UPyWidget_SelectHero_HeroListBtn::IsTeamSelected' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, IsBaned) == 0x000759, "Member 'UPyWidget_SelectHero_HeroListBtn::IsBaned' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, IsPicked) == 0x00075A, "Member 'UPyWidget_SelectHero_HeroListBtn::IsPicked' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, CanInteract) == 0x00075B, "Member 'UPyWidget_SelectHero_HeroListBtn::CanInteract' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, BtnNormalOpacity) == 0x00075C, "Member 'UPyWidget_SelectHero_HeroListBtn::BtnNormalOpacity' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, BtnSelectedOpacity) == 0x000760, "Member 'UPyWidget_SelectHero_HeroListBtn::BtnSelectedOpacity' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, BtnLockAndTeamSelectedOpacity) == 0x000764, "Member 'UPyWidget_SelectHero_HeroListBtn::BtnLockAndTeamSelectedOpacity' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, BtnUnSelectableOpacity) == 0x000768, "Member 'UPyWidget_SelectHero_HeroListBtn::BtnUnSelectableOpacity' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Default_Bg) == 0x000770, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Default_Bg' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Hover_Bg) == 0x000778, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Hover_Bg' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Select_Bg) == 0x000780, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Select_Bg' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Select_BanPick_Bg) == 0x000788, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Select_BanPick_Bg' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Confirm_Bg) == 0x000790, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Confirm_Bg' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Hover_Frame) == 0x000798, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Hover_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Select_Frame) == 0x0007A0, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Select_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Select_Ban_Frame) == 0x0007A8, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Select_Ban_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Select_Pick_Frame) == 0x0007B0, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Select_Pick_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Confirm_Frame) == 0x0007B8, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Confirm_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_TeammateConfirm_Frame) == 0x0007C0, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_TeammateConfirm_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Locked_Frame) == 0x0007C8, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Locked_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Pick_Frame) == 0x0007D0, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Pick_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, Btn_Ban_Frame) == 0x0007D8, "Member 'UPyWidget_SelectHero_HeroListBtn::Btn_Ban_Frame' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, NormalBtnOffset) == 0x0007E0, "Member 'UPyWidget_SelectHero_HeroListBtn::NormalBtnOffset' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, PreviewBtnOffset) == 0x0007F0, "Member 'UPyWidget_SelectHero_HeroListBtn::PreviewBtnOffset' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, AkEvent_OnHovered) == 0x000800, "Member 'UPyWidget_SelectHero_HeroListBtn::AkEvent_OnHovered' has a wrong offset!");
static_assert(offsetof(UPyWidget_SelectHero_HeroListBtn, OnIsPreview) == 0x000808, "Member 'UPyWidget_SelectHero_HeroListBtn::OnIsPreview' has a wrong offset!");

}

