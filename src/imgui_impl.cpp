// SDL
#include <SDL.h>
#include <SDL_syswm.h>
#include <SDL_video.h>

// IMGUI
#include "imgui_impl.h"
#include "libimgui/imgui.h"

// STD
#include <string>
#include <vector>
#include <map>
//#include <iostream>

// Data
static double       g_Time = 0.0f;
static bool         g_MousePressed[3] = { false, false, false };
static float        g_MouseWheel = 0.0f;
static int			g_window = -1;
static std::string	g_iniPath;
static std::map<std::string, int>	g_keyMap;
static lua_State	*g_L;

// This is the main rendering function that you have to implement and provide to ImGui (via setting up 'RenderDrawListsFn' in the ImGuiIO structure)
// If text or lines are blurry when integrating ImGui in your engine:
// - in your Render function, try translating your projection matrix by (0.5f,0.5f) or (0.375f,0.375f)
void ImGui_ImplSdl_RenderDrawLists(ImDrawData* draw_data)
{
	// Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
	ImGuiIO& io = ImGui::GetIO();
	int fb_width = (int)(io.DisplaySize.x * io.DisplayFramebufferScale.x);
	int fb_height = (int)(io.DisplaySize.y * io.DisplayFramebufferScale.y);
	if (fb_width == 0 || fb_height == 0)
		return;
	draw_data->ScaleClipRects(io.DisplayFramebufferScale);

	lua_getglobal(g_L, "imgui");
	// Render command lists
	for (int n = 0; n < draw_data->CmdListsCount; n++)
	{
		const ImDrawList* cmd_list = draw_data->CmdLists[n];

		lua_newtable(g_L);
		for (int i = 1; i <= cmd_list->IdxBuffer.size(); i++)
		{
			lua_pushnumber(g_L, i);
			lua_pushnumber(g_L, cmd_list->IdxBuffer[i - 1] + 1);
			lua_rawset(g_L, -3);
		}
		lua_setfield(g_L, -2, "idx");

		lua_pushlstring(g_L, (char *)&cmd_list->VtxBuffer.front(), cmd_list->VtxBuffer.size() * sizeof(ImDrawVert));
		lua_setfield(g_L, -2, "verticesData");
		lua_pushnumber(g_L, cmd_list->VtxBuffer.size() * sizeof(ImDrawVert));
		lua_setfield(g_L, -2, "verticesSize");

		luaL_dostring(g_L, "imgui.renderMesh = love.graphics.newMesh(imgui.vertexformat, love.image.newImageData(imgui.verticesSize / 4, 1, imgui.verticesData), \"triangles\") imgui.renderMesh:setTexture(imgui.textureObject) imgui.renderMesh:setVertexMap(imgui.idx)");

		int position = 1;
		for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.size(); cmd_i++)
		{
			const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
			lua_pushnumber(g_L, pcmd->ElemCount);
			lua_setfield(g_L, -2, "vertexCount");
			lua_pushnumber(g_L, position);
			lua_setfield(g_L, -2, "vertexPosition");
			position += pcmd->ElemCount;

			lua_pushnumber(g_L, (int)pcmd->ClipRect.x);
			lua_setfield(g_L, -2, "clipX");
			lua_pushnumber(g_L, (int)(pcmd->ClipRect.y));
			lua_setfield(g_L, -2, "clipY");
			lua_pushnumber(g_L, (int)(pcmd->ClipRect.z - pcmd->ClipRect.x));
			lua_setfield(g_L, -2, "clipWidth");
			lua_pushnumber(g_L, (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));
			lua_setfield(g_L, -2, "clipHeight");

			luaL_dostring(g_L, "\
				love.graphics.setScissor(imgui.clipX, imgui.clipY, imgui.clipWidth, imgui.clipHeight) \
				imgui.renderMesh:setDrawRange(imgui.vertexPosition, imgui.vertexPosition + imgui.vertexCount - 1) \
				love.graphics.draw(imgui.renderMesh) \
			");
		}
	}
	luaL_dostring(g_L, "love.graphics.setScissor()");
	lua_pop(g_L, 1);
}

static const char* ImGui_ImplSdl_GetClipboardText()
{
	return SDL_GetClipboardText();
}

