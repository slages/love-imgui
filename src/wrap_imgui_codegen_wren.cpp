// This is an automatically generated file!!

#include "wren.hpp"
#include "wrap_imgui_codegen.h"
#include "imgui.h"
#include "imgui_stdlib.h"

#include <codecvt>
#include <locale>
#include <optional>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

// Enums {{{

std::optional<ImGuiWindowFlags_> getImGuiWindowFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiWindowFlags_None; }
	if (strcmp(in, "DockNodeHost") == 0) { return ImGuiWindowFlags_DockNodeHost; }
	if (strcmp(in, "NavFlattened") == 0) { return ImGuiWindowFlags_NavFlattened; }
	if (strcmp(in, "ChildMenu") == 0) { return ImGuiWindowFlags_ChildMenu; }
	if (strcmp(in, "Modal") == 0) { return ImGuiWindowFlags_Modal; }
	if (strcmp(in, "NoResize") == 0) { return ImGuiWindowFlags_NoResize; }
	if (strcmp(in, "AlwaysVerticalScrollbar") == 0) { return ImGuiWindowFlags_AlwaysVerticalScrollbar; }
	if (strcmp(in, "MenuBar") == 0) { return ImGuiWindowFlags_MenuBar; }
	if (strcmp(in, "Popup") == 0) { return ImGuiWindowFlags_Popup; }
	if (strcmp(in, "HorizontalScrollbar") == 0) { return ImGuiWindowFlags_HorizontalScrollbar; }
	if (strcmp(in, "NoNavFocus") == 0) { return ImGuiWindowFlags_NoNavFocus; }
	if (strcmp(in, "ChildWindow") == 0) { return ImGuiWindowFlags_ChildWindow; }
	if (strcmp(in, "NoTitleBar") == 0) { return ImGuiWindowFlags_NoTitleBar; }
	if (strcmp(in, "NoInputs") == 0) { return ImGuiWindowFlags_NoInputs; }
	if (strcmp(in, "NoCollapse") == 0) { return ImGuiWindowFlags_NoCollapse; }
	if (strcmp(in, "NoBackground") == 0) { return ImGuiWindowFlags_NoBackground; }
	if (strcmp(in, "NoDecoration") == 0) { return ImGuiWindowFlags_NoDecoration; }
	if (strcmp(in, "AlwaysAutoResize") == 0) { return ImGuiWindowFlags_AlwaysAutoResize; }
	if (strcmp(in, "AlwaysHorizontalScrollbar") == 0) { return ImGuiWindowFlags_AlwaysHorizontalScrollbar; }
	if (strcmp(in, "NoBringToFrontOnFocus") == 0) { return ImGuiWindowFlags_NoBringToFrontOnFocus; }
	if (strcmp(in, "NoMove") == 0) { return ImGuiWindowFlags_NoMove; }
	if (strcmp(in, "NoDocking") == 0) { return ImGuiWindowFlags_NoDocking; }
	if (strcmp(in, "UnsavedDocument") == 0) { return ImGuiWindowFlags_UnsavedDocument; }
	if (strcmp(in, "AlwaysUseWindowPadding") == 0) { return ImGuiWindowFlags_AlwaysUseWindowPadding; }
	if (strcmp(in, "Tooltip") == 0) { return ImGuiWindowFlags_Tooltip; }
	if (strcmp(in, "NoSavedSettings") == 0) { return ImGuiWindowFlags_NoSavedSettings; }
	if (strcmp(in, "NoNavInputs") == 0) { return ImGuiWindowFlags_NoNavInputs; }
	if (strcmp(in, "NoScrollWithMouse") == 0) { return ImGuiWindowFlags_NoScrollWithMouse; }
	if (strcmp(in, "NoNav") == 0) { return ImGuiWindowFlags_NoNav; }
	if (strcmp(in, "NoFocusOnAppearing") == 0) { return ImGuiWindowFlags_NoFocusOnAppearing; }
	if (strcmp(in, "NoScrollbar") == 0) { return ImGuiWindowFlags_NoScrollbar; }
	if (strcmp(in, "NoMouseInputs") == 0) { return ImGuiWindowFlags_NoMouseInputs; }
	return std::nullopt;
}
const char* getStringFromImGuiWindowFlags(ImGuiWindowFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 29: return "DockNodeHost";
		case 1 << 23: return "NavFlattened";
		case 1 << 28: return "ChildMenu";
		case 1 << 27: return "Modal";
		case 1 << 1: return "NoResize";
		case 1 << 14: return "AlwaysVerticalScrollbar";
		case 1 << 10: return "MenuBar";
		case 1 << 26: return "Popup";
		case 1 << 11: return "HorizontalScrollbar";
		case 1 << 19: return "NoNavFocus";
		case 1 << 24: return "ChildWindow";
		case 1 << 0: return "NoTitleBar";
		// skipping // case ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus: return "NoInputs";
		case 1 << 5: return "NoCollapse";
		case 1 << 7: return "NoBackground";
		// skipping // case ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse: return "NoDecoration";
		case 1 << 6: return "AlwaysAutoResize";
		case 1<< 15: return "AlwaysHorizontalScrollbar";
		case 1 << 13: return "NoBringToFrontOnFocus";
		case 1 << 2: return "NoMove";
		case 1 << 21: return "NoDocking";
		case 1 << 20: return "UnsavedDocument";
		case 1 << 16: return "AlwaysUseWindowPadding";
		case 1 << 25: return "Tooltip";
		case 1 << 8: return "NoSavedSettings";
		case 1 << 18: return "NoNavInputs";
		case 1 << 4: return "NoScrollWithMouse";
		// skipping // case ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus: return "NoNav";
		case 1 << 12: return "NoFocusOnAppearing";
		case 1 << 3: return "NoScrollbar";
		case 1 << 9: return "NoMouseInputs";
	}
	return "";
}

std::optional<ImGuiInputTextFlags_> getImGuiInputTextFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiInputTextFlags_None; }
	if (strcmp(in, "AlwaysInsertMode") == 0) { return ImGuiInputTextFlags_AlwaysInsertMode; }
	if (strcmp(in, "NoHorizontalScroll") == 0) { return ImGuiInputTextFlags_NoHorizontalScroll; }
	if (strcmp(in, "NoMarkEdited") == 0) { return ImGuiInputTextFlags_NoMarkEdited; }
	if (strcmp(in, "CallbackHistory") == 0) { return ImGuiInputTextFlags_CallbackHistory; }
	if (strcmp(in, "CallbackAlways") == 0) { return ImGuiInputTextFlags_CallbackAlways; }
	if (strcmp(in, "ReadOnly") == 0) { return ImGuiInputTextFlags_ReadOnly; }
	if (strcmp(in, "CallbackResize") == 0) { return ImGuiInputTextFlags_CallbackResize; }
	if (strcmp(in, "CallbackCompletion") == 0) { return ImGuiInputTextFlags_CallbackCompletion; }
	if (strcmp(in, "AutoSelectAll") == 0) { return ImGuiInputTextFlags_AutoSelectAll; }
	if (strcmp(in, "CallbackCharFilter") == 0) { return ImGuiInputTextFlags_CallbackCharFilter; }
	if (strcmp(in, "CharsUppercase") == 0) { return ImGuiInputTextFlags_CharsUppercase; }
	if (strcmp(in, "CharsHexadecimal") == 0) { return ImGuiInputTextFlags_CharsHexadecimal; }
	if (strcmp(in, "Multiline") == 0) { return ImGuiInputTextFlags_Multiline; }
	if (strcmp(in, "CharsScientific") == 0) { return ImGuiInputTextFlags_CharsScientific; }
	if (strcmp(in, "CharsDecimal") == 0) { return ImGuiInputTextFlags_CharsDecimal; }
	if (strcmp(in, "CharsNoBlank") == 0) { return ImGuiInputTextFlags_CharsNoBlank; }
	if (strcmp(in, "Password") == 0) { return ImGuiInputTextFlags_Password; }
	if (strcmp(in, "CtrlEnterForNewLine") == 0) { return ImGuiInputTextFlags_CtrlEnterForNewLine; }
	if (strcmp(in, "AllowTabInput") == 0) { return ImGuiInputTextFlags_AllowTabInput; }
	if (strcmp(in, "NoUndoRedo") == 0) { return ImGuiInputTextFlags_NoUndoRedo; }
	if (strcmp(in, "EnterReturnsTrue") == 0) { return ImGuiInputTextFlags_EnterReturnsTrue; }
	return std::nullopt;
}
const char* getStringFromImGuiInputTextFlags(ImGuiInputTextFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 13: return "AlwaysInsertMode";
		case 1 << 12: return "NoHorizontalScroll";
		case 1 << 21: return "NoMarkEdited";
		case 1 << 7: return "CallbackHistory";
		case 1 << 8: return "CallbackAlways";
		case 1 << 14: return "ReadOnly";
		case 1 << 18: return "CallbackResize";
		case 1 << 6: return "CallbackCompletion";
		case 1 << 4: return "AutoSelectAll";
		case 1 << 9: return "CallbackCharFilter";
		case 1 << 2: return "CharsUppercase";
		case 1 << 1: return "CharsHexadecimal";
		case 1 << 20: return "Multiline";
		case 1 << 17: return "CharsScientific";
		case 1 << 0: return "CharsDecimal";
		case 1 << 3: return "CharsNoBlank";
		case 1 << 15: return "Password";
		case 1 << 11: return "CtrlEnterForNewLine";
		case 1 << 10: return "AllowTabInput";
		case 1 << 16: return "NoUndoRedo";
		case 1 << 5: return "EnterReturnsTrue";
	}
	return "";
}

std::optional<ImGuiTreeNodeFlags_> getImGuiTreeNodeFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiTreeNodeFlags_None; }
	if (strcmp(in, "OpenOnArrow") == 0) { return ImGuiTreeNodeFlags_OpenOnArrow; }
	if (strcmp(in, "SpanFullWidth") == 0) { return ImGuiTreeNodeFlags_SpanFullWidth; }
	if (strcmp(in, "SpanAvailWidth") == 0) { return ImGuiTreeNodeFlags_SpanAvailWidth; }
	if (strcmp(in, "NavLeftJumpsBackHere") == 0) { return ImGuiTreeNodeFlags_NavLeftJumpsBackHere; }
	if (strcmp(in, "DefaultOpen") == 0) { return ImGuiTreeNodeFlags_DefaultOpen; }
	if (strcmp(in, "FramePadding") == 0) { return ImGuiTreeNodeFlags_FramePadding; }
	if (strcmp(in, "Selected") == 0) { return ImGuiTreeNodeFlags_Selected; }
	if (strcmp(in, "OpenOnDoubleClick") == 0) { return ImGuiTreeNodeFlags_OpenOnDoubleClick; }
	if (strcmp(in, "AllowItemOverlap") == 0) { return ImGuiTreeNodeFlags_AllowItemOverlap; }
	if (strcmp(in, "Framed") == 0) { return ImGuiTreeNodeFlags_Framed; }
	if (strcmp(in, "CollapsingHeader") == 0) { return ImGuiTreeNodeFlags_CollapsingHeader; }
	if (strcmp(in, "NoAutoOpenOnLog") == 0) { return ImGuiTreeNodeFlags_NoAutoOpenOnLog; }
	if (strcmp(in, "Bullet") == 0) { return ImGuiTreeNodeFlags_Bullet; }
	if (strcmp(in, "NoTreePushOnOpen") == 0) { return ImGuiTreeNodeFlags_NoTreePushOnOpen; }
	if (strcmp(in, "Leaf") == 0) { return ImGuiTreeNodeFlags_Leaf; }
	return std::nullopt;
}
const char* getStringFromImGuiTreeNodeFlags(ImGuiTreeNodeFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 7: return "OpenOnArrow";
		case 1 << 12: return "SpanFullWidth";
		case 1 << 11: return "SpanAvailWidth";
		case 1 << 13: return "NavLeftJumpsBackHere";
		case 1 << 5: return "DefaultOpen";
		case 1 << 10: return "FramePadding";
		case 1 << 0: return "Selected";
		case 1 << 6: return "OpenOnDoubleClick";
		case 1 << 2: return "AllowItemOverlap";
		case 1 << 1: return "Framed";
		// skipping // case ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_NoAutoOpenOnLog: return "CollapsingHeader";
		case 1 << 4: return "NoAutoOpenOnLog";
		case 1 << 9: return "Bullet";
		case 1 << 3: return "NoTreePushOnOpen";
		case 1 << 8: return "Leaf";
	}
	return "";
}

std::optional<ImGuiSelectableFlags_> getImGuiSelectableFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiSelectableFlags_None; }
	if (strcmp(in, "AllowItemOverlap") == 0) { return ImGuiSelectableFlags_AllowItemOverlap; }
	if (strcmp(in, "DontClosePopups") == 0) { return ImGuiSelectableFlags_DontClosePopups; }
	if (strcmp(in, "SpanAllColumns") == 0) { return ImGuiSelectableFlags_SpanAllColumns; }
	if (strcmp(in, "AllowDoubleClick") == 0) { return ImGuiSelectableFlags_AllowDoubleClick; }
	if (strcmp(in, "Disabled") == 0) { return ImGuiSelectableFlags_Disabled; }
	return std::nullopt;
}
const char* getStringFromImGuiSelectableFlags(ImGuiSelectableFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 4: return "AllowItemOverlap";
		case 1 << 0: return "DontClosePopups";
		case 1 << 1: return "SpanAllColumns";
		case 1 << 2: return "AllowDoubleClick";
		case 1 << 3: return "Disabled";
	}
	return "";
}

std::optional<ImGuiComboFlags_> getImGuiComboFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiComboFlags_None; }
	if (strcmp(in, "HeightRegular") == 0) { return ImGuiComboFlags_HeightRegular; }
	if (strcmp(in, "HeightSmall") == 0) { return ImGuiComboFlags_HeightSmall; }
	if (strcmp(in, "NoArrowButton") == 0) { return ImGuiComboFlags_NoArrowButton; }
	if (strcmp(in, "HeightMask_") == 0) { return ImGuiComboFlags_HeightMask_; }
	if (strcmp(in, "HeightLargest") == 0) { return ImGuiComboFlags_HeightLargest; }
	if (strcmp(in, "NoPreview") == 0) { return ImGuiComboFlags_NoPreview; }
	if (strcmp(in, "HeightLarge") == 0) { return ImGuiComboFlags_HeightLarge; }
	if (strcmp(in, "PopupAlignLeft") == 0) { return ImGuiComboFlags_PopupAlignLeft; }
	return std::nullopt;
}
const char* getStringFromImGuiComboFlags(ImGuiComboFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 2: return "HeightRegular";
		case 1 << 1: return "HeightSmall";
		case 1 << 5: return "NoArrowButton";
		// skipping // case ImGuiComboFlags_HeightSmall | ImGuiComboFlags_HeightRegular | ImGuiComboFlags_HeightLarge | ImGuiComboFlags_HeightLargest: return "HeightMask_";
		case 1 << 4: return "HeightLargest";
		case 1 << 6: return "NoPreview";
		case 1 << 3: return "HeightLarge";
		case 1 << 0: return "PopupAlignLeft";
	}
	return "";
}

std::optional<ImGuiTabBarFlags_> getImGuiTabBarFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiTabBarFlags_None; }
	if (strcmp(in, "NoTooltip") == 0) { return ImGuiTabBarFlags_NoTooltip; }
	if (strcmp(in, "TabListPopupButton") == 0) { return ImGuiTabBarFlags_TabListPopupButton; }
	if (strcmp(in, "FittingPolicyResizeDown") == 0) { return ImGuiTabBarFlags_FittingPolicyResizeDown; }
	if (strcmp(in, "NoTabListScrollingButtons") == 0) { return ImGuiTabBarFlags_NoTabListScrollingButtons; }
	if (strcmp(in, "Reorderable") == 0) { return ImGuiTabBarFlags_Reorderable; }
	if (strcmp(in, "FittingPolicyMask_") == 0) { return ImGuiTabBarFlags_FittingPolicyMask_; }
	if (strcmp(in, "AutoSelectNewTabs") == 0) { return ImGuiTabBarFlags_AutoSelectNewTabs; }
	if (strcmp(in, "FittingPolicyDefault_") == 0) { return ImGuiTabBarFlags_FittingPolicyDefault_; }
	if (strcmp(in, "NoCloseWithMiddleMouseButton") == 0) { return ImGuiTabBarFlags_NoCloseWithMiddleMouseButton; }
	if (strcmp(in, "FittingPolicyScroll") == 0) { return ImGuiTabBarFlags_FittingPolicyScroll; }
	return std::nullopt;
}
const char* getStringFromImGuiTabBarFlags(ImGuiTabBarFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 5: return "NoTooltip";
		case 1 << 2: return "TabListPopupButton";
		case 1 << 6: return "FittingPolicyResizeDown";
		case 1 << 4: return "NoTabListScrollingButtons";
		case 1 << 0: return "Reorderable";
		// skipping // case ImGuiTabBarFlags_FittingPolicyResizeDown | ImGuiTabBarFlags_FittingPolicyScroll: return "FittingPolicyMask_";
		case 1 << 1: return "AutoSelectNewTabs";
		// skipping // case ImGuiTabBarFlags_FittingPolicyResizeDown: return "FittingPolicyDefault_";
		case 1 << 3: return "NoCloseWithMiddleMouseButton";
		case 1 << 7: return "FittingPolicyScroll";
	}
	return "";
}

