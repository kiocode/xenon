#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_SelectHero_TeamInfo

#include "Basic.hpp"

#include "PyWidget_SelectHero_PlayerList_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_SelectHero_TeamInfo.WBP_SelectHero_TeamInfo_C
// 0x0038 (0x0628 - 0x05F0)
class UWBP_SelectHero_TeamInfo_C final : public UPyWidget_SelectHero_PlayerList
{
public:
	class UMarvelHorizontalBox*                   HBox_TeamInfo;                                     // 0x05F0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_SelectHero_PlayerInfo_C*           WBP_PlayerInfo_1;                                  // 0x05F8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_SelectHero_PlayerInfo_C*           WBP_PlayerInfo_2;                                  // 0x0600(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_SelectHero_PlayerInfo_C*           WBP_PlayerInfo_3;                                  // 0x0608(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_SelectHero_PlayerInfo_C*           WBP_PlayerInfo_4;                                  // 0x0610(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_SelectHero_PlayerInfo_C*           WBP_PlayerInfo_5;                                  // 0x0618(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_SelectHero_PlayerInfo_C*           WBP_PlayerInfo_6;                                  // 0x0620(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_SelectHero_TeamInfo_C">();
	}
	static class UWBP_SelectHero_TeamInfo_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_SelectHero_TeamInfo_C>();
	}
};
////static_assert(alignof(UWBP_SelectHero_TeamInfo_C) == 0x000008, "Wrong alignment on UWBP_SelectHero_TeamInfo_C");
////static_assert(sizeof(UWBP_SelectHero_TeamInfo_C) == 0x000628, "Wrong size on UWBP_SelectHero_TeamInfo_C");
////static_assert(offsetof(UWBP_SelectHero_TeamInfo_C, HBox_TeamInfo) == 0x0005F0, "Member 'UWBP_SelectHero_TeamInfo_C::HBox_TeamInfo' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_TeamInfo_C, WBP_PlayerInfo_1) == 0x0005F8, "Member 'UWBP_SelectHero_TeamInfo_C::WBP_PlayerInfo_1' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_TeamInfo_C, WBP_PlayerInfo_2) == 0x000600, "Member 'UWBP_SelectHero_TeamInfo_C::WBP_PlayerInfo_2' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_TeamInfo_C, WBP_PlayerInfo_3) == 0x000608, "Member 'UWBP_SelectHero_TeamInfo_C::WBP_PlayerInfo_3' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_TeamInfo_C, WBP_PlayerInfo_4) == 0x000610, "Member 'UWBP_SelectHero_TeamInfo_C::WBP_PlayerInfo_4' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_TeamInfo_C, WBP_PlayerInfo_5) == 0x000618, "Member 'UWBP_SelectHero_TeamInfo_C::WBP_PlayerInfo_5' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_TeamInfo_C, WBP_PlayerInfo_6) == 0x000620, "Member 'UWBP_SelectHero_TeamInfo_C::WBP_PlayerInfo_6' has a wrong offset!");

}

