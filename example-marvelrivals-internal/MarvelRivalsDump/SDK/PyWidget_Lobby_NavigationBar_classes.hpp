#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_Lobby_NavigationBar

#include "Basic.hpp"

#include "PyWidget_Common_NavigationBar_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_Lobby_NavigationBar.PyWidget_Lobby_NavigationBar
// 0x0000 (0x0780 - 0x0780)
class UPyWidget_Lobby_NavigationBar final : public UPyWidget_Common_NavigationBar
{
public:
	void OnInitialized();
	void Construct();
	void Destruct();
	bool GetEnableRegisterInputContextBp();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_Lobby_NavigationBar">();
	}
	static class UPyWidget_Lobby_NavigationBar* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_Lobby_NavigationBar>();
	}
};
static_assert(alignof(UPyWidget_Lobby_NavigationBar) == 0x000008, "Wrong alignment on UPyWidget_Lobby_NavigationBar");
static_assert(sizeof(UPyWidget_Lobby_NavigationBar) == 0x000780, "Wrong size on UPyWidget_Lobby_NavigationBar");

}

