#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_Chat_ItemText

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "PyWidget_ChatItemEntry_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_Chat_ItemText.WBP_Chat_ItemText_C
// 0x0040 (0x09E0 - 0x09A0)
class UWBP_Chat_ItemText_C final : public UPyWidget_ChatItemEntryText
{
public:
	uint8                                         Pad_991[0x7];                                      // 0x0991(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0998(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UMarvelButton*                          Btn_Base;                                          // 0x09A0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Day_Line;                                      // 0x09A8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Day_Line_1;                                    // 0x09B0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Input_Ps;                                      // 0x09B8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelHorizontalBox*                   Panel_Chat_Day;                                    // 0x09C0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelRichTextBlock*                   RText_Content;                                     // 0x09C8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               SizeBox_TextWidth;                                 // 0x09D0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelTextBlock*                       Text_Day;                                          // 0x09D8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void BP_OnEntryReleased();
	void BP_OnItemExpansionChanged(bool bIsExpanded);
	void BP_OnItemSelectionChanged(bool bIsSelected);
	void ExecuteUbergraph_WBP_Chat_ItemText(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_Chat_ItemText_C">();
	}
	static class UWBP_Chat_ItemText_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_Chat_ItemText_C>();
	}
};
//static_assert(alignof(UWBP_Chat_ItemText_C) == 0x000010, "Wrong alignment on UWBP_Chat_ItemText_C");
//static_assert(sizeof(UWBP_Chat_ItemText_C) == 0x0009E0, "Wrong size on UWBP_Chat_ItemText_C");
//static_assert(offsetof(UWBP_Chat_ItemText_C, UberGraphFrame) == 0x000998, "Member 'UWBP_Chat_ItemText_C::UberGraphFrame' has a wrong offset!");
//static_assert(offsetof(UWBP_Chat_ItemText_C, Btn_Base) == 0x0009A0, "Member 'UWBP_Chat_ItemText_C::Btn_Base' has a wrong offset!");
//static_assert(offsetof(UWBP_Chat_ItemText_C, Img_Day_Line) == 0x0009A8, "Member 'UWBP_Chat_ItemText_C::Img_Day_Line' has a wrong offset!");
//static_assert(offsetof(UWBP_Chat_ItemText_C, Img_Day_Line_1) == 0x0009B0, "Member 'UWBP_Chat_ItemText_C::Img_Day_Line_1' has a wrong offset!");
//static_assert(offsetof(UWBP_Chat_ItemText_C, Img_Input_Ps) == 0x0009B8, "Member 'UWBP_Chat_ItemText_C::Img_Input_Ps' has a wrong offset!");
//static_assert(offsetof(UWBP_Chat_ItemText_C, Panel_Chat_Day) == 0x0009C0, "Member 'UWBP_Chat_ItemText_C::Panel_Chat_Day' has a wrong offset!");
//static_assert(offsetof(UWBP_Chat_ItemText_C, RText_Content) == 0x0009C8, "Member 'UWBP_Chat_ItemText_C::RText_Content' has a wrong offset!");
//static_assert(offsetof(UWBP_Chat_ItemText_C, SizeBox_TextWidth) == 0x0009D0, "Member 'UWBP_Chat_ItemText_C::SizeBox_TextWidth' has a wrong offset!");
//static_assert(offsetof(UWBP_Chat_ItemText_C, Text_Day) == 0x0009D8, "Member 'UWBP_Chat_ItemText_C::Text_Day' has a wrong offset!");

}

