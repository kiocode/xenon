#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Post_1031001_Physics

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK
{

// ScriptStruct Post_1031001_Physics.Post_1031001_Physics_C.AnimBlueprintGeneratedConstantData
// 0x00DF (0x00E0 - 0x0001)
struct Post_1031001_Physics::FAnimBlueprintGeneratedConstantData final : public FAnimBlueprintConstantData
{
public:
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   __NameProperty_67;                                 // 0x0004(0x000C)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   __NameProperty_68;                                 // 0x0010(0x000C)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FAnimNodeFunctionRef                   __StructProperty_69;                               // 0x0020(0x0028)(BlueprintVisible, NoDestructor)
	struct FAnimSubsystem_PropertyAccess          AnimBlueprintExtension_PropertyAccess;             // 0x0048(0x0080)()
	struct FAnimSubsystem_Base                    AnimBlueprintExtension_Base;                       // 0x00C8(0x0018)()
};
static_assert(alignof(Post_1031001_Physics::FAnimBlueprintGeneratedConstantData) == 0x000008, "Wrong alignment on Post_1031001_Physics::FAnimBlueprintGeneratedConstantData");
static_assert(sizeof(Post_1031001_Physics::FAnimBlueprintGeneratedConstantData) == 0x0000E0, "Wrong size on Post_1031001_Physics::FAnimBlueprintGeneratedConstantData");
static_assert(offsetof(Post_1031001_Physics::FAnimBlueprintGeneratedConstantData, __NameProperty_67) == 0x000004, "Member 'Post_1031001_Physics::FAnimBlueprintGeneratedConstantData::__NameProperty_67' has a wrong offset!");
static_assert(offsetof(Post_1031001_Physics::FAnimBlueprintGeneratedConstantData, __NameProperty_68) == 0x000010, "Member 'Post_1031001_Physics::FAnimBlueprintGeneratedConstantData::__NameProperty_68' has a wrong offset!");
static_assert(offsetof(Post_1031001_Physics::FAnimBlueprintGeneratedConstantData, __StructProperty_69) == 0x000020, "Member 'Post_1031001_Physics::FAnimBlueprintGeneratedConstantData::__StructProperty_69' has a wrong offset!");
static_assert(offsetof(Post_1031001_Physics::FAnimBlueprintGeneratedConstantData, AnimBlueprintExtension_PropertyAccess) == 0x000048, "Member 'Post_1031001_Physics::FAnimBlueprintGeneratedConstantData::AnimBlueprintExtension_PropertyAccess' has a wrong offset!");
static_assert(offsetof(Post_1031001_Physics::FAnimBlueprintGeneratedConstantData, AnimBlueprintExtension_Base) == 0x0000C8, "Member 'Post_1031001_Physics::FAnimBlueprintGeneratedConstantData::AnimBlueprintExtension_Base' has a wrong offset!");

}

