/**
* Copyright (c) 2006-2016 LOVE Development Team
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
**/

#include "libimgui/imgui.h"
#include "imgui_impl.h"
#include "wrap_imgui_codegen.h"

#include <vector>
#include <cstring>

#if defined(_WIN32) || defined(_WIN64)

#include <math.h>

// strndup() is not available on Windows
char *strndup( const char *s1, size_t n)
{
    char *copy= (char*)malloc( n+1 );
    memcpy( copy, s1, n );
    copy[n] = 0;
    return copy;
};

#endif

/*
** Love implentation functions
*/
static bool g_inited = false;
static int	g_textures[250]; // Should be enough

static int w_ShutDown(lua_State *L)
{
	ShutDown();
	return 0;
}

static int w_NewFrame(lua_State *L)
{
	if (!g_inited)
	{
		Init(L);
		g_inited = true;
	}
	NewFrame();
	return 0;
}

static int w_Render(lua_State *L)
{
	Render();
	return 0;
}

// Util
const char* getRealDirectoryIfExists(lua_State *L, const char* relativePath)
{
    if (L == nullptr || relativePath == nullptr)
    {
        return nullptr;
    }

    int originalStackSize = lua_gettop(L);
    lua_getglobal(L, "love");
    if (lua_isnil(L, -1))
    {
        lua_pop(L, 1);
        return nullptr;
    }

    lua_getfield(L, -1, "filesystem");
    lua_getfield(L, -1, "getRealDirectory");
    lua_pushstring(L, relativePath);
    lua_call(L, 1, 1);

    char* result = nullptr;
    if (!lua_isnil(L, -1))
    {
        size_t size = 0;
        const char* tmp = lua_tolstring(L, -1, &size);
        result = strndup(tmp, size);
    }

    lua_pop(L, lua_gettop(L) - originalStackSize);
    return result;
}

// Inputs

static int w_MouseMoved(lua_State *L)
{
	int x = (int)luaL_checknumber(L, 1);
	int y = (int)luaL_checknumber(L, 2);
	MouseMoved(x, y);
	return 0;
}

static int w_MousePressed(lua_State *L)
{
	int button = (int)luaL_checknumber(L, 1);
	MousePressed(button);
	return 0;
}

static int w_MouseReleased(lua_State *L)
{
	int button = (int)luaL_checknumber(L, 1);
	MouseReleased(button);
	return 0;
}

static int w_WheelMoved(lua_State *L)
{
	int y = (int)luaL_checknumber(L, 1);
	WheelMoved(y);
	return 0;
}

static int w_KeyPressed(lua_State *L)
{
	size_t size;
	const char *key = luaL_checklstring(L, 1, &size);
	KeyPressed(key);
	return 0;
}

static int w_KeyReleased(lua_State *L)
{
	size_t size;
	const char *key = luaL_checklstring(L, 1, &size);
	KeyReleased(key);
	return 0;
}

static int w_TextInput(lua_State *L)
{
	size_t size;
	const char *text = luaL_checklstring(L, 1, &size);
	TextInput(text);
	return 0;
}

static int w_GetWantCaptureMouse(lua_State *L)
{
	lua_pushboolean(L, GetWantCaptureMouse());
	return 1;
}

static int w_GetWantCaptureKeyboard(lua_State *L)
{
	lua_pushboolean(L, GetWantCaptureKeyboard());
	return 1;
}

static int w_GetWantTextInput(lua_State *L)
{
	lua_pushboolean(L, GetWantTextInput());
	return 1;
}

/*
** Custom bindings
*/

static int w_GetStyleColorName(lua_State *L)
{
	int idx = luaL_checkint(L, 1);
	lua_pushstring(L, ImGui::GetStyleColorName(idx - 1));
	return 1;
}

static int w_GetStyleColCount(lua_State *L)
{
	lua_pushinteger(L, ImGuiCol_COUNT);
	return 1;
}

static int w_SetGlobalFontFromFileTTF(lua_State *L)
{
	size_t size;
	const char *path = luaL_checklstring(L, 1, &size);
	float size_pixels = luaL_checknumber(L, 2);
	float spacing_x = luaL_optnumber(L, 3, 0);
	float spacing_y = luaL_optnumber(L, 4, 0);
	float oversample_x = luaL_optnumber(L, 5, 1);
	float oversample_y = luaL_optnumber(L, 6, 1);

	const char* basePath = getRealDirectoryIfExists(L, path);
	if (basePath == nullptr) {
		lua_pushstring(L, "File does not exist.");
		lua_error(L);
		return 0;
	}

	char fullPath[4096] = {0};
	snprintf(&(fullPath[0]), sizeof(fullPath) - 1, "%s/%s", basePath, path);
	SetGlobalFontFromFileTTF(&(fullPath[0]), size_pixels, spacing_x, spacing_y,
							oversample_x, oversample_y);
	lua_settop(L, 0);
	return 0;
}

