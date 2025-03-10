#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: RatAnimBP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass RatAnimBP.RatAnimBP_C
// 0x0130 (0x03F0 - 0x02C0)
class URatAnimBP_C final : public UAnimInstance
{
public:
	uint8                                         Pad_2B8[0x8];                                      // 0x02B8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02C0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root;                                // 0x02C8(0x0030)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer;                    // 0x02F8(0x00E8)()
	float                                         Speed;                                             // 0x03E0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void AnimGraph(struct FPoseLink* AnimGraph_0);
	void BlueprintUpdateAnimation(float DeltaTimeX);
	void ExecuteUbergraph_RatAnimBP(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"RatAnimBP_C">();
	}
	static class URatAnimBP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<URatAnimBP_C>();
	}
};
static_assert(alignof(URatAnimBP_C) == 0x000010, "Wrong alignment on URatAnimBP_C");
static_assert(sizeof(URatAnimBP_C) == 0x0003F0, "Wrong size on URatAnimBP_C");
static_assert(offsetof(URatAnimBP_C, UberGraphFrame) == 0x0002C0, "Member 'URatAnimBP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(URatAnimBP_C, AnimGraphNode_Root) == 0x0002C8, "Member 'URatAnimBP_C::AnimGraphNode_Root' has a wrong offset!");
static_assert(offsetof(URatAnimBP_C, AnimGraphNode_BlendSpacePlayer) == 0x0002F8, "Member 'URatAnimBP_C::AnimGraphNode_BlendSpacePlayer' has a wrong offset!");
static_assert(offsetof(URatAnimBP_C, Speed) == 0x0003E0, "Member 'URatAnimBP_C::Speed' has a wrong offset!");

}

