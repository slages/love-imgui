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
<% for _, enumData in ipairs(imgui.enums) do %>
<%- helpers.genEnumFromString(imgui, enumData) %>
<% end %>


// Functions
<% for _, fnData in ipairs(imgui.functions) do %>
<%- helpers.genFunctionWrapper(imgui, fnData) %>
<% end %>

void addImguiWrappers(lua_State* L)
{
<% for _, fnData in ipairs(imgui.validFunctions) do %>
	lua_pushcfunction(L, w_<%- fnData.name %>);
	lua_setfield(L, -2, "<%- fnData.name %>");
<% end %>
}

void createImguiTable(lua_State* L)
{
	lua_createtable(L, 0, <%- #imgui.validFunctions %>); 
	addImguiWrappers(L);
}
