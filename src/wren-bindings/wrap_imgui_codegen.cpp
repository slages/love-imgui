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
#include <variant>
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

std::optional<ImGuiKeyModFlags_> getImGuiKeyModFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiKeyModFlags_None; }
	if (strcmp(in, "Shift") == 0) { return ImGuiKeyModFlags_Shift; }
	if (strcmp(in, "Super") == 0) { return ImGuiKeyModFlags_Super; }
	if (strcmp(in, "Ctrl") == 0) { return ImGuiKeyModFlags_Ctrl; }
	if (strcmp(in, "Alt") == 0) { return ImGuiKeyModFlags_Alt; }
	return std::nullopt;
}
const char* getStringFromImGuiKeyModFlags(ImGuiKeyModFlags in)
{
	switch (in) {
		case 0: return "None";
		case 1 << 1: return "Shift";
		case 1 << 3: return "Super";
		case 1 << 0: return "Ctrl";
		case 1 << 2: return "Alt";
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
	if (strcmp(in, "_InputMask") == 0) { return ImGuiColorEditFlags__InputMask; }
	if (strcmp(in, "NoLabel") == 0) { return ImGuiColorEditFlags_NoLabel; }
	if (strcmp(in, "_PickerMask") == 0) { return ImGuiColorEditFlags__PickerMask; }
	if (strcmp(in, "_DisplayMask") == 0) { return ImGuiColorEditFlags__DisplayMask; }
	if (strcmp(in, "AlphaPreviewHalf") == 0) { return ImGuiColorEditFlags_AlphaPreviewHalf; }
	if (strcmp(in, "NoOptions") == 0) { return ImGuiColorEditFlags_NoOptions; }
	if (strcmp(in, "NoAlpha") == 0) { return ImGuiColorEditFlags_NoAlpha; }
	if (strcmp(in, "NoPicker") == 0) { return ImGuiColorEditFlags_NoPicker; }
	if (strcmp(in, "DisplayHSV") == 0) { return ImGuiColorEditFlags_DisplayHSV; }
	if (strcmp(in, "HDR") == 0) { return ImGuiColorEditFlags_HDR; }
	if (strcmp(in, "Float") == 0) { return ImGuiColorEditFlags_Float; }
	if (strcmp(in, "NoSidePreview") == 0) { return ImGuiColorEditFlags_NoSidePreview; }
	if (strcmp(in, "AlphaPreview") == 0) { return ImGuiColorEditFlags_AlphaPreview; }
	if (strcmp(in, "PickerHueWheel") == 0) { return ImGuiColorEditFlags_PickerHueWheel; }
	if (strcmp(in, "AlphaBar") == 0) { return ImGuiColorEditFlags_AlphaBar; }
	if (strcmp(in, "NoInputs") == 0) { return ImGuiColorEditFlags_NoInputs; }
	if (strcmp(in, "Uint8") == 0) { return ImGuiColorEditFlags_Uint8; }
	if (strcmp(in, "InputHSV") == 0) { return ImGuiColorEditFlags_InputHSV; }
	if (strcmp(in, "NoSmallPreview") == 0) { return ImGuiColorEditFlags_NoSmallPreview; }
	if (strcmp(in, "PickerHueBar") == 0) { return ImGuiColorEditFlags_PickerHueBar; }
	if (strcmp(in, "NoBorder") == 0) { return ImGuiColorEditFlags_NoBorder; }
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
		// skipping // case ImGuiColorEditFlags_InputRGB|ImGuiColorEditFlags_InputHSV: return "_InputMask";
		case 1 << 7: return "NoLabel";
		// skipping // case ImGuiColorEditFlags_PickerHueWheel|ImGuiColorEditFlags_PickerHueBar: return "_PickerMask";
		// skipping // case ImGuiColorEditFlags_DisplayRGB|ImGuiColorEditFlags_DisplayHSV|ImGuiColorEditFlags_DisplayHex: return "_DisplayMask";
		case 1 << 18: return "AlphaPreviewHalf";
		case 1 << 3: return "NoOptions";
		case 1 << 1: return "NoAlpha";
		case 1 << 2: return "NoPicker";
		case 1 << 21: return "DisplayHSV";
		case 1 << 19: return "HDR";
		case 1 << 24: return "Float";
		case 1 << 8: return "NoSidePreview";
		case 1 << 17: return "AlphaPreview";
		case 1 << 26: return "PickerHueWheel";
		case 1 << 16: return "AlphaBar";
		case 1 << 5: return "NoInputs";
		case 1 << 23: return "Uint8";
		case 1 << 28: return "InputHSV";
		case 1 << 4: return "NoSmallPreview";
		case 1 << 25: return "PickerHueBar";
		case 1 << 10: return "NoBorder";
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

using WrenNull = std::monostate;

void wrenExSetSlot(WrenVM* vm, int slotIdx, WrenNull v)
{
	(void)v;
	wrenSetSlotNull(vm, slotIdx);
}

void wrenExSetSlot(WrenVM* vm, int slotIdx, bool v)
{
	wrenSetSlotBool(vm, slotIdx, v);
}

void wrenExSetSlot(WrenVM* vm, int slotIdx, double v)
{
	wrenSetSlotDouble(vm, slotIdx, v);
}

void wrenExSetSlot(WrenVM* vm, int slotIdx, const std::string& v)
{
	wrenSetSlotString(vm, slotIdx, v.c_str());
}

const char* wrenExGetSlotTypeString(WrenVM* vm, int slotIdx)
{
	switch(wrenGetSlotType(vm, slotIdx))
	{
	case WREN_TYPE_BOOL: return "bool";
	case WREN_TYPE_NUM: return "number";
	case WREN_TYPE_FOREIGN: return "foreign object";
	case WREN_TYPE_LIST: return "list";
	case WREN_TYPE_NULL: return "null";
	case WREN_TYPE_STRING: return "string";
	case WREN_TYPE_UNKNOWN: return "unknown";
	}
	return "unknown";
}

template<typename T>
T wrenExGetSlot(WrenVM* vm, int slotIdx);

template<>
bool wrenExGetSlot<bool>(WrenVM* vm, int slotIdx)
{
	if (wrenGetSlotType(vm, slotIdx) != WREN_TYPE_BOOL) {
		wrenExAbortf(vm, "Expected bool as argument %d, received %s", slotIdx, wrenExGetSlotTypeString(vm, slotIdx));
	}

	return wrenGetSlotBool(vm, slotIdx);
}

template<>
double wrenExGetSlot<double>(WrenVM* vm, int slotIdx)
{
	if (wrenGetSlotType(vm, slotIdx) != WREN_TYPE_NUM) {
		wrenExAbortf(vm, "Expected double as argument %d, received %s", slotIdx, wrenExGetSlotTypeString(vm, slotIdx));
	}

	return wrenGetSlotDouble(vm, slotIdx);
}

template<>
float wrenExGetSlot<float>(WrenVM* vm, int slotIdx)
{
	if (wrenGetSlotType(vm, slotIdx) != WREN_TYPE_NUM) {
		wrenExAbortf(vm, "Expected float as argument %d, received %s", slotIdx, wrenExGetSlotTypeString(vm, slotIdx));
	}

	return static_cast<float>(wrenGetSlotDouble(vm, slotIdx));
}

template<>
int wrenExGetSlot<int>(WrenVM* vm, int slotIdx)
{
	if (wrenGetSlotType(vm, slotIdx) != WREN_TYPE_NUM) {
		wrenExAbortf(vm, "Expected int as argument %d, received %s", slotIdx, wrenExGetSlotTypeString(vm, slotIdx));
	}

	return static_cast<int>(wrenGetSlotDouble(vm, slotIdx));
}

template<>
unsigned int wrenExGetSlot<unsigned int>(WrenVM* vm, int slotIdx)
{
	if (wrenGetSlotType(vm, slotIdx) != WREN_TYPE_NUM) {
		wrenExAbortf(vm, "Expected unsigned int as argument %d, received %s", slotIdx, wrenExGetSlotTypeString(vm, slotIdx));
	}

	return static_cast<unsigned int>(wrenGetSlotDouble(vm, slotIdx));
}

template<>
std::string wrenExGetSlot<std::string>(WrenVM* vm, int slotIdx)
{
	if (wrenGetSlotType(vm, slotIdx) != WREN_TYPE_STRING) {
		wrenExAbortf(vm, "Expected bool as argument %d, received %s", slotIdx, wrenExGetSlotTypeString(vm, slotIdx));
	}

	return std::string(wrenGetSlotString(vm, slotIdx));
}

bool wrenExIsSlotDefault(WrenVM* vm, int slotIdx)
{
	if(wrenGetSlotCount(vm) <= slotIdx) {
		return true;
	}

	if (wrenGetSlotType(vm, slotIdx) == WREN_TYPE_NULL) {
		return true;
	}

	return false;
}

template<typename T, typename U>
T wrenExGetSlotEnum(U fromString, WrenVM* vm, int slotIdx)
{
	std::string s = wrenExGetSlot<std::string>(vm, slotIdx);
	std::optional<T> opt = fromString(s.c_str());
	if(!opt) {
		wrenExAbortf(vm, "Invalid enum as argument %d, received \"%s\"", slotIdx, s.c_str());
	}
	return *opt;
}

template<typename T, typename U>
T wrenExGetSlotFlags(U fromString, WrenVM* vm, int slotIdx)
{
	T out{};
	WrenType type = wrenGetSlotType(vm, slotIdx);
	if (type == WREN_TYPE_NUM) {
		// variant A: raw number
		out = static_cast<T>(wrenExGetSlot<int>(vm, slotIdx));
	} else if (type == WREN_TYPE_STRING) {
		// variant B: string, split by '|'
		const char* s = wrenGetSlotString(vm, slotIdx);
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);
		while (std::getline(tokenStream, token, '|')) {
			std::optional<T> opt = fromString(token.c_str());
			if (!opt) {
				wrenExAbortf(vm, "Unrecognized value in flags parameter %d: %s", slotIdx, token.c_str());
			}
			out = out | *opt;
		}
	} else {
		wrenExAbortf(vm, "Unrecognized flag parameter %d: must be int, string, or table", slotIdx);
	}

	return out;
}

template<typename T, typename U>
T wrenExGetSlotFlagsDefault(U fromString, WrenVM* vm, int slotIdx, T d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenExGetSlotFlags<T, U>(fromString, vm, slotIdx);
	} else {
		return d;
	}
}

// End Helpers }}}

// Helper classes {{{
class Box {
	using Field = std::variant<WrenNull, bool, double, std::string>;
	public:
	static void alloc(WrenVM* vm)
	{
		void* memory = wrenSetSlotNewForeign(vm, 0, 0, sizeof(Field));
		Field* field = new (memory) Field();
	}
	static void finalize(void* memory)
	{
		Field* field = (Field*)memory;
		field->~Field();
	}
	static void init(WrenVM* vm)
	{
		set(vm);
	}
	static void get(WrenVM* vm)
	{
		Field* field = (Field*)wrenGetSlotForeign(vm, 0);
		std::visit([&](auto&&arg){wrenExSetSlot(vm, 0, arg);}, *field);
	}
	template<typename T>
	static T getCPP(WrenVM* vm, int slotIdx)
	{
		Field* field = (Field*)wrenGetSlotForeign(vm, slotIdx);
		return std::get<T>(*field);
	}
	static void set(WrenVM* vm)
	{
		Field* field = (Field*)wrenGetSlotForeign(vm, 0);
		switch(wrenGetSlotType(vm, 1))
		{
		case WREN_TYPE_BOOL:
			{
				*field = wrenExGetSlot<bool>(vm, 1);
			}
			break;
		case WREN_TYPE_NUM:
			{
				*field = wrenExGetSlot<double>(vm, 1);
			}
			break;
		case WREN_TYPE_STRING:
			{
				*field = wrenExGetSlot<std::string>(vm, 1);
			}
			break;
		default:
			{
				wrenExAbortf(vm, "Invalid box type");
			}
			break;
		}
	}
	template<typename T>
	static void setCPP(WrenVM* vm, int slotIdx, T v)
	{
		Field* field = (Field*)wrenGetSlotForeign(vm, slotIdx);
		*field = v;
	}
};

class WrapImVec2 {
	public:
	static void alloc(WrenVM* vm)
	{
		void* memory = wrenSetSlotNewForeign(vm, 0, 0, sizeof(ImVec2));
		ImVec2* field = new (memory) ImVec2(0.0f, 0.0f);
	}
	static void finalize(void* memory)
	{
		ImVec2* field = (ImVec2*)memory;
		field->~ImVec2();
	}
	static void init(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to X is not a number");
		}
		field->x = static_cast<float>(wrenExGetSlot<double>(vm, 1));

		if(!wrenGetSlotType(vm, 2) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Y is not a number");
		}
		field->y = static_cast<float>(wrenExGetSlot<double>(vm, 2));
	}
	static void getX(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		wrenExSetSlot(vm, 0, field->x);
	}
	static void setX(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to X is not a number");
		}
		field->x = static_cast<float>(wrenExGetSlot<double>(vm, 1));
	}
	static void getY(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		wrenExSetSlot(vm, 0, field->y);
	}
	static void setY(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Y is not a number");
		}
		field->y = static_cast<float>(wrenExGetSlot<double>(vm, 1));
	}

	static ImVec2 getSlot(WrenVM* vm, int slotIdx)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, slotIdx);
		return *field;
	}

	static ImVec2 getSlotDefault(WrenVM* vm, int slotIdx, const ImVec2 d)
	{
		if(wrenGetSlotCount(vm) > slotIdx) {
			ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
			return *field;
		} else {
			return d;
		}
	}

	static ImVec2* setSlot(WrenVM* vm, int slotIdx, const ImVec2 d = ImVec2(0, 0))
	{
		wrenGetVariable(vm, "ImGui", "ImVec2", slotIdx);
		void* memory = wrenSetSlotNewForeign(vm, slotIdx, slotIdx, sizeof(ImVec2));
		ImVec2* field = (ImVec2*) memory;
		*field = d;
		return field;
	}
};

class WrapImVec4 {
	public:
	static void alloc(WrenVM* vm)
	{
		void* memory = wrenSetSlotNewForeign(vm, 0, 0, sizeof(ImVec4));
		ImVec4* field = new (memory) ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	}
	static void finalize(void* memory)
	{
		ImVec4* field = (ImVec4*)memory;
		field->~ImVec4();
	}
	static void init(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to X is not a number");
		}
		field->x = static_cast<float>(wrenExGetSlot<double>(vm, 1));

