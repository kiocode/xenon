#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_101542

#include "Basic.hpp"

#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyAbility_101542.PyConfig_101542
// 0x0030 (0x00C8 - 0x0098)
class UPyConfig_101542 final : public UMarvelAbilityConfig
{
public:
	struct FStateChangedTaskParam                 ActiveUserSetting;                                 // 0x0098(0x0028)(Edit, NoDestructor, NativeAccessSpecifierPublic)
	float                                         ActiveWaitTime;                                    // 0x00C0(0x0004)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyConfig_101542">();
	}
	static class UPyConfig_101542* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyConfig_101542>();
	}
};
static_assert(alignof(UPyConfig_101542) == 0x000008, "Wrong alignment on UPyConfig_101542");
static_assert(sizeof(UPyConfig_101542) == 0x0000C8, "Wrong size on UPyConfig_101542");
static_assert(offsetof(UPyConfig_101542, ActiveUserSetting) == 0x000098, "Member 'UPyConfig_101542::ActiveUserSetting' has a wrong offset!");
static_assert(offsetof(UPyConfig_101542, ActiveWaitTime) == 0x0000C0, "Member 'UPyConfig_101542::ActiveWaitTime' has a wrong offset!");

// PythonClass PyAbility_101542.PyAbility_101542
// 0x0000 (0x2580 - 0x2580)
class UPyAbility_101542 : public UMarvelGameplayAbility
{
public:
	void BeginPlay();
	void EndPlay();
	bool CanActivate();
	void K2_ActivateAbility();
	void K2_OnEndAbility(bool bCanceled);
	void NativeOnMontageEvent(const class FString& EventTag);
	void NativeOnMontageCompleted(const class FString& EventTag);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyAbility_101542">();
	}
	static class UPyAbility_101542* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyAbility_101542>();
	}
};
static_assert(alignof(UPyAbility_101542) == 0x000008, "Wrong alignment on UPyAbility_101542");
static_assert(sizeof(UPyAbility_101542) == 0x002580, "Wrong size on UPyAbility_101542");

// PythonClass PyAbility_101542.PyUIController_101542
// 0x0010 (0x0C70 - 0x0C60)
class UPyUIController_101542 final : public UUIC_Ability
{
public:
	class UTexture2D*                             StormWeatherAbilityIcon;                           // 0x0C60(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             ThunderWeatherAbilityIcon;                         // 0x0C68(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void SetAbility(int32 InAbilityId, class UGameplayAbility* InAbility);
	void OnDestruct();
	void OnOwnedTagUpdate(const struct FGameplayTag& InTag, bool bInExist);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyUIController_101542">();
	}
	static class UPyUIController_101542* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyUIController_101542>();
	}
};
static_assert(alignof(UPyUIController_101542) == 0x000008, "Wrong alignment on UPyUIController_101542");
static_assert(sizeof(UPyUIController_101542) == 0x000C70, "Wrong size on UPyUIController_101542");
static_assert(offsetof(UPyUIController_101542, StormWeatherAbilityIcon) == 0x000C60, "Member 'UPyUIController_101542::StormWeatherAbilityIcon' has a wrong offset!");
static_assert(offsetof(UPyUIController_101542, ThunderWeatherAbilityIcon) == 0x000C68, "Member 'UPyUIController_101542::ThunderWeatherAbilityIcon' has a wrong offset!");

}

