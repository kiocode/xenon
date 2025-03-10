#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BlastNiagara

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK
{

// ScriptStruct BlastNiagara.BlastBigChunkState
// 0x0040 (0x0040 - 0x0000)
struct FBlastBigChunkState final
{
public:
	struct FVector3f                              PositionWS;                                        // 0x0000(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         FragmentImpluse;                                   // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector3f                              FragmentForceAxis;                                 // 0x0010(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         BigChunkBrokenImpluse;                             // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FQuat4f                                BigChunkQuaternion;                                // 0x0020(0x0010)(IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector3f                              BigChunkBoxSize;                                   // 0x0030(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         Padding;                                           // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
//static_assert(alignof(FBlastBigChunkState) == 0x000010, "Wrong alignment on FBlastBigChunkState");
//static_assert(sizeof(FBlastBigChunkState) == 0x000040, "Wrong size on FBlastBigChunkState");
//static_assert(offsetof(FBlastBigChunkState, PositionWS) == 0x000000, "Member 'FBlastBigChunkState::PositionWS' has a wrong offset!");
//static_assert(offsetof(FBlastBigChunkState, FragmentImpluse) == 0x00000C, "Member 'FBlastBigChunkState::FragmentImpluse' has a wrong offset!");
//static_assert(offsetof(FBlastBigChunkState, FragmentForceAxis) == 0x000010, "Member 'FBlastBigChunkState::FragmentForceAxis' has a wrong offset!");
//static_assert(offsetof(FBlastBigChunkState, BigChunkBrokenImpluse) == 0x00001C, "Member 'FBlastBigChunkState::BigChunkBrokenImpluse' has a wrong offset!");
//static_assert(offsetof(FBlastBigChunkState, BigChunkQuaternion) == 0x000020, "Member 'FBlastBigChunkState::BigChunkQuaternion' has a wrong offset!");
//static_assert(offsetof(FBlastBigChunkState, BigChunkBoxSize) == 0x000030, "Member 'FBlastBigChunkState::BigChunkBoxSize' has a wrong offset!");
//static_assert(offsetof(FBlastBigChunkState, Padding) == 0x00003C, "Member 'FBlastBigChunkState::Padding' has a wrong offset!");

// ScriptStruct BlastNiagara.BlastFXChunkState
// 0x0020 (0x0020 - 0x0000)
struct FBlastFXChunkState final
{
public:
	class UStaticMesh*                            FXMesh;                                            // 0x0000(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector3f                              PositionWS;                                        // 0x0008(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector3f                              RotationWS;                                        // 0x0014(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
//static_assert(alignof(FBlastFXChunkState) == 0x000008, "Wrong alignment on FBlastFXChunkState");
//static_assert(sizeof(FBlastFXChunkState) == 0x000020, "Wrong size on FBlastFXChunkState");
//static_assert(offsetof(FBlastFXChunkState, FXMesh) == 0x000000, "Member 'FBlastFXChunkState::FXMesh' has a wrong offset!");
//static_assert(offsetof(FBlastFXChunkState, PositionWS) == 0x000008, "Member 'FBlastFXChunkState::PositionWS' has a wrong offset!");
//static_assert(offsetof(FBlastFXChunkState, RotationWS) == 0x000014, "Member 'FBlastFXChunkState::RotationWS' has a wrong offset!");

// ScriptStruct BlastNiagara.BlastBigChunkBrokenMessage
// 0x0050 (0x0050 - 0x0000)
struct FBlastBigChunkBrokenMessage final
{
public:
	struct FBlastBigChunkState                    BigChunkState;                                     // 0x0000(0x0040)(NoDestructor, NativeAccessSpecifierPublic)
	TArray<struct FBlastFXChunkState>             FXChunkStates;                                     // 0x0040(0x0010)(ZeroConstructor, NativeAccessSpecifierPublic)
};
//static_assert(alignof(FBlastBigChunkBrokenMessage) == 0x000010, "Wrong alignment on FBlastBigChunkBrokenMessage");
//static_assert(sizeof(FBlastBigChunkBrokenMessage) == 0x000050, "Wrong size on FBlastBigChunkBrokenMessage");
//static_assert(offsetof(FBlastBigChunkBrokenMessage, BigChunkState) == 0x000000, "Member 'FBlastBigChunkBrokenMessage::BigChunkState' has a wrong offset!");
//static_assert(offsetof(FBlastBigChunkBrokenMessage, FXChunkStates) == 0x000040, "Member 'FBlastBigChunkBrokenMessage::FXChunkStates' has a wrong offset!");

// ScriptStruct BlastNiagara.BlastFXChunkParticleData
// 0x0020 (0x0020 - 0x0000)
struct FBlastFXChunkParticleData final
{
public:
	struct FVector3f                              Position;                                          // 0x0000(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint32                                        MeshIndex;                                         // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVector3f                              Rotation;                                          // 0x0010(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint32                                        FatherChunkDataIndex;                              // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};
//static_assert(alignof(FBlastFXChunkParticleData) == 0x000004, "Wrong alignment on FBlastFXChunkParticleData");
//static_assert(sizeof(FBlastFXChunkParticleData) == 0x000020, "Wrong size on FBlastFXChunkParticleData");
//static_assert(offsetof(FBlastFXChunkParticleData, Position) == 0x000000, "Member 'FBlastFXChunkParticleData::Position' has a wrong offset!");
//static_assert(offsetof(FBlastFXChunkParticleData, MeshIndex) == 0x00000C, "Member 'FBlastFXChunkParticleData::MeshIndex' has a wrong offset!");
//static_assert(offsetof(FBlastFXChunkParticleData, Rotation) == 0x000010, "Member 'FBlastFXChunkParticleData::Rotation' has a wrong offset!");
//static_assert(offsetof(FBlastFXChunkParticleData, FatherChunkDataIndex) == 0x00001C, "Member 'FBlastFXChunkParticleData::FatherChunkDataIndex' has a wrong offset!");

}

