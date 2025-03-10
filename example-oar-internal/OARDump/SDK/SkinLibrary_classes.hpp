#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SkinLibrary

#include "Basic.hpp"

#include "Engine_classes.hpp"
#include "ShopItemCategory_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass SkinLibrary.SkinLibrary_C
// 0x0000 (0x0028 - 0x0028)
class USkinLibrary_C final : public UBlueprintFunctionLibrary
{
public:
	static void Get_Current_Rotation_Number(class UObject* __WorldContext, int32* Rotation_number, struct FTimespan* Time_left);
	static void GetCoinBundleSkin(int32 Rotation, EShopItemCategory Type, bool Can_be_already_owned_, int32 Number, class UObject* __WorldContext, class UClass** Skin);
	static void SkinsInCoinBundle(class UObject* __WorldContext, TArray<class UClass*>* Skins);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SkinLibrary_C">();
	}
	static class USkinLibrary_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USkinLibrary_C>();
	}
};
static_assert(alignof(USkinLibrary_C) == 0x000008, "Wrong alignment on USkinLibrary_C");
static_assert(sizeof(USkinLibrary_C) == 0x000028, "Wrong size on USkinLibrary_C");

}