		if(!wrenGetSlotType(vm, 2) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Y is not a number");
		}
		field->y = static_cast<float>(wrenExGetSlot<double>(vm, 2));
	}
	static void getX(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		wrenExSetSlot(vm, 0, field->x);
	}
	static void setX(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to X is not a number");
		}
		field->x = static_cast<float>(wrenExGetSlot<double>(vm, 1));
	}
	static void getY(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		wrenExSetSlot(vm, 0, field->y);
	}
	static void setY(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Y is not a number");
		}
		field->y = static_cast<float>(wrenExGetSlot<double>(vm, 1));
	}
	static void getZ(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		wrenExSetSlot(vm, 0, field->y);
	}
	static void setZ(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Z is not a number");
		}
		field->y = static_cast<float>(wrenExGetSlot<double>(vm, 1));
	}
	static void getW(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		wrenExSetSlot(vm, 0, field->y);
	}
	static void setW(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to W is not a number");
		}
		field->y = static_cast<float>(wrenExGetSlot<double>(vm, 1));
	}

	static ImVec4 getSlot(WrenVM* vm, int slotIdx)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, slotIdx);
		return *field;
	}

	static ImVec4 getSlotDefault(WrenVM* vm, int slotIdx, const ImVec4 d)
	{
		if(wrenGetSlotCount(vm) > slotIdx) {
			ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
			return *field;
		} else {
			return d;
		}
	}

	static ImVec4* setSlot(WrenVM* vm, int slotIdx, const ImVec4 d = ImVec4(0, 0, 0, 0))
	{
		wrenGetVariable(vm, "ImGui", "ImVec4", slotIdx);
		void* memory = wrenSetSlotNewForeign(vm, slotIdx, slotIdx, sizeof(ImVec4));
		ImVec4* field = (ImVec4*) memory;
		*field = d;
		return field;
	}
};
// }}}

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

/*  ends the Dear ImGui frame. automatically called by Render(). If you don't need to render data (skipping rendering) you may call EndFrame() without Render()... but you'll have wasted CPU already! If you don't need to render, better to not create any windows and not call NewFrame() at all! */
void w_EndFrame(WrenVM *vm)
{
	ImGui::EndFrame();
	
}

/*  ends the Dear ImGui frame, finalize the draw data. You can get call GetDrawData() to obtain it and run your rendering function (up to v1.60, this used to call io.RenderDrawListsFn(). Nowadays, we allow and prefer calling your render function yourself.) */
void w_Render(WrenVM *vm)
{
	ImGui::Render();
	
}

// skipping w_GetDrawData due to unimplemented return type: "ImDrawData*"

/*  create Demo window (previously called ShowTestWindow). demonstrate most ImGui features. call this to learn about the library! try to make it always available in your application! */
void w_ShowDemoWindow(WrenVM *vm)
{
	auto p_open = static_cast<bool>(Box::getCPP<bool>(vm, 1));
	
	ImGui::ShowDemoWindow(&p_open);
	
	Box::setCPP<bool>(vm, 1, p_open);
}

/*  create About window. display Dear ImGui version, credits and build/system information. */
void w_ShowAboutWindow(WrenVM *vm)
{
	auto p_open = static_cast<bool>(Box::getCPP<bool>(vm, 1));
	
	ImGui::ShowAboutWindow(&p_open);
	
	Box::setCPP<bool>(vm, 1, p_open);
}

/*  create Debug/Metrics window. display Dear ImGui internals: draw commands (with individual draw calls and vertices), window list, basic internal state, etc. */
void w_ShowMetricsWindow(WrenVM *vm)
{
	auto p_open = static_cast<bool>(Box::getCPP<bool>(vm, 1));
	
	ImGui::ShowMetricsWindow(&p_open);
	
	Box::setCPP<bool>(vm, 1, p_open);
}

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

void w_Begin(WrenVM *vm)
{
	auto name = wrenGetSlotString(vm, 1);
	auto p_open = static_cast<bool>(Box::getCPP<bool>(vm, 2));
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, vm, 3);
	
	bool out = ImGui::Begin(name, &p_open, flags);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<bool>(vm, 2, p_open);
}

void w_End(WrenVM *vm)
{
	ImGui::End();
	
}

void w_BeginChild_Override1(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	auto size = wrenExIsSlotDefault(vm, 2) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 2);
	auto border = wrenExIsSlotDefault(vm, 3) ? false : wrenExGetSlot<bool>(vm, 3);
	auto flags = wrenExIsSlotDefault(vm, 4) ? 0 : wrenExGetSlotFlags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, vm, 4);
	
	bool out = ImGui::BeginChild(str_id, size, border, flags);
	wrenSetSlotBool(vm, 0, out);
	
}

void w_BeginChild_Override2(WrenVM *vm)
{
	auto id = static_cast<ImGuiID>(wrenExGetSlot<int>(vm, 1));
	auto size = wrenExIsSlotDefault(vm, 2) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 2);
	auto border = wrenExIsSlotDefault(vm, 3) ? false : wrenExGetSlot<bool>(vm, 3);
	auto flags = wrenExIsSlotDefault(vm, 4) ? 0 : wrenExGetSlotFlags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, vm, 4);
	
	bool out = ImGui::BeginChild(id, size, border, flags);
	wrenSetSlotBool(vm, 0, out);
	
}

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
	auto flags = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlotFlags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, vm, 1);
	
	bool out = ImGui::IsWindowFocused(flags);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  is current window hovered (and typically: not blocked by a popup/modal)? see flags for options. NB: If you are trying to check whether your mouse should be dispatched to imgui or to your app, you should use the 'io.WantCaptureMouse' boolean for that! Please read the FAQ! */
void w_IsWindowHovered(WrenVM *vm)
{
	auto flags = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlotFlags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, vm, 1);
	
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

/*  get current window position in screen space (useful if you want to do your own drawing via the DrawList API) */
void w_GetWindowPos(WrenVM *vm)
{
	ImVec2 out = ImGui::GetWindowPos();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  get current window size */
void w_GetWindowSize(WrenVM *vm)
{
	ImVec2 out = ImGui::GetWindowSize();
	WrapImVec2::setSlot(vm, 0, out);
	
}

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

/*  set next window position. call before Begin(). use pivot=(0.5f,0.5f) to center on given point, etc. */
void w_SetNextWindowPos(WrenVM *vm)
{
	auto pos = WrapImVec2::getSlot(vm, 1);
	auto cond = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 2);
	auto pivot = wrenExIsSlotDefault(vm, 3) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 3);
	
	ImGui::SetNextWindowPos(pos, cond, pivot);
	
}

/*  set next window size. set axis to 0.0f to force an auto-fit on this axis. call before Begin() */
void w_SetNextWindowSize(WrenVM *vm)
{
	auto size = WrapImVec2::getSlot(vm, 1);
	auto cond = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 2);
	
	ImGui::SetNextWindowSize(size, cond);
	
}

// skipping w_SetNextWindowSizeConstraints due to unimplemented argument type: "ImGuiSizeCallback"

/*  set next window content size (~ scrollable client area, which enforce the range of scrollbars). Not including window decorations (title bar, menu bar, etc.) nor WindowPadding. set an axis to 0.0f to leave it automatic. call before Begin() */
void w_SetNextWindowContentSize(WrenVM *vm)
{
	auto size = WrapImVec2::getSlot(vm, 1);
	
	ImGui::SetNextWindowContentSize(size);
	
}

/*  set next window collapsed state. call before Begin() */
void w_SetNextWindowCollapsed(WrenVM *vm)
{
	auto collapsed = wrenExGetSlot<bool>(vm, 1);
	auto cond = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 2);
	
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
	auto alpha = wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetNextWindowBgAlpha(alpha);
	
}

/*  set next window viewport */
void w_SetNextWindowViewport(WrenVM *vm)
{
	auto viewport_id = static_cast<ImGuiID>(wrenExGetSlot<int>(vm, 1));
	
	ImGui::SetNextWindowViewport(viewport_id);
	
}

/*  (not recommended) set current window position - call within Begin()/End(). prefer using SetNextWindowPos(), as this may incur tearing and side-effects. */
void w_SetWindowPos_Override1(WrenVM *vm)
{
	auto pos = WrapImVec2::getSlot(vm, 1);
	auto cond = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 2);
	
	ImGui::SetWindowPos(pos, cond);
	
}

/*  (not recommended) set current window size - call within Begin()/End(). set to ImVec2(0, 0) to force an auto-fit. prefer using SetNextWindowSize(), as this may incur tearing and minor side-effects. */
void w_SetWindowSize_Override1(WrenVM *vm)
{
	auto size = WrapImVec2::getSlot(vm, 1);
	auto cond = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 2);
	
	ImGui::SetWindowSize(size, cond);
	
}

/*  (not recommended) set current window collapsed state. prefer using SetNextWindowCollapsed(). */
void w_SetWindowCollapsed_Override1(WrenVM *vm)
{
	auto collapsed = wrenExGetSlot<bool>(vm, 1);
	auto cond = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 2);
	
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
	auto scale = wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetWindowFontScale(scale);
	
}

/*  set named window position. */
void w_SetWindowPos_Override2(WrenVM *vm)
{
	auto name = wrenGetSlotString(vm, 1);
	auto pos = WrapImVec2::getSlot(vm, 2);
	auto cond = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 3);
	
	ImGui::SetWindowPos(name, pos, cond);
	
}

/*  set named window size. set axis to 0.0f to force an auto-fit on this axis. */
void w_SetWindowSize_Override2(WrenVM *vm)
{
	auto name = wrenGetSlotString(vm, 1);
	auto size = WrapImVec2::getSlot(vm, 2);
	auto cond = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 3);
	
	ImGui::SetWindowSize(name, size, cond);
	
}

/*  set named window collapsed state */
void w_SetWindowCollapsed_Override2(WrenVM *vm)
{
	auto name = wrenGetSlotString(vm, 1);
	auto collapsed = wrenExGetSlot<bool>(vm, 2);
	auto cond = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 3);
	
	ImGui::SetWindowCollapsed(name, collapsed, cond);
	
}

/*  set named window to be focused / top-most. use NULL to remove focus. */
void w_SetWindowFocus_Override2(WrenVM *vm)
{
	auto name = wrenGetSlotString(vm, 1);
	
	ImGui::SetWindowFocus(name);
	
}

