#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BTT_PyGeneralMoveTo

#include "Basic.hpp"

#include "AIModule_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "PyBTNodeBase_classes.hpp"


namespace SDK
{

// PythonClass BTT_PyGeneralMoveTo.BTT_PyGeneralMoveTo
// 0x0108 (0x01C8 - 0x00C0)
class UBTT_PyGeneralMoveTo : public UBTTask_PyBase
{
public:
	struct FBlackboardKeySelector                 InMoveTarget;                                      // 0x00C0(0x0030)(Edit, NativeAccessSpecifierPublic)
	struct FBlackboardKeySelector                 AbilityMoveLogic;                                  // 0x00F0(0x0030)(Edit, NativeAccessSpecifierPublic)
	float                                         RandomRadius;                                      // 0x0120(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ScaleRandomRadius;                                 // 0x0124(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          OverrideTickInterval;                              // 0x0125(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_126[0x2];                                      // 0x0126(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FBlackboardKeySelector                 RandomRadiusBlackboard;                            // 0x0128(0x0030)(Edit, NativeAccessSpecifierPublic)
	float                                         AcceptanceRadius;                                  // 0x0158(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_15C[0x4];                                      // 0x015C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FAIDataProviderFloatValue              AcceptanceRadius_Dynamic;                          // 0x0160(0x0040)(Edit, NativeAccessSpecifierPublic)
	bool                                          AlwaysUseRandom;                                   // 0x01A0(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bUpdateTarget;                                     // 0x01A1(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          AllowPartialPath;                                  // 0x01A2(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bAlwaysSuccess;                                    // 0x01A3(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_1A4[0x4];                                      // 0x01A4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UPathFollowingComponent*                CachedPFComp;                                      // 0x01A8(0x0008)(Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, Transient, EditConst, InstancedReference, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UNavigationSystemV1*                    CachedNavSys;                                      // 0x01B0(0x0008)(Edit, ZeroConstructor, Transient, EditConst, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FGameplayTag                           DebugTag;                                          // 0x01B8(0x000C)(Edit, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void ReceiveTickAI(class AAIController* OwnerController, class APawn* ControlledPawn, float DeltaSeconds);
	void ReceiveExecuteAI(class AAIController* OwnerController, class APawn* ControlledPawn);
	void ReceiveAbortAI(class AAIController* OwnerController, class APawn* ControlledPawn);
	void ReceiveOnTaskFinished(class AAIController* OwnerController, class APawn* ControlledPawn, EBTNodeResult Result);
	void OnSVONMoveRequestFailed();
	void OnMoveCompleted(const struct FAIRequestID& RequestID, EPathFollowingResult Result);
	void OnMoveEnd(bool bSuccess);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"BTT_PyGeneralMoveTo">();
	}
	static class UBTT_PyGeneralMoveTo* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBTT_PyGeneralMoveTo>();
	}
};
//static_assert(alignof(UBTT_PyGeneralMoveTo) == 0x000008, "Wrong alignment on UBTT_PyGeneralMoveTo");
//static_assert(sizeof(UBTT_PyGeneralMoveTo) == 0x0001C8, "Wrong size on UBTT_PyGeneralMoveTo");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, InMoveTarget) == 0x0000C0, "Member 'UBTT_PyGeneralMoveTo::InMoveTarget' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, AbilityMoveLogic) == 0x0000F0, "Member 'UBTT_PyGeneralMoveTo::AbilityMoveLogic' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, RandomRadius) == 0x000120, "Member 'UBTT_PyGeneralMoveTo::RandomRadius' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, ScaleRandomRadius) == 0x000124, "Member 'UBTT_PyGeneralMoveTo::ScaleRandomRadius' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, OverrideTickInterval) == 0x000125, "Member 'UBTT_PyGeneralMoveTo::OverrideTickInterval' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, RandomRadiusBlackboard) == 0x000128, "Member 'UBTT_PyGeneralMoveTo::RandomRadiusBlackboard' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, AcceptanceRadius) == 0x000158, "Member 'UBTT_PyGeneralMoveTo::AcceptanceRadius' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, AcceptanceRadius_Dynamic) == 0x000160, "Member 'UBTT_PyGeneralMoveTo::AcceptanceRadius_Dynamic' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, AlwaysUseRandom) == 0x0001A0, "Member 'UBTT_PyGeneralMoveTo::AlwaysUseRandom' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, bUpdateTarget) == 0x0001A1, "Member 'UBTT_PyGeneralMoveTo::bUpdateTarget' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, AllowPartialPath) == 0x0001A2, "Member 'UBTT_PyGeneralMoveTo::AllowPartialPath' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, bAlwaysSuccess) == 0x0001A3, "Member 'UBTT_PyGeneralMoveTo::bAlwaysSuccess' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, CachedPFComp) == 0x0001A8, "Member 'UBTT_PyGeneralMoveTo::CachedPFComp' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, CachedNavSys) == 0x0001B0, "Member 'UBTT_PyGeneralMoveTo::CachedNavSys' has a wrong offset!");
//static_assert(offsetof(UBTT_PyGeneralMoveTo, DebugTag) == 0x0001B8, "Member 'UBTT_PyGeneralMoveTo::DebugTag' has a wrong offset!");

}