std::optional<ImGuiTabItemFlags_> getImGuiTabItemFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiTabItemFlags_None; }
	if (strcmp(in, "NoPushId") == 0) { return ImGuiTabItemFlags_NoPushId; }
	if (strcmp(in, "SetSelected") == 0) { return ImGuiTabItemFlags_SetSelected; }
	if (strcmp(in, "NoCloseWithMiddleMouseButton") == 0) { return ImGuiTabItemFlags_NoCloseWithMiddleMouseButton; }
	if (strcmp(in, "UnsavedDocument") == 0) { return ImGuiTabItemFlags_UnsavedDocument; }
	return std::nullopt;
}
const char* getStringFromImGuiTabItemFlags(ImGuiTabItemFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 3: return "NoPushId";
		case 1 << 1: return "SetSelected";
		case 1 << 2: return "NoCloseWithMiddleMouseButton";
		case 1 << 0: return "UnsavedDocument";
	}
	return "";
}

std::optional<ImGuiFocusedFlags_> getImGuiFocusedFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiFocusedFlags_None; }
	if (strcmp(in, "RootWindow") == 0) { return ImGuiFocusedFlags_RootWindow; }
	if (strcmp(in, "AnyWindow") == 0) { return ImGuiFocusedFlags_AnyWindow; }
	if (strcmp(in, "ChildWindows") == 0) { return ImGuiFocusedFlags_ChildWindows; }
	if (strcmp(in, "RootAndChildWindows") == 0) { return ImGuiFocusedFlags_RootAndChildWindows; }
	return std::nullopt;
}
const char* getStringFromImGuiFocusedFlags(ImGuiFocusedFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 1: return "RootWindow";
		case 1 << 2: return "AnyWindow";
		case 1 << 0: return "ChildWindows";
		// skipping // case ImGuiFocusedFlags_RootWindow | ImGuiFocusedFlags_ChildWindows: return "RootAndChildWindows";
	}
	return "";
}

std::optional<ImGuiHoveredFlags_> getImGuiHoveredFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiHoveredFlags_None; }
	if (strcmp(in, "RootAndChildWindows") == 0) { return ImGuiHoveredFlags_RootAndChildWindows; }
	if (strcmp(in, "AllowWhenDisabled") == 0) { return ImGuiHoveredFlags_AllowWhenDisabled; }
	if (strcmp(in, "RootWindow") == 0) { return ImGuiHoveredFlags_RootWindow; }
	if (strcmp(in, "AnyWindow") == 0) { return ImGuiHoveredFlags_AnyWindow; }
	if (strcmp(in, "RectOnly") == 0) { return ImGuiHoveredFlags_RectOnly; }
	if (strcmp(in, "AllowWhenBlockedByPopup") == 0) { return ImGuiHoveredFlags_AllowWhenBlockedByPopup; }
	if (strcmp(in, "AllowWhenOverlapped") == 0) { return ImGuiHoveredFlags_AllowWhenOverlapped; }
	if (strcmp(in, "ChildWindows") == 0) { return ImGuiHoveredFlags_ChildWindows; }
	if (strcmp(in, "AllowWhenBlockedByActiveItem") == 0) { return ImGuiHoveredFlags_AllowWhenBlockedByActiveItem; }
	return std::nullopt;
}
const char* getStringFromImGuiHoveredFlags(ImGuiHoveredFlags in)
{
	switch (in) {
		case 0: return "None";
		// skipping // case ImGuiHoveredFlags_RootWindow | ImGuiHoveredFlags_ChildWindows: return "RootAndChildWindows";
		case 1 << 7: return "AllowWhenDisabled";
		case 1 << 1: return "RootWindow";
		case 1 << 2: return "AnyWindow";
		// skipping // case ImGuiHoveredFlags_AllowWhenBlockedByPopup | ImGuiHoveredFlags_AllowWhenBlockedByActiveItem | ImGuiHoveredFlags_AllowWhenOverlapped: return "RectOnly";
		case 1 << 3: return "AllowWhenBlockedByPopup";
		case 1 << 6: return "AllowWhenOverlapped";
		case 1 << 0: return "ChildWindows";
		case 1 << 5: return "AllowWhenBlockedByActiveItem";
	}
	return "";
}

std::optional<ImGuiDockNodeFlags_> getImGuiDockNodeFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiDockNodeFlags_None; }
	if (strcmp(in, "NoSplit") == 0) { return ImGuiDockNodeFlags_NoSplit; }
	if (strcmp(in, "AutoHideTabBar") == 0) { return ImGuiDockNodeFlags_AutoHideTabBar; }
	if (strcmp(in, "KeepAliveOnly") == 0) { return ImGuiDockNodeFlags_KeepAliveOnly; }
	if (strcmp(in, "NoResize") == 0) { return ImGuiDockNodeFlags_NoResize; }
	if (strcmp(in, "PassthruCentralNode") == 0) { return ImGuiDockNodeFlags_PassthruCentralNode; }
	if (strcmp(in, "NoDockingInCentralNode") == 0) { return ImGuiDockNodeFlags_NoDockingInCentralNode; }
	return std::nullopt;
}
const char* getStringFromImGuiDockNodeFlags(ImGuiDockNodeFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 4: return "NoSplit";
		case 1 << 6: return "AutoHideTabBar";
		case 1 << 0: return "KeepAliveOnly";
		case 1 << 5: return "NoResize";
		case 1 << 3: return "PassthruCentralNode";
		case 1 << 2: return "NoDockingInCentralNode";
	}
	return "";
}

std::optional<ImGuiDragDropFlags_> getImGuiDragDropFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiDragDropFlags_None; }
	if (strcmp(in, "SourceExtern") == 0) { return ImGuiDragDropFlags_SourceExtern; }
	if (strcmp(in, "SourceAutoExpirePayload") == 0) { return ImGuiDragDropFlags_SourceAutoExpirePayload; }
	if (strcmp(in, "AcceptPeekOnly") == 0) { return ImGuiDragDropFlags_AcceptPeekOnly; }
	if (strcmp(in, "SourceAllowNullID") == 0) { return ImGuiDragDropFlags_SourceAllowNullID; }
	if (strcmp(in, "SourceNoDisableHover") == 0) { return ImGuiDragDropFlags_SourceNoDisableHover; }
	if (strcmp(in, "SourceNoHoldToOpenOthers") == 0) { return ImGuiDragDropFlags_SourceNoHoldToOpenOthers; }
	if (strcmp(in, "AcceptBeforeDelivery") == 0) { return ImGuiDragDropFlags_AcceptBeforeDelivery; }
	if (strcmp(in, "AcceptNoDrawDefaultRect") == 0) { return ImGuiDragDropFlags_AcceptNoDrawDefaultRect; }
	if (strcmp(in, "SourceNoPreviewTooltip") == 0) { return ImGuiDragDropFlags_SourceNoPreviewTooltip; }
	if (strcmp(in, "AcceptNoPreviewTooltip") == 0) { return ImGuiDragDropFlags_AcceptNoPreviewTooltip; }
	return std::nullopt;
}
const char* getStringFromImGuiDragDropFlags(ImGuiDragDropFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 4: return "SourceExtern";
		case 1 << 5: return "SourceAutoExpirePayload";
		// skipping // case ImGuiDragDropFlags_AcceptBeforeDelivery | ImGuiDragDropFlags_AcceptNoDrawDefaultRect: return "AcceptPeekOnly";
		case 1 << 3: return "SourceAllowNullID";
		case 1 << 1: return "SourceNoDisableHover";
		case 1 << 2: return "SourceNoHoldToOpenOthers";
		case 1 << 10: return "AcceptBeforeDelivery";
		case 1 << 11: return "AcceptNoDrawDefaultRect";
		case 1 << 0: return "SourceNoPreviewTooltip";
		case 1 << 12: return "AcceptNoPreviewTooltip";
	}
	return "";
}

std::optional<ImGuiDataType_> getImGuiDataTypeFromString(const char* in)
{
	if (strcmp(in, "U8") == 0) { return ImGuiDataType_U8; }
	if (strcmp(in, "U32") == 0) { return ImGuiDataType_U32; }
	if (strcmp(in, "Double") == 0) { return ImGuiDataType_Double; }
	if (strcmp(in, "S8") == 0) { return ImGuiDataType_S8; }
	if (strcmp(in, "U64") == 0) { return ImGuiDataType_U64; }
	if (strcmp(in, "S64") == 0) { return ImGuiDataType_S64; }
	if (strcmp(in, "S32") == 0) { return ImGuiDataType_S32; }
	if (strcmp(in, "Float") == 0) { return ImGuiDataType_Float; }
	if (strcmp(in, "S16") == 0) { return ImGuiDataType_S16; }
	if (strcmp(in, "U16") == 0) { return ImGuiDataType_U16; }
	return std::nullopt;
}
const char* getStringFromImGuiDataType(ImGuiDataType in)
{
	switch (in) {
		case 1: return "U8";
		case 5: return "U32";
		case 9: return "Double";
		case 0: return "S8";
		case 7: return "U64";
		case 6: return "S64";
		case 4: return "S32";
		case 8: return "Float";
		case 2: return "S16";
		case 3: return "U16";
	}
	return "";
}

std::optional<ImGuiDir_> getImGuiDirFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiDir_None; }
	if (strcmp(in, "Left") == 0) { return ImGuiDir_Left; }
	if (strcmp(in, "Right") == 0) { return ImGuiDir_Right; }
	if (strcmp(in, "Up") == 0) { return ImGuiDir_Up; }
	if (strcmp(in, "Down") == 0) { return ImGuiDir_Down; }
	return std::nullopt;
}
const char* getStringFromImGuiDir(ImGuiDir in)
{
	switch (in) {
		case -1: return "None";
		case 0: return "Left";
		case 1: return "Right";
		case 2: return "Up";
		case 3: return "Down";
	}
	return "";
}

std::optional<ImGuiKey_> getImGuiKeyFromString(const char* in)
{
	if (strcmp(in, "Tab") == 0) { return ImGuiKey_Tab; }
	if (strcmp(in, "Space") == 0) { return ImGuiKey_Space; }
	if (strcmp(in, "PageUp") == 0) { return ImGuiKey_PageUp; }
	if (strcmp(in, "Z") == 0) { return ImGuiKey_Z; }
	if (strcmp(in, "Delete") == 0) { return ImGuiKey_Delete; }
	if (strcmp(in, "LeftArrow") == 0) { return ImGuiKey_LeftArrow; }
	if (strcmp(in, "RightArrow") == 0) { return ImGuiKey_RightArrow; }
	if (strcmp(in, "Insert") == 0) { return ImGuiKey_Insert; }
	if (strcmp(in, "Home") == 0) { return ImGuiKey_Home; }
	if (strcmp(in, "DownArrow") == 0) { return ImGuiKey_DownArrow; }
	if (strcmp(in, "Escape") == 0) { return ImGuiKey_Escape; }
	if (strcmp(in, "UpArrow") == 0) { return ImGuiKey_UpArrow; }
	if (strcmp(in, "A") == 0) { return ImGuiKey_A; }
	if (strcmp(in, "V") == 0) { return ImGuiKey_V; }
	if (strcmp(in, "C") == 0) { return ImGuiKey_C; }
	if (strcmp(in, "X") == 0) { return ImGuiKey_X; }
	if (strcmp(in, "Enter") == 0) { return ImGuiKey_Enter; }
	if (strcmp(in, "Backspace") == 0) { return ImGuiKey_Backspace; }
	if (strcmp(in, "Y") == 0) { return ImGuiKey_Y; }
	if (strcmp(in, "KeyPadEnter") == 0) { return ImGuiKey_KeyPadEnter; }
	if (strcmp(in, "End") == 0) { return ImGuiKey_End; }
	if (strcmp(in, "PageDown") == 0) { return ImGuiKey_PageDown; }
	return std::nullopt;
}
const char* getStringFromImGuiKey(ImGuiKey in)
{
	switch (in) {
		case 0: return "Tab";
		case 12: return "Space";
		case 5: return "PageUp";
		case 21: return "Z";
		case 10: return "Delete";
		case 1: return "LeftArrow";
		case 2: return "RightArrow";
		case 9: return "Insert";
		case 7: return "Home";
		case 4: return "DownArrow";
		case 14: return "Escape";
		case 3: return "UpArrow";
		case 16: return "A";
		case 18: return "V";
		case 17: return "C";
		case 19: return "X";
		case 13: return "Enter";
		case 11: return "Backspace";
		case 20: return "Y";
		case 15: return "KeyPadEnter";
		case 8: return "End";
		case 6: return "PageDown";
	}
	return "";
}

std::optional<ImGuiNavInput_> getImGuiNavInputFromString(const char* in)
{
	if (strcmp(in, "Menu") == 0) { return ImGuiNavInput_Menu; }
	if (strcmp(in, "TweakSlow") == 0) { return ImGuiNavInput_TweakSlow; }
	if (strcmp(in, "DpadRight") == 0) { return ImGuiNavInput_DpadRight; }
	if (strcmp(in, "LStickDown") == 0) { return ImGuiNavInput_LStickDown; }
	if (strcmp(in, "TweakFast") == 0) { return ImGuiNavInput_TweakFast; }
	if (strcmp(in, "Cancel") == 0) { return ImGuiNavInput_Cancel; }
	if (strcmp(in, "DpadDown") == 0) { return ImGuiNavInput_DpadDown; }
	if (strcmp(in, "FocusPrev") == 0) { return ImGuiNavInput_FocusPrev; }
	if (strcmp(in, "DpadUp") == 0) { return ImGuiNavInput_DpadUp; }
	if (strcmp(in, "LStickUp") == 0) { return ImGuiNavInput_LStickUp; }
	if (strcmp(in, "KeyMenu_") == 0) { return ImGuiNavInput_KeyMenu_; }
	if (strcmp(in, "LStickRight") == 0) { return ImGuiNavInput_LStickRight; }
	if (strcmp(in, "DpadLeft") == 0) { return ImGuiNavInput_DpadLeft; }
	if (strcmp(in, "InternalStart_") == 0) { return ImGuiNavInput_InternalStart_; }
	if (strcmp(in, "KeyLeft_") == 0) { return ImGuiNavInput_KeyLeft_; }
	if (strcmp(in, "KeyUp_") == 0) { return ImGuiNavInput_KeyUp_; }
	if (strcmp(in, "KeyRight_") == 0) { return ImGuiNavInput_KeyRight_; }
	if (strcmp(in, "Activate") == 0) { return ImGuiNavInput_Activate; }
	if (strcmp(in, "KeyDown_") == 0) { return ImGuiNavInput_KeyDown_; }
	if (strcmp(in, "FocusNext") == 0) { return ImGuiNavInput_FocusNext; }
	if (strcmp(in, "Input") == 0) { return ImGuiNavInput_Input; }
	if (strcmp(in, "LStickLeft") == 0) { return ImGuiNavInput_LStickLeft; }
	return std::nullopt;
}
const char* getStringFromImGuiNavInput(ImGuiNavInput in)
{
	switch (in) {
		case 3: return "Menu";
		case 14: return "TweakSlow";
		case 5: return "DpadRight";
		case 11: return "LStickDown";
		case 15: return "TweakFast";
		case 1: return "Cancel";
		case 7: return "DpadDown";
		case 12: return "FocusPrev";
		case 6: return "DpadUp";
		case 10: return "LStickUp";
		case 16: return "KeyMenu_";
		case 9: return "LStickRight";
		case 4: return "DpadLeft";
		// skipping // case ImGuiNavInput_KeyMenu_: return "InternalStart_";
		case 17: return "KeyLeft_";
		case 19: return "KeyUp_";
		case 18: return "KeyRight_";
		case 0: return "Activate";
		case 20: return "KeyDown_";
		case 13: return "FocusNext";
		case 2: return "Input";
		case 8: return "LStickLeft";
	}
	return "";
}

