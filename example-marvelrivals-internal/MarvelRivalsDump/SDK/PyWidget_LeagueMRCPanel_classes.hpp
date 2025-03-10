#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_LeagueMRCPanel

#include "Basic.hpp"

#include "SlateCore_structs.hpp"
#include "Marvel_structs.hpp"
#include "PyMarvelUserWidget_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_LeagueMRCPanel.PyWidget_LeagueMRCPanel
// 0x00F8 (0x06E8 - 0x05F0)
class UPyWidget_LeagueMRCPanel final : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x3];                                      // 0x05E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateColor                            TextColorRankMeetStandard;                         // 0x05EC(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorRankNotMeetStandard;                      // 0x0600(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorSignUpSuccess;                            // 0x0614(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorSignUpCanceling;                          // 0x0628(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorSignUpConfirming;                         // 0x063C(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorPreliminaryMatching;                      // 0x0650(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorPreliminaryFinish;                        // 0x0664(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorKnockoutEarlyStart;                       // 0x0678(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorWalkover;                                 // 0x068C(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FSlateColor                            TextColorPromoted;                                 // 0x06A0(0x0014)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	struct FMargin                                SignUpCardMargin;                                  // 0x06B4(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	struct FMargin                                ObserveCardMargin;                                 // 0x06C4(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_6D4[0x4];                                      // 0x06D4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FGuideTipsStyle>                GuideActions;                                      // 0x06D8(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void Construct();
	void Destruct();
	void MarvelSetVisible(bool Visible);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_LeagueMRCPanel">();
	}
	static class UPyWidget_LeagueMRCPanel* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_LeagueMRCPanel>();
	}
};
static_assert(alignof(UPyWidget_LeagueMRCPanel) == 0x000008, "Wrong alignment on UPyWidget_LeagueMRCPanel");
static_assert(sizeof(UPyWidget_LeagueMRCPanel) == 0x0006E8, "Wrong size on UPyWidget_LeagueMRCPanel");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorRankMeetStandard) == 0x0005EC, "Member 'UPyWidget_LeagueMRCPanel::TextColorRankMeetStandard' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorRankNotMeetStandard) == 0x000600, "Member 'UPyWidget_LeagueMRCPanel::TextColorRankNotMeetStandard' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorSignUpSuccess) == 0x000614, "Member 'UPyWidget_LeagueMRCPanel::TextColorSignUpSuccess' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorSignUpCanceling) == 0x000628, "Member 'UPyWidget_LeagueMRCPanel::TextColorSignUpCanceling' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorSignUpConfirming) == 0x00063C, "Member 'UPyWidget_LeagueMRCPanel::TextColorSignUpConfirming' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorPreliminaryMatching) == 0x000650, "Member 'UPyWidget_LeagueMRCPanel::TextColorPreliminaryMatching' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorPreliminaryFinish) == 0x000664, "Member 'UPyWidget_LeagueMRCPanel::TextColorPreliminaryFinish' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorKnockoutEarlyStart) == 0x000678, "Member 'UPyWidget_LeagueMRCPanel::TextColorKnockoutEarlyStart' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorWalkover) == 0x00068C, "Member 'UPyWidget_LeagueMRCPanel::TextColorWalkover' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, TextColorPromoted) == 0x0006A0, "Member 'UPyWidget_LeagueMRCPanel::TextColorPromoted' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, SignUpCardMargin) == 0x0006B4, "Member 'UPyWidget_LeagueMRCPanel::SignUpCardMargin' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, ObserveCardMargin) == 0x0006C4, "Member 'UPyWidget_LeagueMRCPanel::ObserveCardMargin' has a wrong offset!");
static_assert(offsetof(UPyWidget_LeagueMRCPanel, GuideActions) == 0x0006D8, "Member 'UPyWidget_LeagueMRCPanel::GuideActions' has a wrong offset!");

}

