#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: One014_CharacterBP

#include "Basic.hpp"

#include "PyPunisherCharacter_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass 1014_CharacterBP.1014_CharacterBP_C
// 0x0010 (0x1880 - 0x1870)
class AOne014_CharacterBP_C final : public APyPunisherCharacter
{
public:
	class UPhysicalInteractionComponent*          PhysicalInteraction;                               // 0x1870(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"1014_CharacterBP_C">();
	}
	static class AOne014_CharacterBP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AOne014_CharacterBP_C>();
	}
};
static_assert(alignof(AOne014_CharacterBP_C) == 0x000010, "Wrong alignment on AOne014_CharacterBP_C");
static_assert(sizeof(AOne014_CharacterBP_C) == 0x001880, "Wrong size on AOne014_CharacterBP_C");
static_assert(offsetof(AOne014_CharacterBP_C, PhysicalInteraction) == 0x001870, "Member 'AOne014_CharacterBP_C::PhysicalInteraction' has a wrong offset!");

}

