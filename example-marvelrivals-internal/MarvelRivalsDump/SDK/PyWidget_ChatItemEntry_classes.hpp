#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PyWidget_ChatItemEntry

#include "Basic.hpp"

#include "Marvel_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "CoreUObject_classes.hpp"
#include "SlateCore_structs.hpp"
#include "PyMarvelUserWidget_classes.hpp"
#include "Const_chat_structs.hpp"


namespace SDK
{

// PythonClass PyWidget_ChatItemEntry.ChatMsgItem
// 0x0000 (0x0030 - 0x0030)
class UChatMsgItem final : public UObject
{
public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"ChatMsgItem">();
	}
	static class UChatMsgItem* GetDefaultObj()
	{
		return GetDefaultObjImpl<UChatMsgItem>();
	}
};
static_assert(alignof(UChatMsgItem) == 0x000008, "Wrong alignment on UChatMsgItem");
static_assert(sizeof(UChatMsgItem) == 0x000030, "Wrong size on UChatMsgItem");

// PythonClass PyWidget_ChatItemEntry.PyWidget_ChatItemEntryText
// 0x03B0 (0x09A0 - 0x05F0)
#pragma pack(push, 0x1)
class alignas(0x10) UPyWidget_ChatItemEntryText : public UPyMarvelUserWidget
{
public:
	uint8                                         Pad_5E9[0x7];                                      // 0x05E9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UAkAudioEvent*                          AkEvent_CommonChatUserClickPlay;                   // 0x05F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FMargin                                DefaultChannelPadding;                             // 0x05F8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	struct FMargin                                PrivateMessageChannelPadding;                      // 0x0608(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, NativeAccessSpecifierPublic)
	uint8                                         Pad_618[0x8];                                      // 0x0618(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTextBlockStyle                        DefaultTextStyleOverride;                          // 0x0620(0x0350)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	TArray<class UTexture2D*>                     IconList;                                          // 0x0970(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	TArray<struct FLinearColor>                   VXColor;                                           // 0x0980(0x0010)(Edit, BlueprintVisible, NativeAccessSpecifierPublic)
	bool                                          bCustomColorPreview;                               // 0x0990(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

public:
	void OnInitialized();
	void Construct();
	void Destruct();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_ChatItemEntryText">();
	}
	static class UPyWidget_ChatItemEntryText* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_ChatItemEntryText>();
	}
};
#pragma pack(pop)
static_assert(alignof(UPyWidget_ChatItemEntryText) == 0x000010, "Wrong alignment on UPyWidget_ChatItemEntryText");
static_assert(sizeof(UPyWidget_ChatItemEntryText) == 0x0009A0, "Wrong size on UPyWidget_ChatItemEntryText");
static_assert(offsetof(UPyWidget_ChatItemEntryText, AkEvent_CommonChatUserClickPlay) == 0x0005F0, "Member 'UPyWidget_ChatItemEntryText::AkEvent_CommonChatUserClickPlay' has a wrong offset!");
static_assert(offsetof(UPyWidget_ChatItemEntryText, DefaultChannelPadding) == 0x0005F8, "Member 'UPyWidget_ChatItemEntryText::DefaultChannelPadding' has a wrong offset!");
static_assert(offsetof(UPyWidget_ChatItemEntryText, PrivateMessageChannelPadding) == 0x000608, "Member 'UPyWidget_ChatItemEntryText::PrivateMessageChannelPadding' has a wrong offset!");
static_assert(offsetof(UPyWidget_ChatItemEntryText, DefaultTextStyleOverride) == 0x000620, "Member 'UPyWidget_ChatItemEntryText::DefaultTextStyleOverride' has a wrong offset!");
static_assert(offsetof(UPyWidget_ChatItemEntryText, IconList) == 0x000970, "Member 'UPyWidget_ChatItemEntryText::IconList' has a wrong offset!");
static_assert(offsetof(UPyWidget_ChatItemEntryText, VXColor) == 0x000980, "Member 'UPyWidget_ChatItemEntryText::VXColor' has a wrong offset!");
static_assert(offsetof(UPyWidget_ChatItemEntryText, bCustomColorPreview) == 0x000990, "Member 'UPyWidget_ChatItemEntryText::bCustomColorPreview' has a wrong offset!");

// PythonClass PyWidget_ChatItemEntry.PyWidget_ChatItemEntry
// 0x0058 (0x0608 - 0x05B0)
class UPyWidget_ChatItemEntry : public UWidget_ListEntry
{
public:
	EChatCustomMsgType                            CurrentCustomWidget;                               // 0x05B0(0x0001)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_5B1[0x7];                                      // 0x05B1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<EChatCustomMsgType, struct FSoftClassPath> CustomWidgets;                                     // 0x05B8(0x0050)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, NativeAccessSpecifierPublic)

public:
	void Construct();
	void PreConstruct(bool IsDesignTime);
	void Destruct();
	void OnListItemObjectSet(class UObject* _itm);

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"PyWidget_ChatItemEntry">();
	}
	static class UPyWidget_ChatItemEntry* GetDefaultObj()
	{
		return GetDefaultObjImpl<UPyWidget_ChatItemEntry>();
	}
};
static_assert(alignof(UPyWidget_ChatItemEntry) == 0x000008, "Wrong alignment on UPyWidget_ChatItemEntry");
static_assert(sizeof(UPyWidget_ChatItemEntry) == 0x000608, "Wrong size on UPyWidget_ChatItemEntry");
static_assert(offsetof(UPyWidget_ChatItemEntry, CurrentCustomWidget) == 0x0005B0, "Member 'UPyWidget_ChatItemEntry::CurrentCustomWidget' has a wrong offset!");
static_assert(offsetof(UPyWidget_ChatItemEntry, CustomWidgets) == 0x0005B8, "Member 'UPyWidget_ChatItemEntry::CustomWidgets' has a wrong offset!");

}