/*  current content boundaries (typically window boundaries including scrolling, or current column boundaries), in windows coordinates */
void w_GetContentRegionMax(WrenVM *vm)
{
	ImVec2 out = ImGui::GetContentRegionMax();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  == GetContentRegionMax() - GetCursorPos() */
void w_GetContentRegionAvail(WrenVM *vm)
{
	ImVec2 out = ImGui::GetContentRegionAvail();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  content boundaries min (roughly (0,0)-Scroll), in window coordinates */
void w_GetWindowContentRegionMin(WrenVM *vm)
{
	ImVec2 out = ImGui::GetWindowContentRegionMin();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  content boundaries max (roughly (0,0)+Size-Scroll) where Size can be override with SetNextWindowContentSize(), in window coordinates */
void w_GetWindowContentRegionMax(WrenVM *vm)
{
	ImVec2 out = ImGui::GetWindowContentRegionMax();
	WrapImVec2::setSlot(vm, 0, out);
	
}

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
	auto scroll_x = wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetScrollX(scroll_x);
	
}

/*  set scrolling amount [0..GetScrollMaxY()] */
void w_SetScrollY(WrenVM *vm)
{
	auto scroll_y = wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetScrollY(scroll_y);
	
}

/*  adjust scrolling amount to make current cursor position visible. center_x_ratio=0.0: left, 0.5: center, 1.0: right. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead. */
void w_SetScrollHereX(WrenVM *vm)
{
	auto center_x_ratio = wrenExIsSlotDefault(vm, 1) ? 0.5f : wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetScrollHereX(center_x_ratio);
	
}

/*  adjust scrolling amount to make current cursor position visible. center_y_ratio=0.0: top, 0.5: center, 1.0: bottom. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead. */
void w_SetScrollHereY(WrenVM *vm)
{
	auto center_y_ratio = wrenExIsSlotDefault(vm, 1) ? 0.5f : wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetScrollHereY(center_y_ratio);
	
}

/*  adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position. */
void w_SetScrollFromPosX(WrenVM *vm)
{
	auto local_x = wrenExGetSlot<float>(vm, 1);
	auto center_x_ratio = wrenExIsSlotDefault(vm, 2) ? 0.5f : wrenExGetSlot<float>(vm, 2);
	
	ImGui::SetScrollFromPosX(local_x, center_x_ratio);
	
}

/*  adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position. */
void w_SetScrollFromPosY(WrenVM *vm)
{
	auto local_y = wrenExGetSlot<float>(vm, 1);
	auto center_y_ratio = wrenExIsSlotDefault(vm, 2) ? 0.5f : wrenExGetSlot<float>(vm, 2);
	
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
	auto col = static_cast<ImU32>(wrenExGetSlot<unsigned int>(vm, 2));
	
	ImGui::PushStyleColor(idx, col);
	
}

void w_PushStyleColor_Override2(WrenVM *vm)
{
	auto idx = wrenExGetSlotEnum<ImGuiCol>(getImGuiColFromString, vm, 1);
	auto col = WrapImVec4::getSlot(vm, 2);
	
	ImGui::PushStyleColor(idx, col);
	
}

void w_PopStyleColor(WrenVM *vm)
{
	auto count = wrenExIsSlotDefault(vm, 1) ? 1 : wrenExGetSlot<int>(vm, 1);
	
	ImGui::PopStyleColor(count);
	
}

void w_PushStyleVar_Override1(WrenVM *vm)
{
	auto idx = wrenExGetSlotEnum<ImGuiStyleVar>(getImGuiStyleVarFromString, vm, 1);
	auto val = wrenExGetSlot<float>(vm, 2);
	
	ImGui::PushStyleVar(idx, val);
	
}

void w_PushStyleVar_Override2(WrenVM *vm)
{
	auto idx = wrenExGetSlotEnum<ImGuiStyleVar>(getImGuiStyleVarFromString, vm, 1);
	auto val = WrapImVec2::getSlot(vm, 2);
	
	ImGui::PushStyleVar(idx, val);
	
}

void w_PopStyleVar(WrenVM *vm)
{
	auto count = wrenExIsSlotDefault(vm, 1) ? 1 : wrenExGetSlot<int>(vm, 1);
	
	ImGui::PopStyleVar(count);
	
}

/*  retrieve style color as stored in ImGuiStyle structure. use to feed back into PushStyleColor(), otherwise use GetColorU32() to get style color with style alpha baked in. */
void w_GetStyleColorVec4(WrenVM *vm)
{
	auto idx = wrenExGetSlotEnum<ImGuiCol>(getImGuiColFromString, vm, 1);
	
	const ImVec4& out = ImGui::GetStyleColorVec4(idx);
	WrapImVec4::setSlot(vm, 0, out);
	
}

// skipping w_GetFont due to unimplemented return type: "ImFont*"

/*  get current font size (= height in pixels) of current font with current scale applied */
void w_GetFontSize(WrenVM *vm)
{
	float out = ImGui::GetFontSize();
	wrenSetSlotDouble(vm, 0, out);
	
}

/*  get UV coordinate for a while pixel, useful to draw custom shapes via the ImDrawList API */
void w_GetFontTexUvWhitePixel(WrenVM *vm)
{
	ImVec2 out = ImGui::GetFontTexUvWhitePixel();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  push width of items for common large "item+label" widgets. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side). 0.0f = default to ~2/3 of windows width, */
void w_PushItemWidth(WrenVM *vm)
{
	auto item_width = wrenExGetSlot<float>(vm, 1);
	
	ImGui::PushItemWidth(item_width);
	
}

void w_PopItemWidth(WrenVM *vm)
{
	ImGui::PopItemWidth();
	
}

/*  set width of the _next_ common large "item+label" widget. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side) */
void w_SetNextItemWidth(WrenVM *vm)
{
	auto item_width = wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetNextItemWidth(item_width);
	
}

/*  width of item given pushed settings and current cursor position. NOT necessarily the width of last item unlike most 'Item' functions. */
void w_CalcItemWidth(WrenVM *vm)
{
	float out = ImGui::CalcItemWidth();
	wrenSetSlotDouble(vm, 0, out);
	
}

/*  push word-wrapping position for Text*() commands. < 0.0f: no wrapping; 0.0f: wrap to end of window (or column); > 0.0f: wrap at 'wrap_pos_x' position in window local space */
void w_PushTextWrapPos(WrenVM *vm)
{
	auto wrap_local_pos_x = wrenExIsSlotDefault(vm, 1) ? 0.0f : wrenExGetSlot<float>(vm, 1);
	
	ImGui::PushTextWrapPos(wrap_local_pos_x);
	
}

void w_PopTextWrapPos(WrenVM *vm)
{
	ImGui::PopTextWrapPos();
	
}

/*  allow focusing using TAB/Shift-TAB, enabled by default but you can disable it for certain widgets */
void w_PushAllowKeyboardFocus(WrenVM *vm)
{
	auto allow_keyboard_focus = wrenExGetSlot<bool>(vm, 1);
	
	ImGui::PushAllowKeyboardFocus(allow_keyboard_focus);
	
}

void w_PopAllowKeyboardFocus(WrenVM *vm)
{
	ImGui::PopAllowKeyboardFocus();
	
}

/*  in 'repeat' mode, Button*() functions return repeated true in a typematic manner (using io.KeyRepeatDelay/io.KeyRepeatRate setting). Note that you can call IsItemActive() after any Button() to tell if the button is held in the current frame. */
void w_PushButtonRepeat(WrenVM *vm)
{
	auto repeat = wrenExGetSlot<bool>(vm, 1);
	
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
	auto offset_from_start_x = wrenExIsSlotDefault(vm, 1) ? 0.0f : wrenExGetSlot<float>(vm, 1);
	auto spacing = wrenExIsSlotDefault(vm, 2) ? -1.0f : wrenExGetSlot<float>(vm, 2);
	
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

/*  add a dummy item of given size. unlike InvisibleButton(), Dummy() won't take the mouse click or be navigable into. */
void w_Dummy(WrenVM *vm)
{
	auto size = WrapImVec2::getSlot(vm, 1);
	
	ImGui::Dummy(size);
	
}

/*  move content position toward the right, by style.IndentSpacing or indent_w if != 0 */
void w_Indent(WrenVM *vm)
{
	auto indent_w = wrenExIsSlotDefault(vm, 1) ? 0.0f : wrenExGetSlot<float>(vm, 1);
	
	ImGui::Indent(indent_w);
	
}

/*  move content position back to the left, by style.IndentSpacing or indent_w if != 0 */
void w_Unindent(WrenVM *vm)
{
	auto indent_w = wrenExIsSlotDefault(vm, 1) ? 0.0f : wrenExGetSlot<float>(vm, 1);
	
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

/*  cursor position in window coordinates (relative to window position) */
void w_GetCursorPos(WrenVM *vm)
{
	ImVec2 out = ImGui::GetCursorPos();
	WrapImVec2::setSlot(vm, 0, out);
	
}

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

/*     are using the main, absolute coordinate system. */
void w_SetCursorPos(WrenVM *vm)
{
	auto local_pos = WrapImVec2::getSlot(vm, 1);
	
	ImGui::SetCursorPos(local_pos);
	
}

/*     GetWindowPos() + GetCursorPos() == GetCursorScreenPos() etc.) */
void w_SetCursorPosX(WrenVM *vm)
{
	auto local_x = wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetCursorPosX(local_x);
	
}

void w_SetCursorPosY(WrenVM *vm)
{
	auto local_y = wrenExGetSlot<float>(vm, 1);
	
	ImGui::SetCursorPosY(local_y);
	
}

/*  initial cursor position in window coordinates */
void w_GetCursorStartPos(WrenVM *vm)
{
	ImVec2 out = ImGui::GetCursorStartPos();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  cursor position in absolute screen coordinates (0..io.DisplaySize) or natural OS coordinates when using multiple viewport. Useful to work with ImDrawList API. */
void w_GetCursorScreenPos(WrenVM *vm)
{
	ImVec2 out = ImGui::GetCursorScreenPos();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  cursor position in absolute screen coordinates (0..io.DisplaySize) or natural OS coordinates when using multiple viewport. */
void w_SetCursorScreenPos(WrenVM *vm)
{
	auto pos = WrapImVec2::getSlot(vm, 1);
	
	ImGui::SetCursorScreenPos(pos);
	
}

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
	auto int_id = wrenExGetSlot<int>(vm, 1);
	
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
	auto text_end = wrenExIsSlotDefault(vm, 2) ? NULL : wrenGetSlotString(vm, 2);
	
	ImGui::TextUnformatted(text, text_end);
	
}

/*  formatted text */
void w_Text(WrenVM *vm)
{
	auto fmt = wrenGetSlotString(vm, 1);
	
	ImGui::Text(fmt);
	
}

/*  shortcut for PushStyleColor(ImGuiCol_Text, col); Text(fmt, ...); PopStyleColor(); */
void w_TextColored(WrenVM *vm)
{
	auto col = WrapImVec4::getSlot(vm, 1);
	auto fmt = wrenGetSlotString(vm, 2);
	
	ImGui::TextColored(col, fmt);
	
}

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

/*  button */
void w_Button(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto size = wrenExIsSlotDefault(vm, 2) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 2);
	
	bool out = ImGui::Button(label, size);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  button with FramePadding=(0,0) to easily embed within text */
void w_SmallButton(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	
	bool out = ImGui::SmallButton(label);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  button behavior without the visuals, frequently useful to build custom behaviors using the public api (along with IsItemActive, IsItemHovered, etc.) */
void w_InvisibleButton(WrenVM *vm)
{
	auto str_id = wrenGetSlotString(vm, 1);
	auto size = WrapImVec2::getSlot(vm, 2);
	
	bool out = ImGui::InvisibleButton(str_id, size);
	wrenSetSlotBool(vm, 0, out);
	
}

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

void w_Checkbox(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<bool>(Box::getCPP<bool>(vm, 2));
	
	bool out = ImGui::Checkbox(label, &v);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<bool>(vm, 2, v);
}

void w_CheckboxFlags(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto flags = static_cast<unsigned int>(Box::getCPP<double>(vm, 2));
	auto flags_value = wrenExGetSlot<unsigned int>(vm, 3);
	
	bool out = ImGui::CheckboxFlags(label, &flags, flags_value);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, flags);
}

/*  use with e.g. if (RadioButton("one", my_value==1)) { my_value = 1; } */
void w_RadioButton_Override1(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto active = wrenExGetSlot<bool>(vm, 2);
	
	bool out = ImGui::RadioButton(label, active);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  shortcut to handle the above pattern when value is an integer */
void w_RadioButton_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<int>(Box::getCPP<double>(vm, 2));
	auto v_button = wrenExGetSlot<int>(vm, 3);
	
	bool out = ImGui::RadioButton(label, &v, v_button);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v);
}

void w_ProgressBar(WrenVM *vm)
{
	auto fraction = wrenExGetSlot<float>(vm, 1);
	auto size_arg = wrenExIsSlotDefault(vm, 2) ? ImVec2(-1, 0) : WrapImVec2::getSlot(vm, 2);
	auto overlay = wrenExIsSlotDefault(vm, 3) ? NULL : wrenGetSlotString(vm, 3);
	
	ImGui::ProgressBar(fraction, size_arg, overlay);
	
}

/*  draw a small circle and keep the cursor on the same line. advance cursor x position by GetTreeNodeToLabelSpacing(), same distance that TreeNode() uses */
void w_Bullet(WrenVM *vm)
{
	ImGui::Bullet();
	
}

void w_BeginCombo(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto preview_value = wrenGetSlotString(vm, 2);
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiComboFlags>(getImGuiComboFlagsFromString, vm, 3);
	
	bool out = ImGui::BeginCombo(label, preview_value, flags);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  only call EndCombo() if BeginCombo() returns true! */
void w_EndCombo(WrenVM *vm)
{
	ImGui::EndCombo();
	
}

// skipping w_Combo_Override1 due to unimplemented argument type: "const char* const[]"

/*  Separate items with \0 within a string, end item-list with \0\0. e.g. "One\0Two\0Three\0" */
void w_Combo_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto current_item = static_cast<int>(Box::getCPP<double>(vm, 2));
	auto items_separated_by_zeros = wrenGetSlotString(vm, 3);
	auto popup_max_height_in_items = wrenExIsSlotDefault(vm, 4) ? -1 : wrenExGetSlot<int>(vm, 4);
	
	bool out = ImGui::Combo(label, &current_item, items_separated_by_zeros, popup_max_height_in_items);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, current_item);
}

// skipping w_Combo_Override3 due to unimplemented argument type: " bool(*items_getter)(void* data, int idx, const char** out_text)"

/*  If v_min >= v_max we have no bound */
void w_DragFloat(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<float>(Box::getCPP<double>(vm, 2));
	auto v_speed = wrenExIsSlotDefault(vm, 3) ? 1.0f : wrenExGetSlot<float>(vm, 3);
	auto v_min = wrenExIsSlotDefault(vm, 4) ? 0.0f : wrenExGetSlot<float>(vm, 4);
	auto v_max = wrenExIsSlotDefault(vm, 5) ? 0.0f : wrenExGetSlot<float>(vm, 5);
	auto format = wrenExIsSlotDefault(vm, 6) ? "%.3f" : wrenGetSlotString(vm, 6);
	auto power = wrenExIsSlotDefault(vm, 7) ? 1.0f : wrenExGetSlot<float>(vm, 7);
	
	bool out = ImGui::DragFloat(label, &v, v_speed, v_min, v_max, format, power);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v);
}

// skipping w_DragFloat2 due to unimplemented argument type: "float[2]"

// skipping w_DragFloat3 due to unimplemented argument type: "float[3]"

// skipping w_DragFloat4 due to unimplemented argument type: "float[4]"

void w_DragFloatRange2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v_current_min = static_cast<float>(Box::getCPP<double>(vm, 2));
	auto v_current_max = static_cast<float>(Box::getCPP<double>(vm, 3));
	auto v_speed = wrenExIsSlotDefault(vm, 4) ? 1.0f : wrenExGetSlot<float>(vm, 4);
	auto v_min = wrenExIsSlotDefault(vm, 5) ? 0.0f : wrenExGetSlot<float>(vm, 5);
	auto v_max = wrenExIsSlotDefault(vm, 6) ? 0.0f : wrenExGetSlot<float>(vm, 6);
	auto format = wrenExIsSlotDefault(vm, 7) ? "%.3f" : wrenGetSlotString(vm, 7);
	auto format_max = wrenExIsSlotDefault(vm, 8) ? NULL : wrenGetSlotString(vm, 8);
	auto power = wrenExIsSlotDefault(vm, 9) ? 1.0f : wrenExGetSlot<float>(vm, 9);
	
	bool out = ImGui::DragFloatRange2(label, &v_current_min, &v_current_max, v_speed, v_min, v_max, format, format_max, power);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v_current_min);
	Box::setCPP<double>(vm, 3, v_current_max);
}

/*  If v_min >= v_max we have no bound */
void w_DragInt(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<int>(Box::getCPP<double>(vm, 2));
	auto v_speed = wrenExIsSlotDefault(vm, 3) ? 1.0f : wrenExGetSlot<float>(vm, 3);
	auto v_min = wrenExIsSlotDefault(vm, 4) ? 0 : wrenExGetSlot<int>(vm, 4);
	auto v_max = wrenExIsSlotDefault(vm, 5) ? 0 : wrenExGetSlot<int>(vm, 5);
	auto format = wrenExIsSlotDefault(vm, 6) ? "%d" : wrenGetSlotString(vm, 6);
	
	bool out = ImGui::DragInt(label, &v, v_speed, v_min, v_max, format);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v);
}

// skipping w_DragInt2 due to unimplemented argument type: "int[2]"

// skipping w_DragInt3 due to unimplemented argument type: "int[3]"

// skipping w_DragInt4 due to unimplemented argument type: "int[4]"

void w_DragIntRange2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v_current_min = static_cast<int>(Box::getCPP<double>(vm, 2));
	auto v_current_max = static_cast<int>(Box::getCPP<double>(vm, 3));
	auto v_speed = wrenExIsSlotDefault(vm, 4) ? 1.0f : wrenExGetSlot<float>(vm, 4);
	auto v_min = wrenExIsSlotDefault(vm, 5) ? 0 : wrenExGetSlot<int>(vm, 5);
	auto v_max = wrenExIsSlotDefault(vm, 6) ? 0 : wrenExGetSlot<int>(vm, 6);
	auto format = wrenExIsSlotDefault(vm, 7) ? "%d" : wrenGetSlotString(vm, 7);
	auto format_max = wrenExIsSlotDefault(vm, 8) ? NULL : wrenGetSlotString(vm, 8);
	
	bool out = ImGui::DragIntRange2(label, &v_current_min, &v_current_max, v_speed, v_min, v_max, format, format_max);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v_current_min);
	Box::setCPP<double>(vm, 3, v_current_max);
}

/*  adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display. Use power!=1.0 for power curve sliders */
void w_SliderFloat(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<float>(Box::getCPP<double>(vm, 2));
	auto v_min = wrenExGetSlot<float>(vm, 3);
	auto v_max = wrenExGetSlot<float>(vm, 4);
	auto format = wrenExIsSlotDefault(vm, 5) ? "%.3f" : wrenGetSlotString(vm, 5);
	auto power = wrenExIsSlotDefault(vm, 6) ? 1.0f : wrenExGetSlot<float>(vm, 6);
	
	bool out = ImGui::SliderFloat(label, &v, v_min, v_max, format, power);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v);
}

// skipping w_SliderFloat2 due to unimplemented argument type: "float[2]"

// skipping w_SliderFloat3 due to unimplemented argument type: "float[3]"

// skipping w_SliderFloat4 due to unimplemented argument type: "float[4]"

void w_SliderAngle(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v_rad = static_cast<float>(Box::getCPP<double>(vm, 2));
	auto v_degrees_min = wrenExIsSlotDefault(vm, 3) ? -360.0f : wrenExGetSlot<float>(vm, 3);
	auto v_degrees_max = wrenExIsSlotDefault(vm, 4) ? +360.0f : wrenExGetSlot<float>(vm, 4);
	auto format = wrenExIsSlotDefault(vm, 5) ? "%.0f deg" : wrenGetSlotString(vm, 5);
	
	bool out = ImGui::SliderAngle(label, &v_rad, v_degrees_min, v_degrees_max, format);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v_rad);
}

