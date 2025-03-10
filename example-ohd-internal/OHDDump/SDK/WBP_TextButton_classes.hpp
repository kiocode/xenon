#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_TextButton

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_classes.hpp"
#include "SlateCore_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_TextButton.WBP_TextButton_C
// 0x0408 (0x0638 - 0x0230)
class UWBP_TextButton_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0230(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UButton*                                Button;                                            // 0x0238(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             ButtonText;                                        // 0x0240(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   BtnText;                                           // 0x0248(0x0018)(Edit, BlueprintVisible, ExposeOnSpawn)
	FMulticastInlineDelegateProperty_             ButtonClicked;                                     // 0x0260(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             ButtonPressed;                                     // 0x0270(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             ButtonReleased;                                    // 0x0280(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             ButtonHovered;                                     // 0x0290(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             ButtonUnhovered;                                   // 0x02A0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	struct FMargin                                TextPadding;                                       // 0x02B0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	struct FSlateColor                            TextColorNormal;                                   // 0x02C0(0x0028)(Edit, BlueprintVisible, ExposeOnSpawn)
	struct FSlateColor                            TextColorPressed;                                  // 0x02E8(0x0028)(Edit, BlueprintVisible, ExposeOnSpawn)
	struct FSlateColor                            TextColorHovered;                                  // 0x0310(0x0028)(Edit, BlueprintVisible, ExposeOnSpawn)
	struct FButtonStyle                           BtnStyle;                                          // 0x0338(0x0278)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FSlateFontInfo                         TextFont;                                          // 0x05B0(0x0050)(Edit, BlueprintVisible, ExposeOnSpawn, HasGetValueTypeHash)
	bool                                          bUppercaseText;                                    // 0x0600(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	uint8                                         Pad_601[0x7];                                      // 0x0601(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateColor                            TextColorCustom;                                   // 0x0608(0x0028)(Edit, BlueprintVisible, ExposeOnSpawn)
	bool                                          bUseCustomTextColor;                               // 0x0630(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)

public:
	void ButtonClicked__DelegateSignature();
	void ButtonPressed__DelegateSignature();
	void ButtonReleased__DelegateSignature();
	void ButtonHovered__DelegateSignature();
	void ButtonUnhovered__DelegateSignature();
	void ExecuteUbergraph_WBP_TextButton(int32 EntryPoint);
	void BndEvt__Button_K2Node_ComponentBoundEvent_4_OnButtonHoverEvent__DelegateSignature();
	void BndEvt__Button_K2Node_ComponentBoundEvent_3_OnButtonHoverEvent__DelegateSignature();
	void BndEvt__Button_K2Node_ComponentBoundEvent_2_OnButtonReleasedEvent__DelegateSignature();
	void BndEvt__Button_K2Node_ComponentBoundEvent_1_OnButtonPressedEvent__DelegateSignature();
	void BndEvt__Button_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature();
	void PreConstruct(bool IsDesignTime);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_TextButton_C">();
	}
	static class UWBP_TextButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_TextButton_C>();
	}
};
static_assert(alignof(UWBP_TextButton_C) == 0x000008, "Wrong alignment on UWBP_TextButton_C");
static_assert(sizeof(UWBP_TextButton_C) == 0x000638, "Wrong size on UWBP_TextButton_C");
static_assert(offsetof(UWBP_TextButton_C, UberGraphFrame) == 0x000230, "Member 'UWBP_TextButton_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, Button) == 0x000238, "Member 'UWBP_TextButton_C::Button' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, ButtonText) == 0x000240, "Member 'UWBP_TextButton_C::ButtonText' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, BtnText) == 0x000248, "Member 'UWBP_TextButton_C::BtnText' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, ButtonClicked) == 0x000260, "Member 'UWBP_TextButton_C::ButtonClicked' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, ButtonPressed) == 0x000270, "Member 'UWBP_TextButton_C::ButtonPressed' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, ButtonReleased) == 0x000280, "Member 'UWBP_TextButton_C::ButtonReleased' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, ButtonHovered) == 0x000290, "Member 'UWBP_TextButton_C::ButtonHovered' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, ButtonUnhovered) == 0x0002A0, "Member 'UWBP_TextButton_C::ButtonUnhovered' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, TextPadding) == 0x0002B0, "Member 'UWBP_TextButton_C::TextPadding' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, TextColorNormal) == 0x0002C0, "Member 'UWBP_TextButton_C::TextColorNormal' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, TextColorPressed) == 0x0002E8, "Member 'UWBP_TextButton_C::TextColorPressed' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, TextColorHovered) == 0x000310, "Member 'UWBP_TextButton_C::TextColorHovered' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, BtnStyle) == 0x000338, "Member 'UWBP_TextButton_C::BtnStyle' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, TextFont) == 0x0005B0, "Member 'UWBP_TextButton_C::TextFont' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, bUppercaseText) == 0x000600, "Member 'UWBP_TextButton_C::bUppercaseText' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, TextColorCustom) == 0x000608, "Member 'UWBP_TextButton_C::TextColorCustom' has a wrong offset!");
static_assert(offsetof(UWBP_TextButton_C, bUseCustomTextColor) == 0x000630, "Member 'UWBP_TextButton_C::bUseCustomTextColor' has a wrong offset!");

}

