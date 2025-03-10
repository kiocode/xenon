#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Mag_Empty

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Mag_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Mag_Empty.Mag_Empty_C
// 0x0008 (0x0238 - 0x0230)
class AMag_Empty_C final : public AMag_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0230(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_Mag_Empty(int32 EntryPoint);
	void ReceiveBeginPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Mag_Empty_C">();
	}
	static class AMag_Empty_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AMag_Empty_C>();
	}
};
static_assert(alignof(AMag_Empty_C) == 0x000008, "Wrong alignment on AMag_Empty_C");
static_assert(sizeof(AMag_Empty_C) == 0x000238, "Wrong size on AMag_Empty_C");
static_assert(offsetof(AMag_Empty_C, UberGraphFrame) == 0x000230, "Member 'AMag_Empty_C::UberGraphFrame' has a wrong offset!");

}

