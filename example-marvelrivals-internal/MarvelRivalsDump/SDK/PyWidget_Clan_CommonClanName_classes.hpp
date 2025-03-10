#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_Clan_CommonClanName

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "SlateCore_structs.hpp"
#include "PyMarvelUserWidget_classes.hpp"


namespace SDK
{

// PythonClass PyWidget_Clan_CommonClanName.PyWidget_CommonClanMiniName
// 0x0088 (0x0678 - 0x05F0)
class UPyWidget_CommonClanMiniName : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x3];                                      // 0x05E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           ClanIconColor;                                     // 0x05EC(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5FC[0x4];                                      // 0x05FC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateFontInfo                         ClanMiniNameFont;                                  // 0x0600(0x0068)(Edit, BlueprintVisible, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ClanMiniNamePSFontSize;                            // 0x0668(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ClanOpacity;                                       // 0x066C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ClanMainColor;                                     // 0x0670(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ClanTeamColor;                                     // 0x0674(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void PreConstruct(bool IsDesignTime);
	void Construct();
	void Destruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_CommonClanMiniName">();
	}
	static class UPyWidget_CommonClanMiniName* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_CommonClanMiniName>();
	}
};
static_assert(alignof(UPyWidget_CommonClanMiniName) == 0x000008, "Wrong alignment on UPyWidget_CommonClanMiniName");
static_assert(sizeof(UPyWidget_CommonClanMiniName) == 0x000678, "Wrong size on UPyWidget_CommonClanMiniName");
static_assert(offsetof(UPyWidget_CommonClanMiniName, ClanIconColor) == 0x0005EC, "Member 'UPyWidget_CommonClanMiniName::ClanIconColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanMiniName, ClanMiniNameFont) == 0x000600, "Member 'UPyWidget_CommonClanMiniName::ClanMiniNameFont' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanMiniName, ClanMiniNamePSFontSize) == 0x000668, "Member 'UPyWidget_CommonClanMiniName::ClanMiniNamePSFontSize' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanMiniName, ClanOpacity) == 0x00066C, "Member 'UPyWidget_CommonClanMiniName::ClanOpacity' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanMiniName, ClanMainColor) == 0x000670, "Member 'UPyWidget_CommonClanMiniName::ClanMainColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanMiniName, ClanTeamColor) == 0x000674, "Member 'UPyWidget_CommonClanMiniName::ClanTeamColor' has a wrong offset!");

// PythonClass PyWidget_Clan_CommonClanName.PyWidget_CommonClanName
// 0x0088 (0x0678 - 0x05F0)
class UPyWidget_CommonClanName final : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x3];                                      // 0x05E9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           ClanNameColor;                                     // 0x05EC(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5FC[0x4];                                      // 0x05FC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSlateFontInfo                         ClanNameFont;                                      // 0x0600(0x0068)(Edit, BlueprintVisible, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ClanNamePSFontSize;                                // 0x0668(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ClanOpacity;                                       // 0x066C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ClanMainColor;                                     // 0x0670(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ClanTeamColor;                                     // 0x0674(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void PreConstruct(bool IsDesignTime);
	void Construct();
	void Destruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_CommonClanName">();
	}
	static class UPyWidget_CommonClanName* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_CommonClanName>();
	}
};
static_assert(alignof(UPyWidget_CommonClanName) == 0x000008, "Wrong alignment on UPyWidget_CommonClanName");
static_assert(sizeof(UPyWidget_CommonClanName) == 0x000678, "Wrong size on UPyWidget_CommonClanName");
static_assert(offsetof(UPyWidget_CommonClanName, ClanNameColor) == 0x0005EC, "Member 'UPyWidget_CommonClanName::ClanNameColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanName, ClanNameFont) == 0x000600, "Member 'UPyWidget_CommonClanName::ClanNameFont' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanName, ClanNamePSFontSize) == 0x000668, "Member 'UPyWidget_CommonClanName::ClanNamePSFontSize' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanName, ClanOpacity) == 0x00066C, "Member 'UPyWidget_CommonClanName::ClanOpacity' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanName, ClanMainColor) == 0x000670, "Member 'UPyWidget_CommonClanName::ClanMainColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_CommonClanName, ClanTeamColor) == 0x000674, "Member 'UPyWidget_CommonClanName::ClanTeamColor' has a wrong offset!");

}

