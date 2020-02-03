// This is an automatically generated file!!

#include "wrap_imgui_codegen.h"
#include "libimgui/imgui.h"

#include <optional>
#include <string>
#include <vector>
#include <sstream>

// helpers
bool luax_optboolean(lua_State* L, int narg, bool d)
{
	if(lua_isnoneornil(L, narg)) {
		return d;
	}
	return lua_toboolean(L, narg);
}

bool luax_checkboolean(lua_State* L, int narg)
{
	return lua_toboolean(L, narg);
}

template<typename T, typename U>
T luax_checkenum(U fromString, lua_State* L, int narg)
{
	const char* s = luaL_checkstring(L, narg);
	std::optional<T> opt = fromString(s);
	if(!opt) {
		luaL_error(L, "Invalid enum as argument %d, received \"%s\"", narg, s);
	}
	return *opt;
}

template<typename T, typename U>
T luax_optenum(U fromString, lua_State* L, int narg, T d)
{
	if(!lua_isstring(L, narg)) {
		return d;
	}
	const char* s = lua_tostring(L, narg);
	std::optional<T> opt = fromString(s);
	if(!opt) {
		return d;
	}
	return *opt;
}

template<typename T, typename U>
T luax_checkflags(U fromString, lua_State* L, int narg)
{
	const char* s = luaL_checkstring(L, narg);
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	T out;
	while (std::getline(tokenStream, token, '|')) {
		std::optional<T> opt = fromString(token.c_str());
		if (opt) {
			out = out | *opt;
		}
	}
	return out;
}

template<typename T, typename U>
T luax_optflags(U fromString, lua_State* L, int narg, T d)
{
	if(!lua_isstring(L, narg)) {
		return d;
	}
	const char* s = lua_tostring(L, narg);
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	bool defined = false;
	T out;
	while (std::getline(tokenStream, token, '|')) {
		std::optional<T> opt = fromString(token.c_str());
		if (opt) {
			out = out | *opt;
			defined = true;
		}
	}
	if (defined) {
		return out;
	} else {
		return d;
	}
}

// Enums

std::optional<ImGuiWindowFlags_> getImGuiWindowFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiWindowFlags_None; }
	if (strcmp(in, "NavFlattened") == 0) { return ImGuiWindowFlags_NavFlattened; }
	if (strcmp(in, "ChildMenu") == 0) { return ImGuiWindowFlags_ChildMenu; }
	if (strcmp(in, "NoResize") == 0) { return ImGuiWindowFlags_NoResize; }
	if (strcmp(in, "AlwaysVerticalScrollbar") == 0) { return ImGuiWindowFlags_AlwaysVerticalScrollbar; }
	if (strcmp(in, "MenuBar") == 0) { return ImGuiWindowFlags_MenuBar; }
	if (strcmp(in, "Modal") == 0) { return ImGuiWindowFlags_Modal; }
	if (strcmp(in, "HorizontalScrollbar") == 0) { return ImGuiWindowFlags_HorizontalScrollbar; }
	if (strcmp(in, "Popup") == 0) { return ImGuiWindowFlags_Popup; }
	if (strcmp(in, "NoNavFocus") == 0) { return ImGuiWindowFlags_NoNavFocus; }
	if (strcmp(in, "NoTitleBar") == 0) { return ImGuiWindowFlags_NoTitleBar; }
	if (strcmp(in, "ChildWindow") == 0) { return ImGuiWindowFlags_ChildWindow; }
	if (strcmp(in, "NoCollapse") == 0) { return ImGuiWindowFlags_NoCollapse; }
	if (strcmp(in, "NoBackground") == 0) { return ImGuiWindowFlags_NoBackground; }
	if (strcmp(in, "NoInputs") == 0) { return ImGuiWindowFlags_NoInputs; }
	if (strcmp(in, "AlwaysAutoResize") == 0) { return ImGuiWindowFlags_AlwaysAutoResize; }
	if (strcmp(in, "AlwaysHorizontalScrollbar") == 0) { return ImGuiWindowFlags_AlwaysHorizontalScrollbar; }
	if (strcmp(in, "NoDecoration") == 0) { return ImGuiWindowFlags_NoDecoration; }
	if (strcmp(in, "NoMove") == 0) { return ImGuiWindowFlags_NoMove; }
	if (strcmp(in, "NoBringToFrontOnFocus") == 0) { return ImGuiWindowFlags_NoBringToFrontOnFocus; }
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

std::optional<ImGuiTabItemFlags_> getImGuiTabItemFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiTabItemFlags_None; }
	if (strcmp(in, "NoPushId") == 0) { return ImGuiTabItemFlags_NoPushId; }
	if (strcmp(in, "SetSelected") == 0) { return ImGuiTabItemFlags_SetSelected; }
	if (strcmp(in, "NoCloseWithMiddleMouseButton") == 0) { return ImGuiTabItemFlags_NoCloseWithMiddleMouseButton; }
	if (strcmp(in, "UnsavedDocument") == 0) { return ImGuiTabItemFlags_UnsavedDocument; }
	return std::nullopt;
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

std::optional<ImGuiDir_> getImGuiDirFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiDir_None; }
	if (strcmp(in, "Left") == 0) { return ImGuiDir_Left; }
	if (strcmp(in, "Right") == 0) { return ImGuiDir_Right; }
	if (strcmp(in, "Up") == 0) { return ImGuiDir_Up; }
	if (strcmp(in, "Down") == 0) { return ImGuiDir_Down; }
	return std::nullopt;
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

std::optional<ImGuiConfigFlags_> getImGuiConfigFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiConfigFlags_None; }
	if (strcmp(in, "NavNoCaptureKeyboard") == 0) { return ImGuiConfigFlags_NavNoCaptureKeyboard; }
	if (strcmp(in, "NavEnableGamepad") == 0) { return ImGuiConfigFlags_NavEnableGamepad; }
	if (strcmp(in, "IsSRGB") == 0) { return ImGuiConfigFlags_IsSRGB; }
	if (strcmp(in, "NavEnableKeyboard") == 0) { return ImGuiConfigFlags_NavEnableKeyboard; }
	if (strcmp(in, "IsTouchScreen") == 0) { return ImGuiConfigFlags_IsTouchScreen; }
	if (strcmp(in, "NoMouse") == 0) { return ImGuiConfigFlags_NoMouse; }
	if (strcmp(in, "NavEnableSetMousePos") == 0) { return ImGuiConfigFlags_NavEnableSetMousePos; }
	if (strcmp(in, "NoMouseCursorChange") == 0) { return ImGuiConfigFlags_NoMouseCursorChange; }
	return std::nullopt;
}

std::optional<ImGuiBackendFlags_> getImGuiBackendFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImGuiBackendFlags_None; }
	if (strcmp(in, "HasGamepad") == 0) { return ImGuiBackendFlags_HasGamepad; }
	if (strcmp(in, "HasMouseCursors") == 0) { return ImGuiBackendFlags_HasMouseCursors; }
	if (strcmp(in, "RendererHasVtxOffset") == 0) { return ImGuiBackendFlags_RendererHasVtxOffset; }
	if (strcmp(in, "HasSetMousePos") == 0) { return ImGuiBackendFlags_HasSetMousePos; }
	return std::nullopt;
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
	if (strcmp(in, "SeparatorActive") == 0) { return ImGuiCol_SeparatorActive; }
	if (strcmp(in, "Border") == 0) { return ImGuiCol_Border; }
	if (strcmp(in, "ButtonActive") == 0) { return ImGuiCol_ButtonActive; }
	if (strcmp(in, "NavWindowingHighlight") == 0) { return ImGuiCol_NavWindowingHighlight; }
	if (strcmp(in, "Separator") == 0) { return ImGuiCol_Separator; }
	if (strcmp(in, "FrameBgHovered") == 0) { return ImGuiCol_FrameBgHovered; }
	if (strcmp(in, "DragDropTarget") == 0) { return ImGuiCol_DragDropTarget; }
	if (strcmp(in, "PlotLinesHovered") == 0) { return ImGuiCol_PlotLinesHovered; }
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

std::optional<ImGuiMouseButton_> getImGuiMouseButtonFromString(const char* in)
{
	if (strcmp(in, "Right") == 0) { return ImGuiMouseButton_Right; }
	if (strcmp(in, "Middle") == 0) { return ImGuiMouseButton_Middle; }
	if (strcmp(in, "Left") == 0) { return ImGuiMouseButton_Left; }
	return std::nullopt;
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

std::optional<ImGuiCond_> getImGuiCondFromString(const char* in)
{
	if (strcmp(in, "Once") == 0) { return ImGuiCond_Once; }
	if (strcmp(in, "Always") == 0) { return ImGuiCond_Always; }
	if (strcmp(in, "Appearing") == 0) { return ImGuiCond_Appearing; }
	if (strcmp(in, "FirstUseEver") == 0) { return ImGuiCond_FirstUseEver; }
	return std::nullopt;
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

std::optional<ImDrawListFlags_> getImDrawListFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImDrawListFlags_None; }
	if (strcmp(in, "AllowVtxOffset") == 0) { return ImDrawListFlags_AllowVtxOffset; }
	if (strcmp(in, "AntiAliasedFill") == 0) { return ImDrawListFlags_AntiAliasedFill; }
	if (strcmp(in, "AntiAliasedLines") == 0) { return ImDrawListFlags_AntiAliasedLines; }
	return std::nullopt;
}

std::optional<ImFontAtlasFlags_> getImFontAtlasFlagsFromString(const char* in)
{
	if (strcmp(in, "None") == 0) { return ImFontAtlasFlags_None; }
	if (strcmp(in, "NoPowerOfTwoHeight") == 0) { return ImFontAtlasFlags_NoPowerOfTwoHeight; }
	if (strcmp(in, "NoMouseCursors") == 0) { return ImFontAtlasFlags_NoMouseCursors; }
	return std::nullopt;
}



// Functions

// skipping function due to unimplemented argument type "ImFontAtlas*": ImGui::CreateContext

// skipping function due to unimplemented argument type "ImGuiContext*": ImGui::DestroyContext

// skipping function due to unimplemented return type "ImGuiContext*": ImGui::GetCurrentContext

// skipping function due to unimplemented argument type "ImGuiContext*": ImGui::SetCurrentContext

// skipping function due to unimplemented argument type "size_t": ImGui::DebugCheckVersionAndDataLayout

// skipping function due to unimplemented return type "ImGuiIO&": ImGui::GetIO

// skipping function due to unimplemented return type "ImGuiStyle&": ImGui::GetStyle

static int w_NewFrame(lua_State *L)
{
	
	ImGui::NewFrame();
	
	return 0;
}

static int w_EndFrame(lua_State *L)
{
	
	ImGui::EndFrame();
	
	return 0;
}

static int w_Render(lua_State *L)
{
	
	ImGui::Render();
	
	return 0;
}

// skipping function due to unimplemented return type "ImDrawData*": ImGui::GetDrawData

static int w_ShowDemoWindow(lua_State *L)
{
	auto p_open = luax_optboolean(L, 1, NULL);
	
	ImGui::ShowDemoWindow(&p_open);
	
	lua_pushboolean(L, p_open);
	return 1;
}

static int w_ShowAboutWindow(lua_State *L)
{
	auto p_open = luax_optboolean(L, 1, NULL);
	
	ImGui::ShowAboutWindow(&p_open);
	
	lua_pushboolean(L, p_open);
	return 1;
}

static int w_ShowMetricsWindow(lua_State *L)
{
	auto p_open = luax_optboolean(L, 1, NULL);
	
	ImGui::ShowMetricsWindow(&p_open);
	
	lua_pushboolean(L, p_open);
	return 1;
}

// skipping function due to unimplemented argument type "ImGuiStyle*": ImGui::ShowStyleEditor

static int w_ShowStyleSelector(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	
	bool out = ImGui::ShowStyleSelector(label);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_ShowFontSelector(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	
	ImGui::ShowFontSelector(label);
	
	return 0;
}

static int w_ShowUserGuide(lua_State *L)
{
	
	ImGui::ShowUserGuide();
	
	return 0;
}

static int w_GetVersion(lua_State *L)
{
	
	const char* out = ImGui::GetVersion();
	
	lua_pushstring(L, out);
	return 1;
}

// skipping function due to unimplemented argument type "ImGuiStyle*": ImGui::StyleColorsDark

// skipping function due to unimplemented argument type "ImGuiStyle*": ImGui::StyleColorsClassic

// skipping function due to unimplemented argument type "ImGuiStyle*": ImGui::StyleColorsLight

static int w_Begin(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	auto p_open = luax_optboolean(L, 2, NULL);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 3, 0);
	
	bool out = ImGui::Begin(name, &p_open, flags);
	
	lua_pushboolean(L, p_open);
	lua_pushboolean(L, out);
	return 2;
}

static int w_End(lua_State *L)
{
	
	ImGui::End();
	
	return 0;
}

