// This is an automatically generated file!!
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include "wrap_imgui_codegen.h"
#include "imgui.h"
#include "imgui_stdlib.h"

#include <array>
#include <optional>
#include <string>
#include <vector>
#include <sstream>
#include <locale>

extern ImTextureID luax_checkTextureID(lua_State* L, int narg); // define in your application

namespace {
	long g_currentFrameNumber = 0;

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

// Manually Implemented Wrappers {{{
struct FuncRef {
	lua_State* L = nullptr;
	int index = 0;
};

// unicode
// lifted from sol2, which in turn was lifted from ogonek apparently :)
namespace unicode {
	enum class error_code {
		ok = 0,
		invalid_code_point,
		invalid_code_unit,
		invalid_leading_surrogate,
		invalid_trailing_surrogate,
		sequence_too_short,
		overlong_sequence,
	};

	template <typename It>
	struct decoded_result {
		error_code error;
		char32_t codepoint;
		It next;
	};

	template <typename C>
	struct encoded_result {
		error_code error;
		std::size_t code_units_size;
		std::array<C, 4> code_units;
	};

	struct unicode_detail {
		// codepoint related
		static constexpr char32_t last_code_point = 0x10FFFF;

		static constexpr char32_t first_lead_surrogate = 0xD800;
		static constexpr char32_t last_lead_surrogate = 0xDBFF;

		static constexpr char32_t first_trail_surrogate = 0xDC00;
		static constexpr char32_t last_trail_surrogate = 0xDFFF;

		static constexpr char32_t first_surrogate = first_lead_surrogate;
		static constexpr char32_t last_surrogate = last_trail_surrogate;

		static constexpr bool is_lead_surrogate(char32_t u) {
			return u >= first_lead_surrogate && u <= last_lead_surrogate;
		}
		static constexpr bool is_trail_surrogate(char32_t u) {
			return u >= first_trail_surrogate && u <= last_trail_surrogate;
		}
		static constexpr bool is_surrogate(char32_t u) {
			return u >= first_surrogate && u <= last_surrogate;
		}

		// utf8 related
		static constexpr auto last_1byte_value = 0x7Fu;
		static constexpr auto last_2byte_value = 0x7FFu;
		static constexpr auto last_3byte_value = 0xFFFFu;

		static constexpr auto start_2byte_mask = 0x80u;
		static constexpr auto start_3byte_mask = 0xE0u;
		static constexpr auto start_4byte_mask = 0xF0u;

		static constexpr auto continuation_mask = 0xC0u;
		static constexpr auto continuation_signature = 0x80u;

		static constexpr bool is_invalid(unsigned char b) {
			return b == 0xC0 || b == 0xC1 || b > 0xF4;
		}

		static constexpr bool is_continuation(unsigned char b) {
			return (b & unicode_detail::continuation_mask) == unicode_detail::continuation_signature;
		}

		static constexpr bool is_overlong(char32_t u, std::size_t bytes) {
			return u <= unicode_detail::last_1byte_value || (u <= unicode_detail::last_2byte_value && bytes > 2)
				 || (u <= unicode_detail::last_3byte_value && bytes > 3);
		}

		static constexpr int sequence_length(unsigned char b) {
			return (b & start_2byte_mask) == 0 ? 1
				: (b & start_3byte_mask) != start_3byte_mask ? 2
				: (b & start_4byte_mask) != start_4byte_mask ? 3
				: 4;
		}

		static constexpr char32_t decode(unsigned char b0, unsigned char b1) {
			return ((b0 & 0x1F) << 6) | (b1 & 0x3F);
		}
		static constexpr char32_t decode(unsigned char b0, unsigned char b1, unsigned char b2) {
			return ((b0 & 0x0F) << 12) | ((b1 & 0x3F) << 6) | (b2 & 0x3F);
		}
		static constexpr char32_t decode(unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3) {
			return ((b0 & 0x07) << 18) | ((b1 & 0x3F) << 12) | ((b2 & 0x3F) << 6) | (b3 & 0x3F);
		}

		// utf16 related
		static constexpr char32_t last_bmp_value = 0xFFFF;
		static constexpr char32_t normalizing_value = 0x10000;
		static constexpr int lead_surrogate_bitmask = 0xFFC00;
		static constexpr int trail_surrogate_bitmask = 0x3FF;
		static constexpr int lead_shifted_bits = 10;
		static constexpr char32_t replacement = 0xFFFD;

		static char32_t combine_surrogates(char16_t lead, char16_t trail) {
			auto hi = lead - first_lead_surrogate;
			auto lo = trail - first_trail_surrogate;
			return normalizing_value + ((hi << lead_shifted_bits) | lo);
		}
	};

