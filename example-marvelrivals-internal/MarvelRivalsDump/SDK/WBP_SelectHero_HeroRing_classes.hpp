#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_SelectHero_HeroRing

#include "Basic.hpp"

#include "PyWidget_SelectHero_HeroRing_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_SelectHero_HeroRing.WBP_SelectHero_HeroRing_C
// 0x0048 (0x0638 - 0x05F0)
class UWBP_SelectHero_HeroRing_C final : public UPyWidget_SelectHero_HeroRing
{
public:
	class UWBP_SelectHero_HeroBigUnit_C*          HeroBigUnit;                                       // 0x05F0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_SelectHero_HeroMiddleUnit_C*       HeroMiddleUnit;                                    // 0x05F8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_SelectHero_HeroSmalUnit_C*         HeroSmalUnit;                                      // 0x0600(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Left_BigLine;                                  // 0x0608(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Left_MiddleLine;                               // 0x0610(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Left_SmalLine;                                 // 0x0618(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Right_BigLine;                                 // 0x0620(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Right_MiddleLine;                              // 0x0628(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelImage*                           Img_Right_SmalLine;                                // 0x0630(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_SelectHero_HeroRing_C">();
	}
	static class UWBP_SelectHero_HeroRing_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_SelectHero_HeroRing_C>();
	}
};
////static_assert(alignof(UWBP_SelectHero_HeroRing_C) == 0x000008, "Wrong alignment on UWBP_SelectHero_HeroRing_C");
////static_assert(sizeof(UWBP_SelectHero_HeroRing_C) == 0x000638, "Wrong size on UWBP_SelectHero_HeroRing_C");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, HeroBigUnit) == 0x0005F0, "Member 'UWBP_SelectHero_HeroRing_C::HeroBigUnit' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, HeroMiddleUnit) == 0x0005F8, "Member 'UWBP_SelectHero_HeroRing_C::HeroMiddleUnit' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, HeroSmalUnit) == 0x000600, "Member 'UWBP_SelectHero_HeroRing_C::HeroSmalUnit' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, Img_Left_BigLine) == 0x000608, "Member 'UWBP_SelectHero_HeroRing_C::Img_Left_BigLine' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, Img_Left_MiddleLine) == 0x000610, "Member 'UWBP_SelectHero_HeroRing_C::Img_Left_MiddleLine' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, Img_Left_SmalLine) == 0x000618, "Member 'UWBP_SelectHero_HeroRing_C::Img_Left_SmalLine' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, Img_Right_BigLine) == 0x000620, "Member 'UWBP_SelectHero_HeroRing_C::Img_Right_BigLine' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, Img_Right_MiddleLine) == 0x000628, "Member 'UWBP_SelectHero_HeroRing_C::Img_Right_MiddleLine' has a wrong offset!");
////static_assert(offsetof(UWBP_SelectHero_HeroRing_C, Img_Right_SmalLine) == 0x000630, "Member 'UWBP_SelectHero_HeroRing_C::Img_Right_SmalLine' has a wrong offset!");

}

