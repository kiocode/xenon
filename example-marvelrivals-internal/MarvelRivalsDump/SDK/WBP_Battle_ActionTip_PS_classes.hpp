#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_Battle_ActionTip_PS

#include "Basic.hpp"

#include "PyWidget_ActionTip_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_Battle_ActionTip_PS.WBP_Battle_ActionTip_PS_C
// 0x0030 (0x0648 - 0x0618)
class UWBP_Battle_ActionTip_PS_C final : public UPyWidget_ActionTip
{
public:
	class UWidgetAnimation*                       Anim_KeyState;                                     // 0x0618(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Frame_Bottom;                                  // 0x0620(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Frame_Top;                                     // 0x0628(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Line_PS;                                       // 0x0630(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelOverlay*                         Overlay_Tip;                                       // 0x0638(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelRichTextBlock*                   Text_KeyHint;                                      // 0x0640(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_Battle_ActionTip_PS_C">();
	}
	static class UWBP_Battle_ActionTip_PS_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_Battle_ActionTip_PS_C>();
	}
};
//static_assert(alignof(UWBP_Battle_ActionTip_PS_C) == 0x000008, "Wrong alignment on UWBP_Battle_ActionTip_PS_C");
//static_assert(sizeof(UWBP_Battle_ActionTip_PS_C) == 0x000648, "Wrong size on UWBP_Battle_ActionTip_PS_C");
//static_assert(offsetof(UWBP_Battle_ActionTip_PS_C, Anim_KeyState) == 0x000618, "Member 'UWBP_Battle_ActionTip_PS_C::Anim_KeyState' has a wrong offset!");
//static_assert(offsetof(UWBP_Battle_ActionTip_PS_C, Img_Frame_Bottom) == 0x000620, "Member 'UWBP_Battle_ActionTip_PS_C::Img_Frame_Bottom' has a wrong offset!");
//static_assert(offsetof(UWBP_Battle_ActionTip_PS_C, Img_Frame_Top) == 0x000628, "Member 'UWBP_Battle_ActionTip_PS_C::Img_Frame_Top' has a wrong offset!");
//static_assert(offsetof(UWBP_Battle_ActionTip_PS_C, Img_Line_PS) == 0x000630, "Member 'UWBP_Battle_ActionTip_PS_C::Img_Line_PS' has a wrong offset!");
//static_assert(offsetof(UWBP_Battle_ActionTip_PS_C, Overlay_Tip) == 0x000638, "Member 'UWBP_Battle_ActionTip_PS_C::Overlay_Tip' has a wrong offset!");
//static_assert(offsetof(UWBP_Battle_ActionTip_PS_C, Text_KeyHint) == 0x000640, "Member 'UWBP_Battle_ActionTip_PS_C::Text_KeyHint' has a wrong offset!");

}

