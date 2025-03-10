#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_SingleActiveWidget

#include "Basic.hpp"

#include "PyMarvelUserWidget_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_SingleActiveWidget.PySingleActiveWidget
// 0x0010 (0x0600 - 0x05F0)
class UPySingleActiveWidget : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x7];                                      // 0x05E9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnActivationChanged;                               // 0x05F0(0x0010)(ZeroConstructor, InstancedReference, BlueprintAssignable, BlueprintCallable, NativeAccessSpecifierPublic)

public:
	void OnActivationChanged__DelegateSignature(bool Activation);
	void OnInitialized();
	void Construct();
	void Destruct();
	void MarvelSetVisible(bool Visible);
	void MarvelSetVisibleImmediately(bool Visible);
	void MarvelVisibilityChanged();
	void OnCascadingVisibleChanged(bool bVisible_0);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PySingleActiveWidget">();
	}
	static class UPySingleActiveWidget* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPySingleActiveWidget>();
	}
};
static_assert(alignof(UPySingleActiveWidget) == 0x000008, "Wrong alignment on UPySingleActiveWidget");
static_assert(sizeof(UPySingleActiveWidget) == 0x000600, "Wrong size on UPySingleActiveWidget");
static_assert(offsetof(UPySingleActiveWidget, OnActivationChanged) == 0x0005F0, "Member 'UPySingleActiveWidget::OnActivationChanged' has a wrong offset!");

}

