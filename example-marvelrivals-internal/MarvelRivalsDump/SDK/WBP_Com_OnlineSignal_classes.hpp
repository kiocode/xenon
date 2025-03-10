#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_Com_OnlineSignal

#include "Basic.hpp"

#include "PyWidget_PingPanel_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_Com_OnlineSignal.WBP_Com_OnlineSignal_C
// 0x0028 (0x0620 - 0x05F8)
class UWBP_Com_OnlineSignal_C final : public UPyWidget_PingPanel
{
public:
	class UMarvelImage*                           Img_Signal_1;                                      // 0x05F8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Signal_2;                                      // 0x0600(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Signal_3;                                      // 0x0608(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Signal_Bg;                                     // 0x0610(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelOverlay*                         Overlay_Signal;                                    // 0x0618(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_Com_OnlineSignal_C">();
	}
	static class UWBP_Com_OnlineSignal_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_Com_OnlineSignal_C>();
	}
};
//static_assert(alignof(UWBP_Com_OnlineSignal_C) == 0x000008, "Wrong alignment on UWBP_Com_OnlineSignal_C");
//static_assert(sizeof(UWBP_Com_OnlineSignal_C) == 0x000620, "Wrong size on UWBP_Com_OnlineSignal_C");
//static_assert(offsetof(UWBP_Com_OnlineSignal_C, Img_Signal_1) == 0x0005F8, "Member 'UWBP_Com_OnlineSignal_C::Img_Signal_1' has a wrong offset!");
//static_assert(offsetof(UWBP_Com_OnlineSignal_C, Img_Signal_2) == 0x000600, "Member 'UWBP_Com_OnlineSignal_C::Img_Signal_2' has a wrong offset!");
//static_assert(offsetof(UWBP_Com_OnlineSignal_C, Img_Signal_3) == 0x000608, "Member 'UWBP_Com_OnlineSignal_C::Img_Signal_3' has a wrong offset!");
//static_assert(offsetof(UWBP_Com_OnlineSignal_C, Img_Signal_Bg) == 0x000610, "Member 'UWBP_Com_OnlineSignal_C::Img_Signal_Bg' has a wrong offset!");
//static_assert(offsetof(UWBP_Com_OnlineSignal_C, Overlay_Signal) == 0x000618, "Member 'UWBP_Com_OnlineSignal_C::Overlay_Signal' has a wrong offset!");

}

