#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Ability_401801_BP

#include "Basic.hpp"

#include "Marvel_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Ability_401801_BP.Ability_401801_BP_C
// 0x0000 (0x2580 - 0x2580)
class UAbility_401801_BP_C final : public UMarvelGameplayAbility
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Ability_401801_BP_C">();
	}
	static class UAbility_401801_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAbility_401801_BP_C>();
	}
};
//static_assert(alignof(UAbility_401801_BP_C) == 0x000008, "Wrong alignment on UAbility_401801_BP_C");
//static_assert(sizeof(UAbility_401801_BP_C) == 0x002580, "Wrong size on UAbility_401801_BP_C");

}

