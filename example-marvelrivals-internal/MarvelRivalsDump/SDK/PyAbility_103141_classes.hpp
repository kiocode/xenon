#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_103141

#include "Basic.hpp"

#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyAbility_103141.PyUIController_103142
// 0x0000 (0x0C60 - 0x0C60)
class UPyUIController_103142 final : public UUIC_Ability
{
public:
	void SetAbility(int32 InAbilityId, class UGameplayAbility* InAbility);
	void OnSwitchAbilityForOldController();
	void OnSwitchAbilityForNewController();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyUIController_103142">();
	}
	static class UPyUIController_103142* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyUIController_103142>();
	}
};
static_assert(alignof(UPyUIController_103142) == 0x000008, "Wrong alignment on UPyUIController_103142");
static_assert(sizeof(UPyUIController_103142) == 0x000C60, "Wrong size on UPyUIController_103142");

// PythonClass PyAbility_103141.PyAbility_103141
// 0x0000 (0x2588 - 0x2588)
class UPyAbility_103141 : public UAbility_108
{
public:
	void K2_EndAbilityWithChecked();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyAbility_103141">();
	}
	static class UPyAbility_103141* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyAbility_103141>();
	}
};
static_assert(alignof(UPyAbility_103141) == 0x000008, "Wrong alignment on UPyAbility_103141");
static_assert(sizeof(UPyAbility_103141) == 0x002588, "Wrong size on UPyAbility_103141");

// PythonClass PyAbility_103141.PyUIController_103141
// 0x0010 (0x0C70 - 0x0C60)
class UPyUIController_103141 : public UUIC_Ability
{
public:
	class UTexture2D*                             EnhancedIcon;                                      // 0x0C60(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             NormalIcon;                                        // 0x0C68(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInit();
	void SetAbility(int32 InAbilityId, class UGameplayAbility* InAbility);
	void Destruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyUIController_103141">();
	}
	static class UPyUIController_103141* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyUIController_103141>();
	}
};
static_assert(alignof(UPyUIController_103141) == 0x000008, "Wrong alignment on UPyUIController_103141");
static_assert(sizeof(UPyUIController_103141) == 0x000C70, "Wrong size on UPyUIController_103141");
static_assert(offsetof(UPyUIController_103141, EnhancedIcon) == 0x000C60, "Member 'UPyUIController_103141::EnhancedIcon' has a wrong offset!");
static_assert(offsetof(UPyUIController_103141, NormalIcon) == 0x000C68, "Member 'UPyUIController_103141::NormalIcon' has a wrong offset!");

// PythonClass PyAbility_103141.PyCue_Scope_HitImpact_10314201
// 0x0000 (0x04D0 - 0x04D0)
class UPyCue_Scope_HitImpact_10314201 : public UMarvelCueNotify_HitImpact
{
public:
	void OnNiagaraSpawned(class UNiagaraComponent* InFXComponent, class AActor* MyTarget, const struct FGameplayCueParameters& Parameters);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Scope_HitImpact_10314201">();
	}
	static class UPyCue_Scope_HitImpact_10314201* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyCue_Scope_HitImpact_10314201>();
	}
};
static_assert(alignof(UPyCue_Scope_HitImpact_10314201) == 0x000008, "Wrong alignment on UPyCue_Scope_HitImpact_10314201");
static_assert(sizeof(UPyCue_Scope_HitImpact_10314201) == 0x0004D0, "Wrong size on UPyCue_Scope_HitImpact_10314201");

}

