// This is an automatically generated file!!

#include "wrap_imgui_codegen.h"
#include "imgui.h"
#include "imgui_stdlib.h"

#include <optional>
#include <string>
#include <vector>
#include <sstream>
#include <locale>
#include <codecvt>

extern ImTextureID luax_checkTextureID(lua_State* L, int narg); // define in your application

namespace {
// Helpers {{{
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

void* luax_checklightuserdata(lua_State* L, int narg)
{
	if(!lua_islightuserdata(L, narg)) {
		luaL_error(L, "Invalid lightuserdata passed as parameter %d", narg);
		return nullptr;
	}
	return lua_touserdata(L, narg);
}

void* luax_optlightuserdata(lua_State* L, int narg, void* d)
{
	if(lua_isnoneornil(L, narg)) {
		return d;
	}
	return luax_checklightuserdata(L, narg);
}

const char* luax_formatargs(lua_State* L, int startarg)
{
	int endarg = lua_gettop(L);

	lua_getglobal(L, "string"); // 1
	lua_getfield(L, -1, "format"); // 2
	lua_remove(L, -2); // 1, remove string
	for (int i = startarg; i <= endarg; ++i) {
		lua_pushvalue(L, i);
	} // 1 + args
	// out = string.format(...)
	lua_call(L, endarg - startarg + 1, 1); // 1
	const char* out = luaL_checkstring(L, -1); // 1
	lua_pop(L, 1); // 0

	return out;
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
	T out{};
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
	T out{};
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

std::vector<const char*> luax_checkstringvector(lua_State* L, int narg)
{
	if(!lua_istable(L, narg)) {
		luaL_error(L, "Invalid table passed as parameter %d", narg);
	}

	std::vector<const char*> out;
	int idx = 1;
	lua_rawgeti(L, narg, idx);
	while (!lua_isnil(L, -1)) {
		out.emplace_back(luaL_checkstring(L, -1));
		lua_pop(L, 1);
		idx++;
		lua_rawgeti(L, narg, idx);
	}

	return out;
}

std::vector<float> luax_checkfloatvector(lua_State* L, int narg)
{
	if(!lua_istable(L, narg)) {
		luaL_error(L, "Invalid table passed as parameter %d", narg);
	}

	std::vector<float> out;
	int idx = 1;
	lua_rawgeti(L, narg, idx);
	while (!lua_isnil(L, -1)) {
		out.emplace_back(static_cast<float>(luaL_checknumber(L, -1)));
		lua_pop(L, 1);
		idx++;
		lua_rawgeti(L, narg, idx);
	}

	return out;
}
// End Helpers }}}

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

// Callbacks {{{
struct FuncRef {
	lua_State* L = nullptr;
	int index = 0;
};

int callLuaInputTextCallback(ImGuiInputTextCallbackData *data)
{
	auto* ref = reinterpret_cast<FuncRef*>(data->UserData);
	if(!ref) {
		return 0; // no lua ref
	}
	lua_State* L = ref->L;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ref->index);
	luaL_unref(L, LUA_REGISTRYINDEX, ref->index);

	// TODO: metatable to add/remove from buffer
	lua_newtable(L);
	lua_pushvalue(L, -1); //copy for later
	
	lua_pushstring(L, getStringFromImGuiInputTextFlags(data->EventFlag));
	lua_setfield(L, -2, "EventFlag");

	lua_pushlstring(L, data->Buf, data->BufTextLen);
	lua_setfield(L, -2, "Buf");

	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
	if(data->Flags & ImGuiInputTextFlags_CallbackCharFilter) {
		ImWchar k = data->EventChar;
		std::string u8str = convert.to_bytes(k);
		lua_pushlstring(L, u8str.c_str(), u8str.size());
		lua_setfield(L, -2, "EventChar");
	}
	if (data->Flags & (ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory)) {
		lua_pushstring(L, getStringFromImGuiKey(data->EventKey));
		lua_setfield(L, -2, "EventKey");
	}
	if (data->Flags & (ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory | ImGuiInputTextFlags_CallbackAlways)) {
		lua_pushinteger(L, data->CursorPos);
		lua_setfield(L, -2, "CursorPos");
		lua_pushinteger(L, data->SelectionStart);
		lua_setfield(L, -2, "SelectionStart");
		lua_pushinteger(L, data->SelectionEnd);
		lua_setfield(L, -2, "SelectionEnd");
	}

	lua_call(L, 1, 1);
	int out = lua_tointeger(L, -1);
	lua_pop(L, 1);

	if(data->Flags & ImGuiInputTextFlags_CallbackCharFilter) {
		lua_getfield(L, -2, "EventChar");
		const char* k = lua_tostring(L, -1);
		std::u16string u16str = convert.from_bytes(k);
		data->EventChar = u16str.at(0);
		lua_pop(L, 1);
	}
	delete ref;
	data->UserData = nullptr;
	return out;
}

void* luax_getImguiInputTextCallback(lua_State* L, int narg)
{
	ptrdiff_t ref = 0;
	if (lua_isfunction(L, narg)) {
		auto* ref = new FuncRef;
		ref->L = L;
		lua_pushvalue(L, narg);
		ref->index = luaL_ref(L, LUA_REGISTRYINDEX);
		return ref;
	}
	return nullptr;
}
// End Callbacks }}}

// Functions {{{

int w_CreateContext(lua_State *L)
{
	ImFontAtlas* shared_font_atlas = NULL; // skipping
	
	ImGuiContext* out = ImGui::CreateContext(shared_font_atlas);
	
	lua_pushlightuserdata(L, out);
	return 1;
}

/*  NULL = destroy current context */
int w_DestroyContext(lua_State *L)
{
	auto ctx = static_cast<ImGuiContext*>(luax_optlightuserdata(L, 1, NULL));
	
	ImGui::DestroyContext(ctx);
	
	return 0;
}

int w_GetCurrentContext(lua_State *L)
{
	ImGuiContext* out = ImGui::GetCurrentContext();
	
	lua_pushlightuserdata(L, out);
	return 1;
}

int w_SetCurrentContext(lua_State *L)
{
	auto ctx = static_cast<ImGuiContext*>(luax_checklightuserdata(L, 1));
	
	ImGui::SetCurrentContext(ctx);
	
	return 0;
}

// skipping w_GetIO due to unimplemented return type: "ImGuiIO&"

/*  access the Style structure (colors, sizes). Always use PushStyleCol(), PushStyleVar() to modify style mid-frame. */
int w_GetStyle(lua_State *L)
{
	ImGuiStyle& out = ImGui::GetStyle();
	
	lua_pushlightuserdata(L, &out);
	return 1;
}

/*  start a new Dear ImGui frame, you can submit any command from this point until Render()/EndFrame(). */
int w_NewFrame(lua_State *L)
{
	ImGui::NewFrame();
	
	return 0;
}

/*  ends the Dear ImGui frame. automatically called by Render(), you likely don't need to call that yourself directly. If you don't need to render data (skipping rendering) you may call EndFrame() but you'll have wasted CPU already! If you don't need to render, better to not create any imgui windows and not call NewFrame() at all! */
int w_EndFrame(lua_State *L)
{
	ImGui::EndFrame();
	
	return 0;
}

/*  ends the Dear ImGui frame, finalize the draw data. You can get call GetDrawData() to obtain it and run your rendering function. (Obsolete: this used to call io.RenderDrawListsFn(). Nowadays, we allow and prefer calling your render function yourself.) */
int w_Render(lua_State *L)
{
	ImGui::Render();
	
	return 0;
}

// skipping w_GetDrawData due to unimplemented return type: "ImDrawData*"

/*  create Demo window (previously called ShowTestWindow). demonstrate most ImGui features. call this to learn about the library! try to make it always available in your application! */
int w_ShowDemoWindow(lua_State *L)
{
	bool p_open = luax_optboolean(L, 1, NULL);
	
	ImGui::ShowDemoWindow(&p_open);
	
	lua_pushboolean(L, p_open);
	return 1;
}

/*  create About window. display Dear ImGui version, credits and build/system information. */
int w_ShowAboutWindow(lua_State *L)
{
	bool p_open = luax_optboolean(L, 1, NULL);
	
	ImGui::ShowAboutWindow(&p_open);
	
	lua_pushboolean(L, p_open);
	return 1;
}

/*  create Metrics/Debug window. display Dear ImGui internals: draw commands (with individual draw calls and vertices), window list, basic internal state, etc. */
int w_ShowMetricsWindow(lua_State *L)
{
	bool p_open = luax_optboolean(L, 1, NULL);
	
	ImGui::ShowMetricsWindow(&p_open);
	
	lua_pushboolean(L, p_open);
	return 1;
}

/*  add style editor block (not a window). you can pass in a reference ImGuiStyle structure to compare to, revert to and save to (else it uses the default style) */
int w_ShowStyleEditor(lua_State *L)
{
	auto ref = static_cast<ImGuiStyle*>(luax_optlightuserdata(L, 1, NULL));
	
	ImGui::ShowStyleEditor(ref);
	
	return 0;
}

/*  add style selector block (not a window), essentially a combo listing the default styles. */
int w_ShowStyleSelector(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	
	bool out = ImGui::ShowStyleSelector(label);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  add font selector block (not a window), essentially a combo listing the loaded fonts. */
int w_ShowFontSelector(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	
	ImGui::ShowFontSelector(label);
	
	return 0;
}

/*  add basic help/info block (not a window): how to manipulate ImGui as a end-user (mouse/keyboard controls). */
int w_ShowUserGuide(lua_State *L)
{
	ImGui::ShowUserGuide();
	
	return 0;
}

/*  get the compiled version string e.g. "1.23" (essentially the compiled value for IMGUI_VERSION) */
int w_GetVersion(lua_State *L)
{
	const char* out = ImGui::GetVersion();
	
	lua_pushstring(L, out);
	return 1;
}

/*  new, recommended style (default) */
int w_StyleColorsDark(lua_State *L)
{
	auto dst = static_cast<ImGuiStyle*>(luax_optlightuserdata(L, 1, NULL));
	
	ImGui::StyleColorsDark(dst);
	
	return 0;
}

/*  classic imgui style */
int w_StyleColorsClassic(lua_State *L)
{
	auto dst = static_cast<ImGuiStyle*>(luax_optlightuserdata(L, 1, NULL));
	
	ImGui::StyleColorsClassic(dst);
	
	return 0;
}

/*  best used with borders and a custom, thicker font */
int w_StyleColorsLight(lua_State *L)
{
	auto dst = static_cast<ImGuiStyle*>(luax_optlightuserdata(L, 1, NULL));
	
	ImGui::StyleColorsLight(dst);
	
	return 0;
}

int w_Begin(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	bool p_open = luax_optboolean(L, 2, NULL);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 3, 0);
	
	bool out = ImGui::Begin(name, &p_open, flags);
	
	lua_pushboolean(L, p_open);
	lua_pushboolean(L, out);
	return 2;
}

int w_End(lua_State *L)
{
	ImGui::End();
	
	return 0;
}

int w_BeginChild_Override1(lua_State *L)
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

int w_BeginChild_Override2(lua_State *L)
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

int w_EndChild(lua_State *L)
{
	ImGui::EndChild();
	
	return 0;
}

int w_IsWindowAppearing(lua_State *L)
{
	bool out = ImGui::IsWindowAppearing();
	
	lua_pushboolean(L, out);
	return 1;
}

int w_IsWindowCollapsed(lua_State *L)
{
	bool out = ImGui::IsWindowCollapsed();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is current window focused? or its root/child, depending on flags. see flags for options. */
int w_IsWindowFocused(lua_State *L)
{
	auto flags = luax_optflags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, L, 1, 0);
	
	bool out = ImGui::IsWindowFocused(flags);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is current window hovered (and typically: not blocked by a popup/modal)? see flags for options. NB: If you are trying to check whether your mouse should be dispatched to imgui or to your app, you should use the 'io.WantCaptureMouse' boolean for that! Please read the FAQ! */
int w_IsWindowHovered(lua_State *L)
{
	auto flags = luax_optflags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, L, 1, 0);
	
	bool out = ImGui::IsWindowHovered(flags);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping w_GetWindowDrawList due to unimplemented return type: "ImDrawList*"

/*  get DPI scale currently associated to the current window's viewport. */
int w_GetWindowDpiScale(lua_State *L)
{
	float out = ImGui::GetWindowDpiScale();
	
	lua_pushnumber(L, out);
	return 1;
}

// skipping w_GetWindowViewport due to unimplemented return type: "ImGuiViewport*"

/*  get current window position in screen space (useful if you want to do your own drawing via the DrawList API) */
int w_GetWindowPos(lua_State *L)
{
	ImVec2 out = ImGui::GetWindowPos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  get current window size */
int w_GetWindowSize(lua_State *L)
{
	ImVec2 out = ImGui::GetWindowSize();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  get current window width (shortcut for GetWindowSize().x) */
int w_GetWindowWidth(lua_State *L)
{
	float out = ImGui::GetWindowWidth();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  get current window height (shortcut for GetWindowSize().y) */
int w_GetWindowHeight(lua_State *L)
{
	float out = ImGui::GetWindowHeight();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  set next window position. call before Begin(). use pivot=(0.5f,0.5f) to center on given point, etc. */
int w_SetNextWindowPos(lua_State *L)
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

/*  set next window size. set axis to 0.0f to force an auto-fit on this axis. call before Begin() */
int w_SetNextWindowSize(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	
	ImGui::SetNextWindowSize(size, cond);
	
	return 0;
}

// skipping w_SetNextWindowSizeConstraints due to unimplemented argument type: "ImGuiSizeCallback"

/*  set next window content size (~ scrollable client area, which enforce the range of scrollbars). Not including window decorations (title bar, menu bar, etc.) nor WindowPadding. set an axis to 0.0f to leave it automatic. call before Begin() */
int w_SetNextWindowContentSize(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	
	ImGui::SetNextWindowContentSize(size);
	
	return 0;
}

/*  set next window collapsed state. call before Begin() */
int w_SetNextWindowCollapsed(lua_State *L)
{
	auto collapsed = luax_checkboolean(L, 1);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 2, 0);
	
	ImGui::SetNextWindowCollapsed(collapsed, cond);
	
	return 0;
}

/*  set next window to be focused / top-most. call before Begin() */
int w_SetNextWindowFocus(lua_State *L)
{
	ImGui::SetNextWindowFocus();
	
	return 0;
}

/*  set next window background color alpha. helper to easily override the Alpha component of ImGuiCol_WindowBg/ChildBg/PopupBg. you may also use ImGuiWindowFlags_NoBackground. */
int w_SetNextWindowBgAlpha(lua_State *L)
{
	auto alpha = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetNextWindowBgAlpha(alpha);
	
	return 0;
}

/*  set next window viewport */
int w_SetNextWindowViewport(lua_State *L)
{
	auto viewport_id = static_cast<ImGuiID>(luaL_checkint(L, 1));
	
	ImGui::SetNextWindowViewport(viewport_id);
	
	return 0;
}

/*  (not recommended) set current window position - call within Begin()/End(). prefer using SetNextWindowPos(), as this may incur tearing and side-effects. */
int w_SetWindowPos_Override1(lua_State *L)
{
	ImVec2 pos;
	pos.x = luaL_checknumber(L, 1);
	pos.y = luaL_checknumber(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	
	ImGui::SetWindowPos(pos, cond);
	
	return 0;
}

/*  (not recommended) set current window size - call within Begin()/End(). set to ImVec2(0,0) to force an auto-fit. prefer using SetNextWindowSize(), as this may incur tearing and minor side-effects. */
int w_SetWindowSize_Override1(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	
	ImGui::SetWindowSize(size, cond);
	
	return 0;
}

/*  (not recommended) set current window collapsed state. prefer using SetNextWindowCollapsed(). */
int w_SetWindowCollapsed_Override1(lua_State *L)
{
	auto collapsed = luax_checkboolean(L, 1);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 2, 0);
	
	ImGui::SetWindowCollapsed(collapsed, cond);
	
	return 0;
}

/*  (not recommended) set current window to be focused / top-most. prefer using SetNextWindowFocus(). */
int w_SetWindowFocus_Override1(lua_State *L)
{
	ImGui::SetWindowFocus();
	
	return 0;
}

/*  set font scale. Adjust IO.FontGlobalScale if you want to scale all windows. This is an old API! For correct scaling, prefer to reload font + rebuild ImFontAtlas + call style.ScaleAllSizes(). */
int w_SetWindowFontScale(lua_State *L)
{
	auto scale = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetWindowFontScale(scale);
	
	return 0;
}

/*  set named window position. */
int w_SetWindowPos_Override2(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	ImVec2 pos;
	pos.x = luaL_checknumber(L, 2);
	pos.y = luaL_checknumber(L, 3);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 4, 0);
	
	ImGui::SetWindowPos(name, pos, cond);
	
	return 0;
}

/*  set named window size. set axis to 0.0f to force an auto-fit on this axis. */
int w_SetWindowSize_Override2(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 4, 0);
	
	ImGui::SetWindowSize(name, size, cond);
	
	return 0;
}

/*  set named window collapsed state */
int w_SetWindowCollapsed_Override2(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	auto collapsed = luax_checkboolean(L, 2);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 3, 0);
	
	ImGui::SetWindowCollapsed(name, collapsed, cond);
	
	return 0;
}

/*  set named window to be focused / top-most. use NULL to remove focus. */
int w_SetWindowFocus_Override2(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	
	ImGui::SetWindowFocus(name);
	
	return 0;
}

/*  current content boundaries (typically window boundaries including scrolling, or current column boundaries), in windows coordinates */
int w_GetContentRegionMax(lua_State *L)
{
	ImVec2 out = ImGui::GetContentRegionMax();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  == GetContentRegionMax() - GetCursorPos() */
int w_GetContentRegionAvail(lua_State *L)
{
	ImVec2 out = ImGui::GetContentRegionAvail();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  content boundaries min (roughly (0,0)-Scroll), in window coordinates */
int w_GetWindowContentRegionMin(lua_State *L)
{
	ImVec2 out = ImGui::GetWindowContentRegionMin();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  content boundaries max (roughly (0,0)+Size-Scroll) where Size can be override with SetNextWindowContentSize(), in window coordinates */
int w_GetWindowContentRegionMax(lua_State *L)
{
	ImVec2 out = ImGui::GetWindowContentRegionMax();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

int w_GetWindowContentRegionWidth(lua_State *L)
{
	float out = ImGui::GetWindowContentRegionWidth();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  get scrolling amount [0..GetScrollMaxX()] */
int w_GetScrollX(lua_State *L)
{
	float out = ImGui::GetScrollX();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  get scrolling amount [0..GetScrollMaxY()] */
int w_GetScrollY(lua_State *L)
{
	float out = ImGui::GetScrollY();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  get maximum scrolling amount ~~ ContentSize.X - WindowSize.X */
int w_GetScrollMaxX(lua_State *L)
{
	float out = ImGui::GetScrollMaxX();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  get maximum scrolling amount ~~ ContentSize.Y - WindowSize.Y */
int w_GetScrollMaxY(lua_State *L)
{
	float out = ImGui::GetScrollMaxY();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  set scrolling amount [0..GetScrollMaxX()] */
int w_SetScrollX(lua_State *L)
{
	auto scroll_x = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetScrollX(scroll_x);
	
	return 0;
}

/*  set scrolling amount [0..GetScrollMaxY()] */
int w_SetScrollY(lua_State *L)
{
	auto scroll_y = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetScrollY(scroll_y);
	
	return 0;
}

/*  adjust scrolling amount to make current cursor position visible. center_x_ratio=0.0: left, 0.5: center, 1.0: right. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead. */
int w_SetScrollHereX(lua_State *L)
{
	auto center_x_ratio = static_cast<float>(luaL_optnumber(L, 1, 0.5f));
	
	ImGui::SetScrollHereX(center_x_ratio);
	
	return 0;
}

/*  adjust scrolling amount to make current cursor position visible. center_y_ratio=0.0: top, 0.5: center, 1.0: bottom. When using to make a "default/current item" visible, consider using SetItemDefaultFocus() instead. */
int w_SetScrollHereY(lua_State *L)
{
	auto center_y_ratio = static_cast<float>(luaL_optnumber(L, 1, 0.5f));
	
	ImGui::SetScrollHereY(center_y_ratio);
	
	return 0;
}

/*  adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position. */
int w_SetScrollFromPosX(lua_State *L)
{
	auto local_x = static_cast<float>(luaL_checknumber(L, 1));
	auto center_x_ratio = static_cast<float>(luaL_optnumber(L, 2, 0.5f));
	
	ImGui::SetScrollFromPosX(local_x, center_x_ratio);
	
	return 0;
}

/*  adjust scrolling amount to make given position visible. Generally GetCursorStartPos() + offset to compute a valid position. */
int w_SetScrollFromPosY(lua_State *L)
{
	auto local_y = static_cast<float>(luaL_checknumber(L, 1));
	auto center_y_ratio = static_cast<float>(luaL_optnumber(L, 2, 0.5f));
	
	ImGui::SetScrollFromPosY(local_y, center_y_ratio);
	
	return 0;
}

// skipping w_PushFont due to unimplemented argument type: "ImFont*"

int w_PopFont(lua_State *L)
{
	ImGui::PopFont();
	
	return 0;
}

int w_PushStyleColor_Override1(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiCol>(getImGuiColFromString, L, 1);
	auto col = static_cast<unsigned int>(luaL_checklong(L, 2));
	
	ImGui::PushStyleColor(idx, col);
	
	return 0;
}

int w_PushStyleColor_Override2(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiCol>(getImGuiColFromString, L, 1);
	ImVec4 col;
	col.x = luaL_checknumber(L, 2);
	col.y = luaL_checknumber(L, 3);
	col.z = luaL_checknumber(L, 4);
	col.w = luaL_checknumber(L, 5);
	
	ImGui::PushStyleColor(idx, col);
	
	return 0;
}

int w_PopStyleColor(lua_State *L)
{
	auto count = luaL_optint(L, 1, 1);
	
	ImGui::PopStyleColor(count);
	
	return 0;
}

int w_PushStyleVar_Override1(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiStyleVar>(getImGuiStyleVarFromString, L, 1);
	auto val = static_cast<float>(luaL_checknumber(L, 2));
	
	ImGui::PushStyleVar(idx, val);
	
	return 0;
}

int w_PushStyleVar_Override2(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiStyleVar>(getImGuiStyleVarFromString, L, 1);
	ImVec2 val;
	val.x = luaL_checknumber(L, 2);
	val.y = luaL_checknumber(L, 3);
	
	ImGui::PushStyleVar(idx, val);
	
	return 0;
}

int w_PopStyleVar(lua_State *L)
{
	auto count = luaL_optint(L, 1, 1);
	
	ImGui::PopStyleVar(count);
	
	return 0;
}

/*  retrieve style color as stored in ImGuiStyle structure. use to feed back into PushStyleColor(), otherwise use GetColorU32() to get style color with style alpha baked in. */
int w_GetStyleColorVec4(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiCol>(getImGuiColFromString, L, 1);
	
	const ImVec4& out = ImGui::GetStyleColorVec4(idx);
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	lua_pushnumber(L, out.z);
	lua_pushnumber(L, out.w);
	return 2;
}

// skipping w_GetFont due to unimplemented return type: "ImFont*"

/*  get current font size (= height in pixels) of current font with current scale applied */
int w_GetFontSize(lua_State *L)
{
	float out = ImGui::GetFontSize();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  get UV coordinate for a while pixel, useful to draw custom shapes via the ImDrawList API */
int w_GetFontTexUvWhitePixel(lua_State *L)
{
	ImVec2 out = ImGui::GetFontTexUvWhitePixel();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  set width of items for common large "item+label" widgets. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side). 0.0f = default to ~2/3 of windows width, */
int w_PushItemWidth(lua_State *L)
{
	auto item_width = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::PushItemWidth(item_width);
	
	return 0;
}

int w_PopItemWidth(lua_State *L)
{
	ImGui::PopItemWidth();
	
	return 0;
}

/*  set width of the _next_ common large "item+label" widget. >0.0f: width in pixels, <0.0f align xx pixels to the right of window (so -1.0f always align width to the right side) */
int w_SetNextItemWidth(lua_State *L)
{
	auto item_width = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetNextItemWidth(item_width);
	
	return 0;
}

/*  width of item given pushed settings and current cursor position. NOT necessarily the width of last item unlike most 'Item' functions. */
int w_CalcItemWidth(lua_State *L)
{
	float out = ImGui::CalcItemWidth();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  word-wrapping for Text*() commands. < 0.0f: no wrapping; 0.0f: wrap to end of window (or column); > 0.0f: wrap at 'wrap_pos_x' position in window local space */
int w_PushTextWrapPos(lua_State *L)
{
	auto wrap_local_pos_x = static_cast<float>(luaL_optnumber(L, 1, 0.0f));
	
	ImGui::PushTextWrapPos(wrap_local_pos_x);
	
	return 0;
}

int w_PopTextWrapPos(lua_State *L)
{
	ImGui::PopTextWrapPos();
	
	return 0;
}

/*  allow focusing using TAB/Shift-TAB, enabled by default but you can disable it for certain widgets */
int w_PushAllowKeyboardFocus(lua_State *L)
{
	auto allow_keyboard_focus = luax_checkboolean(L, 1);
	
	ImGui::PushAllowKeyboardFocus(allow_keyboard_focus);
	
	return 0;
}

int w_PopAllowKeyboardFocus(lua_State *L)
{
	ImGui::PopAllowKeyboardFocus();
	
	return 0;
}

/*  in 'repeat' mode, Button*() functions return repeated true in a typematic manner (using io.KeyRepeatDelay/io.KeyRepeatRate setting). Note that you can call IsItemActive() after any Button() to tell if the button is held in the current frame. */
int w_PushButtonRepeat(lua_State *L)
{
	auto repeat = luax_checkboolean(L, 1);
	
	ImGui::PushButtonRepeat(repeat);
	
	return 0;
}

int w_PopButtonRepeat(lua_State *L)
{
	ImGui::PopButtonRepeat();
	
	return 0;
}

/*  separator, generally horizontal. inside a menu bar or in horizontal layout mode, this becomes a vertical separator. */
int w_Separator(lua_State *L)
{
	ImGui::Separator();
	
	return 0;
}

/*  call between widgets or groups to layout them horizontally. X position given in window coordinates. */
int w_SameLine(lua_State *L)
{
	auto offset_from_start_x = static_cast<float>(luaL_optnumber(L, 1, 0.0f));
	auto spacing = static_cast<float>(luaL_optnumber(L, 2, -1.0f));
	
	ImGui::SameLine(offset_from_start_x, spacing);
	
	return 0;
}

/*  undo a SameLine() or force a new line when in an horizontal-layout context. */
int w_NewLine(lua_State *L)
{
	ImGui::NewLine();
	
	return 0;
}

/*  add vertical spacing. */
int w_Spacing(lua_State *L)
{
	ImGui::Spacing();
	
	return 0;
}

/*  add a dummy item of given size. unlike InvisibleButton(), Dummy() won't take the mouse click or be navigable into. */
int w_Dummy(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	
	ImGui::Dummy(size);
	
	return 0;
}

/*  move content position toward the right, by style.IndentSpacing or indent_w if != 0 */
int w_Indent(lua_State *L)
{
	auto indent_w = static_cast<float>(luaL_optnumber(L, 1, 0.0f));
	
	ImGui::Indent(indent_w);
	
	return 0;
}

/*  move content position back to the left, by style.IndentSpacing or indent_w if != 0 */
int w_Unindent(lua_State *L)
{
	auto indent_w = static_cast<float>(luaL_optnumber(L, 1, 0.0f));
	
	ImGui::Unindent(indent_w);
	
	return 0;
}

/*  lock horizontal starting position */
int w_BeginGroup(lua_State *L)
{
	ImGui::BeginGroup();
	
	return 0;
}

/*  unlock horizontal starting position + capture the whole group bounding box into one "item" (so you can use IsItemHovered() or layout primitives such as SameLine() on whole group, etc.) */
int w_EndGroup(lua_State *L)
{
	ImGui::EndGroup();
	
	return 0;
}

/*  cursor position in window coordinates (relative to window position) */
int w_GetCursorPos(lua_State *L)
{
	ImVec2 out = ImGui::GetCursorPos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*    (some functions are using window-relative coordinates, such as: GetCursorPos, GetCursorStartPos, GetContentRegionMax, GetWindowContentRegion* etc. */
int w_GetCursorPosX(lua_State *L)
{
	float out = ImGui::GetCursorPosX();
	
	lua_pushnumber(L, out);
	return 1;
}

/*     other functions such as GetCursorScreenPos or everything in ImDrawList:: */
int w_GetCursorPosY(lua_State *L)
{
	float out = ImGui::GetCursorPosY();
	
	lua_pushnumber(L, out);
	return 1;
}

/*     are using the main, absolute coordinate system. */
int w_SetCursorPos(lua_State *L)
{
	ImVec2 local_pos;
	local_pos.x = luaL_checknumber(L, 1);
	local_pos.y = luaL_checknumber(L, 2);
	
	ImGui::SetCursorPos(local_pos);
	
	return 0;
}

/*     GetWindowPos() + GetCursorPos() == GetCursorScreenPos() etc.) */
int w_SetCursorPosX(lua_State *L)
{
	auto local_x = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetCursorPosX(local_x);
	
	return 0;
}

int w_SetCursorPosY(lua_State *L)
{
	auto local_y = static_cast<float>(luaL_checknumber(L, 1));
	
	ImGui::SetCursorPosY(local_y);
	
	return 0;
}

/*  initial cursor position in window coordinates */
int w_GetCursorStartPos(lua_State *L)
{
	ImVec2 out = ImGui::GetCursorStartPos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  cursor position in absolute screen coordinates (0..io.DisplaySize) or natural OS coordinates when using multiple viewport. Useful to work with ImDrawList API. */
int w_GetCursorScreenPos(lua_State *L)
{
	ImVec2 out = ImGui::GetCursorScreenPos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  cursor position in absolute screen coordinates (0..io.DisplaySize) or natural OS coordinates when using multiple viewport. */
int w_SetCursorScreenPos(lua_State *L)
{
	ImVec2 pos;
	pos.x = luaL_checknumber(L, 1);
	pos.y = luaL_checknumber(L, 2);
	
	ImGui::SetCursorScreenPos(pos);
	
	return 0;
}

/*  vertically align upcoming text baseline to FramePadding.y so that it will align properly to regularly framed items (call if you have text on a line before a framed item) */
int w_AlignTextToFramePadding(lua_State *L)
{
	ImGui::AlignTextToFramePadding();
	
	return 0;
}

/*  ~ FontSize */
int w_GetTextLineHeight(lua_State *L)
{
	float out = ImGui::GetTextLineHeight();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  ~ FontSize + style.ItemSpacing.y (distance in pixels between 2 consecutive lines of text) */
int w_GetTextLineHeightWithSpacing(lua_State *L)
{
	float out = ImGui::GetTextLineHeightWithSpacing();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  ~ FontSize + style.FramePadding.y * 2 */
int w_GetFrameHeight(lua_State *L)
{
	float out = ImGui::GetFrameHeight();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  ~ FontSize + style.FramePadding.y * 2 + style.ItemSpacing.y (distance in pixels between 2 consecutive lines of framed widgets) */
int w_GetFrameHeightWithSpacing(lua_State *L)
{
	float out = ImGui::GetFrameHeightWithSpacing();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  push string into the ID stack (will hash string). */
int w_PushID_Override1(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	ImGui::PushID(str_id);
	
	return 0;
}

/*  push string into the ID stack (will hash string). */
int w_PushID_Override2(lua_State *L)
{
	auto str_id_begin = luaL_checkstring(L, 1);
	auto str_id_end = luaL_checkstring(L, 2);
	
	ImGui::PushID(str_id_begin, str_id_end);
	
	return 0;
}

// skipping w_PushID_Override3 due to unimplemented argument type: "const void*"

/*  push integer into the ID stack (will hash integer). */
int w_PushID_Override4(lua_State *L)
{
	auto int_id = luaL_checkint(L, 1);
	
	ImGui::PushID(int_id);
	
	return 0;
}

/*  pop from the ID stack. */
int w_PopID(lua_State *L)
{
	ImGui::PopID();
	
	return 0;
}

/*  calculate unique ID (hash of whole ID stack + given parameter). e.g. if you want to query into ImGuiStorage yourself */
int w_GetID_Override1(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	ImGuiID out = ImGui::GetID(str_id);
	
	lua_pushinteger(L, out);
	return 1;
}

int w_GetID_Override2(lua_State *L)
{
	auto str_id_begin = luaL_checkstring(L, 1);
	auto str_id_end = luaL_checkstring(L, 2);
	
	ImGuiID out = ImGui::GetID(str_id_begin, str_id_end);
	
	lua_pushinteger(L, out);
	return 1;
}

// skipping w_GetID_Override3 due to unimplemented argument type: "const void*"

/*  raw text without formatting. Roughly equivalent to Text("%s", text) but: A) doesn't require null terminated string if 'text_end' is specified, B) it's faster, no memory copy is done, no buffer size limits, recommended for long chunks of text. */
int w_TextUnformatted(lua_State *L)
{
	auto text = luaL_checkstring(L, 1);
	auto text_end = luaL_optstring(L, 2, NULL);
	
	ImGui::TextUnformatted(text, text_end);
	
	return 0;
}

/*  formatted text */
int w_Text(lua_State *L)
{
	auto fmt = luax_formatargs(L, 1);
	
	ImGui::Text("%s", fmt);
	
	return 0;
}

/*  shortcut for PushStyleColor(ImGuiCol_Text, col); Text(fmt, ...); PopStyleColor(); */
int w_TextColored(lua_State *L)
{
	ImVec4 col;
	col.x = luaL_checknumber(L, 1);
	col.y = luaL_checknumber(L, 2);
	col.z = luaL_checknumber(L, 3);
	col.w = luaL_checknumber(L, 4);
	auto fmt = luax_formatargs(L, 5);
	
	ImGui::TextColored(col, "%s", fmt);
	
	return 0;
}

/*  shortcut for PushStyleColor(ImGuiCol_Text, style.Colors[ImGuiCol_TextDisabled]); Text(fmt, ...); PopStyleColor(); */
int w_TextDisabled(lua_State *L)
{
	auto fmt = luax_formatargs(L, 1);
	
	ImGui::TextDisabled("%s", fmt);
	
	return 0;
}

/*  shortcut for PushTextWrapPos(0.0f); Text(fmt, ...); PopTextWrapPos();. Note that this won't work on an auto-resizing window if there's no other widgets to extend the window width, yoy may need to set a size using SetNextWindowSize(). */
int w_TextWrapped(lua_State *L)
{
	auto fmt = luax_formatargs(L, 1);
	
	ImGui::TextWrapped("%s", fmt);
	
	return 0;
}

/*  display text+label aligned the same way as value+label widgets */
int w_LabelText(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto fmt = luax_formatargs(L, 2);
	
	ImGui::LabelText(label, "%s", fmt);
	
	return 0;
}

/*  shortcut for Bullet()+Text() */
int w_BulletText(lua_State *L)
{
	auto fmt = luax_formatargs(L, 1);
	
	ImGui::BulletText("%s", fmt);
	
	return 0;
}

/*  button */
int w_Button(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 2, size.x);
	size.y = luaL_optnumber(L, 3, size.y);
	
	bool out = ImGui::Button(label, size);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  button with FramePadding=(0,0) to easily embed within text */
int w_SmallButton(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	
	bool out = ImGui::SmallButton(label);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  button behavior without the visuals, frequently useful to build custom behaviors using the public api (along with IsItemActive, IsItemHovered, etc.) */
int w_InvisibleButton(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	
	bool out = ImGui::InvisibleButton(str_id, size);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  square button with an arrow shape */
int w_ArrowButton(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto dir = luax_checkenum<ImGuiDir>(getImGuiDirFromString, L, 2);
	
	bool out = ImGui::ArrowButton(str_id, dir);
	
	lua_pushboolean(L, out);
	return 1;
}

int w_Image(lua_State *L)
{
	auto user_texture_id = luax_checkTextureID(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	auto uv0 = ImVec2(0,0);
	uv0.x = luaL_optnumber(L, 4, uv0.x);
	uv0.y = luaL_optnumber(L, 5, uv0.y);
	auto uv1 = ImVec2(1,1);
	uv1.x = luaL_optnumber(L, 6, uv1.x);
	uv1.y = luaL_optnumber(L, 7, uv1.y);
	ImVec4 tint_col = ImVec4(1,1,1,1);
	tint_col.x = luaL_optnumber(L, 8, tint_col.x);
	tint_col.y = luaL_optnumber(L, 9, tint_col.y);
	tint_col.z = luaL_optnumber(L, 10, tint_col.z);
	tint_col.w = luaL_optnumber(L, 11, tint_col.w);
	ImVec4 border_col = ImVec4(0,0,0,0);
	border_col.x = luaL_optnumber(L, 12, border_col.x);
	border_col.y = luaL_optnumber(L, 13, border_col.y);
	border_col.z = luaL_optnumber(L, 14, border_col.z);
	border_col.w = luaL_optnumber(L, 15, border_col.w);
	
	ImGui::Image(user_texture_id, size, uv0, uv1, tint_col, border_col);
	
	return 0;
}

/*  <0 frame_padding uses default frame padding settings. 0 for no padding */
int w_ImageButton(lua_State *L)
{
	auto user_texture_id = luax_checkTextureID(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	auto uv0 = ImVec2(0,0);
	uv0.x = luaL_optnumber(L, 4, uv0.x);
	uv0.y = luaL_optnumber(L, 5, uv0.y);
	auto uv1 = ImVec2(1,1);
	uv1.x = luaL_optnumber(L, 6, uv1.x);
	uv1.y = luaL_optnumber(L, 7, uv1.y);
	auto frame_padding = luaL_optint(L, 8, -1);
	ImVec4 bg_col = ImVec4(0,0,0,0);
	bg_col.x = luaL_optnumber(L, 9, bg_col.x);
	bg_col.y = luaL_optnumber(L, 10, bg_col.y);
	bg_col.z = luaL_optnumber(L, 11, bg_col.z);
	bg_col.w = luaL_optnumber(L, 12, bg_col.w);
	ImVec4 tint_col = ImVec4(1,1,1,1);
	tint_col.x = luaL_optnumber(L, 13, tint_col.x);
	tint_col.y = luaL_optnumber(L, 14, tint_col.y);
	tint_col.z = luaL_optnumber(L, 15, tint_col.z);
	tint_col.w = luaL_optnumber(L, 16, tint_col.w);
	
	bool out = ImGui::ImageButton(user_texture_id, size, uv0, uv1, frame_padding, bg_col, tint_col);
	
	lua_pushboolean(L, out);
	return 1;
}

int w_Checkbox(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	bool v = luax_checkboolean(L, 2);
	
	bool out = ImGui::Checkbox(label, &v);
	
	lua_pushboolean(L, v);
	lua_pushboolean(L, out);
	return 2;
}

int w_CheckboxFlags(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto flags = static_cast<unsigned int>(luaL_checkint(L, 2));
	auto flags_value = static_cast<unsigned int>(luaL_checklong(L, 3));
	
	bool out = ImGui::CheckboxFlags(label, &flags, flags_value);
	
	lua_pushinteger(L, flags);
	lua_pushboolean(L, out);
	return 2;
}

/*  use with e.g. if (RadioButton("one", my_value==1)) { my_value = 1; } */
int w_RadioButton_Override1(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto active = luax_checkboolean(L, 2);
	
	bool out = ImGui::RadioButton(label, active);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  shortcut to handle the above pattern when value is an integer */
int w_RadioButton_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v = luaL_checkint(L, 2);
	auto v_button = luaL_checkint(L, 3);
	
	bool out = ImGui::RadioButton(label, &v, v_button);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

int w_ProgressBar(lua_State *L)
{
	auto fraction = static_cast<float>(luaL_checknumber(L, 1));
	auto size_arg = ImVec2(-1,0);
	size_arg.x = luaL_optnumber(L, 2, size_arg.x);
	size_arg.y = luaL_optnumber(L, 3, size_arg.y);
	auto overlay = luaL_optstring(L, 4, NULL);
	
	ImGui::ProgressBar(fraction, size_arg, overlay);
	
	return 0;
}

/*  draw a small circle and keep the cursor on the same line. advance cursor x position by GetTreeNodeToLabelSpacing(), same distance that TreeNode() uses */
int w_Bullet(lua_State *L)
{
	ImGui::Bullet();
	
	return 0;
}

int w_BeginCombo(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto preview_value = luaL_checkstring(L, 2);
	auto flags = luax_optflags<ImGuiComboFlags>(getImGuiComboFlagsFromString, L, 3, 0);
	
	bool out = ImGui::BeginCombo(label, preview_value, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  only call EndCombo() if BeginCombo() returns true! */
int w_EndCombo(lua_State *L)
{
	ImGui::EndCombo();
	
	return 0;
}

// skipping w_Combo_Override1 due to unimplemented argument type: "const char* const[]"

/*  Separate items with \0 within a string, end item-list with \0\0. e.g. "One\0Two\0Three\0" */
int w_Combo_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int current_item = luaL_checkint(L, 2);
	auto items_separated_by_zeros = luaL_checkstring(L, 3);
	auto popup_max_height_in_items = luaL_optint(L, 4, -1);
	
	bool out = ImGui::Combo(label, &current_item, items_separated_by_zeros, popup_max_height_in_items);
	
	lua_pushinteger(L, current_item);
	lua_pushboolean(L, out);
	return 2;
}

// skipping w_Combo_Override3 due to unimplemented argument type: " bool(*items_getter)(void* data, int idx, const char** out_text)"

/*  If v_min >= v_max we have no bound */
int w_DragFloat(lua_State *L)
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

int w_DragFloat2(lua_State *L)
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

int w_DragFloat3(lua_State *L)
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

int w_DragFloat4(lua_State *L)
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

int w_DragFloatRange2(lua_State *L)
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

/*  If v_min >= v_max we have no bound */
int w_DragInt(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v = luaL_checkint(L, 2);
	auto v_speed = static_cast<float>(luaL_optnumber(L, 3, 1.0f));
	auto v_min = luaL_optint(L, 4, 0);
	auto v_max = luaL_optint(L, 5, 0);
	auto format = luaL_optstring(L, 6, "%d");
	
	bool out = ImGui::DragInt(label, &v, v_speed, v_min, v_max, format);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

int w_DragInt2(lua_State *L)
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

int w_DragInt3(lua_State *L)
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

int w_DragInt4(lua_State *L)
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

int w_DragIntRange2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v_current_min = luaL_checkint(L, 2);
	int v_current_max = luaL_checkint(L, 3);
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

/*  adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display. Use power!=1.0 for power curve sliders */
int w_SliderFloat(lua_State *L)
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

int w_SliderFloat2(lua_State *L)
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

int w_SliderFloat3(lua_State *L)
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

int w_SliderFloat4(lua_State *L)
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

int w_SliderAngle(lua_State *L)
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

int w_SliderInt(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v = luaL_checkint(L, 2);
	auto v_min = luaL_checkint(L, 3);
	auto v_max = luaL_checkint(L, 4);
	auto format = luaL_optstring(L, 5, "%d");
	
	bool out = ImGui::SliderInt(label, &v, v_min, v_max, format);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

int w_SliderInt2(lua_State *L)
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

int w_SliderInt3(lua_State *L)
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

int w_SliderInt4(lua_State *L)
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

int w_VSliderFloat(lua_State *L)
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

int w_VSliderInt(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	ImVec2 size;
	size.x = luaL_checknumber(L, 2);
	size.y = luaL_checknumber(L, 3);
	int v = luaL_checkint(L, 4);
	auto v_min = luaL_checkint(L, 5);
	auto v_max = luaL_checkint(L, 6);
	auto format = luaL_optstring(L, 7, "%d");
	
	bool out = ImGui::VSliderInt(label, size, &v, v_min, v_max, format);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

// skipping w_InputText_Override1 due to unimplemented argument type: "(TODO) const buf*"

// skipping w_InputTextMultiline_Override1 due to unimplemented argument type: "(TODO) const buf*"

// skipping w_InputTextWithHint_Override1 due to unimplemented argument type: "(TODO) const buf*"

int w_InputFloat(lua_State *L)
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

int w_InputFloat2(lua_State *L)
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

int w_InputFloat3(lua_State *L)
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

int w_InputFloat4(lua_State *L)
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

int w_InputInt(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int v = luaL_checkint(L, 2);
	auto step = luaL_optint(L, 3, 1);
	auto step_fast = luaL_optint(L, 4, 100);
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 5, 0);
	
	bool out = ImGui::InputInt(label, &v, step, step_fast, flags);
	
	lua_pushinteger(L, v);
	lua_pushboolean(L, out);
	return 2;
}

int w_InputInt2(lua_State *L)
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

int w_InputInt3(lua_State *L)
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

int w_InputInt4(lua_State *L)
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

int w_InputDouble(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	double v = luaL_checknumber(L, 2);
	auto step = luaL_optnumber(L, 3, 0.0);
	auto step_fast = luaL_optnumber(L, 4, 0.0);
	auto format = luaL_optstring(L, 5, "%.6f");
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 6, 0);
	
	bool out = ImGui::InputDouble(label, &v, step, step_fast, format, flags);
	
	lua_pushnumber(L, v);
	lua_pushboolean(L, out);
	return 2;
}

int w_ColorEdit3(lua_State *L)
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

int w_ColorEdit4(lua_State *L)
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

int w_ColorPicker3(lua_State *L)
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

// skipping w_ColorPicker4 due to unimplemented argument type: "const float*"

/*  display a colored square/button, hover for details, return true when pressed. */
int w_ColorButton(lua_State *L)
{
	auto desc_id = luaL_checkstring(L, 1);
	ImVec4 col;
	col.x = luaL_checknumber(L, 2);
	col.y = luaL_checknumber(L, 3);
	col.z = luaL_checknumber(L, 4);
	col.w = luaL_checknumber(L, 5);
	auto flags = luax_optflags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, L, 6, 0);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 7, size.x);
	size.y = luaL_optnumber(L, 8, size.y);
	
	bool out = ImGui::ColorButton(desc_id, col, flags, size);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  initialize current options (generally on application startup) if you want to select a default format, picker type, etc. User will be able to change many settings, unless you pass the _NoOptions flag to your calls. */
int w_SetColorEditOptions(lua_State *L)
{
	auto flags = luax_checkflags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, L, 1);
	
	ImGui::SetColorEditOptions(flags);
	
	return 0;
}

int w_TreeNode_Override1(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	
	bool out = ImGui::TreeNode(label);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  helper variation to easily decorelate the id from the displayed string. Read the FAQ about why and how to use ID. to align arbitrary text at the same level as a TreeNode() you can use Bullet(). */
int w_TreeNode_Override2(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto fmt = luax_formatargs(L, 2);
	
	bool out = ImGui::TreeNode(str_id, "%s", fmt);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping w_TreeNode_Override3 due to unimplemented argument type: "const void*"

int w_TreeNodeEx_Override1(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto flags = luax_optflags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, L, 2, 0);
	
	bool out = ImGui::TreeNodeEx(label, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

int w_TreeNodeEx_Override2(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto flags = luax_checkflags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, L, 2);
	auto fmt = luax_formatargs(L, 3);
	
	bool out = ImGui::TreeNodeEx(str_id, flags, "%s", fmt);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping w_TreeNodeEx_Override3 due to unimplemented argument type: "const void*"

/*  ~ Indent()+PushId(). Already called by TreeNode() when returning true, but you can call TreePush/TreePop yourself if desired. */
int w_TreePush_Override1(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	ImGui::TreePush(str_id);
	
	return 0;
}

// skipping w_TreePush_Override2 due to unimplemented argument type: "const void*"

/*  ~ Unindent()+PopId() */
int w_TreePop(lua_State *L)
{
	ImGui::TreePop();
	
	return 0;
}

/*  horizontal distance preceding label when using TreeNode*() or Bullet() == (g.FontSize + style.FramePadding.x*2) for a regular unframed TreeNode */
int w_GetTreeNodeToLabelSpacing(lua_State *L)
{
	float out = ImGui::GetTreeNodeToLabelSpacing();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  if returning 'true' the header is open. doesn't indent nor push on ID stack. user doesn't have to call TreePop(). */
int w_CollapsingHeader_Override1(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto flags = luax_optflags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, L, 2, 0);
	
	bool out = ImGui::CollapsingHeader(label, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  when 'p_open' isn't NULL, display an additional small close button on upper right of the header */
int w_CollapsingHeader_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	bool p_open = luax_checkboolean(L, 2);
	auto flags = luax_optflags<ImGuiTreeNodeFlags>(getImGuiTreeNodeFlagsFromString, L, 3, 0);
	
	bool out = ImGui::CollapsingHeader(label, &p_open, flags);
	
	lua_pushboolean(L, p_open);
	lua_pushboolean(L, out);
	return 2;
}

/*  set next TreeNode/CollapsingHeader open state. */
int w_SetNextItemOpen(lua_State *L)
{
	auto is_open = luax_checkboolean(L, 1);
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 2, 0);
	
	ImGui::SetNextItemOpen(is_open, cond);
	
	return 0;
}

/*  "bool selected" carry the selection state (read-only). Selectable() is clicked is returns true so you can modify your selection state. size.x==0.0: use remaining width, size.x>0.0: specify width. size.y==0.0: use label height, size.y>0.0: specify height */
int w_Selectable_Override1(lua_State *L)
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

/*  "bool* p_selected" point to the selection state (read-write), as a convenient helper. */
int w_Selectable_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	bool p_selected = luax_checkboolean(L, 2);
	auto flags = luax_optflags<ImGuiSelectableFlags>(getImGuiSelectableFlagsFromString, L, 3, 0);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 4, size.x);
	size.y = luaL_optnumber(L, 5, size.y);
	
	bool out = ImGui::Selectable(label, &p_selected, flags, size);
	
	lua_pushboolean(L, p_selected);
	lua_pushboolean(L, out);
	return 2;
}

// skipping w_ListBox_Override1 due to unimplemented argument type: "const char* const[]"

// skipping w_ListBox_Override2 due to unimplemented argument type: " bool (*items_getter)(void* data, int idx, const char** out_text)"

/*  use if you want to reimplement ListBox() will custom data or interactions. if the function return true, you can output elements then call ListBoxFooter() afterwards. */
int w_ListBoxHeader_Override1(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto size = ImVec2(0,0);
	size.x = luaL_optnumber(L, 2, size.x);
	size.y = luaL_optnumber(L, 3, size.y);
	
	bool out = ImGui::ListBoxHeader(label, size);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  " */
int w_ListBoxHeader_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto items_count = luaL_checkint(L, 2);
	auto height_in_items = luaL_optint(L, 3, -1);
	
	bool out = ImGui::ListBoxHeader(label, items_count, height_in_items);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  terminate the scrolling region. only call ListBoxFooter() if ListBoxHeader() returned true! */
int w_ListBoxFooter(lua_State *L)
{
	ImGui::ListBoxFooter();
	
	return 0;
}

// skipping w_PlotLines_Override1 due to unimplemented argument type: "const float*"

// skipping w_PlotLines_Override2 due to unimplemented argument type: " float(*values_getter)(void* data, int idx)"

// skipping w_PlotHistogram_Override1 due to unimplemented argument type: "const float*"

// skipping w_PlotHistogram_Override2 due to unimplemented argument type: " float(*values_getter)(void* data, int idx)"

int w_Value_Override1(lua_State *L)
{
	auto prefix = luaL_checkstring(L, 1);
	auto b = luax_checkboolean(L, 2);
	
	ImGui::Value(prefix, b);
	
	return 0;
}

int w_Value_Override2(lua_State *L)
{
	auto prefix = luaL_checkstring(L, 1);
	auto v = luaL_checkint(L, 2);
	
	ImGui::Value(prefix, v);
	
	return 0;
}

int w_Value_Override3(lua_State *L)
{
	auto prefix = luaL_checkstring(L, 1);
	auto v = static_cast<unsigned int>(luaL_checklong(L, 2));
	
	ImGui::Value(prefix, v);
	
	return 0;
}

int w_Value_Override4(lua_State *L)
{
	auto prefix = luaL_checkstring(L, 1);
	auto v = static_cast<float>(luaL_checknumber(L, 2));
	auto float_format = luaL_optstring(L, 3, NULL);
	
	ImGui::Value(prefix, v, float_format);
	
	return 0;
}

/*  append to menu-bar of current window (requires ImGuiWindowFlags_MenuBar flag set on parent window). */
int w_BeginMenuBar(lua_State *L)
{
	bool out = ImGui::BeginMenuBar();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  only call EndMenuBar() if BeginMenuBar() returns true! */
int w_EndMenuBar(lua_State *L)
{
	ImGui::EndMenuBar();
	
	return 0;
}

/*  create and append to a full screen menu-bar. */
int w_BeginMainMenuBar(lua_State *L)
{
	bool out = ImGui::BeginMainMenuBar();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  only call EndMainMenuBar() if BeginMainMenuBar() returns true! */
int w_EndMainMenuBar(lua_State *L)
{
	ImGui::EndMainMenuBar();
	
	return 0;
}

/*  create a sub-menu entry. only call EndMenu() if this returns true! */
int w_BeginMenu(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto enabled = luax_optboolean(L, 2, true);
	
	bool out = ImGui::BeginMenu(label, enabled);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  only call EndMenu() if BeginMenu() returns true! */
int w_EndMenu(lua_State *L)
{
	ImGui::EndMenu();
	
	return 0;
}

/*  return true when activated. shortcuts are displayed for convenience but not processed by ImGui at the moment */
int w_MenuItem_Override1(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto shortcut = luaL_optstring(L, 2, NULL);
	auto selected = luax_optboolean(L, 3, false);
	auto enabled = luax_optboolean(L, 4, true);
	
	bool out = ImGui::MenuItem(label, shortcut, selected, enabled);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  return true when activated + toggle (*p_selected) if p_selected != NULL */
int w_MenuItem_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto shortcut = luaL_checkstring(L, 2);
	bool p_selected = luax_checkboolean(L, 3);
	auto enabled = luax_optboolean(L, 4, true);
	
	bool out = ImGui::MenuItem(label, shortcut, &p_selected, enabled);
	
	lua_pushboolean(L, p_selected);
	lua_pushboolean(L, out);
	return 2;
}

/*  begin/append a tooltip window. to create full-featured tooltip (with any kind of items). */
int w_BeginTooltip(lua_State *L)
{
	ImGui::BeginTooltip();
	
	return 0;
}

int w_EndTooltip(lua_State *L)
{
	ImGui::EndTooltip();
	
	return 0;
}

/*  set a text-only tooltip, typically use with ImGui::IsItemHovered(). override any previous call to SetTooltip(). */
int w_SetTooltip(lua_State *L)
{
	auto fmt = luax_formatargs(L, 1);
	
	ImGui::SetTooltip("%s", fmt);
	
	return 0;
}

/*  call to mark popup as open (don't call every frame!). popups are closed when user click outside, or if CloseCurrentPopup() is called within a BeginPopup()/EndPopup() block. By default, Selectable()/MenuItem() are calling CloseCurrentPopup(). Popup identifiers are relative to the current ID-stack (so OpenPopup and BeginPopup needs to be at the same level). */
int w_OpenPopup(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	ImGui::OpenPopup(str_id);
	
	return 0;
}

/*  return true if the popup is open, and you can start outputting to it. only call EndPopup() if BeginPopup() returns true! */
int w_BeginPopup(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 2, 0);
	
	bool out = ImGui::BeginPopup(str_id, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  helper to open and begin popup when clicked on last item. if you can pass a NULL str_id only if the previous item had an id. If you want to use that on a non-interactive item such as Text() you need to pass in an explicit ID here. read comments in .cpp! */
int w_BeginPopupContextItem(lua_State *L)
{
	auto str_id = luaL_optstring(L, 1, NULL);
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 2, 1);
	
	bool out = ImGui::BeginPopupContextItem(str_id, mouse_button);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  helper to open and begin popup when clicked on current window. */
int w_BeginPopupContextWindow(lua_State *L)
{
	auto str_id = luaL_optstring(L, 1, NULL);
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 2, 1);
	auto also_over_items = luax_optboolean(L, 3, true);
	
	bool out = ImGui::BeginPopupContextWindow(str_id, mouse_button, also_over_items);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  helper to open and begin popup when clicked in void (where there are no imgui windows). */
int w_BeginPopupContextVoid(lua_State *L)
{
	auto str_id = luaL_optstring(L, 1, NULL);
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 2, 1);
	
	bool out = ImGui::BeginPopupContextVoid(str_id, mouse_button);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  modal dialog (regular window with title bar, block interactions behind the modal window, can't close the modal window by clicking outside) */
int w_BeginPopupModal(lua_State *L)
{
	auto name = luaL_checkstring(L, 1);
	bool p_open = luax_optboolean(L, 2, NULL);
	auto flags = luax_optflags<ImGuiWindowFlags>(getImGuiWindowFlagsFromString, L, 3, 0);
	
	bool out = ImGui::BeginPopupModal(name, &p_open, flags);
	
	lua_pushboolean(L, p_open);
	lua_pushboolean(L, out);
	return 2;
}

/*  only call EndPopup() if BeginPopupXXX() returns true! */
int w_EndPopup(lua_State *L)
{
	ImGui::EndPopup();
	
	return 0;
}

/*  helper to open popup when clicked on last item (note: actually triggers on the mouse _released_ event to be consistent with popup behaviors). return true when just opened. */
int w_OpenPopupOnItemClick(lua_State *L)
{
	auto str_id = luaL_optstring(L, 1, NULL);
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 2, 1);
	
	bool out = ImGui::OpenPopupOnItemClick(str_id, mouse_button);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  return true if the popup is open at the current begin-ed level of the popup stack. */
int w_IsPopupOpen(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	
	bool out = ImGui::IsPopupOpen(str_id);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  close the popup we have begin-ed into. clicking on a MenuItem or Selectable automatically close the current popup. */
int w_CloseCurrentPopup(lua_State *L)
{
	ImGui::CloseCurrentPopup();
	
	return 0;
}

int w_Columns(lua_State *L)
{
	auto count = luaL_optint(L, 1, 1);
	auto id = luaL_optstring(L, 2, NULL);
	auto border = luax_optboolean(L, 3, true);
	
	ImGui::Columns(count, id, border);
	
	return 0;
}

/*  next column, defaults to current row or next row if the current row is finished */
int w_NextColumn(lua_State *L)
{
	ImGui::NextColumn();
	
	return 0;
}

/*  get current column index */
int w_GetColumnIndex(lua_State *L)
{
	int out = ImGui::GetColumnIndex();
	
	lua_pushinteger(L, out);
	return 1;
}

/*  get column width (in pixels). pass -1 to use current column */
int w_GetColumnWidth(lua_State *L)
{
	auto column_index = luaL_optint(L, 1, -1);
	
	float out = ImGui::GetColumnWidth(column_index);
	
	lua_pushnumber(L, out);
	return 1;
}

/*  set column width (in pixels). pass -1 to use current column */
int w_SetColumnWidth(lua_State *L)
{
	auto column_index = luaL_checkint(L, 1);
	auto width = static_cast<float>(luaL_checknumber(L, 2));
	
	ImGui::SetColumnWidth(column_index, width);
	
	return 0;
}

/*  get position of column line (in pixels, from the left side of the contents region). pass -1 to use current column, otherwise 0..GetColumnsCount() inclusive. column 0 is typically 0.0f */
int w_GetColumnOffset(lua_State *L)
{
	auto column_index = luaL_optint(L, 1, -1);
	
	float out = ImGui::GetColumnOffset(column_index);
	
	lua_pushnumber(L, out);
	return 1;
}

/*  set position of column line (in pixels, from the left side of the contents region). pass -1 to use current column */
int w_SetColumnOffset(lua_State *L)
{
	auto column_index = luaL_checkint(L, 1);
	auto offset_x = static_cast<float>(luaL_checknumber(L, 2));
	
	ImGui::SetColumnOffset(column_index, offset_x);
	
	return 0;
}

int w_GetColumnsCount(lua_State *L)
{
	int out = ImGui::GetColumnsCount();
	
	lua_pushinteger(L, out);
	return 1;
}

/*  create and append into a TabBar */
int w_BeginTabBar(lua_State *L)
{
	auto str_id = luaL_checkstring(L, 1);
	auto flags = luax_optflags<ImGuiTabBarFlags>(getImGuiTabBarFlagsFromString, L, 2, 0);
	
	bool out = ImGui::BeginTabBar(str_id, flags);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  only call EndTabBar() if BeginTabBar() returns true! */
int w_EndTabBar(lua_State *L)
{
	ImGui::EndTabBar();
	
	return 0;
}

/*  create a Tab. Returns true if the Tab is selected. */
int w_BeginTabItem(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	bool p_open = luax_optboolean(L, 2, NULL);
	auto flags = luax_optflags<ImGuiTabItemFlags>(getImGuiTabItemFlagsFromString, L, 3, 0);
	
	bool out = ImGui::BeginTabItem(label, &p_open, flags);
	
	lua_pushboolean(L, p_open);
	lua_pushboolean(L, out);
	return 2;
}

/*  only call EndTabItem() if BeginTabItem() returns true! */
int w_EndTabItem(lua_State *L)
{
	ImGui::EndTabItem();
	
	return 0;
}

/*  notify TabBar or Docking system of a closed tab/window ahead (useful to reduce visual flicker on reorderable tab bars). For tab-bar: call after BeginTabBar() and before Tab submissions. Otherwise call with a window name. */
int w_SetTabItemClosed(lua_State *L)
{
	auto tab_or_docked_window_label = luaL_checkstring(L, 1);
	
	ImGui::SetTabItemClosed(tab_or_docked_window_label);
	
	return 0;
}

int w_DockSpace(lua_State *L)
{
	auto id = static_cast<ImGuiID>(luaL_checkint(L, 1));
	auto size = ImVec2(0, 0);
	size.x = luaL_optnumber(L, 2, size.x);
	size.y = luaL_optnumber(L, 3, size.y);
	auto flags = luax_optflags<ImGuiDockNodeFlags>(getImGuiDockNodeFlagsFromString, L, 4, 0);
	const ImGuiWindowClass* window_class = NULL; // skipping
	
	ImGui::DockSpace(id, size, flags, window_class);
	
	return 0;
}

int w_DockSpaceOverViewport(lua_State *L)
{
	ImGuiViewport* viewport = NULL; // skipping
	auto flags = luax_optflags<ImGuiDockNodeFlags>(getImGuiDockNodeFlagsFromString, L, 1, 0);
	const ImGuiWindowClass* window_class = NULL; // skipping
	
	ImGuiID out = ImGui::DockSpaceOverViewport(viewport, flags, window_class);
	
	lua_pushinteger(L, out);
	return 1;
}

/*  set next window dock id (FIXME-DOCK) */
int w_SetNextWindowDockID(lua_State *L)
{
	auto dock_id = static_cast<ImGuiID>(luaL_checkint(L, 1));
	auto cond = luax_optenum<ImGuiCond>(getImGuiCondFromString, L, 2, 0);
	
	ImGui::SetNextWindowDockID(dock_id, cond);
	
	return 0;
}

// skipping w_SetNextWindowClass due to unimplemented argument type: "const ImGuiWindowClass*"

int w_GetWindowDockID(lua_State *L)
{
	ImGuiID out = ImGui::GetWindowDockID();
	
	lua_pushinteger(L, out);
	return 1;
}

/*  is current window docked into another window? */
int w_IsWindowDocked(lua_State *L)
{
	bool out = ImGui::IsWindowDocked();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  start logging to tty (stdout) */
int w_LogToTTY(lua_State *L)
{
	auto auto_open_depth = luaL_optint(L, 1, -1);
	
	ImGui::LogToTTY(auto_open_depth);
	
	return 0;
}

/*  start logging to file */
int w_LogToFile(lua_State *L)
{
	auto auto_open_depth = luaL_optint(L, 1, -1);
	auto filename = luaL_optstring(L, 2, NULL);
	
	ImGui::LogToFile(auto_open_depth, filename);
	
	return 0;
}

/*  start logging to OS clipboard */
int w_LogToClipboard(lua_State *L)
{
	auto auto_open_depth = luaL_optint(L, 1, -1);
	
	ImGui::LogToClipboard(auto_open_depth);
	
	return 0;
}

/*  stop logging (close file, etc.) */
int w_LogFinish(lua_State *L)
{
	ImGui::LogFinish();
	
	return 0;
}

/*  helper to display buttons for logging to tty/file/clipboard */
int w_LogButtons(lua_State *L)
{
	ImGui::LogButtons();
	
	return 0;
}

/*  pass text data straight to log (without being displayed) */
int w_LogText(lua_State *L)
{
	auto fmt = luax_formatargs(L, 1);
	
	ImGui::LogText("%s", fmt);
	
	return 0;
}

/*  call when the current item is active. If this return true, you can call SetDragDropPayload() + EndDragDropSource() */
int w_BeginDragDropSource(lua_State *L)
{
	auto flags = luax_optflags<ImGuiDragDropFlags>(getImGuiDragDropFlagsFromString, L, 1, 0);
	
	bool out = ImGui::BeginDragDropSource(flags);
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping w_SetDragDropPayload due to unimplemented argument type: "(TODO) const buf*"

/*  only call EndDragDropSource() if BeginDragDropSource() returns true! */
int w_EndDragDropSource(lua_State *L)
{
	ImGui::EndDragDropSource();
	
	return 0;
}

/*  call after submitting an item that may receive a payload. If this returns true, you can call AcceptDragDropPayload() + EndDragDropTarget() */
int w_BeginDragDropTarget(lua_State *L)
{
	bool out = ImGui::BeginDragDropTarget();
	
	lua_pushboolean(L, out);
	return 1;
}

// skipping w_AcceptDragDropPayload due to unimplemented return type: "const ImGuiPayload*"

/*  only call EndDragDropTarget() if BeginDragDropTarget() returns true! */
int w_EndDragDropTarget(lua_State *L)
{
	ImGui::EndDragDropTarget();
	
	return 0;
}

// skipping w_GetDragDropPayload due to unimplemented return type: "const ImGuiPayload*"

int w_PushClipRect(lua_State *L)
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

int w_PopClipRect(lua_State *L)
{
	ImGui::PopClipRect();
	
	return 0;
}

/*  make last item the default focused item of a window. */
int w_SetItemDefaultFocus(lua_State *L)
{
	ImGui::SetItemDefaultFocus();
	
	return 0;
}

/*  focus keyboard on the next widget. Use positive 'offset' to access sub components of a multiple component widget. Use -1 to access previous widget. */
int w_SetKeyboardFocusHere(lua_State *L)
{
	auto offset = luaL_optint(L, 1, 0);
	
	ImGui::SetKeyboardFocusHere(offset);
	
	return 0;
}

/*  is the last item hovered? (and usable, aka not blocked by a popup, etc.). See ImGuiHoveredFlags for more options. */
int w_IsItemHovered(lua_State *L)
{
	auto flags = luax_optflags<ImGuiFocusedFlags>(getImGuiFocusedFlagsFromString, L, 1, 0);
	
	bool out = ImGui::IsItemHovered(flags);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is the last item active? (e.g. button being held, text field being edited. This will continuously return true while holding mouse button on an item. Items that don't interact will always return false) */
int w_IsItemActive(lua_State *L)
{
	bool out = ImGui::IsItemActive();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is the last item focused for keyboard/gamepad navigation? */
int w_IsItemFocused(lua_State *L)
{
	bool out = ImGui::IsItemFocused();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is the last item clicked? (e.g. button/node just clicked on) == IsMouseClicked(mouse_button) && IsItemHovered() */
int w_IsItemClicked(lua_State *L)
{
	auto mouse_button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1, 0);
	
	bool out = ImGui::IsItemClicked(mouse_button);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is the last item visible? (items may be out of sight because of clipping/scrolling) */
int w_IsItemVisible(lua_State *L)
{
	bool out = ImGui::IsItemVisible();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  did the last item modify its underlying value this frame? or was pressed? This is generally the same as the "bool" return value of many widgets. */
int w_IsItemEdited(lua_State *L)
{
	bool out = ImGui::IsItemEdited();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  was the last item just made active (item was previously inactive). */
int w_IsItemActivated(lua_State *L)
{
	bool out = ImGui::IsItemActivated();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  was the last item just made inactive (item was previously active). Useful for Undo/Redo patterns with widgets that requires continuous editing. */
int w_IsItemDeactivated(lua_State *L)
{
	bool out = ImGui::IsItemDeactivated();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  was the last item just made inactive and made a value change when it was active? (e.g. Slider/Drag moved). Useful for Undo/Redo patterns with widgets that requires continuous editing. Note that you may get false positives (some widgets such as Combo()/ListBox()/Selectable() will return true even when clicking an already selected item). */
int w_IsItemDeactivatedAfterEdit(lua_State *L)
{
	bool out = ImGui::IsItemDeactivatedAfterEdit();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  was the last item open state toggled? set by TreeNode(). */
int w_IsItemToggledOpen(lua_State *L)
{
	bool out = ImGui::IsItemToggledOpen();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is any item hovered? */
int w_IsAnyItemHovered(lua_State *L)
{
	bool out = ImGui::IsAnyItemHovered();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is any item active? */
int w_IsAnyItemActive(lua_State *L)
{
	bool out = ImGui::IsAnyItemActive();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is any item focused? */
int w_IsAnyItemFocused(lua_State *L)
{
	bool out = ImGui::IsAnyItemFocused();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  get upper-left bounding rectangle of the last item (screen space) */
int w_GetItemRectMin(lua_State *L)
{
	ImVec2 out = ImGui::GetItemRectMin();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  get lower-right bounding rectangle of the last item (screen space) */
int w_GetItemRectMax(lua_State *L)
{
	ImVec2 out = ImGui::GetItemRectMax();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  get size of last item */
int w_GetItemRectSize(lua_State *L)
{
	ImVec2 out = ImGui::GetItemRectSize();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  allow last item to be overlapped by a subsequent item. sometimes useful with invisible buttons, selectables, etc. to catch unused area. */
int w_SetItemAllowOverlap(lua_State *L)
{
	ImGui::SetItemAllowOverlap();
	
	return 0;
}

/*  test if rectangle (of given size, starting from cursor position) is visible / not clipped. */
int w_IsRectVisible_Override1(lua_State *L)
{
	ImVec2 size;
	size.x = luaL_checknumber(L, 1);
	size.y = luaL_checknumber(L, 2);
	
	bool out = ImGui::IsRectVisible(size);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  test if rectangle (in screen space) is visible / not clipped. to perform coarse clipping on user's side. */
int w_IsRectVisible_Override2(lua_State *L)
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

/*  get global imgui time. incremented by io.DeltaTime every frame. */
int w_GetTime(lua_State *L)
{
	double out = ImGui::GetTime();
	
	lua_pushnumber(L, out);
	return 1;
}

/*  get global imgui frame count. incremented by 1 every frame. */
int w_GetFrameCount(lua_State *L)
{
	int out = ImGui::GetFrameCount();
	
	lua_pushinteger(L, out);
	return 1;
}

// skipping w_GetBackgroundDrawList_Override1 due to unimplemented return type: "ImDrawList*"

// skipping w_GetForegroundDrawList_Override1 due to unimplemented return type: "ImDrawList*"

// skipping w_GetBackgroundDrawList_Override2 due to unimplemented argument type: "ImGuiViewport*"

// skipping w_GetForegroundDrawList_Override2 due to unimplemented argument type: "ImGuiViewport*"

// skipping w_GetDrawListSharedData due to unimplemented return type: "ImDrawListSharedData*"

/*  get a string corresponding to the enum value (for display, saving, etc.). */
int w_GetStyleColorName(lua_State *L)
{
	auto idx = luax_checkenum<ImGuiCol>(getImGuiColFromString, L, 1);
	
	const char* out = ImGui::GetStyleColorName(idx);
	
	lua_pushstring(L, out);
	return 1;
}

// skipping w_SetStateStorage due to unimplemented argument type: "ImGuiStorage*"

// skipping w_GetStateStorage due to unimplemented return type: "ImGuiStorage*"

int w_CalcTextSize(lua_State *L)
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

/*  calculate coarse clipping for large list of evenly sized items. Prefer using the ImGuiListClipper higher-level helper if you can. */
int w_CalcListClipping(lua_State *L)
{
	auto items_count = luaL_checkint(L, 1);
	auto items_height = static_cast<float>(luaL_checknumber(L, 2));
	int out_items_display_start = luaL_checkint(L, 3);
	int out_items_display_end = luaL_checkint(L, 4);
	
	ImGui::CalcListClipping(items_count, items_height, &out_items_display_start, &out_items_display_end);
	
	lua_pushinteger(L, out_items_display_start);
	lua_pushinteger(L, out_items_display_end);
	return 2;
}

/*  helper to create a child window / scrolling region that looks like a normal widget frame */
int w_BeginChildFrame(lua_State *L)
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

/*  always call EndChildFrame() regardless of BeginChildFrame() return values (which indicates a collapsed/clipped window) */
int w_EndChildFrame(lua_State *L)
{
	ImGui::EndChildFrame();
	
	return 0;
}

int w_ColorConvertU32ToFloat4(lua_State *L)
{
	auto in = static_cast<unsigned int>(luaL_checklong(L, 1));
	
	ImVec4 out = ImGui::ColorConvertU32ToFloat4(in);
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	lua_pushnumber(L, out.z);
	lua_pushnumber(L, out.w);
	return 2;
}

/*  map ImGuiKey_* values into user's key index. == io.KeyMap[key] */
int w_GetKeyIndex(lua_State *L)
{
	auto imgui_key = luax_checkenum<ImGuiKey>(getImGuiKeyFromString, L, 1);
	
	int out = ImGui::GetKeyIndex(imgui_key);
	
	lua_pushinteger(L, out);
	return 1;
}

/*  is key being held. == io.KeysDown[user_key_index]. */
int w_IsKeyDown(lua_State *L)
{
	auto user_key_index = luaL_checkint(L, 1);
	
	bool out = ImGui::IsKeyDown(user_key_index);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  was key pressed (went from !Down to Down)? if repeat=true, uses io.KeyRepeatDelay / KeyRepeatRate */
int w_IsKeyPressed(lua_State *L)
{
	auto user_key_index = luaL_checkint(L, 1);
	auto repeat = luax_optboolean(L, 2, true);
	
	bool out = ImGui::IsKeyPressed(user_key_index, repeat);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  was key released (went from Down to !Down)? */
int w_IsKeyReleased(lua_State *L)
{
	auto user_key_index = luaL_checkint(L, 1);
	
	bool out = ImGui::IsKeyReleased(user_key_index);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  uses provided repeat rate/delay. return a count, most often 0 or 1 but might be >1 if RepeatRate is small enough that DeltaTime > RepeatRate */
int w_GetKeyPressedAmount(lua_State *L)
{
	auto key_index = luaL_checkint(L, 1);
	auto repeat_delay = static_cast<float>(luaL_checknumber(L, 2));
	auto rate = static_cast<float>(luaL_checknumber(L, 3));
	
	int out = ImGui::GetKeyPressedAmount(key_index, repeat_delay, rate);
	
	lua_pushinteger(L, out);
	return 1;
}

/*  attention: misleading name! manually override io.WantCaptureKeyboard flag next frame (said flag is entirely left for your application to handle). e.g. force capture keyboard when your widget is being hovered. This is equivalent to setting "io.WantCaptureKeyboard = want_capture_keyboard_value"; after the next NewFrame() call. */
int w_CaptureKeyboardFromApp(lua_State *L)
{
	auto want_capture_keyboard_value = luax_optboolean(L, 1, true);
	
	ImGui::CaptureKeyboardFromApp(want_capture_keyboard_value);
	
	return 0;
}

/*  is mouse button held? */
int w_IsMouseDown(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	
	bool out = ImGui::IsMouseDown(button);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  did mouse button clicked? (went from !Down to Down) */
int w_IsMouseClicked(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	auto repeat = luax_optboolean(L, 2, false);
	
	bool out = ImGui::IsMouseClicked(button, repeat);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  did mouse button released? (went from Down to !Down) */
int w_IsMouseReleased(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	
	bool out = ImGui::IsMouseReleased(button);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  did mouse button double-clicked? a double-click returns false in IsMouseClicked(). uses io.MouseDoubleClickTime. */
int w_IsMouseDoubleClicked(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	
	bool out = ImGui::IsMouseDoubleClicked(button);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is mouse hovering given bounding rect (in screen space). clipped by current clipping settings, but disregarding of other consideration of focus/window ordering/popup-block. */
int w_IsMouseHoveringRect(lua_State *L)
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

/*  by convention we use (-FLT_MAX,-FLT_MAX) to denote that there is no mouse available */
int w_IsMousePosValid(lua_State *L)
{
	ImVec2* mouse_pos = NULL;
	ImVec2 mouse_pos_buf;
	if(!lua_isnoneornil(L, 2)) {
		mouse_pos_buf.x = luaL_checknumber(L, 1);
		mouse_pos_buf.y = luaL_checknumber(L, 2);
	}
	
	bool out = ImGui::IsMousePosValid(mouse_pos);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  is any mouse button held? */
int w_IsAnyMouseDown(lua_State *L)
{
	bool out = ImGui::IsAnyMouseDown();
	
	lua_pushboolean(L, out);
	return 1;
}

/*  shortcut to ImGui::GetIO().MousePos provided by user, to be consistent with other calls */
int w_GetMousePos(lua_State *L)
{
	ImVec2 out = ImGui::GetMousePos();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  retrieve mouse position at the time of opening popup we have BeginPopup() into (helper to avoid user backing that value themselves) */
int w_GetMousePosOnOpeningCurrentPopup(lua_State *L)
{
	ImVec2 out = ImGui::GetMousePosOnOpeningCurrentPopup();
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

/*  is mouse dragging? (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold) */
int w_IsMouseDragging(lua_State *L)
{
	auto button = luax_checkenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1);
	auto lock_threshold = static_cast<float>(luaL_optnumber(L, 2, -1.0f));
	
	bool out = ImGui::IsMouseDragging(button, lock_threshold);
	
	lua_pushboolean(L, out);
	return 1;
}

/*  return the delta from the initial clicking position while the mouse button is pressed or was just released. This is locked and return 0.0f until the mouse moves past a distance threshold at least once (if lock_threshold < -1.0f, uses io.MouseDraggingThreshold) */
int w_GetMouseDragDelta(lua_State *L)
{
	auto button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1, 0);
	auto lock_threshold = static_cast<float>(luaL_optnumber(L, 2, -1.0f));
	
	ImVec2 out = ImGui::GetMouseDragDelta(button, lock_threshold);
	
	lua_pushnumber(L, out.x);
	lua_pushnumber(L, out.y);
	return 2;
}

int w_ResetMouseDragDelta(lua_State *L)
{
	auto button = luax_optenum<ImGuiMouseButton>(getImGuiMouseButtonFromString, L, 1, 0);
	
	ImGui::ResetMouseDragDelta(button);
	
	return 0;
}

/*  get desired cursor type, reset in ImGui::NewFrame(), this is updated during the frame. valid before Render(). If you use software rendering by setting io.MouseDrawCursor ImGui will render those for you */
int w_GetMouseCursor(lua_State *L)
{
	ImGuiMouseCursor out = ImGui::GetMouseCursor();
	
	lua_pushstring(L, getStringFromImGuiMouseCursor(out));
	return 1;
}

/*  set desired cursor type */
int w_SetMouseCursor(lua_State *L)
{
	auto cursor_type = luax_checkenum<ImGuiMouseCursor>(getImGuiMouseCursorFromString, L, 1);
	
	ImGui::SetMouseCursor(cursor_type);
	
	return 0;
}

/*  attention: misleading name! manually override io.WantCaptureMouse flag next frame (said flag is entirely left for your application to handle). This is equivalent to setting "io.WantCaptureMouse = want_capture_mouse_value;" after the next NewFrame() call. */
int w_CaptureMouseFromApp(lua_State *L)
{
	auto want_capture_mouse_value = luax_optboolean(L, 1, true);
	
	ImGui::CaptureMouseFromApp(want_capture_mouse_value);
	
	return 0;
}

int w_GetClipboardText(lua_State *L)
{
	const char* out = ImGui::GetClipboardText();
	
	lua_pushstring(L, out);
	return 1;
}

int w_SetClipboardText(lua_State *L)
{
	auto text = luaL_checkstring(L, 1);
	
	ImGui::SetClipboardText(text);
	
	return 0;
}

/*  call after CreateContext() and before the first call to NewFrame(). NewFrame() automatically calls LoadIniSettingsFromDisk(io.IniFilename). */
int w_LoadIniSettingsFromDisk(lua_State *L)
{
	auto ini_filename = luaL_checkstring(L, 1);
	
	ImGui::LoadIniSettingsFromDisk(ini_filename);
	
	return 0;
}

// skipping w_LoadIniSettingsFromMemory due to unimplemented argument type: "(TODO) const buf*"

/*  this is automatically called (if io.IniFilename is not empty) a few seconds after any modification that should be reflected in the .ini file (and also by DestroyContext). */
int w_SaveIniSettingsToDisk(lua_State *L)
{
	auto ini_filename = luaL_checkstring(L, 1);
	
	ImGui::SaveIniSettingsToDisk(ini_filename);
	
	return 0;
}

// skipping w_SaveIniSettingsToMemory due to unimplemented argument type: "size_t*"

// skipping w_GetPlatformIO due to unimplemented return type: "ImGuiPlatformIO&"

// skipping w_GetMainViewport due to unimplemented return type: "ImGuiViewport*"

/*  call in main loop. will call CreateWindow/ResizeWindow/etc. platform functions for each secondary viewport, and DestroyWindow for each inactive viewport. */
int w_UpdatePlatformWindows(lua_State *L)
{
	ImGui::UpdatePlatformWindows();
	
	return 0;
}

// skipping w_RenderPlatformWindowsDefault due to unimplemented argument type: "void*"

/*  call DestroyWindow platform functions for all viewports. call from back-end Shutdown() if you need to close platform windows before imgui shutdown. otherwise will be called by DestroyContext(). */
int w_DestroyPlatformWindows(lua_State *L)
{
	ImGui::DestroyPlatformWindows();
	
	return 0;
}

// skipping w_FindViewportByID due to unimplemented return type: "ImGuiViewport*"

// skipping w_FindViewportByPlatformHandle due to unimplemented argument type: "void*"

int w_InputText_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	std::string str = luaL_checkstring(L, 2);
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 3, 0);
	ImGuiInputTextCallback callback = callLuaInputTextCallback;
	void* user_data = luax_getImguiInputTextCallback(L, 4);
	if (!user_data) { callback = nullptr; }
	
	bool out = ImGui::InputText(label, &str, flags, callback, user_data);
	
	lua_pushlstring(L, str.c_str(), str.size());
	lua_pushboolean(L, out);
	return 2;
}

int w_InputTextMultiline_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	std::string str = luaL_checkstring(L, 2);
	auto size = ImVec2(0, 0);
	size.x = luaL_optnumber(L, 3, size.x);
	size.y = luaL_optnumber(L, 4, size.y);
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 5, 0);
	ImGuiInputTextCallback callback = callLuaInputTextCallback;
	void* user_data = luax_getImguiInputTextCallback(L, 6);
	if (!user_data) { callback = nullptr; }
	
	bool out = ImGui::InputTextMultiline(label, &str, size, flags, callback, user_data);
	
	lua_pushlstring(L, str.c_str(), str.size());
	lua_pushboolean(L, out);
	return 2;
}

int w_InputTextWithHint_Override2(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	auto hint = luaL_checkstring(L, 2);
	std::string str = luaL_checkstring(L, 3);
	auto flags = luax_optflags<ImGuiInputTextFlags>(getImGuiInputTextFlagsFromString, L, 4, 0);
	ImGuiInputTextCallback callback = callLuaInputTextCallback;
	void* user_data = luax_getImguiInputTextCallback(L, 5);
	if (!user_data) { callback = nullptr; }
	
	bool out = ImGui::InputTextWithHint(label, hint, &str, flags, callback, user_data);
	
	lua_pushlstring(L, str.c_str(), str.size());
	lua_pushboolean(L, out);
	return 2;
}

int w_Combo_Override4(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int current_item = luaL_checkint(L, 2);
	std::vector<const char*> items = luax_checkstringvector(L, 3);
	auto popup_max_height_in_items = luaL_optint(L, 4, -1);
	
	bool out = ImGui::Combo(label, &current_item, items, popup_max_height_in_items);
	
	lua_pushinteger(L, current_item);
	lua_pushboolean(L, out);
	return 2;
}

int w_ListBox_Override3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	int current_item = luaL_checkint(L, 2);
	std::vector<const char*> items = luax_checkstringvector(L, 3);
	auto height_in_items = luaL_optint(L, 4, -1);
	
	bool out = ImGui::ListBox(label, &current_item, items, height_in_items);
	
	lua_pushinteger(L, current_item);
	lua_pushboolean(L, out);
	return 2;
}

int w_PlotLines_Override3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	std::vector<float> values = luax_checkfloatvector(L, 2);
	auto values_offset = luaL_optint(L, 3, 0);
	auto overlay_text = luaL_optstring(L, 4, NULL);
	auto scale_min = static_cast<float>(luaL_optnumber(L, 5, FLT_MAX));
	auto scale_max = static_cast<float>(luaL_optnumber(L, 6, FLT_MAX));
	auto graph_size = ImVec2(0, 0);
	graph_size.x = luaL_optnumber(L, 7, graph_size.x);
	graph_size.y = luaL_optnumber(L, 8, graph_size.y);
	
	ImGui::PlotLines(label, values, values_offset, overlay_text, scale_min, scale_max, graph_size);
	
	return 0;
}

int w_PlotHistogram_Override3(lua_State *L)
{
	auto label = luaL_checkstring(L, 1);
	std::vector<float> values = luax_checkfloatvector(L, 2);
	auto values_offset = luaL_optint(L, 3, 0);
	auto overlay_text = luaL_optstring(L, 4, NULL);
	auto scale_min = static_cast<float>(luaL_optnumber(L, 5, FLT_MAX));
	auto scale_max = static_cast<float>(luaL_optnumber(L, 6, FLT_MAX));
	auto graph_size = ImVec2(0, 0);
	graph_size.x = luaL_optnumber(L, 7, graph_size.x);
	graph_size.y = luaL_optnumber(L, 8, graph_size.y);
	
	ImGui::PlotHistogram(label, values, values_offset, overlay_text, scale_min, scale_max, graph_size);
	
	return 0;
}

// End Functions }}}

// Function Overrides (manually written) {{{
// FIXME: these overrides create a a source of breakage when the imgui API
// changes. if IMGUI ever changes the order of function overrides on their end,
// or removes one of the API calls, we're in trouble!

static int w_Value(lua_State* L)
{
	if (lua_isboolean(L, 2)) {
		return w_Value_Override1(L); // prefix, b
	} else {
		return w_Value_Override4(L); // prefix, v, float_format=nil
	}
}

static int w_MenuItem(lua_State* L)
{
	if (lua_gettop(L) < 3) {
		return w_MenuItem_Override1(L); // label, shortcut
	} else {
		return w_MenuItem_Override2(L); // label, shortcut, p_selected, enabled
	}
}

static int w_IsRectVisible(lua_State* L)
{
	if (lua_gettop(L) <= 2) {
		return w_IsRectVisible_Override1(L); // size_x, size_y
	} else {
		return w_IsRectVisible_Override2(L); // rect_min_x, rect_min_y, rect_max_x, rect_max_y
	}
}

static int w_BeginChild(lua_State* L)
{
	if (lua_isstring(L, 1)) {
		return w_BeginChild_Override1(L); // str_id, size_x, size_y, border, flags
	} else {
		return w_BeginChild_Override2(L); // id, size_x, size_y, border, flags
	}
}

static int w_InputText(lua_State* L)
{
	return w_InputText_Override2(L); // std::string variant
}

static int w_InputTextMultiline(lua_State* L)
{
	return w_InputTextMultiline_Override2(L); // std::string variant
}

static int w_InputTextWithHint(lua_State* L)
{
	return w_InputTextWithHint_Override2(L); // std::string variant
}


static int w_SetWindowPos(lua_State* L)
{
	if (lua_isstring(L, 1)) {
		return w_SetWindowPos_Override2(L); // with window name
	} else {
		return w_SetWindowPos_Override1(L); // no window name
	}
}

static int w_SetWindowSize(lua_State* L)
{
	if (lua_isstring(L, 1)) {
		return w_SetWindowSize_Override2(L); // with window name
	} else {
		return w_SetWindowSize_Override1(L); // no window name
	}
}

static int w_SetWindowCollapsed(lua_State* L)
{
	if (lua_isstring(L, 1)) {
		return w_SetWindowCollapsed_Override2(L); // with window name
	} else {
		return w_SetWindowCollapsed_Override1(L); // no window name
	}
}

static int w_SetWindowFocus(lua_State* L)
{
	if (lua_isstring(L, 1)) {
		return w_SetWindowFocus_Override2(L); // with window name
	} else {
		return w_SetWindowFocus_Override1(L); // no window name
	}
}


static int w_PushStyleColor(lua_State* L)
{
	// Only one interesting override
	return w_PushStyleColor_Override2(L); // idx, col_r, col_g, col_b, col_a
}

static int w_PushStyleVar(lua_State* L)
{
	if (lua_isnumber(L, 3)) {
		return w_PushStyleVar_Override2(L); // idx, val_x, val_y
	} 

	return w_PushStyleVar_Override1(L); // idx, val_float
}

static int w_PushID(lua_State* L)
{
	if (lua_isstring(L, 2)) {
		return w_PushID_Override2(L); // str_id_begin, str_id_end
	} else if (lua_isstring(L, 1)) {
		return w_PushID_Override1(L); // str_id
	} 

	return w_PushID_Override4(L); // id
}

static int w_GetID(lua_State* L)
{
	if (lua_isstring(L, 2)) {
		return w_GetID_Override2(L); // str_id_begin, str_id_end
	}

	return w_GetID_Override1(L); // str_id
}

static int w_RadioButton(lua_State* L)
{
	if (lua_isboolean(L, 2)) {
		return w_RadioButton_Override1(L); // label, active
	} else {
		return w_RadioButton_Override2(L); // label, v, v_button
	}
}

static int w_TreeNode(lua_State* L)
{
	// TODO: Override2, Override3
	return w_TreeNode_Override1(L); // label
}

static int w_TreeNodeEx(lua_State* L)
{
	// TODO: Override2, Override3
	return w_TreeNodeEx_Override1(L); // label, flags
}

static int w_TreePush(lua_State* L)
{
	// intentionally only one override
	return w_TreePush_Override1(L); // str_id
}

static int w_CollapsingHeader(lua_State* L)
{
	if (lua_isboolean(L, 2)) {
		return w_CollapsingHeader_Override2(L); // label, p_open, flags
	} else {
		return w_CollapsingHeader_Override1(L); // label, flags
	}
}

static int w_Selectable(lua_State* L)
{
	// Only one interesting override
	return w_Selectable_Override2(L); // label, p_selected, flags, size
}

static int w_Combo(lua_State* L)
{
	if (lua_istable(L, 3)) {
		return w_Combo_Override4(L); // label, current_item, items, popup_max_height_in_items
	} else {
		return w_Combo_Override2(L); // label, current_item, items_separated_by_zeros, popup_max_height_in_items
	}
}

static int w_ListBox(lua_State* L)
{
	return w_ListBox_Override3(L); // label, current_item, items, height_in_items
}

static int w_PlotLines(lua_State* L)
{
	return w_PlotLines_Override3(L); // label, values, offset, overlay_text, scale_min, scale_max, graph_size_x, graph_size_y
}

static int w_PlotHistogram(lua_State* L)
{
	return w_PlotHistogram_Override3(L); // label, values, offset, overlay_text, scale_min, scale_max, graph_size_x, graph_size_y
}

static int w_ListBoxHeaderXY(lua_State* L)
{
		// There's no way to distinguish these two
	return w_ListBoxHeader_Override1(L); // label, size
}

static int w_ListBoxHeaderItems(lua_State* L)
{
		// There's no way to distinguish these two
	return w_ListBoxHeader_Override2(L); // label, count, height_in_items
}

static int w_ColorPicker4(lua_State* L)
{
	// manually implemented to handle ref_col, which is a little goofy
		auto label = luaL_checkstring(L, 1);
	float col[4];
	col[0] = static_cast<float>(luaL_checknumber(L, 2));
	col[1] = static_cast<float>(luaL_checknumber(L, 3));
	col[2] = static_cast<float>(luaL_checknumber(L, 4));
	col[3] = static_cast<float>(luaL_checknumber(L, 5));
	auto flags = luax_optflags<ImGuiColorEditFlags>(getImGuiColorEditFlagsFromString, L, 6, 0);
	float ref_col_data[4];
	float* ref_col = nullptr;
	if(lua_gettop(L) > 6) {
		ref_col_data[0] = static_cast<float>(luaL_checknumber(L, 7));
		ref_col_data[1] = static_cast<float>(luaL_checknumber(L, 8));
		ref_col_data[2] = static_cast<float>(luaL_checknumber(L, 9));
		ref_col_data[3] = static_cast<float>(luaL_checknumber(L, 10));
		ref_col = ref_col_data;
	}
	
	bool out = ImGui::ColorPicker4(label, col, flags, ref_col);
	
	lua_pushnumber(L, col[0]);
	lua_pushnumber(L, col[1]);
	lua_pushnumber(L, col[2]);
	lua_pushnumber(L, col[3]);
	lua_pushboolean(L, out);
	return 5;
}

// End Function Overrides }}}
}

// API entry points {{{

void wrap_imgui::addImguiWrappers(lua_State* L)
{
	lua_pushcfunction(L, w_SetColumnOffset);
	lua_setfield(L, -2, "SetColumnOffset");
	lua_pushcfunction(L, w_IsItemDeactivatedAfterEdit);
	lua_setfield(L, -2, "IsItemDeactivatedAfterEdit");
	lua_pushcfunction(L, w_GetTreeNodeToLabelSpacing);
	lua_setfield(L, -2, "GetTreeNodeToLabelSpacing");
	lua_pushcfunction(L, w_PopTextWrapPos);
	lua_setfield(L, -2, "PopTextWrapPos");
	lua_pushcfunction(L, w_EndDragDropSource);
	lua_setfield(L, -2, "EndDragDropSource");
	lua_pushcfunction(L, w_GetMousePos);
	lua_setfield(L, -2, "GetMousePos");
	lua_pushcfunction(L, w_GetID);
	lua_setfield(L, -2, "GetID");
	lua_pushcfunction(L, w_ColorButton);
	lua_setfield(L, -2, "ColorButton");
	lua_pushcfunction(L, w_PushStyleVar);
	lua_setfield(L, -2, "PushStyleVar");
	lua_pushcfunction(L, w_InputFloat);
	lua_setfield(L, -2, "InputFloat");
	lua_pushcfunction(L, w_IsMouseDown);
	lua_setfield(L, -2, "IsMouseDown");
	lua_pushcfunction(L, w_ShowStyleEditor);
	lua_setfield(L, -2, "ShowStyleEditor");
	lua_pushcfunction(L, w_BeginChild);
	lua_setfield(L, -2, "BeginChild");
	lua_pushcfunction(L, w_SliderInt3);
	lua_setfield(L, -2, "SliderInt3");
	lua_pushcfunction(L, w_GetCursorPosX);
	lua_setfield(L, -2, "GetCursorPosX");
	lua_pushcfunction(L, w_GetItemRectMin);
	lua_setfield(L, -2, "GetItemRectMin");
	lua_pushcfunction(L, w_EndChildFrame);
	lua_setfield(L, -2, "EndChildFrame");
	lua_pushcfunction(L, w_SetScrollHereY);
	lua_setfield(L, -2, "SetScrollHereY");
	lua_pushcfunction(L, w_GetContentRegionMax);
	lua_setfield(L, -2, "GetContentRegionMax");
	lua_pushcfunction(L, w_InputFloat3);
	lua_setfield(L, -2, "InputFloat3");
	lua_pushcfunction(L, w_SliderFloat2);
	lua_setfield(L, -2, "SliderFloat2");
	lua_pushcfunction(L, w_GetColumnOffset);
	lua_setfield(L, -2, "GetColumnOffset");
	lua_pushcfunction(L, w_VSliderFloat);
	lua_setfield(L, -2, "VSliderFloat");
	lua_pushcfunction(L, w_DockSpace);
	lua_setfield(L, -2, "DockSpace");
	lua_pushcfunction(L, w_IsKeyPressed);
	lua_setfield(L, -2, "IsKeyPressed");
	lua_pushcfunction(L, w_GetFontSize);
	lua_setfield(L, -2, "GetFontSize");
	lua_pushcfunction(L, w_GetContentRegionAvail);
	lua_setfield(L, -2, "GetContentRegionAvail");
	lua_pushcfunction(L, w_DockSpaceOverViewport);
	lua_setfield(L, -2, "DockSpaceOverViewport");
	lua_pushcfunction(L, w_BeginChildFrame);
	lua_setfield(L, -2, "BeginChildFrame");
	lua_pushcfunction(L, w_SetClipboardText);
	lua_setfield(L, -2, "SetClipboardText");
	lua_pushcfunction(L, w_PlotHistogram);
	lua_setfield(L, -2, "PlotHistogram");
	lua_pushcfunction(L, w_UpdatePlatformWindows);
	lua_setfield(L, -2, "UpdatePlatformWindows");
	lua_pushcfunction(L, w_IsWindowHovered);
	lua_setfield(L, -2, "IsWindowHovered");
	lua_pushcfunction(L, w_ProgressBar);
	lua_setfield(L, -2, "ProgressBar");
	lua_pushcfunction(L, w_DragFloat2);
	lua_setfield(L, -2, "DragFloat2");
	lua_pushcfunction(L, w_IsRectVisible);
	lua_setfield(L, -2, "IsRectVisible");
	lua_pushcfunction(L, w_GetKeyIndex);
	lua_setfield(L, -2, "GetKeyIndex");
	lua_pushcfunction(L, w_PlotLines);
	lua_setfield(L, -2, "PlotLines");
	lua_pushcfunction(L, w_RadioButton);
	lua_setfield(L, -2, "RadioButton");
	lua_pushcfunction(L, w_BeginTabItem);
	lua_setfield(L, -2, "BeginTabItem");
	lua_pushcfunction(L, w_IsItemEdited);
	lua_setfield(L, -2, "IsItemEdited");
	lua_pushcfunction(L, w_GetClipboardText);
	lua_setfield(L, -2, "GetClipboardText");
	lua_pushcfunction(L, w_CheckboxFlags);
	lua_setfield(L, -2, "CheckboxFlags");
	lua_pushcfunction(L, w_DragFloatRange2);
	lua_setfield(L, -2, "DragFloatRange2");
	lua_pushcfunction(L, w_GetVersion);
	lua_setfield(L, -2, "GetVersion");
	lua_pushcfunction(L, w_SetWindowPos);
	lua_setfield(L, -2, "SetWindowPos");
	lua_pushcfunction(L, w_DragInt3);
	lua_setfield(L, -2, "DragInt3");
	lua_pushcfunction(L, w_PushStyleColor);
	lua_setfield(L, -2, "PushStyleColor");
	lua_pushcfunction(L, w_EndMenuBar);
	lua_setfield(L, -2, "EndMenuBar");
	lua_pushcfunction(L, w_ShowAboutWindow);
	lua_setfield(L, -2, "ShowAboutWindow");
	lua_pushcfunction(L, w_SetNextWindowPos);
	lua_setfield(L, -2, "SetNextWindowPos");
	lua_pushcfunction(L, w_SetNextWindowFocus);
	lua_setfield(L, -2, "SetNextWindowFocus");
	lua_pushcfunction(L, w_GetWindowPos);
	lua_setfield(L, -2, "GetWindowPos");
	lua_pushcfunction(L, w_IsItemClicked);
	lua_setfield(L, -2, "IsItemClicked");
	lua_pushcfunction(L, w_CollapsingHeader);
	lua_setfield(L, -2, "CollapsingHeader");
	lua_pushcfunction(L, w_LogToTTY);
	lua_setfield(L, -2, "LogToTTY");
	lua_pushcfunction(L, w_GetWindowSize);
	lua_setfield(L, -2, "GetWindowSize");
	lua_pushcfunction(L, w_GetWindowHeight);
	lua_setfield(L, -2, "GetWindowHeight");
	lua_pushcfunction(L, w_IsMouseHoveringRect);
	lua_setfield(L, -2, "IsMouseHoveringRect");
	lua_pushcfunction(L, w_GetItemRectSize);
	lua_setfield(L, -2, "GetItemRectSize");
	lua_pushcfunction(L, w_AlignTextToFramePadding);
	lua_setfield(L, -2, "AlignTextToFramePadding");
	lua_pushcfunction(L, w_CloseCurrentPopup);
	lua_setfield(L, -2, "CloseCurrentPopup");
	lua_pushcfunction(L, w_SetColumnWidth);
	lua_setfield(L, -2, "SetColumnWidth");
	lua_pushcfunction(L, w_SetCursorPosX);
	lua_setfield(L, -2, "SetCursorPosX");
	lua_pushcfunction(L, w_GetWindowContentRegionMin);
	lua_setfield(L, -2, "GetWindowContentRegionMin");
	lua_pushcfunction(L, w_IsItemActivated);
	lua_setfield(L, -2, "IsItemActivated");
	lua_pushcfunction(L, w_Unindent);
	lua_setfield(L, -2, "Unindent");
	lua_pushcfunction(L, w_Combo);
	lua_setfield(L, -2, "Combo");
	lua_pushcfunction(L, w_SetScrollX);
	lua_setfield(L, -2, "SetScrollX");
	lua_pushcfunction(L, w_ImageButton);
	lua_setfield(L, -2, "ImageButton");
	lua_pushcfunction(L, w_PopAllowKeyboardFocus);
	lua_setfield(L, -2, "PopAllowKeyboardFocus");
	lua_pushcfunction(L, w_EndPopup);
	lua_setfield(L, -2, "EndPopup");
	lua_pushcfunction(L, w_SetNextWindowBgAlpha);
	lua_setfield(L, -2, "SetNextWindowBgAlpha");
	lua_pushcfunction(L, w_SliderInt4);
	lua_setfield(L, -2, "SliderInt4");
	lua_pushcfunction(L, w_SetWindowFocus);
	lua_setfield(L, -2, "SetWindowFocus");
	lua_pushcfunction(L, w_PushClipRect);
	lua_setfield(L, -2, "PushClipRect");
	lua_pushcfunction(L, w_LogToClipboard);
	lua_setfield(L, -2, "LogToClipboard");
	lua_pushcfunction(L, w_IsWindowCollapsed);
	lua_setfield(L, -2, "IsWindowCollapsed");
	lua_pushcfunction(L, w_IsMouseReleased);
	lua_setfield(L, -2, "IsMouseReleased");
	lua_pushcfunction(L, w_CreateContext);
	lua_setfield(L, -2, "CreateContext");
	lua_pushcfunction(L, w_NewLine);
	lua_setfield(L, -2, "NewLine");
	lua_pushcfunction(L, w_SetWindowSize);
	lua_setfield(L, -2, "SetWindowSize");
	lua_pushcfunction(L, w_SetCursorScreenPos);
	lua_setfield(L, -2, "SetCursorScreenPos");
	lua_pushcfunction(L, w_InputInt2);
	lua_setfield(L, -2, "InputInt2");
	lua_pushcfunction(L, w_ShowDemoWindow);
	lua_setfield(L, -2, "ShowDemoWindow");
	lua_pushcfunction(L, w_InputInt);
	lua_setfield(L, -2, "InputInt");
	lua_pushcfunction(L, w_TextColored);
	lua_setfield(L, -2, "TextColored");
	lua_pushcfunction(L, w_StyleColorsDark);
	lua_setfield(L, -2, "StyleColorsDark");
	lua_pushcfunction(L, w_GetWindowDpiScale);
	lua_setfield(L, -2, "GetWindowDpiScale");
	lua_pushcfunction(L, w_GetColumnsCount);
	lua_setfield(L, -2, "GetColumnsCount");
	lua_pushcfunction(L, w_IsPopupOpen);
	lua_setfield(L, -2, "IsPopupOpen");
	lua_pushcfunction(L, w_SaveIniSettingsToDisk);
	lua_setfield(L, -2, "SaveIniSettingsToDisk");
	lua_pushcfunction(L, w_SetWindowCollapsed);
	lua_setfield(L, -2, "SetWindowCollapsed");
	lua_pushcfunction(L, w_TreePop);
	lua_setfield(L, -2, "TreePop");
	lua_pushcfunction(L, w_MenuItem);
	lua_setfield(L, -2, "MenuItem");
	lua_pushcfunction(L, w_SetCurrentContext);
	lua_setfield(L, -2, "SetCurrentContext");
	lua_pushcfunction(L, w_LogButtons);
	lua_setfield(L, -2, "LogButtons");
	lua_pushcfunction(L, w_GetWindowDockID);
	lua_setfield(L, -2, "GetWindowDockID");
	lua_pushcfunction(L, w_SetColorEditOptions);
	lua_setfield(L, -2, "SetColorEditOptions");
	lua_pushcfunction(L, w_GetMouseCursor);
	lua_setfield(L, -2, "GetMouseCursor");
	lua_pushcfunction(L, w_PopID);
	lua_setfield(L, -2, "PopID");
	lua_pushcfunction(L, w_Value);
	lua_setfield(L, -2, "Value");
	lua_pushcfunction(L, w_OpenPopup);
	lua_setfield(L, -2, "OpenPopup");
	lua_pushcfunction(L, w_ColorPicker3);
	lua_setfield(L, -2, "ColorPicker3");
	lua_pushcfunction(L, w_SetMouseCursor);
	lua_setfield(L, -2, "SetMouseCursor");
	lua_pushcfunction(L, w_EndTabBar);
	lua_setfield(L, -2, "EndTabBar");
	lua_pushcfunction(L, w_InputFloat2);
	lua_setfield(L, -2, "InputFloat2");
	lua_pushcfunction(L, w_SliderFloat);
	lua_setfield(L, -2, "SliderFloat");
	lua_pushcfunction(L, w_SliderFloat4);
	lua_setfield(L, -2, "SliderFloat4");
	lua_pushcfunction(L, w_GetCursorPos);
	lua_setfield(L, -2, "GetCursorPos");
	lua_pushcfunction(L, w_InvisibleButton);
	lua_setfield(L, -2, "InvisibleButton");
	lua_pushcfunction(L, w_EndDragDropTarget);
	lua_setfield(L, -2, "EndDragDropTarget");
	lua_pushcfunction(L, w_BeginDragDropTarget);
	lua_setfield(L, -2, "BeginDragDropTarget");
	lua_pushcfunction(L, w_IsMouseDoubleClicked);
	lua_setfield(L, -2, "IsMouseDoubleClicked");
	lua_pushcfunction(L, w_SetNextItemOpen);
	lua_setfield(L, -2, "SetNextItemOpen");
	lua_pushcfunction(L, w_GetWindowWidth);
	lua_setfield(L, -2, "GetWindowWidth");
	lua_pushcfunction(L, w_IsAnyItemFocused);
	lua_setfield(L, -2, "IsAnyItemFocused");
	lua_pushcfunction(L, w_TextWrapped);
	lua_setfield(L, -2, "TextWrapped");
	lua_pushcfunction(L, w_GetStyleColorName);
	lua_setfield(L, -2, "GetStyleColorName");
	lua_pushcfunction(L, w_ColorEdit4);
	lua_setfield(L, -2, "ColorEdit4");
	lua_pushcfunction(L, w_BeginCombo);
	lua_setfield(L, -2, "BeginCombo");
	lua_pushcfunction(L, w_SmallButton);
	lua_setfield(L, -2, "SmallButton");
	lua_pushcfunction(L, w_IsMouseClicked);
	lua_setfield(L, -2, "IsMouseClicked");
	lua_pushcfunction(L, w_InputFloat4);
	lua_setfield(L, -2, "InputFloat4");
	lua_pushcfunction(L, w_BeginPopupContextWindow);
	lua_setfield(L, -2, "BeginPopupContextWindow");
	lua_pushcfunction(L, w_Checkbox);
	lua_setfield(L, -2, "Checkbox");
	lua_pushcfunction(L, w_SliderFloat3);
	lua_setfield(L, -2, "SliderFloat3");
	lua_pushcfunction(L, w_VSliderInt);
	lua_setfield(L, -2, "VSliderInt");
	lua_pushcfunction(L, w_TreeNodeEx);
	lua_setfield(L, -2, "TreeNodeEx");
	lua_pushcfunction(L, w_ShowFontSelector);
	lua_setfield(L, -2, "ShowFontSelector");
	lua_pushcfunction(L, w_SetScrollHereX);
	lua_setfield(L, -2, "SetScrollHereX");
	lua_pushcfunction(L, w_PushAllowKeyboardFocus);
	lua_setfield(L, -2, "PushAllowKeyboardFocus");
	lua_pushcfunction(L, w_PopStyleVar);
	lua_setfield(L, -2, "PopStyleVar");
	lua_pushcfunction(L, w_IsKeyReleased);
	lua_setfield(L, -2, "IsKeyReleased");
	lua_pushcfunction(L, w_IsMouseDragging);
	lua_setfield(L, -2, "IsMouseDragging");
	lua_pushcfunction(L, w_InputInt4);
	lua_setfield(L, -2, "InputInt4");
	lua_pushcfunction(L, w_IsKeyDown);
	lua_setfield(L, -2, "IsKeyDown");
	lua_pushcfunction(L, w_SameLine);
	lua_setfield(L, -2, "SameLine");
	lua_pushcfunction(L, w_Begin);
	lua_setfield(L, -2, "Begin");
	lua_pushcfunction(L, w_BeginMenu);
	lua_setfield(L, -2, "BeginMenu");
	lua_pushcfunction(L, w_ShowUserGuide);
	lua_setfield(L, -2, "ShowUserGuide");
	lua_pushcfunction(L, w_DragFloat);
	lua_setfield(L, -2, "DragFloat");
	lua_pushcfunction(L, w_InputDouble);
	lua_setfield(L, -2, "InputDouble");
	lua_pushcfunction(L, w_DragFloat3);
	lua_setfield(L, -2, "DragFloat3");
	lua_pushcfunction(L, w_SliderInt2);
	lua_setfield(L, -2, "SliderInt2");
	lua_pushcfunction(L, w_PopFont);
	lua_setfield(L, -2, "PopFont");
	lua_pushcfunction(L, w_IsItemHovered);
	lua_setfield(L, -2, "IsItemHovered");
	lua_pushcfunction(L, w_GetTextLineHeightWithSpacing);
	lua_setfield(L, -2, "GetTextLineHeightWithSpacing");
	lua_pushcfunction(L, w_GetKeyPressedAmount);
	lua_setfield(L, -2, "GetKeyPressedAmount");
	lua_pushcfunction(L, w_SetTabItemClosed);
	lua_setfield(L, -2, "SetTabItemClosed");
	lua_pushcfunction(L, w_GetStyle);
	lua_setfield(L, -2, "GetStyle");
	lua_pushcfunction(L, w_DragInt2);
	lua_setfield(L, -2, "DragInt2");
	lua_pushcfunction(L, w_ListBoxFooter);
	lua_setfield(L, -2, "ListBoxFooter");
	lua_pushcfunction(L, w_StyleColorsClassic);
	lua_setfield(L, -2, "StyleColorsClassic");
	lua_pushcfunction(L, w_BeginMainMenuBar);
	lua_setfield(L, -2, "BeginMainMenuBar");
	lua_pushcfunction(L, w_GetFrameHeight);
	lua_setfield(L, -2, "GetFrameHeight");
	lua_pushcfunction(L, w_DragIntRange2);
	lua_setfield(L, -2, "DragIntRange2");
	lua_pushcfunction(L, w_GetScrollY);
	lua_setfield(L, -2, "GetScrollY");
	lua_pushcfunction(L, w_GetCurrentContext);
	lua_setfield(L, -2, "GetCurrentContext");
	lua_pushcfunction(L, w_IsMousePosValid);
	lua_setfield(L, -2, "IsMousePosValid");
	lua_pushcfunction(L, w_IsWindowDocked);
	lua_setfield(L, -2, "IsWindowDocked");
	lua_pushcfunction(L, w_GetFrameHeightWithSpacing);
	lua_setfield(L, -2, "GetFrameHeightWithSpacing");
	lua_pushcfunction(L, w_NextColumn);
	lua_setfield(L, -2, "NextColumn");
	lua_pushcfunction(L, w_EndFrame);
	lua_setfield(L, -2, "EndFrame");
	lua_pushcfunction(L, w_PushItemWidth);
	lua_setfield(L, -2, "PushItemWidth");
	lua_pushcfunction(L, w_IsWindowAppearing);
	lua_setfield(L, -2, "IsWindowAppearing");
	lua_pushcfunction(L, w_EndCombo);
	lua_setfield(L, -2, "EndCombo");
	lua_pushcfunction(L, w_IsAnyMouseDown);
	lua_setfield(L, -2, "IsAnyMouseDown");
	lua_pushcfunction(L, w_LogToFile);
	lua_setfield(L, -2, "LogToFile");
	lua_pushcfunction(L, w_CaptureKeyboardFromApp);
	lua_setfield(L, -2, "CaptureKeyboardFromApp");
	lua_pushcfunction(L, w_BeginDragDropSource);
	lua_setfield(L, -2, "BeginDragDropSource");
	lua_pushcfunction(L, w_Columns);
	lua_setfield(L, -2, "Columns");
	lua_pushcfunction(L, w_ColorPicker4);
	lua_setfield(L, -2, "ColorPicker4");
	lua_pushcfunction(L, w_GetTime);
	lua_setfield(L, -2, "GetTime");
	lua_pushcfunction(L, w_SetNextWindowDockID);
	lua_setfield(L, -2, "SetNextWindowDockID");
	lua_pushcfunction(L, w_ListBoxHeaderItems);
	lua_setfield(L, -2, "ListBoxHeaderItems");
	lua_pushcfunction(L, w_ListBoxHeaderXY);
	lua_setfield(L, -2, "ListBoxHeaderXY");
	lua_pushcfunction(L, w_SetCursorPosY);
	lua_setfield(L, -2, "SetCursorPosY");
	lua_pushcfunction(L, w_InputTextWithHint);
	lua_setfield(L, -2, "InputTextWithHint");
	lua_pushcfunction(L, w_IsItemFocused);
	lua_setfield(L, -2, "IsItemFocused");
	lua_pushcfunction(L, w_PopButtonRepeat);
	lua_setfield(L, -2, "PopButtonRepeat");
	lua_pushcfunction(L, w_InputTextMultiline);
	lua_setfield(L, -2, "InputTextMultiline");
	lua_pushcfunction(L, w_IsWindowFocused);
	lua_setfield(L, -2, "IsWindowFocused");
	lua_pushcfunction(L, w_SetScrollFromPosX);
	lua_setfield(L, -2, "SetScrollFromPosX");
	lua_pushcfunction(L, w_ResetMouseDragDelta);
	lua_setfield(L, -2, "ResetMouseDragDelta");
	lua_pushcfunction(L, w_End);
	lua_setfield(L, -2, "End");
	lua_pushcfunction(L, w_InputText);
	lua_setfield(L, -2, "InputText");
	lua_pushcfunction(L, w_StyleColorsLight);
	lua_setfield(L, -2, "StyleColorsLight");
	lua_pushcfunction(L, w_SetScrollY);
	lua_setfield(L, -2, "SetScrollY");
	lua_pushcfunction(L, w_GetCursorPosY);
	lua_setfield(L, -2, "GetCursorPosY");
	lua_pushcfunction(L, w_LoadIniSettingsFromDisk);
	lua_setfield(L, -2, "LoadIniSettingsFromDisk");
	lua_pushcfunction(L, w_LogFinish);
	lua_setfield(L, -2, "LogFinish");
	lua_pushcfunction(L, w_SetItemDefaultFocus);
	lua_setfield(L, -2, "SetItemDefaultFocus");
	lua_pushcfunction(L, w_GetMouseDragDelta);
	lua_setfield(L, -2, "GetMouseDragDelta");
	lua_pushcfunction(L, w_SetScrollFromPosY);
	lua_setfield(L, -2, "SetScrollFromPosY");
	lua_pushcfunction(L, w_SetNextWindowCollapsed);
	lua_setfield(L, -2, "SetNextWindowCollapsed");
	lua_pushcfunction(L, w_BulletText);
	lua_setfield(L, -2, "BulletText");
	lua_pushcfunction(L, w_LabelText);
	lua_setfield(L, -2, "LabelText");
	lua_pushcfunction(L, w_SetNextWindowContentSize);
	lua_setfield(L, -2, "SetNextWindowContentSize");
	lua_pushcfunction(L, w_IsItemActive);
	lua_setfield(L, -2, "IsItemActive");
	lua_pushcfunction(L, w_Spacing);
	lua_setfield(L, -2, "Spacing");
	lua_pushcfunction(L, w_TextUnformatted);
	lua_setfield(L, -2, "TextUnformatted");
	lua_pushcfunction(L, w_Button);
	lua_setfield(L, -2, "Button");
	lua_pushcfunction(L, w_Image);
	lua_setfield(L, -2, "Image");
	lua_pushcfunction(L, w_Dummy);
	lua_setfield(L, -2, "Dummy");
	lua_pushcfunction(L, w_PushButtonRepeat);
	lua_setfield(L, -2, "PushButtonRepeat");
	lua_pushcfunction(L, w_Indent);
	lua_setfield(L, -2, "Indent");
	lua_pushcfunction(L, w_CalcItemWidth);
	lua_setfield(L, -2, "CalcItemWidth");
	lua_pushcfunction(L, w_BeginPopupModal);
	lua_setfield(L, -2, "BeginPopupModal");
	lua_pushcfunction(L, w_OpenPopupOnItemClick);
	lua_setfield(L, -2, "OpenPopupOnItemClick");
	lua_pushcfunction(L, w_CaptureMouseFromApp);
	lua_setfield(L, -2, "CaptureMouseFromApp");
	lua_pushcfunction(L, w_PopItemWidth);
	lua_setfield(L, -2, "PopItemWidth");
	lua_pushcfunction(L, w_DestroyPlatformWindows);
	lua_setfield(L, -2, "DestroyPlatformWindows");
	lua_pushcfunction(L, w_Separator);
	lua_setfield(L, -2, "Separator");
	lua_pushcfunction(L, w_SetNextItemWidth);
	lua_setfield(L, -2, "SetNextItemWidth");
	lua_pushcfunction(L, w_BeginGroup);
	lua_setfield(L, -2, "BeginGroup");
	lua_pushcfunction(L, w_GetFontTexUvWhitePixel);
	lua_setfield(L, -2, "GetFontTexUvWhitePixel");
	lua_pushcfunction(L, w_EndTooltip);
	lua_setfield(L, -2, "EndTooltip");
	lua_pushcfunction(L, w_ColorEdit3);
	lua_setfield(L, -2, "ColorEdit3");
	lua_pushcfunction(L, w_SetNextWindowViewport);
	lua_setfield(L, -2, "SetNextWindowViewport");
	lua_pushcfunction(L, w_GetStyleColorVec4);
	lua_setfield(L, -2, "GetStyleColorVec4");
	lua_pushcfunction(L, w_BeginPopup);
	lua_setfield(L, -2, "BeginPopup");
	lua_pushcfunction(L, w_IsItemVisible);
	lua_setfield(L, -2, "IsItemVisible");
	lua_pushcfunction(L, w_IsAnyItemActive);
	lua_setfield(L, -2, "IsAnyItemActive");
	lua_pushcfunction(L, w_GetFrameCount);
	lua_setfield(L, -2, "GetFrameCount");
	lua_pushcfunction(L, w_Render);
	lua_setfield(L, -2, "Render");
	lua_pushcfunction(L, w_CalcListClipping);
	lua_setfield(L, -2, "CalcListClipping");
	lua_pushcfunction(L, w_DestroyContext);
	lua_setfield(L, -2, "DestroyContext");
	lua_pushcfunction(L, w_Bullet);
	lua_setfield(L, -2, "Bullet");
	lua_pushcfunction(L, w_EndMainMenuBar);
	lua_setfield(L, -2, "EndMainMenuBar");
	lua_pushcfunction(L, w_ListBox);
	lua_setfield(L, -2, "ListBox");
	lua_pushcfunction(L, w_ShowMetricsWindow);
	lua_setfield(L, -2, "ShowMetricsWindow");
	lua_pushcfunction(L, w_BeginPopupContextItem);
	lua_setfield(L, -2, "BeginPopupContextItem");
	lua_pushcfunction(L, w_GetCursorStartPos);
	lua_setfield(L, -2, "GetCursorStartPos");
	lua_pushcfunction(L, w_PopStyleColor);
	lua_setfield(L, -2, "PopStyleColor");
	lua_pushcfunction(L, w_ArrowButton);
	lua_setfield(L, -2, "ArrowButton");
	lua_pushcfunction(L, w_IsItemToggledOpen);
	lua_setfield(L, -2, "IsItemToggledOpen");
	lua_pushcfunction(L, w_ShowStyleSelector);
	lua_setfield(L, -2, "ShowStyleSelector");
	lua_pushcfunction(L, w_GetWindowContentRegionWidth);
	lua_setfield(L, -2, "GetWindowContentRegionWidth");
	lua_pushcfunction(L, w_TreeNode);
	lua_setfield(L, -2, "TreeNode");
	lua_pushcfunction(L, w_LogText);
	lua_setfield(L, -2, "LogText");
	lua_pushcfunction(L, w_GetScrollMaxX);
	lua_setfield(L, -2, "GetScrollMaxX");
	lua_pushcfunction(L, w_Selectable);
	lua_setfield(L, -2, "Selectable");
	lua_pushcfunction(L, w_DragInt4);
	lua_setfield(L, -2, "DragInt4");
	lua_pushcfunction(L, w_SliderAngle);
	lua_setfield(L, -2, "SliderAngle");
	lua_pushcfunction(L, w_SetTooltip);
	lua_setfield(L, -2, "SetTooltip");
	lua_pushcfunction(L, w_GetCursorScreenPos);
	lua_setfield(L, -2, "GetCursorScreenPos");
	lua_pushcfunction(L, w_GetScrollMaxY);
	lua_setfield(L, -2, "GetScrollMaxY");
	lua_pushcfunction(L, w_PushID);
	lua_setfield(L, -2, "PushID");
	lua_pushcfunction(L, w_BeginPopupContextVoid);
	lua_setfield(L, -2, "BeginPopupContextVoid");
	lua_pushcfunction(L, w_GetColumnWidth);
	lua_setfield(L, -2, "GetColumnWidth");
	lua_pushcfunction(L, w_GetMousePosOnOpeningCurrentPopup);
	lua_setfield(L, -2, "GetMousePosOnOpeningCurrentPopup");
	lua_pushcfunction(L, w_InputInt3);
	lua_setfield(L, -2, "InputInt3");
	lua_pushcfunction(L, w_DragInt);
	lua_setfield(L, -2, "DragInt");
	lua_pushcfunction(L, w_NewFrame);
	lua_setfield(L, -2, "NewFrame");
	lua_pushcfunction(L, w_IsAnyItemHovered);
	lua_setfield(L, -2, "IsAnyItemHovered");
	lua_pushcfunction(L, w_EndChild);
	lua_setfield(L, -2, "EndChild");
	lua_pushcfunction(L, w_TreePush);
	lua_setfield(L, -2, "TreePush");
	lua_pushcfunction(L, w_BeginTooltip);
	lua_setfield(L, -2, "BeginTooltip");
	lua_pushcfunction(L, w_SetWindowFontScale);
	lua_setfield(L, -2, "SetWindowFontScale");
	lua_pushcfunction(L, w_SliderInt);
	lua_setfield(L, -2, "SliderInt");
	lua_pushcfunction(L, w_EndTabItem);
	lua_setfield(L, -2, "EndTabItem");
	lua_pushcfunction(L, w_TextDisabled);
	lua_setfield(L, -2, "TextDisabled");
	lua_pushcfunction(L, w_GetTextLineHeight);
	lua_setfield(L, -2, "GetTextLineHeight");
	lua_pushcfunction(L, w_GetColumnIndex);
	lua_setfield(L, -2, "GetColumnIndex");
	lua_pushcfunction(L, w_SetNextWindowSize);
	lua_setfield(L, -2, "SetNextWindowSize");
	lua_pushcfunction(L, w_BeginMenuBar);
	lua_setfield(L, -2, "BeginMenuBar");
	lua_pushcfunction(L, w_GetScrollX);
	lua_setfield(L, -2, "GetScrollX");
	lua_pushcfunction(L, w_BeginTabBar);
	lua_setfield(L, -2, "BeginTabBar");
	lua_pushcfunction(L, w_PushTextWrapPos);
	lua_setfield(L, -2, "PushTextWrapPos");
	lua_pushcfunction(L, w_GetWindowContentRegionMax);
	lua_setfield(L, -2, "GetWindowContentRegionMax");
	lua_pushcfunction(L, w_CalcTextSize);
	lua_setfield(L, -2, "CalcTextSize");
	lua_pushcfunction(L, w_EndGroup);
	lua_setfield(L, -2, "EndGroup");
	lua_pushcfunction(L, w_EndMenu);
	lua_setfield(L, -2, "EndMenu");
	lua_pushcfunction(L, w_SetKeyboardFocusHere);
	lua_setfield(L, -2, "SetKeyboardFocusHere");
	lua_pushcfunction(L, w_PopClipRect);
	lua_setfield(L, -2, "PopClipRect");
	lua_pushcfunction(L, w_SetCursorPos);
	lua_setfield(L, -2, "SetCursorPos");
	lua_pushcfunction(L, w_DragFloat4);
	lua_setfield(L, -2, "DragFloat4");
	lua_pushcfunction(L, w_IsItemDeactivated);
	lua_setfield(L, -2, "IsItemDeactivated");
	lua_pushcfunction(L, w_GetItemRectMax);
	lua_setfield(L, -2, "GetItemRectMax");
	lua_pushcfunction(L, w_SetItemAllowOverlap);
	lua_setfield(L, -2, "SetItemAllowOverlap");
	lua_pushcfunction(L, w_ColorConvertU32ToFloat4);
	lua_setfield(L, -2, "ColorConvertU32ToFloat4");
	lua_pushcfunction(L, w_Text);
	lua_setfield(L, -2, "Text");
}

void wrap_imgui::createImguiTable(lua_State* L)
{
	lua_createtable(L, 0, 283); 
	addImguiWrappers(L);
}

// End API entry points }}}
