#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Summoned_10240201_BP

#include "Basic.hpp"

#include "Marvel_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Summoned_10240201_BP.Summoned_10240201_BP_C
// 0x0010 (0x08A0 - 0x0890)
class ASummoned_10240201_BP_C final : public AMarvelSummonerBase
{
public:
	class USummonedMovementComponent*             SummonedMovement;                                  // 0x0890(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Summoned_10240201_BP_C">();
	}
	static class ASummoned_10240201_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ASummoned_10240201_BP_C>();
	}
};
//static_assert(alignof(ASummoned_10240201_BP_C) == 0x000010, "Wrong alignment on ASummoned_10240201_BP_C");
//static_assert(sizeof(ASummoned_10240201_BP_C) == 0x0008A0, "Wrong size on ASummoned_10240201_BP_C");
//static_assert(offsetof(ASummoned_10240201_BP_C, SummonedMovement) == 0x000890, "Member 'ASummoned_10240201_BP_C::SummonedMovement' has a wrong offset!");

}

