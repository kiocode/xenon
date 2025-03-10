#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_LocalBattleKillTest

#include "Basic.hpp"

#include "PyMarvelUserWidget_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_LocalBattleKillTest.PyWidget_LocalBattleKillPanelUnit
// 0x00C0 (0x0668 - 0x05A8)
class UPyWidget_LocalBattleKillPanelUnit : public UMarvelUserWidget
{
public:
	float                                         ExistTime;                                         // 0x05A8(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         KillInfoDelayDisplayTime;                          // 0x05AC(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bOverrideColor;                                    // 0x05B0(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5B1[0x3];                                      // 0x05B1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           BaseColor;                                         // 0x05B4(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLinearColor                           HighlightColor;                                    // 0x05C4(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLinearColor                           CacheBaseColor;                                    // 0x05D4(0x0010)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLinearColor                           CacheHighlightColor;                               // 0x05E4(0x0010)(BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bOverrideFontColor;                                // 0x05F4(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5F5[0x3];                                      // 0x05F5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           FontTopColor;                                      // 0x05F8(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FLinearColor                           FontButtomColor;                                   // 0x0608(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bCustomColorPreview;                               // 0x0618(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bUseStyleTable;                                    // 0x0619(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_61A[0x6];                                      // 0x061A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UDataTable*                             StyleTable;                                        // 0x0620(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                         PreviewHeroID;                                     // 0x0628(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_62C[0x4];                                      // 0x062C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UTexture2D*>                     AngleTextures;                                     // 0x0630(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	TArray<class UTexture2D*>                     AngleGlowTextures;                                 // 0x0640(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	TArray<class UMaterialInstance*>              AngleVXMaterials;                                  // 0x0650(0x0010)(Edit, BlueprintVisible, BlueprintReadOnly, NativeAccessSpecifierPublic)
	class UMaterialInstance*                      AngleVXMaterial_Upstoppable;                       // 0x0660(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void PreConstruct(bool IsDesignTime);
	void Construct();
	void Destruct();
	void OnAnimationFinished(const class UWidgetAnimation* Animation);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_LocalBattleKillPanelUnit">();
	}
	static class UPyWidget_LocalBattleKillPanelUnit* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_LocalBattleKillPanelUnit>();
	}
};
static_assert(alignof(UPyWidget_LocalBattleKillPanelUnit) == 0x000008, "Wrong alignment on UPyWidget_LocalBattleKillPanelUnit");
static_assert(sizeof(UPyWidget_LocalBattleKillPanelUnit) == 0x000668, "Wrong size on UPyWidget_LocalBattleKillPanelUnit");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, ExistTime) == 0x0005A8, "Member 'UPyWidget_LocalBattleKillPanelUnit::ExistTime' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, KillInfoDelayDisplayTime) == 0x0005AC, "Member 'UPyWidget_LocalBattleKillPanelUnit::KillInfoDelayDisplayTime' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, bOverrideColor) == 0x0005B0, "Member 'UPyWidget_LocalBattleKillPanelUnit::bOverrideColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, BaseColor) == 0x0005B4, "Member 'UPyWidget_LocalBattleKillPanelUnit::BaseColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, HighlightColor) == 0x0005C4, "Member 'UPyWidget_LocalBattleKillPanelUnit::HighlightColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, CacheBaseColor) == 0x0005D4, "Member 'UPyWidget_LocalBattleKillPanelUnit::CacheBaseColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, CacheHighlightColor) == 0x0005E4, "Member 'UPyWidget_LocalBattleKillPanelUnit::CacheHighlightColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, bOverrideFontColor) == 0x0005F4, "Member 'UPyWidget_LocalBattleKillPanelUnit::bOverrideFontColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, FontTopColor) == 0x0005F8, "Member 'UPyWidget_LocalBattleKillPanelUnit::FontTopColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, FontButtomColor) == 0x000608, "Member 'UPyWidget_LocalBattleKillPanelUnit::FontButtomColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, bCustomColorPreview) == 0x000618, "Member 'UPyWidget_LocalBattleKillPanelUnit::bCustomColorPreview' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, bUseStyleTable) == 0x000619, "Member 'UPyWidget_LocalBattleKillPanelUnit::bUseStyleTable' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, StyleTable) == 0x000620, "Member 'UPyWidget_LocalBattleKillPanelUnit::StyleTable' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, PreviewHeroID) == 0x000628, "Member 'UPyWidget_LocalBattleKillPanelUnit::PreviewHeroID' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, AngleTextures) == 0x000630, "Member 'UPyWidget_LocalBattleKillPanelUnit::AngleTextures' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, AngleGlowTextures) == 0x000640, "Member 'UPyWidget_LocalBattleKillPanelUnit::AngleGlowTextures' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, AngleVXMaterials) == 0x000650, "Member 'UPyWidget_LocalBattleKillPanelUnit::AngleVXMaterials' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit, AngleVXMaterial_Upstoppable) == 0x000660, "Member 'UPyWidget_LocalBattleKillPanelUnit::AngleVXMaterial_Upstoppable' has a wrong offset!");

