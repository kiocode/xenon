#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PySquirrelGirlCharacter

#include "Basic.hpp"

#include "Hero_1032_classes.hpp"


namespace SDK
{

// PythonClass PySquirrelGirlCharacter.PySquirrelGirlCharacter
// 0x0000 (0x1830 - 0x1830)
class APySquirrelGirlCharacter : public ASquirrelGirlCharacter
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PySquirrelGirlCharacter">();
	}
	static class APySquirrelGirlCharacter* GetDefaultObj()
	{
		return GetDefaultObjImpl<APySquirrelGirlCharacter>();
	}
};
static_assert(alignof(APySquirrelGirlCharacter) == 0x000010, "Wrong alignment on APySquirrelGirlCharacter");
static_assert(sizeof(APySquirrelGirlCharacter) == 0x001830, "Wrong size on APySquirrelGirlCharacter");

}