static int w_BeginChild(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 2, size.x);
	size.y = luaL_optnumber(L, 3, size.y);
	auto border = luax_optboolean(L, 4, false);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 5, 0);
	
	bool out = ImGui::BeginChild(str_id, size, border, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_BeginChild_EX(lua_State *L)
{
	auto id = static_cast<ImGuiID>(luaL_checkint(L, 1));
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 2, size.x);
	size.y = luaL_optnumber(L, 3, size.y);
	auto border = luax_optboolean(L, 4, false);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 5, 0);
	
	bool out = ImGui::BeginChild(id, size, border, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_EndChild(lua_State *L)
{
	
	ImGui::EndChild();
	
	return 0;
}

static int w_IsWindowAppearing(lua_State *L)
{
	
	bool out = ImGui::IsWindowAppearing();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsWindowCollapsed(lua_State *L)
{
	
	bool out = ImGui::IsWindowCollapsed();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsWindowFocused(lua_State *L)
{
	auto flags = luax_optflags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, L, 1, 0);
	
	bool out = ImGui::IsWindowFocused(flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsWindowHovered(lua_State *L)
{
	auto flags = luax_optflags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, L, 1, 0);
	
	bool out = ImGui::IsWindowHovered(flags);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping function due to unimplemented return type "ImDrawList*": ImGui::GetWindowDrawList

static int w_GetWindowPos(lua_State *L)
{
	
	ImVec2 out = ImGui::GetWindowPos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetWindowSize(lua_State *L)
{
	
	ImVec2 out = ImGui::GetWindowSize();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetWindowWidth(lua_State *L)
{
	
	float out = ImGui::GetWindowWidth();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetWindowHeight(lua_State *L)
{
	
	float out = ImGui::GetWindowHeight();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_SetNextWindowPos(lua_State *L)
{
	ImVec2 pos;
	pos.x = luaL_checknumber(L, 1);
	pos.y = luaL_checknumber(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	auto pivot = ImVec2(0,0);
	pivot.x = luaL_optnumber(L, 4, pivot.x);
	pivot.y = luaL_optnumber(L, 5, pivot.y);
	
	ImGui::SetNextWindowPos(pos, cond, pivot);
	
	return 0;
}

static int w_SetNextWindowSize(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	
	ImGui::SetNextWindowSize(size, cond);
	
	return 0;
}

// skipping function due to unimplemented argument type "ImGuiSizeCallback": ImGui::SetNextWindowSizeConstraints

static int w_SetNextWindowContentSize(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	
	ImGui::SetNextWindowContentSize(size);
	
	return 0;
}

static int w_SetNextWindowCollapsed(lua_State *L)
{
	auto collapsed = luax_checkboolean(L, 1);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 2, 0);
	
	ImGui::SetNextWindowCollapsed(collapsed, cond);
	
	return 0;
}

static int w_SetNextWindowFocus(lua_State *L)
{
	
	ImGui::SetNextWindowFocus();
	
	return 0;
}

static int w_SetNextWindowBgAlpha(lua_State *L)
{
	auto alpha = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetNextWindowBgAlpha(alpha);
	
	return 0;
}

static int w_SetWindowPos(lua_State *L)
{
	ImVec2 pos;
	pos.x = luaL_checknumber(L, 1);
	pos.y = luaL_checknumber(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	
	ImGui::SetWindowPos(pos, cond);
	
	return 0;
}

static int w_SetWindowSize(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	
	ImGui::SetWindowSize(size, cond);
	
	return 0;
}

static int w_SetWindowCollapsed(lua_State *L)
{
	auto collapsed = luax_checkboolean(L, 1);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 2, 0);
	
	ImGui::SetWindowCollapsed(collapsed, cond);
	
	return 0;
}

static int w_SetWindowFocus(lua_State *L)
{
	
	ImGui::SetWindowFocus();
	
	return 0;
}

static int w_SetWindowFontScale(lua_State *L)
{
	auto scale = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetWindowFontScale(scale);
	
	return 0;
}

static int w_SetWindowPos_EX(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	ImVec2 pos;
	pos.x = luaL_checknumber(L, 2);
	pos.y = luaL_checknumber(L, 3);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 4, 0);
	
	ImGui::SetWindowPos(name, pos, cond);
	
	return 0;
}

static int w_SetWindowSize_EX(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 4, 0);
	
	ImGui::SetWindowSize(name, size, cond);
	
	return 0;
}

static int w_SetWindowCollapsed_EX(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	auto collapsed = luax_checkboolean(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	
	ImGui::SetWindowCollapsed(name, collapsed, cond);
	
	return 0;
}

static int w_SetWindowFocus_EX(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	
	ImGui::SetWindowFocus(name);
	
	return 0;
}

static int w_GetContentRegionMax(lua_State *L)
{
	
	ImVec2 out = ImGui::GetContentRegionMax();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetContentRegionAvail(lua_State *L)
{
	
	ImVec2 out = ImGui::GetContentRegionAvail();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetWindowContentRegionMin(lua_State *L)
{
	
	ImVec2 out = ImGui::GetWindowContentRegionMin();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetWindowContentRegionMax(lua_State *L)
{
	
	ImVec2 out = ImGui::GetWindowContentRegionMax();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetWindowContentRegionWidth(lua_State *L)
{
	
	float out = ImGui::GetWindowContentRegionWidth();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetScrollX(lua_State *L)
{
	
	float out = ImGui::GetScrollX();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetScrollY(lua_State *L)
{
	
	float out = ImGui::GetScrollY();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetScrollMaxX(lua_State *L)
{
	
	float out = ImGui::GetScrollMaxX();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetScrollMaxY(lua_State *L)
{
	
	float out = ImGui::GetScrollMaxY();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_SetScrollX(lua_State *L)
{
	auto scroll_x = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetScrollX(scroll_x);
	
	return 0;
}

static int w_SetScrollY(lua_State *L)
{
	auto scroll_y = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetScrollY(scroll_y);
	
	return 0;
}

static int w_SetScrollHereX(lua_State *L)
{
	auto center_x_ratio = static_cast<float>(luaL_optnumber(L, 1, 0.5f));
	
	ImGui::SetScrollHereX(center_x_ratio);
	
	return 0;
}

static int w_SetScrollHereY(lua_State *L)
{
	auto center_y_ratio = static_cast<float>(luaL_optnumber(L, 1, 0.5f));
	
	ImGui::SetScrollHereY(center_y_ratio);
	
	return 0;
}

static int w_SetScrollFromPosX(lua_State *L)
{
	auto local_x = static_cast<float>(luaL_checknumber(L, 1));
	auto center_x_ratio = static_cast<float>(luaL_optnumber(L, 2, 0.5f));
	
	ImGui::SetScrollFromPosX(local_x, center_x_ratio);
	
	return 0;
}

static int w_SetScrollFromPosY(lua_State *L)
{
	auto local_y = static_cast<float>(luaL_checknumber(L, 1));
	auto center_y_ratio = static_cast<float>(luaL_optnumber(L, 2, 0.5f));
	
	ImGui::SetScrollFromPosY(local_y, center_y_ratio);
	
	return 0;
}

// skipping function due to unimplemented argument type "ImFont*": ImGui::PushFont

static int w_PopFont(lua_State *L)
{
	
	ImGui::PopFont();
	
	return 0;
}

static int w_PushStyleColor(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiCol>(getImGuiColFromString, L, 1);
	auto col = static_cast<unsigned int>(luaL_checklong(L, 2));
	
	ImGui::PushStyleColor(idx, col);
	
	return 0;
}

static int w_PushStyleColor_EX(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiCol>(getImGuiColFromString, L, 1);
	ImVec4 col;
	col.x = luaL_checknumber(L, 2);
	col.y = luaL_checknumber(L, 3);
	col.z = luaL_checknumber(L, 3);
	col.w = luaL_checknumber(L, 3);
	
	ImGui::PushStyleColor(idx, col);
	
	return 0;
}

static int w_PopStyleColor(lua_State *L)
{
	auto count = luaL_optint(L, 1, 1);
	
	ImGui::PopStyleColor(count);
	
	return 0;
}

static int w_PushStyleVar(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiStyleVar>(getImGuiStyleVarFromString, L, 1);
	auto val = static_cast<float>(luaL_checknumber(L, 2));
	
	ImGui::PushStyleVar(idx, val);
	
	return 0;
}

static int w_PushStyleVar_EX(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiStyleVar>(getImGuiStyleVarFromString, L, 1);
	ImVec2 val;
	val.x = luaL_checknumber(L, 2);
	val.y = luaL_checknumber(L, 3);
	
	ImGui::PushStyleVar(idx, val);
	
	return 0;
}

static int w_PopStyleVar(lua_State *L)
{
	auto count = luaL_optint(L, 1, 1);
	
	ImGui::PopStyleVar(count);
	
	return 0;
}

// skipping function due to unimplemented return type "const ImVec4&": ImGui::GetStyleColorVec4

// skipping function due to unimplemented return type "ImFont*": ImGui::GetFont

static int w_GetFontSize(lua_State *L)
{
	
	float out = ImGui::GetFontSize();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetFontTexUvWhitePixel(lua_State *L)
{
	
	ImVec2 out = ImGui::GetFontTexUvWhitePixel();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetColorU32(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiCol>(getImGuiColFromString, L, 1);
	auto alpha_mul = static_cast<float>(luaL_optnumber(L, 2, 1.0f));
	
	ImU32 out = ImGui::GetColorU32(idx, alpha_mul);
	
	lua_pushinteger(L, out);
	return 1;
}

static int w_GetColorU32_EX(lua_State *L)
{
	ImVec4 col;
	col.x = luaL_checknumber(L, 1);
	col.y = luaL_checknumber(L, 2);
	col.z = luaL_checknumber(L, 2);
	col.w = luaL_checknumber(L, 2);
	
	ImU32 out = ImGui::GetColorU32(col);
	
	lua_pushinteger(L, out);
	return 1;
}

static int w_GetColorU32_EX_EX(lua_State *L)
{
	auto col = static_cast<unsigned int>(luaL_checklong(L, 1));
	
	ImU32 out = ImGui::GetColorU32(col);
	
	lua_pushinteger(L, out);
	return 1;
}

static int w_PushItemWidth(lua_State *L)
{
	auto item_width = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::PushItemWidth(item_width);
	
	return 0;
}

static int w_PopItemWidth(lua_State *L)
{
	
	ImGui::PopItemWidth();
	
	return 0;
}

static int w_SetNextItemWidth(lua_State *L)
{
	auto item_width = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetNextItemWidth(item_width);
	
	return 0;
}

static int w_CalcItemWidth(lua_State *L)
{
	
	float out = ImGui::CalcItemWidth();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_PushTextWrapPos(lua_State *L)
{
	auto wrap_local_pos_x = static_cast<float>(luaL_optnumber(L, 1, 0.0f));
	
	ImGui::PushTextWrapPos(wrap_local_pos_x);
	
	return 0;
}

static int w_PopTextWrapPos(lua_State *L)
{
	
	ImGui::PopTextWrapPos();
	
	return 0;
}

static int w_PushAllowKeyboardFocus(lua_State *L)
{
	auto allow_keyboard_focus = luax_checkboolean(L, 1);
	
	ImGui::PushAllowKeyboardFocus(allow_keyboard_focus);
	
	return 0;
}

static int w_PopAllowKeyboardFocus(lua_State *L)
{
	
	ImGui::PopAllowKeyboardFocus();
	
	return 0;
}

static int w_PushButtonRepeat(lua_State *L)
{
	auto repeat = luax_checkboolean(L, 1);
	
	ImGui::PushButtonRepeat(repeat);
	
	return 0;
}

static int w_PopButtonRepeat(lua_State *L)
{
	
	ImGui::PopButtonRepeat();
	
	return 0;
}

static int w_Separator(lua_State *L)
{
	
	ImGui::Separator();
	
	return 0;
}

static int w_SameLine(lua_State *L)
{
	auto offset_from_start_x = static_cast<float>(luaL_optnumber(L, 1, 0.0f));
	auto spacing = static_cast<float>(luaL_optnumber(L, 2, -1.0f));
	
	ImGui::SameLine(offset_from_start_x, spacing);
	
	return 0;
}

static int w_NewLine(lua_State *L)
{
	
	ImGui::NewLine();
	
	return 0;
}

static int w_Spacing(lua_State *L)
{
	
	ImGui::Spacing();
	
	return 0;
}

static int w_Dummy(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	
	ImGui::Dummy(size);
	
	return 0;
}

static int w_Indent(lua_State *L)
{
	auto indent_w = static_cast<float>(luaL_optnumber(L, 1, 0.0f));
	
	ImGui::Indent(indent_w);
	
	return 0;
}

static int w_Unindent(lua_State *L)
{
	auto indent_w = static_cast<float>(luaL_optnumber(L, 1, 0.0f));
	
	ImGui::Unindent(indent_w);
	
	return 0;
}

static int w_BeginGroup(lua_State *L)
{
	
	ImGui::BeginGroup();
	
	return 0;
}

static int w_EndGroup(lua_State *L)
{
	
	ImGui::EndGroup();
	
	return 0;
}

static int w_GetCursorPos(lua_State *L)
{
	
	ImVec2 out = ImGui::GetCursorPos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetCursorPosX(lua_State *L)
{
	
	float out = ImGui::GetCursorPosX();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetCursorPosY(lua_State *L)
{
	
	float out = ImGui::GetCursorPosY();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_SetCursorPos(lua_State *L)
{
	ImVec2 local_pos;
	local_pos.x = luaL_checknumber(L, 1);
	local_pos.y = luaL_checknumber(L, 2);
	
	ImGui::SetCursorPos(local_pos);
	
	return 0;
}

static int w_SetCursorPosX(lua_State *L)
{
	auto local_x = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetCursorPosX(local_x);
	
	return 0;
}

static int w_SetCursorPosY(lua_State *L)
{
	auto local_y = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetCursorPosY(local_y);
	
	return 0;
}

static int w_GetCursorStartPos(lua_State *L)
{
	
	ImVec2 out = ImGui::GetCursorStartPos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetCursorScreenPos(lua_State *L)
{
	
	ImVec2 out = ImGui::GetCursorScreenPos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_SetCursorScreenPos(lua_State *L)
{
	ImVec2 pos;
	pos.x = luaL_checknumber(L, 1);
	pos.y = luaL_checknumber(L, 2);
	
	ImGui::SetCursorScreenPos(pos);
	
	return 0;
}

static int w_AlignTextToFramePadding(lua_State *L)
{
	
	ImGui::AlignTextToFramePadding();
	
	return 0;
}

static int w_GetTextLineHeight(lua_State *L)
{
	
	float out = ImGui::GetTextLineHeight();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetTextLineHeightWithSpacing(lua_State *L)
{
	
	float out = ImGui::GetTextLineHeightWithSpacing();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetFrameHeight(lua_State *L)
{
	
	float out = ImGui::GetFrameHeight();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetFrameHeightWithSpacing(lua_State *L)
{
	
	float out = ImGui::GetFrameHeightWithSpacing();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_PushID(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	ImGui::PushID(str_id);
	
	return 0;
}

static int w_PushID_EX(lua_State *L)
{
	auto str_id_begin = luaL_checkstring(L, 1);
	auto str_id_end = luaL_checkstring(L, 2);
	
	ImGui::PushID(str_id_begin, str_id_end);
	
	return 0;
}

// skipping function due to unimplemented argument type "const void*": ImGui::PushID

static int w_PushID_EX_EX(lua_State *L)
{
	auto int_id = luaL_checkint(L, 1);
	
	ImGui::PushID(int_id);
	
	return 0;
}

static int w_PopID(lua_State *L)
{
	
	ImGui::PopID();
	
	return 0;
}

static int w_GetID(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	ImGuiID out = ImGui::GetID(str_id);
	
	lua_pushinteger(L, out);
	return 1;
}

static int w_GetID_EX(lua_State *L)
{
	auto str_id_begin = luaL_checkstring(L, 1);
	auto str_id_end = luaL_checkstring(L, 2);
	
	ImGuiID out = ImGui::GetID(str_id_begin, str_id_end);
	
	lua_pushinteger(L, out);
	return 1;
}

// skipping function due to unimplemented argument type "const void*": ImGui::GetID

static int w_TextUnformatted(lua_State *L)
{
	auto text = luaL_checkstring(L, 1);
	auto text_end = luaL_optstring(L, 2, NULL);
	
	ImGui::TextUnformatted(text, text_end);
	
	return 0;
}

// skipping function due to having variable arguments: ImGui::Text

// skipping function due to having variable arguments: ImGui::TextColored

// skipping function due to having variable arguments: ImGui::TextDisabled

// skipping function due to having variable arguments: ImGui::TextWrapped

// skipping function due to having variable arguments: ImGui::LabelText

// skipping function due to having variable arguments: ImGui::BulletText

static int w_Button(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 2, size.x);
	size.y = luaL_optnumber(L, 3, size.y);
	
	bool out = ImGui::Button(label, size);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_SmallButton(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	
	bool out = ImGui::SmallButton(label);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_InvisibleButton(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	
	bool out = ImGui::InvisibleButton(str_id, size);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_ArrowButton(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto dir = luax_checkenum<ImGuiDir>(getImGuiDirFromString, L, 2);
	
	bool out = ImGui::ArrowButton(str_id, dir);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping function due to unimplemented argument type "ImTextureID": ImGui::Image

// skipping function due to unimplemented argument type "ImTextureID": ImGui::ImageButton

static int w_Checkbox(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = luax_checkboolean(L, 2);
	
	bool out = ImGui::Checkbox(label, &v);
	
	lua_pushboolean(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_CheckboxFlags(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto flags = static_cast<unsigned int>(luaL_checkint(L, 2));
	auto flags_value = static_cast<unsigned int>(luaL_checklong(L, 3));
	
	bool out = ImGui::CheckboxFlags(label, &flags, flags_value);
	
	lua_pushinteger(L, flags);
	lua_pushboolean(L, out);
	return 2;
}

static int w_RadioButton(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto active = luax_checkboolean(L, 2);
	
	bool out = ImGui::RadioButton(label, active);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_RadioButton_EX(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = luaL_checkint(L, 2);
	auto v_button = luaL_checkint(L, 3);
	
	bool out = ImGui::RadioButton(label, &v, v_button);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_ProgressBar(lua_State *L)
{
	auto fraction = static_cast<float>(luaL_checknumber(L, 1));
	auto size_arg = ImVec2(-1,0);
	size_arg.x = luaL_optnumber(L, 2, size_arg.x);
	size_arg.y = luaL_optnumber(L, 3, size_arg.y);
	auto overlay = luaL_optstring(L, 4, NULL);
	
	ImGui::ProgressBar(fraction, size_arg, overlay);
	
	return 0;
}

static int w_Bullet(lua_State *L)
{
	
	ImGui::Bullet();
	
	return 0;
}

static int w_BeginCombo(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto preview_value = luaL_checkstring(L, 2);
	auto flags = luax_optflags<ImGuiComboFlags>(getImGuiComboFlagsFromString, L, 3, 0);
	
	bool out = ImGui::BeginCombo(label, preview_value, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_EndCombo(lua_State *L)
{
	
	ImGui::EndCombo();
	
	return 0;
}

// skipping function due to unimplemented argument type "const char* const[]": ImGui::Combo

static int w_Combo(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto current_item = luaL_checkint(L, 2);
	auto items_separated_by_zeros = luaL_checkstring(L, 3);
	auto popup_max_height_in_items = luaL_optint(L, 4, -1);
	
	bool out = ImGui::Combo(label, &current_item, items_separated_by_zeros, popup_max_height_in_items);
	
	lua_pushinteger(L, current_item);
	lua_pushboolean(L, out);
	return 2;
}

// skipping function due to unimplemented argument type " bool(*items_getter)(void* data, int idx, const char** out_text)": ImGui::Combo

static int w_DragFloat(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = static_cast<float>(luaL_checknumber(L, 2));
	auto v_speed = static_cast<float>(luaL_optnumber(L, 3, 1.0f));
	auto v_min = static_cast<float>(luaL_optnumber(L, 4, 0.0f));
	auto v_max = static_cast<float>(luaL_optnumber(L, 5, 0.0f));
	auto format = luaL_optstring(L, 6, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 7, 1.0f));
	
	bool out = ImGui::DragFloat(label, &v, v_speed, v_min, v_max, format, power);
	
	lua_pushnumber(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_DragFloat2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[2];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	auto v_speed = static_cast<float>(luaL_optnumber(L, 4, 1.0f));
	auto v_min = static_cast<float>(luaL_optnumber(L, 5, 0.0f));
	auto v_max = static_cast<float>(luaL_optnumber(L, 6, 0.0f));
	auto format = luaL_optstring(L, 7, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 8, 1.0f));
	
	bool out = ImGui::DragFloat2(label, v, v_speed, v_min, v_max, format, power);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushboolean(L, out);
	return 3;
}

static int w_DragFloat3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[3];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	v[2] = static_cast<float>(luaL_checknumber(L, 4));
	auto v_speed = static_cast<float>(luaL_optnumber(L, 5, 1.0f));
	auto v_min = static_cast<float>(luaL_optnumber(L, 6, 0.0f));
	auto v_max = static_cast<float>(luaL_optnumber(L, 7, 0.0f));
	auto format = luaL_optstring(L, 8, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 9, 1.0f));
	
	bool out = ImGui::DragFloat3(label, v, v_speed, v_min, v_max, format, power);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushnumber(L, v[2]);
	lua_pushboolean(L, out);
	return 4;
}

static int w_DragFloat4(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[4];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	v[2] = static_cast<float>(luaL_checknumber(L, 4));
	v[3] = static_cast<float>(luaL_checknumber(L, 5));
	auto v_speed = static_cast<float>(luaL_optnumber(L, 6, 1.0f));
	auto v_min = static_cast<float>(luaL_optnumber(L, 7, 0.0f));
	auto v_max = static_cast<float>(luaL_optnumber(L, 8, 0.0f));
	auto format = luaL_optstring(L, 9, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 10, 1.0f));
	
	bool out = ImGui::DragFloat4(label, v, v_speed, v_min, v_max, format, power);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushnumber(L, v[2]);
	lua_pushnumber(L, v[3]);
	lua_pushboolean(L, out);
	return 5;
}

static int w_DragFloatRange2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v_current_min = static_cast<float>(luaL_checknumber(L, 2));
	auto v_current_max = static_cast<float>(luaL_checknumber(L, 3));
	auto v_speed = static_cast<float>(luaL_optnumber(L, 4, 1.0f));
	auto v_min = static_cast<float>(luaL_optnumber(L, 5, 0.0f));
	auto v_max = static_cast<float>(luaL_optnumber(L, 6, 0.0f));
	auto format = luaL_optstring(L, 7, "%.3f");
	auto format_max = luaL_optstring(L, 8, NULL);
	auto power = static_cast<float>(luaL_optnumber(L, 9, 1.0f));
	
	bool out = ImGui::DragFloatRange2(label, &v_current_min, &v_current_max, v_speed, v_min, v_max, format, format_max, power);
	
	lua_pushnumber(L, v_current_min);
	lua_pushnumber(L, v_current_max);
	lua_pushboolean(L, out);
	return 3;
}

static int w_DragInt(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = luaL_checkint(L, 2);
	auto v_speed = static_cast<float>(luaL_optnumber(L, 3, 1.0f));
	auto v_min = luaL_optint(L, 4, 0);
	auto v_max = luaL_optint(L, 5, 0);
	auto format = luaL_optstring(L, 6, "%d");
	
	bool out = ImGui::DragInt(label, &v, v_speed, v_min, v_max, format);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_DragInt2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[2];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	auto v_speed = static_cast<float>(luaL_optnumber(L, 4, 1.0f));
	auto v_min = luaL_optint(L, 5, 0);
	auto v_max = luaL_optint(L, 6, 0);
	auto format = luaL_optstring(L, 7, "%d");
	
	bool out = ImGui::DragInt2(label, v, v_speed, v_min, v_max, format);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushboolean(L, out);
	return 3;
}

static int w_DragInt3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[3];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	v[2] = static_cast<int>(luaL_checkint(L, 4));
	auto v_speed = static_cast<float>(luaL_optnumber(L, 5, 1.0f));
	auto v_min = luaL_optint(L, 6, 0);
	auto v_max = luaL_optint(L, 7, 0);
	auto format = luaL_optstring(L, 8, "%d");
	
	bool out = ImGui::DragInt3(label, v, v_speed, v_min, v_max, format);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushinteger(L, v[2]);
	lua_pushboolean(L, out);
	return 4;
}

static int w_DragInt4(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[4];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	v[2] = static_cast<int>(luaL_checkint(L, 4));
	v[3] = static_cast<int>(luaL_checkint(L, 5));
	auto v_speed = static_cast<float>(luaL_optnumber(L, 6, 1.0f));
	auto v_min = luaL_optint(L, 7, 0);
	auto v_max = luaL_optint(L, 8, 0);
	auto format = luaL_optstring(L, 9, "%d");
	
	bool out = ImGui::DragInt4(label, v, v_speed, v_min, v_max, format);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushinteger(L, v[2]);
	lua_pushinteger(L, v[3]);
	lua_pushboolean(L, out);
	return 5;
}

static int w_DragIntRange2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v_current_min = luaL_checkint(L, 2);
	auto v_current_max = luaL_checkint(L, 3);
	auto v_speed = static_cast<float>(luaL_optnumber(L, 4, 1.0f));
	auto v_min = luaL_optint(L, 5, 0);
	auto v_max = luaL_optint(L, 6, 0);
	auto format = luaL_optstring(L, 7, "%d");
	auto format_max = luaL_optstring(L, 8, NULL);
	
	bool out = ImGui::DragIntRange2(label, &v_current_min, &v_current_max, v_speed, v_min, v_max, format, format_max);
	
	lua_pushinteger(L, v_current_min);
	lua_pushinteger(L, v_current_max);
	lua_pushboolean(L, out);
	return 3;
}

// skipping function due to unimplemented argument type "ImGuiDataType": ImGui::DragScalar

// skipping function due to unimplemented argument type "ImGuiDataType": ImGui::DragScalarN

static int w_SliderFloat(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = static_cast<float>(luaL_checknumber(L, 2));
	auto v_min = static_cast<float>(luaL_checknumber(L, 3));
	auto v_max = static_cast<float>(luaL_checknumber(L, 4));
	auto format = luaL_optstring(L, 5, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 6, 1.0f));
	
	bool out = ImGui::SliderFloat(label, &v, v_min, v_max, format, power);
	
	lua_pushnumber(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_SliderFloat2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[2];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	auto v_min = static_cast<float>(luaL_checknumber(L, 4));
	auto v_max = static_cast<float>(luaL_checknumber(L, 5));
	auto format = luaL_optstring(L, 6, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 7, 1.0f));
	
	bool out = ImGui::SliderFloat2(label, v, v_min, v_max, format, power);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushboolean(L, out);
	return 3;
}

static int w_SliderFloat3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[3];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	v[2] = static_cast<float>(luaL_checknumber(L, 4));
	auto v_min = static_cast<float>(luaL_checknumber(L, 5));
	auto v_max = static_cast<float>(luaL_checknumber(L, 6));
	auto format = luaL_optstring(L, 7, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 8, 1.0f));
	
	bool out = ImGui::SliderFloat3(label, v, v_min, v_max, format, power);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushnumber(L, v[2]);
	lua_pushboolean(L, out);
	return 4;
}

static int w_SliderFloat4(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[4];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	v[2] = static_cast<float>(luaL_checknumber(L, 4));
	v[3] = static_cast<float>(luaL_checknumber(L, 5));
	auto v_min = static_cast<float>(luaL_checknumber(L, 6));
	auto v_max = static_cast<float>(luaL_checknumber(L, 7));
	auto format = luaL_optstring(L, 8, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 9, 1.0f));
	
	bool out = ImGui::SliderFloat4(label, v, v_min, v_max, format, power);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushnumber(L, v[2]);
	lua_pushnumber(L, v[3]);
	lua_pushboolean(L, out);
	return 5;
}

static int w_SliderAngle(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v_rad = static_cast<float>(luaL_checknumber(L, 2));
	auto v_degrees_min = static_cast<float>(luaL_optnumber(L, 3, -360.0f));
	auto v_degrees_max = static_cast<float>(luaL_optnumber(L, 4, +360.0f));
	auto format = luaL_optstring(L, 5, "%.0f deg");
	
	bool out = ImGui::SliderAngle(label, &v_rad, v_degrees_min, v_degrees_max, format);
	
	lua_pushnumber(L, v_rad);
	lua_pushboolean(L, out);
	return 2;
}

static int w_SliderInt(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = luaL_checkint(L, 2);
	auto v_min = luaL_checkint(L, 3);
	auto v_max = luaL_checkint(L, 4);
	auto format = luaL_optstring(L, 5, "%d");
	
	bool out = ImGui::SliderInt(label, &v, v_min, v_max, format);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_SliderInt2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[2];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	auto v_min = luaL_checkint(L, 4);
	auto v_max = luaL_checkint(L, 5);
	auto format = luaL_optstring(L, 6, "%d");
	
	bool out = ImGui::SliderInt2(label, v, v_min, v_max, format);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushboolean(L, out);
	return 3;
}

static int w_SliderInt3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[3];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	v[2] = static_cast<int>(luaL_checkint(L, 4));
	auto v_min = luaL_checkint(L, 5);
	auto v_max = luaL_checkint(L, 6);
	auto format = luaL_optstring(L, 7, "%d");
	
	bool out = ImGui::SliderInt3(label, v, v_min, v_max, format);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushinteger(L, v[2]);
	lua_pushboolean(L, out);
	return 4;
}

static int w_SliderInt4(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[4];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	v[2] = static_cast<int>(luaL_checkint(L, 4));
	v[3] = static_cast<int>(luaL_checkint(L, 5));
	auto v_min = luaL_checkint(L, 6);
	auto v_max = luaL_checkint(L, 7);
	auto format = luaL_optstring(L, 8, "%d");
	
	bool out = ImGui::SliderInt4(label, v, v_min, v_max, format);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushinteger(L, v[2]);
	lua_pushinteger(L, v[3]);
	lua_pushboolean(L, out);
	return 5;
}

// skipping function due to unimplemented argument type "ImGuiDataType": ImGui::SliderScalar

// skipping function due to unimplemented argument type "ImGuiDataType": ImGui::SliderScalarN

static int w_VSliderFloat(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	auto v = static_cast<float>(luaL_checknumber(L, 4));
	auto v_min = static_cast<float>(luaL_checknumber(L, 5));
	auto v_max = static_cast<float>(luaL_checknumber(L, 6));
	auto format = luaL_optstring(L, 7, "%.3f");
	auto power = static_cast<float>(luaL_optnumber(L, 8, 1.0f));
	
	bool out = ImGui::VSliderFloat(label, size, &v, v_min, v_max, format, power);
	
	lua_pushnumber(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_VSliderInt(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	auto v = luaL_checkint(L, 4);
	auto v_min = luaL_checkint(L, 5);
	auto v_max = luaL_checkint(L, 6);
	auto format = luaL_optstring(L, 7, "%d");
	
	bool out = ImGui::VSliderInt(label, size, &v, v_min, v_max, format);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

// skipping function due to unimplemented argument type "ImGuiDataType": ImGui::VSliderScalar

// skipping function due to unimplemented argument type "char*": ImGui::InputText

// skipping function due to unimplemented argument type "char*": ImGui::InputTextMultiline

// skipping function due to unimplemented argument type "char*": ImGui::InputTextWithHint

static int w_InputFloat(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = static_cast<float>(luaL_checknumber(L, 2));
	auto step = static_cast<float>(luaL_optnumber(L, 3, 0.0f));
	auto step_fast = static_cast<float>(luaL_optnumber(L, 4, 0.0f));
	auto format = luaL_optstring(L, 5, "%.3f");
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 6, 0);
	
	bool out = ImGui::InputFloat(label, &v, step, step_fast, format, flags);
	
	lua_pushnumber(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_InputFloat2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[2];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	auto format = luaL_optstring(L, 4, "%.3f");
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 5, 0);
	
	bool out = ImGui::InputFloat2(label, v, format, flags);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushboolean(L, out);
	return 3;
}

static int w_InputFloat3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[3];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	v[2] = static_cast<float>(luaL_checknumber(L, 4));
	auto format = luaL_optstring(L, 5, "%.3f");
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 6, 0);
	
	bool out = ImGui::InputFloat3(label, v, format, flags);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushnumber(L, v[2]);
	lua_pushboolean(L, out);
	return 4;
}

static int w_InputFloat4(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float v[4];
	v[0] = static_cast<float>(luaL_checknumber(L, 2));
	v[1] = static_cast<float>(luaL_checknumber(L, 3));
	v[2] = static_cast<float>(luaL_checknumber(L, 4));
	v[3] = static_cast<float>(luaL_checknumber(L, 5));
	auto format = luaL_optstring(L, 6, "%.3f");
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 7, 0);
	
	bool out = ImGui::InputFloat4(label, v, format, flags);
	
	lua_pushnumber(L, v[0]);
	lua_pushnumber(L, v[1]);
	lua_pushnumber(L, v[2]);
	lua_pushnumber(L, v[3]);
	lua_pushboolean(L, out);
	return 5;
}

static int w_InputInt(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = luaL_checkint(L, 2);
	auto step = luaL_optint(L, 3, 1);
	auto step_fast = luaL_optint(L, 4, 100);
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 5, 0);
	
	bool out = ImGui::InputInt(label, &v, step, step_fast, flags);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

static int w_InputInt2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[2];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 4, 0);
	
	bool out = ImGui::InputInt2(label, v, flags);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushboolean(L, out);
	return 3;
}

static int w_InputInt3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[3];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	v[2] = static_cast<int>(luaL_checkint(L, 4));
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 5, 0);
	
	bool out = ImGui::InputInt3(label, v, flags);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushinteger(L, v[2]);
	lua_pushboolean(L, out);
	return 4;
}

static int w_InputInt4(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v[4];
	v[0] = static_cast<int>(luaL_checkint(L, 2));
	v[1] = static_cast<int>(luaL_checkint(L, 3));
	v[2] = static_cast<int>(luaL_checkint(L, 4));
	v[3] = static_cast<int>(luaL_checkint(L, 5));
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 6, 0);
	
	bool out = ImGui::InputInt4(label, v, flags);
	
	lua_pushinteger(L, v[0]);
	lua_pushinteger(L, v[1]);
	lua_pushinteger(L, v[2]);
	lua_pushinteger(L, v[3]);
	lua_pushboolean(L, out);
	return 5;
}

static int w_InputDouble(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto v = luaL_checknumber(L, 2);
	auto step = luaL_optnumber(L, 3, 0.0);
	auto step_fast = luaL_optnumber(L, 4, 0.0);
	auto format = luaL_optstring(L, 5, "%.6f");
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 6, 0);
	
	bool out = ImGui::InputDouble(label, &v, step, step_fast, format, flags);
	
	lua_pushnumber(L, v);
	lua_pushboolean(L, out);
	return 2;
}

// skipping function due to unimplemented argument type "ImGuiDataType": ImGui::InputScalar

// skipping function due to unimplemented argument type "ImGuiDataType": ImGui::InputScalarN

static int w_ColorEdit3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float col[3];
	col[0] = static_cast<float>(luaL_checknumber(L, 2));
	col[1] = static_cast<float>(luaL_checknumber(L, 3));
	col[2] = static_cast<float>(luaL_checknumber(L, 4));
	auto flags = luax_optflags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, L, 5, 0);
	
	bool out = ImGui::ColorEdit3(label, col, flags);
	
	lua_pushnumber(L, col[0]);
	lua_pushnumber(L, col[1]);
	lua_pushnumber(L, col[2]);
	lua_pushboolean(L, out);
	return 4;
}

static int w_ColorEdit4(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float col[4];
	col[0] = static_cast<float>(luaL_checknumber(L, 2));
	col[1] = static_cast<float>(luaL_checknumber(L, 3));
	col[2] = static_cast<float>(luaL_checknumber(L, 4));
	col[3] = static_cast<float>(luaL_checknumber(L, 5));
	auto flags = luax_optflags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, L, 6, 0);
	
	bool out = ImGui::ColorEdit4(label, col, flags);
	
	lua_pushnumber(L, col[0]);
	lua_pushnumber(L, col[1]);
	lua_pushnumber(L, col[2]);
	lua_pushnumber(L, col[3]);
	lua_pushboolean(L, out);
	return 5;
}

static int w_ColorPicker3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	float col[3];
	col[0] = static_cast<float>(luaL_checknumber(L, 2));
	col[1] = static_cast<float>(luaL_checknumber(L, 3));
	col[2] = static_cast<float>(luaL_checknumber(L, 4));
	auto flags = luax_optflags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, L, 5, 0);
	
	bool out = ImGui::ColorPicker3(label, col, flags);
	
	lua_pushnumber(L, col[0]);
	lua_pushnumber(L, col[1]);
	lua_pushnumber(L, col[2]);
	lua_pushboolean(L, out);
	return 4;
}

// skipping function due to unimplemented argument type "const float*": ImGui::ColorPicker4

static int w_ColorButton(lua_State *L)
{
	auto desc_id = luaL_checkstring(L, 1);
	ImVec4 col;
	col.x = luaL_checknumber(L, 2);
	col.y = luaL_checknumber(L, 3);
	col.z = luaL_checknumber(L, 3);
	col.w = luaL_checknumber(L, 3);
	auto flags = luax_optflags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, L, 6, 0);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 7, size.x);
	size.y = luaL_optnumber(L, 8, size.y);
	
	bool out = ImGui::ColorButton(desc_id, col, flags, size);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_SetColorEditOptions(lua_State *L)
{
	auto flags = luax_checkflags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, L, 1);
	
	ImGui::SetColorEditOptions(flags);
	
	return 0;
}

static int w_TreeNode(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	
	bool out = ImGui::TreeNode(label);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping function due to having variable arguments: ImGui::TreeNode

// skipping function due to having variable arguments: ImGui::TreeNode

static int w_TreeNodeEx(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto flags = luax_optflags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, L, 2, 0);
	
	bool out = ImGui::TreeNodeEx(label, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping function due to having variable arguments: ImGui::TreeNodeEx

// skipping function due to having variable arguments: ImGui::TreeNodeEx

static int w_TreePush(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	ImGui::TreePush(str_id);
	
	return 0;
}

// skipping function due to unimplemented argument type "const void*": ImGui::TreePush

static int w_TreePop(lua_State *L)
{
	
	ImGui::TreePop();
	
	return 0;
}

static int w_GetTreeNodeToLabelSpacing(lua_State *L)
{
	
	float out = ImGui::GetTreeNodeToLabelSpacing();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_CollapsingHeader(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto flags = luax_optflags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, L, 2, 0);
	
	bool out = ImGui::CollapsingHeader(label, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_CollapsingHeader_EX(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto p_open = luax_checkboolean(L, 2);
	auto flags = luax_optflags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, L, 3, 0);
	
	bool out = ImGui::CollapsingHeader(label, &p_open, flags);
	
	lua_pushboolean(L, p_open);
	lua_pushboolean(L, out);
	return 2;
}

static int w_SetNextItemOpen(lua_State *L)
{
	auto is_open = luax_checkboolean(L, 1);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 2, 0);
	
	ImGui::SetNextItemOpen(is_open, cond);
	
	return 0;
}

static int w_Selectable(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto selected = luax_optboolean(L, 2, false);
	auto flags = luax_optflags<ImGuiSelectableFlags>(getImGuiSelectableFlagsFromString, L, 3, 0);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 4, size.x);
	size.y = luaL_optnumber(L, 5, size.y);
	
	bool out = ImGui::Selectable(label, selected, flags, size);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_Selectable_EX(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto p_selected = luax_checkboolean(L, 2);
	auto flags = luax_optflags<ImGuiSelectableFlags>(getImGuiSelectableFlagsFromString, L, 3, 0);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 4, size.x);
	size.y = luaL_optnumber(L, 5, size.y);
	
	bool out = ImGui::Selectable(label, &p_selected, flags, size);
	
	lua_pushboolean(L, p_selected);
	lua_pushboolean(L, out);
	return 2;
}

// skipping function due to unimplemented argument type "const char* const[]": ImGui::ListBox

// skipping function due to unimplemented argument type " bool (*items_getter)(void* data, int idx, const char** out_text)": ImGui::ListBox

static int w_ListBoxHeader(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 2, size.x);
	size.y = luaL_optnumber(L, 3, size.y);
	
	bool out = ImGui::ListBoxHeader(label, size);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_ListBoxHeader_EX(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto items_count = luaL_checkint(L, 2);
	auto height_in_items = luaL_optint(L, 3, -1);
	
	bool out = ImGui::ListBoxHeader(label, items_count, height_in_items);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_ListBoxFooter(lua_State *L)
{
	
	ImGui::ListBoxFooter();
	
	return 0;
}

// skipping function due to unimplemented argument type "const float*": ImGui::PlotLines

// skipping function due to unimplemented argument type " float(*values_getter)(void* data, int idx)": ImGui::PlotLines

// skipping function due to unimplemented argument type "const float*": ImGui::PlotHistogram

// skipping function due to unimplemented argument type " float(*values_getter)(void* data, int idx)": ImGui::PlotHistogram

static int w_Value(lua_State *L)
{
	auto prefix = luaL_checkstring(L, 1);
	auto b = luax_checkboolean(L, 2);
	
	ImGui::Value(prefix, b);
	
	return 0;
}

static int w_Value_EX(lua_State *L)
{
	auto prefix = luaL_checkstring(L, 1);
	auto v = luaL_checkint(L, 2);
	
	ImGui::Value(prefix, v);
	
	return 0;
}

static int w_Value_EX_EX(lua_State *L)
{
	auto prefix = luaL_checkstring(L, 1);
	auto v = static_cast<unsigned int>(luaL_checklong(L, 2));
	
	ImGui::Value(prefix, v);
	
	return 0;
}

static int w_Value_EX_EX_EX(lua_State *L)
{
	auto prefix = luaL_checkstring(L, 1);
	auto v = static_cast<float>(luaL_checknumber(L, 2));
	auto float_format = luaL_optstring(L, 3, NULL);
	
	ImGui::Value(prefix, v, float_format);
	
	return 0;
}

static int w_BeginMenuBar(lua_State *L)
{
	
	bool out = ImGui::BeginMenuBar();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_EndMenuBar(lua_State *L)
{
	
	ImGui::EndMenuBar();
	
	return 0;
}

static int w_BeginMainMenuBar(lua_State *L)
{
	
	bool out = ImGui::BeginMainMenuBar();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_EndMainMenuBar(lua_State *L)
{
	
	ImGui::EndMainMenuBar();
	
	return 0;
}

static int w_BeginMenu(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto enabled = luax_optboolean(L, 2, true);
	
	bool out = ImGui::BeginMenu(label, enabled);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_EndMenu(lua_State *L)
{
	
	ImGui::EndMenu();
	
	return 0;
}

static int w_MenuItem(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto shortcut = luaL_optstring(L, 2, NULL);
	auto selected = luax_optboolean(L, 3, false);
	auto enabled = luax_optboolean(L, 4, true);
	
	bool out = ImGui::MenuItem(label, shortcut, selected, enabled);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_MenuItem_EX(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto shortcut = luaL_checkstring(L, 2);
	auto p_selected = luax_checkboolean(L, 3);
	auto enabled = luax_optboolean(L, 4, true);
	
	bool out = ImGui::MenuItem(label, shortcut, &p_selected, enabled);
	
	lua_pushboolean(L, p_selected);
	lua_pushboolean(L, out);
	return 2;
}

static int w_BeginTooltip(lua_State *L)
{
	
	ImGui::BeginTooltip();
	
	return 0;
}

static int w_EndTooltip(lua_State *L)
{
	
	ImGui::EndTooltip();
	
	return 0;
}

// skipping function due to having variable arguments: ImGui::SetTooltip

static int w_OpenPopup(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	ImGui::OpenPopup(str_id);
	
	return 0;
}

static int w_BeginPopup(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 2, 0);
	
	bool out = ImGui::BeginPopup(str_id, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_BeginPopupContextItem(lua_State *L)
{
	auto str_id = luaL_optstring(L, 1, NULL);
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 2, 1);
	
	bool out = ImGui::BeginPopupContextItem(str_id, mouse_button);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_BeginPopupContextWindow(lua_State *L)
{
	auto str_id = luaL_optstring(L, 1, NULL);
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 2, 1);
	auto also_over_items = luax_optboolean(L, 3, true);
	
	bool out = ImGui::BeginPopupContextWindow(str_id, mouse_button, also_over_items);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_BeginPopupContextVoid(lua_State *L)
{
	auto str_id = luaL_optstring(L, 1, NULL);
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 2, 1);
	
	bool out = ImGui::BeginPopupContextVoid(str_id, mouse_button);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_BeginPopupModal(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	auto p_open = luax_optboolean(L, 2, NULL);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 3, 0);
	
	bool out = ImGui::BeginPopupModal(name, &p_open, flags);
	
	lua_pushboolean(L, p_open);
	lua_pushboolean(L, out);
	return 2;
}

static int w_EndPopup(lua_State *L)
{
	
	ImGui::EndPopup();
	
	return 0;
}

static int w_OpenPopupOnItemClick(lua_State *L)
{
	auto str_id = luaL_optstring(L, 1, NULL);
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 2, 1);
	
	bool out = ImGui::OpenPopupOnItemClick(str_id, mouse_button);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsPopupOpen(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	bool out = ImGui::IsPopupOpen(str_id);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_CloseCurrentPopup(lua_State *L)
{
	
	ImGui::CloseCurrentPopup();
	
	return 0;
}

static int w_Columns(lua_State *L)
{
	auto count = luaL_optint(L, 1, 1);
	auto id = luaL_optstring(L, 2, NULL);
	auto border = luax_optboolean(L, 3, true);
	
	ImGui::Columns(count, id, border);
	
	return 0;
}

static int w_NextColumn(lua_State *L)
{
	
	ImGui::NextColumn();
	
	return 0;
}

static int w_GetColumnIndex(lua_State *L)
{
	
	int out = ImGui::GetColumnIndex();
	
	lua_pushinteger(L, out);
	return 1;
}

static int w_GetColumnWidth(lua_State *L)
{
	auto column_index = luaL_optint(L, 1, -1);
	
	float out = ImGui::GetColumnWidth(column_index);
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_SetColumnWidth(lua_State *L)
{
	auto column_index = luaL_checkint(L, 1);
	auto width = static_cast<float>(luaL_checknumber(L, 2));
	
	ImGui::SetColumnWidth(column_index, width);
	
	return 0;
}

static int w_GetColumnOffset(lua_State *L)
{
	auto column_index = luaL_optint(L, 1, -1);
	
	float out = ImGui::GetColumnOffset(column_index);
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_SetColumnOffset(lua_State *L)
{
	auto column_index = luaL_checkint(L, 1);
	auto offset_x = static_cast<float>(luaL_checknumber(L, 2));
	
	ImGui::SetColumnOffset(column_index, offset_x);
	
	return 0;
}

static int w_GetColumnsCount(lua_State *L)
{
	
	int out = ImGui::GetColumnsCount();
	
	lua_pushinteger(L, out);
	return 1;
}

static int w_BeginTabBar(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto flags = luax_optflags<ImGuiTabBarFlags>(getImGuiTabBarFlagsFromString, L, 2, 0);
	
	bool out = ImGui::BeginTabBar(str_id, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_EndTabBar(lua_State *L)
{
	
	ImGui::EndTabBar();
	
	return 0;
}

static int w_BeginTabItem(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto p_open = luax_optboolean(L, 2, NULL);
	auto flags = luax_optflags<ImGuiTabItemFlags>(getImGuiTabItemFlagsFromString, L, 3, 0);
	
	bool out = ImGui::BeginTabItem(label, &p_open, flags);
	
	lua_pushboolean(L, p_open);
	lua_pushboolean(L, out);
	return 2;
}

static int w_EndTabItem(lua_State *L)
{
	
	ImGui::EndTabItem();
	
	return 0;
}

static int w_SetTabItemClosed(lua_State *L)
{
	auto tab_or_docked_window_label = luaL_checkstring(L, 1);
	
	ImGui::SetTabItemClosed(tab_or_docked_window_label);
	
	return 0;
}

static int w_LogToTTY(lua_State *L)
{
	auto auto_open_depth = luaL_optint(L, 1, -1);
	
	ImGui::LogToTTY(auto_open_depth);
	
	return 0;
}

static int w_LogToFile(lua_State *L)
{
	auto auto_open_depth = luaL_optint(L, 1, -1);
	auto filename = luaL_optstring(L, 2, NULL);
	
	ImGui::LogToFile(auto_open_depth, filename);
	
	return 0;
}

static int w_LogToClipboard(lua_State *L)
{
	auto auto_open_depth = luaL_optint(L, 1, -1);
	
	ImGui::LogToClipboard(auto_open_depth);
	
	return 0;
}

static int w_LogFinish(lua_State *L)
{
	
	ImGui::LogFinish();
	
	return 0;
}

static int w_LogButtons(lua_State *L)
{
	
	ImGui::LogButtons();
	
	return 0;
}

// skipping function due to having variable arguments: ImGui::LogText

static int w_BeginDragDropSource(lua_State *L)
{
	auto flags = luax_optflags<ImGuiDragDropFlags>(getImGuiDragDropFlagsFromString, L, 1, 0);
	
	bool out = ImGui::BeginDragDropSource(flags);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping function due to unimplemented argument type "const void*": ImGui::SetDragDropPayload

static int w_EndDragDropSource(lua_State *L)
{
	
	ImGui::EndDragDropSource();
	
	return 0;
}

static int w_BeginDragDropTarget(lua_State *L)
{
	
	bool out = ImGui::BeginDragDropTarget();
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping function due to unimplemented return type "const ImGuiPayload*": ImGui::AcceptDragDropPayload

static int w_EndDragDropTarget(lua_State *L)
{
	
	ImGui::EndDragDropTarget();
	
	return 0;
}

// skipping function due to unimplemented return type "const ImGuiPayload*": ImGui::GetDragDropPayload

static int w_PushClipRect(lua_State *L)
{
	ImVec2 clip_rect_min;
	clip_rect_min.x = luaL_checknumber(L, 1);
	clip_rect_min.y = luaL_checknumber(L, 2);
	ImVec2 clip_rect_max;
	clip_rect_max.x = luaL_checknumber(L, 3);
	clip_rect_max.y = luaL_checknumber(L, 4);
	auto intersect_with_current_clip_rect = luax_checkboolean(L, 5);
	
	ImGui::PushClipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect);
	
	return 0;
}

static int w_PopClipRect(lua_State *L)
{
	
	ImGui::PopClipRect();
	
	return 0;
}

static int w_SetItemDefaultFocus(lua_State *L)
{
	
	ImGui::SetItemDefaultFocus();
	
	return 0;
}

static int w_SetKeyboardFocusHere(lua_State *L)
{
	auto offset = luaL_optint(L, 1, 0);
	
	ImGui::SetKeyboardFocusHere(offset);
	
	return 0;
}

static int w_IsItemHovered(lua_State *L)
{
	auto flags = luax_optflags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, L, 1, 0);
	
	bool out = ImGui::IsItemHovered(flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemActive(lua_State *L)
{
	
	bool out = ImGui::IsItemActive();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemFocused(lua_State *L)
{
	
	bool out = ImGui::IsItemFocused();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemClicked(lua_State *L)
{
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1, 0);
	
	bool out = ImGui::IsItemClicked(mouse_button);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemVisible(lua_State *L)
{
	
	bool out = ImGui::IsItemVisible();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemEdited(lua_State *L)
{
	
	bool out = ImGui::IsItemEdited();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemActivated(lua_State *L)
{
	
	bool out = ImGui::IsItemActivated();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemDeactivated(lua_State *L)
{
	
	bool out = ImGui::IsItemDeactivated();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemDeactivatedAfterEdit(lua_State *L)
{
	
	bool out = ImGui::IsItemDeactivatedAfterEdit();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsItemToggledOpen(lua_State *L)
{
	
	bool out = ImGui::IsItemToggledOpen();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsAnyItemHovered(lua_State *L)
{
	
	bool out = ImGui::IsAnyItemHovered();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsAnyItemActive(lua_State *L)
{
	
	bool out = ImGui::IsAnyItemActive();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsAnyItemFocused(lua_State *L)
{
	
	bool out = ImGui::IsAnyItemFocused();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_GetItemRectMin(lua_State *L)
{
	
	ImVec2 out = ImGui::GetItemRectMin();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetItemRectMax(lua_State *L)
{
	
	ImVec2 out = ImGui::GetItemRectMax();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetItemRectSize(lua_State *L)
{
	
	ImVec2 out = ImGui::GetItemRectSize();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_SetItemAllowOverlap(lua_State *L)
{
	
	ImGui::SetItemAllowOverlap();
	
	return 0;
}

static int w_IsRectVisible(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	
	bool out = ImGui::IsRectVisible(size);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsRectVisible_EX(lua_State *L)
{
	ImVec2 rect_min;
	rect_min.x = luaL_checknumber(L, 1);
	rect_min.y = luaL_checknumber(L, 2);
	ImVec2 rect_max;
	rect_max.x = luaL_checknumber(L, 3);
	rect_max.y = luaL_checknumber(L, 4);
	
	bool out = ImGui::IsRectVisible(rect_min, rect_max);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_GetTime(lua_State *L)
{
	
	double out = ImGui::GetTime();
	
	lua_pushnumber(L, out);
	return 1;
}

static int w_GetFrameCount(lua_State *L)
{
	
	int out = ImGui::GetFrameCount();
	
	lua_pushinteger(L, out);
	return 1;
}

// skipping function due to unimplemented return type "ImDrawList*": ImGui::GetBackgroundDrawList

// skipping function due to unimplemented return type "ImDrawList*": ImGui::GetForegroundDrawList

// skipping function due to unimplemented return type "ImDrawListSharedData*": ImGui::GetDrawListSharedData

static int w_GetStyleColorName(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiCol>(getImGuiColFromString, L, 1);
	
	const char* out = ImGui::GetStyleColorName(idx);
	
	lua_pushstring(L, out);
	return 1;
}

// skipping function due to unimplemented argument type "ImGuiStorage*": ImGui::SetStateStorage

// skipping function due to unimplemented return type "ImGuiStorage*": ImGui::GetStateStorage

static int w_CalcTextSize(lua_State *L)
{
	auto text = luaL_checkstring(L, 1);
	auto text_end = luaL_optstring(L, 2, NULL);
	auto hide_text_after_double_hash = luax_optboolean(L, 3, false);
	auto wrap_width = static_cast<float>(luaL_optnumber(L, 4, -1.0f));
	
	ImVec2 out = ImGui::CalcTextSize(text, text_end, hide_text_after_double_hash, wrap_width);
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_CalcListClipping(lua_State *L)
{
	auto items_count = luaL_checkint(L, 1);
	auto items_height = static_cast<float>(luaL_checknumber(L, 2));
	auto out_items_display_start = luaL_checkint(L, 3);
	auto out_items_display_end = luaL_checkint(L, 4);
	
	ImGui::CalcListClipping(items_count, items_height, &out_items_display_start, &out_items_display_end);
	
	lua_pushinteger(L, out_items_display_start);
	lua_pushinteger(L, out_items_display_end);
	return 2;
}

static int w_BeginChildFrame(lua_State *L)
{
	auto id = static_cast<ImGuiID>(luaL_checkint(L, 1));
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 4, 0);
	
	bool out = ImGui::BeginChildFrame(id, size, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_EndChildFrame(lua_State *L)
{
	
	ImGui::EndChildFrame();
	
	return 0;
}

// skipping function due to unimplemented return type "ImVec4": ImGui::ColorConvertU32ToFloat4

static int w_ColorConvertFloat4ToU32(lua_State *L)
{
	ImVec4 in;
	in.x = luaL_checknumber(L, 1);
	in.y = luaL_checknumber(L, 2);
	in.z = luaL_checknumber(L, 2);
	in.w = luaL_checknumber(L, 2);
	
	ImU32 out = ImGui::ColorConvertFloat4ToU32(in);
	
	lua_pushinteger(L, out);
	return 1;
}

// skipping function due to unimplemented argument type "float&": ImGui::ColorConvertHSVtoRGB

static int w_GetKeyIndex(lua_State *L)
{
	auto imgui_key = luax_checkenum<ImGuiKey>(getImGuiKeyFromString, L, 1);
	
	int out = ImGui::GetKeyIndex(imgui_key);
	
	lua_pushinteger(L, out);
	return 1;
}

static int w_IsKeyDown(lua_State *L)
{
	auto user_key_index = luaL_checkint(L, 1);
	
	bool out = ImGui::IsKeyDown(user_key_index);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsKeyPressed(lua_State *L)
{
	auto user_key_index = luaL_checkint(L, 1);
	auto repeat = luax_optboolean(L, 2, true);
	
	bool out = ImGui::IsKeyPressed(user_key_index, repeat);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsKeyReleased(lua_State *L)
{
	auto user_key_index = luaL_checkint(L, 1);
	
	bool out = ImGui::IsKeyReleased(user_key_index);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_GetKeyPressedAmount(lua_State *L)
{
	auto key_index = luaL_checkint(L, 1);
	auto repeat_delay = static_cast<float>(luaL_checknumber(L, 2));
	auto rate = static_cast<float>(luaL_checknumber(L, 3));
	
	int out = ImGui::GetKeyPressedAmount(key_index, repeat_delay, rate);
	
	lua_pushinteger(L, out);
	return 1;
}

static int w_CaptureKeyboardFromApp(lua_State *L)
{
	auto want_capture_keyboard_value = luax_optboolean(L, 1, true);
	
	ImGui::CaptureKeyboardFromApp(want_capture_keyboard_value);
	
	return 0;
}

static int w_IsMouseDown(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	
	bool out = ImGui::IsMouseDown(button);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsMouseClicked(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	auto repeat = luax_optboolean(L, 2, false);
	
	bool out = ImGui::IsMouseClicked(button, repeat);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsMouseReleased(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	
	bool out = ImGui::IsMouseReleased(button);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsMouseDoubleClicked(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	
	bool out = ImGui::IsMouseDoubleClicked(button);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_IsMouseHoveringRect(lua_State *L)
{
	ImVec2 r_min;
	r_min.x = luaL_checknumber(L, 1);
	r_min.y = luaL_checknumber(L, 2);
	ImVec2 r_max;
	r_max.x = luaL_checknumber(L, 3);
	r_max.y = luaL_checknumber(L, 4);
	auto clip = luax_optboolean(L, 5, true);
	
	bool out = ImGui::IsMouseHoveringRect(r_min, r_max, clip);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping function due to unimplemented argument type "const ImVec2*": ImGui::IsMousePosValid

static int w_IsAnyMouseDown(lua_State *L)
{
	
	bool out = ImGui::IsAnyMouseDown();
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_GetMousePos(lua_State *L)
{
	
	ImVec2 out = ImGui::GetMousePos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_GetMousePosOnOpeningCurrentPopup(lua_State *L)
{
	
	ImVec2 out = ImGui::GetMousePosOnOpeningCurrentPopup();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_IsMouseDragging(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	auto lock_threshold = static_cast<float>(luaL_optnumber(L, 2, -1.0f));
	
	bool out = ImGui::IsMouseDragging(button, lock_threshold);
	
	lua_pushboolean(L, out);
	return 1;
}

static int w_GetMouseDragDelta(lua_State *L)
{
	auto button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1, 0);
	auto lock_threshold = static_cast<float>(luaL_optnumber(L, 2, -1.0f));
	
	ImVec2 out = ImGui::GetMouseDragDelta(button, lock_threshold);
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

static int w_ResetMouseDragDelta(lua_State *L)
{
	auto button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1, 0);
	
	ImGui::ResetMouseDragDelta(button);
	
	return 0;
}

// skipping function due to unimplemented return type "ImGuiMouseCursor": ImGui::GetMouseCursor

static int w_SetMouseCursor(lua_State *L)
{
	auto cursor_type = luax_checkenum<ImGuiMouseCursor>(getImGuiMouseCursorFromString, L, 1);
	
	ImGui::SetMouseCursor(cursor_type);
	
	return 0;
}

static int w_CaptureMouseFromApp(lua_State *L)
{
	auto want_capture_mouse_value = luax_optboolean(L, 1, true);
	
	ImGui::CaptureMouseFromApp(want_capture_mouse_value);
	
	return 0;
}

static int w_GetClipboardText(lua_State *L)
{
	
	const char* out = ImGui::GetClipboardText();
	
	lua_pushstring(L, out);
	return 1;
}

static int w_SetClipboardText(lua_State *L)
{
	auto text = luaL_checkstring(L, 1);
	
	ImGui::SetClipboardText(text);
	
	return 0;
}

static int w_LoadIniSettingsFromDisk(lua_State *L)
{
	auto ini_filename = luaL_checkstring(L, 1);
	
	ImGui::LoadIniSettingsFromDisk(ini_filename);
	
	return 0;
}

// skipping function due to unimplemented argument type "size_t": ImGui::LoadIniSettingsFromMemory

static int w_SaveIniSettingsToDisk(lua_State *L)
{
	auto ini_filename = luaL_checkstring(L, 1);
	
	ImGui::SaveIniSettingsToDisk(ini_filename);
	
	return 0;
}

// skipping function due to unimplemented argument type "size_t*": ImGui::SaveIniSettingsToMemory

// skipping function due to unimplemented argument type "void* (*alloc_func)(size_t sz, void* user_data)": ImGui::SetAllocatorFunctions

// skipping function due to unimplemented argument type "size_t": ImGui::MemAlloc

// skipping function due to unimplemented argument type "void*": ImGui::MemFree


void addImguiWrappers(lua_State* L)
{

	lua_pushcfunction(L, w_NewFrame);
	lua_setfield(L, -2, "NewFrame");

	lua_pushcfunction(L, w_EndFrame);
	lua_setfield(L, -2, "EndFrame");

	lua_pushcfunction(L, w_Render);
	lua_setfield(L, -2, "Render");

	lua_pushcfunction(L, w_ShowDemoWindow);
	lua_setfield(L, -2, "ShowDemoWindow");

	lua_pushcfunction(L, w_ShowAboutWindow);
	lua_setfield(L, -2, "ShowAboutWindow");

	lua_pushcfunction(L, w_ShowMetricsWindow);
	lua_setfield(L, -2, "ShowMetricsWindow");

	lua_pushcfunction(L, w_ShowStyleSelector);
	lua_setfield(L, -2, "ShowStyleSelector");

	lua_pushcfunction(L, w_ShowFontSelector);
	lua_setfield(L, -2, "ShowFontSelector");

	lua_pushcfunction(L, w_ShowUserGuide);
	lua_setfield(L, -2, "ShowUserGuide");

	lua_pushcfunction(L, w_GetVersion);
	lua_setfield(L, -2, "GetVersion");

	lua_pushcfunction(L, w_Begin);
	lua_setfield(L, -2, "Begin");

	lua_pushcfunction(L, w_End);
	lua_setfield(L, -2, "End");

	lua_pushcfunction(L, w_BeginChild);
	lua_setfield(L, -2, "BeginChild");

	lua_pushcfunction(L, w_BeginChild);
	lua_setfield(L, -2, "BeginChild");

	lua_pushcfunction(L, w_EndChild);
	lua_setfield(L, -2, "EndChild");

	lua_pushcfunction(L, w_IsWindowAppearing);
	lua_setfield(L, -2, "IsWindowAppearing");

	lua_pushcfunction(L, w_IsWindowCollapsed);
	lua_setfield(L, -2, "IsWindowCollapsed");

	lua_pushcfunction(L, w_IsWindowFocused);
	lua_setfield(L, -2, "IsWindowFocused");

	lua_pushcfunction(L, w_IsWindowHovered);
	lua_setfield(L, -2, "IsWindowHovered");

	lua_pushcfunction(L, w_GetWindowPos);
	lua_setfield(L, -2, "GetWindowPos");

	lua_pushcfunction(L, w_GetWindowSize);
	lua_setfield(L, -2, "GetWindowSize");

	lua_pushcfunction(L, w_GetWindowWidth);
	lua_setfield(L, -2, "GetWindowWidth");

	lua_pushcfunction(L, w_GetWindowHeight);
	lua_setfield(L, -2, "GetWindowHeight");

	lua_pushcfunction(L, w_SetNextWindowPos);
	lua_setfield(L, -2, "SetNextWindowPos");

	lua_pushcfunction(L, w_SetNextWindowSize);
	lua_setfield(L, -2, "SetNextWindowSize");

	lua_pushcfunction(L, w_SetNextWindowContentSize);
	lua_setfield(L, -2, "SetNextWindowContentSize");

	lua_pushcfunction(L, w_SetNextWindowCollapsed);
	lua_setfield(L, -2, "SetNextWindowCollapsed");

	lua_pushcfunction(L, w_SetNextWindowFocus);
	lua_setfield(L, -2, "SetNextWindowFocus");

	lua_pushcfunction(L, w_SetNextWindowBgAlpha);
	lua_setfield(L, -2, "SetNextWindowBgAlpha");

	lua_pushcfunction(L, w_SetWindowPos);
	lua_setfield(L, -2, "SetWindowPos");

	lua_pushcfunction(L, w_SetWindowSize);
	lua_setfield(L, -2, "SetWindowSize");

	lua_pushcfunction(L, w_SetWindowCollapsed);
	lua_setfield(L, -2, "SetWindowCollapsed");

	lua_pushcfunction(L, w_SetWindowFocus);
	lua_setfield(L, -2, "SetWindowFocus");

	lua_pushcfunction(L, w_SetWindowFontScale);
	lua_setfield(L, -2, "SetWindowFontScale");

	lua_pushcfunction(L, w_SetWindowPos);
	lua_setfield(L, -2, "SetWindowPos");

	lua_pushcfunction(L, w_SetWindowSize);
	lua_setfield(L, -2, "SetWindowSize");

	lua_pushcfunction(L, w_SetWindowCollapsed);
	lua_setfield(L, -2, "SetWindowCollapsed");

	lua_pushcfunction(L, w_SetWindowFocus);
	lua_setfield(L, -2, "SetWindowFocus");

	lua_pushcfunction(L, w_GetContentRegionMax);
	lua_setfield(L, -2, "GetContentRegionMax");

	lua_pushcfunction(L, w_GetContentRegionAvail);
	lua_setfield(L, -2, "GetContentRegionAvail");

	lua_pushcfunction(L, w_GetWindowContentRegionMin);
	lua_setfield(L, -2, "GetWindowContentRegionMin");

	lua_pushcfunction(L, w_GetWindowContentRegionMax);
	lua_setfield(L, -2, "GetWindowContentRegionMax");

	lua_pushcfunction(L, w_GetWindowContentRegionWidth);
	lua_setfield(L, -2, "GetWindowContentRegionWidth");

	lua_pushcfunction(L, w_GetScrollX);
	lua_setfield(L, -2, "GetScrollX");

	lua_pushcfunction(L, w_GetScrollY);
	lua_setfield(L, -2, "GetScrollY");

	lua_pushcfunction(L, w_GetScrollMaxX);
	lua_setfield(L, -2, "GetScrollMaxX");

	lua_pushcfunction(L, w_GetScrollMaxY);
	lua_setfield(L, -2, "GetScrollMaxY");

	lua_pushcfunction(L, w_SetScrollX);
	lua_setfield(L, -2, "SetScrollX");

	lua_pushcfunction(L, w_SetScrollY);
	lua_setfield(L, -2, "SetScrollY");

	lua_pushcfunction(L, w_SetScrollHereX);
	lua_setfield(L, -2, "SetScrollHereX");

	lua_pushcfunction(L, w_SetScrollHereY);
	lua_setfield(L, -2, "SetScrollHereY");

	lua_pushcfunction(L, w_SetScrollFromPosX);
	lua_setfield(L, -2, "SetScrollFromPosX");

	lua_pushcfunction(L, w_SetScrollFromPosY);
	lua_setfield(L, -2, "SetScrollFromPosY");

	lua_pushcfunction(L, w_PopFont);
	lua_setfield(L, -2, "PopFont");

	lua_pushcfunction(L, w_PushStyleColor);
	lua_setfield(L, -2, "PushStyleColor");

	lua_pushcfunction(L, w_PushStyleColor);
	lua_setfield(L, -2, "PushStyleColor");

	lua_pushcfunction(L, w_PopStyleColor);
	lua_setfield(L, -2, "PopStyleColor");

	lua_pushcfunction(L, w_PushStyleVar);
	lua_setfield(L, -2, "PushStyleVar");

	lua_pushcfunction(L, w_PushStyleVar);
	lua_setfield(L, -2, "PushStyleVar");

	lua_pushcfunction(L, w_PopStyleVar);
	lua_setfield(L, -2, "PopStyleVar");

	lua_pushcfunction(L, w_GetFontSize);
	lua_setfield(L, -2, "GetFontSize");

	lua_pushcfunction(L, w_GetFontTexUvWhitePixel);
	lua_setfield(L, -2, "GetFontTexUvWhitePixel");

	lua_pushcfunction(L, w_GetColorU32);
	lua_setfield(L, -2, "GetColorU32");

	lua_pushcfunction(L, w_GetColorU32);
	lua_setfield(L, -2, "GetColorU32");

	lua_pushcfunction(L, w_GetColorU32);
	lua_setfield(L, -2, "GetColorU32");

	lua_pushcfunction(L, w_PushItemWidth);
	lua_setfield(L, -2, "PushItemWidth");

	lua_pushcfunction(L, w_PopItemWidth);
	lua_setfield(L, -2, "PopItemWidth");

	lua_pushcfunction(L, w_SetNextItemWidth);
	lua_setfield(L, -2, "SetNextItemWidth");

	lua_pushcfunction(L, w_CalcItemWidth);
	lua_setfield(L, -2, "CalcItemWidth");

	lua_pushcfunction(L, w_PushTextWrapPos);
	lua_setfield(L, -2, "PushTextWrapPos");

	lua_pushcfunction(L, w_PopTextWrapPos);
	lua_setfield(L, -2, "PopTextWrapPos");

	lua_pushcfunction(L, w_PushAllowKeyboardFocus);
	lua_setfield(L, -2, "PushAllowKeyboardFocus");

	lua_pushcfunction(L, w_PopAllowKeyboardFocus);
	lua_setfield(L, -2, "PopAllowKeyboardFocus");

	lua_pushcfunction(L, w_PushButtonRepeat);
	lua_setfield(L, -2, "PushButtonRepeat");

	lua_pushcfunction(L, w_PopButtonRepeat);
	lua_setfield(L, -2, "PopButtonRepeat");

	lua_pushcfunction(L, w_Separator);
	lua_setfield(L, -2, "Separator");

	lua_pushcfunction(L, w_SameLine);
	lua_setfield(L, -2, "SameLine");

	lua_pushcfunction(L, w_NewLine);
	lua_setfield(L, -2, "NewLine");

	lua_pushcfunction(L, w_Spacing);
	lua_setfield(L, -2, "Spacing");

	lua_pushcfunction(L, w_Dummy);
	lua_setfield(L, -2, "Dummy");

	lua_pushcfunction(L, w_Indent);
	lua_setfield(L, -2, "Indent");

	lua_pushcfunction(L, w_Unindent);
	lua_setfield(L, -2, "Unindent");

	lua_pushcfunction(L, w_BeginGroup);
	lua_setfield(L, -2, "BeginGroup");

	lua_pushcfunction(L, w_EndGroup);
	lua_setfield(L, -2, "EndGroup");

	lua_pushcfunction(L, w_GetCursorPos);
	lua_setfield(L, -2, "GetCursorPos");

	lua_pushcfunction(L, w_GetCursorPosX);
	lua_setfield(L, -2, "GetCursorPosX");

	lua_pushcfunction(L, w_GetCursorPosY);
	lua_setfield(L, -2, "GetCursorPosY");

	lua_pushcfunction(L, w_SetCursorPos);
	lua_setfield(L, -2, "SetCursorPos");

	lua_pushcfunction(L, w_SetCursorPosX);
	lua_setfield(L, -2, "SetCursorPosX");

	lua_pushcfunction(L, w_SetCursorPosY);
	lua_setfield(L, -2, "SetCursorPosY");

	lua_pushcfunction(L, w_GetCursorStartPos);
	lua_setfield(L, -2, "GetCursorStartPos");

	lua_pushcfunction(L, w_GetCursorScreenPos);
	lua_setfield(L, -2, "GetCursorScreenPos");

	lua_pushcfunction(L, w_SetCursorScreenPos);
	lua_setfield(L, -2, "SetCursorScreenPos");

	lua_pushcfunction(L, w_AlignTextToFramePadding);
	lua_setfield(L, -2, "AlignTextToFramePadding");

	lua_pushcfunction(L, w_GetTextLineHeight);
	lua_setfield(L, -2, "GetTextLineHeight");

	lua_pushcfunction(L, w_GetTextLineHeightWithSpacing);
	lua_setfield(L, -2, "GetTextLineHeightWithSpacing");

	lua_pushcfunction(L, w_GetFrameHeight);
	lua_setfield(L, -2, "GetFrameHeight");

	lua_pushcfunction(L, w_GetFrameHeightWithSpacing);
	lua_setfield(L, -2, "GetFrameHeightWithSpacing");

	lua_pushcfunction(L, w_PushID);
	lua_setfield(L, -2, "PushID");

	lua_pushcfunction(L, w_PushID);
	lua_setfield(L, -2, "PushID");

	lua_pushcfunction(L, w_PushID);
	lua_setfield(L, -2, "PushID");

	lua_pushcfunction(L, w_PopID);
	lua_setfield(L, -2, "PopID");

	lua_pushcfunction(L, w_GetID);
	lua_setfield(L, -2, "GetID");

	lua_pushcfunction(L, w_GetID);
	lua_setfield(L, -2, "GetID");

	lua_pushcfunction(L, w_TextUnformatted);
	lua_setfield(L, -2, "TextUnformatted");

	lua_pushcfunction(L, w_Button);
	lua_setfield(L, -2, "Button");

	lua_pushcfunction(L, w_SmallButton);
	lua_setfield(L, -2, "SmallButton");

	lua_pushcfunction(L, w_InvisibleButton);
	lua_setfield(L, -2, "InvisibleButton");

	lua_pushcfunction(L, w_ArrowButton);
	lua_setfield(L, -2, "ArrowButton");

	lua_pushcfunction(L, w_Checkbox);
	lua_setfield(L, -2, "Checkbox");

	lua_pushcfunction(L, w_CheckboxFlags);
	lua_setfield(L, -2, "CheckboxFlags");

	lua_pushcfunction(L, w_RadioButton);
	lua_setfield(L, -2, "RadioButton");

	lua_pushcfunction(L, w_RadioButton);
	lua_setfield(L, -2, "RadioButton");

	lua_pushcfunction(L, w_ProgressBar);
	lua_setfield(L, -2, "ProgressBar");

	lua_pushcfunction(L, w_Bullet);
	lua_setfield(L, -2, "Bullet");

	lua_pushcfunction(L, w_BeginCombo);
	lua_setfield(L, -2, "BeginCombo");

	lua_pushcfunction(L, w_EndCombo);
	lua_setfield(L, -2, "EndCombo");

	lua_pushcfunction(L, w_Combo);
	lua_setfield(L, -2, "Combo");

	lua_pushcfunction(L, w_DragFloat);
	lua_setfield(L, -2, "DragFloat");

	lua_pushcfunction(L, w_DragFloat2);
	lua_setfield(L, -2, "DragFloat2");

	lua_pushcfunction(L, w_DragFloat3);
	lua_setfield(L, -2, "DragFloat3");

	lua_pushcfunction(L, w_DragFloat4);
	lua_setfield(L, -2, "DragFloat4");

	lua_pushcfunction(L, w_DragFloatRange2);
	lua_setfield(L, -2, "DragFloatRange2");

	lua_pushcfunction(L, w_DragInt);
	lua_setfield(L, -2, "DragInt");

	lua_pushcfunction(L, w_DragInt2);
	lua_setfield(L, -2, "DragInt2");

	lua_pushcfunction(L, w_DragInt3);
	lua_setfield(L, -2, "DragInt3");

	lua_pushcfunction(L, w_DragInt4);
	lua_setfield(L, -2, "DragInt4");

	lua_pushcfunction(L, w_DragIntRange2);
	lua_setfield(L, -2, "DragIntRange2");

	lua_pushcfunction(L, w_SliderFloat);
	lua_setfield(L, -2, "SliderFloat");

	lua_pushcfunction(L, w_SliderFloat2);
	lua_setfield(L, -2, "SliderFloat2");

	lua_pushcfunction(L, w_SliderFloat3);
	lua_setfield(L, -2, "SliderFloat3");

	lua_pushcfunction(L, w_SliderFloat4);
	lua_setfield(L, -2, "SliderFloat4");

	lua_pushcfunction(L, w_SliderAngle);
	lua_setfield(L, -2, "SliderAngle");

	lua_pushcfunction(L, w_SliderInt);
	lua_setfield(L, -2, "SliderInt");

	lua_pushcfunction(L, w_SliderInt2);
	lua_setfield(L, -2, "SliderInt2");

	lua_pushcfunction(L, w_SliderInt3);
	lua_setfield(L, -2, "SliderInt3");

	lua_pushcfunction(L, w_SliderInt4);
	lua_setfield(L, -2, "SliderInt4");

	lua_pushcfunction(L, w_VSliderFloat);
	lua_setfield(L, -2, "VSliderFloat");

	lua_pushcfunction(L, w_VSliderInt);
	lua_setfield(L, -2, "VSliderInt");

	lua_pushcfunction(L, w_InputFloat);
	lua_setfield(L, -2, "InputFloat");

	lua_pushcfunction(L, w_InputFloat2);
	lua_setfield(L, -2, "InputFloat2");

	lua_pushcfunction(L, w_InputFloat3);
	lua_setfield(L, -2, "InputFloat3");

	lua_pushcfunction(L, w_InputFloat4);
	lua_setfield(L, -2, "InputFloat4");

	lua_pushcfunction(L, w_InputInt);
	lua_setfield(L, -2, "InputInt");

	lua_pushcfunction(L, w_InputInt2);
	lua_setfield(L, -2, "InputInt2");

	lua_pushcfunction(L, w_InputInt3);
	lua_setfield(L, -2, "InputInt3");

	lua_pushcfunction(L, w_InputInt4);
	lua_setfield(L, -2, "InputInt4");

	lua_pushcfunction(L, w_InputDouble);
	lua_setfield(L, -2, "InputDouble");

	lua_pushcfunction(L, w_ColorEdit3);
	lua_setfield(L, -2, "ColorEdit3");

	lua_pushcfunction(L, w_ColorEdit4);
	lua_setfield(L, -2, "ColorEdit4");

	lua_pushcfunction(L, w_ColorPicker3);
	lua_setfield(L, -2, "ColorPicker3");

	lua_pushcfunction(L, w_ColorButton);
	lua_setfield(L, -2, "ColorButton");

	lua_pushcfunction(L, w_SetColorEditOptions);
	lua_setfield(L, -2, "SetColorEditOptions");

	lua_pushcfunction(L, w_TreeNode);
	lua_setfield(L, -2, "TreeNode");

	lua_pushcfunction(L, w_TreeNodeEx);
	lua_setfield(L, -2, "TreeNodeEx");

	lua_pushcfunction(L, w_TreePush);
	lua_setfield(L, -2, "TreePush");

	lua_pushcfunction(L, w_TreePop);
	lua_setfield(L, -2, "TreePop");

	lua_pushcfunction(L, w_GetTreeNodeToLabelSpacing);
	lua_setfield(L, -2, "GetTreeNodeToLabelSpacing");

	lua_pushcfunction(L, w_CollapsingHeader);
	lua_setfield(L, -2, "CollapsingHeader");

	lua_pushcfunction(L, w_CollapsingHeader);
	lua_setfield(L, -2, "CollapsingHeader");

	lua_pushcfunction(L, w_SetNextItemOpen);
	lua_setfield(L, -2, "SetNextItemOpen");

	lua_pushcfunction(L, w_Selectable);
	lua_setfield(L, -2, "Selectable");

	lua_pushcfunction(L, w_Selectable);
	lua_setfield(L, -2, "Selectable");

	lua_pushcfunction(L, w_ListBoxHeader);
	lua_setfield(L, -2, "ListBoxHeader");

	lua_pushcfunction(L, w_ListBoxHeader);
	lua_setfield(L, -2, "ListBoxHeader");

	lua_pushcfunction(L, w_ListBoxFooter);
	lua_setfield(L, -2, "ListBoxFooter");

	lua_pushcfunction(L, w_Value);
	lua_setfield(L, -2, "Value");

	lua_pushcfunction(L, w_Value);
	lua_setfield(L, -2, "Value");

	lua_pushcfunction(L, w_Value);
	lua_setfield(L, -2, "Value");

	lua_pushcfunction(L, w_Value);
	lua_setfield(L, -2, "Value");

	lua_pushcfunction(L, w_BeginMenuBar);
	lua_setfield(L, -2, "BeginMenuBar");

	lua_pushcfunction(L, w_EndMenuBar);
	lua_setfield(L, -2, "EndMenuBar");

	lua_pushcfunction(L, w_BeginMainMenuBar);
	lua_setfield(L, -2, "BeginMainMenuBar");

	lua_pushcfunction(L, w_EndMainMenuBar);
	lua_setfield(L, -2, "EndMainMenuBar");

	lua_pushcfunction(L, w_BeginMenu);
	lua_setfield(L, -2, "BeginMenu");

	lua_pushcfunction(L, w_EndMenu);
	lua_setfield(L, -2, "EndMenu");

	lua_pushcfunction(L, w_MenuItem);
	lua_setfield(L, -2, "MenuItem");

	lua_pushcfunction(L, w_MenuItem);
	lua_setfield(L, -2, "MenuItem");

	lua_pushcfunction(L, w_BeginTooltip);
	lua_setfield(L, -2, "BeginTooltip");

	lua_pushcfunction(L, w_EndTooltip);
	lua_setfield(L, -2, "EndTooltip");

	lua_pushcfunction(L, w_OpenPopup);
	lua_setfield(L, -2, "OpenPopup");

	lua_pushcfunction(L, w_BeginPopup);
	lua_setfield(L, -2, "BeginPopup");

	lua_pushcfunction(L, w_BeginPopupContextItem);
	lua_setfield(L, -2, "BeginPopupContextItem");

	lua_pushcfunction(L, w_BeginPopupContextWindow);
	lua_setfield(L, -2, "BeginPopupContextWindow");

	lua_pushcfunction(L, w_BeginPopupContextVoid);
	lua_setfield(L, -2, "BeginPopupContextVoid");

	lua_pushcfunction(L, w_BeginPopupModal);
	lua_setfield(L, -2, "BeginPopupModal");

	lua_pushcfunction(L, w_EndPopup);
	lua_setfield(L, -2, "EndPopup");

	lua_pushcfunction(L, w_OpenPopupOnItemClick);
	lua_setfield(L, -2, "OpenPopupOnItemClick");

	lua_pushcfunction(L, w_IsPopupOpen);
	lua_setfield(L, -2, "IsPopupOpen");

	lua_pushcfunction(L, w_CloseCurrentPopup);
	lua_setfield(L, -2, "CloseCurrentPopup");

	lua_pushcfunction(L, w_Columns);
	lua_setfield(L, -2, "Columns");

	lua_pushcfunction(L, w_NextColumn);
	lua_setfield(L, -2, "NextColumn");

	lua_pushcfunction(L, w_GetColumnIndex);
	lua_setfield(L, -2, "GetColumnIndex");

	lua_pushcfunction(L, w_GetColumnWidth);
	lua_setfield(L, -2, "GetColumnWidth");

	lua_pushcfunction(L, w_SetColumnWidth);
	lua_setfield(L, -2, "SetColumnWidth");

	lua_pushcfunction(L, w_GetColumnOffset);
	lua_setfield(L, -2, "GetColumnOffset");

	lua_pushcfunction(L, w_SetColumnOffset);
	lua_setfield(L, -2, "SetColumnOffset");

	lua_pushcfunction(L, w_GetColumnsCount);
	lua_setfield(L, -2, "GetColumnsCount");

	lua_pushcfunction(L, w_BeginTabBar);
	lua_setfield(L, -2, "BeginTabBar");

	lua_pushcfunction(L, w_EndTabBar);
	lua_setfield(L, -2, "EndTabBar");

	lua_pushcfunction(L, w_BeginTabItem);
	lua_setfield(L, -2, "BeginTabItem");

	lua_pushcfunction(L, w_EndTabItem);
	lua_setfield(L, -2, "EndTabItem");

	lua_pushcfunction(L, w_SetTabItemClosed);
	lua_setfield(L, -2, "SetTabItemClosed");

	lua_pushcfunction(L, w_LogToTTY);
	lua_setfield(L, -2, "LogToTTY");

	lua_pushcfunction(L, w_LogToFile);
	lua_setfield(L, -2, "LogToFile");

	lua_pushcfunction(L, w_LogToClipboard);
	lua_setfield(L, -2, "LogToClipboard");

	lua_pushcfunction(L, w_LogFinish);
	lua_setfield(L, -2, "LogFinish");

	lua_pushcfunction(L, w_LogButtons);
	lua_setfield(L, -2, "LogButtons");

	lua_pushcfunction(L, w_BeginDragDropSource);
	lua_setfield(L, -2, "BeginDragDropSource");

	lua_pushcfunction(L, w_EndDragDropSource);
	lua_setfield(L, -2, "EndDragDropSource");

	lua_pushcfunction(L, w_BeginDragDropTarget);
	lua_setfield(L, -2, "BeginDragDropTarget");

	lua_pushcfunction(L, w_EndDragDropTarget);
	lua_setfield(L, -2, "EndDragDropTarget");

	lua_pushcfunction(L, w_PushClipRect);
	lua_setfield(L, -2, "PushClipRect");

	lua_pushcfunction(L, w_PopClipRect);
	lua_setfield(L, -2, "PopClipRect");

	lua_pushcfunction(L, w_SetItemDefaultFocus);
	lua_setfield(L, -2, "SetItemDefaultFocus");

	lua_pushcfunction(L, w_SetKeyboardFocusHere);
	lua_setfield(L, -2, "SetKeyboardFocusHere");

	lua_pushcfunction(L, w_IsItemHovered);
	lua_setfield(L, -2, "IsItemHovered");

	lua_pushcfunction(L, w_IsItemActive);
	lua_setfield(L, -2, "IsItemActive");

	lua_pushcfunction(L, w_IsItemFocused);
	lua_setfield(L, -2, "IsItemFocused");

	lua_pushcfunction(L, w_IsItemClicked);
	lua_setfield(L, -2, "IsItemClicked");

	lua_pushcfunction(L, w_IsItemVisible);
	lua_setfield(L, -2, "IsItemVisible");

	lua_pushcfunction(L, w_IsItemEdited);
	lua_setfield(L, -2, "IsItemEdited");

	lua_pushcfunction(L, w_IsItemActivated);
	lua_setfield(L, -2, "IsItemActivated");

	lua_pushcfunction(L, w_IsItemDeactivated);
	lua_setfield(L, -2, "IsItemDeactivated");

	lua_pushcfunction(L, w_IsItemDeactivatedAfterEdit);
	lua_setfield(L, -2, "IsItemDeactivatedAfterEdit");

	lua_pushcfunction(L, w_IsItemToggledOpen);
	lua_setfield(L, -2, "IsItemToggledOpen");

	lua_pushcfunction(L, w_IsAnyItemHovered);
	lua_setfield(L, -2, "IsAnyItemHovered");

	lua_pushcfunction(L, w_IsAnyItemActive);
	lua_setfield(L, -2, "IsAnyItemActive");

	lua_pushcfunction(L, w_IsAnyItemFocused);
	lua_setfield(L, -2, "IsAnyItemFocused");

	lua_pushcfunction(L, w_GetItemRectMin);
	lua_setfield(L, -2, "GetItemRectMin");

	lua_pushcfunction(L, w_GetItemRectMax);
	lua_setfield(L, -2, "GetItemRectMax");

	lua_pushcfunction(L, w_GetItemRectSize);
	lua_setfield(L, -2, "GetItemRectSize");

	lua_pushcfunction(L, w_SetItemAllowOverlap);
	lua_setfield(L, -2, "SetItemAllowOverlap");

	lua_pushcfunction(L, w_IsRectVisible);
	lua_setfield(L, -2, "IsRectVisible");

	lua_pushcfunction(L, w_IsRectVisible);
	lua_setfield(L, -2, "IsRectVisible");

	lua_pushcfunction(L, w_GetTime);
	lua_setfield(L, -2, "GetTime");

	lua_pushcfunction(L, w_GetFrameCount);
	lua_setfield(L, -2, "GetFrameCount");

	lua_pushcfunction(L, w_GetStyleColorName);
	lua_setfield(L, -2, "GetStyleColorName");

	lua_pushcfunction(L, w_CalcTextSize);
	lua_setfield(L, -2, "CalcTextSize");

	lua_pushcfunction(L, w_CalcListClipping);
	lua_setfield(L, -2, "CalcListClipping");

	lua_pushcfunction(L, w_BeginChildFrame);
	lua_setfield(L, -2, "BeginChildFrame");

	lua_pushcfunction(L, w_EndChildFrame);
	lua_setfield(L, -2, "EndChildFrame");

	lua_pushcfunction(L, w_ColorConvertFloat4ToU32);
	lua_setfield(L, -2, "ColorConvertFloat4ToU32");

	lua_pushcfunction(L, w_GetKeyIndex);
	lua_setfield(L, -2, "GetKeyIndex");

	lua_pushcfunction(L, w_IsKeyDown);
	lua_setfield(L, -2, "IsKeyDown");

	lua_pushcfunction(L, w_IsKeyPressed);
	lua_setfield(L, -2, "IsKeyPressed");

	lua_pushcfunction(L, w_IsKeyReleased);
	lua_setfield(L, -2, "IsKeyReleased");

	lua_pushcfunction(L, w_GetKeyPressedAmount);
	lua_setfield(L, -2, "GetKeyPressedAmount");

	lua_pushcfunction(L, w_CaptureKeyboardFromApp);
	lua_setfield(L, -2, "CaptureKeyboardFromApp");

	lua_pushcfunction(L, w_IsMouseDown);
	lua_setfield(L, -2, "IsMouseDown");

	lua_pushcfunction(L, w_IsMouseClicked);
	lua_setfield(L, -2, "IsMouseClicked");

	lua_pushcfunction(L, w_IsMouseReleased);
	lua_setfield(L, -2, "IsMouseReleased");

	lua_pushcfunction(L, w_IsMouseDoubleClicked);
	lua_setfield(L, -2, "IsMouseDoubleClicked");

	lua_pushcfunction(L, w_IsMouseHoveringRect);
	lua_setfield(L, -2, "IsMouseHoveringRect");

	lua_pushcfunction(L, w_IsAnyMouseDown);
	lua_setfield(L, -2, "IsAnyMouseDown");

	lua_pushcfunction(L, w_GetMousePos);
	lua_setfield(L, -2, "GetMousePos");

	lua_pushcfunction(L, w_GetMousePosOnOpeningCurrentPopup);
	lua_setfield(L, -2, "GetMousePosOnOpeningCurrentPopup");

	lua_pushcfunction(L, w_IsMouseDragging);
	lua_setfield(L, -2, "IsMouseDragging");

	lua_pushcfunction(L, w_GetMouseDragDelta);
	lua_setfield(L, -2, "GetMouseDragDelta");

	lua_pushcfunction(L, w_ResetMouseDragDelta);
	lua_setfield(L, -2, "ResetMouseDragDelta");

	lua_pushcfunction(L, w_SetMouseCursor);
	lua_setfield(L, -2, "SetMouseCursor");

	lua_pushcfunction(L, w_CaptureMouseFromApp);
	lua_setfield(L, -2, "CaptureMouseFromApp");

	lua_pushcfunction(L, w_GetClipboardText);
	lua_setfield(L, -2, "GetClipboardText");

	lua_pushcfunction(L, w_SetClipboardText);
	lua_setfield(L, -2, "SetClipboardText");

	lua_pushcfunction(L, w_LoadIniSettingsFromDisk);
	lua_setfield(L, -2, "LoadIniSettingsFromDisk");

	lua_pushcfunction(L, w_SaveIniSettingsToDisk);
	lua_setfield(L, -2, "SaveIniSettingsToDisk");

}

void createImguiTable(lua_State* L)
{
	lua_createtable(L, 0, 266); 
	addImguiWrappers(L);
}
