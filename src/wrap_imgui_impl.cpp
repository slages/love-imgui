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
#include "libimgui/imgui_dock.h"
#include "imgui_impl.h"
#include "wrap_imgui_impl.h"

#include <vector>
#include <cstring>

/*
** Love implentation functions
*/
static bool g_inited = false;
static int	g_textures[250]; // Should be enough
static bool	g_returnValueLast = true;

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

static int w_SetReturnValueLast(lua_State *L)
{
	g_returnValueLast = (bool)lua_toboolean(L, 1);
	return 0;
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

	lua_getglobal(L, "love");
	lua_getfield(L, -1, "filesystem");
	lua_remove(L, -2);
	lua_getfield(L, -1, "getRealDirectory");
	lua_remove(L, -2);
	lua_pushstring(L, path);
	lua_call(L, 1, 1);
	if (lua_isnil(L, -1))
	{
		lua_pushstring(L, "File does not exist.");
		lua_error(L);
		return 0;
	}
	lua_pushstring(L, "/");
	lua_pushstring(L, path);
	lua_concat(L, 3);
	const char *realpath = lua_tostring(L, -1);
	lua_pop(L, 1);

	SetGlobalFontFromFileTTF(realpath, size_pixels, spacing_x, spacing_y, oversample_x, oversample_y);
	return 0;
}

/*
** Wrapped functions
*/

#define IMGUI_FUNCTION(name) \
static int impl_##name(lua_State *L) { \
  int max_args = lua_gettop(L); \
  int arg = 1; \
  int stackval = 0;

#define TEXTURE_ARG(name) \
	lua_getglobal(L, "imgui"); \
	lua_pushvalue(L, arg++); \
	lua_setfield(L, -2, "textureID"); \
	luaL_dostring(L, "imgui.textures = imgui.textures or {}\
					  table.insert(imgui.textures, imgui.textureID)\
					  return #imgui.textures"); \
	lua_pop(L, 1); \
	int index = luaL_checkint(L, 0);\
	g_textures[index - 1] = index; \
	void *name = &g_textures[index - 1]; \

#define OPTIONAL_LABEL_ARG(name, value) \
  const char* name; \
  if (arg <= max_args) { \
    name = lua_tostring(L, arg++); \
          } else { \
    name = value; \
          }

