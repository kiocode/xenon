#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BTT_PyAbilityActionBase

#include "Basic.hpp"

#include "AIModule_structs.hpp"
#include "PyBTNodeBase_classes.hpp"
#include "Marvel_structs.hpp"


namespace SDK
{

// PythonClass BTT_PyAbilityActionBase.BTT_PyAbilityActionBase
// 0x0030 (0x00F0 - 0x00C0)
class UBTT_PyAbilityActionBase : public UBTTask_PyBase
{
public:
	struct FBlackboardKeySelector                 InAbilityUsageObject;                              // 0x00C0(0x0030)(Edit, NativeAccessSpecifierPublic)

public:
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);
	void ReceiveAbortAI(class AAIController* OwnerController, class APawn* ControlledPawn);
	void ReceiveOnTaskFinished(class AAIController* OwnerController, class APawn* ControlledPawn, EBTNodeResult Result);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"BTT_PyAbilityActionBase">();
	}
	static class UBTT_PyAbilityActionBase* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBTT_PyAbilityActionBase>();
	}
};
////static_assert(alignof(UBTT_PyAbilityActionBase) == 0x000008, "Wrong alignment on UBTT_PyAbilityActionBase");
////static_assert(sizeof(UBTT_PyAbilityActionBase) == 0x0000F0, "Wrong size on UBTT_PyAbilityActionBase");
////static_assert(offsetof(UBTT_PyAbilityActionBase, InAbilityUsageObject) == 0x0000C0, "Member 'UBTT_PyAbilityActionBase::InAbilityUsageObject' has a wrong offset!");

// PythonClass BTT_PyAbilityActionBase.BTT_PyAbilityActionButtonBase
// 0x0008 (0x00F8 - 0x00F0)
class UBTT_PyAbilityActionButtonBase : public UBTT_PyAbilityActionBase
{
public:
	EAbilityInputBinds                            Action;                                            // 0x00F0(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_F1[0x3];                                       // 0x00F1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         PressDuration;                                     // 0x00F4(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"BTT_PyAbilityActionButtonBase">();
	}
	static class UBTT_PyAbilityActionButtonBase* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBTT_PyAbilityActionButtonBase>();
	}
};
////static_assert(alignof(UBTT_PyAbilityActionButtonBase) == 0x000008, "Wrong alignment on UBTT_PyAbilityActionButtonBase");
////static_assert(sizeof(UBTT_PyAbilityActionButtonBase) == 0x0000F8, "Wrong size on UBTT_PyAbilityActionButtonBase");
////static_assert(offsetof(UBTT_PyAbilityActionButtonBase, Action) == 0x0000F0, "Member 'UBTT_PyAbilityActionButtonBase::Action' has a wrong offset!");
////static_assert(offsetof(UBTT_PyAbilityActionButtonBase, PressDuration) == 0x0000F4, "Member 'UBTT_PyAbilityActionButtonBase::PressDuration' has a wrong offset!");

}

