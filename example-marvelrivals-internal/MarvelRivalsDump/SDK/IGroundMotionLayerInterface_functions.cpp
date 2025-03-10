#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: IGroundMotionLayerInterface

#include "Basic.hpp"

#include "IGroundMotionLayerInterface_classes.hpp"
#include "IGroundMotionLayerInterface_parameters.hpp"


namespace SDK
{

// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.Turning_Post
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        InPose                                                 (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// struct FPoseLink                        Turning_Post_0                                         (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::Turning_Post(const struct FPoseLink& InPose, struct FPoseLink* Turning_Post_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "Turning_Post");

	Params::IGroundMotionLayerInterface_C_Turning_Post Parms{};

	Parms.InPose = std::move(InPose);

	UObject::ProcessEvent(Func, &Parms);

	if (Turning_Post_0 != nullptr)
		*Turning_Post_0 = std::move(Parms.Turning_Post_0);
}


// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.JumpStartNew
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        JumpStartNew_0                                         (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::JumpStartNew(struct FPoseLink* JumpStartNew_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "JumpStartNew");

	Params::IGroundMotionLayerInterface_C_JumpStartNew Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (JumpStartNew_0 != nullptr)
		*JumpStartNew_0 = std::move(Parms.JumpStartNew_0);
}


// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.JumpLoopNew
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        JumpLoopNew_0                                          (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::JumpLoopNew(struct FPoseLink* JumpLoopNew_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "JumpLoopNew");

	Params::IGroundMotionLayerInterface_C_JumpLoopNew Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (JumpLoopNew_0 != nullptr)
		*JumpLoopNew_0 = std::move(Parms.JumpLoopNew_0);
}


// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.JumpLandNew
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        JumpLandNew_0                                          (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::JumpLandNew(struct FPoseLink* JumpLandNew_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "JumpLandNew");

	Params::IGroundMotionLayerInterface_C_JumpLandNew Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (JumpLandNew_0 != nullptr)
		*JumpLandNew_0 = std::move(Parms.JumpLandNew_0);
}


// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.Jump
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        GroundDetail                                           (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// struct FPoseLink                        Jump_0                                                 (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::Jump(const struct FPoseLink& GroundDetail, struct FPoseLink* Jump_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "Jump");

	Params::IGroundMotionLayerInterface_C_Jump Parms{};

	Parms.GroundDetail = std::move(GroundDetail);

	UObject::ProcessEvent(Func, &Parms);

	if (Jump_0 != nullptr)
		*Jump_0 = std::move(Parms.Jump_0);
}


// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.GroundStop
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        GroundStop_0                                           (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::GroundStop(struct FPoseLink* GroundStop_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "GroundStop");

	Params::IGroundMotionLayerInterface_C_GroundStop Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (GroundStop_0 != nullptr)
		*GroundStop_0 = std::move(Parms.GroundStop_0);
}


// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.GroundNew
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        Idle                                                   (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// struct FPoseLink                        Loop                                                   (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// struct FPoseLink                        Stop                                                   (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// struct FPoseLink                        GroundNew_0                                            (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::GroundNew(const struct FPoseLink& Idle, const struct FPoseLink& Loop, const struct FPoseLink& Stop, struct FPoseLink* GroundNew_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "GroundNew");

	Params::IGroundMotionLayerInterface_C_GroundNew Parms{};

	Parms.Idle = std::move(Idle);
	Parms.Loop = std::move(Loop);
	Parms.Stop = std::move(Stop);

	UObject::ProcessEvent(Func, &Parms);

	if (GroundNew_0 != nullptr)
		*GroundNew_0 = std::move(Parms.GroundNew_0);
}


// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.GroundLoop
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        GroundLoop_0                                           (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::GroundLoop(struct FPoseLink* GroundLoop_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "GroundLoop");

	Params::IGroundMotionLayerInterface_C_GroundLoop Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (GroundLoop_0 != nullptr)
		*GroundLoop_0 = std::move(Parms.GroundLoop_0);
}


// Function IGroundMotionLayerInterface.IGroundMotionLayerInterface_C.GroundDetail_Post
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        Ground                                                 (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// struct FPoseLink                        GroundDetail_Post_0                                    (Parm, OutParm, NoDestructor)

void IIGroundMotionLayerInterface_C::GroundDetail_Post(const struct FPoseLink& Ground, struct FPoseLink* GroundDetail_Post_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("IGroundMotionLayerInterface_C", "GroundDetail_Post");

	Params::IGroundMotionLayerInterface_C_GroundDetail_Post Parms{};

	Parms.Ground = std::move(Ground);

	UObject::ProcessEvent(Func, &Parms);

	if (GroundDetail_Post_0 != nullptr)
		*GroundDetail_Post_0 = std::move(Parms.GroundDetail_Post_0);
}

}

