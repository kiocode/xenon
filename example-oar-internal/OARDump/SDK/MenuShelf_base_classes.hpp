#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MenuShelf_base

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass MenuShelf_base.MenuShelf_base_C
// 0x0018 (0x0238 - 0x0220)
class AMenuShelf_base_C : public AActor
{
public:
	class UArrowComponent*                        Arrow;                                             // 0x0220(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MenuShelf_base_C">();
	}
	static class AMenuShelf_base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AMenuShelf_base_C>();
	}
};
static_assert(alignof(AMenuShelf_base_C) == 0x000008, "Wrong alignment on AMenuShelf_base_C");
static_assert(sizeof(AMenuShelf_base_C) == 0x000238, "Wrong size on AMenuShelf_base_C");
static_assert(offsetof(AMenuShelf_base_C, Arrow) == 0x000220, "Member 'AMenuShelf_base_C::Arrow' has a wrong offset!");
static_assert(offsetof(AMenuShelf_base_C, StaticMesh) == 0x000228, "Member 'AMenuShelf_base_C::StaticMesh' has a wrong offset!");
static_assert(offsetof(AMenuShelf_base_C, DefaultSceneRoot) == 0x000230, "Member 'AMenuShelf_base_C::DefaultSceneRoot' has a wrong offset!");

}

