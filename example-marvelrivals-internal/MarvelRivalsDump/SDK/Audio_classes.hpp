#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Audio

#include "Basic.hpp"

#include "Marvel_classes.hpp"
#include "PyDefaultUISettingEntryHandler_classes.hpp"


namespace SDK
{

// PythonClass Audio.UISettingEntryInputDeviceHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingEntryInputDeviceHandler final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingEntryInputDeviceHandler">();
	}
	static class UUISettingEntryInputDeviceHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingEntryInputDeviceHandler>();
	}
};
//static_assert(alignof(UUISettingEntryInputDeviceHandler) == 0x000008, "Wrong alignment on UUISettingEntryInputDeviceHandler");
//static_assert(sizeof(UUISettingEntryInputDeviceHandler) == 0x000030, "Wrong size on UUISettingEntryInputDeviceHandler");

// PythonClass Audio.UISettingEntryVolumeHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingEntryVolumeHandler final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);
	float BP_GetDefaultValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingEntryVolumeHandler">();
	}
	static class UUISettingEntryVolumeHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingEntryVolumeHandler>();
	}
};
//static_assert(alignof(UUISettingEntryVolumeHandler) == 0x000008, "Wrong alignment on UUISettingEntryVolumeHandler");
//static_assert(sizeof(UUISettingEntryVolumeHandler) == 0x000030, "Wrong size on UUISettingEntryVolumeHandler");

// PythonClass Audio.UISettingEntryInputDeviceOptionGenerator
// 0x0000 (0x0030 - 0x0030)
class UUISettingEntryInputDeviceOptionGenerator final : public UUISettingEntryOptionsGenerator
{
public:
	TMap<int32, class FText> BP_Gen(class UObject* Obj, const class FString& Setting_key, const TMap<int32, class FText>& OPTIONS);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingEntryInputDeviceOptionGenerator">();
	}
	static class UUISettingEntryInputDeviceOptionGenerator* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingEntryInputDeviceOptionGenerator>();
	}
};
//static_assert(alignof(UUISettingEntryInputDeviceOptionGenerator) == 0x000008, "Wrong alignment on UUISettingEntryInputDeviceOptionGenerator");
//static_assert(sizeof(UUISettingEntryInputDeviceOptionGenerator) == 0x000030, "Wrong size on UUISettingEntryInputDeviceOptionGenerator");

// PythonClass Audio.UISettingEntryChatVolumeHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingEntryChatVolumeHandler final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);
	float BP_GetDefaultValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingEntryChatVolumeHandler">();
	}
	static class UUISettingEntryChatVolumeHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingEntryChatVolumeHandler>();
	}
};
//static_assert(alignof(UUISettingEntryChatVolumeHandler) == 0x000008, "Wrong alignment on UUISettingEntryChatVolumeHandler");
//static_assert(sizeof(UUISettingEntryChatVolumeHandler) == 0x000030, "Wrong size on UUISettingEntryChatVolumeHandler");

// PythonClass Audio.UISettingEntryChatOptionGenerator
// 0x0000 (0x0030 - 0x0030)
class UUISettingEntryChatOptionGenerator final : public UUISettingEntryOptionsGenerator
{
public:
	TMap<int32, class FText> BP_Gen(class UObject* Obj, const class FString& Setting_key, const TMap<int32, class FText>& OPTIONS);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingEntryChatOptionGenerator">();
	}
	static class UUISettingEntryChatOptionGenerator* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingEntryChatOptionGenerator>();
	}
};
//static_assert(alignof(UUISettingEntryChatOptionGenerator) == 0x000008, "Wrong alignment on UUISettingEntryChatOptionGenerator");
//static_assert(sizeof(UUISettingEntryChatOptionGenerator) == 0x000030, "Wrong size on UUISettingEntryChatOptionGenerator");

// PythonClass Audio.UISettingEntryChatHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingEntryChatHandler final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);
	float BP_GetDefaultValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingEntryChatHandler">();
	}
	static class UUISettingEntryChatHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingEntryChatHandler>();
	}
};
//static_assert(alignof(UUISettingEntryChatHandler) == 0x000008, "Wrong alignment on UUISettingEntryChatHandler");
//static_assert(sizeof(UUISettingEntryChatHandler) == 0x000030, "Wrong size on UUISettingEntryChatHandler");

// PythonClass Audio.UISettingEntryDubbingHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingEntryDubbingHandler final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);
	float BP_GetDefaultValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingEntryDubbingHandler">();
	}
	static class UUISettingEntryDubbingHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingEntryDubbingHandler>();
	}
};
//static_assert(alignof(UUISettingEntryDubbingHandler) == 0x000008, "Wrong alignment on UUISettingEntryDubbingHandler");
//static_assert(sizeof(UUISettingEntryDubbingHandler) == 0x000030, "Wrong size on UUISettingEntryDubbingHandler");