// PythonClass PyWidget_LocalBattleKillTest.PyWidget_LocalBattleKillPanel
// 0x0060 (0x0650 - 0x05F0)
class UPyWidget_LocalBattleKillPanel : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x7];                                      // 0x05E9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSubclassOf<class UUserWidget>                Class_KillText;                                    // 0x05F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class UUserWidget>                Class_KillReticle;                                 // 0x05F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class UUserWidget>                Class_PickupText;                                  // 0x0600(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TSubclassOf<class UUserWidget>                Class_KillStreak;                                  // 0x0608(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         MinimalMsgInterval;                                // 0x0610(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         CenterKillShowInterval;                            // 0x0614(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          ShowSingleKillInfo;                                // 0x0618(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          DisplayHighlight;                                  // 0x0619(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_61A[0x6];                                      // 0x061A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UDataTable*                             KillFeedbackTable;                                 // 0x0620(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class FText                                   BondAssistKillSuffix;                              // 0x0628(0x0018)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	TArray<int32>                                 ComboAbilityIDs;                                   // 0x0640(0x0010)(BlueprintVisible, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void Construct();
	void Destruct();
	void OnKillingSpreeCountChanged(int32 Count, class AMarvelPlayerState* PS);
	void OnPickUpKillConfirm(class AActor* Item, class AMarvelPlayerState* PlayerState, EBattleSide BattleSide, bool IsAlly);
	void OnActorDeathDispatcher(class AActor* Source, class AActor* Target, const struct FAttributeModifierHandle& ModifierHandle, const struct FGlobalEventExtraData& ExtraData);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_LocalBattleKillPanel">();
	}
	static class UPyWidget_LocalBattleKillPanel* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_LocalBattleKillPanel>();
	}
};
static_assert(alignof(UPyWidget_LocalBattleKillPanel) == 0x000008, "Wrong alignment on UPyWidget_LocalBattleKillPanel");
static_assert(sizeof(UPyWidget_LocalBattleKillPanel) == 0x000650, "Wrong size on UPyWidget_LocalBattleKillPanel");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, Class_KillText) == 0x0005F0, "Member 'UPyWidget_LocalBattleKillPanel::Class_KillText' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, Class_KillReticle) == 0x0005F8, "Member 'UPyWidget_LocalBattleKillPanel::Class_KillReticle' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, Class_PickupText) == 0x000600, "Member 'UPyWidget_LocalBattleKillPanel::Class_PickupText' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, Class_KillStreak) == 0x000608, "Member 'UPyWidget_LocalBattleKillPanel::Class_KillStreak' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, MinimalMsgInterval) == 0x000610, "Member 'UPyWidget_LocalBattleKillPanel::MinimalMsgInterval' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, CenterKillShowInterval) == 0x000614, "Member 'UPyWidget_LocalBattleKillPanel::CenterKillShowInterval' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, ShowSingleKillInfo) == 0x000618, "Member 'UPyWidget_LocalBattleKillPanel::ShowSingleKillInfo' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, DisplayHighlight) == 0x000619, "Member 'UPyWidget_LocalBattleKillPanel::DisplayHighlight' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, KillFeedbackTable) == 0x000620, "Member 'UPyWidget_LocalBattleKillPanel::KillFeedbackTable' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, BondAssistKillSuffix) == 0x000628, "Member 'UPyWidget_LocalBattleKillPanel::BondAssistKillSuffix' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanel, ComboAbilityIDs) == 0x000640, "Member 'UPyWidget_LocalBattleKillPanel::ComboAbilityIDs' has a wrong offset!");