void w_SliderInt(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<int>(Box::getCPP<double>(vm, 2));
	auto v_min = wrenExGetSlot<int>(vm, 3);
	auto v_max = wrenExGetSlot<int>(vm, 4);
	auto format = wrenExIsSlotDefault(vm, 5) ? "%d" : wrenGetSlotString(vm, 5);
	
	bool out = ImGui::SliderInt(label, &v, v_min, v_max, format);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v);
}

// skipping w_SliderInt2 due to unimplemented argument type: "int[2]"

// skipping w_SliderInt3 due to unimplemented argument type: "int[3]"

// skipping w_SliderInt4 due to unimplemented argument type: "int[4]"

void w_VSliderFloat(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto size = WrapImVec2::getSlot(vm, 2);
	auto v = static_cast<float>(Box::getCPP<double>(vm, 3));
	auto v_min = wrenExGetSlot<float>(vm, 4);
	auto v_max = wrenExGetSlot<float>(vm, 5);
	auto format = wrenExIsSlotDefault(vm, 6) ? "%.3f" : wrenGetSlotString(vm, 6);
	auto power = wrenExIsSlotDefault(vm, 7) ? 1.0f : wrenExGetSlot<float>(vm, 7);
	
	bool out = ImGui::VSliderFloat(label, size, &v, v_min, v_max, format, power);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 3, v);
}

void w_VSliderInt(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto size = WrapImVec2::getSlot(vm, 2);
	auto v = static_cast<int>(Box::getCPP<double>(vm, 3));
	auto v_min = wrenExGetSlot<int>(vm, 4);
	auto v_max = wrenExGetSlot<int>(vm, 5);
	auto format = wrenExIsSlotDefault(vm, 6) ? "%d" : wrenGetSlotString(vm, 6);
	
	bool out = ImGui::VSliderInt(label, size, &v, v_min, v_max, format);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 3, v);
}

// skipping w_InputText_Override1 due to unimplemented argument type: "(TODO) const buf*"

// skipping w_InputTextMultiline_Override1 due to unimplemented argument type: "(TODO) const buf*"

// skipping w_InputTextWithHint_Override1 due to unimplemented argument type: "(TODO) const buf*"

void w_InputFloat(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<float>(Box::getCPP<double>(vm, 2));
	auto step = wrenExIsSlotDefault(vm, 3) ? 0.0f : wrenExGetSlot<float>(vm, 3);
	auto step_fast = wrenExIsSlotDefault(vm, 4) ? 0.0f : wrenExGetSlot<float>(vm, 4);
	auto format = wrenExIsSlotDefault(vm, 5) ? "%.3f" : wrenGetSlotString(vm, 5);
	auto flags = wrenExIsSlotDefault(vm, 6) ? 0 : wrenExGetSlotFlags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, vm, 6);
	
	bool out = ImGui::InputFloat(label, &v, step, step_fast, format, flags);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v);
}

// skipping w_InputFloat2 due to unimplemented argument type: "float[2]"

// skipping w_InputFloat3 due to unimplemented argument type: "float[3]"

// skipping w_InputFloat4 due to unimplemented argument type: "float[4]"

void w_InputInt(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<int>(Box::getCPP<double>(vm, 2));
	auto step = wrenExIsSlotDefault(vm, 3) ? 1 : wrenExGetSlot<int>(vm, 3);
	auto step_fast = wrenExIsSlotDefault(vm, 4) ? 100 : wrenExGetSlot<int>(vm, 4);
	auto flags = wrenExIsSlotDefault(vm, 5) ? 0 : wrenExGetSlotFlags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, vm, 5);
	
	bool out = ImGui::InputInt(label, &v, step, step_fast, flags);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v);
}

// skipping w_InputInt2 due to unimplemented argument type: "int[2]"

// skipping w_InputInt3 due to unimplemented argument type: "int[3]"

// skipping w_InputInt4 due to unimplemented argument type: "int[4]"

void w_InputDouble(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto v = static_cast<double>(Box::getCPP<double>(vm, 2));
	auto step = wrenExIsSlotDefault(vm, 3) ? 0.0 : wrenExGetSlot<double>(vm, 3);
	auto step_fast = wrenExIsSlotDefault(vm, 4) ? 0.0 : wrenExGetSlot<double>(vm, 4);
	auto format = wrenExIsSlotDefault(vm, 5) ? "%.6f" : wrenGetSlotString(vm, 5);
	auto flags = wrenExIsSlotDefault(vm, 6) ? 0 : wrenExGetSlotFlags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, vm, 6);
	
	bool out = ImGui::InputDouble(label, &v, step, step_fast, format, flags);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<double>(vm, 2, v);
}

// skipping w_ColorEdit3 due to unimplemented argument type: "float[3]"

// skipping w_ColorEdit4 due to unimplemented argument type: "float[4]"

// skipping w_ColorPicker3 due to unimplemented argument type: "float[3]"

// skipping w_ColorPicker4 due to unimplemented argument type: "float[4]"

/*  display a colored square/button, hover for details, return true when pressed. */
void w_ColorButton(WrenVM *vm)
{
	auto desc_id = wrenGetSlotString(vm, 1);
	auto col = WrapImVec4::getSlot(vm, 2);
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, vm, 3);
	auto size = wrenExIsSlotDefault(vm, 4) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 4);
	
	bool out = ImGui::ColorButton(desc_id, col, flags, size);
	wrenSetSlotBool(vm, 0, out);
	
}

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
	auto flags = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotFlags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, vm, 2);
	
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
	auto flags = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotFlags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, vm, 2);
	
	bool out = ImGui::CollapsingHeader(label, flags);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  when 'p_open' isn't NULL, display an additional small close button on upper right of the header */
void w_CollapsingHeader_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto p_open = static_cast<bool>(Box::getCPP<bool>(vm, 2));
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, vm, 3);
	
	bool out = ImGui::CollapsingHeader(label, &p_open, flags);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<bool>(vm, 2, p_open);
}

/*  set next TreeNode/CollapsingHeader open state. */
void w_SetNextItemOpen(WrenVM *vm)
{
	auto is_open = wrenExGetSlot<bool>(vm, 1);
	auto cond = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 2);
	
	ImGui::SetNextItemOpen(is_open, cond);
	
}

/*  "bool selected" carry the selection state (read-only). Selectable() is clicked is returns true so you can modify your selection state. size.x==0.0: use remaining width, size.x>0.0: specify width. size.y==0.0: use label height, size.y>0.0: specify height */
void w_Selectable_Override1(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto selected = wrenExIsSlotDefault(vm, 2) ? false : wrenExGetSlot<bool>(vm, 2);
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiSelectableFlags>(getImGuiSelectableFlagsFromString, vm, 3);
	auto size = wrenExIsSlotDefault(vm, 4) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 4);
	
	bool out = ImGui::Selectable(label, selected, flags, size);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  "bool* p_selected" point to the selection state (read-write), as a convenient helper. */
void w_Selectable_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto p_selected = static_cast<bool>(Box::getCPP<bool>(vm, 2));
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiSelectableFlags>(getImGuiSelectableFlagsFromString, vm, 3);
	auto size = wrenExIsSlotDefault(vm, 4) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 4);
	
	bool out = ImGui::Selectable(label, &p_selected, flags, size);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<bool>(vm, 2, p_selected);
}

// skipping w_ListBox_Override1 due to unimplemented argument type: "const char* const[]"

// skipping w_ListBox_Override2 due to unimplemented argument type: " bool (*items_getter)(void* data, int idx, const char** out_text)"

/*  use if you want to reimplement ListBox() will custom data or interactions. if the function return true, you can output elements then call ListBoxFooter() afterwards. */
void w_ListBoxHeader_Override1(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto size = wrenExIsSlotDefault(vm, 2) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 2);
	
	bool out = ImGui::ListBoxHeader(label, size);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  " */
void w_ListBoxHeader_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto items_count = wrenExGetSlot<int>(vm, 2);
	auto height_in_items = wrenExIsSlotDefault(vm, 3) ? -1 : wrenExGetSlot<int>(vm, 3);
	
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
	auto b = wrenExGetSlot<bool>(vm, 2);
	
	ImGui::Value(prefix, b);
	
}

void w_Value_Override2(WrenVM *vm)
{
	auto prefix = wrenGetSlotString(vm, 1);
	auto v = wrenExGetSlot<int>(vm, 2);
	
	ImGui::Value(prefix, v);
	
}

void w_Value_Override3(WrenVM *vm)
{
	auto prefix = wrenGetSlotString(vm, 1);
	auto v = wrenExGetSlot<unsigned int>(vm, 2);
	
	ImGui::Value(prefix, v);
	
}

void w_Value_Override4(WrenVM *vm)
{
	auto prefix = wrenGetSlotString(vm, 1);
	auto v = wrenExGetSlot<float>(vm, 2);
	auto float_format = wrenExIsSlotDefault(vm, 3) ? NULL : wrenGetSlotString(vm, 3);
	
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
	auto enabled = wrenExIsSlotDefault(vm, 2) ? true : wrenExGetSlot<bool>(vm, 2);
	
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
	auto shortcut = wrenExIsSlotDefault(vm, 2) ? NULL : wrenGetSlotString(vm, 2);
	auto selected = wrenExIsSlotDefault(vm, 3) ? false : wrenExGetSlot<bool>(vm, 3);
	auto enabled = wrenExIsSlotDefault(vm, 4) ? true : wrenExGetSlot<bool>(vm, 4);
	
	bool out = ImGui::MenuItem(label, shortcut, selected, enabled);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  return true when activated + toggle (*p_selected) if p_selected != NULL */
void w_MenuItem_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto shortcut = wrenGetSlotString(vm, 2);
	auto p_selected = static_cast<bool>(Box::getCPP<bool>(vm, 3));
	auto enabled = wrenExIsSlotDefault(vm, 4) ? true : wrenExGetSlot<bool>(vm, 4);
	
	bool out = ImGui::MenuItem(label, shortcut, &p_selected, enabled);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<bool>(vm, 3, p_selected);
}

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
	auto flags = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotFlags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, vm, 2);
	
	bool out = ImGui::BeginPopup(str_id, flags);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  helper to open and begin popup when clicked on last item. if you can pass a NULL str_id only if the previous item had an id. If you want to use that on a non-interactive item such as Text() you need to pass in an explicit ID here. read comments in .cpp! */
void w_BeginPopupContextItem(WrenVM *vm)
{
	auto str_id = wrenExIsSlotDefault(vm, 1) ? NULL : wrenGetSlotString(vm, 1);
	auto mouse_button = wrenExIsSlotDefault(vm, 2) ? 1 : wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 2);
	
	bool out = ImGui::BeginPopupContextItem(str_id, mouse_button);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  helper to open and begin popup when clicked on current window. */
void w_BeginPopupContextWindow(WrenVM *vm)
{
	auto str_id = wrenExIsSlotDefault(vm, 1) ? NULL : wrenGetSlotString(vm, 1);
	auto mouse_button = wrenExIsSlotDefault(vm, 2) ? 1 : wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 2);
	auto also_over_items = wrenExIsSlotDefault(vm, 3) ? true : wrenExGetSlot<bool>(vm, 3);
	
	bool out = ImGui::BeginPopupContextWindow(str_id, mouse_button, also_over_items);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  helper to open and begin popup when clicked in void (where there are no imgui windows). */
void w_BeginPopupContextVoid(WrenVM *vm)
{
	auto str_id = wrenExIsSlotDefault(vm, 1) ? NULL : wrenGetSlotString(vm, 1);
	auto mouse_button = wrenExIsSlotDefault(vm, 2) ? 1 : wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 2);
	
	bool out = ImGui::BeginPopupContextVoid(str_id, mouse_button);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  modal dialog (regular window with title bar, block interactions behind the modal window, can't close the modal window by clicking outside) */
void w_BeginPopupModal(WrenVM *vm)
{
	auto name = wrenGetSlotString(vm, 1);
	auto p_open = static_cast<bool>(Box::getCPP<bool>(vm, 2));
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, vm, 3);
	
	bool out = ImGui::BeginPopupModal(name, &p_open, flags);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<bool>(vm, 2, p_open);
}

/*  only call EndPopup() if BeginPopupXXX() returns true! */
void w_EndPopup(WrenVM *vm)
{
	ImGui::EndPopup();
	
}

/*  helper to open popup when clicked on last item (note: actually triggers on the mouse _released_ event to be consistent with popup behaviors). return true when just opened. */
void w_OpenPopupOnItemClick(WrenVM *vm)
{
	auto str_id = wrenExIsSlotDefault(vm, 1) ? NULL : wrenGetSlotString(vm, 1);
	auto mouse_button = wrenExIsSlotDefault(vm, 2) ? 1 : wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 2);
	
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
	auto count = wrenExIsSlotDefault(vm, 1) ? 1 : wrenExGetSlot<int>(vm, 1);
	auto id = wrenExIsSlotDefault(vm, 2) ? NULL : wrenGetSlotString(vm, 2);
	auto border = wrenExIsSlotDefault(vm, 3) ? true : wrenExGetSlot<bool>(vm, 3);
	
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
	auto column_index = wrenExIsSlotDefault(vm, 1) ? -1 : wrenExGetSlot<int>(vm, 1);
	
	float out = ImGui::GetColumnWidth(column_index);
	wrenSetSlotDouble(vm, 0, out);
	
}

/*  set column width (in pixels). pass -1 to use current column */
void w_SetColumnWidth(WrenVM *vm)
{
	auto column_index = wrenExGetSlot<int>(vm, 1);
	auto width = wrenExGetSlot<float>(vm, 2);
	
	ImGui::SetColumnWidth(column_index, width);
	
}

/*  get position of column line (in pixels, from the left side of the contents region). pass -1 to use current column, otherwise 0..GetColumnsCount() inclusive. column 0 is typically 0.0f */
void w_GetColumnOffset(WrenVM *vm)
{
	auto column_index = wrenExIsSlotDefault(vm, 1) ? -1 : wrenExGetSlot<int>(vm, 1);
	
	float out = ImGui::GetColumnOffset(column_index);
	wrenSetSlotDouble(vm, 0, out);
	
}