	inline encoded_result<char> code_point_to_utf8(char32_t codepoint) {
		encoded_result<char> er;
		er.error = error_code::ok;
		if (codepoint <= unicode_detail::last_1byte_value) {
			er.code_units_size = 1;
			er.code_units = std::array<char, 4>{ { static_cast<char>(codepoint) } };
		}
		else if (codepoint <= unicode_detail::last_2byte_value) {
			er.code_units_size = 2;
			er.code_units = std::array<char, 4>{{
				static_cast<char>(0xC0 | ((codepoint & 0x7C0) >> 6)),
				static_cast<char>(0x80 | (codepoint & 0x3F)),
			}};
		}
		else if (codepoint <= unicode_detail::last_3byte_value) {
			er.code_units_size = 3;
			er.code_units = std::array<char, 4>{{
				static_cast<char>(0xE0 | ((codepoint & 0xF000) >> 12)),
				static_cast<char>(0x80 | ((codepoint & 0xFC0) >> 6)),
				static_cast<char>(0x80 | (codepoint & 0x3F)),
			}};
		}
		else {
			er.code_units_size = 4;
			er.code_units = std::array<char, 4>{ {
				static_cast<char>(0xF0 | ((codepoint & 0x1C0000) >> 18)),
					static_cast<char>(0x80 | ((codepoint & 0x3F000) >> 12)),
					static_cast<char>(0x80 | ((codepoint & 0xFC0) >> 6)),
					static_cast<char>(0x80 | (codepoint & 0x3F)),
			} };
		}
		return er;
	}

	inline encoded_result<char16_t> code_point_to_utf16(char32_t codepoint) {
		encoded_result<char16_t> er;

		if (codepoint <= unicode_detail::last_bmp_value) {
			er.code_units_size = 1;
			er.code_units = std::array<char16_t, 4>{ { static_cast<char16_t>(codepoint) } };
			er.error = error_code::ok;
		}
		else {
			auto normal = codepoint - unicode_detail::normalizing_value;
			auto lead = unicode_detail::first_lead_surrogate + ((normal & unicode_detail::lead_surrogate_bitmask) >> unicode_detail::lead_shifted_bits);
			auto trail = unicode_detail::first_trail_surrogate + (normal & unicode_detail::trail_surrogate_bitmask);
			er.code_units = std::array<char16_t, 4>{ {
				static_cast<char16_t>(lead),
				static_cast<char16_t>(trail)
			} };
			er.code_units_size = 2;
			er.error = error_code::ok;
		}
		return er;
	}

	inline encoded_result<char32_t> code_point_to_utf32(char32_t codepoint) {
		encoded_result<char32_t> er;
		er.code_units_size = 1;
		er.code_units[0] = codepoint;
		er.error = error_code::ok;
		return er;
	}

	template <typename It>
	inline decoded_result<It> utf8_to_code_point(It it, It last) {
		decoded_result<It> dr;
		if (it == last) {
			dr.next = it;
			dr.error = error_code::sequence_too_short;
			return dr;
		}

		unsigned char b0 = *it;
		std::size_t length = unicode_detail::sequence_length(b0);

		if (length == 1) {
			dr.codepoint = static_cast<char32_t>(b0);
			dr.error = error_code::ok;
			++it;
			dr.next = it;
			return dr;
		}

		if (unicode_detail::is_invalid(b0) || unicode_detail::is_continuation(b0)) {
			dr.error = error_code::invalid_code_unit;
			dr.next = it;
			return dr;
		}

		++it;
		std::array<unsigned char, 4> b;
		b[0] = b0;
		for (std::size_t i = 1; i < length; ++i) {
			b[i] = *it;
			if (!unicode_detail::is_continuation(b[i])) {
				dr.error = error_code::invalid_code_unit;
				dr.next = it;
				return dr;
			}
			++it;
		}

		char32_t decoded;
		switch (length) {
		case 2:
			decoded = unicode_detail::decode(b[0], b[1]);
			break;
		case 3:
			decoded = unicode_detail::decode(b[0], b[1], b[2]);
			break;
		default:
			decoded = unicode_detail::decode(b[0], b[1], b[2], b[3]);
			break;
		}

		if (unicode_detail::is_overlong(decoded, length)) {
			dr.error = error_code::overlong_sequence;
			return dr;
		}
		if (unicode_detail::is_surrogate(decoded) || decoded > unicode_detail::last_code_point) {
			dr.error = error_code::invalid_code_point;
			return dr;
		}
		
		// then everything is fine
		dr.codepoint = decoded;
		dr.error = error_code::ok;
		dr.next = it;
		return dr;
	}

