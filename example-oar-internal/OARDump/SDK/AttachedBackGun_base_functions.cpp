#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AttachedBackGun_base

#include "Basic.hpp"

#include "AttachedBackGun_base_classes.hpp"
#include "AttachedBackGun_base_parameters.hpp"


namespace SDK
{

// Function AttachedBackGun_base.AttachedBackGun_base_C.SetupAttachments
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FAttachmentArrayStructure        Attachments                                            (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)

void AAttachedBackGun_base_C::SetupAttachments(const struct FAttachmentArrayStructure& Attachments)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("AttachedBackGun_base_C", "SetupAttachments");

	Params::AttachedBackGun_base_C_SetupAttachments Parms{};

	Parms.Attachments = std::move(Attachments);

	UObject::ProcessEvent(Func, &Parms);
}

}

