#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AttachedBackGun_MK47

#include "Basic.hpp"

#include "AttachedBackGun_base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass AttachedBackGun_MK47.AttachedBackGun_MK47_C
// 0x0038 (0x02A0 - 0x0268)
class AAttachedBackGun_MK47_C final : public AAttachedBackGun_base_C
{
public:
	class UStaticMeshComponent*                   SM_Wep_Mod_A_Stock;                                // 0x0268(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   SM_Wep_Mod_A_Handguard_01;                         // 0x0270(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   SM_Wep_Mod_A_Handguard_02;                         // 0x0278(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Scope_front;                                       // 0x0280(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Trigger;                                           // 0x0288(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   SM_Wep_Mod_A_handle;                               // 0x0290(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   SM_Wep_Mod_A_Barrel;                               // 0x0298(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AttachedBackGun_MK47_C">();
	}
	static class AAttachedBackGun_MK47_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AAttachedBackGun_MK47_C>();
	}
};
static_assert(alignof(AAttachedBackGun_MK47_C) == 0x000008, "Wrong alignment on AAttachedBackGun_MK47_C");
static_assert(sizeof(AAttachedBackGun_MK47_C) == 0x0002A0, "Wrong size on AAttachedBackGun_MK47_C");
static_assert(offsetof(AAttachedBackGun_MK47_C, SM_Wep_Mod_A_Stock) == 0x000268, "Member 'AAttachedBackGun_MK47_C::SM_Wep_Mod_A_Stock' has a wrong offset!");
static_assert(offsetof(AAttachedBackGun_MK47_C, SM_Wep_Mod_A_Handguard_01) == 0x000270, "Member 'AAttachedBackGun_MK47_C::SM_Wep_Mod_A_Handguard_01' has a wrong offset!");
static_assert(offsetof(AAttachedBackGun_MK47_C, SM_Wep_Mod_A_Handguard_02) == 0x000278, "Member 'AAttachedBackGun_MK47_C::SM_Wep_Mod_A_Handguard_02' has a wrong offset!");
static_assert(offsetof(AAttachedBackGun_MK47_C, Scope_front) == 0x000280, "Member 'AAttachedBackGun_MK47_C::Scope_front' has a wrong offset!");
static_assert(offsetof(AAttachedBackGun_MK47_C, Trigger) == 0x000288, "Member 'AAttachedBackGun_MK47_C::Trigger' has a wrong offset!");
static_assert(offsetof(AAttachedBackGun_MK47_C, SM_Wep_Mod_A_handle) == 0x000290, "Member 'AAttachedBackGun_MK47_C::SM_Wep_Mod_A_handle' has a wrong offset!");
static_assert(offsetof(AAttachedBackGun_MK47_C, SM_Wep_Mod_A_Barrel) == 0x000298, "Member 'AAttachedBackGun_MK47_C::SM_Wep_Mod_A_Barrel' has a wrong offset!");

}