	template <typename It>
	inline decoded_result<It> utf16_to_code_point(It it, It last) {
		decoded_result<It> dr;
		if (it == last) {
			dr.next = it;
			dr.error = error_code::sequence_too_short;
			return dr;
		}

		char16_t lead = static_cast<char16_t>(*it);
		
		if (!unicode_detail::is_surrogate(lead)) {
			++it;
			dr.codepoint = static_cast<char32_t>(lead);
			dr.next = it;
			dr.error = error_code::ok;
			return dr;
		}
		if (!unicode_detail::is_lead_surrogate(lead)) {
			dr.error = error_code::invalid_leading_surrogate;
			dr.next = it;
			return dr;
		}

		++it;
		auto trail = *it;
		if (!unicode_detail::is_trail_surrogate(trail)) {
			dr.error = error_code::invalid_trailing_surrogate;
			dr.next = it;
			return dr;
		}
		
		dr.codepoint = unicode_detail::combine_surrogates(lead, trail);
		dr.next = ++it;
		dr.error = error_code::ok;
		return dr;
	}

	template <typename It>
	inline decoded_result<It> utf32_to_code_point(It it, It last) {
		decoded_result<It> dr;
		if (it == last) {
			dr.next = it;
			dr.error = error_code::sequence_too_short;
			return dr;
		}
		dr.codepoint = static_cast<char32_t>(*it);
		dr.next = ++it;
		dr.error = error_code::ok;
		return dr;
	}
}

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
	if(data->Flags & ImGuiInputTextFlags_CallbackCharFilter) {
		ImWchar k = data->EventChar;
		unicode::encoded_result<char> result = unicode::code_point_to_utf8(k);
		if (result.error == unicode::error_code::ok) {
			lua_pushlstring(L, result.code_units.data(), result.code_units_size);
			lua_setfield(L, -2, "EventChar");
		}
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
		size_t len;
		const char* k = lua_tolstring(L, -1, &len);
		lua_pop(L, 1);
		auto result = unicode::utf8_to_code_point(k, k+len);
		if (result.error == unicode::error_code::ok && result.codepoint < INT16_MAX)
		{
			data->EventChar = static_cast<ImWchar>(result.codepoint);
		}
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

struct WrapImDrawList
{
	ImDrawList* value;
	long frameNumber;
	void init() { frameNumber = 0L; }
	bool isValid() { return g_currentFrameNumber == frameNumber; }
};

<% helpers.addFunctionOverride(imgui.functions.ImGui, "bool ColorPicker4(const char* label, float& col1, float& col2, float& col3, float& col4, flags);") -%>
int w_ColorPicker4(lua_State* L)
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

<% helpers.addFunctionOverride(imgui.functions.ImGui, "void NewFrame();") -%>
int w_NewFrame(lua_State* L)
{
	// manually implemented to track new frames
	ImGui::NewFrame();
	g_currentFrameNumber++;
	return 0;
}

// End Manually Implemented Wrappers }}}

// Functions {{{
<% for _, fnElement in util.sortedPairs(imgui.functions) do -%>
<% for _, fnData in ipairs(fnElement.fnData) do -%>
<%- helpers.genFunctionWrapper(fnElement, fnData) %>

<% end -%>
<% end -%>
// End Functions }}}

// Function Overrides (manually written) {{{
// FIXME: these overrides create a a source of breakage when the imgui API
// changes. if IMGUI ever changes the order of function overrides on their end,
// or removes one of the API calls, we're in trouble!

int w_Value(lua_State* L)
{
	if (lua_isboolean(L, 2)) {
		return w_Value_Override1(L); // prefix, b
	} else {
		return w_Value_Override4(L); // prefix, v, float_format=nil
	}
}

int w_MenuItem(lua_State* L)
{
	if (lua_gettop(L) < 3) {
		return w_MenuItem_Override1(L); // label, shortcut
	} else {
		return w_MenuItem_Override2(L); // label, shortcut, p_selected, enabled
	}
}

int w_IsRectVisible(lua_State* L)
{
	if (lua_gettop(L) <= 2) {
		return w_IsRectVisible_Override1(L); // size_x, size_y
	} else {
		return w_IsRectVisible_Override2(L); // rect_min_x, rect_min_y, rect_max_x, rect_max_y
	}
}

int w_BeginChild(lua_State* L)
{
	if (lua_isstring(L, 1)) {
		return w_BeginChild_Override1(L); // str_id, size_x, size_y, border, flags
	} else {
		return w_BeginChild_Override2(L); // id, size_x, size_y, border, flags
	}
}

int w_InputText(lua_State* L)
{
	return w_InputText_Override2(L); // std::string variant
}

int w_InputTextMultiline(lua_State* L)
{
	return w_InputTextMultiline_Override2(L); // std::string variant
}

int w_InputTextWithHint(lua_State* L)
{
	return w_InputTextWithHint_Override2(L); // std::string variant
}

<% 
local windowFunctions = {"SetWindowPos", "SetWindowSize", "SetWindowCollapsed", "SetWindowFocus"}
for _, fn in ipairs(windowFunctions) do
%>
int w_<%-fn%>(lua_State* L)
{
	if (lua_isstring(L, 1)) {
		return w_<%-fn%>_Override2(L); // with window name
	} else {
		return w_<%-fn%>_Override1(L); // no window name
	}
}
<% end %>

int w_PushStyleColor(lua_State* L)
{
	// Only one interesting override
	return w_PushStyleColor_Override2(L); // idx, col_r, col_g, col_b, col_a
}

int w_PushStyleVar(lua_State* L)
{
	if (lua_isnumber(L, 3)) {
		return w_PushStyleVar_Override2(L); // idx, val_x, val_y
	} 

	return w_PushStyleVar_Override1(L); // idx, val_float
}

int w_PushID(lua_State* L)
{
	if (lua_isstring(L, 2)) {
		return w_PushID_Override2(L); // str_id_begin, str_id_end
	} else if (lua_isstring(L, 1)) {
		return w_PushID_Override1(L); // str_id
	} 

	return w_PushID_Override4(L); // id
}

int w_GetID(lua_State* L)
{
	if (lua_isstring(L, 2)) {
		return w_GetID_Override2(L); // str_id_begin, str_id_end
	}

	return w_GetID_Override1(L); // str_id
}

int w_RadioButton(lua_State* L)
{
	if (lua_isboolean(L, 2)) {
		return w_RadioButton_Override1(L); // label, active
	} else {
		return w_RadioButton_Override2(L); // label, v, v_button
	}
}

int w_TreeNode(lua_State* L)
{
	// TODO: Override2, Override3
	return w_TreeNode_Override1(L); // label
}

int w_TreeNodeEx(lua_State* L)
{
	// TODO: Override2, Override3
	return w_TreeNodeEx_Override1(L); // label, flags
}

int w_TreePush(lua_State* L)
{
	// intentionally only one override
	return w_TreePush_Override1(L); // str_id
}

int w_CollapsingHeader(lua_State* L)
{
	if (lua_isboolean(L, 2)) {
		return w_CollapsingHeader_Override2(L); // label, p_open, flags
	} else {
		return w_CollapsingHeader_Override1(L); // label, flags
	}
}

int w_Selectable(lua_State* L)
{
	// Only one interesting override
	return w_Selectable_Override2(L); // label, p_selected, flags, size
}

int w_Combo(lua_State* L)
{
	return w_Combo_Override2(L); // label, current_item, items_separated_by_zeros, popup_max_height_in_items
}

<% helpers.chooseFunctionOverride(imgui.functions.ImGui, "ListBoxHeaderXY", "ImGui::ListBoxHeader", 1) -%>
int w_ListBoxHeaderXY(lua_State* L)
{
	// There's no way to distinguish these two
	return w_ListBoxHeader_Override1(L); // label, size
}

<% helpers.chooseFunctionOverride(imgui.functions.ImGui,"ListBoxHeaderItems", "ImGui::ListBoxHeader", 2) -%>
int w_ListBoxHeaderItems(lua_State* L)
{
	// There's no way to distinguish these two
	return w_ListBoxHeader_Override2(L); // label, count, height_in_items
}

<% helpers.removeValidFunction(imgui.functions.ImGui, "ListBoxHeader") -%>

int w_GetForegroundDrawList(lua_State* L)
{
	return w_GetForegroundDrawList_Override1(L);
}

int w_GetBackgroundDrawList(lua_State* L)
{
	return w_GetBackgroundDrawList_Override1(L);
}

int w_ImDrawList_AddText(lua_State* L)
{
	return w_ImDrawList_AddText_Override1(L);
}

// End Function Overrides }}}
}

// API entry points {{{

void wrap_imgui::addImguiWrappers(lua_State* L)
{
<% for name in util.lineNumberPairs(imgui.functions.ImGui.validNames) do -%>
	lua_pushcfunction(L, w_<%- name %>);
	lua_setfield(L, -2, "<%- name %>");
<% end -%>

	luaL_newmetatable(L, "ImDrawList");
<% for name in util.lineNumberPairs(imgui.functions.ImDrawList.validNames) do -%>
	lua_pushcfunction(L, w_ImDrawList_<%- name %>);
	lua_setfield(L, -2, "<%- name %>");
<% end -%>
}

void wrap_imgui::createImguiTable(lua_State* L)
{
	lua_createtable(L, 0, <%- util.count(imgui.functions.ImGui.validNames) %>); 
	addImguiWrappers(L);
}

// End API entry points }}}