// PythonClass PyWidget_LocalBattleKillTest.PyWidget_LocalBattleKillPanelUnit_V3
// 0x0060 (0x0608 - 0x05A8)
class UPyWidget_LocalBattleKillPanelUnit_V3 final : public UMarvelUserWidget
{
public:
	class UTexture2D*                             SpikeK2;                                           // 0x05A8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             SpikeK3;                                           // 0x05B0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             SpikeK4;                                           // 0x05B8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             SpikeK5;                                           // 0x05C0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             SpikeK6;                                           // 0x05C8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             NormalKillTex;                                     // 0x05D0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             HeadShotTex;                                       // 0x05D8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             TerrainTex;                                        // 0x05E0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             AssistTex;                                         // 0x05E8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             ParticipateTex;                                    // 0x05F0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UDataTable*                             HeroCombatHighlightTable;                          // 0x05F8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ExistTime;                                         // 0x0600(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         KillInfoDelayDisplayTime;                          // 0x0604(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void Construct();
	void Destruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_LocalBattleKillPanelUnit_V3">();
	}
	static class UPyWidget_LocalBattleKillPanelUnit_V3* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_LocalBattleKillPanelUnit_V3>();
	}
};
static_assert(alignof(UPyWidget_LocalBattleKillPanelUnit_V3) == 0x000008, "Wrong alignment on UPyWidget_LocalBattleKillPanelUnit_V3");
static_assert(sizeof(UPyWidget_LocalBattleKillPanelUnit_V3) == 0x000608, "Wrong size on UPyWidget_LocalBattleKillPanelUnit_V3");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, SpikeK2) == 0x0005A8, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::SpikeK2' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, SpikeK3) == 0x0005B0, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::SpikeK3' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, SpikeK4) == 0x0005B8, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::SpikeK4' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, SpikeK5) == 0x0005C0, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::SpikeK5' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, SpikeK6) == 0x0005C8, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::SpikeK6' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, NormalKillTex) == 0x0005D0, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::NormalKillTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, HeadShotTex) == 0x0005D8, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::HeadShotTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, TerrainTex) == 0x0005E0, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::TerrainTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, AssistTex) == 0x0005E8, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::AssistTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, ParticipateTex) == 0x0005F0, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::ParticipateTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, HeroCombatHighlightTable) == 0x0005F8, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::HeroCombatHighlightTable' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, ExistTime) == 0x000600, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::ExistTime' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelUnit_V3, KillInfoDelayDisplayTime) == 0x000604, "Member 'UPyWidget_LocalBattleKillPanelUnit_V3::KillInfoDelayDisplayTime' has a wrong offset!");

