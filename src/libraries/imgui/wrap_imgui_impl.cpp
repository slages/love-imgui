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

#include "imgui/imgui_impl.h"
#include "imgui/libimgui/imgui.h"
#include "imgui/wrap_imgui_impl.h"


/*
** Love implentation functions
*/

static int w_ShutDown(lua_State *L)
{
	ShutDown();
	return 0;
}

static int w_NewFrame(lua_State *L)
{
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

/*
** Wrapped functions
*/

#include <vector>
#include <cstring>

#define IMGUI_FUNCTION(name) \
static int impl_##name(lua_State *L) { \
  int max_args = lua_gettop(L); \
  int arg = 1; \
  int stackval = 0;

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
  const ImVec2 name((float)i_##name##_x, (float)i_##name##_y);

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
    name = lua_tonumber(L, arg++); \
    }

#define FLOAT_POINTER_ARG(name) \
  float i_##name##_value = (float)luaL_checknumber(L, arg++); \
  float* name = &(i_##name##_value);

#define END_FLOAT_POINTER(name) \
  if (name != NULL) { \
    lua_pushnumber(L, i_##name##_value); \
    stackval++; \
    }

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
  int i_##name##_1 = (float)luaL_checknumber(L, arg++); \
  int i_##name##_2 = (float)luaL_checknumber(L, arg++); \
  int name[2] = { i_##name##_1, i_##name##_2 };

#define END_INT_ARRAY2(name) \
    lua_pushnumber(L, name[0]); \
    lua_pushnumber(L, name[1]); \
    stackval += 2; \

#define INT_ARRAY3_ARG(name) \
  int i_##name##_1 = (int)luaL_checknumber(L, arg++); \
  int i_##name##_2 = (int)luaL_checknumber(L, arg++); \
  int i_##name##_3 = (int)luaL_checknumber(L, arg++); \
  int name[3] = { i_##name##_1, i_##name##_2, i_##name##_3 };

#define END_INT_ARRAY3(name) \
    lua_pushnumber(L, name[0]); \
    lua_pushnumber(L, name[1]); \
    lua_pushnumber(L, name[2]); \
    stackval += 3; \

#define INT_ARRAY4_ARG(name) \
  int i_##name##_1 = (int)luaL_checknumber(L, arg++); \
  int i_##name##_2 = (int)luaL_checknumber(L, arg++); \
  int i_##name##_3 = (int)luaL_checknumber(L, arg++); \
  int i_##name##_4 = (int)luaL_checknumber(L, arg++); \
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
    name = (int)lua_tonumber(L, arg++); \
    }

#define INT_ARG(name) \
  const int name = (int)luaL_checknumber(L, arg++);

#define OPTIONAL_UINT_ARG(name, otherwise)\
  unsigned int name = otherwise; \
  if (arg <= max_args) { \
    name = (unsigned int)lua_tounsigned(L, arg++); \
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
			i_##name##_value = (bool)lua_toboolean(L, -1); \
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
  lua_pushnumber(L, name); \
  stackval++;

#define PUSH_BOOL(name) \
  lua_pushboolean(L, (int) name); \
  stackval++;

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

#include "imgui/imgui_iterator.cpp"


static const struct luaL_Reg imguilib[] = {
#undef IMGUI_FUNCTION
#define IMGUI_FUNCTION(name) {#name, impl_##name},
	// These defines are just redefining everything to nothing so
	// we can get the function names
#undef DEFAULT_ARG
#define DEFAULT_ARG(type, name, value)
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

#include "imgui/imgui_iterator.cpp"
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
  { NULL, NULL }
};

extern "C" {
	void luax_register(lua_State *L, const char *name, const luaL_Reg *l);
}

extern "C" int luaopen_imgui(lua_State *L)
{
	luax_register(L, "imgui", imguilib);

	// Enums not handled by iterator yet
	lua_pushnumber(L, ImGuiWindowFlags_NoTitleBar);
	lua_setglobal(L, "ImGuiWindowFlags_NoTitleBar");
	lua_pushnumber(L, ImGuiWindowFlags_NoResize);
	lua_setglobal(L, "ImGuiWindowFlags_NoResize");
	lua_pushnumber(L, ImGuiWindowFlags_NoMove);
	lua_setglobal(L, "ImGuiWindowFlags_NoMove");
	lua_pushnumber(L, ImGuiWindowFlags_NoScrollbar);
	lua_setglobal(L, "ImGuiWindowFlags_NoScrollbar");
	lua_pushnumber(L, ImGuiWindowFlags_NoScrollWithMouse);
	lua_setglobal(L, "ImGuiWindowFlags_NoScrollWithMouse");
	lua_pushnumber(L, ImGuiWindowFlags_NoCollapse);
	lua_setglobal(L, "ImGuiWindowFlags_NoCollapse");
	lua_pushnumber(L, ImGuiWindowFlags_AlwaysAutoResize);
	lua_setglobal(L, "ImGuiWindowFlags_AlwaysAutoResize");
	lua_pushnumber(L, ImGuiWindowFlags_ShowBorders);
	lua_setglobal(L, "ImGuiWindowFlags_ShowBorders");
	lua_pushnumber(L, ImGuiWindowFlags_NoSavedSettings);
	lua_setglobal(L, "ImGuiWindowFlags_NoSavedSettings");
	lua_pushnumber(L, ImGuiWindowFlags_NoInputs);
	lua_setglobal(L, "ImGuiWindowFlags_NoInputs");
	lua_pushnumber(L, ImGuiWindowFlags_MenuBar);
	lua_setglobal(L, "ImGuiWindowFlags_MenuBar");
	lua_pushnumber(L, ImGuiWindowFlags_HorizontalScrollbar);
	lua_setglobal(L, "ImGuiWindowFlags_HorizontalScrollbar");
	lua_pushnumber(L, ImGuiWindowFlags_NoFocusOnAppearing);
	lua_setglobal(L, "ImGuiWindowFlags_NoFocusOnAppearing");
	lua_pushnumber(L, ImGuiWindowFlags_NoBringToFrontOnFocus);
	lua_setglobal(L, "ImGuiWindowFlags_NoBringToFrontOnFocus");
	lua_pushnumber(L, ImGuiWindowFlags_ChildWindow);
	lua_setglobal(L, "ImGuiWindowFlags_ChildWindow");
	lua_pushnumber(L, ImGuiWindowFlags_ChildWindowAutoFitX);
	lua_setglobal(L, "ImGuiWindowFlags_ChildWindowAutoFitX");
	lua_pushnumber(L, ImGuiWindowFlags_ChildWindowAutoFitY);
	lua_setglobal(L, "ImGuiWindowFlags_ChildWindowAutoFitY");
	lua_pushnumber(L, ImGuiWindowFlags_ComboBox);
	lua_setglobal(L, "ImGuiWindowFlags_ComboBox");
	lua_pushnumber(L, ImGuiWindowFlags_Tooltip);
	lua_setglobal(L, "ImGuiWindowFlags_Tooltip");
	lua_pushnumber(L, ImGuiWindowFlags_Popup);
	lua_setglobal(L, "ImGuiWindowFlags_Popup");
	lua_pushnumber(L, ImGuiWindowFlags_Modal);
	lua_setglobal(L, "ImGuiWindowFlags_Modal");
	lua_pushnumber(L, ImGuiWindowFlags_ChildMenu);
	lua_setglobal(L, "ImGuiWindowFlags_ChildMenu");
	lua_pushnumber(L, ImGuiInputTextFlags_CharsDecimal);
	lua_setglobal(L, "ImGuiInputTextFlags_CharsDecimal");
	lua_pushnumber(L, ImGuiInputTextFlags_CharsHexadecimal);
	lua_setglobal(L, "ImGuiInputTextFlags_CharsHexadecimal");
	lua_pushnumber(L, ImGuiInputTextFlags_CharsUppercase);
	lua_setglobal(L, "ImGuiInputTextFlags_CharsUppercase");
	lua_pushnumber(L, ImGuiInputTextFlags_CharsNoBlank);
	lua_setglobal(L, "ImGuiInputTextFlags_CharsNoBlank");
	lua_pushnumber(L, ImGuiInputTextFlags_AutoSelectAll);
	lua_setglobal(L, "ImGuiInputTextFlags_AutoSelectAll");
	lua_pushnumber(L, ImGuiInputTextFlags_EnterReturnsTrue);
	lua_setglobal(L, "ImGuiInputTextFlags_EnterReturnsTrue");
	lua_pushnumber(L, ImGuiInputTextFlags_CallbackCompletion);
	lua_setglobal(L, "ImGuiInputTextFlags_CallbackCompletion");
	lua_pushnumber(L, ImGuiInputTextFlags_CallbackHistory);
	lua_setglobal(L, "ImGuiInputTextFlags_CallbackHistory");
	lua_pushnumber(L, ImGuiInputTextFlags_CallbackAlways);
	lua_setglobal(L, "ImGuiInputTextFlags_CallbackAlways");
	lua_pushnumber(L, ImGuiInputTextFlags_CallbackCharFilter);
	lua_setglobal(L, "ImGuiInputTextFlags_CallbackCharFilter");
	lua_pushnumber(L, ImGuiInputTextFlags_AllowTabInput);
	lua_setglobal(L, "ImGuiInputTextFlags_AllowTabInput");
	lua_pushnumber(L, ImGuiInputTextFlags_CtrlEnterForNewLine);
	lua_setglobal(L, "ImGuiInputTextFlags_CtrlEnterForNewLine");
	lua_pushnumber(L, ImGuiInputTextFlags_NoHorizontalScroll);
	lua_setglobal(L, "ImGuiInputTextFlags_NoHorizontalScroll");
	lua_pushnumber(L, ImGuiInputTextFlags_AlwaysInsertMode);
	lua_setglobal(L, "ImGuiInputTextFlags_AlwaysInsertMode");
	lua_pushnumber(L, ImGuiInputTextFlags_ReadOnly);
	lua_setglobal(L, "ImGuiInputTextFlags_ReadOnly");
	lua_pushnumber(L, ImGuiInputTextFlags_Password);
	lua_setglobal(L, "ImGuiInputTextFlags_Password");
	lua_pushnumber(L, ImGuiInputTextFlags_Multiline);
	lua_setglobal(L, "ImGuiInputTextFlags_Multiline");
	lua_pushnumber(L, ImGuiSelectableFlags_DontClosePopups);
	lua_setglobal(L, "ImGuiSelectableFlags_DontClosePopups");
	lua_pushnumber(L, ImGuiSelectableFlags_SpanAllColumns);
	lua_setglobal(L, "ImGuiSelectableFlags_SpanAllColumns");
	lua_pushnumber(L, ImGuiKey_Tab);
	lua_setglobal(L, "ImGuiKey_Tab");
	lua_pushnumber(L, ImGuiKey_LeftArrow);
	lua_setglobal(L, "ImGuiKey_LeftArrow");
	lua_pushnumber(L, ImGuiKey_RightArrow);
	lua_setglobal(L, "ImGuiKey_RightArrow");
	lua_pushnumber(L, ImGuiKey_UpArrow);
	lua_setglobal(L, "ImGuiKey_UpArrow");
	lua_pushnumber(L, ImGuiKey_DownArrow);
	lua_setglobal(L, "ImGuiKey_DownArrow");
	lua_pushnumber(L, ImGuiKey_PageUp);
	lua_setglobal(L, "ImGuiKey_PageUp");
	lua_pushnumber(L, ImGuiKey_PageDown);
	lua_setglobal(L, "ImGuiKey_PageDown");
	lua_pushnumber(L, ImGuiKey_Home);
	lua_setglobal(L, "ImGuiKey_Home");
	lua_pushnumber(L, ImGuiSetCond_Always);
	lua_setglobal(L, "ImGuiSetCond_Always");
	lua_pushnumber(L, ImGuiSetCond_Once);
	lua_setglobal(L, "ImGuiSetCond_Once");
	lua_pushnumber(L, ImGuiSetCond_FirstUseEver);
	lua_setglobal(L, "ImGuiSetCond_FirstUseEver");
	lua_pushnumber(L, ImGuiSetCond_Appearing);
	lua_setglobal(L, "ImGuiSetCond_Appearing");
	lua_pushnumber(L, ImGuiCol_Text);
	lua_setglobal(L, "ImGuiCol_Text");
	lua_pushnumber(L, ImGuiCol_TextDisabled);
	lua_setglobal(L, "ImGuiCol_TextDisabled");
	lua_pushnumber(L, ImGuiCol_WindowBg);
	lua_setglobal(L, "ImGuiCol_WindowBg");
	lua_pushnumber(L, ImGuiCol_ChildWindowBg);
	lua_setglobal(L, "ImGuiCol_ChildWindowBg");
	lua_pushnumber(L, ImGuiCol_PopupBg);
	lua_setglobal(L, "ImGuiCol_PopupBg");
	lua_pushnumber(L, ImGuiCol_Border);
	lua_setglobal(L, "ImGuiCol_Border");
	lua_pushnumber(L, ImGuiCol_BorderShadow);
	lua_setglobal(L, "ImGuiCol_BorderShadow");
	lua_pushnumber(L, ImGuiCol_FrameBg);
	lua_setglobal(L, "ImGuiCol_FrameBg");
	lua_pushnumber(L, ImGuiCol_FrameBgHovered);
	lua_setglobal(L, "ImGuiCol_FrameBgHovered");
	lua_pushnumber(L, ImGuiCol_FrameBgActive);
	lua_setglobal(L, "ImGuiCol_FrameBgActive");
	lua_pushnumber(L, ImGuiCol_TitleBg);
	lua_setglobal(L, "ImGuiCol_TitleBg");
	lua_pushnumber(L, ImGuiCol_TitleBgCollapsed);
	lua_setglobal(L, "ImGuiCol_TitleBgCollapsed");
	lua_pushnumber(L, ImGuiCol_TitleBgActive);
	lua_setglobal(L, "ImGuiCol_TitleBgActive");
	lua_pushnumber(L, ImGuiCol_MenuBarBg);
	lua_setglobal(L, "ImGuiCol_MenuBarBg");
	lua_pushnumber(L, ImGuiCol_ScrollbarBg);
	lua_setglobal(L, "ImGuiCol_ScrollbarBg");
	lua_pushnumber(L, ImGuiCol_ScrollbarGrab);
	lua_setglobal(L, "ImGuiCol_ScrollbarGrab");
	lua_pushnumber(L, ImGuiCol_ScrollbarGrabHovered);
	lua_setglobal(L, "ImGuiCol_ScrollbarGrabHovered");
	lua_pushnumber(L, ImGuiCol_ScrollbarGrabActive);
	lua_setglobal(L, "ImGuiCol_ScrollbarGrabActive");
	lua_pushnumber(L, ImGuiCol_ComboBg);
	lua_setglobal(L, "ImGuiCol_ComboBg");
	lua_pushnumber(L, ImGuiCol_CheckMark);
	lua_setglobal(L, "ImGuiCol_CheckMark");
	lua_pushnumber(L, ImGuiCol_SliderGrab);
	lua_setglobal(L, "ImGuiCol_SliderGrab");
	lua_pushnumber(L, ImGuiCol_SliderGrabActive);
	lua_setglobal(L, "ImGuiCol_SliderGrabActive");
	lua_pushnumber(L, ImGuiCol_Button);
	lua_setglobal(L, "ImGuiCol_Button");
	lua_pushnumber(L, ImGuiCol_ButtonHovered);
	lua_setglobal(L, "ImGuiCol_ButtonHovered");
	lua_pushnumber(L, ImGuiCol_ButtonActive);
	lua_setglobal(L, "ImGuiCol_ButtonActive");
	lua_pushnumber(L, ImGuiCol_Header);
	lua_setglobal(L, "ImGuiCol_Header");
	lua_pushnumber(L, ImGuiCol_HeaderHovered);
	lua_setglobal(L, "ImGuiCol_HeaderHovered");
	lua_pushnumber(L, ImGuiCol_HeaderActive);
	lua_setglobal(L, "ImGuiCol_HeaderActive");
	lua_pushnumber(L, ImGuiCol_Column);
	lua_setglobal(L, "ImGuiCol_Column");
	lua_pushnumber(L, ImGuiCol_ColumnHovered);
	lua_setglobal(L, "ImGuiCol_ColumnHovered");
	lua_pushnumber(L, ImGuiCol_ColumnActive);
	lua_setglobal(L, "ImGuiCol_ColumnActive");
	lua_pushnumber(L, ImGuiCol_ResizeGrip);
	lua_setglobal(L, "ImGuiCol_ResizeGrip");
	lua_pushnumber(L, ImGuiCol_ResizeGripHovered);
	lua_setglobal(L, "ImGuiCol_ResizeGripHovered");
	lua_pushnumber(L, ImGuiCol_ResizeGripActive);
	lua_setglobal(L, "ImGuiCol_ResizeGripActive");
	lua_pushnumber(L, ImGuiCol_CloseButton);
	lua_setglobal(L, "ImGuiCol_CloseButton");
	lua_pushnumber(L, ImGuiCol_CloseButtonHovered);
	lua_setglobal(L, "ImGuiCol_CloseButtonHovered");
	lua_pushnumber(L, ImGuiCol_CloseButtonActive);
	lua_setglobal(L, "ImGuiCol_CloseButtonActive");
	lua_pushnumber(L, ImGuiCol_PlotLines);
	lua_setglobal(L, "ImGuiCol_PlotLines");
	lua_pushnumber(L, ImGuiCol_PlotLinesHovered);
	lua_setglobal(L, "ImGuiCol_PlotLinesHovered");
	lua_pushnumber(L, ImGuiCol_PlotHistogram);
	lua_setglobal(L, "ImGuiCol_PlotHistogram");
	lua_pushnumber(L, ImGuiCol_PlotHistogramHovered);
	lua_setglobal(L, "ImGuiCol_PlotHistogramHovered");
	lua_pushnumber(L, ImGuiCol_TextSelectedBg);
	lua_setglobal(L, "ImGuiCol_TextSelectedBg");
	lua_pushnumber(L, ImGuiCol_ModalWindowDarkening);
	lua_setglobal(L, "ImGuiCol_ModalWindowDarkening");
	return 1;
}
