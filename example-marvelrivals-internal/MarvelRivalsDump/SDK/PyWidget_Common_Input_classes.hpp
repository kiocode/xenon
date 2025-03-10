#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_Common_Input

#include "Basic.hpp"

#include "Marvel_structs.hpp"
#include "PyWidget_Common_Input_structs.hpp"
#include "SlateCore_structs.hpp"
#include "PyMarvelUserWidget_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_Common_Input.PyWidget_Common_Input
// 0x1620 (0x1C10 - 0x05F0)
class UPyWidget_Common_Input : public UPyMarvelUserWidget
{
public:
	PyWidget_Common_Input::EInputType             InputType;                                         // 0x05E9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5EA[0x6];                                      // 0x05EA(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FButtonStyle                           BeforeEnterButtonStyle;                            // 0x05F0(0x0400)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	struct FButtonStyle                           AfterEnterButtonStyle;                             // 0x09F0(0x0400)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	struct FButtonStyle                           PasswordShowBtnStyle;                              // 0x0DF0(0x0400)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	struct FButtonStyle                           PasswordHideBtnStyle;                              // 0x11F0(0x0400)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	TArray<struct FGuideTipsStyle>                TipsStyle;                                         // 0x15F0(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	bool                                          IsCheckSensitiveWords;                             // 0x1600(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          SelectAllTextWhenFocused;                          // 0x1601(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          SubmitTextWhenNotFocused;                          // 0x1602(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1603[0x5];                                     // 0x1603(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   BtnPromptDefaultText;                              // 0x1608(0x0018)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	struct FSlateColor                            BtnPromptText_HoverColor;                          // 0x1620(0x0014)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            BtnPromptText_UnhoverColor;                        // 0x1634(0x0014)(Edit, BlueprintVisible, DisableEditOnInstance, NativeAccessSpecifierPublic)
	class FText                                   InputHintText;                                     // 0x1648(0x0018)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	class FText                                   DefaultInputText;                                  // 0x1660(0x0018)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	int32                                         TextPromptFontSize;                                // 0x1678(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         InputFontSize;                                     // 0x167C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsNicknameReview;                                  // 0x1680(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsNickwordsReview;                                 // 0x1681(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsForceSubmit;                                     // 0x1682(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsLimitLength;                                     // 0x1683(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsSimpleCheckLimitLength;                          // 0x1684(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1685[0x3];                                     // 0x1685(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         MinTextLength;                                     // 0x1688(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MaxTextLength;                                     // 0x168C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ETextTypeRestriction                          TextRestrictionType;                               // 0x1690(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsEmptyTextAllowed;                                // 0x1691(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1692[0xE];                                     // 0x1692(0x000E)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateBrush                            BtnNoContentNormalBrush;                           // 0x16A0(0x00D0)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateBrush                            BtnNoContentHoverBrush;                            // 0x1770(0x00D0)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateBrush                            BtnHasContentNormalBrush;                          // 0x1840(0x00D0)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateBrush                            BtnHasContentHoverBrush;                           // 0x1910(0x00D0)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	float                                         OverlayDefaultHeight;                              // 0x19E0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsDefaultEditing;                                  // 0x19E4(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsShowOperateButton;                               // 0x19E5(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsOperateIndependently;                            // 0x19E6(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsEnterEnabled;                                    // 0x19E7(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class UUserWidget>                Input_Prompt;                                      // 0x19E8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsTipDownside;                                     // 0x19F0(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19F1[0x3];                                     // 0x19F1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         TipTime;                                           // 0x19F4(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsCenterAlign;                                     // 0x19F8(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19F9[0x7];                                     // 0x19F9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FInputTips                             WrongTextEmpty;                                    // 0x1A00(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongTextMax;                                      // 0x1A20(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongTextMin;                                      // 0x1A40(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongTextOnlyNum;                                  // 0x1A60(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongTextOnlyAlphabet;                             // 0x1A80(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongTextOnlyAlNum;                                // 0x1AA0(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongTextOnlyMultiAl;                              // 0x1AC0(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongTextWithSpecialSymbols;                       // 0x1AE0(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongSensitiveWords;                               // 0x1B00(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongSpaceAtEnd;                                   // 0x1B20(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FInputTips                             WrongCustomText;                                   // 0x1B40(0x0020)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	bool                                          ClearKeyboardFocusOnCommit;                        // 0x1B60(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsSpecialSymbolsAllowed;                           // 0x1B61(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          NeedCheckSpecialChar;                              // 0x1B62(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          NeedCheckSpecialCharInPlayerName;                  // 0x1B63(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          NeedValidCharsSetInDataTable;                      // 0x1B64(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1B65[0x3];                                     // 0x1B65(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FString>                         ValidSpecialCharInPlayerName;                      // 0x1B68(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	class FString                                 ValidSpecialCharConfigRowName;                     // 0x1B78(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          SpecialCharNeedWhitelistForMinorityLanguage;       // 0x1B88(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          NeedCustomCheck;                                   // 0x1B89(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          NeedDeleteSpaceAtStartAndEnd;                      // 0x1B8A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          NeedCheckTextHasInvalidGlyph;                      // 0x1B8B(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1B8C[0x4];                                     // 0x1B8C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UWidgetAnimation*                       Anim_Approve;                                      // 0x1B90(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UWidgetAnimation*                       Anim_Diapprove;                                    // 0x1B98(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnSubmitText;                                      // 0x1BA0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnTextChanged;                                     // 0x1BB0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnTextStandardChanged;                             // 0x1BC0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnResetText;                                       // 0x1BD0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnCheckDisapprove;                                 // 0x1BE0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnHovered;                                         // 0x1BF0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnUnhovered;                                       // 0x1C00(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnSubmitText__DelegateSignature(const class FString& TextStr);
	void OnTextChanged__DelegateSignature(const class FString& TextStr);
	void OnTextStandardChanged__DelegateSignature(bool Enable);
	void OnResetText__DelegateSignature();
	void OnCheckDisapprove__DelegateSignature();
	void OnHovered__DelegateSignature();
	void OnUnhovered__DelegateSignature();
	void OnInitialized();
	void PreConstruct(bool IsDesignTime);
	void Construct();
	void Destruct();
	void SetInputTextFocus();
	void SetIsOwner(bool IsOwner);
	void SetIsEditable(bool IsEditable);
	void SetInputHintText(const class FText& HintText);
	void SetPromptHintText(const class FText& HintText);
	void SetTextPrompt(const class FText& Prompt);
	void SetInputSize();
	void SetFontSize();
	void SetIsEditing(bool IsEditing);
	void UpdateWidgetStyleWithEditState(bool IsEditing);
	void SetOperateBtnStyle(const struct FButtonStyle& BtnStyle);
	void SetIsSearch(bool IsSearch);
	void SetIsPassword(bool IsPassword);
	void SetEnterEnabled();
	int32 GetLenUTFEight(const class FString& Str);
	void SetInputText(const class FText& Text);
	class FText GetInputText();
	void SetTipsText(const struct FInputTips& Tips);
	void SetTipEnabled(bool TipEnabled);
	void SubmitText(const class FText& Text, bool bIsEnter);
	void SetMinTextLength(int32 Min_length);
	void SetMaxTextLength(int32 Max_length);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_Common_Input">();
	}
	static class UPyWidget_Common_Input* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_Common_Input>();
	}
};
static_assert(alignof(UPyWidget_Common_Input) == 0x000010, "Wrong alignment on UPyWidget_Common_Input");
static_assert(sizeof(UPyWidget_Common_Input) == 0x001C10, "Wrong size on UPyWidget_Common_Input");
static_assert(offsetof(UPyWidget_Common_Input, InputType) == 0x0005E9, "Member 'UPyWidget_Common_Input::InputType' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, BeforeEnterButtonStyle) == 0x0005F0, "Member 'UPyWidget_Common_Input::BeforeEnterButtonStyle' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, AfterEnterButtonStyle) == 0x0009F0, "Member 'UPyWidget_Common_Input::AfterEnterButtonStyle' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, PasswordShowBtnStyle) == 0x000DF0, "Member 'UPyWidget_Common_Input::PasswordShowBtnStyle' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, PasswordHideBtnStyle) == 0x0011F0, "Member 'UPyWidget_Common_Input::PasswordHideBtnStyle' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, TipsStyle) == 0x0015F0, "Member 'UPyWidget_Common_Input::TipsStyle' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsCheckSensitiveWords) == 0x001600, "Member 'UPyWidget_Common_Input::IsCheckSensitiveWords' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, SelectAllTextWhenFocused) == 0x001601, "Member 'UPyWidget_Common_Input::SelectAllTextWhenFocused' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, SubmitTextWhenNotFocused) == 0x001602, "Member 'UPyWidget_Common_Input::SubmitTextWhenNotFocused' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, BtnPromptDefaultText) == 0x001608, "Member 'UPyWidget_Common_Input::BtnPromptDefaultText' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, BtnPromptText_HoverColor) == 0x001620, "Member 'UPyWidget_Common_Input::BtnPromptText_HoverColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, BtnPromptText_UnhoverColor) == 0x001634, "Member 'UPyWidget_Common_Input::BtnPromptText_UnhoverColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, InputHintText) == 0x001648, "Member 'UPyWidget_Common_Input::InputHintText' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, DefaultInputText) == 0x001660, "Member 'UPyWidget_Common_Input::DefaultInputText' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, TextPromptFontSize) == 0x001678, "Member 'UPyWidget_Common_Input::TextPromptFontSize' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, InputFontSize) == 0x00167C, "Member 'UPyWidget_Common_Input::InputFontSize' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsNicknameReview) == 0x001680, "Member 'UPyWidget_Common_Input::IsNicknameReview' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsNickwordsReview) == 0x001681, "Member 'UPyWidget_Common_Input::IsNickwordsReview' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsForceSubmit) == 0x001682, "Member 'UPyWidget_Common_Input::IsForceSubmit' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsLimitLength) == 0x001683, "Member 'UPyWidget_Common_Input::IsLimitLength' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsSimpleCheckLimitLength) == 0x001684, "Member 'UPyWidget_Common_Input::IsSimpleCheckLimitLength' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, MinTextLength) == 0x001688, "Member 'UPyWidget_Common_Input::MinTextLength' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, MaxTextLength) == 0x00168C, "Member 'UPyWidget_Common_Input::MaxTextLength' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, TextRestrictionType) == 0x001690, "Member 'UPyWidget_Common_Input::TextRestrictionType' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsEmptyTextAllowed) == 0x001691, "Member 'UPyWidget_Common_Input::IsEmptyTextAllowed' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, BtnNoContentNormalBrush) == 0x0016A0, "Member 'UPyWidget_Common_Input::BtnNoContentNormalBrush' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, BtnNoContentHoverBrush) == 0x001770, "Member 'UPyWidget_Common_Input::BtnNoContentHoverBrush' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, BtnHasContentNormalBrush) == 0x001840, "Member 'UPyWidget_Common_Input::BtnHasContentNormalBrush' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, BtnHasContentHoverBrush) == 0x001910, "Member 'UPyWidget_Common_Input::BtnHasContentHoverBrush' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, OverlayDefaultHeight) == 0x0019E0, "Member 'UPyWidget_Common_Input::OverlayDefaultHeight' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsDefaultEditing) == 0x0019E4, "Member 'UPyWidget_Common_Input::IsDefaultEditing' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsShowOperateButton) == 0x0019E5, "Member 'UPyWidget_Common_Input::IsShowOperateButton' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsOperateIndependently) == 0x0019E6, "Member 'UPyWidget_Common_Input::IsOperateIndependently' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsEnterEnabled) == 0x0019E7, "Member 'UPyWidget_Common_Input::IsEnterEnabled' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, Input_Prompt) == 0x0019E8, "Member 'UPyWidget_Common_Input::Input_Prompt' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsTipDownside) == 0x0019F0, "Member 'UPyWidget_Common_Input::IsTipDownside' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, TipTime) == 0x0019F4, "Member 'UPyWidget_Common_Input::TipTime' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsCenterAlign) == 0x0019F8, "Member 'UPyWidget_Common_Input::IsCenterAlign' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongTextEmpty) == 0x001A00, "Member 'UPyWidget_Common_Input::WrongTextEmpty' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongTextMax) == 0x001A20, "Member 'UPyWidget_Common_Input::WrongTextMax' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongTextMin) == 0x001A40, "Member 'UPyWidget_Common_Input::WrongTextMin' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongTextOnlyNum) == 0x001A60, "Member 'UPyWidget_Common_Input::WrongTextOnlyNum' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongTextOnlyAlphabet) == 0x001A80, "Member 'UPyWidget_Common_Input::WrongTextOnlyAlphabet' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongTextOnlyAlNum) == 0x001AA0, "Member 'UPyWidget_Common_Input::WrongTextOnlyAlNum' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongTextOnlyMultiAl) == 0x001AC0, "Member 'UPyWidget_Common_Input::WrongTextOnlyMultiAl' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongTextWithSpecialSymbols) == 0x001AE0, "Member 'UPyWidget_Common_Input::WrongTextWithSpecialSymbols' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongSensitiveWords) == 0x001B00, "Member 'UPyWidget_Common_Input::WrongSensitiveWords' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongSpaceAtEnd) == 0x001B20, "Member 'UPyWidget_Common_Input::WrongSpaceAtEnd' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, WrongCustomText) == 0x001B40, "Member 'UPyWidget_Common_Input::WrongCustomText' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, ClearKeyboardFocusOnCommit) == 0x001B60, "Member 'UPyWidget_Common_Input::ClearKeyboardFocusOnCommit' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, IsSpecialSymbolsAllowed) == 0x001B61, "Member 'UPyWidget_Common_Input::IsSpecialSymbolsAllowed' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, NeedCheckSpecialChar) == 0x001B62, "Member 'UPyWidget_Common_Input::NeedCheckSpecialChar' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, NeedCheckSpecialCharInPlayerName) == 0x001B63, "Member 'UPyWidget_Common_Input::NeedCheckSpecialCharInPlayerName' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, NeedValidCharsSetInDataTable) == 0x001B64, "Member 'UPyWidget_Common_Input::NeedValidCharsSetInDataTable' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, ValidSpecialCharInPlayerName) == 0x001B68, "Member 'UPyWidget_Common_Input::ValidSpecialCharInPlayerName' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, ValidSpecialCharConfigRowName) == 0x001B78, "Member 'UPyWidget_Common_Input::ValidSpecialCharConfigRowName' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, SpecialCharNeedWhitelistForMinorityLanguage) == 0x001B88, "Member 'UPyWidget_Common_Input::SpecialCharNeedWhitelistForMinorityLanguage' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, NeedCustomCheck) == 0x001B89, "Member 'UPyWidget_Common_Input::NeedCustomCheck' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, NeedDeleteSpaceAtStartAndEnd) == 0x001B8A, "Member 'UPyWidget_Common_Input::NeedDeleteSpaceAtStartAndEnd' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, NeedCheckTextHasInvalidGlyph) == 0x001B8B, "Member 'UPyWidget_Common_Input::NeedCheckTextHasInvalidGlyph' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, Anim_Approve) == 0x001B90, "Member 'UPyWidget_Common_Input::Anim_Approve' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, Anim_Diapprove) == 0x001B98, "Member 'UPyWidget_Common_Input::Anim_Diapprove' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, OnSubmitText) == 0x001BA0, "Member 'UPyWidget_Common_Input::OnSubmitText' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, OnTextChanged) == 0x001BB0, "Member 'UPyWidget_Common_Input::OnTextChanged' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, OnTextStandardChanged) == 0x001BC0, "Member 'UPyWidget_Common_Input::OnTextStandardChanged' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, OnResetText) == 0x001BD0, "Member 'UPyWidget_Common_Input::OnResetText' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, OnCheckDisapprove) == 0x001BE0, "Member 'UPyWidget_Common_Input::OnCheckDisapprove' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, OnHovered) == 0x001BF0, "Member 'UPyWidget_Common_Input::OnHovered' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_Input, OnUnhovered) == 0x001C00, "Member 'UPyWidget_Common_Input::OnUnhovered' has a wrong offset!");

}

