#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget3D__SummonedMarker

#include "Basic.hpp"

#include "Marvel_structs.hpp"
#include "Marvel_classes.hpp"
#include "DeclarativeUnreal_structs.hpp"


namespace SDK
{

// PythonClass PyWidget3D__SummonedMarker.PyWidget3D_SummonedMarker
// 0x0040 (0x08E0 - 0x08A0)
#pragma pack(push, 0x1)
class alignas(0x10) UPyWidget3D_SummonedMarker : public UMarvel3DWidget
{
public:
	uint8                                         Pad_898[0x8];                                      // 0x0898(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDeclarationHolder                     ViewerSideWatcher;                                 // 0x08A0(0x0010)(NativeAccessSpecifierPublic)
	struct FDeclarationHolder                     ViewingCharacterWatcher;                           // 0x08B0(0x0010)(NativeAccessSpecifierPublic)
	TArray<int32>                                 VisibleAllyHeroIDs;                                // 0x08C0(0x0010)(Edit, NativeAccessSpecifierPublic)
	bool                                          IsShowCountdown;                                   // 0x08D0(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          bCustomColorPreview;                               // 0x08D1(0x0001)(Edit, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void PreConstruct(bool IsDesignTime);
	void Construct();
	void Destruct();
	void OwnerGameplayActorChanged();
	void OwnerCueWhileActive();
	void OwnerCueActiveChanged();
	void SetViewerSide(EClientPlayerViewSide ViewSide);
	void SetViewingCharacter(class AActor* ViewingCharacter);
	bool ShouldBeVisible();
	void OnAnimationStarted(const class UWidgetAnimation* Animation);
	void OnAnimationFinished(const class UWidgetAnimation* Animation);
	void StartHandlerSignal(const struct FSignalResult& Result);
	void EndHandlerSignal(const struct FSignalResult& Result);
	void MarvelVisibilityChanged();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget3D_SummonedMarker">();
	}
	static class UPyWidget3D_SummonedMarker* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget3D_SummonedMarker>();
	}
};
#pragma pack(pop)
static_assert(alignof(UPyWidget3D_SummonedMarker) == 0x000010, "Wrong alignment on UPyWidget3D_SummonedMarker");
static_assert(sizeof(UPyWidget3D_SummonedMarker) == 0x0008E0, "Wrong size on UPyWidget3D_SummonedMarker");
static_assert(offsetof(UPyWidget3D_SummonedMarker, ViewerSideWatcher) == 0x0008A0, "Member 'UPyWidget3D_SummonedMarker::ViewerSideWatcher' has a wrong offset!");
static_assert(offsetof(UPyWidget3D_SummonedMarker, ViewingCharacterWatcher) == 0x0008B0, "Member 'UPyWidget3D_SummonedMarker::ViewingCharacterWatcher' has a wrong offset!");
static_assert(offsetof(UPyWidget3D_SummonedMarker, VisibleAllyHeroIDs) == 0x0008C0, "Member 'UPyWidget3D_SummonedMarker::VisibleAllyHeroIDs' has a wrong offset!");
static_assert(offsetof(UPyWidget3D_SummonedMarker, IsShowCountdown) == 0x0008D0, "Member 'UPyWidget3D_SummonedMarker::IsShowCountdown' has a wrong offset!");
static_assert(offsetof(UPyWidget3D_SummonedMarker, bCustomColorPreview) == 0x0008D1, "Member 'UPyWidget3D_SummonedMarker::bCustomColorPreview' has a wrong offset!");

}

