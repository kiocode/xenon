#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_AbilityStatus_V1

#include "Basic.hpp"

#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_AbilityStatus_V1.PyWidget_AbilityStatusPanel_V1
// 0x0000 (0x0460 - 0x0460)
class UPyWidget_AbilityStatusPanel_V1 : public UWidget_AbilityStatusPanel
{
public:
	class UWidget_AbilityEnergy_Charge* GetEnergyChargeWidget();
	class UWidget_AbilityActionTips* GetActionTips();
	class UWidget_AbilityEnergy* GetEnergyWidget(EEnergyWidgetType WidgetType);
	class UWidget_AbilityDuration* GetDurationWidget(EWidgetPosition BarPosition);
	void OnSpecialVXPlay(EMarvelAbilityUIHudAnim ShakeMode);
	void RemoveWeaponWidget(class UUserWidget* InWidget);
	void SetVisible(bool Invisible);
	void HideStateHint(const struct FCueHintData& HintData);
	void ShowStateHint(const struct FCueHintData& HintData);
	void AddOtherWidget(class UUserWidget* InWidget, EAbilityStatusWidgetType Type);
	void AddWidget(class UUserWidget* InWidget);
	void ClearCommonWidget();
	void AddWeaponWidget(class UUserWidget* InWidget, int32 WeaponIndex);
	void AddAbilityWidget(class UUserWidget* InWidget, int32 SlotIndex);
	void OnAbilityWidgetLoaded(int32 AbilityID);
	void PreAddAbilityWidget(int32 AbilityID);
	void SetTargetActor(class AActor* InActor);
	void Construct();
	void OnInitialized();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_AbilityStatusPanel_V1">();
	}
	static class UPyWidget_AbilityStatusPanel_V1* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_AbilityStatusPanel_V1>();
	}
};
static_assert(alignof(UPyWidget_AbilityStatusPanel_V1) == 0x000008, "Wrong alignment on UPyWidget_AbilityStatusPanel_V1");
static_assert(sizeof(UPyWidget_AbilityStatusPanel_V1) == 0x000460, "Wrong size on UPyWidget_AbilityStatusPanel_V1");

}