// PythonClass Audio.UISettingCombatMixStatusHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingCombatMixStatusHandler final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& O);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingCombatMixStatusHandler">();
	}
	static class UUISettingCombatMixStatusHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingCombatMixStatusHandler>();
	}
};
//static_assert(alignof(UUISettingCombatMixStatusHandler) == 0x000008, "Wrong alignment on UUISettingCombatMixStatusHandler");
//static_assert(sizeof(UUISettingCombatMixStatusHandler) == 0x000030, "Wrong size on UUISettingCombatMixStatusHandler");

// PythonClass Audio.UISettingCombatMixRtpcHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingCombatMixRtpcHandler final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& O);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);
	float BP_GetDefaultValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& P, const TMap<int32, class FText>& O);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingCombatMixRtpcHandler">();
	}
	static class UUISettingCombatMixRtpcHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingCombatMixRtpcHandler>();
	}
};
//static_assert(alignof(UUISettingCombatMixRtpcHandler) == 0x000008, "Wrong alignment on UUISettingCombatMixRtpcHandler");
//static_assert(sizeof(UUISettingCombatMixRtpcHandler) == 0x000030, "Wrong size on UUISettingCombatMixRtpcHandler");

// PythonClass Audio.UISettingPlayModeHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingPlayModeHandler final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& O);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingPlayModeHandler">();
	}
	static class UUISettingPlayModeHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingPlayModeHandler>();
	}
};
//static_assert(alignof(UUISettingPlayModeHandler) == 0x000008, "Wrong alignment on UUISettingPlayModeHandler");
//static_assert(sizeof(UUISettingPlayModeHandler) == 0x000030, "Wrong size on UUISettingPlayModeHandler");

// PythonClass Audio.UISettingSoundPlayModeHeadphonesEnhancementHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingSoundPlayModeHeadphonesEnhancementHandler final : public UPyDefaultSettingEntryHandler
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingSoundPlayModeHeadphonesEnhancementHandler">();
	}
	static class UUISettingSoundPlayModeHeadphonesEnhancementHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingSoundPlayModeHeadphonesEnhancementHandler>();
	}
};
//static_assert(alignof(UUISettingSoundPlayModeHeadphonesEnhancementHandler) == 0x000008, "Wrong alignment on UUISettingSoundPlayModeHeadphonesEnhancementHandler");
//static_assert(sizeof(UUISettingSoundPlayModeHeadphonesEnhancementHandler) == 0x000030, "Wrong size on UUISettingSoundPlayModeHeadphonesEnhancementHandler");

// PythonClass Audio.UISettingSoundPlayModeBackgroundHandler
// 0x0000 (0x0030 - 0x0030)
class UUISettingSoundPlayModeBackgroundHandler final : public UPyDefaultSettingEntryHandler
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingSoundPlayModeBackgroundHandler">();
	}
	static class UUISettingSoundPlayModeBackgroundHandler* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingSoundPlayModeBackgroundHandler>();
	}
};
//static_assert(alignof(UUISettingSoundPlayModeBackgroundHandler) == 0x000008, "Wrong alignment on UUISettingSoundPlayModeBackgroundHandler");
//static_assert(sizeof(UUISettingSoundPlayModeBackgroundHandler) == 0x000030, "Wrong size on UUISettingSoundPlayModeBackgroundHandler");

// PythonClass Audio.UISettingSoundPlayOutputDevice
// 0x0000 (0x0030 - 0x0030)
class UUISettingSoundPlayOutputDevice final : public UUISettingEntrySettingHandler
{
public:
	float BP_GetCurrentValue(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& O);
	TMap<class FString, int32> BP_OnChanged(class UObject* Obj, const class FString& Setting_key, const TMap<class FString, class FString>& Params_0, const TMap<int32, class FText>& OPTIONS, float Value, const TMap<class FString, int32>& Tags);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingSoundPlayOutputDevice">();
	}
	static class UUISettingSoundPlayOutputDevice* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingSoundPlayOutputDevice>();
	}
};
//static_assert(alignof(UUISettingSoundPlayOutputDevice) == 0x000008, "Wrong alignment on UUISettingSoundPlayOutputDevice");
//static_assert(sizeof(UUISettingSoundPlayOutputDevice) == 0x000030, "Wrong size on UUISettingSoundPlayOutputDevice");

// PythonClass Audio.UISettingEntrySoundPlayOutputDeviceGenerator
// 0x0000 (0x0030 - 0x0030)
class UUISettingEntrySoundPlayOutputDeviceGenerator final : public UUISettingEntryOptionsGenerator
{
public:
	TMap<int32, class FText> BP_Gen(class UObject* Obj, const class FString& Setting_key, const TMap<int32, class FText>& OPTIONS);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"UISettingEntrySoundPlayOutputDeviceGenerator">();
	}
	static class UUISettingEntrySoundPlayOutputDeviceGenerator* GetDefaultObj()
	{
		return GetDefaultObjImpl<UUISettingEntrySoundPlayOutputDeviceGenerator>();
	}
};
//static_assert(alignof(UUISettingEntrySoundPlayOutputDeviceGenerator) == 0x000008, "Wrong alignment on UUISettingEntrySoundPlayOutputDeviceGenerator");
//static_assert(sizeof(UUISettingEntrySoundPlayOutputDeviceGenerator) == 0x000030, "Wrong size on UUISettingEntrySoundPlayOutputDeviceGenerator");

}