static void ImGui_ImplSdl_SetClipboardText(const char* text)
{
	SDL_SetClipboardText(text);
}

//
// Public part
//

bool    Init(lua_State *L)
{
	ImGuiIO& io = ImGui::GetIO();

	// LUA state
	g_L = L;

	// Create the texture object
	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
	
	lua_getglobal(L, "imgui");
	lua_pushnumber(L, width);
	lua_setfield(L, -2, "textureWidth");
	lua_pushnumber(L, height);
	lua_setfield(L, -2, "textureHeight");
	lua_pushlstring(L, (char *)pixels, width * height * 4);
	lua_setfield(L, -2, "texturePixels");
	luaL_dostring(L, "imgui.textureObject = love.graphics.newImage(love.image.newImageData(imgui.textureWidth, imgui.textureHeight, imgui.texturePixels))\
					  imgui.vertexformat = { {\"VertexPosition\", \"float\", 2}, {\"VertexTexCoord\", \"float\", 2}, {\"VertexColor\", \"byte\", 4} }");
	lua_pop(L, 1);

	// Key map
	g_keyMap["tab"] = 1;
	g_keyMap["left"] = 2;
	g_keyMap["right"] = 3;
	g_keyMap["up"] = 4;
	g_keyMap["down"] = 5;
	g_keyMap["pageup"] = 6;
	g_keyMap["pagedown"] = 7;
	g_keyMap["home"] = 8;
	g_keyMap["end"] = 9;
	g_keyMap["delete"] = 10;
	g_keyMap["backspace"] = 11;
	g_keyMap["return"] = 12;
	g_keyMap["escape"] = 13;
	g_keyMap["a"] = 14;
	g_keyMap["c"] = 15;
	g_keyMap["v"] = 16;
	g_keyMap["x"] = 17;
	g_keyMap["y"] = 18;
	g_keyMap["z"] = 19;

	io.KeyMap[ImGuiKey_Tab] = g_keyMap["tab"];                     // Keyboard mapping. ImGui will use those indices to peek into the io.KeyDown[] array.
	io.KeyMap[ImGuiKey_LeftArrow] = g_keyMap["left"];
	io.KeyMap[ImGuiKey_RightArrow] = g_keyMap["right"];
	io.KeyMap[ImGuiKey_UpArrow] = g_keyMap["up"];
	io.KeyMap[ImGuiKey_DownArrow] = g_keyMap["down"];
	io.KeyMap[ImGuiKey_PageUp] = g_keyMap["pageup"];
	io.KeyMap[ImGuiKey_PageDown] = g_keyMap["pagedown"];
	io.KeyMap[ImGuiKey_Home] = g_keyMap["home"];
	io.KeyMap[ImGuiKey_End] = g_keyMap["end"];
	io.KeyMap[ImGuiKey_Delete] = g_keyMap["delete"];
	io.KeyMap[ImGuiKey_Backspace] = g_keyMap["backspace"];
	io.KeyMap[ImGuiKey_Enter] = g_keyMap["return"];
	io.KeyMap[ImGuiKey_Escape] = g_keyMap["escape"];
	io.KeyMap[ImGuiKey_A] = g_keyMap["a"];
	io.KeyMap[ImGuiKey_C] = g_keyMap["c"];
	io.KeyMap[ImGuiKey_V] = g_keyMap["v"];
	io.KeyMap[ImGuiKey_X] = g_keyMap["x"];
	io.KeyMap[ImGuiKey_Y] = g_keyMap["y"];
	io.KeyMap[ImGuiKey_Z] = g_keyMap["z"];

	io.RenderDrawListsFn = ImGui_ImplSdl_RenderDrawLists;   // Alternatively you can set this to NULL and call ImGui::GetDrawData() after ImGui::Render() to get the same ImDrawData pointer.
	io.SetClipboardTextFn = ImGui_ImplSdl_SetClipboardText;
	io.GetClipboardTextFn = ImGui_ImplSdl_GetClipboardText;

	luaL_dostring(L, "love.filesystem.createDirectory(love.filesystem.getSaveDirectory()) return love.filesystem.getSaveDirectory()");
	size_t size;
	const char *path = luaL_checklstring(L, 1, &size);
	g_iniPath = std::string(path) + std::string("/imgui.ini");
	io.IniFilename = g_iniPath.c_str();
	return true;
}

