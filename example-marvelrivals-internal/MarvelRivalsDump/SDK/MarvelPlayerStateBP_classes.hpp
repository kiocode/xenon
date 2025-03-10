#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MarvelPlayerStateBP

#include "Basic.hpp"

#include "PyMarvelPlayerState_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass MarvelPlayerStateBP.MarvelPlayerStateBP_C
// 0x0008 (0x0E00 - 0x0DF8)
class AMarvelPlayerStateBP_C final : public APyMarvelPlayerState
{
public:
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0DF8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MarvelPlayerStateBP_C">();
	}
	static class AMarvelPlayerStateBP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AMarvelPlayerStateBP_C>();
	}
};
static_assert(alignof(AMarvelPlayerStateBP_C) == 0x000008, "Wrong alignment on AMarvelPlayerStateBP_C");
static_assert(sizeof(AMarvelPlayerStateBP_C) == 0x000E00, "Wrong size on AMarvelPlayerStateBP_C");
static_assert(offsetof(AMarvelPlayerStateBP_C, DefaultSceneRoot) == 0x000DF8, "Member 'AMarvelPlayerStateBP_C::DefaultSceneRoot' has a wrong offset!");

}

