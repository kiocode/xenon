#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_Game_Subtitle_Item

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "PyGameSubtitles_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_Game_Subtitle_Item.WBP_Game_Subtitle_Item_C
// 0x0028 (0x0670 - 0x0648)
class UWBP_Game_Subtitle_Item_C final : public UPyWidget_GameSubtitleItem
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0648(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UHorizontalBox*                         HorizontalBox_0;                                   // 0x0650(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_text_bg;                                       // 0x0658(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelRichTextBlock*                   RichText_Speaker;                                  // 0x0660(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               SizeBox_Subtitle;                                  // 0x0668(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_WBP_Game_Subtitle_Item(int32 EntryPoint);
	void BP_OnItemSelectionChanged(bool bIsSelected);
	void BP_OnItemExpansionChanged(bool bIsExpanded);
	void BP_OnEntryReleased();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_Game_Subtitle_Item_C">();
	}
	static class UWBP_Game_Subtitle_Item_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_Game_Subtitle_Item_C>();
	}
};
////static_assert(alignof(UWBP_Game_Subtitle_Item_C) == 0x000008, "Wrong alignment on UWBP_Game_Subtitle_Item_C");
////static_assert(sizeof(UWBP_Game_Subtitle_Item_C) == 0x000670, "Wrong size on UWBP_Game_Subtitle_Item_C");
////static_assert(offsetof(UWBP_Game_Subtitle_Item_C, UberGraphFrame) == 0x000648, "Member 'UWBP_Game_Subtitle_Item_C::UberGraphFrame' has a wrong offset!");
////static_assert(offsetof(UWBP_Game_Subtitle_Item_C, HorizontalBox_0) == 0x000650, "Member 'UWBP_Game_Subtitle_Item_C::HorizontalBox_0' has a wrong offset!");
////static_assert(offsetof(UWBP_Game_Subtitle_Item_C, Img_text_bg) == 0x000658, "Member 'UWBP_Game_Subtitle_Item_C::Img_text_bg' has a wrong offset!");
////static_assert(offsetof(UWBP_Game_Subtitle_Item_C, RichText_Speaker) == 0x000660, "Member 'UWBP_Game_Subtitle_Item_C::RichText_Speaker' has a wrong offset!");
////static_assert(offsetof(UWBP_Game_Subtitle_Item_C, SizeBox_Subtitle) == 0x000668, "Member 'UWBP_Game_Subtitle_Item_C::SizeBox_Subtitle' has a wrong offset!");

}

