#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyAbility_103863

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyAbility_103863.PyUIController_103863
// 0x0000 (0x0C60 - 0x0C60)
class UPyUIController_103863 final : public UUIC_Ability
{
public:
	void OnInit();
	void OnDestruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyUIController_103863">();
	}
	static class UPyUIController_103863* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyUIController_103863>();
	}
};
//static_assert(alignof(UPyUIController_103863) == 0x000008, "Wrong alignment on UPyUIController_103863");
//static_assert(sizeof(UPyUIController_103863) == 0x000C60, "Wrong size on UPyUIController_103863");

// PythonClass PyAbility_103863.PyAbility_103863
// 0x0038 (0x2818 - 0x27E0)
class UPyAbility_103863 : public UAbility_113
{
public:
	class AActor*                                 Shield;                                            // 0x27E0(0x0008)(BlueprintVisible, Net, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bCanSpawnProjectile;                               // 0x27E8(0x0001)(BlueprintVisible, Net, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_27E9[0x3];                                     // 0x27E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FStateChangedTaskParam                 ActiveUserSetting;                                 // 0x27EC(0x0028)(Edit, NoDestructor, NativeAccessSpecifierPublic)

public:
	void BeginPlay();
	bool CanActivateInteractiveAbility();
	void K2_ActivateAbility();
	void K2_OnEndAbility(bool bWasCancelled);
	void SetTargetActor();
	void NativeOnMontageEvent(const class FString& Tag);
	void OnAdsorbSucceed(class AActor* InActor);
	void OnAdsorbEnd();
	void SpawnObstacleSuccess(class AActor* SpawnActor);
	void OnSummonedEndAgentTask(class AActor* InActor);
	void OnPressFireInput(float TimeWaited);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyAbility_103863">();
	}
	static class UPyAbility_103863* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyAbility_103863>();
	}
};
//static_assert(alignof(UPyAbility_103863) == 0x000008, "Wrong alignment on UPyAbility_103863");
//static_assert(sizeof(UPyAbility_103863) == 0x002818, "Wrong size on UPyAbility_103863");
//static_assert(offsetof(UPyAbility_103863, Shield) == 0x0027E0, "Member 'UPyAbility_103863::Shield' has a wrong offset!");
//static_assert(offsetof(UPyAbility_103863, bCanSpawnProjectile) == 0x0027E8, "Member 'UPyAbility_103863::bCanSpawnProjectile' has a wrong offset!");
//static_assert(offsetof(UPyAbility_103863, ActiveUserSetting) == 0x0027EC, "Member 'UPyAbility_103863::ActiveUserSetting' has a wrong offset!");

// PythonClass PyAbility_103863.PyConfig_103863
// 0x10D0 (0x2260 - 0x1190)
class UPyConfig_103863 final : public UConfig_113
{
public:
	int32                                         SummonedID;                                        // 0x1190(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         LowHealthThreshold;                                // 0x1194(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SummonedStartFXTime;                               // 0x1198(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         ProjectileID;                                      // 0x119C(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         MaxProjectileNum;                                  // 0x11A0(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         LowHealthProjectileNum;                            // 0x11A4(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FVector>                        ProjectileRelativeLocation;                        // 0x11A8(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)
	uint8                                         Pad_11B8[0x8];                                     // 0x11B8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSelectTaskParam                       SelectParam;                                       // 0x11C0(0x10A0)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyConfig_103863">();
	}
	static class UPyConfig_103863* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyConfig_103863>();
	}
};
//static_assert(alignof(UPyConfig_103863) == 0x000010, "Wrong alignment on UPyConfig_103863");
//static_assert(sizeof(UPyConfig_103863) == 0x002260, "Wrong size on UPyConfig_103863");
//static_assert(offsetof(UPyConfig_103863, SummonedID) == 0x001190, "Member 'UPyConfig_103863::SummonedID' has a wrong offset!");
//static_assert(offsetof(UPyConfig_103863, LowHealthThreshold) == 0x001194, "Member 'UPyConfig_103863::LowHealthThreshold' has a wrong offset!");
//static_assert(offsetof(UPyConfig_103863, SummonedStartFXTime) == 0x001198, "Member 'UPyConfig_103863::SummonedStartFXTime' has a wrong offset!");
//static_assert(offsetof(UPyConfig_103863, ProjectileID) == 0x00119C, "Member 'UPyConfig_103863::ProjectileID' has a wrong offset!");
//static_assert(offsetof(UPyConfig_103863, MaxProjectileNum) == 0x0011A0, "Member 'UPyConfig_103863::MaxProjectileNum' has a wrong offset!");
//static_assert(offsetof(UPyConfig_103863, LowHealthProjectileNum) == 0x0011A4, "Member 'UPyConfig_103863::LowHealthProjectileNum' has a wrong offset!");
//static_assert(offsetof(UPyConfig_103863, ProjectileRelativeLocation) == 0x0011A8, "Member 'UPyConfig_103863::ProjectileRelativeLocation' has a wrong offset!");
//static_assert(offsetof(UPyConfig_103863, SelectParam) == 0x0011C0, "Member 'UPyConfig_103863::SelectParam' has a wrong offset!");

// PythonClass PyAbility_103863.PySummoned_10386301
// 0x0010 (0x08A0 - 0x0890)
class APySummoned_10386301 : public AMarvelSummonerBase
{
public:
	class UBoxComponent*                          BoxShield;                                         // 0x0890(0x0008)(Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PySummoned_10386301">();
	}
	static class APySummoned_10386301* GetDefaultObj()
	{
		return GetDefaultObjImpl<APySummoned_10386301>();
	}
};
//static_assert(alignof(APySummoned_10386301) == 0x000010, "Wrong alignment on APySummoned_10386301");
//static_assert(sizeof(APySummoned_10386301) == 0x0008A0, "Wrong size on APySummoned_10386301");
//static_assert(offsetof(APySummoned_10386301, BoxShield) == 0x000890, "Member 'APySummoned_10386301::BoxShield' has a wrong offset!");

}

