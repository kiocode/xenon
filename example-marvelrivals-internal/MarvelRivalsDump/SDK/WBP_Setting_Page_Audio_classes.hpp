#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_Setting_Page_Audio

#include "Basic.hpp"

#include "PyWidget_SettingPageAudio_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_Setting_Page_Audio.WBP_Setting_Page_Audio_C
// 0x0008 (0x0610 - 0x0608)
class UWBP_Setting_Page_Audio_C final : public UPyWidget_SettingyPageAudio
{
public:
	class UMarvelVerticalBox*                     VBox_Panel;                                        // 0x0608(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_Setting_Page_Audio_C">();
	}
	static class UWBP_Setting_Page_Audio_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_Setting_Page_Audio_C>();
	}
};
////static_assert(alignof(UWBP_Setting_Page_Audio_C) == 0x000008, "Wrong alignment on UWBP_Setting_Page_Audio_C");
////static_assert(sizeof(UWBP_Setting_Page_Audio_C) == 0x000610, "Wrong size on UWBP_Setting_Page_Audio_C");
////static_assert(offsetof(UWBP_Setting_Page_Audio_C, VBox_Panel) == 0x000608, "Member 'UWBP_Setting_Page_Audio_C::VBox_Panel' has a wrong offset!");

}