static int w_AddFontFromFileTTF(lua_State *L) {
    size_t filenameSize;
    const char* filename = luaL_checklstring(L, 1, &filenameSize);
    float pixelSize = luaL_checknumber(L, 2);

    const char* basePath = getRealDirectoryIfExists(L, filename);
    if (basePath == nullptr) {
		lua_pushstring(L, "File does not exist.");
		lua_error(L);
		return 0;
    }

    char fullPath[4096] = {0};
    snprintf(&(fullPath[0]), sizeof(fullPath) - 1, "%s/%s", basePath, filename);

    ImFontConfig* fontCfg = (ImFontConfig*)lua_touserdata(L, 3);

    ImGuiIO& io = ImGui::GetIO();
    ImFont* font = io.Fonts->AddFontFromFileTTF(&(fullPath[0]), pixelSize);
    lua_settop(L, 0);

    if (font == nullptr) {
        return luaL_error(L, "Could not load font");
    } else {
        lua_pushlightuserdata(L, (void*)font);
        return 1;
    }
}

/*
** Hand made overrides
*/

/*
static int w_Value(lua_State *L)
{
	if (lua_isboolean(L, 2))
	{
		return impl_Value(L);
	}
	return impl_Value_4(L);
}

static int w_CollapsingHeader(lua_State *L)
{
	if (lua_isboolean(L, 2))
	{
		return impl_CollapsingHeader_2(L);
	}
	return impl_CollapsingHeader(L);
}

static int w_TreeNodeEx(lua_State *L)
{
	if (lua_gettop(L) > 2)
	{
		return impl_TreeNodeEx_2(L);
	}
	return impl_TreeNodeEx(L);
}

static int w_TreeNode(lua_State *L)
{
	if (lua_gettop(L) > 1)
	{
		return impl_TreeNode_2(L);
	}
	return impl_TreeNode(L);
}

static int w_Combo(lua_State *L)
{
	if (lua_isstring(L, 3))
	{
		return impl_Combo_2(L);
	}
	return impl_Combo(L);
}

static int w_RadioButton(lua_State *L)
{
	if (lua_gettop(L) > 2)
	{
		return impl_RadioButton_2(L);
	}
	return impl_RadioButton(L);
}

static int w_PushID(lua_State *L)
{
	if (lua_gettop(L) > 1)
	{
		return impl_PushID_2(L);
	}
	return impl_PushID(L);
}

static int w_GetID(lua_State *L)
{
	if (lua_gettop(L) > 1)
	{
		return impl_GetID_2(L);
	}
	return impl_GetID(L);
}

static int w_PushStyleVar(lua_State *L)
{
	if (lua_gettop(L) > 2)
	{
		return impl_PushStyleVar_2(L);
	}
	return impl_PushStyleVar(L);
}

static int w_PushStyleColor(lua_State *L)
{
	if (lua_gettop(L) > 2)
	{
		return impl_PushStyleColor_2(L);
	}
	return impl_PushStyleColor(L);
}

static int w_SetWindowPos(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_SetWindowPos_2(L);
	}
	return impl_SetWindowPos(L);
}

static int w_SetWindowSize(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_SetWindowSize_2(L);
	}
	return impl_SetWindowSize(L);
}

static int w_SetWindowCollapsed(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_SetWindowCollapsed_2(L);
	}
	return impl_SetWindowCollapsed(L);
}

static int w_SetWindowFocus(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_SetWindowFocus_2(L);
	}
	return impl_SetWindowFocus(L);
}

static int w_BeginChild(lua_State *L)
{
	if (lua_isstring(L, 1))
	{
		return impl_BeginChild(L);
	}
	return impl_BeginChild_2(L);
}
*/

/*
** Reg
*/

static const struct luaL_Reg imguilib[] = {
	// Custom
	{ "GetStyleColName", w_GetStyleColorName },
	{ "GetStyleColCount", w_GetStyleColCount },
	{ "SetGlobalFontFromFileTTF", w_SetGlobalFontFromFileTTF },
	{ "AddFontFromFileTTF", w_AddFontFromFileTTF },

	// Overrides
	//{ "Value", w_Value },
	//{ "CollapsingHeader", w_CollapsingHeader },
	//{ "Combo", w_Combo },
	//{ "RadioButton", w_RadioButton },
	//{ "PushID", w_PushID },
	//{ "GetID", w_GetID },
	//{ "PushStyleVar", w_PushStyleVar },
	//{ "PushStyleColor", w_PushStyleColor },
	//{ "SetWindowPos", w_SetWindowPos },
	//{ "SetWindowSize", w_SetWindowSize },
	//{ "SetWindowCollapsed", w_SetWindowCollapsed },
	//{ "SetWindowFocus", w_SetWindowFocus },
	//{ "BeginChild", w_BeginChild },

	// Implementation
	{ "ShutDown", w_ShutDown },
	{ "NewFrame", w_NewFrame },
	{ "Render", w_Render },
	{ "MouseMoved", w_MouseMoved },
	{ "MousePressed", w_MousePressed },
	{ "MouseReleased", w_MouseReleased },
	{ "WheelMoved", w_WheelMoved },
	{ "KeyPressed", w_KeyPressed },
	{ "KeyReleased", w_KeyReleased },
	{ "TextInput", w_TextInput },
	{ "GetWantCaptureKeyboard", w_GetWantCaptureKeyboard },
	{ "GetWantCaptureMouse", w_GetWantCaptureMouse },
	{ "GetWantTextInput", w_GetWantTextInput },

	{ NULL, NULL }
};

extern "C" {
	void luax_register(lua_State *L, const char *name, const luaL_Reg *l);
}

extern "C" int luaopen_imgui(lua_State *L)
{

	// Enums not handled by iterator yet
	lua_newtable(L);
	addImguiWrappers(L);


	luaL_openlib(L, "imgui", imguilib, 1);
	return 1;
}
