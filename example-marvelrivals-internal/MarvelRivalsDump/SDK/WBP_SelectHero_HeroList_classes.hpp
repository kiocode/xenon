#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_SelectHero_HeroList

#include "Basic.hpp"

#include "PyWidget_SelectHero_HeroList_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_SelectHero_HeroList.WBP_SelectHero_HeroList_C
// 0x0018 (0x06E0 - 0x06C8)
class UWBP_SelectHero_HeroList_C final : public UPyWidget_SelectHero_HeroList
{
public:
	class UMarvelCanvasPanel*                     CanvasPanel_DutyList;                              // 0x06C8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelCanvasPanel*                     CanvasPanel_HeroList;                              // 0x06D0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Corona_Bg;                                         // 0x06D8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_SelectHero_HeroList_C">();
	}
	static class UWBP_SelectHero_HeroList_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_SelectHero_HeroList_C>();
	}
};
////static_assert(alignof(UWBP_SelectHero_HeroList_C) == 0x000008, "Wrong alignment on UWBP_SelectHero_HeroList_C");
////static_assert(sizeof(UWBP_SelectHero_HeroList_C) == 0x0006E0, "Wrong size on UWBP_SelectHero_HeroList_C");
////static_assert(offsetof(UWBP_SelectHero_HeroList_C, CanvasPanel_DutyList) == 0x0006C8, "Member 'UWBP_SelectHero_HeroList_C::CanvasPanel_DutyList' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroList_C, CanvasPanel_HeroList) == 0x0006D0, "Member 'UWBP_SelectHero_HeroList_C::CanvasPanel_HeroList' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroList_C, Corona_Bg) == 0x0006D8, "Member 'UWBP_SelectHero_HeroList_C::Corona_Bg' has a wrong offset!");

}

