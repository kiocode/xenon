#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyMoonKnightCharacter

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// PythonFunction PyMoonKnightCharacter.PyMoonKnightCharacter.ReceiveEndPlay
// 0x0001 (0x0001 - 0x0000)
struct PyMoonKnightCharacter_ReceiveEndPlay final
{
public:
	EEndPlayReason                                Reason;                                            // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyMoonKnightCharacter_ReceiveEndPlay) == 0x000001, "Wrong alignment on PyMoonKnightCharacter_ReceiveEndPlay");
static_assert(sizeof(PyMoonKnightCharacter_ReceiveEndPlay) == 0x000001, "Wrong size on PyMoonKnightCharacter_ReceiveEndPlay");
static_assert(offsetof(PyMoonKnightCharacter_ReceiveEndPlay, Reason) == 0x000000, "Member 'PyMoonKnightCharacter_ReceiveEndPlay::Reason' has a wrong offset!");

// PythonFunction PyMoonKnightCharacter.PyMoonKnightCharacter.OnGameplayActorAdded
// 0x0008 (0x0008 - 0x0000)
struct PyMoonKnightCharacter_OnGameplayActorAdded final
{
public:
	class AActor*                                 GameplayActor;                                     // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyMoonKnightCharacter_OnGameplayActorAdded) == 0x000008, "Wrong alignment on PyMoonKnightCharacter_OnGameplayActorAdded");
static_assert(sizeof(PyMoonKnightCharacter_OnGameplayActorAdded) == 0x000008, "Wrong size on PyMoonKnightCharacter_OnGameplayActorAdded");
static_assert(offsetof(PyMoonKnightCharacter_OnGameplayActorAdded, GameplayActor) == 0x000000, "Member 'PyMoonKnightCharacter_OnGameplayActorAdded::GameplayActor' has a wrong offset!");

// PythonFunction PyMoonKnightCharacter.PyMoonKnightCharacter.OnGameplayActorRemoved
// 0x0008 (0x0008 - 0x0000)
struct PyMoonKnightCharacter_OnGameplayActorRemoved final
{
public:
	class AActor*                                 GameplayActor;                                     // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyMoonKnightCharacter_OnGameplayActorRemoved) == 0x000008, "Wrong alignment on PyMoonKnightCharacter_OnGameplayActorRemoved");
static_assert(sizeof(PyMoonKnightCharacter_OnGameplayActorRemoved) == 0x000008, "Wrong size on PyMoonKnightCharacter_OnGameplayActorRemoved");
static_assert(offsetof(PyMoonKnightCharacter_OnGameplayActorRemoved, GameplayActor) == 0x000000, "Member 'PyMoonKnightCharacter_OnGameplayActorRemoved::GameplayActor' has a wrong offset!");

}

