#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Projectile_105051_BP

#include "Basic.hpp"

#include "PyAbility_105051_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Projectile_105051_BP.Projectile_105051_BP_C
// 0x0000 (0x3050 - 0x3050)
class AProjectile_105051_BP_C final : public APyProjectile_105051
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Projectile_105051_BP_C">();
	}
	static class AProjectile_105051_BP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AProjectile_105051_BP_C>();
	}
};
static_assert(alignof(AProjectile_105051_BP_C) == 0x000010, "Wrong alignment on AProjectile_105051_BP_C");
static_assert(sizeof(AProjectile_105051_BP_C) == 0x003050, "Wrong size on AProjectile_105051_BP_C");

}

