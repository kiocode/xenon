#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HeroVoiceManagerBP

#include "Basic.hpp"

#include "PyHeroVoiceManager_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass HeroVoiceManagerBP.HeroVoiceManagerBP_C
// 0x0000 (0x0880 - 0x0880)
class AHeroVoiceManagerBP_C final : public APyHeroVoiceManager
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HeroVoiceManagerBP_C">();
	}
	static class AHeroVoiceManagerBP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AHeroVoiceManagerBP_C>();
	}
};
static_assert(alignof(AHeroVoiceManagerBP_C) == 0x000008, "Wrong alignment on AHeroVoiceManagerBP_C");
static_assert(sizeof(AHeroVoiceManagerBP_C) == 0x000880, "Wrong size on AHeroVoiceManagerBP_C");

}