std::optional<ImGuiConfigFlags_> getImGuiConfigFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiConfigFlags_None; }
	if (strcmp(in, "NavNoCaptureKeyboard") == 0) { return ImGuiConfigFlags_NavNoCaptureKeyboard; }
	if (strcmp(in, "NavEnableGamepad") == 0) { return ImGuiConfigFlags_NavEnableGamepad; }
	if (strcmp(in, "IsSRGB") == 0) { return ImGuiConfigFlags_IsSRGB; }
	if (strcmp(in, "NavEnableKeyboard") == 0) { return ImGuiConfigFlags_NavEnableKeyboard; }
	if (strcmp(in, "NavEnableSetMousePos") == 0) { return ImGuiConfigFlags_NavEnableSetMousePos; }
	if (strcmp(in, "DpiEnableScaleFonts") == 0) { return ImGuiConfigFlags_DpiEnableScaleFonts; }
	if (strcmp(in, "DpiEnableScaleViewports") == 0) { return ImGuiConfigFlags_DpiEnableScaleViewports; }
	if (strcmp(in, "DockingEnable") == 0) { return ImGuiConfigFlags_DockingEnable; }
	if (strcmp(in, "IsTouchScreen") == 0) { return ImGuiConfigFlags_IsTouchScreen; }
	if (strcmp(in, "NoMouse") == 0) { return ImGuiConfigFlags_NoMouse; }
	if (strcmp(in, "NoMouseCursorChange") == 0) { return ImGuiConfigFlags_NoMouseCursorChange; }
	if (strcmp(in, "ViewportsEnable") == 0) { return ImGuiConfigFlags_ViewportsEnable; }
	return std::nullopt;
}
const char* getStringFromImGuiConfigFlags(ImGuiConfigFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 3: return "NavNoCaptureKeyboard";
		case 1 << 1: return "NavEnableGamepad";
		case 1 << 20: return "IsSRGB";
		case 1 << 0: return "NavEnableKeyboard";
		case 1 << 2: return "NavEnableSetMousePos";
		case 1 << 15: return "DpiEnableScaleFonts";
		case 1 << 14: return "DpiEnableScaleViewports";
		case 1 << 6: return "DockingEnable";
		case 1 << 21: return "IsTouchScreen";
		case 1 << 4: return "NoMouse";
		case 1 << 5: return "NoMouseCursorChange";
		case 1 << 10: return "ViewportsEnable";
	}
	return "";
}

std::optional<ImGuiBackendFlags_> getImGuiBackendFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiBackendFlags_None; }
	if (strcmp(in, "HasGamepad") == 0) { return ImGuiBackendFlags_HasGamepad; }
	if (strcmp(in, "HasMouseCursors") == 0) { return ImGuiBackendFlags_HasMouseCursors; }
	if (strcmp(in, "RendererHasViewports") == 0) { return ImGuiBackendFlags_RendererHasViewports; }
	if (strcmp(in, "HasMouseHoveredViewport") == 0) { return ImGuiBackendFlags_HasMouseHoveredViewport; }
	if (strcmp(in, "RendererHasVtxOffset") == 0) { return ImGuiBackendFlags_RendererHasVtxOffset; }
	if (strcmp(in, "PlatformHasViewports") == 0) { return ImGuiBackendFlags_PlatformHasViewports; }
	if (strcmp(in, "HasSetMousePos") == 0) { return ImGuiBackendFlags_HasSetMousePos; }
	return std::nullopt;
}
const char* getStringFromImGuiBackendFlags(ImGuiBackendFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 0: return "HasGamepad";
		case 1 << 1: return "HasMouseCursors";
		case 1 << 12: return "RendererHasViewports";
		case 1 << 11: return "HasMouseHoveredViewport";
		case 1 << 3: return "RendererHasVtxOffset";
		case 1 << 10: return "PlatformHasViewports";
		case 1 << 2: return "HasSetMousePos";
	}
	return "";
}

std::optional<ImGuiCol_> getImGuiColFromString(const char* in)
{
	if (strcmp(in, "ScrollbarGrab") == 0) { return ImGuiCol_ScrollbarGrab; }
	if (strcmp(in, "TabActive") == 0) { return ImGuiCol_TabActive; }
	if (strcmp(in, "TabHovered") == 0) { return ImGuiCol_TabHovered; }
	if (strcmp(in, "FrameBgActive") == 0) { return ImGuiCol_FrameBgActive; }
	if (strcmp(in, "ButtonHovered") == 0) { return ImGuiCol_ButtonHovered; }
	if (strcmp(in, "ChildBg") == 0) { return ImGuiCol_ChildBg; }
	if (strcmp(in, "PlotHistogram") == 0) { return ImGuiCol_PlotHistogram; }
	if (strcmp(in, "SliderGrabActive") == 0) { return ImGuiCol_SliderGrabActive; }
	if (strcmp(in, "ResizeGripActive") == 0) { return ImGuiCol_ResizeGripActive; }
	if (strcmp(in, "ModalWindowDimBg") == 0) { return ImGuiCol_ModalWindowDimBg; }
	if (strcmp(in, "FrameBg") == 0) { return ImGuiCol_FrameBg; }
	if (strcmp(in, "TextDisabled") == 0) { return ImGuiCol_TextDisabled; }
	if (strcmp(in, "ResizeGripHovered") == 0) { return ImGuiCol_ResizeGripHovered; }
	if (strcmp(in, "PlotHistogramHovered") == 0) { return ImGuiCol_PlotHistogramHovered; }
	if (strcmp(in, "PlotLines") == 0) { return ImGuiCol_PlotLines; }
	if (strcmp(in, "SliderGrab") == 0) { return ImGuiCol_SliderGrab; }
	if (strcmp(in, "TextSelectedBg") == 0) { return ImGuiCol_TextSelectedBg; }
	if (strcmp(in, "TabUnfocused") == 0) { return ImGuiCol_TabUnfocused; }
	if (strcmp(in, "TitleBgCollapsed") == 0) { return ImGuiCol_TitleBgCollapsed; }
	if (strcmp(in, "TitleBg") == 0) { return ImGuiCol_TitleBg; }
	if (strcmp(in, "NavHighlight") == 0) { return ImGuiCol_NavHighlight; }
	if (strcmp(in, "SeparatorHovered") == 0) { return ImGuiCol_SeparatorHovered; }
	if (strcmp(in, "ResizeGrip") == 0) { return ImGuiCol_ResizeGrip; }
	if (strcmp(in, "ButtonActive") == 0) { return ImGuiCol_ButtonActive; }
	if (strcmp(in, "SeparatorActive") == 0) { return ImGuiCol_SeparatorActive; }
	if (strcmp(in, "NavWindowingHighlight") == 0) { return ImGuiCol_NavWindowingHighlight; }
	if (strcmp(in, "Border") == 0) { return ImGuiCol_Border; }
	if (strcmp(in, "DragDropTarget") == 0) { return ImGuiCol_DragDropTarget; }
	if (strcmp(in, "PlotLinesHovered") == 0) { return ImGuiCol_PlotLinesHovered; }
	if (strcmp(in, "Separator") == 0) { return ImGuiCol_Separator; }
	if (strcmp(in, "FrameBgHovered") == 0) { return ImGuiCol_FrameBgHovered; }
	if (strcmp(in, "DockingEmptyBg") == 0) { return ImGuiCol_DockingEmptyBg; }
	if (strcmp(in, "DockingPreview") == 0) { return ImGuiCol_DockingPreview; }
	if (strcmp(in, "TabUnfocusedActive") == 0) { return ImGuiCol_TabUnfocusedActive; }
	if (strcmp(in, "Tab") == 0) { return ImGuiCol_Tab; }
	if (strcmp(in, "CheckMark") == 0) { return ImGuiCol_CheckMark; }
	if (strcmp(in, "ScrollbarGrabHovered") == 0) { return ImGuiCol_ScrollbarGrabHovered; }
	if (strcmp(in, "HeaderHovered") == 0) { return ImGuiCol_HeaderHovered; }
	if (strcmp(in, "HeaderActive") == 0) { return ImGuiCol_HeaderActive; }
	if (strcmp(in, "Button") == 0) { return ImGuiCol_Button; }
	if (strcmp(in, "ScrollbarGrabActive") == 0) { return ImGuiCol_ScrollbarGrabActive; }
	if (strcmp(in, "NavWindowingDimBg") == 0) { return ImGuiCol_NavWindowingDimBg; }
	if (strcmp(in, "PopupBg") == 0) { return ImGuiCol_PopupBg; }
	if (strcmp(in, "WindowBg") == 0) { return ImGuiCol_WindowBg; }
	if (strcmp(in, "MenuBarBg") == 0) { return ImGuiCol_MenuBarBg; }
	if (strcmp(in, "TitleBgActive") == 0) { return ImGuiCol_TitleBgActive; }
	if (strcmp(in, "Header") == 0) { return ImGuiCol_Header; }
	if (strcmp(in, "BorderShadow") == 0) { return ImGuiCol_BorderShadow; }
	if (strcmp(in, "ScrollbarBg") == 0) { return ImGuiCol_ScrollbarBg; }
	if (strcmp(in, "Text") == 0) { return ImGuiCol_Text; }
	return std::nullopt;
}
const char* getStringFromImGuiCol(ImGuiCol in)
{
	switch (in) {
		case 15: return "ScrollbarGrab";
		case 35: return "TabActive";
		case 34: return "TabHovered";
		case 9: return "FrameBgActive";
		case 22: return "ButtonHovered";
		case 3: return "ChildBg";
		case 42: return "PlotHistogram";
		case 20: return "SliderGrabActive";
		case 32: return "ResizeGripActive";
		case 49: return "ModalWindowDimBg";
		case 7: return "FrameBg";
		case 1: return "TextDisabled";
		case 31: return "ResizeGripHovered";
		case 43: return "PlotHistogramHovered";
		case 40: return "PlotLines";
		case 19: return "SliderGrab";
		case 44: return "TextSelectedBg";
		case 36: return "TabUnfocused";
		case 12: return "TitleBgCollapsed";
		case 10: return "TitleBg";
		case 46: return "NavHighlight";
		case 28: return "SeparatorHovered";
		case 30: return "ResizeGrip";
		case 23: return "ButtonActive";
		case 29: return "SeparatorActive";
		case 47: return "NavWindowingHighlight";
		case 5: return "Border";
		case 45: return "DragDropTarget";
		case 41: return "PlotLinesHovered";
		case 27: return "Separator";
		case 8: return "FrameBgHovered";
		case 39: return "DockingEmptyBg";
		case 38: return "DockingPreview";
		case 37: return "TabUnfocusedActive";
		case 33: return "Tab";
		case 18: return "CheckMark";
		case 16: return "ScrollbarGrabHovered";
		case 25: return "HeaderHovered";
		case 26: return "HeaderActive";
		case 21: return "Button";
		case 17: return "ScrollbarGrabActive";
		case 48: return "NavWindowingDimBg";
		case 4: return "PopupBg";
		case 2: return "WindowBg";
		case 13: return "MenuBarBg";
		case 11: return "TitleBgActive";
		case 24: return "Header";
		case 6: return "BorderShadow";
		case 14: return "ScrollbarBg";
		case 0: return "Text";
	}
	return "";
}

std::optional<ImGuiStyleVar_> getImGuiStyleVarFromString(const char* in)
{
	if (strcmp(in, "FrameBorderSize") == 0) { return ImGuiStyleVar_FrameBorderSize; }
	if (strcmp(in, "FrameRounding") == 0) { return ImGuiStyleVar_FrameRounding; }
	if (strcmp(in, "FramePadding") == 0) { return ImGuiStyleVar_FramePadding; }
	if (strcmp(in, "ChildBorderSize") == 0) { return ImGuiStyleVar_ChildBorderSize; }
	if (strcmp(in, "Alpha") == 0) { return ImGuiStyleVar_Alpha; }
	if (strcmp(in, "IndentSpacing") == 0) { return ImGuiStyleVar_IndentSpacing; }
	if (strcmp(in, "PopupBorderSize") == 0) { return ImGuiStyleVar_PopupBorderSize; }
	if (strcmp(in, "WindowTitleAlign") == 0) { return ImGuiStyleVar_WindowTitleAlign; }
	if (strcmp(in, "ChildRounding") == 0) { return ImGuiStyleVar_ChildRounding; }
	if (strcmp(in, "GrabRounding") == 0) { return ImGuiStyleVar_GrabRounding; }
	if (strcmp(in, "WindowBorderSize") == 0) { return ImGuiStyleVar_WindowBorderSize; }
	if (strcmp(in, "WindowMinSize") == 0) { return ImGuiStyleVar_WindowMinSize; }
	if (strcmp(in, "ScrollbarSize") == 0) { return ImGuiStyleVar_ScrollbarSize; }
	if (strcmp(in, "SelectableTextAlign") == 0) { return ImGuiStyleVar_SelectableTextAlign; }
	if (strcmp(in, "ButtonTextAlign") == 0) { return ImGuiStyleVar_ButtonTextAlign; }
	if (strcmp(in, "TabRounding") == 0) { return ImGuiStyleVar_TabRounding; }
	if (strcmp(in, "WindowPadding") == 0) { return ImGuiStyleVar_WindowPadding; }
	if (strcmp(in, "ItemInnerSpacing") == 0) { return ImGuiStyleVar_ItemInnerSpacing; }
	if (strcmp(in, "ScrollbarRounding") == 0) { return ImGuiStyleVar_ScrollbarRounding; }
	if (strcmp(in, "GrabMinSize") == 0) { return ImGuiStyleVar_GrabMinSize; }
	if (strcmp(in, "PopupRounding") == 0) { return ImGuiStyleVar_PopupRounding; }
	if (strcmp(in, "ItemSpacing") == 0) { return ImGuiStyleVar_ItemSpacing; }
	if (strcmp(in, "WindowRounding") == 0) { return ImGuiStyleVar_WindowRounding; }
	return std::nullopt;
}
const char* getStringFromImGuiStyleVar(ImGuiStyleVar in)
{
	switch (in) {
		case 12: return "FrameBorderSize";
		case 11: return "FrameRounding";
		case 10: return "FramePadding";
		case 7: return "ChildBorderSize";
		case 0: return "Alpha";
		case 15: return "IndentSpacing";
		case 9: return "PopupBorderSize";
		case 5: return "WindowTitleAlign";
		case 6: return "ChildRounding";
		case 19: return "GrabRounding";
		case 3: return "WindowBorderSize";
		case 4: return "WindowMinSize";
		case 16: return "ScrollbarSize";
		case 22: return "SelectableTextAlign";
		case 21: return "ButtonTextAlign";
		case 20: return "TabRounding";
		case 1: return "WindowPadding";
		case 14: return "ItemInnerSpacing";
		case 17: return "ScrollbarRounding";
		case 18: return "GrabMinSize";
		case 8: return "PopupRounding";
		case 13: return "ItemSpacing";
		case 2: return "WindowRounding";
	}
	return "";
}

std::optional<ImGuiColorEditFlags_> getImGuiColorEditFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiColorEditFlags_None; }
	if (strcmp(in, "NoTooltip") == 0) { return ImGuiColorEditFlags_NoTooltip; }
	if (strcmp(in, "_OptionsDefault") == 0) { return ImGuiColorEditFlags__OptionsDefault; }
	if (strcmp(in, "NoDragDrop") == 0) { return ImGuiColorEditFlags_NoDragDrop; }
	if (strcmp(in, "_DataTypeMask") == 0) { return ImGuiColorEditFlags__DataTypeMask; }
	if (strcmp(in, "NoLabel") == 0) { return ImGuiColorEditFlags_NoLabel; }
	if (strcmp(in, "_InputMask") == 0) { return ImGuiColorEditFlags__InputMask; }
	if (strcmp(in, "_PickerMask") == 0) { return ImGuiColorEditFlags__PickerMask; }
	if (strcmp(in, "AlphaPreviewHalf") == 0) { return ImGuiColorEditFlags_AlphaPreviewHalf; }
	if (strcmp(in, "_DisplayMask") == 0) { return ImGuiColorEditFlags__DisplayMask; }
	if (strcmp(in, "Uint8") == 0) { return ImGuiColorEditFlags_Uint8; }
	if (strcmp(in, "NoPicker") == 0) { return ImGuiColorEditFlags_NoPicker; }
	if (strcmp(in, "DisplayHSV") == 0) { return ImGuiColorEditFlags_DisplayHSV; }
	if (strcmp(in, "HDR") == 0) { return ImGuiColorEditFlags_HDR; }
	if (strcmp(in, "NoAlpha") == 0) { return ImGuiColorEditFlags_NoAlpha; }
	if (strcmp(in, "NoSidePreview") == 0) { return ImGuiColorEditFlags_NoSidePreview; }
	if (strcmp(in, "AlphaPreview") == 0) { return ImGuiColorEditFlags_AlphaPreview; }
	if (strcmp(in, "PickerHueWheel") == 0) { return ImGuiColorEditFlags_PickerHueWheel; }
	if (strcmp(in, "AlphaBar") == 0) { return ImGuiColorEditFlags_AlphaBar; }
	if (strcmp(in, "NoInputs") == 0) { return ImGuiColorEditFlags_NoInputs; }
	if (strcmp(in, "Float") == 0) { return ImGuiColorEditFlags_Float; }
	if (strcmp(in, "InputHSV") == 0) { return ImGuiColorEditFlags_InputHSV; }
	if (strcmp(in, "NoSmallPreview") == 0) { return ImGuiColorEditFlags_NoSmallPreview; }
	if (strcmp(in, "PickerHueBar") == 0) { return ImGuiColorEditFlags_PickerHueBar; }
	if (strcmp(in, "NoOptions") == 0) { return ImGuiColorEditFlags_NoOptions; }
	if (strcmp(in, "DisplayHex") == 0) { return ImGuiColorEditFlags_DisplayHex; }
	if (strcmp(in, "DisplayRGB") == 0) { return ImGuiColorEditFlags_DisplayRGB; }
	if (strcmp(in, "InputRGB") == 0) { return ImGuiColorEditFlags_InputRGB; }
	return std::nullopt;
}
const char* getStringFromImGuiColorEditFlags(ImGuiColorEditFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 6: return "NoTooltip";
		// skipping // case ImGuiColorEditFlags_Uint8|ImGuiColorEditFlags_DisplayRGB|ImGuiColorEditFlags_InputRGB|ImGuiColorEditFlags_PickerHueBar: return "_OptionsDefault";
		case 1 << 9: return "NoDragDrop";
		// skipping // case ImGuiColorEditFlags_Uint8|ImGuiColorEditFlags_Float: return "_DataTypeMask";
		case 1 << 7: return "NoLabel";
		// skipping // case ImGuiColorEditFlags_InputRGB|ImGuiColorEditFlags_InputHSV: return "_InputMask";
		// skipping // case ImGuiColorEditFlags_PickerHueWheel|ImGuiColorEditFlags_PickerHueBar: return "_PickerMask";
		case 1 << 18: return "AlphaPreviewHalf";
		// skipping // case ImGuiColorEditFlags_DisplayRGB|ImGuiColorEditFlags_DisplayHSV|ImGuiColorEditFlags_DisplayHex: return "_DisplayMask";
		case 1 << 23: return "Uint8";
		case 1 << 2: return "NoPicker";
		case 1 << 21: return "DisplayHSV";
		case 1 << 19: return "HDR";
		case 1 << 1: return "NoAlpha";
		case 1 << 8: return "NoSidePreview";
		case 1 << 17: return "AlphaPreview";
		case 1 << 26: return "PickerHueWheel";
		case 1 << 16: return "AlphaBar";
		case 1 << 5: return "NoInputs";
		case 1 << 24: return "Float";
		case 1 << 28: return "InputHSV";
		case 1 << 4: return "NoSmallPreview";
		case 1 << 25: return "PickerHueBar";
		case 1 << 3: return "NoOptions";
		case 1 << 22: return "DisplayHex";
		case 1 << 20: return "DisplayRGB";
		case 1 << 27: return "InputRGB";
	}
	return "";
}

