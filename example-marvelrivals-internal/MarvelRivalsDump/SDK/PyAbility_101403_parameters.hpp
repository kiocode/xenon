#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_101403

#include "Basic.hpp"


namespace SDK::Params
{

// PythonFunction PyAbility_101403.PyAbility_101403.CanActivate
// 0x0001 (0x0001 - 0x0000)
struct PyAbility_101403_CanActivate final
{
public:
	bool                                          ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_101403_CanActivate) == 0x000001, "Wrong alignment on PyAbility_101403_CanActivate");
static_assert(sizeof(PyAbility_101403_CanActivate) == 0x000001, "Wrong size on PyAbility_101403_CanActivate");
static_assert(offsetof(PyAbility_101403_CanActivate, ReturnValue) == 0x000000, "Member 'PyAbility_101403_CanActivate::ReturnValue' has a wrong offset!");

// PythonFunction PyAbility_101403.PyAbility_101403.GetAbilityDuration
// 0x0004 (0x0004 - 0x0000)
struct PyAbility_101403_GetAbilityDuration final
{
public:
	float                                         ReturnValue;                                       // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_101403_GetAbilityDuration) == 0x000004, "Wrong alignment on PyAbility_101403_GetAbilityDuration");
static_assert(sizeof(PyAbility_101403_GetAbilityDuration) == 0x000004, "Wrong size on PyAbility_101403_GetAbilityDuration");
static_assert(offsetof(PyAbility_101403_GetAbilityDuration, ReturnValue) == 0x000000, "Member 'PyAbility_101403_GetAbilityDuration::ReturnValue' has a wrong offset!");

// PythonFunction PyAbility_101403.PyAbility_101403.GetCurrentTimelineIndex
// 0x0004 (0x0004 - 0x0000)
struct PyAbility_101403_GetCurrentTimelineIndex final
{
public:
	int32                                         ReturnValue;                                       // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_101403_GetCurrentTimelineIndex) == 0x000004, "Wrong alignment on PyAbility_101403_GetCurrentTimelineIndex");
static_assert(sizeof(PyAbility_101403_GetCurrentTimelineIndex) == 0x000004, "Wrong size on PyAbility_101403_GetCurrentTimelineIndex");
static_assert(offsetof(PyAbility_101403_GetCurrentTimelineIndex, ReturnValue) == 0x000000, "Member 'PyAbility_101403_GetCurrentTimelineIndex::ReturnValue' has a wrong offset!");

// PythonFunction PyAbility_101403.PyAbility_101403.NativeOnMontageEvent
// 0x0010 (0x0010 - 0x0000)
struct PyAbility_101403_NativeOnMontageEvent final
{
public:
	class FString                                 Tag;                                               // 0x0000(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_101403_NativeOnMontageEvent) == 0x000008, "Wrong alignment on PyAbility_101403_NativeOnMontageEvent");
static_assert(sizeof(PyAbility_101403_NativeOnMontageEvent) == 0x000010, "Wrong size on PyAbility_101403_NativeOnMontageEvent");
static_assert(offsetof(PyAbility_101403_NativeOnMontageEvent, Tag) == 0x000000, "Member 'PyAbility_101403_NativeOnMontageEvent::Tag' has a wrong offset!");

}

