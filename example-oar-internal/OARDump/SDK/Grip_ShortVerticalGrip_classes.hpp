#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Grip_ShortVerticalGrip

#include "Basic.hpp"

#include "Attachment_Grip_base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass Grip_ShortVerticalGrip.Grip_ShortVerticalGrip_C
// 0x0000 (0x0250 - 0x0250)
class AGrip_ShortVerticalGrip_C final : public AAttachment_Grip_base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Grip_ShortVerticalGrip_C">();
	}
	static class AGrip_ShortVerticalGrip_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AGrip_ShortVerticalGrip_C>();
	}
};
static_assert(alignof(AGrip_ShortVerticalGrip_C) == 0x000008, "Wrong alignment on AGrip_ShortVerticalGrip_C");
static_assert(sizeof(AGrip_ShortVerticalGrip_C) == 0x000250, "Wrong size on AGrip_ShortVerticalGrip_C");

}