/*  set position of column line (in pixels, from the left side of the contents region). pass -1 to use current column */
void w_SetColumnOffset(WrenVM *vm)
{
	auto column_index = wrenExGetSlot<int>(vm, 1);
	auto offset_x = wrenExGetSlot<float>(vm, 2);
	
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
	auto flags = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotFlags<ImGuiTabBarFlags>(getImGuiTabBarFlagsFromString, vm, 2);
	
	bool out = ImGui::BeginTabBar(str_id, flags);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  only call EndTabBar() if BeginTabBar() returns true! */
void w_EndTabBar(WrenVM *vm)
{
	ImGui::EndTabBar();
	
}

/*  create a Tab. Returns true if the Tab is selected. */
void w_BeginTabItem(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto p_open = static_cast<bool>(Box::getCPP<bool>(vm, 2));
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiTabItemFlags>(getImGuiTabItemFlagsFromString, vm, 3);
	
	bool out = ImGui::BeginTabItem(label, &p_open, flags);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<bool>(vm, 2, p_open);
}

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

void w_DockSpace(WrenVM *vm)
{
	auto id = static_cast<ImGuiID>(wrenExGetSlot<int>(vm, 1));
	auto size = wrenExIsSlotDefault(vm, 2) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 2);
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiDockNodeFlags>(getImGuiDockNodeFlagsFromString, vm, 3);
	const ImGuiWindowClass* window_class = NULL; // skipping
	
	ImGui::DockSpace(id, size, flags, window_class);
	
}

void w_DockSpaceOverViewport(WrenVM *vm)
{
	ImGuiViewport* viewport = NULL; // skipping
	auto flags = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlotFlags<ImGuiDockNodeFlags>(getImGuiDockNodeFlagsFromString, vm, 1);
	const ImGuiWindowClass* window_class = NULL; // skipping
	
	ImGuiID out = ImGui::DockSpaceOverViewport(viewport, flags, window_class);
	wrenSetSlotDouble(vm, 0, out);
	
}

/*  set next window dock id (FIXME-DOCK) */
void w_SetNextWindowDockID(WrenVM *vm)
{
	auto dock_id = static_cast<ImGuiID>(wrenExGetSlot<int>(vm, 1));
	auto cond = wrenExIsSlotDefault(vm, 2) ? 0 : wrenExGetSlotEnum<ImGuiCond>(getImGuiCondFromString, vm, 2);
	
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
	auto auto_open_depth = wrenExIsSlotDefault(vm, 1) ? -1 : wrenExGetSlot<int>(vm, 1);
	
	ImGui::LogToTTY(auto_open_depth);
	
}

/*  start logging to file */
void w_LogToFile(WrenVM *vm)
{
	auto auto_open_depth = wrenExIsSlotDefault(vm, 1) ? -1 : wrenExGetSlot<int>(vm, 1);
	auto filename = wrenExIsSlotDefault(vm, 2) ? NULL : wrenGetSlotString(vm, 2);
	
	ImGui::LogToFile(auto_open_depth, filename);
	
}

/*  start logging to OS clipboard */
void w_LogToClipboard(WrenVM *vm)
{
	auto auto_open_depth = wrenExIsSlotDefault(vm, 1) ? -1 : wrenExGetSlot<int>(vm, 1);
	
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
	auto flags = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlotFlags<ImGuiDragDropFlags>(getImGuiDragDropFlagsFromString, vm, 1);
	
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

void w_PushClipRect(WrenVM *vm)
{
	auto clip_rect_min = WrapImVec2::getSlot(vm, 1);
	auto clip_rect_max = WrapImVec2::getSlot(vm, 2);
	auto intersect_with_current_clip_rect = wrenExGetSlot<bool>(vm, 3);
	
	ImGui::PushClipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect);
	
}

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
	auto offset = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlot<int>(vm, 1);
	
	ImGui::SetKeyboardFocusHere(offset);
	
}

/*  is the last item hovered? (and usable, aka not blocked by a popup, etc.). See ImGuiHoveredFlags for more options. */
void w_IsItemHovered(WrenVM *vm)
{
	auto flags = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlotFlags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, vm, 1);
	
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
	auto mouse_button = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	
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

