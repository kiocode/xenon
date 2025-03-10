#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DataBaseEvents

#include "Basic.hpp"

#include "Marvel_structs.hpp"


namespace SDK::Params
{

// PythonFunction DataBaseEvents.HitEvent.GetEventHeroIDsAll
// 0x0050 (0x0050 - 0x0000)
struct HitEvent_GetEventHeroIDsAll final
{
public:
	TSet<class FString>                           ReturnValue;                                       // 0x0000(0x0050)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(HitEvent_GetEventHeroIDsAll) == 0x000008, "Wrong alignment on HitEvent_GetEventHeroIDsAll");
static_assert(sizeof(HitEvent_GetEventHeroIDsAll) == 0x000050, "Wrong size on HitEvent_GetEventHeroIDsAll");
static_assert(offsetof(HitEvent_GetEventHeroIDsAll, ReturnValue) == 0x000000, "Member 'HitEvent_GetEventHeroIDsAll::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.HitEvent.GetEventHeroIDsAny
// 0x0010 (0x0010 - 0x0000)
struct HitEvent_GetEventHeroIDsAny final
{
public:
	TArray<struct FDependencyHeroIDSet>           ReturnValue;                                       // 0x0000(0x0010)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(HitEvent_GetEventHeroIDsAny) == 0x000008, "Wrong alignment on HitEvent_GetEventHeroIDsAny");
static_assert(sizeof(HitEvent_GetEventHeroIDsAny) == 0x000010, "Wrong size on HitEvent_GetEventHeroIDsAny");
static_assert(offsetof(HitEvent_GetEventHeroIDsAny, ReturnValue) == 0x000000, "Member 'HitEvent_GetEventHeroIDsAny::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.HitRateEvent.GetEventHeroIDsAll
// 0x0050 (0x0050 - 0x0000)
struct HitRateEvent_GetEventHeroIDsAll final
{
public:
	TSet<class FString>                           ReturnValue;                                       // 0x0000(0x0050)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(HitRateEvent_GetEventHeroIDsAll) == 0x000008, "Wrong alignment on HitRateEvent_GetEventHeroIDsAll");
static_assert(sizeof(HitRateEvent_GetEventHeroIDsAll) == 0x000050, "Wrong size on HitRateEvent_GetEventHeroIDsAll");
static_assert(offsetof(HitRateEvent_GetEventHeroIDsAll, ReturnValue) == 0x000000, "Member 'HitRateEvent_GetEventHeroIDsAll::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.HitRateEvent.GetEventHeroIDsAny
// 0x0010 (0x0010 - 0x0000)
struct HitRateEvent_GetEventHeroIDsAny final
{
public:
	TArray<struct FDependencyHeroIDSet>           ReturnValue;                                       // 0x0000(0x0010)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(HitRateEvent_GetEventHeroIDsAny) == 0x000008, "Wrong alignment on HitRateEvent_GetEventHeroIDsAny");
static_assert(sizeof(HitRateEvent_GetEventHeroIDsAny) == 0x000010, "Wrong size on HitRateEvent_GetEventHeroIDsAny");
static_assert(offsetof(HitRateEvent_GetEventHeroIDsAny, ReturnValue) == 0x000000, "Member 'HitRateEvent_GetEventHeroIDsAny::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.SpecialHitNumEvent.GetEventHeroIDsAll
// 0x0050 (0x0050 - 0x0000)
struct SpecialHitNumEvent_GetEventHeroIDsAll final
{
public:
	TSet<class FString>                           ReturnValue;                                       // 0x0000(0x0050)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(SpecialHitNumEvent_GetEventHeroIDsAll) == 0x000008, "Wrong alignment on SpecialHitNumEvent_GetEventHeroIDsAll");
static_assert(sizeof(SpecialHitNumEvent_GetEventHeroIDsAll) == 0x000050, "Wrong size on SpecialHitNumEvent_GetEventHeroIDsAll");
static_assert(offsetof(SpecialHitNumEvent_GetEventHeroIDsAll, ReturnValue) == 0x000000, "Member 'SpecialHitNumEvent_GetEventHeroIDsAll::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.KillEvent.GetEventHeroIDsAll
// 0x0050 (0x0050 - 0x0000)
struct KillEvent_GetEventHeroIDsAll final
{
public:
	TSet<class FString>                           ReturnValue;                                       // 0x0000(0x0050)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(KillEvent_GetEventHeroIDsAll) == 0x000008, "Wrong alignment on KillEvent_GetEventHeroIDsAll");
static_assert(sizeof(KillEvent_GetEventHeroIDsAll) == 0x000050, "Wrong size on KillEvent_GetEventHeroIDsAll");
static_assert(offsetof(KillEvent_GetEventHeroIDsAll, ReturnValue) == 0x000000, "Member 'KillEvent_GetEventHeroIDsAll::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.KillEvent.GetEventHeroIDsAny
// 0x0010 (0x0010 - 0x0000)
struct KillEvent_GetEventHeroIDsAny final
{
public:
	TArray<struct FDependencyHeroIDSet>           ReturnValue;                                       // 0x0000(0x0010)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(KillEvent_GetEventHeroIDsAny) == 0x000008, "Wrong alignment on KillEvent_GetEventHeroIDsAny");
static_assert(sizeof(KillEvent_GetEventHeroIDsAny) == 0x000010, "Wrong size on KillEvent_GetEventHeroIDsAny");
static_assert(offsetof(KillEvent_GetEventHeroIDsAny, ReturnValue) == 0x000000, "Member 'KillEvent_GetEventHeroIDsAny::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.AssistEvent.GetEventHeroIDsAll
// 0x0050 (0x0050 - 0x0000)
struct AssistEvent_GetEventHeroIDsAll final
{
public:
	TSet<class FString>                           ReturnValue;                                       // 0x0000(0x0050)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(AssistEvent_GetEventHeroIDsAll) == 0x000008, "Wrong alignment on AssistEvent_GetEventHeroIDsAll");
static_assert(sizeof(AssistEvent_GetEventHeroIDsAll) == 0x000050, "Wrong size on AssistEvent_GetEventHeroIDsAll");
static_assert(offsetof(AssistEvent_GetEventHeroIDsAll, ReturnValue) == 0x000000, "Member 'AssistEvent_GetEventHeroIDsAll::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.AssistEvent.GetEventHeroIDsAny
// 0x0010 (0x0010 - 0x0000)
struct AssistEvent_GetEventHeroIDsAny final
{
public:
	TArray<struct FDependencyHeroIDSet>           ReturnValue;                                       // 0x0000(0x0010)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(AssistEvent_GetEventHeroIDsAny) == 0x000008, "Wrong alignment on AssistEvent_GetEventHeroIDsAny");
static_assert(sizeof(AssistEvent_GetEventHeroIDsAny) == 0x000010, "Wrong size on AssistEvent_GetEventHeroIDsAny");
static_assert(offsetof(AssistEvent_GetEventHeroIDsAny, ReturnValue) == 0x000000, "Member 'AssistEvent_GetEventHeroIDsAny::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.ReviveEvent.GetEventHeroIDsAny
// 0x0010 (0x0010 - 0x0000)
struct ReviveEvent_GetEventHeroIDsAny final
{
public:
	TArray<struct FDependencyHeroIDSet>           ReturnValue;                                       // 0x0000(0x0010)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(ReviveEvent_GetEventHeroIDsAny) == 0x000008, "Wrong alignment on ReviveEvent_GetEventHeroIDsAny");
static_assert(sizeof(ReviveEvent_GetEventHeroIDsAny) == 0x000010, "Wrong size on ReviveEvent_GetEventHeroIDsAny");
static_assert(offsetof(ReviveEvent_GetEventHeroIDsAny, ReturnValue) == 0x000000, "Member 'ReviveEvent_GetEventHeroIDsAny::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.OccupyCamp.GetEventMapIDsAll
// 0x0050 (0x0050 - 0x0000)
struct OccupyCamp_GetEventMapIDsAll final
{
public:
	TSet<class FString>                           ReturnValue;                                       // 0x0000(0x0050)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(OccupyCamp_GetEventMapIDsAll) == 0x000008, "Wrong alignment on OccupyCamp_GetEventMapIDsAll");
static_assert(sizeof(OccupyCamp_GetEventMapIDsAll) == 0x000050, "Wrong size on OccupyCamp_GetEventMapIDsAll");
static_assert(offsetof(OccupyCamp_GetEventMapIDsAll, ReturnValue) == 0x000000, "Member 'OccupyCamp_GetEventMapIDsAll::ReturnValue' has a wrong offset!");

// PythonFunction DataBaseEvents.FinishEvent.GetEventMapIDsAll
// 0x0050 (0x0050 - 0x0000)
struct FinishEvent_GetEventMapIDsAll final
{
public:
	TSet<class FString>                           ReturnValue;                                       // 0x0000(0x0050)(Parm, OutParm, ReturnParm)
};
static_assert(alignof(FinishEvent_GetEventMapIDsAll) == 0x000008, "Wrong alignment on FinishEvent_GetEventMapIDsAll");
static_assert(sizeof(FinishEvent_GetEventMapIDsAll) == 0x000050, "Wrong size on FinishEvent_GetEventMapIDsAll");
static_assert(offsetof(FinishEvent_GetEventMapIDsAll, ReturnValue) == 0x000000, "Member 'FinishEvent_GetEventMapIDsAll::ReturnValue' has a wrong offset!");

}

