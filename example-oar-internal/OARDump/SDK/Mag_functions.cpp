#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Mag

#include "Basic.hpp"

#include "Mag_classes.hpp"
#include "Mag_parameters.hpp"


namespace SDK
{

// Function Mag.Mag_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AMag_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Mag_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}