#define LABEL_ARG(name) \
  size_t i_##name##_size; \
  const char * name = luaL_checklstring(L, arg++, &(i_##name##_size));

#define LABEL_POINTER_ARG(name) \
  size_t i_##name##_size; \
  const char * content = luaL_checklstring(L, arg++, &(i_##name##_size)); \
  size_t buf_size = luaL_checknumber(L, arg++); \
  char * name = new char [buf_size]; \
  std::strcpy(name, content);

#define END_LABEL_POINTER(name) \
  if (name != NULL) { \
    lua_pushstring(L, name); \
	delete[] name; \
    stackval++; \
        }

#define LABEL_ARRAY_ARG(name) \
  luaL_checktype(L, arg, LUA_TTABLE); \
  int len = lua_objlen(L, arg++); \
  std::vector<const char *> list; \
  for (int i = 0; i < len; i++) \
    { \
	lua_pushinteger(L, i + 1); \
	lua_gettable(L, arg - 1); \
	size_t current_size; \
	list.push_back(luaL_checklstring(L, -1, &(current_size))); \
    } \
  const char **name = list.data(); \

#define IM_VEC_2_ARG(name)\
  const lua_Number i_##name##_x = luaL_checknumber(L, arg++); \
  const lua_Number i_##name##_y = luaL_checknumber(L, arg++); \
  ImVec2 name((float)i_##name##_x, (float)i_##name##_y);

#define OPTIONAL_IM_VEC_2_ARG(name, x, y) \
  lua_Number i_##name##_x = x; \
  lua_Number i_##name##_y = y; \
  if (arg <= max_args - 1) { \
    i_##name##_x = luaL_checknumber(L, arg++); \
    i_##name##_y = luaL_checknumber(L, arg++); \
      } \
  const ImVec2 name((float)i_##name##_x, (float)i_##name##_y);

#define IM_VEC_4_ARG(name)\
  const lua_Number i_##name##_x = luaL_checknumber(L, arg++); \
  const lua_Number i_##name##_y = luaL_checknumber(L, arg++); \
  const lua_Number i_##name##_z = luaL_checknumber(L, arg++); \
  const lua_Number i_##name##_w = luaL_checknumber(L, arg++); \
  const ImVec4 name((float)i_##name##_x, (float)i_##name##_y, (float)i_##name##_z, (float)i_##name##_w);

#define OPTIONAL_IM_VEC_4_ARG(name, x, y, z, w) \
  lua_Number i_##name##_x = x; \
  lua_Number i_##name##_y = y; \
  lua_Number i_##name##_z = z; \
  lua_Number i_##name##_w = w; \
  if (arg <= max_args - 1) { \
    i_##name##_x = luaL_checknumber(L, arg++); \
    i_##name##_y = luaL_checknumber(L, arg++); \
    i_##name##_z = luaL_checknumber(L, arg++); \
    i_##name##_w = luaL_checknumber(L, arg++); \
        } \
  const ImVec4 name((float)i_##name##_x, (float)i_##name##_y, (float)i_##name##_z, (float)i_##name##_w);

#define NUMBER_ARG(name)\
  lua_Number name = luaL_checknumber(L, arg++);

#define OPTIONAL_NUMBER_ARG(name, otherwise)\
  lua_Number name = otherwise; \
  if (arg <= max_args) { \
    name = luaL_checknumber(L, arg++); \
      }

#define FLOAT_POINTER_ARG(name) \
  float i_##name##_value = (float)luaL_checknumber(L, arg++); \
  float* name = &(i_##name##_value);

#define END_FLOAT_POINTER(name) \
  if (name != NULL) { \
    lua_pushnumber(L, i_##name##_value); \
    stackval++; \
      }

#define FLOAT_ARRAY_ARG(name) \
  luaL_checktype(L, arg, LUA_TTABLE); \
  int len = lua_objlen(L, arg++); \
  std::vector<float> list; \
  for (int i = 0; i < len; i++) \
      { \
	lua_pushinteger(L, i + 1); \
	lua_gettable(L, arg - 1); \
	list.push_back(luaL_checknumber(L, -1)); \
      } \
  const float *name = list.data(); \

#define FLOAT_ARRAY2_ARG(name) \
  float i_##name##_1 = (float)luaL_checknumber(L, arg++); \
  float i_##name##_2 = (float)luaL_checknumber(L, arg++); \
  float name[2] = { i_##name##_1, i_##name##_2 };

#define END_FLOAT_ARRAY2(name) \
    lua_pushnumber(L, name[0]); \
    lua_pushnumber(L, name[1]); \
    stackval += 2; \

#define FLOAT_ARRAY3_ARG(name) \
  float i_##name##_1 = (float)luaL_checknumber(L, arg++); \
  float i_##name##_2 = (float)luaL_checknumber(L, arg++); \
  float i_##name##_3 = (float)luaL_checknumber(L, arg++); \
  float name[3] = { i_##name##_1, i_##name##_2, i_##name##_3 };

#define END_FLOAT_ARRAY3(name) \
    lua_pushnumber(L, name[0]); \
    lua_pushnumber(L, name[1]); \
    lua_pushnumber(L, name[2]); \
    stackval += 3; \

#define FLOAT_ARRAY4_ARG(name) \
  float i_##name##_1 = (float)luaL_checknumber(L, arg++); \
  float i_##name##_2 = (float)luaL_checknumber(L, arg++); \
  float i_##name##_3 = (float)luaL_checknumber(L, arg++); \
  float i_##name##_4 = (float)luaL_checknumber(L, arg++); \
  float name[4] = { i_##name##_1, i_##name##_2, i_##name##_3, i_##name##_4 };

#define END_FLOAT_ARRAY4(name) \
    lua_pushnumber(L, name[0]); \
    lua_pushnumber(L, name[1]); \
    lua_pushnumber(L, name[2]); \
    lua_pushnumber(L, name[3]); \
    stackval += 4; \

#define INT_ARRAY2_ARG(name) \
  int i_##name##_1 = (int)luaL_checkinteger(L, arg++); \
  int i_##name##_2 = (int)luaL_checkinteger(L, arg++); \
  int name[2] = { i_##name##_1, i_##name##_2 };

#define END_INT_ARRAY2(name) \
    lua_pushnumber(L, name[0]); \
    lua_pushnumber(L, name[1]); \
    stackval += 2; \

#define INT_ARRAY3_ARG(name) \
  int i_##name##_1 = (int)luaL_checkinteger(L, arg++); \
  int i_##name##_2 = (int)luaL_checkinteger(L, arg++); \
  int i_##name##_3 = (int)luaL_checkinteger(L, arg++); \
  int name[3] = { i_##name##_1, i_##name##_2, i_##name##_3 };

#define END_INT_ARRAY3(name) \
    lua_pushnumber(L, name[0]); \
    lua_pushnumber(L, name[1]); \
    lua_pushnumber(L, name[2]); \
    stackval += 3; \

#define INT_ARRAY4_ARG(name) \
  int i_##name##_1 = (int)luaL_checkinteger(L, arg++); \
  int i_##name##_2 = (int)luaL_checkinteger(L, arg++); \
  int i_##name##_3 = (int)luaL_checkinteger(L, arg++); \
  int i_##name##_4 = (int)luaL_checkinteger(L, arg++); \
  int name[4] = { i_##name##_1, i_##name##_2, i_##name##_3, i_##name##_4 };

#define END_INT_ARRAY4(name) \
    lua_pushnumber(L, name[0]); \
    lua_pushnumber(L, name[1]); \
    lua_pushnumber(L, name[2]); \
    lua_pushnumber(L, name[3]); \
    stackval += 4; \

#define OPTIONAL_INT_ARG(name, otherwise)\
  int name = otherwise; \
  if (arg <= max_args) { \
    name = (int)luaL_checkinteger(L, arg++); \
      }

#define INT_ARG(name) \
  const int name = (int)luaL_checkinteger(L, arg++);

#define OPTIONAL_ENUM_ARG(name, otherwise)\
  int name = otherwise; \
  if (arg <= max_args) { \
	if (lua_istable(L, arg++)) { \
		int len = lua_objlen(L, -1); \
		for (int i = 0; i < len; i++) { \
			lua_pushinteger(L, i + 1); \
			lua_gettable(L, arg - 1); \
			lua_pushvalue(L, -1); \
			lua_gettable(L, lua_upvalueindex(1)); \
			name = name | (int)lua_tonumber(L, -1); \
			lua_pop(L, 1); \
				} \
		} else { \
		lua_pushvalue(L, arg - 1); \
		lua_gettable(L, lua_upvalueindex(1)); \
		name = (int)lua_tonumber(L, -1); \
		lua_pop(L, 1); \
			} \
      }

#define ENUM_ARG(name) \
	int name = 0; \
	if (lua_istable(L, arg++)) { \
		int len = lua_objlen(L, -1); \
		for (int i = 0; i < len; i++) { \
			lua_pushinteger(L, i + 1); \
			lua_gettable(L, arg - 1); \
			lua_pushvalue(L, -1); \
			lua_gettable(L, lua_upvalueindex(1)); \
			name = name | (int)lua_tonumber(L, -1); \
			lua_pop(L, 1); \
				} \
		} else { \
		lua_pushvalue(L, arg - 1); \
		lua_gettable(L, lua_upvalueindex(1)); \
		name = (int)lua_tonumber(L, -1); \
		lua_pop(L, 1); \
		}

#define OPTIONAL_UINT_ARG(name, otherwise)\
  unsigned int name = otherwise; \
  if (arg <= max_args) { \
    name = (unsigned int)luaL_checkint(L, arg++); \
      }

#define UINT_ARG(name) \
  const unsigned int name = (unsigned int)luaL_checkinteger(L, arg++);

#define INT_POINTER_ARG(name) \
  int i_##name##_value = (int)luaL_checkinteger(L, arg++); \
  int* name = &(i_##name##_value);

#define END_INT_POINTER(name) \
  if (name != NULL) { \
    lua_pushnumber(L, i_##name##_value); \
    stackval++; \
      }

#define INT_CURRENT_ITEM_POINTER_ARG(name) \
  int i_##name##_value = (int)luaL_checkinteger(L, arg++) - 1; \
  int* name = &(i_##name##_value);

#define END_INT_CURRENT_ITEM_POINTER(name) \
  if (name != NULL) { \
    lua_pushnumber(L, i_##name##_value + 1); \
    stackval++; \
        }

#define UINT_POINTER_ARG(name) \
  unsigned int i_##name##_value = (unsigned int)luaL_checkinteger(L, arg++); \
  unsigned int* name = &(i_##name##_value);

#define END_UINT_POINTER(name) \
  if (name != NULL) { \
    lua_pushnumber(L, i_##name##_value); \
    stackval++; \
      }

#define BOOL_POINTER_ARG(name) \
  bool i_##name##_value = (bool)lua_toboolean(L, arg++); \
  bool* name = &(i_##name##_value);

#define OPTIONAL_BOOL_POINTER_ARG(name) \
  bool i_##name##_value; \
  bool* name = NULL; \
  if (arg <= max_args) { \
	if (lua_isboolean(L, arg++)) \
			{ \
			i_##name##_value = (bool)lua_toboolean(L, arg - 1); \
			name = &(i_##name##_value); \
		} \
      }

#define OPTIONAL_BOOL_ARG(name, otherwise) \
  bool name = otherwise; \
  if (arg <= max_args) { \
    name = (bool)lua_toboolean(L, arg++); \
      }

#define DEFAULT_ARG(type, name, value) \
  type name = value; \

#define BOOL_ARG(name) \
  bool name = (bool)lua_toboolean(L, arg++);

#define CALL_FUNCTION(name, retType,...) \
  retType ret = ImGui::name(__VA_ARGS__);

#define CALL_FUNCTION_NO_RET(name, ...) \
  ImGui::name(__VA_ARGS__);

#define PUSH_NUMBER(name) \
  if (!g_returnValueLast) { \
    lua_pushnumber(L, name); \
    stackval++; \
      }

#define PUSH_STRING(name) \
  if (!g_returnValueLast) { \
    lua_pushstring(L, name); \
    stackval++; \
      }

#define PUSH_BOOL(name) \
  if (!g_returnValueLast) { \
    lua_pushboolean(L, (int) name); \
    stackval++; \
      }

#define PUSH_LAST_NUMBER(name) \
  if (g_returnValueLast) { \
    lua_pushnumber(L, name); \
    stackval++; \
      }

#define PUSH_LAST_STRING(name) \
  if (g_returnValueLast) { \
    lua_pushstring(L, name); \
    stackval++; \
      }

#define PUSH_LAST_BOOL(name) \
  if (g_returnValueLast) { \
    lua_pushboolean(L, (int) name); \
    stackval++; \
      }

#define END_BOOL_POINTER(name) \
  if (name != NULL) { \
    lua_pushboolean(L, (int)i_##name##_value); \
    stackval++; \
      }

#define END_IMGUI_FUNC \
  return stackval; \
}

#ifdef ENABLE_IM_LUA_END_STACK
#define IF_RET_ADD_END_STACK(type) \
  if (ret) { \
    AddToStack(type); \
      }

#define ADD_END_STACK(type) \
  AddToStack(type);

#define POP_END_STACK(type) \
  PopEndStack(type);

#define END_STACK_START \
static void ImEndStack(int type) { \
  switch(type) {

#define END_STACK_OPTION(type, function) \
    case type: \
      ImGui::function(); \
      break;

#define END_STACK_END \
    } \
}
#else
#define END_STACK_START
#define END_STACK_OPTION(type, function)
#define END_STACK_END
#define IF_RET_ADD_END_STACK(type)
#define ADD_END_STACK(type)
#define POP_END_STACK(type)
#endif

#include "imgui_iterator.h"
#include "imgui_iterator_dock.h"

/*
** Hand made overrides
*/

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

/*
** Reg
*/

static const struct luaL_Reg imguilib[] = {
#undef IMGUI_FUNCTION
#define IMGUI_FUNCTION(name) {#name, impl_##name},
	// These defines are just redefining everything to nothing so
	// we can get the function names
#undef DEFAULT_ARG
#define DEFAULT_ARG(type, name, value)
#undef TEXTURE_ARG
#define TEXTURE_ARG(name)
#undef OPTIONAL_LABEL_ARG
#define OPTIONAL_LABEL_ARG(name, value)
#undef LABEL_ARG
#define LABEL_ARG(name)
#undef LABEL_POINTER_ARG
#define LABEL_POINTER_ARG(name)
#undef END_LABEL_POINTER
#define END_LABEL_POINTER(name)
#undef LABEL_ARRAY_ARG
#define LABEL_ARRAY_ARG(name)
#undef IM_VEC_2_ARG
#define IM_VEC_2_ARG(name)
#undef OPTIONAL_IM_VEC_2_ARG
#define OPTIONAL_IM_VEC_2_ARG(name, x, y)
#undef IM_VEC_4_ARG
#define IM_VEC_4_ARG(name)
#undef OPTIONAL_IM_VEC_4_ARG
#define OPTIONAL_IM_VEC_4_ARG(name, x, y, z, w)
#undef NUMBER_ARG
#define NUMBER_ARG(name)
#undef OPTIONAL_NUMBER_ARG
#define OPTIONAL_NUMBER_ARG(name, otherwise)
#undef FLOAT_POINTER_ARG
#define FLOAT_POINTER_ARG(name)
#undef END_FLOAT_POINTER
#define END_FLOAT_POINTER(name)
#undef FLOAT_ARRAY_ARG
#define FLOAT_ARRAY_ARG(name)
#undef FLOAT_ARRAY2_ARG
#define FLOAT_ARRAY2_ARG(name)
#undef END_FLOAT_ARRAY2
#define END_FLOAT_ARRAY2(name)
#undef FLOAT_ARRAY3_ARG
#define FLOAT_ARRAY3_ARG(name)
#undef END_FLOAT_ARRAY3
#define END_FLOAT_ARRAY3(name)
#undef FLOAT_ARRAY4_ARG
#define FLOAT_ARRAY4_ARG(name)
#undef END_FLOAT_ARRAY4
#define END_FLOAT_ARRAY4(name)
#undef INT_ARRAY2_ARG
#define INT_ARRAY2_ARG(name)
#undef END_INT_ARRAY2
#define END_INT_ARRAY2(name)
#undef INT_ARRAY3_ARG
#define INT_ARRAY3_ARG(name)
#undef END_INT_ARRAY3
#define END_INT_ARRAY3(name)
#undef INT_ARRAY4_ARG
#define INT_ARRAY4_ARG(name)
#undef END_INT_ARRAY4
#define END_INT_ARRAY4(name)
#undef OPTIONAL_INT_ARG
#define OPTIONAL_INT_ARG(name, otherwise)
#undef INT_ARG
#define INT_ARG(name)
#undef OPTIONAL_ENUM_ARG
#define OPTIONAL_ENUM_ARG(name, otherwise)
#undef ENUM_ARG
#define ENUM_ARG(name)
#undef OPTIONAL_UINT_ARG
#define OPTIONAL_UINT_ARG(name, otherwise)
#undef UINT_ARG
#define UINT_ARG(name)
#undef INT_POINTER_ARG
#define INT_POINTER_ARG(name)
#undef END_INT_POINTER
#define END_INT_POINTER(name)
#undef INT_CURRENT_ITEM_POINTER_ARG
#define INT_CURRENT_ITEM_POINTER_ARG(name)
#undef END_INT_CURRENT_ITEM_POINTER
#define END_INT_CURRENT_ITEM_POINTER(name)
#undef UINT_POINTER_ARG
#define UINT_POINTER_ARG(name)
#undef END_UINT_POINTER
#define END_UINT_POINTER(name)
#undef BOOL_POINTER_ARG
#define BOOL_POINTER_ARG(name)
#undef OPTIONAL_BOOL_POINTER_ARG
#define OPTIONAL_BOOL_POINTER_ARG(name)
#undef OPTIONAL_BOOL_ARG
#define OPTIONAL_BOOL_ARG(name, otherwise)
#undef BOOL_ARG
#define BOOL_ARG(name)
#undef CALL_FUNCTION
#define CALL_FUNCTION(name, retType, ...)
#undef CALL_FUNCTION_NO_RET
#define CALL_FUNCTION_NO_RET(name, ...)
#undef PUSH_NUMBER
#define PUSH_NUMBER(name)
#undef PUSH_BOOL
#define PUSH_BOOL(name)
#undef PUSH_STRING
#define PUSH_STRING(name)
#undef PUSH_LAST_NUMBER
#define PUSH_LAST_NUMBER(name)
#undef PUSH_LAST_BOOL
#define PUSH_LAST_BOOL(name)
#undef PUSH_LAST_STRING
#define PUSH_LAST_STRING(name)
#undef END_BOOL_POINTER
#define END_BOOL_POINTER(name)
#undef END_IMGUI_FUNC
#define END_IMGUI_FUNC
#undef END_STACK_START
#define END_STACK_START
#undef END_STACK_OPTION
#define END_STACK_OPTION(type, function)
#undef END_STACK_END
#define END_STACK_END
#undef IF_RET_ADD_END_STACK
#define IF_RET_ADD_END_STACK(type)
#undef ADD_END_STACK
#define ADD_END_STACK(type)
#undef POP_END_STACK
#define POP_END_STACK(type)

#include "imgui_iterator.h"
#include "imgui_iterator_dock.h"

	// Custom
{ "GetStyleColName", w_GetStyleColorName },
{ "GetStyleColCount", w_GetStyleColCount },
{ "SetGlobalFontFromFileTTF", w_SetGlobalFontFromFileTTF },

// Overrides
{ "Value", w_Value },
{ "CollapsingHeader", w_CollapsingHeader },
{ "Combo", w_Combo },
{ "RadioButton", w_RadioButton },
{ "PushID", w_PushID },
{ "GetID", w_GetID },
{ "PushStyleVar", w_PushStyleVar },
{ "PushStyleColor", w_PushStyleColor },
{ "SetWindowPos", w_SetWindowPos },
{ "SetWindowSize", w_SetWindowSize },
{ "SetWindowCollapsed", w_SetWindowCollapsed },
{ "SetWindowFocus", w_SetWindowFocus },
{ "BeginChild", w_BeginChild },

// Implementation
{ "ShutDown", w_ShutDown },
{ "NewFrame", w_NewFrame },
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

// Return value ordering
{ "SetReturnValueLast", w_SetReturnValueLast },

{ NULL, NULL }
};

extern "C" {
	void luax_register(lua_State *L, const char *name, const luaL_Reg *l);
}

#define WRAP_ENUM(L, name, val) \
  lua_pushlstring(L, #name, sizeof(#name)-1); \
  lua_pushnumber(L, val); \
  lua_settable(L, -3);

extern "C" LOVE_IMGUI_EXPORT int luaopen_imgui(lua_State *L)
{
	// Enums not handled by iterator yet
	lua_newtable(L);

	// ImGuiWindowFlags, prefer using the ImGuiXXX_ version instead of the short version as it's deprecated and will be removed
	WRAP_ENUM(L, NoTitleBar, ImGuiWindowFlags_NoTitleBar);
	WRAP_ENUM(L, NoResize, ImGuiWindowFlags_NoResize);
	WRAP_ENUM(L, NoMove, ImGuiWindowFlags_NoMove);
	WRAP_ENUM(L, NoScrollbar, ImGuiWindowFlags_NoScrollbar);
	WRAP_ENUM(L, NoScrollWithMouse, ImGuiWindowFlags_NoScrollWithMouse);
	WRAP_ENUM(L, NoCollapse, ImGuiWindowFlags_NoCollapse);
	WRAP_ENUM(L, AlwaysAutoResize, ImGuiWindowFlags_AlwaysAutoResize);
	WRAP_ENUM(L, NoSavedSettings, ImGuiWindowFlags_NoSavedSettings);
	WRAP_ENUM(L, NoInputs, ImGuiWindowFlags_NoInputs);
	WRAP_ENUM(L, MenuBar, ImGuiWindowFlags_MenuBar);
	WRAP_ENUM(L, HorizontalScrollbar, ImGuiWindowFlags_HorizontalScrollbar);
	WRAP_ENUM(L, NoFocusOnAppearing, ImGuiWindowFlags_NoFocusOnAppearing);
	WRAP_ENUM(L, NoBringToFrontOnFocus, ImGuiWindowFlags_NoBringToFrontOnFocus);
	WRAP_ENUM(L, AlwaysVerticalScrollbar, ImGuiWindowFlags_AlwaysVerticalScrollbar);
	WRAP_ENUM(L, AlwaysHorizontalScrollbar, ImGuiWindowFlags_AlwaysHorizontalScrollbar);
	WRAP_ENUM(L, AlwaysUseWindowPadding, ImGuiWindowFlags_AlwaysUseWindowPadding);
	WRAP_ENUM(L, ResizeFromAnySide, ImGuiWindowFlags_ResizeFromAnySide);

	WRAP_ENUM(L, ImGuiWindowFlags_NoTitleBar, ImGuiWindowFlags_NoTitleBar);
	WRAP_ENUM(L, ImGuiWindowFlags_NoResize, ImGuiWindowFlags_NoResize);
	WRAP_ENUM(L, ImGuiWindowFlags_NoMove, ImGuiWindowFlags_NoMove);
	WRAP_ENUM(L, ImGuiWindowFlags_NoScrollbar, ImGuiWindowFlags_NoScrollbar);
	WRAP_ENUM(L, ImGuiWindowFlags_NoScrollWithMouse, ImGuiWindowFlags_NoScrollWithMouse);
	WRAP_ENUM(L, ImGuiWindowFlags_NoCollapse, ImGuiWindowFlags_NoCollapse);
	WRAP_ENUM(L, ImGuiWindowFlags_AlwaysAutoResize, ImGuiWindowFlags_AlwaysAutoResize);
	WRAP_ENUM(L, ImGuiWindowFlags_NoSavedSettings, ImGuiWindowFlags_NoSavedSettings);
	WRAP_ENUM(L, ImGuiWindowFlags_NoInputs, ImGuiWindowFlags_NoInputs);
	WRAP_ENUM(L, ImGuiWindowFlags_MenuBar, ImGuiWindowFlags_MenuBar);
	WRAP_ENUM(L, ImGuiWindowFlags_HorizontalScrollbar, ImGuiWindowFlags_HorizontalScrollbar);
	WRAP_ENUM(L, ImGuiWindowFlags_NoFocusOnAppearing, ImGuiWindowFlags_NoFocusOnAppearing);
	WRAP_ENUM(L, ImGuiWindowFlags_NoBringToFrontOnFocus, ImGuiWindowFlags_NoBringToFrontOnFocus);
	WRAP_ENUM(L, ImGuiWindowFlags_AlwaysVerticalScrollbar, ImGuiWindowFlags_AlwaysVerticalScrollbar);
	WRAP_ENUM(L, ImGuiWindowFlags_AlwaysHorizontalScrollbar, ImGuiWindowFlags_AlwaysHorizontalScrollbar);
	WRAP_ENUM(L, ImGuiWindowFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_AlwaysUseWindowPadding);
	WRAP_ENUM(L, ImGuiWindowFlags_ResizeFromAnySide, ImGuiWindowFlags_ResizeFromAnySide);

	// ImGuiInputTextFlags
	WRAP_ENUM(L, CharsDecimal, ImGuiInputTextFlags_CharsDecimal);
	WRAP_ENUM(L, CharsHexadecimal, ImGuiInputTextFlags_CharsHexadecimal);
	WRAP_ENUM(L, CharsUppercase, ImGuiInputTextFlags_CharsUppercase);
	WRAP_ENUM(L, CharsNoBlank, ImGuiInputTextFlags_CharsNoBlank);
	WRAP_ENUM(L, AutoSelectAll, ImGuiInputTextFlags_AutoSelectAll);
	WRAP_ENUM(L, EnterReturnsTrue, ImGuiInputTextFlags_EnterReturnsTrue);
	WRAP_ENUM(L, CallbackCompletion, ImGuiInputTextFlags_CallbackCompletion);
	WRAP_ENUM(L, CallbackHistory, ImGuiInputTextFlags_CallbackHistory);
	WRAP_ENUM(L, CallbackAlways, ImGuiInputTextFlags_CallbackAlways);
	WRAP_ENUM(L, CallbackCharFilter, ImGuiInputTextFlags_CallbackCharFilter);
	WRAP_ENUM(L, AllowTabInput, ImGuiInputTextFlags_AllowTabInput);
	WRAP_ENUM(L, CtrlEnterForNewLine, ImGuiInputTextFlags_CtrlEnterForNewLine);
	WRAP_ENUM(L, NoHorizontalScroll, ImGuiInputTextFlags_NoHorizontalScroll);
	WRAP_ENUM(L, AlwaysInsertMode, ImGuiInputTextFlags_AlwaysInsertMode);
	WRAP_ENUM(L, ReadOnly, ImGuiInputTextFlags_ReadOnly);
	WRAP_ENUM(L, Password, ImGuiInputTextFlags_Password);
	WRAP_ENUM(L, NoUndoRedo, ImGuiInputTextFlags_NoUndoRedo);

	WRAP_ENUM(L, ImGuiInputTextFlags_CharsDecimal, ImGuiInputTextFlags_CharsDecimal);
	WRAP_ENUM(L, ImGuiInputTextFlags_CharsHexadecimal, ImGuiInputTextFlags_CharsHexadecimal);
	WRAP_ENUM(L, ImGuiInputTextFlags_CharsUppercase, ImGuiInputTextFlags_CharsUppercase);
	WRAP_ENUM(L, ImGuiInputTextFlags_CharsNoBlank, ImGuiInputTextFlags_CharsNoBlank);
	WRAP_ENUM(L, ImGuiInputTextFlags_AutoSelectAll, ImGuiInputTextFlags_AutoSelectAll);
	WRAP_ENUM(L, ImGuiInputTextFlags_EnterReturnsTrue, ImGuiInputTextFlags_EnterReturnsTrue);
	WRAP_ENUM(L, ImGuiInputTextFlags_CallbackCompletion, ImGuiInputTextFlags_CallbackCompletion);
	WRAP_ENUM(L, ImGuiInputTextFlags_CallbackHistory, ImGuiInputTextFlags_CallbackHistory);
	WRAP_ENUM(L, ImGuiInputTextFlags_CallbackAlways, ImGuiInputTextFlags_CallbackAlways);
	WRAP_ENUM(L, ImGuiInputTextFlags_CallbackCharFilter, ImGuiInputTextFlags_CallbackCharFilter);
	WRAP_ENUM(L, ImGuiInputTextFlags_AllowTabInput, ImGuiInputTextFlags_AllowTabInput);
	WRAP_ENUM(L, ImGuiInputTextFlags_CtrlEnterForNewLine, ImGuiInputTextFlags_CtrlEnterForNewLine);
	WRAP_ENUM(L, ImGuiInputTextFlags_NoHorizontalScroll, ImGuiInputTextFlags_NoHorizontalScroll);
	WRAP_ENUM(L, ImGuiInputTextFlags_AlwaysInsertMode, ImGuiInputTextFlags_AlwaysInsertMode);
	WRAP_ENUM(L, ImGuiInputTextFlags_ReadOnly, ImGuiInputTextFlags_ReadOnly);
	WRAP_ENUM(L, ImGuiInputTextFlags_Password, ImGuiInputTextFlags_Password);
	WRAP_ENUM(L, ImGuiInputTextFlags_NoUndoRedo, ImGuiInputTextFlags_NoUndoRedo);

	// ImGuiTreeNodeFlags
	WRAP_ENUM(L, Selected, ImGuiTreeNodeFlags_Selected);
	WRAP_ENUM(L, Framed, ImGuiTreeNodeFlags_Framed);
	WRAP_ENUM(L, AllowItemOverlap, ImGuiTreeNodeFlags_AllowItemOverlap);
	WRAP_ENUM(L, NoTreePushOnOpen, ImGuiTreeNodeFlags_NoTreePushOnOpen);
	WRAP_ENUM(L, NoAutoOpenOnLog, ImGuiTreeNodeFlags_NoAutoOpenOnLog);
	WRAP_ENUM(L, DefaultOpen, ImGuiTreeNodeFlags_DefaultOpen);
	WRAP_ENUM(L, OpenOnDoubleClick, ImGuiTreeNodeFlags_OpenOnDoubleClick);
	WRAP_ENUM(L, OpenOnArrow, ImGuiTreeNodeFlags_OpenOnArrow);
	WRAP_ENUM(L, Leaf, ImGuiTreeNodeFlags_Leaf);
	WRAP_ENUM(L, Bullet, ImGuiTreeNodeFlags_Bullet);
	WRAP_ENUM(L, FramePadding, ImGuiTreeNodeFlags_FramePadding);
	WRAP_ENUM(L, CollapsingHeader, ImGuiTreeNodeFlags_CollapsingHeader);

	WRAP_ENUM(L, ImGuiTreeNodeFlags_Selected, ImGuiTreeNodeFlags_Selected);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_Framed, ImGuiTreeNodeFlags_Framed);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_AllowItemOverlap, ImGuiTreeNodeFlags_AllowItemOverlap);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_NoTreePushOnOpen, ImGuiTreeNodeFlags_NoTreePushOnOpen);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_NoAutoOpenOnLog, ImGuiTreeNodeFlags_NoAutoOpenOnLog);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_DefaultOpen, ImGuiTreeNodeFlags_DefaultOpen);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_OpenOnDoubleClick, ImGuiTreeNodeFlags_OpenOnDoubleClick);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_OpenOnArrow, ImGuiTreeNodeFlags_OpenOnArrow);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_Leaf, ImGuiTreeNodeFlags_Leaf);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_Bullet, ImGuiTreeNodeFlags_Bullet);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_FramePadding, ImGuiTreeNodeFlags_FramePadding);
	WRAP_ENUM(L, ImGuiTreeNodeFlags_CollapsingHeader, ImGuiTreeNodeFlags_CollapsingHeader);

	// ImGuiSelectableFlags
	WRAP_ENUM(L, DontClosePopups, ImGuiSelectableFlags_DontClosePopups);
	WRAP_ENUM(L, SpanAllColumns, ImGuiSelectableFlags_SpanAllColumns);
	WRAP_ENUM(L, AllowDoubleClick, ImGuiSelectableFlags_AllowDoubleClick);

	WRAP_ENUM(L, ImGuiSelectableFlags_DontClosePopups, ImGuiSelectableFlags_DontClosePopups);
	WRAP_ENUM(L, ImGuiSelectableFlags_SpanAllColumns, ImGuiSelectableFlags_SpanAllColumns);
	WRAP_ENUM(L, ImGuiSelectableFlags_AllowDoubleClick, ImGuiSelectableFlags_AllowDoubleClick);

	// ImGuiComboFlags
	WRAP_ENUM(L, PopupAlignLeft, ImGuiComboFlags_PopupAlignLeft);
	WRAP_ENUM(L, HeightSmall, ImGuiComboFlags_HeightSmall);
	WRAP_ENUM(L, HeightRegular, ImGuiComboFlags_HeightRegular);
	WRAP_ENUM(L, HeightLarge, ImGuiComboFlags_HeightLarge);
	WRAP_ENUM(L, HeightLargest, ImGuiComboFlags_HeightLargest);
	WRAP_ENUM(L, HeightMask_, ImGuiComboFlags_HeightMask_);

	WRAP_ENUM(L, ImGuiComboFlags_PopupAlignLeft, ImGuiComboFlags_PopupAlignLeft);
	WRAP_ENUM(L, ImGuiComboFlags_HeightSmall, ImGuiComboFlags_HeightSmall);
	WRAP_ENUM(L, ImGuiComboFlags_HeightRegular, ImGuiComboFlags_HeightRegular);
	WRAP_ENUM(L, ImGuiComboFlags_HeightLarge, ImGuiComboFlags_HeightLarge);
	WRAP_ENUM(L, ImGuiComboFlags_HeightLargest, ImGuiComboFlags_HeightLargest);
	WRAP_ENUM(L, ImGuiComboFlags_HeightMask_, ImGuiComboFlags_HeightMask_);

	// ImGuiFocusedFlags
	WRAP_ENUM(L, ImGuiFocusedFlags_ChildWindows, ImGuiFocusedFlags_ChildWindows);
	WRAP_ENUM(L, ImGuiFocusedFlags_RootWindow, ImGuiFocusedFlags_RootWindow);
	WRAP_ENUM(L, ImGuiFocusedFlags_RootAndChildWindows, ImGuiFocusedFlags_RootAndChildWindows);

	// ImGuiHoveredFlags
	WRAP_ENUM(L, ImGuiHoveredFlags_Default, ImGuiHoveredFlags_Default);
	WRAP_ENUM(L, ImGuiHoveredFlags_ChildWindows, ImGuiHoveredFlags_ChildWindows);
	WRAP_ENUM(L, ImGuiHoveredFlags_RootWindow, ImGuiHoveredFlags_RootWindow);
	WRAP_ENUM(L, ImGuiHoveredFlags_AllowWhenBlockedByPopup, ImGuiHoveredFlags_AllowWhenBlockedByPopup);
	WRAP_ENUM(L, ImGuiHoveredFlags_AllowWhenBlockedByActiveItem, ImGuiHoveredFlags_AllowWhenBlockedByActiveItem);
	WRAP_ENUM(L, ImGuiHoveredFlags_AllowWhenOverlapped, ImGuiHoveredFlags_AllowWhenOverlapped);
	WRAP_ENUM(L, ImGuiHoveredFlags_RectOnly, ImGuiHoveredFlags_RectOnly);
	WRAP_ENUM(L, ImGuiHoveredFlags_RootAndChildWindows, ImGuiHoveredFlags_RootAndChildWindows);

	// ImGuiDragDropFlags_
	WRAP_ENUM(L, SourceNoPreviewTooltip, ImGuiDragDropFlags_SourceNoPreviewTooltip);
	WRAP_ENUM(L, SourceNoDisableHover, ImGuiDragDropFlags_SourceNoDisableHover);
	WRAP_ENUM(L, SourceNoHoldToOpenOthers, ImGuiDragDropFlags_SourceNoHoldToOpenOthers);
	WRAP_ENUM(L, SourceAllowNullID, ImGuiDragDropFlags_SourceAllowNullID);
	WRAP_ENUM(L, SourceExtern, ImGuiDragDropFlags_SourceExtern);
	WRAP_ENUM(L, AcceptBeforeDelivery, ImGuiDragDropFlags_AcceptBeforeDelivery);
	WRAP_ENUM(L, AcceptNoDrawDefaultRect, ImGuiDragDropFlags_AcceptNoDrawDefaultRect);
	WRAP_ENUM(L, AcceptPeekOnly, ImGuiDragDropFlags_AcceptPeekOnly);

	WRAP_ENUM(L, ImGuiDragDropFlags_SourceNoPreviewTooltip, ImGuiDragDropFlags_SourceNoPreviewTooltip);
	WRAP_ENUM(L, ImGuiDragDropFlags_SourceNoDisableHover, ImGuiDragDropFlags_SourceNoDisableHover);
	WRAP_ENUM(L, ImGuiDragDropFlags_SourceNoHoldToOpenOthers, ImGuiDragDropFlags_SourceNoHoldToOpenOthers);
	WRAP_ENUM(L, ImGuiDragDropFlags_SourceAllowNullID, ImGuiDragDropFlags_SourceAllowNullID);
	WRAP_ENUM(L, ImGuiDragDropFlags_SourceExtern, ImGuiDragDropFlags_SourceExtern);
	WRAP_ENUM(L, ImGuiDragDropFlags_AcceptBeforeDelivery, ImGuiDragDropFlags_AcceptBeforeDelivery);
	WRAP_ENUM(L, ImGuiDragDropFlags_AcceptNoDrawDefaultRect, ImGuiDragDropFlags_AcceptNoDrawDefaultRect);
	WRAP_ENUM(L, ImGuiDragDropFlags_AcceptPeekOnly, ImGuiDragDropFlags_AcceptPeekOnly);

	// ImGuiCol
	WRAP_ENUM(L, Text, ImGuiCol_Text);
	WRAP_ENUM(L, TextDisabled, ImGuiCol_TextDisabled);
	WRAP_ENUM(L, WindowBg, ImGuiCol_WindowBg);
	WRAP_ENUM(L, ChildBg, ImGuiCol_ChildBg);
	WRAP_ENUM(L, PopupBg, ImGuiCol_PopupBg);
	WRAP_ENUM(L, Border, ImGuiCol_Border);
	WRAP_ENUM(L, BorderShadow, ImGuiCol_BorderShadow);
	WRAP_ENUM(L, FrameBg, ImGuiCol_FrameBg);
	WRAP_ENUM(L, FrameBgHovered, ImGuiCol_FrameBgHovered);
	WRAP_ENUM(L, FrameBgActive, ImGuiCol_FrameBgActive);
	WRAP_ENUM(L, TitleBg, ImGuiCol_TitleBg);
	WRAP_ENUM(L, TitleBgActive, ImGuiCol_TitleBgActive);
	WRAP_ENUM(L, TitleBgCollapsed, ImGuiCol_TitleBgCollapsed);
	WRAP_ENUM(L, MenuBarBg, ImGuiCol_MenuBarBg);
	WRAP_ENUM(L, ScrollbarBg, ImGuiCol_ScrollbarBg);
	WRAP_ENUM(L, ScrollbarGrab, ImGuiCol_ScrollbarGrab);
	WRAP_ENUM(L, ScrollbarGrabHovered, ImGuiCol_ScrollbarGrabHovered);
	WRAP_ENUM(L, ScrollbarGrabActive, ImGuiCol_ScrollbarGrabActive);
	WRAP_ENUM(L, CheckMark, ImGuiCol_CheckMark);
	WRAP_ENUM(L, SliderGrab, ImGuiCol_SliderGrab);
	WRAP_ENUM(L, SliderGrabActive, ImGuiCol_SliderGrabActive);
	WRAP_ENUM(L, Button, ImGuiCol_Button);
	WRAP_ENUM(L, ButtonHovered, ImGuiCol_ButtonHovered);
	WRAP_ENUM(L, ButtonActive, ImGuiCol_ButtonActive);
	WRAP_ENUM(L, Header, ImGuiCol_Header);
	WRAP_ENUM(L, HeaderHovered, ImGuiCol_HeaderHovered);
	WRAP_ENUM(L, HeaderActive, ImGuiCol_HeaderActive);
	WRAP_ENUM(L, Separator, ImGuiCol_Separator);
	WRAP_ENUM(L, SeparatorHovered, ImGuiCol_SeparatorHovered);
	WRAP_ENUM(L, SeparatorActive, ImGuiCol_SeparatorActive);
	WRAP_ENUM(L, ResizeGrip, ImGuiCol_ResizeGrip);
	WRAP_ENUM(L, ResizeGripHovered, ImGuiCol_ResizeGripHovered);
	WRAP_ENUM(L, ResizeGripActive, ImGuiCol_ResizeGripActive);
	WRAP_ENUM(L, CloseButton, ImGuiCol_CloseButton);
	WRAP_ENUM(L, CloseButtonHovered, ImGuiCol_CloseButtonHovered);
	WRAP_ENUM(L, CloseButtonActive, ImGuiCol_CloseButtonActive);
	WRAP_ENUM(L, PlotLines, ImGuiCol_PlotLines);
	WRAP_ENUM(L, PlotLinesHovered, ImGuiCol_PlotLinesHovered);
	WRAP_ENUM(L, PlotHistogram, ImGuiCol_PlotHistogram);
	WRAP_ENUM(L, PlotHistogramHovered, ImGuiCol_PlotHistogramHovered);
	WRAP_ENUM(L, TextSelectedBg, ImGuiCol_TextSelectedBg);
	WRAP_ENUM(L, ModalWindowDarkening, ImGuiCol_ModalWindowDarkening);
	WRAP_ENUM(L, DragDropTarget, ImGuiCol_DragDropTarget);

	WRAP_ENUM(L, ImGuiCol_Text, ImGuiCol_Text);
	WRAP_ENUM(L, ImGuiCol_TextDisabled, ImGuiCol_TextDisabled);
	WRAP_ENUM(L, ImGuiCol_WindowBg, ImGuiCol_WindowBg);
	WRAP_ENUM(L, ImGuiCol_ChildBg, ImGuiCol_ChildBg);
	WRAP_ENUM(L, ImGuiCol_PopupBg, ImGuiCol_PopupBg);
	WRAP_ENUM(L, ImGuiCol_Border, ImGuiCol_Border);
	WRAP_ENUM(L, ImGuiCol_BorderShadow, ImGuiCol_BorderShadow);
	WRAP_ENUM(L, ImGuiCol_FrameBg, ImGuiCol_FrameBg);
	WRAP_ENUM(L, ImGuiCol_FrameBgHovered, ImGuiCol_FrameBgHovered);
	WRAP_ENUM(L, ImGuiCol_FrameBgActive, ImGuiCol_FrameBgActive);
	WRAP_ENUM(L, ImGuiCol_TitleBg, ImGuiCol_TitleBg);
	WRAP_ENUM(L, ImGuiCol_TitleBgActive, ImGuiCol_TitleBgActive);
	WRAP_ENUM(L, ImGuiCol_TitleBgCollapsed, ImGuiCol_TitleBgCollapsed);
	WRAP_ENUM(L, ImGuiCol_MenuBarBg, ImGuiCol_MenuBarBg);
	WRAP_ENUM(L, ImGuiCol_ScrollbarBg, ImGuiCol_ScrollbarBg);
	WRAP_ENUM(L, ImGuiCol_ScrollbarGrab, ImGuiCol_ScrollbarGrab);
	WRAP_ENUM(L, ImGuiCol_ScrollbarGrabHovered, ImGuiCol_ScrollbarGrabHovered);
	WRAP_ENUM(L, ImGuiCol_ScrollbarGrabActive, ImGuiCol_ScrollbarGrabActive);
	WRAP_ENUM(L, ImGuiCol_CheckMark, ImGuiCol_CheckMark);
	WRAP_ENUM(L, ImGuiCol_SliderGrab, ImGuiCol_SliderGrab);
	WRAP_ENUM(L, ImGuiCol_SliderGrabActive, ImGuiCol_SliderGrabActive);
	WRAP_ENUM(L, ImGuiCol_Button, ImGuiCol_Button);
	WRAP_ENUM(L, ImGuiCol_ButtonHovered, ImGuiCol_ButtonHovered);
	WRAP_ENUM(L, ImGuiCol_ButtonActive, ImGuiCol_ButtonActive);
	WRAP_ENUM(L, ImGuiCol_Header, ImGuiCol_Header);
	WRAP_ENUM(L, ImGuiCol_HeaderHovered, ImGuiCol_HeaderHovered);
	WRAP_ENUM(L, ImGuiCol_HeaderActive, ImGuiCol_HeaderActive);
	WRAP_ENUM(L, ImGuiCol_Separator, ImGuiCol_Separator);
	WRAP_ENUM(L, ImGuiCol_SeparatorHovered, ImGuiCol_SeparatorHovered);
	WRAP_ENUM(L, ImGuiCol_SeparatorActive, ImGuiCol_SeparatorActive);
	WRAP_ENUM(L, ImGuiCol_ResizeGrip, ImGuiCol_ResizeGrip);
	WRAP_ENUM(L, ImGuiCol_ResizeGripHovered, ImGuiCol_ResizeGripHovered);
	WRAP_ENUM(L, ImGuiCol_ResizeGripActive, ImGuiCol_ResizeGripActive);
	WRAP_ENUM(L, ImGuiCol_CloseButton, ImGuiCol_CloseButton);
	WRAP_ENUM(L, ImGuiCol_CloseButtonHovered, ImGuiCol_CloseButtonHovered);
	WRAP_ENUM(L, ImGuiCol_CloseButtonActive, ImGuiCol_CloseButtonActive);
	WRAP_ENUM(L, ImGuiCol_PlotLines, ImGuiCol_PlotLines);
	WRAP_ENUM(L, ImGuiCol_PlotLinesHovered, ImGuiCol_PlotLinesHovered);
	WRAP_ENUM(L, ImGuiCol_PlotHistogram, ImGuiCol_PlotHistogram);
	WRAP_ENUM(L, ImGuiCol_PlotHistogramHovered, ImGuiCol_PlotHistogramHovered);
	WRAP_ENUM(L, ImGuiCol_TextSelectedBg, ImGuiCol_TextSelectedBg);
	WRAP_ENUM(L, ImGuiCol_ModalWindowDarkening, ImGuiCol_ModalWindowDarkening);
	WRAP_ENUM(L, ImGuiCol_DragDropTarget, ImGuiCol_DragDropTarget);

	// ImGuiStyleVar
	WRAP_ENUM(L, Alpha, ImGuiStyleVar_Alpha);
	WRAP_ENUM(L, WindowPadding, ImGuiStyleVar_WindowPadding);
	WRAP_ENUM(L, WindowRounding, ImGuiStyleVar_WindowRounding);
	WRAP_ENUM(L, WindowBorderSize, ImGuiStyleVar_WindowBorderSize);
	WRAP_ENUM(L, WindowMinSize, ImGuiStyleVar_WindowMinSize);
	WRAP_ENUM(L, ChildRounding, ImGuiStyleVar_ChildRounding);
	WRAP_ENUM(L, ChildBorderSize, ImGuiStyleVar_ChildBorderSize);
	WRAP_ENUM(L, PopupRounding, ImGuiStyleVar_PopupRounding);
	WRAP_ENUM(L, PopupBorderSize, ImGuiStyleVar_PopupBorderSize);
	WRAP_ENUM(L, FramePadding, ImGuiStyleVar_FramePadding);
	WRAP_ENUM(L, FrameRounding, ImGuiStyleVar_FrameRounding);
	WRAP_ENUM(L, FrameBorderSize, ImGuiStyleVar_FrameBorderSize);
	WRAP_ENUM(L, ItemSpacing, ImGuiStyleVar_ItemSpacing);
	WRAP_ENUM(L, ItemInnerSpacing, ImGuiStyleVar_ItemInnerSpacing);
	WRAP_ENUM(L, IndentSpacing, ImGuiStyleVar_IndentSpacing);
	WRAP_ENUM(L, GrabMinSize, ImGuiStyleVar_GrabMinSize);
	WRAP_ENUM(L, ButtonTextAlign, ImGuiStyleVar_ButtonTextAlign);

	WRAP_ENUM(L, ImGuiStyleVar_Alpha, ImGuiStyleVar_Alpha);
	WRAP_ENUM(L, ImGuiStyleVar_WindowPadding, ImGuiStyleVar_WindowPadding);
	WRAP_ENUM(L, ImGuiStyleVar_WindowRounding, ImGuiStyleVar_WindowRounding);
	WRAP_ENUM(L, ImGuiStyleVar_WindowBorderSize, ImGuiStyleVar_WindowBorderSize);
	WRAP_ENUM(L, ImGuiStyleVar_WindowMinSize, ImGuiStyleVar_WindowMinSize);
	WRAP_ENUM(L, ImGuiStyleVar_ChildRounding, ImGuiStyleVar_ChildRounding);
	WRAP_ENUM(L, ImGuiStyleVar_ChildBorderSize, ImGuiStyleVar_ChildBorderSize);
	WRAP_ENUM(L, ImGuiStyleVar_PopupRounding, ImGuiStyleVar_PopupRounding);
	WRAP_ENUM(L, ImGuiStyleVar_PopupBorderSize, ImGuiStyleVar_PopupBorderSize);
	WRAP_ENUM(L, ImGuiStyleVar_FramePadding, ImGuiStyleVar_FramePadding);
	WRAP_ENUM(L, ImGuiStyleVar_FrameRounding, ImGuiStyleVar_FrameRounding);
	WRAP_ENUM(L, ImGuiStyleVar_FrameBorderSize, ImGuiStyleVar_FrameBorderSize);
	WRAP_ENUM(L, ImGuiStyleVar_ItemSpacing, ImGuiStyleVar_ItemSpacing);
	WRAP_ENUM(L, ImGuiStyleVar_ItemInnerSpacing, ImGuiStyleVar_ItemInnerSpacing);
	WRAP_ENUM(L, ImGuiStyleVar_IndentSpacing, ImGuiStyleVar_IndentSpacing);
	WRAP_ENUM(L, ImGuiStyleVar_GrabMinSize, ImGuiStyleVar_GrabMinSize);
	WRAP_ENUM(L, ImGuiStyleVar_ButtonTextAlign, ImGuiStyleVar_ButtonTextAlign);

	// ImGuiColorEditFlags
	WRAP_ENUM(L, NoAlpha, ImGuiColorEditFlags_NoAlpha);
	WRAP_ENUM(L, NoPicker, ImGuiColorEditFlags_NoPicker);
	WRAP_ENUM(L, NoOptions, ImGuiColorEditFlags_NoOptions);
	WRAP_ENUM(L, NoSmallPreview, ImGuiColorEditFlags_NoSmallPreview);
	WRAP_ENUM(L, NoInputs, ImGuiColorEditFlags_NoInputs);
	WRAP_ENUM(L, NoTooltip, ImGuiColorEditFlags_NoTooltip);
	WRAP_ENUM(L, NoLabel, ImGuiColorEditFlags_NoLabel);
	WRAP_ENUM(L, NoSidePreview, ImGuiColorEditFlags_NoSidePreview);
	WRAP_ENUM(L, AlphaBar, ImGuiColorEditFlags_AlphaBar);
	WRAP_ENUM(L, AlphaPreview, ImGuiColorEditFlags_AlphaPreview);
	WRAP_ENUM(L, AlphaPreviewHalf, ImGuiColorEditFlags_AlphaPreviewHalf);
	WRAP_ENUM(L, HDR, ImGuiColorEditFlags_HDR);
	WRAP_ENUM(L, RGB, ImGuiColorEditFlags_RGB);
	WRAP_ENUM(L, HSV, ImGuiColorEditFlags_HSV);
	WRAP_ENUM(L, HEX, ImGuiColorEditFlags_HEX);
	WRAP_ENUM(L, Uint8, ImGuiColorEditFlags_Uint8);
	WRAP_ENUM(L, Float, ImGuiColorEditFlags_Float);
	WRAP_ENUM(L, PickerHueBar, ImGuiColorEditFlags_PickerHueBar);
	WRAP_ENUM(L, PickerHueWheel, ImGuiColorEditFlags_PickerHueWheel);

	WRAP_ENUM(L, ImGuiColorEditFlags_NoAlpha, ImGuiColorEditFlags_NoAlpha);
	WRAP_ENUM(L, ImGuiColorEditFlags_NoPicker, ImGuiColorEditFlags_NoPicker);
	WRAP_ENUM(L, ImGuiColorEditFlags_NoOptions, ImGuiColorEditFlags_NoOptions);
	WRAP_ENUM(L, ImGuiColorEditFlags_NoSmallPreview, ImGuiColorEditFlags_NoSmallPreview);
	WRAP_ENUM(L, ImGuiColorEditFlags_NoInputs, ImGuiColorEditFlags_NoInputs);
	WRAP_ENUM(L, ImGuiColorEditFlags_NoTooltip, ImGuiColorEditFlags_NoTooltip);
	WRAP_ENUM(L, ImGuiColorEditFlags_NoLabel, ImGuiColorEditFlags_NoLabel);
	WRAP_ENUM(L, ImGuiColorEditFlags_NoSidePreview, ImGuiColorEditFlags_NoSidePreview);
	WRAP_ENUM(L, ImGuiColorEditFlags_AlphaBar, ImGuiColorEditFlags_AlphaBar);
	WRAP_ENUM(L, ImGuiColorEditFlags_AlphaPreview, ImGuiColorEditFlags_AlphaPreview);
	WRAP_ENUM(L, ImGuiColorEditFlags_AlphaPreviewHalf, ImGuiColorEditFlags_AlphaPreviewHalf);
	WRAP_ENUM(L, ImGuiColorEditFlags_HDR, ImGuiColorEditFlags_HDR);
	WRAP_ENUM(L, ImGuiColorEditFlags_RGB, ImGuiColorEditFlags_RGB);
	WRAP_ENUM(L, ImGuiColorEditFlags_HSV, ImGuiColorEditFlags_HSV);
	WRAP_ENUM(L, ImGuiColorEditFlags_HEX, ImGuiColorEditFlags_HEX);
	WRAP_ENUM(L, ImGuiColorEditFlags_Uint8, ImGuiColorEditFlags_Uint8);
	WRAP_ENUM(L, ImGuiColorEditFlags_Float, ImGuiColorEditFlags_Float);
	WRAP_ENUM(L, ImGuiColorEditFlags_PickerHueBar, ImGuiColorEditFlags_PickerHueBar);
	WRAP_ENUM(L, ImGuiColorEditFlags_PickerHueWheel, ImGuiColorEditFlags_PickerHueWheel);

	// ImGuiMouseCursor
	WRAP_ENUM(L, None, ImGuiMouseCursor_None);
	WRAP_ENUM(L, Arrow, ImGuiMouseCursor_Arrow);
	WRAP_ENUM(L, TextInput, ImGuiMouseCursor_TextInput);
	WRAP_ENUM(L, Move, ImGuiMouseCursor_Move);
	WRAP_ENUM(L, ResizeNS, ImGuiMouseCursor_ResizeNS);
	WRAP_ENUM(L, ResizeEW, ImGuiMouseCursor_ResizeEW);
	WRAP_ENUM(L, ResizeNESW, ImGuiMouseCursor_ResizeNESW);
	WRAP_ENUM(L, ResizeNWSE, ImGuiMouseCursor_ResizeNWSE);

	WRAP_ENUM(L, ImGuiMouseCursor_None, ImGuiMouseCursor_None);
	WRAP_ENUM(L, ImGuiMouseCursor_Arrow, ImGuiMouseCursor_Arrow);
	WRAP_ENUM(L, ImGuiMouseCursor_TextInput, ImGuiMouseCursor_TextInput);
	WRAP_ENUM(L, ImGuiMouseCursor_Move, ImGuiMouseCursor_Move);
	WRAP_ENUM(L, ImGuiMouseCursor_ResizeNS, ImGuiMouseCursor_ResizeNS);
	WRAP_ENUM(L, ImGuiMouseCursor_ResizeEW, ImGuiMouseCursor_ResizeEW);
	WRAP_ENUM(L, ImGuiMouseCursor_ResizeNESW, ImGuiMouseCursor_ResizeNESW);
	WRAP_ENUM(L, ImGuiMouseCursor_ResizeNWSE, ImGuiMouseCursor_ResizeNWSE);

	// ImGuiCond
	WRAP_ENUM(L, Always, ImGuiCond_Always);
	WRAP_ENUM(L, Once, ImGuiCond_Once);
	WRAP_ENUM(L, FirstUseEver, ImGuiCond_FirstUseEver);
	WRAP_ENUM(L, Appearing, ImGuiCond_Appearing);

	WRAP_ENUM(L, ImGuiCond_Always, ImGuiCond_Always);
	WRAP_ENUM(L, ImGuiCond_Once, ImGuiCond_Once);
	WRAP_ENUM(L, ImGuiCond_FirstUseEver, ImGuiCond_FirstUseEver);
	WRAP_ENUM(L, ImGuiCond_Appearing, ImGuiCond_Appearing);

	// Docks
	WRAP_ENUM(L, ImGuiDockSlot_Left, ImGuiDockSlot_Left);
	WRAP_ENUM(L, ImGuiDockSlot_Right, ImGuiDockSlot_Right);
	WRAP_ENUM(L, ImGuiDockSlot_Top, ImGuiDockSlot_Top);
	WRAP_ENUM(L, ImGuiDockSlot_Bottom, ImGuiDockSlot_Bottom);
	WRAP_ENUM(L, ImGuiDockSlot_Tab, ImGuiDockSlot_Tab);
	WRAP_ENUM(L, ImGuiDockSlot_Float, ImGuiDockSlot_Float);
	WRAP_ENUM(L, ImGuiDockSlot_None, ImGuiDockSlot_None);

	luaL_openlib(L, "imgui", imguilib, 1);
	return 1;
}
