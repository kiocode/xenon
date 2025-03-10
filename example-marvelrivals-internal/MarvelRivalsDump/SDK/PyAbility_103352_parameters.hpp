#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_103352

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK::Params
{

// PythonFunction PyAbility_103352.PyCue_Scope_Start_10335201.OnExecuteFX
// 0x01C0 (0x01C0 - 0x0000)
struct PyCue_Scope_Start_10335201_OnExecuteFX final
{
public:
	class AActor*                                 MyTarget;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                 Parameters;                                        // 0x0008(0x01B8)(ConstParm, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(PyCue_Scope_Start_10335201_OnExecuteFX) == 0x000008, "Wrong alignment on PyCue_Scope_Start_10335201_OnExecuteFX");
static_assert(sizeof(PyCue_Scope_Start_10335201_OnExecuteFX) == 0x0001C0, "Wrong size on PyCue_Scope_Start_10335201_OnExecuteFX");
static_assert(offsetof(PyCue_Scope_Start_10335201_OnExecuteFX, MyTarget) == 0x000000, "Member 'PyCue_Scope_Start_10335201_OnExecuteFX::MyTarget' has a wrong offset!");
static_assert(offsetof(PyCue_Scope_Start_10335201_OnExecuteFX, Parameters) == 0x000008, "Member 'PyCue_Scope_Start_10335201_OnExecuteFX::Parameters' has a wrong offset!");

// PythonFunction PyAbility_103352.PyCue_Scope_Start_10335201.SetFXParameter
// 0x01C8 (0x01C8 - 0x0000)
struct PyCue_Scope_Start_10335201_SetFXParameter final
{
public:
	class UNiagaraComponent*                      InFXComponent;                                     // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	const class AActor*                           MyTarget;                                          // 0x0008(0x0008)(ConstParm, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                 Parameters;                                        // 0x0010(0x01B8)(ConstParm, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(PyCue_Scope_Start_10335201_SetFXParameter) == 0x000008, "Wrong alignment on PyCue_Scope_Start_10335201_SetFXParameter");
static_assert(sizeof(PyCue_Scope_Start_10335201_SetFXParameter) == 0x0001C8, "Wrong size on PyCue_Scope_Start_10335201_SetFXParameter");
static_assert(offsetof(PyCue_Scope_Start_10335201_SetFXParameter, InFXComponent) == 0x000000, "Member 'PyCue_Scope_Start_10335201_SetFXParameter::InFXComponent' has a wrong offset!");
static_assert(offsetof(PyCue_Scope_Start_10335201_SetFXParameter, MyTarget) == 0x000008, "Member 'PyCue_Scope_Start_10335201_SetFXParameter::MyTarget' has a wrong offset!");
static_assert(offsetof(PyCue_Scope_Start_10335201_SetFXParameter, Parameters) == 0x000010, "Member 'PyCue_Scope_Start_10335201_SetFXParameter::Parameters' has a wrong offset!");

// PythonFunction PyAbility_103352.PyProjectile_10335201.K2_OnProcessHit
// 0x0170 (0x0170 - 0x0000)
struct PyProjectile_10335201_K2_OnProcessHit final
{
public:
	struct FHitResult                             ImpactResult;                                      // 0x0000(0x0170)(ConstParm, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(PyProjectile_10335201_K2_OnProcessHit) == 0x000008, "Wrong alignment on PyProjectile_10335201_K2_OnProcessHit");
static_assert(sizeof(PyProjectile_10335201_K2_OnProcessHit) == 0x000170, "Wrong size on PyProjectile_10335201_K2_OnProcessHit");
static_assert(offsetof(PyProjectile_10335201_K2_OnProcessHit, ImpactResult) == 0x000000, "Member 'PyProjectile_10335201_K2_OnProcessHit::ImpactResult' has a wrong offset!");

// PythonFunction PyAbility_103352.PyProjectile_10335202.K2_OnBounce
// 0x0188 (0x0188 - 0x0000)
struct PyProjectile_10335202_K2_OnBounce final
{
public:
	struct FHitResult                             ImpactResult;                                      // 0x0000(0x0170)(ConstParm, Parm, OutParm, ReferenceParm)
	struct FVector                                ImpactVelocity;                                    // 0x0170(0x0018)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyProjectile_10335202_K2_OnBounce) == 0x000008, "Wrong alignment on PyProjectile_10335202_K2_OnBounce");
static_assert(sizeof(PyProjectile_10335202_K2_OnBounce) == 0x000188, "Wrong size on PyProjectile_10335202_K2_OnBounce");
static_assert(offsetof(PyProjectile_10335202_K2_OnBounce, ImpactResult) == 0x000000, "Member 'PyProjectile_10335202_K2_OnBounce::ImpactResult' has a wrong offset!");
static_assert(offsetof(PyProjectile_10335202_K2_OnBounce, ImpactVelocity) == 0x000170, "Member 'PyProjectile_10335202_K2_OnBounce::ImpactVelocity' has a wrong offset!");

// PythonFunction PyAbility_103352.PyAbility_103352.CanActivate
// 0x0001 (0x0001 - 0x0000)
struct PyAbility_103352_CanActivate final
{
public:
	bool                                          ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_103352_CanActivate) == 0x000001, "Wrong alignment on PyAbility_103352_CanActivate");
static_assert(sizeof(PyAbility_103352_CanActivate) == 0x000001, "Wrong size on PyAbility_103352_CanActivate");
static_assert(offsetof(PyAbility_103352_CanActivate, ReturnValue) == 0x000000, "Member 'PyAbility_103352_CanActivate::ReturnValue' has a wrong offset!");

// PythonFunction PyAbility_103352.PyAbility_103352.OnPreLoadedSummonedSpawned
// 0x0008 (0x0008 - 0x0000)
struct PyAbility_103352_OnPreLoadedSummonedSpawned final
{
public:
	class AActor*                                 SpawnedActor;                                      // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_103352_OnPreLoadedSummonedSpawned) == 0x000008, "Wrong alignment on PyAbility_103352_OnPreLoadedSummonedSpawned");
static_assert(sizeof(PyAbility_103352_OnPreLoadedSummonedSpawned) == 0x000008, "Wrong size on PyAbility_103352_OnPreLoadedSummonedSpawned");
static_assert(offsetof(PyAbility_103352_OnPreLoadedSummonedSpawned, SpawnedActor) == 0x000000, "Member 'PyAbility_103352_OnPreLoadedSummonedSpawned::SpawnedActor' has a wrong offset!");

// PythonFunction PyAbility_103352.PyAbility_103352.K2_OnEndAbility
// 0x0001 (0x0001 - 0x0000)
struct PyAbility_103352_K2_OnEndAbility final
{
public:
	bool                                          bWasCancelled;                                     // 0x0000(0x0001)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_103352_K2_OnEndAbility) == 0x000001, "Wrong alignment on PyAbility_103352_K2_OnEndAbility");
static_assert(sizeof(PyAbility_103352_K2_OnEndAbility) == 0x000001, "Wrong size on PyAbility_103352_K2_OnEndAbility");
static_assert(offsetof(PyAbility_103352_K2_OnEndAbility, bWasCancelled) == 0x000000, "Member 'PyAbility_103352_K2_OnEndAbility::bWasCancelled' has a wrong offset!");

// PythonFunction PyAbility_103352.PyAbility_103352.NativeOnMontageEvent
// 0x0010 (0x0010 - 0x0000)
struct PyAbility_103352_NativeOnMontageEvent final
{
public:
	class FString                                 Tag;                                               // 0x0000(0x0010)(Parm, ZeroConstructor, HasGetValueTypeHash)
};
static_assert(alignof(PyAbility_103352_NativeOnMontageEvent) == 0x000008, "Wrong alignment on PyAbility_103352_NativeOnMontageEvent");
static_assert(sizeof(PyAbility_103352_NativeOnMontageEvent) == 0x000010, "Wrong size on PyAbility_103352_NativeOnMontageEvent");
static_assert(offsetof(PyAbility_103352_NativeOnMontageEvent, Tag) == 0x000000, "Member 'PyAbility_103352_NativeOnMontageEvent::Tag' has a wrong offset!");

// PythonFunction PyAbility_103352.PyCue_Ability_Loop_10335201.WhileActive
// 0x01C8 (0x01C8 - 0x0000)
struct PyCue_Ability_Loop_10335201_WhileActive final
{
public:
	class AActor*                                 MyTarget;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                 Parameters;                                        // 0x0008(0x01B8)(ConstParm, Parm, OutParm, ReferenceParm)
	bool                                          ReturnValue;                                       // 0x01C0(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyCue_Ability_Loop_10335201_WhileActive) == 0x000008, "Wrong alignment on PyCue_Ability_Loop_10335201_WhileActive");
static_assert(sizeof(PyCue_Ability_Loop_10335201_WhileActive) == 0x0001C8, "Wrong size on PyCue_Ability_Loop_10335201_WhileActive");
static_assert(offsetof(PyCue_Ability_Loop_10335201_WhileActive, MyTarget) == 0x000000, "Member 'PyCue_Ability_Loop_10335201_WhileActive::MyTarget' has a wrong offset!");
static_assert(offsetof(PyCue_Ability_Loop_10335201_WhileActive, Parameters) == 0x000008, "Member 'PyCue_Ability_Loop_10335201_WhileActive::Parameters' has a wrong offset!");
static_assert(offsetof(PyCue_Ability_Loop_10335201_WhileActive, ReturnValue) == 0x0001C0, "Member 'PyCue_Ability_Loop_10335201_WhileActive::ReturnValue' has a wrong offset!");

// PythonFunction PyAbility_103352.PyCue_Ability_Loop_10335201.OnRemove
// 0x01C8 (0x01C8 - 0x0000)
struct PyCue_Ability_Loop_10335201_OnRemove final
{
public:
	class AActor*                                 MyTarget;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                 Parameters;                                        // 0x0008(0x01B8)(ConstParm, Parm, OutParm, ReferenceParm)
	bool                                          ReturnValue;                                       // 0x01C0(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyCue_Ability_Loop_10335201_OnRemove) == 0x000008, "Wrong alignment on PyCue_Ability_Loop_10335201_OnRemove");
static_assert(sizeof(PyCue_Ability_Loop_10335201_OnRemove) == 0x0001C8, "Wrong size on PyCue_Ability_Loop_10335201_OnRemove");
static_assert(offsetof(PyCue_Ability_Loop_10335201_OnRemove, MyTarget) == 0x000000, "Member 'PyCue_Ability_Loop_10335201_OnRemove::MyTarget' has a wrong offset!");
static_assert(offsetof(PyCue_Ability_Loop_10335201_OnRemove, Parameters) == 0x000008, "Member 'PyCue_Ability_Loop_10335201_OnRemove::Parameters' has a wrong offset!");
static_assert(offsetof(PyCue_Ability_Loop_10335201_OnRemove, ReturnValue) == 0x0001C0, "Member 'PyCue_Ability_Loop_10335201_OnRemove::ReturnValue' has a wrong offset!");

// PythonFunction PyAbility_103352.PyCue_Ability_Loop_10335201.OnExecute
// 0x01C8 (0x01C8 - 0x0000)
struct PyCue_Ability_Loop_10335201_OnExecute final
{
public:
	class AActor*                                 MyTarget;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                 Parameters;                                        // 0x0008(0x01B8)(ConstParm, Parm, OutParm, ReferenceParm)
	bool                                          ReturnValue;                                       // 0x01C0(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PyCue_Ability_Loop_10335201_OnExecute) == 0x000008, "Wrong alignment on PyCue_Ability_Loop_10335201_OnExecute");
static_assert(sizeof(PyCue_Ability_Loop_10335201_OnExecute) == 0x0001C8, "Wrong size on PyCue_Ability_Loop_10335201_OnExecute");
static_assert(offsetof(PyCue_Ability_Loop_10335201_OnExecute, MyTarget) == 0x000000, "Member 'PyCue_Ability_Loop_10335201_OnExecute::MyTarget' has a wrong offset!");
static_assert(offsetof(PyCue_Ability_Loop_10335201_OnExecute, Parameters) == 0x000008, "Member 'PyCue_Ability_Loop_10335201_OnExecute::Parameters' has a wrong offset!");
static_assert(offsetof(PyCue_Ability_Loop_10335201_OnExecute, ReturnValue) == 0x0001C0, "Member 'PyCue_Ability_Loop_10335201_OnExecute::ReturnValue' has a wrong offset!");

// PythonFunction PyAbility_103352.PyCue_Projectile_Loop_10335201.WhileActiveFX
// 0x01C0 (0x01C0 - 0x0000)
struct PyCue_Projectile_Loop_10335201_WhileActiveFX final
{
public:
	class AActor*                                 MyTarget;                                          // 0x0000(0x0008)(Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                 Parameters;                                        // 0x0008(0x01B8)(ConstParm, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(PyCue_Projectile_Loop_10335201_WhileActiveFX) == 0x000008, "Wrong alignment on PyCue_Projectile_Loop_10335201_WhileActiveFX");
static_assert(sizeof(PyCue_Projectile_Loop_10335201_WhileActiveFX) == 0x0001C0, "Wrong size on PyCue_Projectile_Loop_10335201_WhileActiveFX");
static_assert(offsetof(PyCue_Projectile_Loop_10335201_WhileActiveFX, MyTarget) == 0x000000, "Member 'PyCue_Projectile_Loop_10335201_WhileActiveFX::MyTarget' has a wrong offset!");
static_assert(offsetof(PyCue_Projectile_Loop_10335201_WhileActiveFX, Parameters) == 0x000008, "Member 'PyCue_Projectile_Loop_10335201_WhileActiveFX::Parameters' has a wrong offset!");

}