std::optional<ImGuiMouseButton_> getImGuiMouseButtonFromString(const char* in)
{
	if (strcmp(in, "Right") == 0) { return ImGuiMouseButton_Right; }
	if (strcmp(in, "Middle") == 0) { return ImGuiMouseButton_Middle; }
	if (strcmp(in, "Left") == 0) { return ImGuiMouseButton_Left; }
	return std::nullopt;
}
const char* getStringFromImGuiMouseButton(ImGuiMouseButton in)
{
	switch (in) {
		case 1: return "Right";
		case 2: return "Middle";
		case 0: return "Left";
	}
	return "";
}

std::optional<ImGuiMouseCursor_> getImGuiMouseCursorFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiMouseCursor_None; }
	if (strcmp(in, "ResizeEW") == 0) { return ImGuiMouseCursor_ResizeEW; }
	if (strcmp(in, "ResizeNESW") == 0) { return ImGuiMouseCursor_ResizeNESW; }
	if (strcmp(in, "ResizeNWSE") == 0) { return ImGuiMouseCursor_ResizeNWSE; }
	if (strcmp(in, "TextInput") == 0) { return ImGuiMouseCursor_TextInput; }
	if (strcmp(in, "ResizeAll") == 0) { return ImGuiMouseCursor_ResizeAll; }
	if (strcmp(in, "ResizeNS") == 0) { return ImGuiMouseCursor_ResizeNS; }
	if (strcmp(in, "NotAllowed") == 0) { return ImGuiMouseCursor_NotAllowed; }
	if (strcmp(in, "Hand") == 0) { return ImGuiMouseCursor_Hand; }
	if (strcmp(in, "Arrow") == 0) { return ImGuiMouseCursor_Arrow; }
	return std::nullopt;
}
const char* getStringFromImGuiMouseCursor(ImGuiMouseCursor in)
{
	switch (in) {
		case -1: return "None";
		case 4: return "ResizeEW";
		case 5: return "ResizeNESW";
		case 6: return "ResizeNWSE";
		case 1: return "TextInput";
		case 2: return "ResizeAll";
		case 3: return "ResizeNS";
		case 8: return "NotAllowed";
		case 7: return "Hand";
		case 0: return "Arrow";
	}
	return "";
}

std::optional<ImGuiCond_> getImGuiCondFromString(const char* in)
{
	if (strcmp(in, "Once") == 0) { return ImGuiCond_Once; }
	if (strcmp(in, "Always") == 0) { return ImGuiCond_Always; }
	if (strcmp(in, "Appearing") == 0) { return ImGuiCond_Appearing; }
	if (strcmp(in, "FirstUseEver") == 0) { return ImGuiCond_FirstUseEver; }
	return std::nullopt;
}
const char* getStringFromImGuiCond(ImGuiCond in)
{
	switch (in) {
		case 1 << 1: return "Once";
		case 1 << 0: return "Always";
		case 1 << 3: return "Appearing";
		case 1 << 2: return "FirstUseEver";
	}
	return "";
}

std::optional<ImDrawCornerFlags_> getImDrawCornerFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImDrawCornerFlags_None; }
	if (strcmp(in, "TopLeft") == 0) { return ImDrawCornerFlags_TopLeft; }
	if (strcmp(in, "BotLeft") == 0) { return ImDrawCornerFlags_BotLeft; }
	if (strcmp(in, "Bot") == 0) { return ImDrawCornerFlags_Bot; }
	if (strcmp(in, "All") == 0) { return ImDrawCornerFlags_All; }
	if (strcmp(in, "TopRight") == 0) { return ImDrawCornerFlags_TopRight; }
	if (strcmp(in, "Right") == 0) { return ImDrawCornerFlags_Right; }
	if (strcmp(in, "BotRight") == 0) { return ImDrawCornerFlags_BotRight; }
	if (strcmp(in, "Top") == 0) { return ImDrawCornerFlags_Top; }
	if (strcmp(in, "Left") == 0) { return ImDrawCornerFlags_Left; }
	return std::nullopt;
}
const char* getStringFromImDrawCornerFlags(ImDrawCornerFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 0: return "TopLeft";
		case 1 << 2: return "BotLeft";
		// skipping // case ImDrawCornerFlags_BotLeft | ImDrawCornerFlags_BotRight: return "Bot";
		// skipping // case 0xF: return "All";
		case 1 << 1: return "TopRight";
		// skipping // case ImDrawCornerFlags_TopRight | ImDrawCornerFlags_BotRight: return "Right";
		case 1 << 3: return "BotRight";
		// skipping // case ImDrawCornerFlags_TopLeft | ImDrawCornerFlags_TopRight: return "Top";
		// skipping // case ImDrawCornerFlags_TopLeft | ImDrawCornerFlags_BotLeft: return "Left";
	}
	return "";
}

std::optional<ImDrawListFlags_> getImDrawListFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImDrawListFlags_None; }
	if (strcmp(in, "AllowVtxOffset") == 0) { return ImDrawListFlags_AllowVtxOffset; }
	if (strcmp(in, "AntiAliasedFill") == 0) { return ImDrawListFlags_AntiAliasedFill; }
	if (strcmp(in, "AntiAliasedLines") == 0) { return ImDrawListFlags_AntiAliasedLines; }
	return std::nullopt;
}
const char* getStringFromImDrawListFlags(ImDrawListFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 2: return "AllowVtxOffset";
		case 1 << 1: return "AntiAliasedFill";
		case 1 << 0: return "AntiAliasedLines";
	}
	return "";
}

std::optional<ImFontAtlasFlags_> getImFontAtlasFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImFontAtlasFlags_None; }
	if (strcmp(in, "NoPowerOfTwoHeight") == 0) { return ImFontAtlasFlags_NoPowerOfTwoHeight; }
	if (strcmp(in, "NoMouseCursors") == 0) { return ImFontAtlasFlags_NoMouseCursors; }
	return std::nullopt;
}
const char* getStringFromImFontAtlasFlags(ImFontAtlasFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 0: return "NoPowerOfTwoHeight";
		case 1 << 1: return "NoMouseCursors";
	}
	return "";
}

std::optional<ImGuiViewportFlags_> getImGuiViewportFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiViewportFlags_None; }
	if (strcmp(in, "NoFocusOnClick") == 0) { return ImGuiViewportFlags_NoFocusOnClick; }
	if (strcmp(in, "NoRendererClear") == 0) { return ImGuiViewportFlags_NoRendererClear; }
	if (strcmp(in, "TopMost") == 0) { return ImGuiViewportFlags_TopMost; }
	if (strcmp(in, "NoTaskBarIcon") == 0) { return ImGuiViewportFlags_NoTaskBarIcon; }
	if (strcmp(in, "CanHostOtherWindows") == 0) { return ImGuiViewportFlags_CanHostOtherWindows; }
	if (strcmp(in, "Minimized") == 0) { return ImGuiViewportFlags_Minimized; }
	if (strcmp(in, "NoAutoMerge") == 0) { return ImGuiViewportFlags_NoAutoMerge; }
	if (strcmp(in, "NoInputs") == 0) { return ImGuiViewportFlags_NoInputs; }
	if (strcmp(in, "NoFocusOnAppearing") == 0) { return ImGuiViewportFlags_NoFocusOnAppearing; }
	if (strcmp(in, "NoDecoration") == 0) { return ImGuiViewportFlags_NoDecoration; }
	return std::nullopt;
}
const char* getStringFromImGuiViewportFlags(ImGuiViewportFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 3: return "NoFocusOnClick";
		case 1 << 5: return "NoRendererClear";
		case 1 << 6: return "TopMost";
		case 1 << 1: return "NoTaskBarIcon";
		case 1 << 9: return "CanHostOtherWindows";
		case 1 << 7: return "Minimized";
		case 1 << 8: return "NoAutoMerge";
		case 1 << 4: return "NoInputs";
		case 1 << 2: return "NoFocusOnAppearing";
		case 1 << 0: return "NoDecoration";
	}
	return "";
}

// End Enums }}}

// Helpers {{{
const char* wrenExGetSlotStringDefault(WrenVM* vm, int narg, const char* d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	return wrenGetSlotString(vm, narg);
}

bool wrenExGetSlotBoolDefault(WrenVM* vm, int narg, bool d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	return wrenGetSlotBool(vm, narg);
}

int wrenExGetSlotInt(WrenVM* vm, int narg)
{
	// TODO: check integralness
	return static_cast<int>(wrenGetSlotDouble(vm, narg));
}

int wrenExGetSlotIntDefault(WrenVM* vm, int narg, int d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	// TODO: check integralness
	return static_cast<int>(wrenGetSlotDouble(vm, narg));
}

double wrenExGetSlotDoubleDefault(WrenVM* vm, int narg, double d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	return wrenGetSlotDouble(vm, narg);
}

float wrenExGetSlotFloat(WrenVM* vm, int narg)
{
	return static_cast<float>(wrenGetSlotDouble(vm, narg));
}

float wrenExGetSlotFloatDefault(WrenVM* vm, int narg, float d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	return wrenExGetSlotFloat(vm, narg);
}

unsigned int wrenExGetSlotUInt(WrenVM* vm, int narg)
{
	// TODO: check integralness
	return static_cast<unsigned int>(wrenGetSlotDouble(vm, narg));
}

unsigned int wrenExGetSlotUIntDefault(WrenVM* vm, int narg, unsigned int d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	// TODO: check integralness
	return static_cast<unsigned int>(wrenGetSlotDouble(vm, narg));
}

void wrenExAbortf(WrenVM* vm, const char* fmt, ...)
{
	char buf[1000]; // arbitrary size

	va_list arglist;
    va_start(arglist, fmt);
    vsnprintf(buf, 1000, fmt, arglist);
    va_end(arglist);

	int slotIdx = wrenGetSlotCount(vm);
	wrenEnsureSlots(vm, slotIdx + 1);
	wrenSetSlotString(vm, slotIdx, buf);
	wrenAbortFiber(vm, slotIdx);
}

template<typename T, typename U>
T wrenExGetSlotEnum(U fromString, WrenVM* vm, int narg)
{
	const char* s = wrenGetSlotString(vm, narg);
	std::optional<T> opt = fromString(s);
	if(!opt) {
		wrenExAbortf(vm, "Invalid enum as argument %d, received \"%s\"", narg, s);
	}
	return *opt;
}

template<typename T, typename U>
T wrenExGetSlotEnumsDefault(U fromString, WrenVM* vm, int narg, T d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	return wrenExGetSlotEnum<T, U>(fromString, vm, narg);
}

template<typename T, typename U>
T wrenExGetSlotFlags(U fromString, WrenVM* vm, int narg)
{
	T out{};
	WrenType type = wrenGetSlotType(vm, narg);
	if (type == WREN_TYPE_NUM) {
		// variant A: raw number
		out = static_cast<T>(wrenExGetSlotInt(vm, narg));
	} else if (type == WREN_TYPE_STRING) {
		// variant B: string, split by '|'
		const char* s = wrenGetSlotString(vm, narg);
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);
		while (std::getline(tokenStream, token, '|')) {
			std::optional<T> opt = fromString(token.c_str());
			if (!opt) {
				wrenExAbortf(vm, "Unrecognized value in flags parameter %d: %s", narg, token.c_str());
			}
			out = out | *opt;
		}
	} else {
		wrenExAbortf(vm, "Unrecognized flag parameter %d: must be int, string, or table", narg);
	}

	return out;
}

template<typename T, typename U>
T wrenExGetSlotFlagsDefault(U fromString, WrenVM* vm, int narg, T d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	return wrenExGetSlotFlags<T, U>(fromString, vm, narg);
}

// End Helpers }}}

// Functions {{{
// skipping w_CreateContext due to unimplemented return type: "ImGuiContext*"

// skipping w_DestroyContext due to unimplemented argument type: "ImGuiContext*"

// skipping w_GetCurrentContext due to unimplemented return type: "ImGuiContext*"

// skipping w_SetCurrentContext due to unimplemented argument type: "ImGuiContext*"

// skipping w_GetIO due to unimplemented return type: "ImGuiIO&"

// skipping w_GetStyle due to unimplemented return type: "ImGuiStyle&"

/*  start a new Dear ImGui frame, you can submit any command from this point until Render()/EndFrame(). */
void w_NewFrame(WrenVM *vm)
{
	ImGui::NewFrame();
	
}

/*  ends the Dear ImGui frame. automatically called by Render(), you likely don't need to call that yourself directly. If you don't need to render data (skipping rendering) you may call EndFrame() but you'll have wasted CPU already! If you don't need to render, better to not create any imgui windows and not call NewFrame() at all! */
void w_EndFrame(WrenVM *vm)
{
	ImGui::EndFrame();
	
}

/*  ends the Dear ImGui frame, finalize the draw data. You can get call GetDrawData() to obtain it and run your rendering function. (Obsolete: this used to call io.RenderDrawListsFn(). Nowadays, we allow and prefer calling your render function yourself.) */
void w_Render(WrenVM *vm)
{
	ImGui::Render();
	
}

// skipping w_GetDrawData due to unimplemented return type: "ImDrawData*"

// skipping w_ShowDemoWindow due to unimplemented argument type: "bool*"

// skipping w_ShowAboutWindow due to unimplemented argument type: "bool*"

// skipping w_ShowMetricsWindow due to unimplemented argument type: "bool*"

// skipping w_ShowStyleEditor due to unimplemented argument type: "ImGuiStyle*"

