#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_102343

#include "Basic.hpp"

#include "Hero_1023_structs.hpp"


namespace SDK::Params
{

// PythonFunction PyAbility_102343.PyAbility_102343.OnCueStateChanged
// 0x0010 (0x0010 - 0x0000)
struct PyAbility_102343_OnCueStateChanged final
{
public:
	class USummonedComp_10234101*                 SummonedComponent;                                 // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	ESpawnState                                   OldState;                                          // 0x0008(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESpawnState                                   NewState;                                          // 0x0009(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_102343_OnCueStateChanged) == 0x000008, "Wrong alignment on PyAbility_102343_OnCueStateChanged");
static_assert(sizeof(PyAbility_102343_OnCueStateChanged) == 0x000010, "Wrong size on PyAbility_102343_OnCueStateChanged");
static_assert(offsetof(PyAbility_102343_OnCueStateChanged, SummonedComponent) == 0x000000, "Member 'PyAbility_102343_OnCueStateChanged::SummonedComponent' has a wrong offset!");
static_assert(offsetof(PyAbility_102343_OnCueStateChanged, OldState) == 0x000008, "Member 'PyAbility_102343_OnCueStateChanged::OldState' has a wrong offset!");
static_assert(offsetof(PyAbility_102343_OnCueStateChanged, NewState) == 0x000009, "Member 'PyAbility_102343_OnCueStateChanged::NewState' has a wrong offset!");

// PythonFunction PyAbility_102343.PyAbility_102343.OnSummonedEnd
// 0x0008 (0x0008 - 0x0000)
struct PyAbility_102343_OnSummonedEnd final
{
public:
	class AActor*                                 InActor;                                           // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_102343_OnSummonedEnd) == 0x000008, "Wrong alignment on PyAbility_102343_OnSummonedEnd");
static_assert(sizeof(PyAbility_102343_OnSummonedEnd) == 0x000008, "Wrong size on PyAbility_102343_OnSummonedEnd");
static_assert(offsetof(PyAbility_102343_OnSummonedEnd, InActor) == 0x000000, "Member 'PyAbility_102343_OnSummonedEnd::InActor' has a wrong offset!");

// PythonFunction PyAbility_102343.PyAbility_102343.RecycleSummoned
// 0x0004 (0x0004 - 0x0000)
struct PyAbility_102343_RecycleSummoned final
{
public:
	float                                         TimeWaited;                                        // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_102343_RecycleSummoned) == 0x000004, "Wrong alignment on PyAbility_102343_RecycleSummoned");
static_assert(sizeof(PyAbility_102343_RecycleSummoned) == 0x000004, "Wrong size on PyAbility_102343_RecycleSummoned");
static_assert(offsetof(PyAbility_102343_RecycleSummoned, TimeWaited) == 0x000000, "Member 'PyAbility_102343_RecycleSummoned::TimeWaited' has a wrong offset!");

// PythonFunction PyAbility_102343.PyAbility_102343.K2_OnEndAbility
// 0x0001 (0x0001 - 0x0000)
struct PyAbility_102343_K2_OnEndAbility final
{
public:
	bool                                          bWasCancelled;                                     // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_102343_K2_OnEndAbility) == 0x000001, "Wrong alignment on PyAbility_102343_K2_OnEndAbility");
static_assert(sizeof(PyAbility_102343_K2_OnEndAbility) == 0x000001, "Wrong size on PyAbility_102343_K2_OnEndAbility");
static_assert(offsetof(PyAbility_102343_K2_OnEndAbility, bWasCancelled) == 0x000000, "Member 'PyAbility_102343_K2_OnEndAbility::bWasCancelled' has a wrong offset!");

}