void ShutDown()
{
	ImGui::Shutdown();
}

void NewFrame()
{
	SDL_Window *window = SDL_GL_GetCurrentWindow();
	if (!window)
		return;

	ImGuiIO& io = ImGui::GetIO();

	if (SDL_GetWindowID(window) != g_window)
	{
		if (g_window == -1)
		{
#ifdef _WIN32
			SDL_SysWMinfo wmInfo;
			SDL_VERSION(&wmInfo.version);
			SDL_GetWindowWMInfo(window, &wmInfo);
			io.ImeWindowHandle = wmInfo.info.win.window;
#endif
		}
		g_window = SDL_GetWindowID(window);
	}

	// Setup display size (every frame to accommodate for window resizing)
	int w, h;
	int display_w, display_h;
	SDL_GetWindowSize(window, &w, &h);
	SDL_GL_GetDrawableSize(window, &display_w, &display_h);
	io.DisplaySize = ImVec2((float)w, (float)h);
	io.DisplayFramebufferScale = ImVec2(w > 0 ? ((float)display_w / w) : 0, h > 0 ? ((float)display_h / h) : 0);

	// Setup time step
	Uint32	time = SDL_GetTicks();
	double current_time = time / 1000.0;
	io.DeltaTime = g_Time > 0.0 ? (float)(current_time - g_Time) : (float)(1.0f / 60.0f);
	g_Time = current_time;

	// Setup input
	io.MouseDown[0] = g_MousePressed[0];
	io.MouseDown[1] = g_MousePressed[1];
	io.MouseDown[2] = g_MousePressed[2];
	io.MouseWheel = g_MouseWheel;
	g_MouseWheel = 0.0f;

	// Hide OS mouse cursor if ImGui is drawing it
	SDL_ShowCursor(io.MouseDrawCursor ? 0 : 1);

	// Start the frame
	ImGui::NewFrame();
}

//
// Inputs
//
void MouseMoved(int x, int y)
{
	SDL_Window *window = SDL_GL_GetCurrentWindow();
	if (window)
	{
		ImGuiIO& io = ImGui::GetIO();
		int mx, my;
		Uint32 mouseMask = SDL_GetMouseState(&mx, &my);
		if (SDL_GetWindowFlags(window) & SDL_WINDOW_MOUSE_FOCUS)
			io.MousePos = ImVec2((float)x, (float)y);   // Mouse position, in pixels (set to -1,-1 if no mouse / on another screen, etc.)
		else
			io.MousePos = ImVec2(-1, -1);
	}
}

void MousePressed(int button)
{
	if (button == 1) g_MousePressed[0] = true;
	if (button == 2) g_MousePressed[1] = true;
	if (button == 3) g_MousePressed[2] = true;
}

void MouseReleased(int button)
{
	if (button == 1) g_MousePressed[0] = false;
	if (button == 2) g_MousePressed[1] = false;
	if (button == 3) g_MousePressed[2] = false;
}

void WheelMoved(int y)
{
	if (y > 0)
		g_MouseWheel = 1;
	if (y < 0)
		g_MouseWheel = -1;
}

void KeyPressed(const char *key)
{
	std::string k(key);
	if (k == "kpenter")
		k = "return";
	ImGuiIO& io = ImGui::GetIO();
	io.KeysDown[g_keyMap[k]] = true;
	io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
	io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
	io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
	io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
}

void KeyReleased(const char *key)
{
	std::string k(key);
	if (k == "kpenter")
		k = "return";
	ImGuiIO& io = ImGui::GetIO();
	io.KeysDown[g_keyMap[k.c_str()]] = false;
	io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
	io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
	io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
	io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
}

void TextInput(const char *text)
{
	ImGuiIO& io = ImGui::GetIO();
	io.AddInputCharactersUTF8(text);
}

// Inputs state
bool GetWantCaptureMouse()
{
	ImGuiIO& io = ImGui::GetIO();
	return io.WantCaptureMouse;
}

bool GetWantCaptureKeyboard()
{
	ImGuiIO& io = ImGui::GetIO();
	return io.WantCaptureKeyboard;
}

bool GetWantTextInput()
{
	ImGuiIO& io = ImGui::GetIO();
	return io.WantTextInput;
}
