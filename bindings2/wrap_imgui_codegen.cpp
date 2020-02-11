// This is an automatically generated file!!
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

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

float luax_optfloat(lua_State* L, int narg, float d)
{
	if(lua_isnoneornil(L, narg)) {
		return d;
	}
	return static_cast<float>(lua_tonumber(L, narg));
}

float luax_checkfloat(lua_State* L, int narg)
{
	return static_cast<float>(luaL_checknumber(L, narg));
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
	T out{};
	if (lua_isnumber(L, narg)) {
		// variant A: raw number
		out = static_cast<T>(lua_tointeger(L, narg));
	} else if (lua_isstring(L, narg)) {
		// variant B: string, split by '|'
		const char* s = lua_tostring(L, narg);
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);
		while (std::getline(tokenStream, token, '|')) {
			std::optional<T> opt = fromString(token.c_str());
			if (!opt) {
				luaL_error(L, "Unrecognized value in flags parameter %d: %s", narg, token.c_str());
			}
			out = out | *opt;
		}
	} else if (lua_istable(L, narg)) {
		// Variant C: table, both [enum] = true, and "enum" are supported
		lua_pushvalue(L, narg); // t
		lua_pushnil(L); // t, k(nil)
		while (lua_next(L, -2)) {// t, k, v
			lua_pushvalue(L, -2); // t, k, v, k
			if (lua_isstring(L, -1)) {
				const char* flagString = lua_tostring(L, -1);
				std::optional<T> opt = fromString(flagString);
				if (!opt) {
					luaL_error(L, "Unrecognized enum in flags parameter %d: %s.", narg);
				}
				bool enabled = lua_toboolean(L, -2);
				if (enabled) {
					out = out | *opt;
				}
			} else if (lua_isnumber(L, -1)) {
				const char* flagString = lua_tostring(L, -2);
				std::optional<T> opt = fromString(flagString);
				if (!opt) {
					luaL_error(L, "Unrecognized enum in flags parameter %d: %s.", narg);
				}
				out = out | *opt;
			}

			lua_pop(L, 2); // t, k
		}
		lua_pop(L, 1); // clean
	} else {
		luaL_error(L, "Unrecognized flag parameter %d: must be int, string, or table", narg);
	}

	return out;
}

template<typename T, typename U>
T luax_optflags(U fromString, lua_State* L, int narg, T d)
{
	if (lua_isnoneornil(L, narg)) {
		return d;
	}
	return luax_checkflags<T, U>(fromString, L, narg);
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
<% for _, enumData in ipairs(imgui.enums) do %>
<%- helpers.genEnumFromString(imgui, enumData) %>
<% end %>
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

	//using int16_t instead of char16_t to avoid a visual studio bug in codecvt
	std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t> convert;
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
	int out = static_cast<int>(lua_tointeger(L, -1));
	lua_pop(L, 1);

	if(data->Flags & ImGuiInputTextFlags_CallbackCharFilter) {
		lua_getfield(L, -2, "EventChar");
		const char* k = lua_tostring(L, -1);
		std::basic_string<int16_t> u16str = convert.from_bytes(k);
		data->EventChar = u16str.at(0);
		lua_pop(L, 1);
	}
	delete ref;
	data->UserData = nullptr;
	return out;
}

void* luax_getImguiInputTextCallback(lua_State* L, int narg)
{
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
<% for _, fnData in ipairs(imgui.functions) do %>
<%- helpers.genFunctionWrapper(imgui, fnData) %>
<% end %>
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

<% 
local windowFunctions = {"SetWindowPos", "SetWindowSize", "SetWindowCollapsed", "SetWindowFocus"}
for _, fn in ipairs(windowFunctions) do
%>
static int w_<%-fn%>(lua_State* L)
{
	if (lua_isstring(L, 1)) {
		return w_<%-fn%>_Override2(L); // with window name
	} else {
		return w_<%-fn%>_Override1(L); // no window name
	}
}
<% end %>

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

<% helpers.removeValidFunction(imgui, "ListBoxHeader") -%>
static int w_ListBoxHeaderXY(lua_State* L)
{
	<% helpers.addValidFunctions(imgui, "ListBoxHeaderXY") -%>
	// There's no way to distinguish these two
	return w_ListBoxHeader_Override1(L); // label, size
}

static int w_ListBoxHeaderItems(lua_State* L)
{
	<% helpers.addValidFunctions(imgui, "ListBoxHeaderItems") -%>
	// There's no way to distinguish these two
	return w_ListBoxHeader_Override2(L); // label, count, height_in_items
}

static int w_ColorPicker4(lua_State* L)
{
	// manually implemented to handle ref_col, which is a little goofy
	<% helpers.addValidFunctions(imgui, "ColorPicker4") -%>
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
<% for name in pairs(imgui.validFunctionNames) do -%>
	lua_pushcfunction(L, w_<%- name %>);
	lua_setfield(L, -2, "<%- name %>");
<% end -%>
}

void wrap_imgui::createImguiTable(lua_State* L)
{
	lua_createtable(L, 0, <%- helpers.count(imgui.validFunctionNames) %>); 
	addImguiWrappers(L);
}

// End API entry points }}}
