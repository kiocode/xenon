#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_SynergyAbilityTips

#include "Basic.hpp"

#include "Marvel_structs.hpp"


namespace SDK::Params
{

// PythonFunction PyWidget_SynergyAbilityTips.PyWidget_SynergyAbilityTips.OnAnimationFinished
// 0x0008 (0x0008 - 0x0000)
struct PyWidget_SynergyAbilityTips_OnAnimationFinished final
{
public:
	const class UWidgetAnimation*                 Animation;                                         // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyWidget_SynergyAbilityTips_OnAnimationFinished) == 0x000008, "Wrong alignment on PyWidget_SynergyAbilityTips_OnAnimationFinished");
static_assert(sizeof(PyWidget_SynergyAbilityTips_OnAnimationFinished) == 0x000008, "Wrong size on PyWidget_SynergyAbilityTips_OnAnimationFinished");
static_assert(offsetof(PyWidget_SynergyAbilityTips_OnAnimationFinished, Animation) == 0x000000, "Member 'PyWidget_SynergyAbilityTips_OnAnimationFinished::Animation' has a wrong offset!");

// PythonFunction PyWidget_SynergyAbilityTips.PyWidget_SynergyAbilityTips_Popups.OnHeadPictureLoadCompleted
// 0x0008 (0x0008 - 0x0000)
struct PyWidget_SynergyAbilityTips_Popups_OnHeadPictureLoadCompleted final
{
public:
	class UTexture2D*                             Picture;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyWidget_SynergyAbilityTips_Popups_OnHeadPictureLoadCompleted) == 0x000008, "Wrong alignment on PyWidget_SynergyAbilityTips_Popups_OnHeadPictureLoadCompleted");
static_assert(sizeof(PyWidget_SynergyAbilityTips_Popups_OnHeadPictureLoadCompleted) == 0x000008, "Wrong size on PyWidget_SynergyAbilityTips_Popups_OnHeadPictureLoadCompleted");
static_assert(offsetof(PyWidget_SynergyAbilityTips_Popups_OnHeadPictureLoadCompleted, Picture) == 0x000000, "Member 'PyWidget_SynergyAbilityTips_Popups_OnHeadPictureLoadCompleted::Picture' has a wrong offset!");

// PythonFunction PyWidget_SynergyAbilityTips.PyWidget_SynergyAbilityTipsPanel.OnBondStateChanged
// 0x00A0 (0x00A0 - 0x0000)
struct PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged final
{
public:
	struct FBondInstance                          InBondInstance;                                    // 0x0000(0x0090)(ConstParm, Parm, OutParm, ReferenceParm)
	TArray<class AMarvelBaseCharacter*>           TriggerCharacters;                                 // 0x0090(0x0010)(ConstParm, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged) == 0x000008, "Wrong alignment on PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged");
static_assert(sizeof(PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged) == 0x0000A0, "Wrong size on PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged");
static_assert(offsetof(PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged, InBondInstance) == 0x000000, "Member 'PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged::InBondInstance' has a wrong offset!");
static_assert(offsetof(PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged, TriggerCharacters) == 0x000090, "Member 'PyWidget_SynergyAbilityTipsPanel_OnBondStateChanged::TriggerCharacters' has a wrong offset!");

// PythonFunction PyWidget_SynergyAbilityTips.PyWidget_ReplaySynergyAbilityTipsPanel.OnBondStateChanged
// 0x00A0 (0x00A0 - 0x0000)
struct PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged final
{
public:
	struct FBondInstance                          InBondInstance;                                    // 0x0000(0x0090)(ConstParm, Parm, OutParm, ReferenceParm)
	TArray<class AMarvelBaseCharacter*>           TriggerCharacters;                                 // 0x0090(0x0010)(ConstParm, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged) == 0x000008, "Wrong alignment on PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged");
static_assert(sizeof(PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged) == 0x0000A0, "Wrong size on PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged");
static_assert(offsetof(PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged, InBondInstance) == 0x000000, "Member 'PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged::InBondInstance' has a wrong offset!");
static_assert(offsetof(PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged, TriggerCharacters) == 0x000090, "Member 'PyWidget_ReplaySynergyAbilityTipsPanel_OnBondStateChanged::TriggerCharacters' has a wrong offset!");

// PythonFunction PyWidget_SynergyAbilityTips.PyWidget_SynergyAbilityTips_FullScreen.OnAnimationFinished
// 0x0008 (0x0008 - 0x0000)
struct PyWidget_SynergyAbilityTips_FullScreen_OnAnimationFinished final
{
public:
	const class UWidgetAnimation*                 Animation;                                         // 0x0000(0x0008)(ConstParm, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyWidget_SynergyAbilityTips_FullScreen_OnAnimationFinished) == 0x000008, "Wrong alignment on PyWidget_SynergyAbilityTips_FullScreen_OnAnimationFinished");
static_assert(sizeof(PyWidget_SynergyAbilityTips_FullScreen_OnAnimationFinished) == 0x000008, "Wrong size on PyWidget_SynergyAbilityTips_FullScreen_OnAnimationFinished");
static_assert(offsetof(PyWidget_SynergyAbilityTips_FullScreen_OnAnimationFinished, Animation) == 0x000000, "Member 'PyWidget_SynergyAbilityTips_FullScreen_OnAnimationFinished::Animation' has a wrong offset!");

// PythonFunction PyWidget_SynergyAbilityTips.PyWidget_SynergyAbilityTips_FullScreen.OnHeadPictureLoadCompleted
// 0x0008 (0x0008 - 0x0000)
struct PyWidget_SynergyAbilityTips_FullScreen_OnHeadPictureLoadCompleted final
{
public:
	class UTexture2D*                             Picture;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyWidget_SynergyAbilityTips_FullScreen_OnHeadPictureLoadCompleted) == 0x000008, "Wrong alignment on PyWidget_SynergyAbilityTips_FullScreen_OnHeadPictureLoadCompleted");
static_assert(sizeof(PyWidget_SynergyAbilityTips_FullScreen_OnHeadPictureLoadCompleted) == 0x000008, "Wrong size on PyWidget_SynergyAbilityTips_FullScreen_OnHeadPictureLoadCompleted");
static_assert(offsetof(PyWidget_SynergyAbilityTips_FullScreen_OnHeadPictureLoadCompleted, Picture) == 0x000000, "Member 'PyWidget_SynergyAbilityTips_FullScreen_OnHeadPictureLoadCompleted::Picture' has a wrong offset!");

// DelegateFunction PyWidget_SynergyAbilityTips.PyWidget_SynergyAbilityTips_FullScreen.OnUpdatePanelShowOrHideState__DelegateSignature
// 0x0001 (0x0001 - 0x0000)
struct PyWidget_SynergyAbilityTips_FullScreen_OnUpdatePanelShowOrHideState__DelegateSignature final
{
public:
	bool                                          b_is_show;                                         // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyWidget_SynergyAbilityTips_FullScreen_OnUpdatePanelShowOrHideState__DelegateSignature) == 0x000001, "Wrong alignment on PyWidget_SynergyAbilityTips_FullScreen_OnUpdatePanelShowOrHideState__DelegateSignature");
static_assert(sizeof(PyWidget_SynergyAbilityTips_FullScreen_OnUpdatePanelShowOrHideState__DelegateSignature) == 0x000001, "Wrong size on PyWidget_SynergyAbilityTips_FullScreen_OnUpdatePanelShowOrHideState__DelegateSignature");
static_assert(offsetof(PyWidget_SynergyAbilityTips_FullScreen_OnUpdatePanelShowOrHideState__DelegateSignature, b_is_show) == 0x000000, "Member 'PyWidget_SynergyAbilityTips_FullScreen_OnUpdatePanelShowOrHideState__DelegateSignature::b_is_show' has a wrong offset!");

}

