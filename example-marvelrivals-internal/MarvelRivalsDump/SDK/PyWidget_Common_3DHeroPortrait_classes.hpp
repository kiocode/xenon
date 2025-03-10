#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_Common_3DHeroPortrait

#include "Basic.hpp"

#include "UMG_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_Common_3DHeroPortrait.PyWidget_Common_3DHeroPortrait
// 0x0028 (0x03E0 - 0x03B8)
class UPyWidget_Common_3DHeroPortrait final : public UUserWidget
{
public:
	class UTexture2D*                             HeroCardMask;                                      // 0x03B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnLoadShowActorFinished;                           // 0x03C0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)
	FMulticastInlineDelegateProperty_             OnViewShowActorChanged;                            // 0x03D0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnLoadShowActorFinished__DelegateSignature();
	void OnViewShowActorChanged__DelegateSignature();
	void OnInitialized();
	void PreConstruct(bool IsDesignTime);
	void Construct();
	void Destruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_Common_3DHeroPortrait">();
	}
	static class UPyWidget_Common_3DHeroPortrait* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_Common_3DHeroPortrait>();
	}
};
static_assert(alignof(UPyWidget_Common_3DHeroPortrait) == 0x000008, "Wrong alignment on UPyWidget_Common_3DHeroPortrait");
static_assert(sizeof(UPyWidget_Common_3DHeroPortrait) == 0x0003E0, "Wrong size on UPyWidget_Common_3DHeroPortrait");
static_assert(offsetof(UPyWidget_Common_3DHeroPortrait, HeroCardMask) == 0x0003B8, "Member 'UPyWidget_Common_3DHeroPortrait::HeroCardMask' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_3DHeroPortrait, OnLoadShowActorFinished) == 0x0003C0, "Member 'UPyWidget_Common_3DHeroPortrait::OnLoadShowActorFinished' has a wrong offset!");
static_assert(offsetof(UPyWidget_Common_3DHeroPortrait, OnViewShowActorChanged) == 0x0003D0, "Member 'UPyWidget_Common_3DHeroPortrait::OnViewShowActorChanged' has a wrong offset!");

}

