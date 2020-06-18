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

// override points
ImTextureID luax_checkTextureID(lua_State* L, int narg)
{
	lua_pushvalue(L, narg);
	// TODO: is this value a love texture?
	ptrdiff_t r = luaL_ref(L, LUA_REGISTRYINDEX);
	return reinterpret_cast<ImTextureID>(r);
}

/*
** Love implentation functions
*/
static bool g_inited = false;

static int w_ShutDown([[maybe_unused]] lua_State *L)
{
	ShutDown();
	return 0;
}

static int w_Init(lua_State *L)
{
	if (!g_inited)
	{
		Init(L);
		g_inited = true;
	}
	return 0;
}

static int w_Render([[maybe_unused]] lua_State *L)
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

static int w_SetGlobalFontFromFileTTF(lua_State *L)
{
	size_t size;
	const char *path = luaL_checklstring(L, 1, &size);
	float size_pixels  = static_cast<float>(luaL_checknumber(L, 2));
	float spacing_x    = static_cast<float>(luaL_optnumber(L, 3, 0));
	float spacing_y    = static_cast<float>(luaL_optnumber(L, 4, 0));
	float oversample_x = static_cast<float>(luaL_optnumber(L, 5, 1));
	float oversample_y = static_cast<float>(luaL_optnumber(L, 6, 1));

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
    float pixelSize = static_cast<float>(luaL_checknumber(L, 2));

    const char* basePath = getRealDirectoryIfExists(L, filename);
    if (basePath == nullptr) {
		lua_pushstring(L, "File does not exist.");
		lua_error(L);
		return 0;
    }

    char fullPath[4096] = {0};
    snprintf(&(fullPath[0]), sizeof(fullPath) - 1, "%s/%s", basePath, filename);

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
** Reg
*/

static const struct luaL_Reg imguilib[] = {
	// Custom
	{ "SetGlobalFontFromFileTTF", w_SetGlobalFontFromFileTTF },
	{ "AddFontFromFileTTF", w_AddFontFromFileTTF },

	// Implementation
	{ "ShutDown", w_ShutDown },
	{ "Init", w_Init },
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

extern "C" int luaopen_imgui(lua_State *L)
{
	lua_newtable(L);
	lua_pushvalue(L, -1);
	lua_setglobal(L, "imgui");
	wrap_imgui::addImguiWrappers(L);
	luaL_register(L, nullptr, imguilib);

	return 1;
}
