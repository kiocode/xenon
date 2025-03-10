#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_Change_Hero_Item

#include "Basic.hpp"

#include "PyWidget_CustomCharacterPanel_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_Change_Hero_Item.WBP_Change_Hero_Item_C
// 0x00F0 (0x0A60 - 0x0970)
class UWBP_Change_Hero_Item_C final : public UPyWidget_CustomCharacterItem
{
public:
	class UWidgetAnimation*                       Anim_Select;                                       // 0x0968(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_Unselect;                                     // 0x0970(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UCanvasPanel*                           CanvasPanel_HeroItem;                              // 0x0978(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_Common_HeroHead_BigSpuare_C*       HeroAvatar;                                        // 0x0980(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_Common_HeroHead_BigSpuare_C*       HeroAvatar_Hover;                                  // 0x0988(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Bg_SynergisticCore;                            // 0x0990(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Hero_Change;                                   // 0x0998(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Hero_Change_Hover;                             // 0x09A0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Hero_Duty;                                     // 0x09A8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Hero_Duty_Hover;                               // 0x09B0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Hero_Duty_Select;                              // 0x09B8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Img_Hero_Staning;                                  // 0x09C0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Hero_Title;                                    // 0x09C8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Img_Hover_Line;                                    // 0x09D0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_HoverToPress_Bg;                               // 0x09D8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Item_Bg;                                       // 0x09E0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Item_Equipped;                                 // 0x09E8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Item_Equipped_Hover;                           // 0x09F0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Item_Equipped_Hover1;                          // 0x09F8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Item_NameBg;                                   // 0x0A00(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Item_SelectFrame;                              // 0x0A08(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Lock_Icon;                                     // 0x0A10(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Lock_Mask;                                     // 0x0A18(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelOverlay*                         Overlay_Hover;                                     // 0x0A20(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelOverlay*                         Overlay_Item_Select;                               // 0x0A28(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelOverlay*                         Overlay_Lock;                                      // 0x0A30(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelOverlay*                         Overlay_SynergisticCore;                           // 0x0A38(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelTextBlock*                       Text_HeroName;                                     // 0x0A40(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelTextBlock*                       Text_HeroName_Hover;                               // 0x0A48(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelTextBlock*                       Text_HeroName_Select;                              // 0x0A50(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Vx_Img_Dynamic_Bg;                                 // 0x0A58(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_Change_Hero_Item_C">();
	}
	static class UWBP_Change_Hero_Item_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_Change_Hero_Item_C>();
	}
};
//static_assert(alignof(UWBP_Change_Hero_Item_C) == 0x000010, "Wrong alignment on UWBP_Change_Hero_Item_C");
//static_assert(sizeof(UWBP_Change_Hero_Item_C) == 0x000A60, "Wrong size on UWBP_Change_Hero_Item_C");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Anim_Select) == 0x000968, "Member 'UWBP_Change_Hero_Item_C::Anim_Select' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Anim_Unselect) == 0x000970, "Member 'UWBP_Change_Hero_Item_C::Anim_Unselect' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, CanvasPanel_HeroItem) == 0x000978, "Member 'UWBP_Change_Hero_Item_C::CanvasPanel_HeroItem' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, HeroAvatar) == 0x000980, "Member 'UWBP_Change_Hero_Item_C::HeroAvatar' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, HeroAvatar_Hover) == 0x000988, "Member 'UWBP_Change_Hero_Item_C::HeroAvatar_Hover' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Bg_SynergisticCore) == 0x000990, "Member 'UWBP_Change_Hero_Item_C::Img_Bg_SynergisticCore' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Hero_Change) == 0x000998, "Member 'UWBP_Change_Hero_Item_C::Img_Hero_Change' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Hero_Change_Hover) == 0x0009A0, "Member 'UWBP_Change_Hero_Item_C::Img_Hero_Change_Hover' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Hero_Duty) == 0x0009A8, "Member 'UWBP_Change_Hero_Item_C::Img_Hero_Duty' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Hero_Duty_Hover) == 0x0009B0, "Member 'UWBP_Change_Hero_Item_C::Img_Hero_Duty_Hover' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Hero_Duty_Select) == 0x0009B8, "Member 'UWBP_Change_Hero_Item_C::Img_Hero_Duty_Select' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Hero_Staning) == 0x0009C0, "Member 'UWBP_Change_Hero_Item_C::Img_Hero_Staning' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Hero_Title) == 0x0009C8, "Member 'UWBP_Change_Hero_Item_C::Img_Hero_Title' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Hover_Line) == 0x0009D0, "Member 'UWBP_Change_Hero_Item_C::Img_Hover_Line' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_HoverToPress_Bg) == 0x0009D8, "Member 'UWBP_Change_Hero_Item_C::Img_HoverToPress_Bg' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Item_Bg) == 0x0009E0, "Member 'UWBP_Change_Hero_Item_C::Img_Item_Bg' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Item_Equipped) == 0x0009E8, "Member 'UWBP_Change_Hero_Item_C::Img_Item_Equipped' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Item_Equipped_Hover) == 0x0009F0, "Member 'UWBP_Change_Hero_Item_C::Img_Item_Equipped_Hover' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Item_Equipped_Hover1) == 0x0009F8, "Member 'UWBP_Change_Hero_Item_C::Img_Item_Equipped_Hover1' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Item_NameBg) == 0x000A00, "Member 'UWBP_Change_Hero_Item_C::Img_Item_NameBg' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Item_SelectFrame) == 0x000A08, "Member 'UWBP_Change_Hero_Item_C::Img_Item_SelectFrame' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Lock_Icon) == 0x000A10, "Member 'UWBP_Change_Hero_Item_C::Img_Lock_Icon' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Img_Lock_Mask) == 0x000A18, "Member 'UWBP_Change_Hero_Item_C::Img_Lock_Mask' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Overlay_Hover) == 0x000A20, "Member 'UWBP_Change_Hero_Item_C::Overlay_Hover' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Overlay_Item_Select) == 0x000A28, "Member 'UWBP_Change_Hero_Item_C::Overlay_Item_Select' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Overlay_Lock) == 0x000A30, "Member 'UWBP_Change_Hero_Item_C::Overlay_Lock' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Overlay_SynergisticCore) == 0x000A38, "Member 'UWBP_Change_Hero_Item_C::Overlay_SynergisticCore' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Text_HeroName) == 0x000A40, "Member 'UWBP_Change_Hero_Item_C::Text_HeroName' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Text_HeroName_Hover) == 0x000A48, "Member 'UWBP_Change_Hero_Item_C::Text_HeroName_Hover' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Text_HeroName_Select) == 0x000A50, "Member 'UWBP_Change_Hero_Item_C::Text_HeroName_Select' has a wrong offset!");
//static_assert(offsetof(UWBP_Change_Hero_Item_C, Vx_Img_Dynamic_Bg) == 0x000A58, "Member 'UWBP_Change_Hero_Item_C::Vx_Img_Dynamic_Bg' has a wrong offset!");

}