/*  get upper-left bounding rectangle of the last item (screen space) */
void w_GetItemRectMin(WrenVM *vm)
{
	ImVec2 out = ImGui::GetItemRectMin();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  get lower-right bounding rectangle of the last item (screen space) */
void w_GetItemRectMax(WrenVM *vm)
{
	ImVec2 out = ImGui::GetItemRectMax();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  get size of last item */
void w_GetItemRectSize(WrenVM *vm)
{
	ImVec2 out = ImGui::GetItemRectSize();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  allow last item to be overlapped by a subsequent item. sometimes useful with invisible buttons, selectables, etc. to catch unused area. */
void w_SetItemAllowOverlap(WrenVM *vm)
{
	ImGui::SetItemAllowOverlap();
	
}

/*  test if rectangle (of given size, starting from cursor position) is visible / not clipped. */
void w_IsRectVisible_Override1(WrenVM *vm)
{
	auto size = WrapImVec2::getSlot(vm, 1);
	
	bool out = ImGui::IsRectVisible(size);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  test if rectangle (in screen space) is visible / not clipped. to perform coarse clipping on user's side. */
void w_IsRectVisible_Override2(WrenVM *vm)
{
	auto rect_min = WrapImVec2::getSlot(vm, 1);
	auto rect_max = WrapImVec2::getSlot(vm, 2);
	
	bool out = ImGui::IsRectVisible(rect_min, rect_max);
	wrenSetSlotBool(vm, 0, out);
	
}

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

/*  calculate coarse clipping for large list of evenly sized items. Prefer using the ImGuiListClipper higher-level helper if you can. */
void w_CalcListClipping(WrenVM *vm)
{
	auto items_count = wrenExGetSlot<int>(vm, 1);
	auto items_height = wrenExGetSlot<float>(vm, 2);
	auto out_items_display_start = static_cast<int>(Box::getCPP<double>(vm, 3));
	auto out_items_display_end = static_cast<int>(Box::getCPP<double>(vm, 4));
	
	ImGui::CalcListClipping(items_count, items_height, &out_items_display_start, &out_items_display_end);
	
	Box::setCPP<double>(vm, 3, out_items_display_start);
	Box::setCPP<double>(vm, 4, out_items_display_end);
}

/*  helper to create a child window / scrolling region that looks like a normal widget frame */
void w_BeginChildFrame(WrenVM *vm)
{
	auto id = static_cast<ImGuiID>(wrenExGetSlot<int>(vm, 1));
	auto size = WrapImVec2::getSlot(vm, 2);
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, vm, 3);
	
	bool out = ImGui::BeginChildFrame(id, size, flags);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  always call EndChildFrame() regardless of BeginChildFrame() return values (which indicates a collapsed/clipped window) */
void w_EndChildFrame(WrenVM *vm)
{
	ImGui::EndChildFrame();
	
}

void w_CalcTextSize(WrenVM *vm)
{
	auto text = wrenGetSlotString(vm, 1);
	auto text_end = wrenExIsSlotDefault(vm, 2) ? NULL : wrenGetSlotString(vm, 2);
	auto hide_text_after_double_hash = wrenExIsSlotDefault(vm, 3) ? false : wrenExGetSlot<bool>(vm, 3);
	auto wrap_width = wrenExIsSlotDefault(vm, 4) ? -1.0f : wrenExGetSlot<float>(vm, 4);
	
	ImVec2 out = ImGui::CalcTextSize(text, text_end, hide_text_after_double_hash, wrap_width);
	WrapImVec2::setSlot(vm, 0, out);
	
}

void w_ColorConvertU32ToFloat4(WrenVM *vm)
{
	auto in = static_cast<ImU32>(wrenExGetSlot<unsigned int>(vm, 1));
	
	ImVec4 out = ImGui::ColorConvertU32ToFloat4(in);
	WrapImVec4::setSlot(vm, 0, out);
	
}

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
	auto user_key_index = wrenExGetSlot<int>(vm, 1);
	
	bool out = ImGui::IsKeyDown(user_key_index);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  was key pressed (went from !Down to Down)? if repeat=true, uses io.KeyRepeatDelay / KeyRepeatRate */
void w_IsKeyPressed(WrenVM *vm)
{
	auto user_key_index = wrenExGetSlot<int>(vm, 1);
	auto repeat = wrenExIsSlotDefault(vm, 2) ? true : wrenExGetSlot<bool>(vm, 2);
	
	bool out = ImGui::IsKeyPressed(user_key_index, repeat);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  was key released (went from Down to !Down)? */
void w_IsKeyReleased(WrenVM *vm)
{
	auto user_key_index = wrenExGetSlot<int>(vm, 1);
	
	bool out = ImGui::IsKeyReleased(user_key_index);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  uses provided repeat rate/delay. return a count, most often 0 or 1 but might be >1 if RepeatRate is small enough that DeltaTime > RepeatRate */
void w_GetKeyPressedAmount(WrenVM *vm)
{
	auto key_index = wrenExGetSlot<int>(vm, 1);
	auto repeat_delay = wrenExGetSlot<float>(vm, 2);
	auto rate = wrenExGetSlot<float>(vm, 3);
	
	int out = ImGui::GetKeyPressedAmount(key_index, repeat_delay, rate);
	wrenSetSlotDouble(vm, 0, out);
	
}

/*  attention: misleading name! manually override io.WantCaptureKeyboard flag next frame (said flag is entirely left for your application to handle). e.g. force capture keyboard when your widget is being hovered. This is equivalent to setting "io.WantCaptureKeyboard = want_capture_keyboard_value"; after the next NewFrame() call. */
void w_CaptureKeyboardFromApp(WrenVM *vm)
{
	auto want_capture_keyboard_value = wrenExIsSlotDefault(vm, 1) ? true : wrenExGetSlot<bool>(vm, 1);
	
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
	auto repeat = wrenExIsSlotDefault(vm, 2) ? false : wrenExGetSlot<bool>(vm, 2);
	
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

/*  is mouse hovering given bounding rect (in screen space). clipped by current clipping settings, but disregarding of other consideration of focus/window ordering/popup-block. */
void w_IsMouseHoveringRect(WrenVM *vm)
{
	auto r_min = WrapImVec2::getSlot(vm, 1);
	auto r_max = WrapImVec2::getSlot(vm, 2);
	auto clip = wrenExIsSlotDefault(vm, 3) ? true : wrenExGetSlot<bool>(vm, 3);
	
	bool out = ImGui::IsMouseHoveringRect(r_min, r_max, clip);
	wrenSetSlotBool(vm, 0, out);
	
}

// skipping w_IsMousePosValid due to unimplemented argument type: "const ImVec2*"

/*  is any mouse button held? */
void w_IsAnyMouseDown(WrenVM *vm)
{
	bool out = ImGui::IsAnyMouseDown();
	wrenSetSlotBool(vm, 0, out);
	
}

/*  shortcut to ImGui::GetIO().MousePos provided by user, to be consistent with other calls */
void w_GetMousePos(WrenVM *vm)
{
	ImVec2 out = ImGui::GetMousePos();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  retrieve mouse position at the time of opening popup we have BeginPopup() into (helper to avoid user backing that value themselves) */
void w_GetMousePosOnOpeningCurrentPopup(WrenVM *vm)
{
	ImVec2 out = ImGui::GetMousePosOnOpeningCurrentPopup();
	WrapImVec2::setSlot(vm, 0, out);
	
}

/*  is mouse dragging? (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold) */
void w_IsMouseDragging(WrenVM *vm)
{
	auto button = wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	auto lock_threshold = wrenExIsSlotDefault(vm, 2) ? -1.0f : wrenExGetSlot<float>(vm, 2);
	
	bool out = ImGui::IsMouseDragging(button, lock_threshold);
	wrenSetSlotBool(vm, 0, out);
	
}

/*  return the delta from the initial clicking position while the mouse button is pressed or was just released. This is locked and return 0.0f until the mouse moves past a distance threshold at least once (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold) */
void w_GetMouseDragDelta(WrenVM *vm)
{
	auto button = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	auto lock_threshold = wrenExIsSlotDefault(vm, 2) ? -1.0f : wrenExGetSlot<float>(vm, 2);
	
	ImVec2 out = ImGui::GetMouseDragDelta(button, lock_threshold);
	WrapImVec2::setSlot(vm, 0, out);
	
}

void w_ResetMouseDragDelta(WrenVM *vm)
{
	auto button = wrenExIsSlotDefault(vm, 1) ? 0 : wrenExGetSlotEnum<ImGuiMouseButton>(getImGuiMouseButtonFromString, vm, 1);
	
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
	auto want_capture_mouse_value = wrenExIsSlotDefault(vm, 1) ? true : wrenExGetSlot<bool>(vm, 1);
	
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

void w_InputText_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto str = static_cast<std::string>(Box::getCPP<std::string>(vm, 2));
	auto flags = wrenExIsSlotDefault(vm, 3) ? 0 : wrenExGetSlotFlags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, vm, 3);
	ImGuiInputTextCallback callback = nullptr; // TODO
	void* user_data = nullptr;
	
	bool out = ImGui::InputText(label, &str, flags, callback, user_data);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<std::string>(vm, 2, str);
}

void w_InputTextMultiline_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto str = static_cast<std::string>(Box::getCPP<std::string>(vm, 2));
	auto size = wrenExIsSlotDefault(vm, 3) ? ImVec2(0, 0) : WrapImVec2::getSlot(vm, 3);
	auto flags = wrenExIsSlotDefault(vm, 4) ? 0 : wrenExGetSlotFlags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, vm, 4);
	ImGuiInputTextCallback callback = nullptr; // TODO
	void* user_data = nullptr;
	
	bool out = ImGui::InputTextMultiline(label, &str, size, flags, callback, user_data);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<std::string>(vm, 2, str);
}

void w_InputTextWithHint_Override2(WrenVM *vm)
{
	auto label = wrenGetSlotString(vm, 1);
	auto hint = wrenGetSlotString(vm, 2);
	auto str = static_cast<std::string>(Box::getCPP<std::string>(vm, 3));
	auto flags = wrenExIsSlotDefault(vm, 4) ? 0 : wrenExGetSlotFlags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, vm, 4);
	ImGuiInputTextCallback callback = nullptr; // TODO
	void* user_data = nullptr;
	
	bool out = ImGui::InputTextWithHint(label, hint, &str, flags, callback, user_data);
	wrenSetSlotBool(vm, 0, out);
	
	Box::setCPP<std::string>(vm, 3, str);
}

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

// skipping w_ImDrawList_PrimReserve due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PrimUnreserve due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList_PrimRect due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList__ResetForNewFrame due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList__ClearFreeMemory due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList__PopUnusedDrawCmd due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList__OnChangedClipRect due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList__OnChangedTextureID due to unimplemented foreign class type: "ImDrawList"

// skipping w_ImDrawList__OnChangedVtxOffset due to unimplemented foreign class type: "ImDrawList"

// End Functions }}}

// {{{ Function overrides
// }}}

const std::unordered_map<std::string, WrenForeignClassMethods> foreignAllocators = {
{"Box", {Box::alloc, Box::finalize}},
{"ImVec2", {WrapImVec2::alloc, WrapImVec2::finalize}},
{"ImVec4", {WrapImVec4::alloc, WrapImVec4::finalize}},
};

const std::unordered_map<std::string, WrenForeignMethodFn> foreignMethods = {
{"Box::init new(_)", Box::init},
{"Box::value", Box::get},
{"Box::value=(_)", Box::set},

{"ImVec2::init new(_,_)", WrapImVec2::init},
{"ImVec2::x", WrapImVec2::getX},
{"ImVec2::x=(_)", WrapImVec2::setX},
{"ImVec2::y", WrapImVec2::getY},
{"ImVec2::y=(_)", WrapImVec2::setY},

{"ImVec4::init new(_,_,_,_)", WrapImVec4::init},
{"ImVec4::x", WrapImVec4::getX},
{"ImVec4::x=(_)", WrapImVec4::setX},
{"ImVec4::y", WrapImVec4::getY},
{"ImVec4::y=(_)", WrapImVec4::setY},
{"ImVec4::z", WrapImVec4::getZ},
{"ImVec4::z=(_)", WrapImVec4::setZ},
{"ImVec4::w", WrapImVec4::getW},
{"ImVec4::w=(_)", WrapImVec4::setW},

{"ImGui::AlignTextToFramePadding()", w_AlignTextToFramePadding},
{"ImGui::ArrowButton(_,_)", w_ArrowButton},
{"ImGui::Begin(_)", w_Begin},
{"ImGui::Begin(_,_)", w_Begin},
{"ImGui::Begin(_,_,_)", w_Begin},
{"ImGui::BeginChildFrame(_,_)", w_BeginChildFrame},
{"ImGui::BeginChildFrame(_,_,_)", w_BeginChildFrame},
{"ImGui::BeginCombo(_,_)", w_BeginCombo},
{"ImGui::BeginCombo(_,_,_)", w_BeginCombo},
{"ImGui::BeginDragDropSource()", w_BeginDragDropSource},
{"ImGui::BeginDragDropSource(_)", w_BeginDragDropSource},
{"ImGui::BeginDragDropTarget()", w_BeginDragDropTarget},
{"ImGui::BeginGroup()", w_BeginGroup},
{"ImGui::BeginMainMenuBar()", w_BeginMainMenuBar},
{"ImGui::BeginMenu(_)", w_BeginMenu},
{"ImGui::BeginMenu(_,_)", w_BeginMenu},
{"ImGui::BeginMenuBar()", w_BeginMenuBar},
{"ImGui::BeginPopup(_)", w_BeginPopup},
{"ImGui::BeginPopup(_,_)", w_BeginPopup},
{"ImGui::BeginPopupContextItem()", w_BeginPopupContextItem},
{"ImGui::BeginPopupContextItem(_)", w_BeginPopupContextItem},
{"ImGui::BeginPopupContextItem(_,_)", w_BeginPopupContextItem},
{"ImGui::BeginPopupContextVoid()", w_BeginPopupContextVoid},
{"ImGui::BeginPopupContextVoid(_)", w_BeginPopupContextVoid},
{"ImGui::BeginPopupContextVoid(_,_)", w_BeginPopupContextVoid},
{"ImGui::BeginPopupContextWindow()", w_BeginPopupContextWindow},
{"ImGui::BeginPopupContextWindow(_)", w_BeginPopupContextWindow},
{"ImGui::BeginPopupContextWindow(_,_)", w_BeginPopupContextWindow},
{"ImGui::BeginPopupContextWindow(_,_,_)", w_BeginPopupContextWindow},
{"ImGui::BeginPopupModal(_)", w_BeginPopupModal},
{"ImGui::BeginPopupModal(_,_)", w_BeginPopupModal},
{"ImGui::BeginPopupModal(_,_,_)", w_BeginPopupModal},
{"ImGui::BeginTabBar(_)", w_BeginTabBar},
{"ImGui::BeginTabBar(_,_)", w_BeginTabBar},
{"ImGui::BeginTabItem(_)", w_BeginTabItem},
{"ImGui::BeginTabItem(_,_)", w_BeginTabItem},
{"ImGui::BeginTabItem(_,_,_)", w_BeginTabItem},
{"ImGui::BeginTooltip()", w_BeginTooltip},
{"ImGui::Bullet()", w_Bullet},
{"ImGui::BulletText(_)", w_BulletText},
{"ImGui::Button(_)", w_Button},
{"ImGui::Button(_,_)", w_Button},
{"ImGui::CalcItemWidth()", w_CalcItemWidth},
{"ImGui::CalcListClipping(_,_,_,_)", w_CalcListClipping},
{"ImGui::CalcTextSize(_)", w_CalcTextSize},
{"ImGui::CalcTextSize(_,_)", w_CalcTextSize},
{"ImGui::CalcTextSize(_,_,_)", w_CalcTextSize},
{"ImGui::CalcTextSize(_,_,_,_)", w_CalcTextSize},
{"ImGui::CaptureKeyboardFromApp()", w_CaptureKeyboardFromApp},
{"ImGui::CaptureKeyboardFromApp(_)", w_CaptureKeyboardFromApp},
{"ImGui::CaptureMouseFromApp()", w_CaptureMouseFromApp},
{"ImGui::CaptureMouseFromApp(_)", w_CaptureMouseFromApp},
{"ImGui::Checkbox(_,_)", w_Checkbox},
{"ImGui::CheckboxFlags(_,_,_)", w_CheckboxFlags},
{"ImGui::CloseCurrentPopup()", w_CloseCurrentPopup},
{"ImGui::ColorButton(_,_)", w_ColorButton},
{"ImGui::ColorButton(_,_,_)", w_ColorButton},
{"ImGui::ColorButton(_,_,_,_)", w_ColorButton},
{"ImGui::ColorConvertU32ToFloat4(_)", w_ColorConvertU32ToFloat4},
{"ImGui::Columns()", w_Columns},
{"ImGui::Columns(_)", w_Columns},
{"ImGui::Columns(_,_)", w_Columns},
{"ImGui::Columns(_,_,_)", w_Columns},
{"ImGui::DestroyPlatformWindows()", w_DestroyPlatformWindows},
{"ImGui::DockSpace(_)", w_DockSpace},
{"ImGui::DockSpace(_,_)", w_DockSpace},
{"ImGui::DockSpace(_,_,_)", w_DockSpace},
{"ImGui::DockSpace(_,_,_,_)", w_DockSpace},
{"ImGui::DockSpaceOverViewport()", w_DockSpaceOverViewport},
{"ImGui::DockSpaceOverViewport(_)", w_DockSpaceOverViewport},
{"ImGui::DockSpaceOverViewport(_,_)", w_DockSpaceOverViewport},
{"ImGui::DockSpaceOverViewport(_,_,_)", w_DockSpaceOverViewport},
{"ImGui::DragFloat(_,_)", w_DragFloat},
{"ImGui::DragFloat(_,_,_)", w_DragFloat},
{"ImGui::DragFloat(_,_,_,_)", w_DragFloat},
{"ImGui::DragFloat(_,_,_,_,_)", w_DragFloat},
{"ImGui::DragFloat(_,_,_,_,_,_)", w_DragFloat},
{"ImGui::DragFloat(_,_,_,_,_,_,_)", w_DragFloat},
{"ImGui::DragFloatRange2(_,_,_)", w_DragFloatRange2},
{"ImGui::DragFloatRange2(_,_,_,_)", w_DragFloatRange2},
{"ImGui::DragFloatRange2(_,_,_,_,_)", w_DragFloatRange2},
{"ImGui::DragFloatRange2(_,_,_,_,_,_)", w_DragFloatRange2},
{"ImGui::DragFloatRange2(_,_,_,_,_,_,_)", w_DragFloatRange2},
{"ImGui::DragFloatRange2(_,_,_,_,_,_,_,_)", w_DragFloatRange2},
{"ImGui::DragFloatRange2(_,_,_,_,_,_,_,_,_)", w_DragFloatRange2},
{"ImGui::DragInt(_,_)", w_DragInt},
{"ImGui::DragInt(_,_,_)", w_DragInt},
{"ImGui::DragInt(_,_,_,_)", w_DragInt},
{"ImGui::DragInt(_,_,_,_,_)", w_DragInt},
{"ImGui::DragInt(_,_,_,_,_,_)", w_DragInt},
{"ImGui::DragIntRange2(_,_,_)", w_DragIntRange2},
{"ImGui::DragIntRange2(_,_,_,_)", w_DragIntRange2},
{"ImGui::DragIntRange2(_,_,_,_,_)", w_DragIntRange2},
{"ImGui::DragIntRange2(_,_,_,_,_,_)", w_DragIntRange2},
{"ImGui::DragIntRange2(_,_,_,_,_,_,_)", w_DragIntRange2},
{"ImGui::DragIntRange2(_,_,_,_,_,_,_,_)", w_DragIntRange2},
{"ImGui::Dummy(_)", w_Dummy},
{"ImGui::End()", w_End},
{"ImGui::EndChild()", w_EndChild},
{"ImGui::EndChildFrame()", w_EndChildFrame},
{"ImGui::EndCombo()", w_EndCombo},
{"ImGui::EndDragDropSource()", w_EndDragDropSource},
{"ImGui::EndDragDropTarget()", w_EndDragDropTarget},
{"ImGui::EndFrame()", w_EndFrame},
{"ImGui::EndGroup()", w_EndGroup},
{"ImGui::EndMainMenuBar()", w_EndMainMenuBar},
{"ImGui::EndMenu()", w_EndMenu},
{"ImGui::EndMenuBar()", w_EndMenuBar},
{"ImGui::EndPopup()", w_EndPopup},
{"ImGui::EndTabBar()", w_EndTabBar},
{"ImGui::EndTabItem()", w_EndTabItem},
{"ImGui::EndTooltip()", w_EndTooltip},
{"ImGui::GetClipboardText()", w_GetClipboardText},
{"ImGui::GetColumnIndex()", w_GetColumnIndex},
{"ImGui::GetColumnOffset()", w_GetColumnOffset},
{"ImGui::GetColumnOffset(_)", w_GetColumnOffset},
{"ImGui::GetColumnWidth()", w_GetColumnWidth},
{"ImGui::GetColumnWidth(_)", w_GetColumnWidth},
{"ImGui::GetColumnsCount()", w_GetColumnsCount},
{"ImGui::GetContentRegionAvail()", w_GetContentRegionAvail},
{"ImGui::GetContentRegionMax()", w_GetContentRegionMax},
{"ImGui::GetCursorPos()", w_GetCursorPos},
{"ImGui::GetCursorPosX()", w_GetCursorPosX},
{"ImGui::GetCursorPosY()", w_GetCursorPosY},
{"ImGui::GetCursorScreenPos()", w_GetCursorScreenPos},
{"ImGui::GetCursorStartPos()", w_GetCursorStartPos},
{"ImGui::GetFontSize()", w_GetFontSize},
{"ImGui::GetFontTexUvWhitePixel()", w_GetFontTexUvWhitePixel},
{"ImGui::GetFrameCount()", w_GetFrameCount},
{"ImGui::GetFrameHeight()", w_GetFrameHeight},
{"ImGui::GetFrameHeightWithSpacing()", w_GetFrameHeightWithSpacing},
{"ImGui::GetItemRectMax()", w_GetItemRectMax},
{"ImGui::GetItemRectMin()", w_GetItemRectMin},
{"ImGui::GetItemRectSize()", w_GetItemRectSize},
{"ImGui::GetKeyIndex(_)", w_GetKeyIndex},
{"ImGui::GetKeyPressedAmount(_,_,_)", w_GetKeyPressedAmount},
{"ImGui::GetMouseCursor()", w_GetMouseCursor},
{"ImGui::GetMouseDragDelta()", w_GetMouseDragDelta},
{"ImGui::GetMouseDragDelta(_)", w_GetMouseDragDelta},
{"ImGui::GetMouseDragDelta(_,_)", w_GetMouseDragDelta},
{"ImGui::GetMousePos()", w_GetMousePos},
{"ImGui::GetMousePosOnOpeningCurrentPopup()", w_GetMousePosOnOpeningCurrentPopup},
{"ImGui::GetScrollMaxX()", w_GetScrollMaxX},
{"ImGui::GetScrollMaxY()", w_GetScrollMaxY},
{"ImGui::GetScrollX()", w_GetScrollX},
{"ImGui::GetScrollY()", w_GetScrollY},
{"ImGui::GetStyleColorName(_)", w_GetStyleColorName},
{"ImGui::GetStyleColorVec4(_)", w_GetStyleColorVec4},
{"ImGui::GetTextLineHeight()", w_GetTextLineHeight},
{"ImGui::GetTextLineHeightWithSpacing()", w_GetTextLineHeightWithSpacing},
{"ImGui::GetTime()", w_GetTime},
{"ImGui::GetTreeNodeToLabelSpacing()", w_GetTreeNodeToLabelSpacing},
{"ImGui::GetVersion()", w_GetVersion},
{"ImGui::GetWindowContentRegionMax()", w_GetWindowContentRegionMax},
{"ImGui::GetWindowContentRegionMin()", w_GetWindowContentRegionMin},
{"ImGui::GetWindowContentRegionWidth()", w_GetWindowContentRegionWidth},
{"ImGui::GetWindowDockID()", w_GetWindowDockID},
{"ImGui::GetWindowDpiScale()", w_GetWindowDpiScale},
{"ImGui::GetWindowHeight()", w_GetWindowHeight},
{"ImGui::GetWindowPos()", w_GetWindowPos},
{"ImGui::GetWindowSize()", w_GetWindowSize},
{"ImGui::GetWindowWidth()", w_GetWindowWidth},
{"ImGui::Indent()", w_Indent},
{"ImGui::Indent(_)", w_Indent},
{"ImGui::InputDouble(_,_)", w_InputDouble},
{"ImGui::InputDouble(_,_,_)", w_InputDouble},
{"ImGui::InputDouble(_,_,_,_)", w_InputDouble},
{"ImGui::InputDouble(_,_,_,_,_)", w_InputDouble},
{"ImGui::InputDouble(_,_,_,_,_,_)", w_InputDouble},
{"ImGui::InputFloat(_,_)", w_InputFloat},
{"ImGui::InputFloat(_,_,_)", w_InputFloat},
{"ImGui::InputFloat(_,_,_,_)", w_InputFloat},
{"ImGui::InputFloat(_,_,_,_,_)", w_InputFloat},
{"ImGui::InputFloat(_,_,_,_,_,_)", w_InputFloat},
{"ImGui::InputInt(_,_)", w_InputInt},
{"ImGui::InputInt(_,_,_)", w_InputInt},
{"ImGui::InputInt(_,_,_,_)", w_InputInt},
{"ImGui::InputInt(_,_,_,_,_)", w_InputInt},
{"ImGui::InvisibleButton(_,_)", w_InvisibleButton},
{"ImGui::IsAnyItemActive()", w_IsAnyItemActive},
{"ImGui::IsAnyItemFocused()", w_IsAnyItemFocused},
{"ImGui::IsAnyItemHovered()", w_IsAnyItemHovered},
{"ImGui::IsAnyMouseDown()", w_IsAnyMouseDown},
{"ImGui::IsItemActivated()", w_IsItemActivated},
{"ImGui::IsItemActive()", w_IsItemActive},
{"ImGui::IsItemClicked()", w_IsItemClicked},
{"ImGui::IsItemClicked(_)", w_IsItemClicked},
{"ImGui::IsItemDeactivated()", w_IsItemDeactivated},
{"ImGui::IsItemDeactivatedAfterEdit()", w_IsItemDeactivatedAfterEdit},
{"ImGui::IsItemEdited()", w_IsItemEdited},
{"ImGui::IsItemFocused()", w_IsItemFocused},
{"ImGui::IsItemHovered()", w_IsItemHovered},
{"ImGui::IsItemHovered(_)", w_IsItemHovered},
{"ImGui::IsItemToggledOpen()", w_IsItemToggledOpen},
{"ImGui::IsItemVisible()", w_IsItemVisible},
{"ImGui::IsKeyDown(_)", w_IsKeyDown},
{"ImGui::IsKeyPressed(_)", w_IsKeyPressed},
{"ImGui::IsKeyPressed(_,_)", w_IsKeyPressed},
{"ImGui::IsKeyReleased(_)", w_IsKeyReleased},
{"ImGui::IsMouseClicked(_)", w_IsMouseClicked},
{"ImGui::IsMouseClicked(_,_)", w_IsMouseClicked},
{"ImGui::IsMouseDoubleClicked(_)", w_IsMouseDoubleClicked},
{"ImGui::IsMouseDown(_)", w_IsMouseDown},
{"ImGui::IsMouseDragging(_)", w_IsMouseDragging},
{"ImGui::IsMouseDragging(_,_)", w_IsMouseDragging},
{"ImGui::IsMouseHoveringRect(_,_)", w_IsMouseHoveringRect},
{"ImGui::IsMouseHoveringRect(_,_,_)", w_IsMouseHoveringRect},
{"ImGui::IsMouseReleased(_)", w_IsMouseReleased},
{"ImGui::IsPopupOpen(_)", w_IsPopupOpen},
{"ImGui::IsWindowAppearing()", w_IsWindowAppearing},
{"ImGui::IsWindowCollapsed()", w_IsWindowCollapsed},
{"ImGui::IsWindowDocked()", w_IsWindowDocked},
{"ImGui::IsWindowFocused()", w_IsWindowFocused},
{"ImGui::IsWindowFocused(_)", w_IsWindowFocused},
{"ImGui::IsWindowHovered()", w_IsWindowHovered},
{"ImGui::IsWindowHovered(_)", w_IsWindowHovered},
{"ImGui::LabelText(_,_)", w_LabelText},
{"ImGui::ListBoxFooter()", w_ListBoxFooter},
{"ImGui::LoadIniSettingsFromDisk(_)", w_LoadIniSettingsFromDisk},
{"ImGui::LogButtons()", w_LogButtons},
{"ImGui::LogFinish()", w_LogFinish},
{"ImGui::LogText(_)", w_LogText},
{"ImGui::LogToClipboard()", w_LogToClipboard},
{"ImGui::LogToClipboard(_)", w_LogToClipboard},
{"ImGui::LogToFile()", w_LogToFile},
{"ImGui::LogToFile(_)", w_LogToFile},
{"ImGui::LogToFile(_,_)", w_LogToFile},
{"ImGui::LogToTTY()", w_LogToTTY},
{"ImGui::LogToTTY(_)", w_LogToTTY},
{"ImGui::NewFrame()", w_NewFrame},
{"ImGui::NewLine()", w_NewLine},
{"ImGui::NextColumn()", w_NextColumn},
{"ImGui::OpenPopup(_)", w_OpenPopup},
{"ImGui::OpenPopupOnItemClick()", w_OpenPopupOnItemClick},
{"ImGui::OpenPopupOnItemClick(_)", w_OpenPopupOnItemClick},
{"ImGui::OpenPopupOnItemClick(_,_)", w_OpenPopupOnItemClick},
{"ImGui::PopAllowKeyboardFocus()", w_PopAllowKeyboardFocus},
{"ImGui::PopButtonRepeat()", w_PopButtonRepeat},
{"ImGui::PopClipRect()", w_PopClipRect},
{"ImGui::PopFont()", w_PopFont},
{"ImGui::PopID()", w_PopID},
{"ImGui::PopItemWidth()", w_PopItemWidth},
{"ImGui::PopStyleColor()", w_PopStyleColor},
{"ImGui::PopStyleColor(_)", w_PopStyleColor},
{"ImGui::PopStyleVar()", w_PopStyleVar},
{"ImGui::PopStyleVar(_)", w_PopStyleVar},
{"ImGui::PopTextWrapPos()", w_PopTextWrapPos},
{"ImGui::ProgressBar(_)", w_ProgressBar},
{"ImGui::ProgressBar(_,_)", w_ProgressBar},
{"ImGui::ProgressBar(_,_,_)", w_ProgressBar},
{"ImGui::PushAllowKeyboardFocus(_)", w_PushAllowKeyboardFocus},
{"ImGui::PushButtonRepeat(_)", w_PushButtonRepeat},
{"ImGui::PushClipRect(_,_,_)", w_PushClipRect},
{"ImGui::PushItemWidth(_)", w_PushItemWidth},
{"ImGui::PushTextWrapPos()", w_PushTextWrapPos},
{"ImGui::PushTextWrapPos(_)", w_PushTextWrapPos},
{"ImGui::Render()", w_Render},
{"ImGui::ResetMouseDragDelta()", w_ResetMouseDragDelta},
{"ImGui::ResetMouseDragDelta(_)", w_ResetMouseDragDelta},
{"ImGui::SameLine()", w_SameLine},
{"ImGui::SameLine(_)", w_SameLine},
{"ImGui::SameLine(_,_)", w_SameLine},
{"ImGui::SaveIniSettingsToDisk(_)", w_SaveIniSettingsToDisk},
{"ImGui::Separator()", w_Separator},
{"ImGui::SetClipboardText(_)", w_SetClipboardText},
{"ImGui::SetColorEditOptions(_)", w_SetColorEditOptions},
{"ImGui::SetColumnOffset(_,_)", w_SetColumnOffset},
{"ImGui::SetColumnWidth(_,_)", w_SetColumnWidth},
{"ImGui::SetCursorPos(_)", w_SetCursorPos},
{"ImGui::SetCursorPosX(_)", w_SetCursorPosX},
{"ImGui::SetCursorPosY(_)", w_SetCursorPosY},
{"ImGui::SetCursorScreenPos(_)", w_SetCursorScreenPos},
{"ImGui::SetItemAllowOverlap()", w_SetItemAllowOverlap},
{"ImGui::SetItemDefaultFocus()", w_SetItemDefaultFocus},
{"ImGui::SetKeyboardFocusHere()", w_SetKeyboardFocusHere},
{"ImGui::SetKeyboardFocusHere(_)", w_SetKeyboardFocusHere},
{"ImGui::SetMouseCursor(_)", w_SetMouseCursor},
{"ImGui::SetNextItemOpen(_)", w_SetNextItemOpen},
{"ImGui::SetNextItemOpen(_,_)", w_SetNextItemOpen},
{"ImGui::SetNextItemWidth(_)", w_SetNextItemWidth},
{"ImGui::SetNextWindowBgAlpha(_)", w_SetNextWindowBgAlpha},
{"ImGui::SetNextWindowCollapsed(_)", w_SetNextWindowCollapsed},
{"ImGui::SetNextWindowCollapsed(_,_)", w_SetNextWindowCollapsed},
{"ImGui::SetNextWindowContentSize(_)", w_SetNextWindowContentSize},
{"ImGui::SetNextWindowDockID(_)", w_SetNextWindowDockID},
{"ImGui::SetNextWindowDockID(_,_)", w_SetNextWindowDockID},
{"ImGui::SetNextWindowFocus()", w_SetNextWindowFocus},
{"ImGui::SetNextWindowPos(_)", w_SetNextWindowPos},
{"ImGui::SetNextWindowPos(_,_)", w_SetNextWindowPos},
{"ImGui::SetNextWindowPos(_,_,_)", w_SetNextWindowPos},
{"ImGui::SetNextWindowSize(_)", w_SetNextWindowSize},
{"ImGui::SetNextWindowSize(_,_)", w_SetNextWindowSize},
{"ImGui::SetNextWindowViewport(_)", w_SetNextWindowViewport},
{"ImGui::SetScrollFromPosX(_)", w_SetScrollFromPosX},
{"ImGui::SetScrollFromPosX(_,_)", w_SetScrollFromPosX},
{"ImGui::SetScrollFromPosY(_)", w_SetScrollFromPosY},
{"ImGui::SetScrollFromPosY(_,_)", w_SetScrollFromPosY},
{"ImGui::SetScrollHereX()", w_SetScrollHereX},
{"ImGui::SetScrollHereX(_)", w_SetScrollHereX},
{"ImGui::SetScrollHereY()", w_SetScrollHereY},
{"ImGui::SetScrollHereY(_)", w_SetScrollHereY},
{"ImGui::SetScrollX(_)", w_SetScrollX},
{"ImGui::SetScrollY(_)", w_SetScrollY},
{"ImGui::SetTabItemClosed(_)", w_SetTabItemClosed},
{"ImGui::SetTooltip(_)", w_SetTooltip},
{"ImGui::SetWindowFontScale(_)", w_SetWindowFontScale},
{"ImGui::ShowAboutWindow()", w_ShowAboutWindow},
{"ImGui::ShowAboutWindow(_)", w_ShowAboutWindow},
{"ImGui::ShowDemoWindow()", w_ShowDemoWindow},
{"ImGui::ShowDemoWindow(_)", w_ShowDemoWindow},
{"ImGui::ShowFontSelector(_)", w_ShowFontSelector},
{"ImGui::ShowMetricsWindow()", w_ShowMetricsWindow},
{"ImGui::ShowMetricsWindow(_)", w_ShowMetricsWindow},
{"ImGui::ShowStyleSelector(_)", w_ShowStyleSelector},
{"ImGui::ShowUserGuide()", w_ShowUserGuide},
{"ImGui::SliderAngle(_,_)", w_SliderAngle},
{"ImGui::SliderAngle(_,_,_)", w_SliderAngle},
{"ImGui::SliderAngle(_,_,_,_)", w_SliderAngle},
{"ImGui::SliderAngle(_,_,_,_,_)", w_SliderAngle},
{"ImGui::SliderFloat(_,_,_,_)", w_SliderFloat},
{"ImGui::SliderFloat(_,_,_,_,_)", w_SliderFloat},
{"ImGui::SliderFloat(_,_,_,_,_,_)", w_SliderFloat},
{"ImGui::SliderInt(_,_,_,_)", w_SliderInt},
{"ImGui::SliderInt(_,_,_,_,_)", w_SliderInt},
{"ImGui::SmallButton(_)", w_SmallButton},
{"ImGui::Spacing()", w_Spacing},
{"ImGui::Text(_)", w_Text},
{"ImGui::TextColored(_,_)", w_TextColored},
{"ImGui::TextDisabled(_)", w_TextDisabled},
{"ImGui::TextUnformatted(_)", w_TextUnformatted},
{"ImGui::TextUnformatted(_,_)", w_TextUnformatted},
{"ImGui::TextWrapped(_)", w_TextWrapped},
{"ImGui::TreePop()", w_TreePop},
{"ImGui::Unindent()", w_Unindent},
{"ImGui::Unindent(_)", w_Unindent},
{"ImGui::UpdatePlatformWindows()", w_UpdatePlatformWindows},
{"ImGui::VSliderFloat(_,_,_,_,_)", w_VSliderFloat},
{"ImGui::VSliderFloat(_,_,_,_,_,_)", w_VSliderFloat},
{"ImGui::VSliderFloat(_,_,_,_,_,_,_)", w_VSliderFloat},
{"ImGui::VSliderInt(_,_,_,_,_)", w_VSliderInt},
{"ImGui::VSliderInt(_,_,_,_,_,_)", w_VSliderInt},

{"ImGui::IsRectVisible(_)", w_IsRectVisible_Override1},
{"ImGui::IsRectVisible(_,_)", w_IsRectVisible_Override2},

{"ImGui::InputText(_,_,_,_)", w_InputText_Override2},
{"ImGui::InputText(_,_,_)", w_InputText_Override2},
{"ImGui::InputText(_,_)", w_InputText_Override2},

{"ImGui::InputTextMultiline(_,_,_,_)", w_InputTextMultiline_Override2},
{"ImGui::InputTextMultiline(_,_,_)", w_InputTextMultiline_Override2},
{"ImGui::InputTextMultiline(_,_)", w_InputTextMultiline_Override2},

{"ImGui::InputTextWithHint(_,_,_,_,_)", w_InputTextWithHint_Override2},
{"ImGui::InputTextWithHint(_,_,_,_)", w_InputTextWithHint_Override2},
{"ImGui::InputTextWithHint(_,_,_)", w_InputTextWithHint_Override2},
};

const char* foreignModuleString = R"MODULE(
foreign class Box {
	foreign construct new(v)
	foreign value
	foreign value=(v)
	set(v) {
		this.value = v
		return this
	}
	get() {
		return this.value
	}
}

foreign class ImVec2 {
	foreign construct new(x, y)
	foreign x
	foreign x=(v)
	foreign y
	foreign y=(v)
	set(newX, newY) {
		x = newX
		y = newY
	}
}

foreign class ImVec4 {
	foreign construct new(x, y, z, w)
	construct new(v) { new(v, v, v, v) }
	construct new(x, y, z) { new(x, y, z, 1) }
	foreign x
	foreign x=(v)
	foreign y
	foreign y=(v)
	foreign z
	foreign z=(v)
	foreign w
	foreign w=(v)
	set(newX, newY, newZ, newW) {
		x = newX
		y = newY
		z = newZ
		w = newW
	}
	set(newX, newY, newZ) {
		set(newX, newY, newX, 1)
	}
	set(v) {
		set(v, v, v, v)
	}
}

class ImGui {
	foreign static SetColumnOffset(column_index, offset_x)
	foreign static IsItemDeactivatedAfterEdit()
	foreign static IsMouseDoubleClicked(button)
	foreign static GetTreeNodeToLabelSpacing()
	foreign static SetNextItemOpen(is_open)
	foreign static SetNextItemOpen(is_open, cond)
	foreign static PopTextWrapPos()
	foreign static EndDragDropSource()
	foreign static GetWindowWidth()
	foreign static SetNextWindowCollapsed(collapsed)
	foreign static SetNextWindowCollapsed(collapsed, cond)
	foreign static TextWrapped(fmt)
	foreign static GetStyleColorName(idx)
	foreign static ColorButton(desc_id, col)
	foreign static ColorButton(desc_id, col, flags)
	foreign static ColorButton(desc_id, col, flags, size)
	foreign static SmallButton(label)
	foreign static IsMouseClicked(button)
	foreign static IsMouseClicked(button, repeat)
	foreign static BeginPopupContextWindow()
	foreign static BeginPopupContextWindow(str_id)
	foreign static BeginPopupContextWindow(str_id, mouse_button)
	foreign static BeginPopupContextWindow(str_id, mouse_button, also_over_items)
	foreign static Checkbox(label, v)
	foreign static InputFloat(label, v)
	foreign static InputFloat(label, v, step)
	foreign static InputFloat(label, v, step, step_fast)
	foreign static InputFloat(label, v, step, step_fast, format)
	foreign static InputFloat(label, v, step, step_fast, format, flags)
	foreign static IsMouseDown(button)
	foreign static VSliderInt(label, size, v, v_min, v_max)
	foreign static VSliderInt(label, size, v, v_min, v_max, format)
	foreign static LogFinish()
	foreign static ShowFontSelector(label)
	foreign static SetScrollHereX()
	foreign static SetScrollHereX(center_x_ratio)
	foreign static PushAllowKeyboardFocus(allow_keyboard_focus)
	foreign static PopStyleVar()
	foreign static PopStyleVar(count)
	foreign static SetScrollHereY()
	foreign static SetScrollHereY(center_y_ratio)
	foreign static GetContentRegionMax()
	foreign static IsMouseDragging(button)
	foreign static IsMouseDragging(button, lock_threshold)
	foreign static IsKeyDown(user_key_index)
	foreign static GetColumnIndex()
	foreign static GetColumnOffset()
	foreign static GetColumnOffset(column_index)
	foreign static VSliderFloat(label, size, v, v_min, v_max)
	foreign static VSliderFloat(label, size, v, v_min, v_max, format)
	foreign static VSliderFloat(label, size, v, v_min, v_max, format, power)
	foreign static DockSpace(id)
	foreign static DockSpace(id, size)
	foreign static DockSpace(id, size, flags)
	foreign static DockSpace(id, size, flags, window_class)
	foreign static IsKeyPressed(user_key_index)
	foreign static IsKeyPressed(user_key_index, repeat)
	foreign static GetFontSize()
	foreign static SameLine()
	foreign static SameLine(offset_from_start_x)
	foreign static SameLine(offset_from_start_x, spacing)
	foreign static Begin(name)
	foreign static Begin(name, p_open)
	foreign static Begin(name, p_open, flags)
	foreign static BeginTooltip()
	foreign static BeginMenu(label)
	foreign static BeginMenu(label, enabled)
	foreign static ShowUserGuide()
	foreign static DragFloat(label, v)
	foreign static DragFloat(label, v, v_speed)
	foreign static DragFloat(label, v, v_speed, v_min)
	foreign static DragFloat(label, v, v_speed, v_min, v_max)
	foreign static DragFloat(label, v, v_speed, v_min, v_max, format)
	foreign static DragFloat(label, v, v_speed, v_min, v_max, format, power)
	foreign static BeginChildFrame(id, size)
	foreign static BeginChildFrame(id, size, flags)
	foreign static InputDouble(label, v)
	foreign static InputDouble(label, v, step)
	foreign static InputDouble(label, v, step, step_fast)
	foreign static InputDouble(label, v, step, step_fast, format)
	foreign static InputDouble(label, v, step, step_fast, format, flags)
	foreign static SetColumnWidth(column_index, width)
	foreign static UpdatePlatformWindows()
	foreign static IsWindowHovered()
	foreign static IsWindowHovered(flags)
	foreign static PopFont()
	foreign static ProgressBar(fraction)
	foreign static ProgressBar(fraction, size_arg)
	foreign static ProgressBar(fraction, size_arg, overlay)
	foreign static GetTextLineHeightWithSpacing()
	foreign static BeginTabBar(str_id)
	foreign static BeginTabBar(str_id, flags)
	foreign static GetWindowContentRegionMin()
	foreign static LoadIniSettingsFromDisk(ini_filename)
	foreign static EndGroup()
	foreign static SetClipboardText(text)
	foreign static IsWindowFocused()
	foreign static IsWindowFocused(flags)
	foreign static EndTabBar()
	foreign static Button(label)
	foreign static Button(label, size)
	foreign static BeginTabItem(label)
	foreign static BeginTabItem(label, p_open)
	foreign static BeginTabItem(label, p_open, flags)
	foreign static IsItemEdited()
	foreign static SetCursorPos(local_pos)
	foreign static GetClipboardText()
	foreign static GetMouseDragDelta()
	foreign static GetMouseDragDelta(button)
	foreign static GetMouseDragDelta(button, lock_threshold)
	foreign static GetMousePosOnOpeningCurrentPopup()
	foreign static GetMousePos()
	foreign static IsAnyMouseDown()
	foreign static ListBoxFooter()
	foreign static IsMouseHoveringRect(r_min, r_max)
	foreign static IsMouseHoveringRect(r_min, r_max, clip)
	foreign static DragFloatRange2(label, v_current_min, v_current_max)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max)
	foreign static DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, power)
	foreign static GetVersion()
	foreign static TextUnformatted(text)
	foreign static TextUnformatted(text, text_end)
	foreign static BeginMainMenuBar()
	foreign static IsAnyItemActive()
	foreign static GetKeyPressedAmount(key_index, repeat_delay, rate)
	foreign static IsKeyReleased(user_key_index)
	foreign static EndMenuBar()
	foreign static GetKeyIndex(imgui_key)
	foreign static ColorConvertU32ToFloat4(input)
	foreign static ShowAboutWindow()
	foreign static ShowAboutWindow(p_open)
	foreign static CheckboxFlags(label, flags, flags_value)
	foreign static GetFrameHeight()
	foreign static SetNextWindowFocus()
	foreign static GetWindowPos()
	foreign static DragIntRange2(label, v_current_min, v_current_max)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format)
	foreign static DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max)
	foreign static EndChildFrame()
	foreign static GetScrollY()
	foreign static SetNextWindowPos(pos)
	foreign static SetNextWindowPos(pos, cond)
	foreign static SetNextWindowPos(pos, cond, pivot)
	foreign static BeginPopupModal(name)
	foreign static BeginPopupModal(name, p_open)
	foreign static BeginPopupModal(name, p_open, flags)
	foreign static GetTime()
	foreign static BeginMenuBar()
	foreign static IsWindowDocked()
	foreign static GetFrameHeightWithSpacing()
	foreign static LogToTTY()
	foreign static LogToTTY(auto_open_depth)
	foreign static NextColumn()
	foreign static GetWindowSize()
	foreign static SetItemAllowOverlap()
	foreign static GetWindowHeight()
	foreign static IsWindowAppearing()
	foreign static EndCombo()
	foreign static GetItemRectSize()
	foreign static SetNextWindowSize(size)
	foreign static SetNextWindowSize(size, cond)
	foreign static GetItemRectMax()
	foreign static AlignTextToFramePadding()
	foreign static CloseCurrentPopup()
	foreign static LogToFile()
	foreign static LogToFile(auto_open_depth)
	foreign static LogToFile(auto_open_depth, filename)
	foreign static GetItemRectMin()
	foreign static IsAnyItemFocused()
	foreign static CaptureKeyboardFromApp()
	foreign static CaptureKeyboardFromApp(want_capture_keyboard_value)
	foreign static IsAnyItemHovered()
	foreign static EndFrame()
	foreign static BeginDragDropSource()
	foreign static BeginDragDropSource(flags)
	foreign static GetCursorPosY()
	foreign static IsItemDeactivated()
	foreign static SetCursorPosX(local_x)
	foreign static EndMenu()
	foreign static TextDisabled(fmt)
	foreign static IsItemActivated()
	foreign static Unindent()
	foreign static Unindent(indent_w)
	foreign static IsItemVisible()
	foreign static SetScrollX(scroll_x)
	foreign static IsItemFocused()
	foreign static PopButtonRepeat()
	foreign static IsItemClicked()
	foreign static IsItemClicked(mouse_button)
	foreign static PopAllowKeyboardFocus()
	foreign static SetScrollFromPosX(local_x)
	foreign static SetScrollFromPosX(local_x, center_x_ratio)
	foreign static ResetMouseDragDelta()
	foreign static ResetMouseDragDelta(button)
	foreign static SetWindowFontScale(scale)
	foreign static IsItemHovered()
	foreign static IsItemHovered(flags)
	foreign static SetNextWindowBgAlpha(alpha)
	foreign static ShowStyleSelector(label)
	foreign static SetKeyboardFocusHere()
	foreign static SetKeyboardFocusHere(offset)
	foreign static BeginDragDropTarget()
	foreign static PopClipRect()
	foreign static SetItemDefaultFocus()
	foreign static PushItemWidth(item_width)
	foreign static PushClipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect)
	foreign static LogToClipboard()
	foreign static LogToClipboard(auto_open_depth)
	foreign static IsWindowCollapsed()
	foreign static IsMouseReleased(button)
	foreign static LogButtons()
	foreign static IsItemActive()
	foreign static Spacing()
	foreign static SetNextWindowDockID(dock_id)
	foreign static SetNextWindowDockID(dock_id, cond)
	foreign static NewLine()
	foreign static DockSpaceOverViewport()
	foreign static DockSpaceOverViewport(viewport)
	foreign static DockSpaceOverViewport(viewport, flags)
	foreign static DockSpaceOverViewport(viewport, flags, window_class)
	foreign static SetTabItemClosed(tab_or_docked_window_label)
	foreign static PushButtonRepeat(repeat)
	foreign static GetStyleColorVec4(idx)
	foreign static CalcItemWidth()
	foreign static SetCursorScreenPos(pos)
	foreign static EndChild()
	foreign static CaptureMouseFromApp()
	foreign static CaptureMouseFromApp(want_capture_mouse_value)
	foreign static GetColumnsCount()
	foreign static DestroyPlatformWindows()
	foreign static EndPopup()
	foreign static Columns()
	foreign static Columns(count)
	foreign static Columns(count, id)
	foreign static Columns(count, id, border)
	foreign static IsPopupOpen(str_id)
	foreign static Bullet()
	foreign static EndTooltip()
	foreign static InputInt(label, v)
	foreign static InputInt(label, v, step)
	foreign static InputInt(label, v, step, step_fast)
	foreign static InputInt(label, v, step, step_fast, flags)
	foreign static SliderAngle(label, v_rad)
	foreign static SliderAngle(label, v_rad, v_degrees_min)
	foreign static SliderAngle(label, v_rad, v_degrees_min, v_degrees_max)
	foreign static SliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format)
	foreign static OpenPopupOnItemClick()
	foreign static OpenPopupOnItemClick(str_id)
	foreign static OpenPopupOnItemClick(str_id, mouse_button)
	foreign static SetScrollFromPosY(local_y)
	foreign static SetScrollFromPosY(local_y, center_y_ratio)
	foreign static GetColumnWidth()
	foreign static GetColumnWidth(column_index)
	foreign static PopStyleColor()
	foreign static PopStyleColor(count)
	foreign static GetFrameCount()
	foreign static GetWindowDpiScale()
	foreign static CalcListClipping(items_count, items_height, out_items_display_start, out_items_display_end)
	foreign static GetScrollMaxY()
	foreign static GetCursorScreenPos()
	foreign static EndMainMenuBar()
	foreign static SaveIniSettingsToDisk(ini_filename)
	foreign static BeginPopup(str_id)
	foreign static BeginPopup(str_id, flags)
	foreign static BeginPopupContextItem()
	foreign static BeginPopupContextItem(str_id)
	foreign static BeginPopupContextItem(str_id, mouse_button)
	foreign static GetCursorStartPos()
	foreign static SetTooltip(fmt)
	foreign static GetScrollMaxX()
	foreign static IsItemToggledOpen()
	foreign static GetCursorPosX()
	foreign static PopItemWidth()
	foreign static SetNextWindowContentSize(size)
	foreign static LogText(fmt)
	foreign static SetScrollY(scroll_y)
	foreign static End()
	foreign static SetNextItemWidth(item_width)
	foreign static TreePop()
	foreign static GetWindowContentRegionWidth()
	foreign static GetFontTexUvWhitePixel()
	foreign static PushTextWrapPos()
	foreign static PushTextWrapPos(wrap_local_pos_x)
	foreign static ArrowButton(str_id, dir)
	foreign static BeginPopupContextVoid()
	foreign static BeginPopupContextVoid(str_id)
	foreign static BeginPopupContextVoid(str_id, mouse_button)
	foreign static ShowMetricsWindow()
	foreign static ShowMetricsWindow(p_open)
	foreign static GetWindowDockID()
	foreign static SetCursorPosY(local_y)
	foreign static DragInt(label, v)
	foreign static DragInt(label, v, v_speed)
	foreign static DragInt(label, v, v_speed, v_min)
	foreign static DragInt(label, v, v_speed, v_min, v_max)
	foreign static DragInt(label, v, v_speed, v_min, v_max, format)
	foreign static NewFrame()
	foreign static SetColorEditOptions(flags)
	foreign static GetMouseCursor()
	foreign static PopID()
	foreign static BeginGroup()
	foreign static Indent()
	foreign static Indent(indent_w)
	foreign static SliderInt(label, v, v_min, v_max)
	foreign static SliderInt(label, v, v_min, v_max, format)
	foreign static EndTabItem()
	foreign static Separator()
	foreign static GetTextLineHeight()
	foreign static GetScrollX()
	foreign static OpenPopup(str_id)
	foreign static LabelText(label, fmt)
	foreign static BulletText(fmt)
	foreign static SetMouseCursor(cursor_type)
	foreign static Dummy(size)
	foreign static GetWindowContentRegionMax()
	foreign static CalcTextSize(text)
	foreign static CalcTextSize(text, text_end)
	foreign static CalcTextSize(text, text_end, hide_text_after_double_hash)
	foreign static CalcTextSize(text, text_end, hide_text_after_double_hash, wrap_width)
	foreign static SliderFloat(label, v, v_min, v_max)
	foreign static SliderFloat(label, v, v_min, v_max, format)
	foreign static SliderFloat(label, v, v_min, v_max, format, power)
	foreign static GetContentRegionAvail()
	foreign static BeginCombo(label, preview_value)
	foreign static BeginCombo(label, preview_value, flags)
	foreign static GetCursorPos()
	foreign static SetNextWindowViewport(viewport_id)
	foreign static Render()
	foreign static TextColored(col, fmt)
	foreign static ShowDemoWindow()
	foreign static ShowDemoWindow(p_open)
	foreign static InvisibleButton(str_id, size)
	foreign static EndDragDropTarget()
	foreign static Text(fmt)
}

)MODULE";

}

char* wrap_imgui::loadModule(WrenVM* vm)
{
	char* buf = (char*)malloc(strlen(foreignModuleString));
	strcpy(buf, foreignModuleString);
	return buf;
}

bool wrap_imgui::bindForeignClass(WrenVM* vm, const char* className, WrenForeignClassMethods& methods)
{
	auto pair = foreignAllocators.find(className);

	if(pair != foreignAllocators.end()) {
		const WrenForeignClassMethods& methods2 = pair->second;
		methods.allocate = methods2.allocate;
		methods.finalize = methods2.finalize;
		return true;
	}
	return false;
}

WrenForeignMethodFn wrap_imgui::bindForeignMethod(WrenVM* vm, const char* className, bool isStatic, const char* signature)
{
	char buf[255];
	snprintf(buf, 255, "%s::%s", className, signature);
	auto pair = foreignMethods.find(buf);

	if(pair != foreignMethods.end()) {
		return pair->second;
	}
	return nullptr;
}
