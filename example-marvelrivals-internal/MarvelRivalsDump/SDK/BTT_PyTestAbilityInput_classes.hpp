#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BTT_PyTestAbilityInput

#include "Basic.hpp"

#include "Marvel_structs.hpp"
#include "PyBTNodeBase_classes.hpp"


namespace SDK
{

// PythonClass BTT_PyTestAbilityInput.BTT_PyTestAbilityInput
// 0x0010 (0x00D0 - 0x00C0)
class UBTT_PyTestAbilityInput : public UBTTask_PyBase
{
public:
	EAbilityInputBinds                            Action;                                            // 0x00C0(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_C1[0x3];                                       // 0x00C1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         AbilityID;                                         // 0x00C4(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsPressed;                                         // 0x00C8(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"BTT_PyTestAbilityInput">();
	}
	static class UBTT_PyTestAbilityInput* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBTT_PyTestAbilityInput>();
	}
};
//static_assert(alignof(UBTT_PyTestAbilityInput) == 0x000008, "Wrong alignment on UBTT_PyTestAbilityInput");
//static_assert(sizeof(UBTT_PyTestAbilityInput) == 0x0000D0, "Wrong size on UBTT_PyTestAbilityInput");
//static_assert(offsetof(UBTT_PyTestAbilityInput, Action) == 0x0000C0, "Member 'UBTT_PyTestAbilityInput::Action' has a wrong offset!");
//static_assert(offsetof(UBTT_PyTestAbilityInput, AbilityID) == 0x0000C4, "Member 'UBTT_PyTestAbilityInput::AbilityID' has a wrong offset!");
//static_assert(offsetof(UBTT_PyTestAbilityInput, IsPressed) == 0x0000C8, "Member 'UBTT_PyTestAbilityInput::IsPressed' has a wrong offset!");

}

