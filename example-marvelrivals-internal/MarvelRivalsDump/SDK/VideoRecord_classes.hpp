#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: VideoRecord

#include "Basic.hpp"

#include "Marvel_classes.hpp"


namespace SDK
{

// PythonClass VideoRecord.UISettingVideoRecordParam
// 0x0000 (0x0030 - 0x0030)
class UUISettingVideoRecordParam final : public UUISettingEntrySettingHandler
{
public:
	TMap<class FString, int32> BP_OnBtnClicked(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingVideoRecordParam">();
	}
	static class UUISettingVideoRecordParam* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingVideoRecordParam>();
	}
};
//static_assert(alignof(UUISettingVideoRecordParam) == 0x000008, "Wrong alignment on UUISettingVideoRecordParam");
//static_assert(sizeof(UUISettingVideoRecordParam) == 0x000030, "Wrong size on UUISettingVideoRecordParam");

// PythonClass VideoRecord.UISettingVideoRecordOpenPath
// 0x0000 (0x0030 - 0x0030)
class UUISettingVideoRecordOpenPath final : public UUISettingEntrySettingHandler
{
public:
	TMap<class FString, int32> BP_OnBtnClicked(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingVideoRecordOpenPath">();
	}
	static class UUISettingVideoRecordOpenPath* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingVideoRecordOpenPath>();
	}
};
//static_assert(alignof(UUISettingVideoRecordOpenPath) == 0x000008, "Wrong alignment on UUISettingVideoRecordOpenPath");
//static_assert(sizeof(UUISettingVideoRecordOpenPath) == 0x000030, "Wrong size on UUISettingVideoRecordOpenPath");

// PythonClass VideoRecord.UISettingVideoRecordChangePath
// 0x0000 (0x0030 - 0x0030)
class UUISettingVideoRecordChangePath final : public UUISettingEntrySettingHandler
{
public:
	TMap<class FString, int32> BP_OnBtnClicked(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingVideoRecordChangePath">();
	}
	static class UUISettingVideoRecordChangePath* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingVideoRecordChangePath>();
	}
};
//static_assert(alignof(UUISettingVideoRecordChangePath) == 0x000008, "Wrong alignment on UUISettingVideoRecordChangePath");
//static_assert(sizeof(UUISettingVideoRecordChangePath) == 0x000030, "Wrong size on UUISettingVideoRecordChangePath");

}

