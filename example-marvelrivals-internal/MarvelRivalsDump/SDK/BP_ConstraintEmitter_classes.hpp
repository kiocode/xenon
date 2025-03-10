#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ConstraintEmitter

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ConstraintEmitter.BP_ConstraintEmitter_C
// 0x00B8 (0x0548 - 0x0490)
class ABP_ConstraintEmitter_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0490(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UNiagaraComponent*                      NS_103614_Hit_01;                                  // 0x0498(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UNiagaraComponent*                      NS_104251_Hit_01;                                  // 0x04A0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UDestructionConstraintComponent*        DestructionConstraint;                             // 0x04A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Sphere;                                            // 0x04B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Web;                                               // 0x04B8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x04C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UChildActorComponent*                   Cue_Cable_BP;                                      // 0x04C8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         ____0______0_69E1C79641358D69169565A6005F3FCE;     // 0x04D0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            ____0__Direction_69E1C79641358D69169565A6005F3FCE; // 0x04D4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4D5[0x3];                                      // 0x04D5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     __t_0;                                             // 0x04D8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	float                                         _________0_E7885DBC44AA7C3BD160B98F6053B2E3;       // 0x04E0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            _____Direction_E7885DBC44AA7C3BD160B98F6053B2E3;   // 0x04E4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4E5[0x3];                                      // 0x04E5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     __t;                                               // 0x04E8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	float                                         ____1______0_C2303BF943B30787BFE615953097E48B;     // 0x04F0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            ____1__Direction_C2303BF943B30787BFE615953097E48B; // 0x04F4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4F5[0x3];                                      // 0x04F5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     __t_1;                                             // 0x04F8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	double                                        NewVar;                                            // 0x0500(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        NewVar_0;                                          // 0x0508(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 Cube;                                              // 0x0510(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, NoDestructor, HasGetValueTypeHash)
	class UDestructionCableComponent*             NewVar_1;                                          // 0x0518(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 Cube_0;                                            // 0x0520(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               WebMat;                                            // 0x0528(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	bool                                          IsSetLimit;                                        // 0x0530(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_531[0x7];                                      // 0x0531(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInterface*                     Source_Material;                                   // 0x0538(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	double                                        NewVar_2;                                          // 0x0540(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void __t__UpdateFunc();
	void __t__FinishedFunc();
	void __t_1__UpdateFunc();
	void __t_1__FinishedFunc();
	void __t_0__UpdateFunc();
	void __t_0__FinishedFunc();
	void SetWebRotation();
	void SetLimit();
	void ReceiveTick(float DeltaSeconds);
	void ReceiveBeginPlay();
	struct FRotator GetAimRotation();
	double GetAimLength();
	void ExecuteUbergraph_BP_ConstraintEmitter(int32 EntryPoint);
	void BreakWeb();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ConstraintEmitter_C">();
	}
	static class ABP_ConstraintEmitter_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ConstraintEmitter_C>();
	}
};
//static_assert(alignof(ABP_ConstraintEmitter_C) == 0x000008, "Wrong alignment on ABP_ConstraintEmitter_C");
//static_assert(sizeof(ABP_ConstraintEmitter_C) == 0x000548, "Wrong size on ABP_ConstraintEmitter_C");
//static_assert(offsetof(ABP_ConstraintEmitter_C, UberGraphFrame) == 0x000490, "Member 'ABP_ConstraintEmitter_C::UberGraphFrame' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, NS_103614_Hit_01) == 0x000498, "Member 'ABP_ConstraintEmitter_C::NS_103614_Hit_01' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, NS_104251_Hit_01) == 0x0004A0, "Member 'ABP_ConstraintEmitter_C::NS_104251_Hit_01' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, DestructionConstraint) == 0x0004A8, "Member 'ABP_ConstraintEmitter_C::DestructionConstraint' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, Sphere) == 0x0004B0, "Member 'ABP_ConstraintEmitter_C::Sphere' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, Web) == 0x0004B8, "Member 'ABP_ConstraintEmitter_C::Web' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, StaticMesh) == 0x0004C0, "Member 'ABP_ConstraintEmitter_C::StaticMesh' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, Cue_Cable_BP) == 0x0004C8, "Member 'ABP_ConstraintEmitter_C::Cue_Cable_BP' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, ____0______0_69E1C79641358D69169565A6005F3FCE) == 0x0004D0, "Member 'ABP_ConstraintEmitter_C::____0______0_69E1C79641358D69169565A6005F3FCE' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, ____0__Direction_69E1C79641358D69169565A6005F3FCE) == 0x0004D4, "Member 'ABP_ConstraintEmitter_C::____0__Direction_69E1C79641358D69169565A6005F3FCE' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, __t_0) == 0x0004D8, "Member 'ABP_ConstraintEmitter_C::__t_0' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, _________0_E7885DBC44AA7C3BD160B98F6053B2E3) == 0x0004E0, "Member 'ABP_ConstraintEmitter_C::_________0_E7885DBC44AA7C3BD160B98F6053B2E3' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, _____Direction_E7885DBC44AA7C3BD160B98F6053B2E3) == 0x0004E4, "Member 'ABP_ConstraintEmitter_C::_____Direction_E7885DBC44AA7C3BD160B98F6053B2E3' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, __t) == 0x0004E8, "Member 'ABP_ConstraintEmitter_C::__t' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, ____1______0_C2303BF943B30787BFE615953097E48B) == 0x0004F0, "Member 'ABP_ConstraintEmitter_C::____1______0_C2303BF943B30787BFE615953097E48B' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, ____1__Direction_C2303BF943B30787BFE615953097E48B) == 0x0004F4, "Member 'ABP_ConstraintEmitter_C::____1__Direction_C2303BF943B30787BFE615953097E48B' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, __t_1) == 0x0004F8, "Member 'ABP_ConstraintEmitter_C::__t_1' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, NewVar) == 0x000500, "Member 'ABP_ConstraintEmitter_C::NewVar' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, NewVar_0) == 0x000508, "Member 'ABP_ConstraintEmitter_C::NewVar_0' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, Cube) == 0x000510, "Member 'ABP_ConstraintEmitter_C::Cube' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, NewVar_1) == 0x000518, "Member 'ABP_ConstraintEmitter_C::NewVar_1' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, Cube_0) == 0x000520, "Member 'ABP_ConstraintEmitter_C::Cube_0' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, WebMat) == 0x000528, "Member 'ABP_ConstraintEmitter_C::WebMat' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, IsSetLimit) == 0x000530, "Member 'ABP_ConstraintEmitter_C::IsSetLimit' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, Source_Material) == 0x000538, "Member 'ABP_ConstraintEmitter_C::Source_Material' has a wrong offset!");
//static_assert(offsetof(ABP_ConstraintEmitter_C, NewVar_2) == 0x000540, "Member 'ABP_ConstraintEmitter_C::NewVar_2' has a wrong offset!");

}