// PythonClass PyWidget_LocalBattleKillTest.PyWidget_LocalBattleKillPanelCenter
// 0x0090 (0x0638 - 0x05A8)
class UPyWidget_LocalBattleKillPanelCenter : public UMarvelUserWidget
{
public:
	class UTexture2D*                             NormalKillTex;                                     // 0x05A8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             HeadShotTex;                                       // 0x05B0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             AssistTex;                                         // 0x05B8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             ParticipateTex;                                    // 0x05C0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             SummonedKillTex;                                   // 0x05C8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             BondAssistTex;                                     // 0x05D0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             BG_NormalKillTex;                                  // 0x05D8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             BG_HeadShotTex;                                    // 0x05E0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             BG_AssistTex;                                      // 0x05E8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             BG_ParticipateTex;                                 // 0x05F0(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             BG_SummonedKillTex;                                // 0x05F8(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UTexture2D*                             BG_BondAssistTex;                                  // 0x0600(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UDataTable*                             HeroCombatHighlightTable;                          // 0x0608(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UDataTable*                             SummonedKillInfoTable;                             // 0x0610(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ExistTime;                                         // 0x0618(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         KillInfoDelayDisplayTime;                          // 0x061C(0x0004)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UAkAudioEvent*                          AkEvent_ParticipateKill;                           // 0x0620(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UAkAudioEvent*                          AkEvent_Assist;                                    // 0x0628(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UAkAudioEvent*                          AkEvent_SummonKill;                                // 0x0630(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void Construct();
	void Destruct();
	void OnAnimationFinished(const class UWidgetAnimation* Animation);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_LocalBattleKillPanelCenter">();
	}
	static class UPyWidget_LocalBattleKillPanelCenter* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_LocalBattleKillPanelCenter>();
	}
};
static_assert(alignof(UPyWidget_LocalBattleKillPanelCenter) == 0x000008, "Wrong alignment on UPyWidget_LocalBattleKillPanelCenter");
static_assert(sizeof(UPyWidget_LocalBattleKillPanelCenter) == 0x000638, "Wrong size on UPyWidget_LocalBattleKillPanelCenter");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, NormalKillTex) == 0x0005A8, "Member 'UPyWidget_LocalBattleKillPanelCenter::NormalKillTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, HeadShotTex) == 0x0005B0, "Member 'UPyWidget_LocalBattleKillPanelCenter::HeadShotTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, AssistTex) == 0x0005B8, "Member 'UPyWidget_LocalBattleKillPanelCenter::AssistTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, ParticipateTex) == 0x0005C0, "Member 'UPyWidget_LocalBattleKillPanelCenter::ParticipateTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, SummonedKillTex) == 0x0005C8, "Member 'UPyWidget_LocalBattleKillPanelCenter::SummonedKillTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, BondAssistTex) == 0x0005D0, "Member 'UPyWidget_LocalBattleKillPanelCenter::BondAssistTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, BG_NormalKillTex) == 0x0005D8, "Member 'UPyWidget_LocalBattleKillPanelCenter::BG_NormalKillTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, BG_HeadShotTex) == 0x0005E0, "Member 'UPyWidget_LocalBattleKillPanelCenter::BG_HeadShotTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, BG_AssistTex) == 0x0005E8, "Member 'UPyWidget_LocalBattleKillPanelCenter::BG_AssistTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, BG_ParticipateTex) == 0x0005F0, "Member 'UPyWidget_LocalBattleKillPanelCenter::BG_ParticipateTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, BG_SummonedKillTex) == 0x0005F8, "Member 'UPyWidget_LocalBattleKillPanelCenter::BG_SummonedKillTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, BG_BondAssistTex) == 0x000600, "Member 'UPyWidget_LocalBattleKillPanelCenter::BG_BondAssistTex' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, HeroCombatHighlightTable) == 0x000608, "Member 'UPyWidget_LocalBattleKillPanelCenter::HeroCombatHighlightTable' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, SummonedKillInfoTable) == 0x000610, "Member 'UPyWidget_LocalBattleKillPanelCenter::SummonedKillInfoTable' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, ExistTime) == 0x000618, "Member 'UPyWidget_LocalBattleKillPanelCenter::ExistTime' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, KillInfoDelayDisplayTime) == 0x00061C, "Member 'UPyWidget_LocalBattleKillPanelCenter::KillInfoDelayDisplayTime' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, AkEvent_ParticipateKill) == 0x000620, "Member 'UPyWidget_LocalBattleKillPanelCenter::AkEvent_ParticipateKill' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, AkEvent_Assist) == 0x000628, "Member 'UPyWidget_LocalBattleKillPanelCenter::AkEvent_Assist' has a wrong offset!");
static_assert(offsetof(UPyWidget_LocalBattleKillPanelCenter, AkEvent_SummonKill) == 0x000630, "Member 'UPyWidget_LocalBattleKillPanelCenter::AkEvent_SummonKill' has a wrong offset!");

// PythonClass PyWidget_LocalBattleKillTest.PyWidget_LocalBattleKillReticleCenter
// 0x0008 (0x05B0 - 0x05A8)
class UPyWidget_LocalBattleKillReticleCenter : public UMarvelUserWidget
{
public:
	bool                                          bCustomColorPreview;                               // 0x05A8(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void PreConstruct(bool IsDesignTime);
	void Construct();
	void Destruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_LocalBattleKillReticleCenter">();
	}
	static class UPyWidget_LocalBattleKillReticleCenter* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_LocalBattleKillReticleCenter>();
	}
};
static_assert(alignof(UPyWidget_LocalBattleKillReticleCenter) == 0x000008, "Wrong alignment on UPyWidget_LocalBattleKillReticleCenter");
static_assert(sizeof(UPyWidget_LocalBattleKillReticleCenter) == 0x0005B0, "Wrong size on UPyWidget_LocalBattleKillReticleCenter");
static_assert(offsetof(UPyWidget_LocalBattleKillReticleCenter, bCustomColorPreview) == 0x0005A8, "Member 'UPyWidget_LocalBattleKillReticleCenter::bCustomColorPreview' has a wrong offset!");

}

