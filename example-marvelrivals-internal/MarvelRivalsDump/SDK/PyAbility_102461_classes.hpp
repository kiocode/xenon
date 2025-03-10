#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_102461

#include "Basic.hpp"

#include "Hero_1024_classes.hpp"
#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyAbility_102461.PyProjectile_102461
// 0x0010 (0x3060 - 0x3050)
class APyProjectile_102461 : public AMarvelAbilityTargetActor_Projectile
{
public:
	int32                                         ScopeId;                                           // 0x3050(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void K2_OnBeginAgentTask();
	void K2_OnFlyOverMaxDistance(const struct FHitResult& HitResult);
	void K2_OnProcessHit(const struct FHitResult& ImpactResult);
	void K2_OnEndAgentTask();
	void K2_OnProjectileInfoForceChanged_ThreadSafe(const struct FProjectileForceChangedInfo& InProjectileForceChangedInfo);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyProjectile_102461">();
	}
	static class APyProjectile_102461* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyProjectile_102461>();
	}
};
static_assert(alignof(APyProjectile_102461) == 0x000010, "Wrong alignment on APyProjectile_102461");
static_assert(sizeof(APyProjectile_102461) == 0x003060, "Wrong size on APyProjectile_102461");
static_assert(offsetof(APyProjectile_102461, ScopeId) == 0x003050, "Member 'APyProjectile_102461::ScopeId' has a wrong offset!");

// PythonClass PyAbility_102461.PyScope_10246101
// 0x0010 (0x1710 - 0x1700)
class APyScope_10246101 final : public AMarvelAbilityTargetActor_Scope
{
public:
	int32                                         BuffID;                                            // 0x1700(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void K2_OnBeginAgentTask();
	void OnTraceResults(const TArray<struct FHitResult>& HitResults);
	void K2_OnEndAgentTask();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyScope_10246101">();
	}
	static class APyScope_10246101* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyScope_10246101>();
	}
};
static_assert(alignof(APyScope_10246101) == 0x000010, "Wrong alignment on APyScope_10246101");
static_assert(sizeof(APyScope_10246101) == 0x001710, "Wrong size on APyScope_10246101");
static_assert(offsetof(APyScope_10246101, BuffID) == 0x001700, "Member 'APyScope_10246101::BuffID' has a wrong offset!");

// PythonClass PyAbility_102461.PyConfig_102461
// 0x0008 (0x0C48 - 0x0C40)
class UPyConfig_102461 final : public UConfig_102461
{
public:
	int32                                         ProjectileID;                                      // 0x0C40(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyConfig_102461">();
	}
	static class UPyConfig_102461* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyConfig_102461>();
	}
};
static_assert(alignof(UPyConfig_102461) == 0x000008, "Wrong alignment on UPyConfig_102461");
static_assert(sizeof(UPyConfig_102461) == 0x000C48, "Wrong size on UPyConfig_102461");
static_assert(offsetof(UPyConfig_102461, ProjectileID) == 0x000C40, "Member 'UPyConfig_102461::ProjectileID' has a wrong offset!");

// PythonClass PyAbility_102461.PyAbility_102461
// 0x0010 (0x2598 - 0x2588)
class UPyAbility_102461 : public UAbility_108
{
public:
	FMulticastInlineDelegateProperty_             OnSoulLinkEnemy;                                   // 0x2588(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnSoulLinkEnemy__DelegateSignature(const TArray<class AActor*>& TargetList);
	void BeginPlay();
	void NativeOnMontageInterrupted(const class FString& Tag);
	void NativeOnMontageCancelled(const class FString& Tag);
	void HandleAnimSocketInfo(int32 SocketId, const struct FMarvelAbilitySocketInfo& SocketInfo);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyAbility_102461">();
	}
	static class UPyAbility_102461* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyAbility_102461>();
	}
};
static_assert(alignof(UPyAbility_102461) == 0x000008, "Wrong alignment on UPyAbility_102461");
static_assert(sizeof(UPyAbility_102461) == 0x002598, "Wrong size on UPyAbility_102461");
static_assert(offsetof(UPyAbility_102461, OnSoulLinkEnemy) == 0x002588, "Member 'UPyAbility_102461::OnSoulLinkEnemy' has a wrong offset!");

// PythonClass PyAbility_102461.PyCue_Buff_10246103
// 0x0018 (0x1050 - 0x1038)
class APyCue_Buff_10246103 final : public AMarvelCueNotify_Buff
{
public:
	class UFXSystemAsset*                         LinkLineFXAsset;                                   // 0x1038(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FName                                   LinkLineFXPramName;                                // 0x1040(0x000C)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void WhileActiveFX(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);
	void OnRemoveFX(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Buff_10246103">();
	}
	static class APyCue_Buff_10246103* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyCue_Buff_10246103>();
	}
};
static_assert(alignof(APyCue_Buff_10246103) == 0x000008, "Wrong alignment on APyCue_Buff_10246103");
static_assert(sizeof(APyCue_Buff_10246103) == 0x001050, "Wrong size on APyCue_Buff_10246103");
static_assert(offsetof(APyCue_Buff_10246103, LinkLineFXAsset) == 0x001038, "Member 'APyCue_Buff_10246103::LinkLineFXAsset' has a wrong offset!");
static_assert(offsetof(APyCue_Buff_10246103, LinkLineFXPramName) == 0x001040, "Member 'APyCue_Buff_10246103::LinkLineFXPramName' has a wrong offset!");

// PythonClass PyAbility_102461.PyCue_Projectile_Loop_10246101
// 0x0020 (0x0DD0 - 0x0DB0)
class APyCue_Projectile_Loop_10246101 final : public AMarvelCueNotify_Projectile
{
public:
	class UFXSystemAsset*                         GroundFX;                                          // 0x0DB0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<class AActor*>                         Ignores;                                           // 0x0DB8(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	float                                         DecalCheckHeight;                                  // 0x0DC8(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnExecuteFX(class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Projectile_Loop_10246101">();
	}
	static class APyCue_Projectile_Loop_10246101* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyCue_Projectile_Loop_10246101>();
	}
};
static_assert(alignof(APyCue_Projectile_Loop_10246101) == 0x000008, "Wrong alignment on APyCue_Projectile_Loop_10246101");
static_assert(sizeof(APyCue_Projectile_Loop_10246101) == 0x000DD0, "Wrong size on APyCue_Projectile_Loop_10246101");
static_assert(offsetof(APyCue_Projectile_Loop_10246101, GroundFX) == 0x000DB0, "Member 'APyCue_Projectile_Loop_10246101::GroundFX' has a wrong offset!");
static_assert(offsetof(APyCue_Projectile_Loop_10246101, Ignores) == 0x000DB8, "Member 'APyCue_Projectile_Loop_10246101::Ignores' has a wrong offset!");
static_assert(offsetof(APyCue_Projectile_Loop_10246101, DecalCheckHeight) == 0x000DC8, "Member 'APyCue_Projectile_Loop_10246101::DecalCheckHeight' has a wrong offset!");

}

