#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_103841

#include "Basic.hpp"

#include "GameplayAbilities_structs.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK::Params
{

// PythonFunction PyAbility_103841.PyCue_Buff_10384101.WhileActiveFX
// 0x01C0 (0x01C0 - 0x0000)
struct PyCue_Buff_10384101_WhileActiveFX final
{
public:
	class AActor*                                 MyTarget;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                 Parameters;                                        // 0x0008(0x01B8)(ConstParm, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(PyCue_Buff_10384101_WhileActiveFX) == 0x000008, "Wrong alignment on PyCue_Buff_10384101_WhileActiveFX");
static_assert(sizeof(PyCue_Buff_10384101_WhileActiveFX) == 0x0001C0, "Wrong size on PyCue_Buff_10384101_WhileActiveFX");
static_assert(offsetof(PyCue_Buff_10384101_WhileActiveFX, MyTarget) == 0x000000, "Member 'PyCue_Buff_10384101_WhileActiveFX::MyTarget' has a wrong offset!");
static_assert(offsetof(PyCue_Buff_10384101_WhileActiveFX, Parameters) == 0x000008, "Member 'PyCue_Buff_10384101_WhileActiveFX::Parameters' has a wrong offset!");

// PythonFunction PyAbility_103841.PyAbility_103841.K2_OnEndAbility
// 0x0001 (0x0001 - 0x0000)
struct PyAbility_103841_K2_OnEndAbility final
{
public:
	bool                                          bWasCancelled;                                     // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_103841_K2_OnEndAbility) == 0x000001, "Wrong alignment on PyAbility_103841_K2_OnEndAbility");
static_assert(sizeof(PyAbility_103841_K2_OnEndAbility) == 0x000001, "Wrong size on PyAbility_103841_K2_OnEndAbility");
static_assert(offsetof(PyAbility_103841_K2_OnEndAbility, bWasCancelled) == 0x000000, "Member 'PyAbility_103841_K2_OnEndAbility::bWasCancelled' has a wrong offset!");

// PythonFunction PyAbility_103841.PyAbility_103841.OnWaitTaskConfirm
// 0x0004 (0x0004 - 0x0000)
struct PyAbility_103841_OnWaitTaskConfirm final
{
public:
	float                                         TimeWaited;                                        // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_103841_OnWaitTaskConfirm) == 0x000004, "Wrong alignment on PyAbility_103841_OnWaitTaskConfirm");
static_assert(sizeof(PyAbility_103841_OnWaitTaskConfirm) == 0x000004, "Wrong size on PyAbility_103841_OnWaitTaskConfirm");
static_assert(offsetof(PyAbility_103841_OnWaitTaskConfirm, TimeWaited) == 0x000000, "Member 'PyAbility_103841_OnWaitTaskConfirm::TimeWaited' has a wrong offset!");

// PythonFunction PyAbility_103841.PyUIController_103841.SetAbility
// 0x0010 (0x0010 - 0x0000)
struct PyUIController_103841_SetAbility final
{
public:
	int32                                         InAbilityId;                                       // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameplayAbility*                       InAbility;                                         // 0x0008(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyUIController_103841_SetAbility) == 0x000008, "Wrong alignment on PyUIController_103841_SetAbility");
static_assert(sizeof(PyUIController_103841_SetAbility) == 0x000010, "Wrong size on PyUIController_103841_SetAbility");
static_assert(offsetof(PyUIController_103841_SetAbility, InAbilityId) == 0x000000, "Member 'PyUIController_103841_SetAbility::InAbilityId' has a wrong offset!");
static_assert(offsetof(PyUIController_103841_SetAbility, InAbility) == 0x000008, "Member 'PyUIController_103841_SetAbility::InAbility' has a wrong offset!");

// PythonFunction PyAbility_103841.PyUIController_103841.OnTagUpdate
// 0x0010 (0x0010 - 0x0000)
struct PyUIController_103841_OnTagUpdate final
{
public:
	struct FGameplayTag                           Tag;                                               // 0x0000(0x000C)(ConstParm, Parm, OutParm, ReferenceParm, NoDestructor, HasGetValueTypeHash)
	bool                                          Exist;                                             // 0x000C(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyUIController_103841_OnTagUpdate) == 0x000004, "Wrong alignment on PyUIController_103841_OnTagUpdate");
static_assert(sizeof(PyUIController_103841_OnTagUpdate) == 0x000010, "Wrong size on PyUIController_103841_OnTagUpdate");
static_assert(offsetof(PyUIController_103841_OnTagUpdate, Tag) == 0x000000, "Member 'PyUIController_103841_OnTagUpdate::Tag' has a wrong offset!");
static_assert(offsetof(PyUIController_103841_OnTagUpdate, Exist) == 0x00000C, "Member 'PyUIController_103841_OnTagUpdate::Exist' has a wrong offset!");

}

