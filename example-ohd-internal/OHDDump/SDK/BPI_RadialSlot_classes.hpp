#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPI_RadialSlot

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BPI_RadialSlot.BPI_RadialSlot_C
// 0x0000 (0x0028 - 0x0028)
class IBPI_RadialSlot_C final : public IInterface
{
public:
	void OnHighlight();
	void OnUnhighlight();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BPI_RadialSlot_C">();
	}
	static class IBPI_RadialSlot_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<IBPI_RadialSlot_C>();
	}
};
static_assert(alignof(IBPI_RadialSlot_C) == 0x000008, "Wrong alignment on IBPI_RadialSlot_C");
static_assert(sizeof(IBPI_RadialSlot_C) == 0x000028, "Wrong size on IBPI_RadialSlot_C");

}

