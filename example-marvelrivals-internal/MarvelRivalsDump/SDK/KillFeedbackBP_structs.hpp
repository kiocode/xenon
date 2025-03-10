#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: KillFeedbackBP

#include "Basic.hpp"

#include "GameplayTags_structs.hpp"


namespace SDK
{

// UserDefinedStruct KillFeedbackBP.KillFeedbackBP
// 0x0050 (0x0050 - 0x0000)
struct FKillFeedbackBP final
{
public:
	class FString                                 Type_7_465D7A034C4540DCED91C8923D18058C;           // 0x0000(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	class FText                                   Desc_10_B07701D147507E6E8E5BA997683FC77E;          // 0x0010(0x0018)(Edit, BlueprintVisible)
	struct FGameplayTag                           AudioTag_33_07ACE4364086F6F5CA74C4AB2C9F5011;      // 0x0028(0x000C)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash)
	bool                                          IsStrong_30_22D97E5F4936FE02049FBAA3FCA9E3EC;      // 0x0034(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_35[0x3];                                       // 0x0035(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Priority_36_9D8EA0B44A89ACF7377CEEBF2BE443F9;      // 0x0038(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         ConsecKill_39_B79A3C4644D975B60D1C5DAD3679EF07;    // 0x003C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ShouldShowInRight_41_0997B5704C1E353EB3D8E89BB43D27E9; // 0x0040(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_41[0x7];                                       // 0x0041(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UAkAudioEvent*                          AudioEvent_45_ADA19DD04FC7B58CA6B3958B084BA2B6;    // 0x0048(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(FKillFeedbackBP) == 0x000008, "Wrong alignment on FKillFeedbackBP");
static_assert(sizeof(FKillFeedbackBP) == 0x000050, "Wrong size on FKillFeedbackBP");
static_assert(offsetof(FKillFeedbackBP, Type_7_465D7A034C4540DCED91C8923D18058C) == 0x000000, "Member 'FKillFeedbackBP::Type_7_465D7A034C4540DCED91C8923D18058C' has a wrong offset!");
static_assert(offsetof(FKillFeedbackBP, Desc_10_B07701D147507E6E8E5BA997683FC77E) == 0x000010, "Member 'FKillFeedbackBP::Desc_10_B07701D147507E6E8E5BA997683FC77E' has a wrong offset!");
static_assert(offsetof(FKillFeedbackBP, AudioTag_33_07ACE4364086F6F5CA74C4AB2C9F5011) == 0x000028, "Member 'FKillFeedbackBP::AudioTag_33_07ACE4364086F6F5CA74C4AB2C9F5011' has a wrong offset!");
static_assert(offsetof(FKillFeedbackBP, IsStrong_30_22D97E5F4936FE02049FBAA3FCA9E3EC) == 0x000034, "Member 'FKillFeedbackBP::IsStrong_30_22D97E5F4936FE02049FBAA3FCA9E3EC' has a wrong offset!");
static_assert(offsetof(FKillFeedbackBP, Priority_36_9D8EA0B44A89ACF7377CEEBF2BE443F9) == 0x000038, "Member 'FKillFeedbackBP::Priority_36_9D8EA0B44A89ACF7377CEEBF2BE443F9' has a wrong offset!");
static_assert(offsetof(FKillFeedbackBP, ConsecKill_39_B79A3C4644D975B60D1C5DAD3679EF07) == 0x00003C, "Member 'FKillFeedbackBP::ConsecKill_39_B79A3C4644D975B60D1C5DAD3679EF07' has a wrong offset!");
static_assert(offsetof(FKillFeedbackBP, ShouldShowInRight_41_0997B5704C1E353EB3D8E89BB43D27E9) == 0x000040, "Member 'FKillFeedbackBP::ShouldShowInRight_41_0997B5704C1E353EB3D8E89BB43D27E9' has a wrong offset!");
static_assert(offsetof(FKillFeedbackBP, AudioEvent_45_ADA19DD04FC7B58CA6B3958B084BA2B6) == 0x000048, "Member 'FKillFeedbackBP::AudioEvent_45_ADA19DD04FC7B58CA6B3958B084BA2B6' has a wrong offset!");

}