/*  add style selector block (not a window), essentially a combo listing the default styles. */
void w_ShowStyleSelector(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	
	bool out = ImGui::ShowStyleSelector(label);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  add font selector block (not a window), essentially a combo listing the loaded fonts. */
void w_ShowFontSelector(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	
	ImGui::ShowFontSelector(label);
	
}

/*  add basic help/info block (not a window): how to manipulate ImGui as a end-user (mouse/keyboard controls). */
void w_ShowUserGuide(WrenVM *vm)
{
	ImGui::ShowUserGuide();
	
}

/*  get the compiled version string e.g. "1.23" (essentially the compiled value for IMGUI_VERSION) */
void w_GetVersion(WrenVM *vm)
{
	const char* out = ImGui::GetVersion();
	
	wrenSetSlotString(vm, 0, out);
}

// skipping w_StyleColorsDark due to unimplemented argument type: "ImGuiStyle*"

// skipping w_StyleColorsClassic due to unimplemented argument type: "ImGuiStyle*"

// skipping w_StyleColorsLight due to unimplemented argument type: "ImGuiStyle*"

// skipping w_Begin due to unimplemented argument type: "bool*"

void w_End(WrenVM *vm)
{
	ImGui::End();
	
}

// skipping w_BeginChild_Override1 due to unimplemented argument type: "const ImVec2&"

// skipping w_BeginChild_Override2 due to unimplemented argument type: "const ImVec2&"

void w_EndChild(WrenVM *vm)
{
	ImGui::EndChild();
	
}

void w_IsWindowAppearing(WrenVM *vm)
{
	bool out = ImGui::IsWindowAppearing();
	
	wrenSetSlotBool(vm, 0, out);
}

void w_IsWindowCollapsed(WrenVM *vm)
{
	bool out = ImGui::IsWindowCollapsed();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is current window focused? or its root/child, depending on flags. see flags for options. */
void w_IsWindowFocused(WrenVM *vm)
{
	auto flags = wrenExGetSlotFlagsDefault<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, vm, 1, 0);
	
	bool out = ImGui::IsWindowFocused(flags);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is current window hovered (and typically: not blocked by a popup/modal)? see flags for options. NB: If you are trying to check whether your mouse should be dispatched to imgui or to your app, you should use the 'io.WantCaptureMouse' boolean for that! Please read the FAQ! */
void w_IsWindowHovered(WrenVM *vm)
{
	auto flags = wrenExGetSlotFlagsDefault<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, vm, 1, 0);
	
	bool out = ImGui::IsWindowHovered(flags);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_GetWindowDrawList due to unimplemented return type: "ImDrawList*"

/*  get DPI scale currently associated to the current window's viewport. */
void w_GetWindowDpiScale(WrenVM *vm)
{
	float out = ImGui::GetWindowDpiScale();
	
	wrenSetSlotDouble(vm, 0, out);
}

// skipping w_GetWindowViewport due to unimplemented return type: "ImGuiViewport*"

// skipping w_GetWindowPos due to unimplemented return type: "ImVec2"

// skipping w_GetWindowSize due to unimplemented return type: "ImVec2"

/*  get current window width (shortcut for GetWindowSize().x) */
void w_GetWindowWidth(WrenVM *vm)
{
	float out = ImGui::GetWindowWidth();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  get current window height (shortcut for GetWindowSize().y) */
void w_GetWindowHeight(WrenVM *vm)
{
	float out = ImGui::GetWindowHeight();
	
	wrenSetSlotDouble(vm, 0, out);
}

// skipping w_SetNextWindowPos due to unimplemented argument type: "const ImVec2&"

// skipping w_SetNextWindowSize due to unimplemented argument type: "const ImVec2&"

// skipping w_SetNextWindowSizeConstraints due to unimplemented argument type: "const ImVec2&"

// skipping w_SetNextWindowContentSize due to unimplemented argument type: "const ImVec2&"

/*  set next window collapsed state. call before Begin() */
void w_SetNextWindowCollapsed(WrenVM *vm)
{
	auto collapsed = wrenGetSlotBool(vm, 1);
	auto cond = wrenExGetSlotEnumsDefault<ImGuiCond>(getImGuiCondFromString, vm, 2, 0);
	
	ImGui::SetNextWindowCollapsed(collapsed, cond);
	
}

/*  set next window to be focused / top-most. call before Begin() */
void w_SetNextWindowFocus(WrenVM *vm)
{
	ImGui::SetNextWindowFocus();
	
}

/*  set next window background color alpha. helper to easily override the Alpha component of ImGuiCol_WindowBg/ChildBg/PopupBg. you may also use ImGuiWindowFlags_NoBackground. */
void w_SetNextWindowBgAlpha(WrenVM *vm)
{
	auto alpha = wrenExGetSlotFloat(vm, 1);
	
	ImGui::SetNextWindowBgAlpha(alpha);
	
}

/*  set next window viewport */
void w_SetNextWindowViewport(WrenVM *vm)
{
	auto viewport_id = static_cast<ImGuiID>(wrenExGetSlotInt(vm, 1));
	
	ImGui::SetNextWindowViewport(viewport_id);
	
}

// skipping w_SetWindowPos_Override1 due to unimplemented argument type: "const ImVec2&"

// skipping w_SetWindowSize_Override1 due to unimplemented argument type: "const ImVec2&"

/*  (not recommended) set current window collapsed state. prefer using SetNextWindowCollapsed(). */
void w_SetWindowCollapsed_Override1(WrenVM *vm)
{
	auto collapsed = wrenGetSlotBool(vm, 1);
	auto cond = wrenExGetSlotEnumsDefault<ImGuiCond>(getImGuiCondFromString, vm, 2, 0);
	
	ImGui::SetWindowCollapsed(collapsed, cond);
	
}

/*  (not recommended) set current window to be focused / top-most. prefer using SetNextWindowFocus(). */
void w_SetWindowFocus_Override1(WrenVM *vm)
{
	ImGui::SetWindowFocus();
	
}

/*  set font scale. Adjust IO.FontGlobalScale if you want to scale all windows. This is an old API! For correct scaling, prefer to reload font + rebuild ImFontAtlas + call style.ScaleAllSizes(). */
void w_SetWindowFontScale(WrenVM *vm)
{
	auto scale = wrenExGetSlotFloat(vm, 1);
	
	ImGui::SetWindowFontScale(scale);
	
}

// skipping w_SetWindowPos_Override2 due to unimplemented argument type: "const ImVec2&"

// skipping w_SetWindowSize_Override2 due to unimplemented argument type: "const ImVec2&"

/*  set named window collapsed state */
void w_SetWindowCollapsed_Override2(WrenVM *vm)
{
	auto name = wrenGetSlotString(vm, 1);
	auto collapsed = wrenGetSlotBool(vm, 2);
	auto cond = wrenExGetSlotEnumsDefault<ImGuiCond>(getImGuiCondFromString, vm, 3, 0);
	
	ImGui::SetWindowCollapsed(name, collapsed, cond);
	
}

/*  set named window to be focused / top-most. use NULL to remove focus. */
void w_SetWindowFocus_Override2(WrenVM *vm)
{
	auto name = wrenGetSlotString(vm, 1);
	
	ImGui::SetWindowFocus(name);
	
}

// skipping w_GetContentRegionMax due to unimplemented return type: "ImVec2"

// skipping w_GetContentRegionAvail due to unimplemented return type: "ImVec2"

// skipping w_GetWindowContentRegionMin due to unimplemented return type: "ImVec2"

// skipping w_GetWindowContentRegionMax due to unimplemented return type: "ImVec2"

void w_GetWindowContentRegionWidth(WrenVM *vm)
{
	float out = ImGui::GetWindowContentRegionWidth();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  get scrolling amount [0..GetScrollMaxX()] */
void w_GetScrollX(WrenVM *vm)
{
	float out = ImGui::GetScrollX();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  get scrolling amount [0..GetScrollMaxY()] */
void w_GetScrollY(WrenVM *vm)
{
	float out = ImGui::GetScrollY();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  get maximum scrolling amount ~~ ContentSize.X - WindowSize.X */
void w_GetScrollMaxX(WrenVM *vm)
{
	float out = ImGui::GetScrollMaxX();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  get maximum scrolling amount ~~ ContentSize.Y - WindowSize.Y */
void w_GetScrollMaxY(WrenVM *vm)
{
	float out = ImGui::GetScrollMaxY();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  set scrolling amount [0..GetScrollMaxX()] */
void w_SetScrollX(WrenVM *vm)
{
	auto scroll_x = wrenExGetSlotFloat(vm, 1);
	
	ImGui::SetScrollX(scroll_x);
	
}

/*  set scrolling amount [0..GetScrollMaxY()] */
void w_SetScrollY(WrenVM *vm)
{
	auto scroll_y = wrenExGetSlotFloat(vm, 1);
	
	ImGui::SetScrollY(scroll_y);
	
}

/*  adjust scrolling amount to make current cursor position visible. center_x_ratio=0.0: left, 0.5: center, 1.0: right. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead. */
void w_SetScrollHereX(WrenVM *vm)
{
	auto center_x_ratio = wrenExGetSlotFloatDefault(vm, 1, 0.5f);
	
	ImGui::SetScrollHereX(center_x_ratio);
	
}

/*  adjust scrolling amount to make current cursor position visible. center_y_ratio=0.0: top, 0.5: center, 1.0: bottom. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead. */
void w_SetScrollHereY(WrenVM *vm)
{
	auto center_y_ratio = wrenExGetSlotFloatDefault(vm, 1, 0.5f);
	
	ImGui::SetScrollHereY(center_y_ratio);
	
}

/*  adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position. */
void w_SetScrollFromPosX(WrenVM *vm)
{
	auto local_x = wrenExGetSlotFloat(vm, 1);
	auto center_x_ratio = wrenExGetSlotFloatDefault(vm, 2, 0.5f);
	
	ImGui::SetScrollFromPosX(local_x, center_x_ratio);
	
}

/*  adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position. */
void w_SetScrollFromPosY(WrenVM *vm)
{
	auto local_y = wrenExGetSlotFloat(vm, 1);
	auto center_y_ratio = wrenExGetSlotFloatDefault(vm, 2, 0.5f);
	
	ImGui::SetScrollFromPosY(local_y, center_y_ratio);
	
}

// skipping w_PushFont due to unimplemented argument type: "ImFont*"

void w_PopFont(WrenVM *vm)
{
	ImGui::PopFont();
	
}

void w_PushStyleColor_Override1(WrenVM *vm)
{
	auto idx = wrenExGetSlotEnum<ImGuiCol>(getImGuiColFromString, vm, 1);
	auto col = static_cast<ImU32>(wrenExGetSlotUInt(vm, 2));
	
	ImGui::PushStyleColor(idx, col);
	
}

// skipping w_PushStyleColor_Override2 due to unimplemented argument type: "const ImVec4&"

void w_PopStyleColor(WrenVM *vm)
{
	auto count = wrenExGetSlotIntDefault(vm, 1, 1);
	
	ImGui::PopStyleColor(count);
	
}

void w_PushStyleVar_Override1(WrenVM *vm)
{
	auto idx = wrenExGetSlotEnum<ImGuiStyleVar>(getImGuiStyleVarFromString, vm, 1);
	auto val = wrenExGetSlotFloat(vm, 2);
	
	ImGui::PushStyleVar(idx, val);
	
}

// skipping w_PushStyleVar_Override2 due to unimplemented argument type: "const ImVec2&"

void w_PopStyleVar(WrenVM *vm)
{
	auto count = wrenExGetSlotIntDefault(vm, 1, 1);
	
	ImGui::PopStyleVar(count);
	
}

// skipping w_GetStyleColorVec4 due to unimplemented return type: "const ImVec4&"

// skipping w_GetFont due to unimplemented return type: "ImFont*"

/*  get current font size (= height in pixels) of current font with current scale applied */
void w_GetFontSize(WrenVM *vm)
{
	float out = ImGui::GetFontSize();
	
	wrenSetSlotDouble(vm, 0, out);
}

// skipping w_GetFontTexUvWhitePixel due to unimplemented return type: "ImVec2"

/*  set width of items for common large "item+label" widgets. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side). 0.0f = default to ~2/3 of windows width, */
void w_PushItemWidth(WrenVM *vm)
{
	auto item_width = wrenExGetSlotFloat(vm, 1);
	
	ImGui::PushItemWidth(item_width);
	
}

void w_PopItemWidth(WrenVM *vm)
{
	ImGui::PopItemWidth();
	
}

/*  set width of the _next_ common large "item+label" widget. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side) */
void w_SetNextItemWidth(WrenVM *vm)
{
	auto item_width = wrenExGetSlotFloat(vm, 1);
	
	ImGui::SetNextItemWidth(item_width);
	
}

/*  width of item given pushed settings and current cursor position. NOT necessarily the width of last item unlike most 'Item' functions. */
void w_CalcItemWidth(WrenVM *vm)
{
	float out = ImGui::CalcItemWidth();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  word-wrapping for Text*() commands. < 0.0f: no wrapping; 0.0f: wrap to end of window (or column); > 0.0f: wrap at 'wrap_pos_x' position in window local space */
void w_PushTextWrapPos(WrenVM *vm)
{
	auto wrap_local_pos_x = wrenExGetSlotFloatDefault(vm, 1, 0.0f);
	
	ImGui::PushTextWrapPos(wrap_local_pos_x);
	
}

void w_PopTextWrapPos(WrenVM *vm)
{
	ImGui::PopTextWrapPos();
	
}

/*  allow focusing using TAB/Shift-TAB, enabled by default but you can disable it for certain widgets */
void w_PushAllowKeyboardFocus(WrenVM *vm)
{
	auto allow_keyboard_focus = wrenGetSlotBool(vm, 1);
	
	ImGui::PushAllowKeyboardFocus(allow_keyboard_focus);
	
}

void w_PopAllowKeyboardFocus(WrenVM *vm)
{
	ImGui::PopAllowKeyboardFocus();
	
}

/*  in 'repeat' mode, Button*() functions return repeated true in a typematic manner (using io.KeyRepeatDelay/io.KeyRepeatRate setting). Note that you can call IsItemActive() after any Button() to tell if the button is held in the current frame. */
void w_PushButtonRepeat(WrenVM *vm)
{
	auto repeat = wrenGetSlotBool(vm, 1);
	
	ImGui::PushButtonRepeat(repeat);
	
}

void w_PopButtonRepeat(WrenVM *vm)
{
	ImGui::PopButtonRepeat();
	
}

/*  separator, generally horizontal. inside a menu bar or in horizontal layout mode, this becomes a vertical separator. */
void w_Separator(WrenVM *vm)
{
	ImGui::Separator();
	
}

/*  call between widgets or groups to layout them horizontally. X position given in window coordinates. */
void w_SameLine(WrenVM *vm)
{
	auto offset_from_start_x = wrenExGetSlotFloatDefault(vm, 1, 0.0f);
	auto spacing = wrenExGetSlotFloatDefault(vm, 2, -1.0f);
	
	ImGui::SameLine(offset_from_start_x, spacing);
	
}

/*  undo a SameLine() or force a new line when in an horizontal-layout context. */
void w_NewLine(WrenVM *vm)
{
	ImGui::NewLine();
	
}

/*  add vertical spacing. */
void w_Spacing(WrenVM *vm)
{
	ImGui::Spacing();
	
}

// skipping w_Dummy due to unimplemented argument type: "const ImVec2&"

/*  move content position toward the right, by style.IndentSpacing or indent_w if != 0 */
void w_Indent(WrenVM *vm)
{
	auto indent_w = wrenExGetSlotFloatDefault(vm, 1, 0.0f);
	
	ImGui::Indent(indent_w);
	
}

/*  move content position back to the left, by style.IndentSpacing or indent_w if != 0 */
void w_Unindent(WrenVM *vm)
{
	auto indent_w = wrenExGetSlotFloatDefault(vm, 1, 0.0f);
	
	ImGui::Unindent(indent_w);
	
}

/*  lock horizontal starting position */
void w_BeginGroup(WrenVM *vm)
{
	ImGui::BeginGroup();
	
}

/*  unlock horizontal starting position + capture the whole group bounding box into one "item" (so you can use IsItemHovered() or layout primitives such as SameLine() on whole group, etc.) */
void w_EndGroup(WrenVM *vm)
{
	ImGui::EndGroup();
	
}

// skipping w_GetCursorPos due to unimplemented return type: "ImVec2"

/*    (some functions are using window-relative coordinates, such as: GetCursorPos, GetCursorStartPos, GetContentRegionMax, GetWindowContentRegion* etc. */
void w_GetCursorPosX(WrenVM *vm)
{
	float out = ImGui::GetCursorPosX();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*     other functions such as GetCursorScreenPos or everything in ImDrawList:: */
void w_GetCursorPosY(WrenVM *vm)
{
	float out = ImGui::GetCursorPosY();
	
	wrenSetSlotDouble(vm, 0, out);
}

// skipping w_SetCursorPos due to unimplemented argument type: "const ImVec2&"

/*     GetWindowPos() + GetCursorPos() == GetCursorScreenPos() etc.) */
void w_SetCursorPosX(WrenVM *vm)
{
	auto local_x = wrenExGetSlotFloat(vm, 1);
	
	ImGui::SetCursorPosX(local_x);
	
}

void w_SetCursorPosY(WrenVM *vm)
{
	auto local_y = wrenExGetSlotFloat(vm, 1);
	
	ImGui::SetCursorPosY(local_y);
	
}

// skipping w_GetCursorStartPos due to unimplemented return type: "ImVec2"

// skipping w_GetCursorScreenPos due to unimplemented return type: "ImVec2"

// skipping w_SetCursorScreenPos due to unimplemented argument type: "const ImVec2&"

/*  vertically align upcoming text baseline to FramePadding.y so that it will align properly to regularly framed items (call if you have text on a line before a framed item) */
void w_AlignTextToFramePadding(WrenVM *vm)
{
	ImGui::AlignTextToFramePadding();
	
}

/*  ~ FontSize */
void w_GetTextLineHeight(WrenVM *vm)
{
	float out = ImGui::GetTextLineHeight();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  ~ FontSize + style.ItemSpacing.y (distance in pixels between 2 consecutive lines of text) */
void w_GetTextLineHeightWithSpacing(WrenVM *vm)
{
	float out = ImGui::GetTextLineHeightWithSpacing();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  ~ FontSize + style.FramePadding.y * 2 */
void w_GetFrameHeight(WrenVM *vm)
{
	float out = ImGui::GetFrameHeight();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  ~ FontSize + style.FramePadding.y * 2 + style.ItemSpacing.y (distance in pixels between 2 consecutive lines of framed widgets) */
void w_GetFrameHeightWithSpacing(WrenVM *vm)
{
	float out = ImGui::GetFrameHeightWithSpacing();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  push string into the ID stack (will hash string). */
void w_PushID_Override1(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	
	ImGui::PushID(str_id);
	
}

/*  push string into the ID stack (will hash string). */
void w_PushID_Override2(WrenVM *vm)
{
	auto str_id_begin = wrenGetSlotString(vm, 1);
	auto str_id_end = wrenGetSlotString(vm, 2);
	
	ImGui::PushID(str_id_begin, str_id_end);
	
}

// skipping w_PushID_Override3 due to unimplemented argument type: "const void*"

/*  push integer into the ID stack (will hash integer). */
void w_PushID_Override4(WrenVM *vm)
{
	auto int_id = wrenExGetSlotInt(vm, 1);
	
	ImGui::PushID(int_id);
	
}

/*  pop from the ID stack. */
void w_PopID(WrenVM *vm)
{
	ImGui::PopID();
	
}

/*  calculate unique ID (hash of whole ID stack + given parameter). e.g. if you want to query into ImGuiStorage yourself */
void w_GetID_Override1(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	
	ImGuiID out = ImGui::GetID(str_id);
	
	wrenSetSlotDouble(vm, 0, out);
}

void w_GetID_Override2(WrenVM *vm)
{
	auto str_id_begin = wrenGetSlotString(vm, 1);
	auto str_id_end = wrenGetSlotString(vm, 2);
	
	ImGuiID out = ImGui::GetID(str_id_begin, str_id_end);
	
	wrenSetSlotDouble(vm, 0, out);
}

// skipping w_GetID_Override3 due to unimplemented argument type: "const void*"

/*  raw text without formatting. Roughly equivalent to Text("%s", text) but: A) doesn't require null terminated string if 'text_end' is specified, B) it's faster, no memory copy is done, no buffer size limits, recommended for long chunks of text. */
void w_TextUnformatted(WrenVM *vm)
{
	auto text = wrenGetSlotString(vm, 1);
	auto text_end = wrenExGetSlotStringDefault(vm, 2, NULL);
	
	ImGui::TextUnformatted(text, text_end);
	
}

/*  formatted text */
void w_Text(WrenVM *vm)
{
	auto fmt = wrenGetSlotString(vm, 1);
	
	ImGui::Text(fmt);
	
}

// skipping w_TextColored due to unimplemented argument type: "const ImVec4&"

/*  shortcut for PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]); Text(fmt, ...); PopStyleColor(); */
void w_TextDisabled(WrenVM *vm)
{
	auto fmt = wrenGetSlotString(vm, 1);
	
	ImGui::TextDisabled(fmt);
	
}

/*  shortcut for PushTextWrapPos(0.0f); Text(fmt, ...); PopTextWrapPos();. Note that this won't work on an auto-resizing window if there's no other widgets to extend the window width, yoy may need to set a size using SetNextWindowSize(). */
void w_TextWrapped(WrenVM *vm)
{
	auto fmt = wrenGetSlotString(vm, 1);
	
	ImGui::TextWrapped(fmt);
	
}

/*  display text+label aligned the same way as value+label widgets */
void w_LabelText(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto fmt = wrenGetSlotString(vm, 2);
	
	ImGui::LabelText(label, fmt);
	
}

/*  shortcut for Bullet()+Text() */
void w_BulletText(WrenVM *vm)
{
	auto fmt = wrenGetSlotString(vm, 1);
	
	ImGui::BulletText(fmt);
	
}

// skipping w_Button due to unimplemented argument type: "const ImVec2&"

/*  button with FramePadding=(0,0) to easily embed within text */
void w_SmallButton(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	
	bool out = ImGui::SmallButton(label);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_InvisibleButton due to unimplemented argument type: "const ImVec2&"

/*  square button with an arrow shape */
void w_ArrowButton(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	auto dir = wrenExGetSlotEnum<ImGuiDir>(getImGuiDirFromString, vm, 2);
	
	bool out = ImGui::ArrowButton(str_id, dir);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_Image due to unimplemented argument type: "ImTextureID"

// skipping w_ImageButton due to unimplemented argument type: "ImTextureID"

// skipping w_Checkbox due to unimplemented argument type: "bool*"

// skipping w_CheckboxFlags due to unimplemented argument type: "unsigned int*"

/*  use with e.g. if (RadioButton("one", my_value==1)) { my_value = 1; } */
void w_RadioButton_Override1(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto active = wrenGetSlotBool(vm, 2);
	
	bool out = ImGui::RadioButton(label, active);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_RadioButton_Override2 due to unimplemented argument type: "int*"

// skipping w_ProgressBar due to unimplemented argument type: "const ImVec2&"

/*  draw a small circle and keep the cursor on the same line. advance cursor x position by GetTreeNodeToLabelSpacing(), same distance that TreeNode() uses */
void w_Bullet(WrenVM *vm)
{
	ImGui::Bullet();
	
}

void w_BeginCombo(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto preview_value = wrenGetSlotString(vm, 2);
	auto flags = wrenExGetSlotFlagsDefault<ImGuiComboFlags>(getImGuiComboFlagsFromString, vm, 3, 0);
	
	bool out = ImGui::BeginCombo(label, preview_value, flags);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  only call EndCombo() if BeginCombo() returns true! */
void w_EndCombo(WrenVM *vm)
{
	ImGui::EndCombo();
	
}

// skipping w_Combo_Override1 due to unimplemented argument type: "int*"

// skipping w_Combo_Override2 due to unimplemented argument type: "int*"

// skipping w_Combo_Override3 due to unimplemented argument type: "int*"

// skipping w_DragFloat due to unimplemented argument type: "float*"

// skipping w_DragFloat2 due to unimplemented argument type: "float[2]"

// skipping w_DragFloat3 due to unimplemented argument type: "float[3]"

// skipping w_DragFloat4 due to unimplemented argument type: "float[4]"

// skipping w_DragFloatRange2 due to unimplemented argument type: "float*"

// skipping w_DragInt due to unimplemented argument type: "int*"

// skipping w_DragInt2 due to unimplemented argument type: "int[2]"

// skipping w_DragInt3 due to unimplemented argument type: "int[3]"

// skipping w_DragInt4 due to unimplemented argument type: "int[4]"

// skipping w_DragIntRange2 due to unimplemented argument type: "int*"

// skipping w_SliderFloat due to unimplemented argument type: "float*"

// skipping w_SliderFloat2 due to unimplemented argument type: "float[2]"

// skipping w_SliderFloat3 due to unimplemented argument type: "float[3]"

// skipping w_SliderFloat4 due to unimplemented argument type: "float[4]"

// skipping w_SliderAngle due to unimplemented argument type: "float*"

// skipping w_SliderInt due to unimplemented argument type: "int*"

// skipping w_SliderInt2 due to unimplemented argument type: "int[2]"

// skipping w_SliderInt3 due to unimplemented argument type: "int[3]"

// skipping w_SliderInt4 due to unimplemented argument type: "int[4]"

// skipping w_VSliderFloat due to unimplemented argument type: "const ImVec2&"

// skipping w_VSliderInt due to unimplemented argument type: "const ImVec2&"

// skipping w_InputText_Override1 due to unimplemented argument type: "(TODO) const buf*"

// skipping w_InputTextMultiline_Override1 due to unimplemented argument type: "(TODO) const buf*"

// skipping w_InputTextWithHint_Override1 due to unimplemented argument type: "(TODO) const buf*"

// skipping w_InputFloat due to unimplemented argument type: "float*"

// skipping w_InputFloat2 due to unimplemented argument type: "float[2]"

// skipping w_InputFloat3 due to unimplemented argument type: "float[3]"

// skipping w_InputFloat4 due to unimplemented argument type: "float[4]"

// skipping w_InputInt due to unimplemented argument type: "int*"

// skipping w_InputInt2 due to unimplemented argument type: "int[2]"

// skipping w_InputInt3 due to unimplemented argument type: "int[3]"

// skipping w_InputInt4 due to unimplemented argument type: "int[4]"

// skipping w_InputDouble due to unimplemented argument type: "double*"

// skipping w_ColorEdit3 due to unimplemented argument type: "float[3]"

// skipping w_ColorEdit4 due to unimplemented argument type: "float[4]"

// skipping w_ColorPicker3 due to unimplemented argument type: "float[3]"

// skipping w_ColorPicker4 due to unimplemented argument type: "float[4]"

// skipping w_ColorButton due to unimplemented argument type: "const ImVec4&"

/*  initialize current options (generally on application startup) if you want to select a default format, picker type, etc. User will be able to change many settings, unless you pass the _NoOptions flag to your calls. */
void w_SetColorEditOptions(WrenVM *vm)
{
	auto flags = wrenExGetSlotFlags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, vm, 1);
	
	ImGui::SetColorEditOptions(flags);
	
}

void w_TreeNode_Override1(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	
	bool out = ImGui::TreeNode(label);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  helper variation to easily decorelate the id from the displayed string. Read the FAQ about why and how to use ID. to align arbitrary text at the same level as a TreeNode() you can use Bullet(). */
void w_TreeNode_Override2(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	auto fmt = wrenGetSlotString(vm, 2);
	
	bool out = ImGui::TreeNode(str_id, fmt);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_TreeNode_Override3 due to unimplemented argument type: "const void*"

void w_TreeNodeEx_Override1(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto flags = wrenExGetSlotFlagsDefault<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, vm, 2, 0);
	
	bool out = ImGui::TreeNodeEx(label, flags);
	
	wrenSetSlotBool(vm, 0, out);
}

void w_TreeNodeEx_Override2(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	auto flags = wrenExGetSlotFlags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, vm, 2);
	auto fmt = wrenGetSlotString(vm, 3);
	
	bool out = ImGui::TreeNodeEx(str_id, flags, fmt);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_TreeNodeEx_Override3 due to unimplemented argument type: "const void*"

/*  ~ Indent()+PushId(). Already called by TreeNode() when returning true, but you can call TreePush/TreePop yourself if desired. */
void w_TreePush_Override1(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	
	ImGui::TreePush(str_id);
	
}

// skipping w_TreePush_Override2 due to unimplemented argument type: "const void*"

/*  ~ Unindent()+PopId() */
void w_TreePop(WrenVM *vm)
{
	ImGui::TreePop();
	
}

/*  horizontal distance preceding label when using TreeNode*() or Bullet() == (g.FontSize + style.FramePadding.x*2) for a regular unframed TreeNode */
void w_GetTreeNodeToLabelSpacing(WrenVM *vm)
{
	float out = ImGui::GetTreeNodeToLabelSpacing();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  if returning 'true' the header is open. doesn't indent nor push on ID stack. user doesn't have to call TreePop(). */
void w_CollapsingHeader_Override1(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto flags = wrenExGetSlotFlagsDefault<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, vm, 2, 0);
	
	bool out = ImGui::CollapsingHeader(label, flags);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_CollapsingHeader_Override2 due to unimplemented argument type: "bool*"

/*  set next TreeNode/CollapsingHeader open state. */
void w_SetNextItemOpen(WrenVM *vm)
{
	auto is_open = wrenGetSlotBool(vm, 1);
	auto cond = wrenExGetSlotEnumsDefault<ImGuiCond>(getImGuiCondFromString, vm, 2, 0);
	
	ImGui::SetNextItemOpen(is_open, cond);
	
}

// skipping w_Selectable_Override1 due to unimplemented argument type: "const ImVec2&"

// skipping w_Selectable_Override2 due to unimplemented argument type: "bool*"

// skipping w_ListBox_Override1 due to unimplemented argument type: "int*"

// skipping w_ListBox_Override2 due to unimplemented argument type: "int*"

// skipping w_ListBoxHeader_Override1 due to unimplemented argument type: "const ImVec2&"

/*  " */
void w_ListBoxHeader_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto items_count = wrenExGetSlotInt(vm, 2);
	auto height_in_items = wrenExGetSlotIntDefault(vm, 3, -1);
	
	bool out = ImGui::ListBoxHeader(label, items_count, height_in_items);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  terminate the scrolling region. only call ListBoxFooter() if ListBoxHeader() returned true! */
void w_ListBoxFooter(WrenVM *vm)
{
	ImGui::ListBoxFooter();
	
}

// skipping w_PlotLines_Override1 due to unimplemented argument type: "const float*"

// skipping w_PlotLines_Override2 due to unimplemented argument type: " float(*values_getter)(void* data, int idx)"

// skipping w_PlotHistogram_Override1 due to unimplemented argument type: "const float*"

// skipping w_PlotHistogram_Override2 due to unimplemented argument type: " float(*values_getter)(void* data, int idx)"

void w_Value_Override1(WrenVM *vm)
{
	auto prefix = wrenGetSlotString(vm, 1);
	auto b = wrenGetSlotBool(vm, 2);
	
	ImGui::Value(prefix, b);
	
}

void w_Value_Override2(WrenVM *vm)
{
	auto prefix = wrenGetSlotString(vm, 1);
	auto v = wrenExGetSlotInt(vm, 2);
	
	ImGui::Value(prefix, v);
	
}

void w_Value_Override3(WrenVM *vm)
{
	auto prefix = wrenGetSlotString(vm, 1);
	auto v = wrenExGetSlotUInt(vm, 2);
	
	ImGui::Value(prefix, v);
	
}

void w_Value_Override4(WrenVM *vm)
{
	auto prefix = wrenGetSlotString(vm, 1);
	auto v = wrenExGetSlotFloat(vm, 2);
	auto float_format = wrenExGetSlotStringDefault(vm, 3, NULL);
	
	ImGui::Value(prefix, v, float_format);
	
}

/*  append to menu-bar of current window (requires ImGuiWindowFlags_MenuBar flag set on parent window). */
void w_BeginMenuBar(WrenVM *vm)
{
	bool out = ImGui::BeginMenuBar();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  only call EndMenuBar() if BeginMenuBar() returns true! */
void w_EndMenuBar(WrenVM *vm)
{
	ImGui::EndMenuBar();
	
}

/*  create and append to a full screen menu-bar. */
void w_BeginMainMenuBar(WrenVM *vm)
{
	bool out = ImGui::BeginMainMenuBar();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  only call EndMainMenuBar() if BeginMainMenuBar() returns true! */
void w_EndMainMenuBar(WrenVM *vm)
{
	ImGui::EndMainMenuBar();
	
}

/*  create a sub-menu entry. only call EndMenu() if this returns true! */
void w_BeginMenu(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto enabled = wrenExGetSlotBoolDefault(vm, 2, true);
	
	bool out = ImGui::BeginMenu(label, enabled);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  only call EndMenu() if BeginMenu() returns true! */
void w_EndMenu(WrenVM *vm)
{
	ImGui::EndMenu();
	
}

/*  return true when activated. shortcuts are displayed for convenience but not processed by ImGui at the moment */
void w_MenuItem_Override1(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto shortcut = wrenExGetSlotStringDefault(vm, 2, NULL);
	auto selected = wrenExGetSlotBoolDefault(vm, 3, false);
	auto enabled = wrenExGetSlotBoolDefault(vm, 4, true);
	
	bool out = ImGui::MenuItem(label, shortcut, selected, enabled);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_MenuItem_Override2 due to unimplemented argument type: "bool*"

/*  begin/append a tooltip window. to create full-featured tooltip (with any kind of items). */
void w_BeginTooltip(WrenVM *vm)
{
	ImGui::BeginTooltip();
	
}

void w_EndTooltip(WrenVM *vm)
{
	ImGui::EndTooltip();
	
}

/*  set a text-only tooltip, typically use with ImGui::IsItemHovered(). override any previous call to SetTooltip(). */
void w_SetTooltip(WrenVM *vm)
{
	auto fmt = wrenGetSlotString(vm, 1);
	
	ImGui::SetTooltip(fmt);
	
}

/*  call to mark popup as open (don't call every frame!). popups are closed when user click outside, or if CloseCurrentPopup() is called within a BeginPopup()/EndPopup() block. By default, Selectable()/MenuItem() are calling CloseCurrentPopup(). Popup identifiers are relative to the current ID-stack (so OpenPopup and BeginPopup needs to be at the same level). */
void w_OpenPopup(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	
	ImGui::OpenPopup(str_id);
	
}

/*  return true if the popup is open, and you can start outputting to it. only call EndPopup() if BeginPopup() returns true! */
void w_BeginPopup(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	auto flags = wrenExGetSlotFlagsDefault<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, vm, 2, 0);
	
	bool out = ImGui::BeginPopup(str_id, flags);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  helper to open and begin popup when clicked on last item. if you can pass a NULL str_id only if the previous item had an id. If you want to use that on a non-interactive item such as Text() you need to pass in an explicit ID here. read comments in .cpp! */
void w_BeginPopupContextItem(WrenVM *vm)
{
	auto str_id = wrenExGetSlotStringDefault(vm, 1, NULL);
	auto mouse_button = wrenExGetSlotEnumsDefault<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 2, 1);
	
	bool out = ImGui::BeginPopupContextItem(str_id, mouse_button);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  helper to open and begin popup when clicked on current window. */
void w_BeginPopupContextWindow(WrenVM *vm)
{
	auto str_id = wrenExGetSlotStringDefault(vm, 1, NULL);
	auto mouse_button = wrenExGetSlotEnumsDefault<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 2, 1);
	auto also_over_items = wrenExGetSlotBoolDefault(vm, 3, true);
	
	bool out = ImGui::BeginPopupContextWindow(str_id, mouse_button, also_over_items);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  helper to open and begin popup when clicked in void (where there are no imgui windows). */
void w_BeginPopupContextVoid(WrenVM *vm)
{
	auto str_id = wrenExGetSlotStringDefault(vm, 1, NULL);
	auto mouse_button = wrenExGetSlotEnumsDefault<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 2, 1);
	
	bool out = ImGui::BeginPopupContextVoid(str_id, mouse_button);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_BeginPopupModal due to unimplemented argument type: "bool*"

/*  only call EndPopup() if BeginPopupXXX() returns true! */
void w_EndPopup(WrenVM *vm)
{
	ImGui::EndPopup();
	
}

/*  helper to open popup when clicked on last item (note: actually triggers on the mouse _released_ event to be consistent with popup behaviors). return true when just opened. */
void w_OpenPopupOnItemClick(WrenVM *vm)
{
	auto str_id = wrenExGetSlotStringDefault(vm, 1, NULL);
	auto mouse_button = wrenExGetSlotEnumsDefault<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 2, 1);
	
	bool out = ImGui::OpenPopupOnItemClick(str_id, mouse_button);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  return true if the popup is open at the current begin-ed level of the popup stack. */
void w_IsPopupOpen(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	
	bool out = ImGui::IsPopupOpen(str_id);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  close the popup we have begin-ed into. clicking on a MenuItem or Selectable automatically close the current popup. */
void w_CloseCurrentPopup(WrenVM *vm)
{
	ImGui::CloseCurrentPopup();
	
}

void w_Columns(WrenVM *vm)
{
	auto count = wrenExGetSlotIntDefault(vm, 1, 1);
	auto id = wrenExGetSlotStringDefault(vm, 2, NULL);
	auto border = wrenExGetSlotBoolDefault(vm, 3, true);
	
	ImGui::Columns(count, id, border);
	
}

/*  next column, defaults to current row or next row if the current row is finished */
void w_NextColumn(WrenVM *vm)
{
	ImGui::NextColumn();
	
}

/*  get current column index */
void w_GetColumnIndex(WrenVM *vm)
{
	int out = ImGui::GetColumnIndex();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  get column width (in pixels). pass -1 to use current column */
void w_GetColumnWidth(WrenVM *vm)
{
	auto column_index = wrenExGetSlotIntDefault(vm, 1, -1);
	
	float out = ImGui::GetColumnWidth(column_index);
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  set column width (in pixels). pass -1 to use current column */
void w_SetColumnWidth(WrenVM *vm)
{
	auto column_index = wrenExGetSlotInt(vm, 1);
	auto width = wrenExGetSlotFloat(vm, 2);
	
	ImGui::SetColumnWidth(column_index, width);
	
}

/*  get position of column line (in pixels, from the left side of the contents region). pass -1 to use current column, otherwise 0..GetColumnsCount() inclusive. column 0 is typically 0.0f */
void w_GetColumnOffset(WrenVM *vm)
{
	auto column_index = wrenExGetSlotIntDefault(vm, 1, -1);
	
	float out = ImGui::GetColumnOffset(column_index);
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  set position of column line (in pixels, from the left side of the contents region). pass -1 to use current column */
void w_SetColumnOffset(WrenVM *vm)
{
	auto column_index = wrenExGetSlotInt(vm, 1);
	auto offset_x = wrenExGetSlotFloat(vm, 2);
	
	ImGui::SetColumnOffset(column_index, offset_x);
	
}

void w_GetColumnsCount(WrenVM *vm)
{
	int out = ImGui::GetColumnsCount();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  create and append into a TabBar */
void w_BeginTabBar(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	auto flags = wrenExGetSlotFlagsDefault<ImGuiTabBarFlags>(getImGuiTabBarFlagsFromString, vm, 2, 0);
	
	bool out = ImGui::BeginTabBar(str_id, flags);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  only call EndTabBar() if BeginTabBar() returns true! */
void w_EndTabBar(WrenVM *vm)
{
	ImGui::EndTabBar();
	
}

// skipping w_BeginTabItem due to unimplemented argument type: "bool*"

/*  only call EndTabItem() if BeginTabItem() returns true! */
void w_EndTabItem(WrenVM *vm)
{
	ImGui::EndTabItem();
	
}

/*  notify TabBar or Docking system of a closed tab/window ahead (useful to reduce visual flicker on reorderable tab bars). For tab-bar: call after BeginTabBar() and before Tab submissions. Otherwise call with a window name. */
void w_SetTabItemClosed(WrenVM *vm)
{
	auto tab_or_docked_window_label = wrenGetSlotString(vm, 1);
	
	ImGui::SetTabItemClosed(tab_or_docked_window_label);
	
}

// skipping w_DockSpace due to unimplemented argument type: "const ImVec2&"

void w_DockSpaceOverViewport(WrenVM *vm)
{
	ImGuiViewport* viewport = NULL; // skipping
	auto flags = wrenExGetSlotFlagsDefault<ImGuiDockNodeFlags>(getImGuiDockNodeFlagsFromString, vm, 1, 0);
	const ImGuiWindowClass* window_class = NULL; // skipping
	
	ImGuiID out = ImGui::DockSpaceOverViewport(viewport, flags, window_class);
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  set next window dock id (FIXME-DOCK) */
void w_SetNextWindowDockID(WrenVM *vm)
{
	auto dock_id = static_cast<ImGuiID>(wrenExGetSlotInt(vm, 1));
	auto cond = wrenExGetSlotEnumsDefault<ImGuiCond>(getImGuiCondFromString, vm, 2, 0);
	
	ImGui::SetNextWindowDockID(dock_id, cond);
	
}

// skipping w_SetNextWindowClass due to unimplemented argument type: "const ImGuiWindowClass*"

void w_GetWindowDockID(WrenVM *vm)
{
	ImGuiID out = ImGui::GetWindowDockID();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  is current window docked into another window? */
void w_IsWindowDocked(WrenVM *vm)
{
	bool out = ImGui::IsWindowDocked();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  start logging to tty (stdout) */
void w_LogToTTY(WrenVM *vm)
{
	auto auto_open_depth = wrenExGetSlotIntDefault(vm, 1, -1);
	
	ImGui::LogToTTY(auto_open_depth);
	
}

/*  start logging to file */
void w_LogToFile(WrenVM *vm)
{
	auto auto_open_depth = wrenExGetSlotIntDefault(vm, 1, -1);
	auto filename = wrenExGetSlotStringDefault(vm, 2, NULL);
	
	ImGui::LogToFile(auto_open_depth, filename);
	
}

/*  start logging to OS clipboard */
void w_LogToClipboard(WrenVM *vm)
{
	auto auto_open_depth = wrenExGetSlotIntDefault(vm, 1, -1);
	
	ImGui::LogToClipboard(auto_open_depth);
	
}

/*  stop logging (close file, etc.) */
void w_LogFinish(WrenVM *vm)
{
	ImGui::LogFinish();
	
}

/*  helper to display buttons for logging to tty/file/clipboard */
void w_LogButtons(WrenVM *vm)
{
	ImGui::LogButtons();
	
}

/*  pass text data straight to log (without being displayed) */
void w_LogText(WrenVM *vm)
{
	auto fmt = wrenGetSlotString(vm, 1);
	
	ImGui::LogText(fmt);
	
}

/*  call when the current item is active. If this return true, you can call SetDragDropPayload() + EndDragDropSource() */
void w_BeginDragDropSource(WrenVM *vm)
{
	auto flags = wrenExGetSlotFlagsDefault<ImGuiDragDropFlags>(getImGuiDragDropFlagsFromString, vm, 1, 0);
	
	bool out = ImGui::BeginDragDropSource(flags);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_SetDragDropPayload due to unimplemented argument type: "(TODO) const buf*"

/*  only call EndDragDropSource() if BeginDragDropSource() returns true! */
void w_EndDragDropSource(WrenVM *vm)
{
	ImGui::EndDragDropSource();
	
}

/*  call after submitting an item that may receive a payload. If this returns true, you can call AcceptDragDropPayload() + EndDragDropTarget() */
void w_BeginDragDropTarget(WrenVM *vm)
{
	bool out = ImGui::BeginDragDropTarget();
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_AcceptDragDropPayload due to unimplemented return type: "const ImGuiPayload*"

/*  only call EndDragDropTarget() if BeginDragDropTarget() returns true! */
void w_EndDragDropTarget(WrenVM *vm)
{
	ImGui::EndDragDropTarget();
	
}

// skipping w_GetDragDropPayload due to unimplemented return type: "const ImGuiPayload*"

// skipping w_PushClipRect due to unimplemented argument type: "const ImVec2&"

void w_PopClipRect(WrenVM *vm)
{
	ImGui::PopClipRect();
	
}

/*  make last item the default focused item of a window. */
void w_SetItemDefaultFocus(WrenVM *vm)
{
	ImGui::SetItemDefaultFocus();
	
}

/*  focus keyboard on the next widget. Use positive 'offset' to access sub components of a multiple component widget. Use -1 to access previous widget. */
void w_SetKeyboardFocusHere(WrenVM *vm)
{
	auto offset = wrenExGetSlotIntDefault(vm, 1, 0);
	
	ImGui::SetKeyboardFocusHere(offset);
	
}

/*  is the last item hovered? (and usable, aka not blocked by a popup, etc.). See ImGuiHoveredFlags for more options. */
void w_IsItemHovered(WrenVM *vm)
{
	auto flags = wrenExGetSlotFlagsDefault<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, vm, 1, 0);
	
	bool out = ImGui::IsItemHovered(flags);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is the last item active? (e.g. button being held, text field being edited. This will continuously return true while holding mouse button on an item. Items that don't interact will always return false) */
void w_IsItemActive(WrenVM *vm)
{
	bool out = ImGui::IsItemActive();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is the last item focused for keyboard/gamepad navigation? */
void w_IsItemFocused(WrenVM *vm)
{
	bool out = ImGui::IsItemFocused();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is the last item clicked? (e.g. button/node just clicked on) == IsMouseClicked(mouse_button) && IsItemHovered() */
void w_IsItemClicked(WrenVM *vm)
{
	auto mouse_button = wrenExGetSlotEnumsDefault<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1, 0);
	
	bool out = ImGui::IsItemClicked(mouse_button);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is the last item visible? (items may be out of sight because of clipping/scrolling) */
void w_IsItemVisible(WrenVM *vm)
{
	bool out = ImGui::IsItemVisible();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  did the last item modify its underlying value this frame? or was pressed? This is generally the same as the "bool" return value of many widgets. */
void w_IsItemEdited(WrenVM *vm)
{
	bool out = ImGui::IsItemEdited();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  was the last item just made active (item was previously inactive). */
void w_IsItemActivated(WrenVM *vm)
{
	bool out = ImGui::IsItemActivated();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  was the last item just made inactive (item was previously active). Useful for Undo/Redo patterns with widgets that requires continuous editing. */
void w_IsItemDeactivated(WrenVM *vm)
{
	bool out = ImGui::IsItemDeactivated();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  was the last item just made inactive and made a value change when it was active? (e.g. Slider/Drag moved). Useful for Undo/Redo patterns with widgets that requires continuous editing. Note that you may get false positives (some widgets such as Combo()/ListBox()/Selectable() will return true even when clicking an already selected item). */
void w_IsItemDeactivatedAfterEdit(WrenVM *vm)
{
	bool out = ImGui::IsItemDeactivatedAfterEdit();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  was the last item open state toggled? set by TreeNode(). */
void w_IsItemToggledOpen(WrenVM *vm)
{
	bool out = ImGui::IsItemToggledOpen();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is any item hovered? */
void w_IsAnyItemHovered(WrenVM *vm)
{
	bool out = ImGui::IsAnyItemHovered();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is any item active? */
void w_IsAnyItemActive(WrenVM *vm)
{
	bool out = ImGui::IsAnyItemActive();
	
	wrenSetSlotBool(vm, 0, out);
}

/*  is any item focused? */
void w_IsAnyItemFocused(WrenVM *vm)
{
	bool out = ImGui::IsAnyItemFocused();
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_GetItemRectMin due to unimplemented return type: "ImVec2"

// skipping w_GetItemRectMax due to unimplemented return type: "ImVec2"

// skipping w_GetItemRectSize due to unimplemented return type: "ImVec2"

/*  allow last item to be overlapped by a subsequent item. sometimes useful with invisible buttons, selectables, etc. to catch unused area. */
void w_SetItemAllowOverlap(WrenVM *vm)
{
	ImGui::SetItemAllowOverlap();
	
}

// skipping w_IsRectVisible_Override1 due to unimplemented argument type: "const ImVec2&"

// skipping w_IsRectVisible_Override2 due to unimplemented argument type: "const ImVec2&"

/*  get global imgui time. incremented by io.DeltaTime every frame. */
void w_GetTime(WrenVM *vm)
{
	double out = ImGui::GetTime();
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  get global imgui frame count. incremented by 1 every frame. */
void w_GetFrameCount(WrenVM *vm)
{
	int out = ImGui::GetFrameCount();
	
	wrenSetSlotDouble(vm, 0, out);
}

// skipping w_GetBackgroundDrawList_Override1 due to unimplemented return type: "ImDrawList*"

// skipping w_GetForegroundDrawList_Override1 due to unimplemented return type: "ImDrawList*"

// skipping w_GetBackgroundDrawList_Override2 due to unimplemented argument type: "ImGuiViewport*"

// skipping w_GetForegroundDrawList_Override2 due to unimplemented argument type: "ImGuiViewport*"

// skipping w_GetDrawListSharedData due to unimplemented return type: "ImDrawListSharedData*"

/*  get a string corresponding to the enum value (for display, saving, etc.). */
void w_GetStyleColorName(WrenVM *vm)
{
	auto idx = wrenExGetSlotEnum<ImGuiCol>(getImGuiColFromString, vm, 1);
	
	const char* out = ImGui::GetStyleColorName(idx);
	
	wrenSetSlotString(vm, 0, out);
}

// skipping w_SetStateStorage due to unimplemented argument type: "ImGuiStorage*"

// skipping w_GetStateStorage due to unimplemented return type: "ImGuiStorage*"

// skipping w_CalcTextSize due to unimplemented return type: "ImVec2"

// skipping w_CalcListClipping due to unimplemented argument type: "int*"

// skipping w_BeginChildFrame due to unimplemented argument type: "const ImVec2&"

/*  always call EndChildFrame() regardless of BeginChildFrame() return values (which indicates a collapsed/clipped window) */
void w_EndChildFrame(WrenVM *vm)
{
	ImGui::EndChildFrame();
	
}

// skipping w_ColorConvertU32ToFloat4 due to unimplemented return type: "ImVec4"

/*  map ImGuiKey_* values into user's key index. == io.KeyMap[key] */
void w_GetKeyIndex(WrenVM *vm)
{
	auto imgui_key = wrenExGetSlotEnum<ImGuiKey>(getImGuiKeyFromString, vm, 1);
	
	int out = ImGui::GetKeyIndex(imgui_key);
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  is key being held. == io.KeysDown[user_key_index]. */
void w_IsKeyDown(WrenVM *vm)
{
	auto user_key_index = wrenExGetSlotInt(vm, 1);
	
	bool out = ImGui::IsKeyDown(user_key_index);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  was key pressed (went from !Down to Down)? if repeat=true, uses io.KeyRepeatDelay / KeyRepeatRate */
void w_IsKeyPressed(WrenVM *vm)
{
	auto user_key_index = wrenExGetSlotInt(vm, 1);
	auto repeat = wrenExGetSlotBoolDefault(vm, 2, true);
	
	bool out = ImGui::IsKeyPressed(user_key_index, repeat);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  was key released (went from Down to !Down)? */
void w_IsKeyReleased(WrenVM *vm)
{
	auto user_key_index = wrenExGetSlotInt(vm, 1);
	
	bool out = ImGui::IsKeyReleased(user_key_index);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  uses provided repeat rate/delay. return a count, most often 0 or 1 but might be >1 if RepeatRate is small enough that DeltaTime > RepeatRate */
void w_GetKeyPressedAmount(WrenVM *vm)
{
	auto key_index = wrenExGetSlotInt(vm, 1);
	auto repeat_delay = wrenExGetSlotFloat(vm, 2);
	auto rate = wrenExGetSlotFloat(vm, 3);
	
	int out = ImGui::GetKeyPressedAmount(key_index, repeat_delay, rate);
	
	wrenSetSlotDouble(vm, 0, out);
}

/*  attention: misleading name! manually override io.WantCaptureKeyboard flag next frame (said flag is entirely left for your application to handle). e.g. force capture keyboard when your widget is being hovered. This is equivalent to setting "io.WantCaptureKeyboard = want_capture_keyboard_value"; after the next NewFrame() call. */
void w_CaptureKeyboardFromApp(WrenVM *vm)
{
	auto want_capture_keyboard_value = wrenExGetSlotBoolDefault(vm, 1, true);
	
	ImGui::CaptureKeyboardFromApp(want_capture_keyboard_value);
	
}

/*  is mouse button held? */
void w_IsMouseDown(WrenVM *vm)
{
	auto button = wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	
	bool out = ImGui::IsMouseDown(button);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  did mouse button clicked? (went from !Down to Down) */
void w_IsMouseClicked(WrenVM *vm)
{
	auto button = wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	auto repeat = wrenExGetSlotBoolDefault(vm, 2, false);
	
	bool out = ImGui::IsMouseClicked(button, repeat);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  did mouse button released? (went from Down to !Down) */
void w_IsMouseReleased(WrenVM *vm)
{
	auto button = wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	
	bool out = ImGui::IsMouseReleased(button);
	
	wrenSetSlotBool(vm, 0, out);
}

/*  did mouse button double-clicked? a double-click returns false in IsMouseClicked(). uses io.MouseDoubleClickTime. */
void w_IsMouseDoubleClicked(WrenVM *vm)
{
	auto button = wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	
	bool out = ImGui::IsMouseDoubleClicked(button);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_IsMouseHoveringRect due to unimplemented argument type: "const ImVec2&"

// skipping w_IsMousePosValid due to unimplemented argument type: "const ImVec2*"

/*  is any mouse button held? */
void w_IsAnyMouseDown(WrenVM *vm)
{
	bool out = ImGui::IsAnyMouseDown();
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_GetMousePos due to unimplemented return type: "ImVec2"

// skipping w_GetMousePosOnOpeningCurrentPopup due to unimplemented return type: "ImVec2"

/*  is mouse dragging? (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold) */
void w_IsMouseDragging(WrenVM *vm)
{
	auto button = wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	auto lock_threshold = wrenExGetSlotFloatDefault(vm, 2, -1.0f);
	
	bool out = ImGui::IsMouseDragging(button, lock_threshold);
	
	wrenSetSlotBool(vm, 0, out);
}

// skipping w_GetMouseDragDelta due to unimplemented return type: "ImVec2"

void w_ResetMouseDragDelta(WrenVM *vm)
{
	auto button = wrenExGetSlotEnumsDefault<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1, 0);
	
	ImGui::ResetMouseDragDelta(button);
	
}

/*  get desired cursor type, reset in ImGui::NewFrame(), this is updated during the frame. valid before Render(). If you use software rendering by setting io.MouseDrawCursor ImGui will render those for you */
void w_GetMouseCursor(WrenVM *vm)
{
	ImGuiMouseCursor out = ImGui::GetMouseCursor();
	
	wrenSetSlotString(vm, 0, getStringFromImGuiMouseCursor(out));
}

/*  set desired cursor type */
void w_SetMouseCursor(WrenVM *vm)
{
	auto cursor_type = wrenExGetSlotEnum<ImGuiMouseCursor>(getImGuiMouseCursorFromString, vm, 1);
	
	ImGui::SetMouseCursor(cursor_type);
	
}

/*  attention: misleading name! manually override io.WantCaptureMouse flag next frame (said flag is entirely left for your application to handle). This is equivalent to setting "io.WantCaptureMouse = want_capture_mouse_value;" after the next NewFrame() call. */
void w_CaptureMouseFromApp(WrenVM *vm)
{
	auto want_capture_mouse_value = wrenExGetSlotBoolDefault(vm, 1, true);
	
	ImGui::CaptureMouseFromApp(want_capture_mouse_value);
	
}

void w_GetClipboardText(WrenVM *vm)
{
	const char* out = ImGui::GetClipboardText();
	
	wrenSetSlotString(vm, 0, out);
}

void w_SetClipboardText(WrenVM *vm)
{
	auto text = wrenGetSlotString(vm, 1);
	
	ImGui::SetClipboardText(text);
	
}

/*  call after CreateContext() and before the first call to NewFrame(). NewFrame() automatically calls LoadIniSettingsFromDisk(io.IniFilename). */
void w_LoadIniSettingsFromDisk(WrenVM *vm)
{
	auto ini_filename = wrenGetSlotString(vm, 1);
	
	ImGui::LoadIniSettingsFromDisk(ini_filename);
	
}

// skipping w_LoadIniSettingsFromMemory due to unimplemented argument type: "(TODO) const buf*"

/*  this is automatically called (if io.IniFilename is not empty) a few seconds after any modification that should be reflected in the .ini file (and also by DestroyContext). */
void w_SaveIniSettingsToDisk(WrenVM *vm)
{
	auto ini_filename = wrenGetSlotString(vm, 1);
	
	ImGui::SaveIniSettingsToDisk(ini_filename);
	
}

// skipping w_SaveIniSettingsToMemory due to unimplemented argument type: "size_t*"

// skipping w_GetPlatformIO due to unimplemented return type: "ImGuiPlatformIO&"

// skipping w_GetMainViewport due to unimplemented return type: "ImGuiViewport*"

/*  call in main loop. will call CreateWindow/ResizeWindow/etc. platform functions for each secondary viewport, and DestroyWindow for each inactive viewport. */
void w_UpdatePlatformWindows(WrenVM *vm)
{
	ImGui::UpdatePlatformWindows();
	
}

// skipping w_RenderPlatformWindowsDefault due to unimplemented argument type: "void*"

/*  call DestroyWindow platform functions for all viewports. call from back-end Shutdown() if you need to close platform windows before imgui shutdown. otherwise will be called by DestroyContext(). */
void w_DestroyPlatformWindows(WrenVM *vm)
{
	ImGui::DestroyPlatformWindows();
	
}

// skipping w_FindViewportByID due to unimplemented return type: "ImGuiViewport*"

// skipping w_FindViewportByPlatformHandle due to unimplemented argument type: "void*"

// skipping w_InputText_Override2 due to unimplemented argument type: "std::string*"

// skipping w_InputTextMultiline_Override2 due to unimplemented argument type: "std::string*"

// skipping w_InputTextWithHint_Override2 due to unimplemented argument type: "std::string*"

// skipping w_Combo_Override4 due to unimplemented argument type: "int*"

// skipping w_ListBox_Override3 due to unimplemented argument type: "int*"

// skipping w_PlotLines_Override3 due to unimplemented argument type: "const std::vector<float>&"

// skipping w_PlotHistogram_Override3 due to unimplemented argument type: "const std::vector<float>&"

// skipping w_ImDrawList_PushClipRect due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PushClipRectFullScreen due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PopClipRect due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PushTextureID due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PopTextureID due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddLine due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddRect due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddRectFilled due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddRectFilledMultiColor due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddQuad due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddQuadFilled due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddTriangle due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddTriangleFilled due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddCircle due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddCircleFilled due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddNgon due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddNgonFilled due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddText_Override1 due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddText_Override2 due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddPolyline due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddConvexPolyFilled due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddBezierCurve due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddImage due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddImageQuad due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddImageRounded due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PathArcTo due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PathArcToFast due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PathBezierCurveTo due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PathRect due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddCallback due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_AddDrawCmd due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_CloneOutput due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_Clear due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_ClearFreeMemory due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PrimReserve due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PrimUnreserve due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PrimRect due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_UpdateClipRect due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_UpdateTextureID due to unimplemented foreign class type: "ImDrawList"

// End Functions }}}

const std::unordered_map<const char*, WrenForeignMethodFn> foreignMethods = {};
/*
{"SetColumnOffset", w_SetColumnOffset},
{"IsItemDeactivatedAfterEdit", w_IsItemDeactivatedAfterEdit},
{"IsMouseDoubleClicked", w_IsMouseDoubleClicked},
{"GetTreeNodeToLabelSpacing", w_GetTreeNodeToLabelSpacing},
{"SetNextItemOpen", w_SetNextItemOpen},
{"PopTextWrapPos", w_PopTextWrapPos},
{"EndDragDropSource", w_EndDragDropSource},
{"GetWindowWidth", w_GetWindowWidth},
{"SetNextWindowCollapsed", w_SetNextWindowCollapsed},
{"TextWrapped", w_TextWrapped},
{"ListBoxHeader", w_ListBoxHeader},
{"GetID", w_GetID},
{"BeginCombo", w_BeginCombo},
{"SmallButton", w_SmallButton},
{"IsMouseClicked", w_IsMouseClicked},
{"PushStyleVar", w_PushStyleVar},
{"SetItemAllowOverlap", w_SetItemAllowOverlap},
{"IsMouseDown", w_IsMouseDown},
{"TreeNodeEx", w_TreeNodeEx},
{"ShowFontSelector", w_ShowFontSelector},
{"GetCursorPosX", w_GetCursorPosX},
{"PushAllowKeyboardFocus", w_PushAllowKeyboardFocus},
{"PopStyleVar", w_PopStyleVar},
{"SetScrollHereY", w_SetScrollHereY},
{"IsKeyReleased", w_IsKeyReleased},
{"IsMouseDragging", w_IsMouseDragging},
{"IsKeyDown", w_IsKeyDown},
{"GetColumnIndex", w_GetColumnIndex},
{"GetColumnOffset", w_GetColumnOffset},
{"IsKeyPressed", w_IsKeyPressed},
{"GetFontSize", w_GetFontSize},
{"SameLine", w_SameLine},
{"BeginTooltip", w_BeginTooltip},
{"BeginMenu", w_BeginMenu},
{"ShowUserGuide", w_ShowUserGuide},
{"DockSpaceOverViewport", w_DockSpaceOverViewport},
{"SetKeyboardFocusHere", w_SetKeyboardFocusHere},
{"UpdatePlatformWindows", w_UpdatePlatformWindows},
{"IsWindowHovered", w_IsWindowHovered},
{"PopFont", w_PopFont},
{"TreePush", w_TreePush},
{"GetTextLineHeightWithSpacing", w_GetTextLineHeightWithSpacing},
{"BeginTabBar", w_BeginTabBar},
{"SetTabItemClosed", w_SetTabItemClosed},
{"RadioButton", w_RadioButton},
{"IsItemEdited", w_IsItemEdited},
{"GetClipboardText", w_GetClipboardText},
{"ListBoxFooter", w_ListBoxFooter},
{"GetVersion", w_GetVersion},
{"BeginMainMenuBar", w_BeginMainMenuBar},
{"PushStyleColor", w_PushStyleColor},
{"EndMenuBar", w_EndMenuBar},
{"GetFrameHeight", w_GetFrameHeight},
{"SetNextWindowFocus", w_SetNextWindowFocus},
{"GetScrollY", w_GetScrollY},
{"BeginMenuBar", w_BeginMenuBar},
{"IsWindowDocked", w_IsWindowDocked},
{"CollapsingHeader", w_CollapsingHeader},
{"LogToTTY", w_LogToTTY},
{"NextColumn", w_NextColumn},
{"EndFrame", w_EndFrame},
{"GetWindowHeight", w_GetWindowHeight},
{"IsWindowAppearing", w_IsWindowAppearing},
{"EndCombo", w_EndCombo},
{"AlignTextToFramePadding", w_AlignTextToFramePadding},
{"CloseCurrentPopup", w_CloseCurrentPopup},
{"LogToFile", w_LogToFile},
{"CaptureKeyboardFromApp", w_CaptureKeyboardFromApp},
{"BeginDragDropSource", w_BeginDragDropSource},
{"GetCursorPosY", w_GetCursorPosY},
{"SetCursorPosX", w_SetCursorPosX},
{"GetScrollMaxX", w_GetScrollMaxX},
{"SetNextWindowDockID", w_SetNextWindowDockID},
{"IsAnyItemHovered", w_IsAnyItemHovered},
{"Unindent", w_Unindent},
{"SetColumnWidth", w_SetColumnWidth},
{"Indent", w_Indent},
{"IsItemFocused", w_IsItemFocused},
{"PopButtonRepeat", w_PopButtonRepeat},
{"LoadIniSettingsFromDisk", w_LoadIniSettingsFromDisk},
{"PopAllowKeyboardFocus", w_PopAllowKeyboardFocus},
{"SetScrollFromPosX", w_SetScrollFromPosX},
{"ResetMouseDragDelta", w_ResetMouseDragDelta},
{"SetWindowFontScale", w_SetWindowFontScale},
{"SetClipboardText", w_SetClipboardText},
{"SetNextWindowBgAlpha", w_SetNextWindowBgAlpha},
{"ShowStyleSelector", w_ShowStyleSelector},
{"IsAnyItemFocused", w_IsAnyItemFocused},
{"EndMenu", w_EndMenu},
{"SetWindowFocus", w_SetWindowFocus},
{"SetItemDefaultFocus", w_SetItemDefaultFocus},
{"Separator", w_Separator},
{"IsAnyMouseDown", w_IsAnyMouseDown},
{"LogToClipboard", w_LogToClipboard},
{"IsWindowCollapsed", w_IsWindowCollapsed},
{"IsMouseReleased", w_IsMouseReleased},
{"GetKeyPressedAmount", w_GetKeyPressedAmount},
{"IsItemActive", w_IsItemActive},
{"Spacing", w_Spacing},
{"GetKeyIndex", w_GetKeyIndex},
{"NewLine", w_NewLine},
{"EndChildFrame", w_EndChildFrame},
{"GetStyleColorName", w_GetStyleColorName},
{"PushButtonRepeat", w_PushButtonRepeat},
{"SetScrollX", w_SetScrollX},
{"CalcItemWidth", w_CalcItemWidth},
{"GetTime", w_GetTime},
{"OpenPopupOnItemClick", w_OpenPopupOnItemClick},
{"CaptureMouseFromApp", w_CaptureMouseFromApp},
{"IsAnyItemActive", w_IsAnyItemActive},
{"DestroyPlatformWindows", w_DestroyPlatformWindows},
{"LogFinish", w_LogFinish},
{"IsItemDeactivated", w_IsItemDeactivated},
{"IsItemActivated", w_IsItemActivated},
{"Bullet", w_Bullet},
{"EndTooltip", w_EndTooltip},
{"IsItemVisible", w_IsItemVisible},
{"IsItemClicked", w_IsItemClicked},
{"IsItemHovered", w_IsItemHovered},
{"BeginPopup", w_BeginPopup},
{"GetColumnWidth", w_GetColumnWidth},
{"PopStyleColor", w_PopStyleColor},
{"GetFrameCount", w_GetFrameCount},
{"GetWindowDpiScale", w_GetWindowDpiScale},
{"PushID", w_PushID},
{"GetScrollMaxY", w_GetScrollMaxY},
{"GetColumnsCount", w_GetColumnsCount},
{"IsPopupOpen", w_IsPopupOpen},
{"SaveIniSettingsToDisk", w_SaveIniSettingsToDisk},
{"SetWindowCollapsed", w_SetWindowCollapsed},
{"BeginPopupContextItem", w_BeginPopupContextItem},
{"BeginDragDropTarget", w_BeginDragDropTarget},
{"PushItemWidth", w_PushItemWidth},
{"LogButtons", w_LogButtons},
{"IsItemToggledOpen", w_IsItemToggledOpen},
{"SetCursorPosY", w_SetCursorPosY},
{"IsWindowFocused", w_IsWindowFocused},
{"GetFrameHeightWithSpacing", w_GetFrameHeightWithSpacing},
{"LogText", w_LogText},
{"SetScrollFromPosY", w_SetScrollFromPosY},
{"GetScrollX", w_GetScrollX},
{"End", w_End},
{"TreePop", w_TreePop},
{"MenuItem", w_MenuItem},
{"PushTextWrapPos", w_PushTextWrapPos},
{"SetScrollY", w_SetScrollY},
{"ArrowButton", w_ArrowButton},
{"BeginPopupContextVoid", w_BeginPopupContextVoid},
{"LabelText", w_LabelText},
{"GetWindowDockID", w_GetWindowDockID},
{"SetScrollHereX", w_SetScrollHereX},
{"GetWindowContentRegionWidth", w_GetWindowContentRegionWidth},
{"NewFrame", w_NewFrame},
{"SetColorEditOptions", w_SetColorEditOptions},
{"GetMouseCursor", w_GetMouseCursor},
{"PopID", w_PopID},
{"TextDisabled", w_TextDisabled},
{"BulletText", w_BulletText},
{"BeginGroup", w_BeginGroup},
{"EndTabItem", w_EndTabItem},
{"Value", w_Value},
{"GetTextLineHeight", w_GetTextLineHeight},
{"TreeNode", w_TreeNode},
{"OpenPopup", w_OpenPopup},
{"EndGroup", w_EndGroup},
{"SetNextItemWidth", w_SetNextItemWidth},
{"SetMouseCursor", w_SetMouseCursor},
{"EndTabBar", w_EndTabBar},
{"EndMainMenuBar", w_EndMainMenuBar},
{"TextUnformatted", w_TextUnformatted},
{"SetNextWindowViewport", w_SetNextWindowViewport},
{"Render", w_Render},
{"SetTooltip", w_SetTooltip},
{"PopClipRect", w_PopClipRect},
{"BeginPopupContextWindow", w_BeginPopupContextWindow},
{"EndChild", w_EndChild},
{"Columns", w_Columns},
{"PopItemWidth", w_PopItemWidth},
{"EndPopup", w_EndPopup},
{"EndDragDropTarget", w_EndDragDropTarget},
{"Text", w_Text},

};
*/

const char* foreignModuleString = R"MODULE(
my code goes here ;)
)MODULE";

}

const char* wrap_imgui::loadModule(WrenVM* vm)
{
	return foreignModuleString;
}

WrenForeignClassMethods wrap_imgui::bindForeignClass(WrenVM* vm, const char* className)
{
	return nullptr;
}

WrenForeignMethodFn wrap_imgui::bindForeignMethod(WrenVM* vm, const char* className, bool isStatic, const char* signature)
{
  auto pair = foreignMethods.find(signature);

  if(pair != foreignMethods.end()) {
	  return pair->second;
  }
  return nulltpr;
}
