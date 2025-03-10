#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyCue_Weapon_Loop_101401

#include "Basic.hpp"

#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass PyCue_Weapon_Loop_101401.PyCue_Weapon_Loop_101401
// 0x0018 (0x10C0 - 0x10A8)
class APyCue_Weapon_Loop_101401 final : public AMarvelCueNotify_Weapon_Loop
{
public:
	class UCurveFloat*                            ShowDissolveCurve1;                                // 0x10A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UCurveFloat*                            ShowDissolveCurve2;                                // 0x10B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	class UCurveFloat*                            ShowDissolveCurve3;                                // 0x10B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyCue_Weapon_Loop_101401">();
	}
	static class APyCue_Weapon_Loop_101401* GetDefaultObj()
	{
		return GetDefaultObjImpl<APyCue_Weapon_Loop_101401>();
	}
};
static_assert(alignof(APyCue_Weapon_Loop_101401) == 0x000008, "Wrong alignment on APyCue_Weapon_Loop_101401");
static_assert(sizeof(APyCue_Weapon_Loop_101401) == 0x0010C0, "Wrong size on APyCue_Weapon_Loop_101401");
static_assert(offsetof(APyCue_Weapon_Loop_101401, ShowDissolveCurve1) == 0x0010A8, "Member 'APyCue_Weapon_Loop_101401::ShowDissolveCurve1' has a wrong offset!");
static_assert(offsetof(APyCue_Weapon_Loop_101401, ShowDissolveCurve2) == 0x0010B0, "Member 'APyCue_Weapon_Loop_101401::ShowDissolveCurve2' has a wrong offset!");
static_assert(offsetof(APyCue_Weapon_Loop_101401, ShowDissolveCurve3) == 0x0010B8, "Member 'APyCue_Weapon_Loop_101401::ShowDissolveCurve3' has a wrong offset!");

}

