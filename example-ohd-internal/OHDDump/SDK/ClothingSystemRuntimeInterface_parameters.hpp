#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ClothingSystemRuntimeInterface

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function ClothingSystemRuntimeInterface.ClothingSimulationInteractor.EnableGravityOverride
// 0x000C (0x000C - 0x0000)
struct ClothingSimulationInteractor_EnableGravityOverride final
{
public:
	struct FVector                                InVector;                                          // 0x0000(0x000C)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ClothingSimulationInteractor_EnableGravityOverride) == 0x000004, "Wrong alignment on ClothingSimulationInteractor_EnableGravityOverride");
static_assert(sizeof(ClothingSimulationInteractor_EnableGravityOverride) == 0x00000C, "Wrong size on ClothingSimulationInteractor_EnableGravityOverride");
static_assert(offsetof(ClothingSimulationInteractor_EnableGravityOverride, InVector) == 0x000000, "Member 'ClothingSimulationInteractor_EnableGravityOverride::InVector' has a wrong offset!");

// Function ClothingSystemRuntimeInterface.ClothingSimulationInteractor.SetAnimDriveSpringStiffness
// 0x0004 (0x0004 - 0x0000)
struct ClothingSimulationInteractor_SetAnimDriveSpringStiffness final
{
public:
	float                                         InStiffness;                                       // 0x0000(0x0004)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
static_assert(alignof(ClothingSimulationInteractor_SetAnimDriveSpringStiffness) == 0x000004, "Wrong alignment on ClothingSimulationInteractor_SetAnimDriveSpringStiffness");
static_assert(sizeof(ClothingSimulationInteractor_SetAnimDriveSpringStiffness) == 0x000004, "Wrong size on ClothingSimulationInteractor_SetAnimDriveSpringStiffness");
static_assert(offsetof(ClothingSimulationInteractor_SetAnimDriveSpringStiffness, InStiffness) == 0x000000, "Member 'ClothingSimulationInteractor_SetAnimDriveSpringStiffness::InStiffness' has a wrong offset!");

}

