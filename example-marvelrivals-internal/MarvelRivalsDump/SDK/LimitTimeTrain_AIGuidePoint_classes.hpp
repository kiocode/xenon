#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LimitTimeTrain_AIGuidePoint

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass LimitTimeTrain_AIGuidePoint.LimitTimeTrain_AIGuidePoint_C
// 0x0008 (0x0498 - 0x0490)
class ALimitTimeTrain_AIGuidePoint_C final : public AActor
{
public:
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0490(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"LimitTimeTrain_AIGuidePoint_C">();
	}
	static class ALimitTimeTrain_AIGuidePoint_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ALimitTimeTrain_AIGuidePoint_C>();
	}
};
static_assert(alignof(ALimitTimeTrain_AIGuidePoint_C) == 0x000008, "Wrong alignment on ALimitTimeTrain_AIGuidePoint_C");
static_assert(sizeof(ALimitTimeTrain_AIGuidePoint_C) == 0x000498, "Wrong size on ALimitTimeTrain_AIGuidePoint_C");
static_assert(offsetof(ALimitTimeTrain_AIGuidePoint_C, DefaultSceneRoot) == 0x000490, "Member 'ALimitTimeTrain_AIGuidePoint_C::DefaultSceneRoot' has a wrong offset!");

}

