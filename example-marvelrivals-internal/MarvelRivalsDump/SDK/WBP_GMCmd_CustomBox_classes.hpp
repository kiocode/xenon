#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_GMCmd_CustomBox

#include "Basic.hpp"

#include "PyWidget_GMCmdCustomBox_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_GMCmd_CustomBox.WBP_GMCmd_CustomBox_C
// 0x0048 (0x0648 - 0x0600)
class UWBP_GMCmd_CustomBox_C final : public UPyWidget_GMCmdCustomBox
{
public:
	class UWBP_Common_Input_C*                    Custom_Editable;                                   // 0x0600(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelVerticalBox*                     CustomCmdBox;                                      // 0x0608(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelHorizontalBox*                   HoriBox_Input;                                     // 0x0610(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_GMCMD_SelectParameters_C*          SelectParameters;                                  // 0x0618(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelTextBlock*                       TextBlock_Custom;                                  // 0x0620(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMarvelTextBlock*                       TextBlock_Description;                             // 0x0628(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWBP_GMCmd_InputBox_C*                  WBP_GMCmd_InputBox;                                // 0x0630(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWrapBox*                               WrapBox_Input;                                     // 0x0638(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UClass*                                 InputBoxClass;                                     // 0x0640(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_GMCmd_CustomBox_C">();
	}
	static class UWBP_GMCmd_CustomBox_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_GMCmd_CustomBox_C>();
	}
};
////static_assert(alignof(UWBP_GMCmd_CustomBox_C) == 0x000008, "Wrong alignment on UWBP_GMCmd_CustomBox_C");
////static_assert(sizeof(UWBP_GMCmd_CustomBox_C) == 0x000648, "Wrong size on UWBP_GMCmd_CustomBox_C");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, Custom_Editable) == 0x000600, "Member 'UWBP_GMCmd_CustomBox_C::Custom_Editable' has a wrong offset!");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, CustomCmdBox) == 0x000608, "Member 'UWBP_GMCmd_CustomBox_C::CustomCmdBox' has a wrong offset!");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, HoriBox_Input) == 0x000610, "Member 'UWBP_GMCmd_CustomBox_C::HoriBox_Input' has a wrong offset!");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, SelectParameters) == 0x000618, "Member 'UWBP_GMCmd_CustomBox_C::SelectParameters' has a wrong offset!");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, TextBlock_Custom) == 0x000620, "Member 'UWBP_GMCmd_CustomBox_C::TextBlock_Custom' has a wrong offset!");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, TextBlock_Description) == 0x000628, "Member 'UWBP_GMCmd_CustomBox_C::TextBlock_Description' has a wrong offset!");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, WBP_GMCmd_InputBox) == 0x000630, "Member 'UWBP_GMCmd_CustomBox_C::WBP_GMCmd_InputBox' has a wrong offset!");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, WrapBox_Input) == 0x000638, "Member 'UWBP_GMCmd_CustomBox_C::WrapBox_Input' has a wrong offset!");
////static_assert(offsetof(UWBP_GMCmd_CustomBox_C, InputBoxClass) == 0x000640, "Member 'UWBP_GMCmd_CustomBox_C::InputBoxClass' has a wrong offset!");

}

