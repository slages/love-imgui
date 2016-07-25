// ImGui SDL2 binding with OpenGL3
// In this binding, ImTextureID is used to store an OpenGL 'GLuint' texture identifier. Read the FAQ about ImTextureID in imgui.cpp.

// You can copy and use unmodified imgui_impl_* files in your project. See main.cpp for an example of using this.
// If you use this binding you'll need to call 4 functions: ImGui_ImplXXXX_Init(), ImGui_ImplXXXX_NewFrame(), ImGui::Render() and ImGui_ImplXXXX_Shutdown().
// If you are new to ImGui, see examples/README.txt and documentation at the top of imgui.cpp.
// https://github.com/ocornut/imgui

#include "glad/gladfuncs.hpp"

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
#include <iostream>

using namespace glad;

// Data
static double       g_Time = 0.0f;
static bool         g_MousePressed[3] = { false, false, false };
static float        g_MouseWheel = 0.0f;
static GLuint       g_FontTexture = 0;
static int			g_window = -1;
static std::string	g_iniPath;
static bool			g_gladInit = false;
static std::map<std::string, int>	g_keyMap;

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

	// Disable current program and vertex attributes
	GLint last_program = 0;
	glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
	std::vector<GLint> enabledAttribs;
	if (glGetError() == 0)
	{
		GLint attribsCount = 0;
		glGetProgramiv(last_program, GL_ACTIVE_ATTRIBUTES, &attribsCount);
		for (GLint i = 0; i < attribsCount; i++)
		{
			GLint enabled;
			glGetVertexAttribiv(i, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);
			if (glGetError() == 0 && enabled > 0)
			{
				enabledAttribs.push_back(i);
				glDisableVertexAttribArray(i);
			}
		}
	}
	glUseProgram(0);

	// We are using the OpenGL fixed pipeline to make the example code simpler to read!
	// Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, vertex/texcoord/color pointers.
	GLint last_texture; glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
	GLint last_viewport[4]; glGetIntegerv(GL_VIEWPORT, last_viewport);
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_TRANSFORM_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_TEXTURE_2D);

	// Setup viewport, orthographic projection matrix
	glViewport(0, 0, (GLsizei)fb_width, (GLsizei)fb_height);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0f, io.DisplaySize.x, io.DisplaySize.y, 0.0f, -1.0f, +1.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Render command lists
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))
	for (int n = 0; n < draw_data->CmdListsCount; n++)
	{
		const ImDrawList* cmd_list = draw_data->CmdLists[n];
		const unsigned char* vtx_buffer = (const unsigned char*)&cmd_list->VtxBuffer.front();
		const ImDrawIdx* idx_buffer = &cmd_list->IdxBuffer.front();
		glVertexPointer(2, GL_FLOAT, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, pos)));
		glTexCoordPointer(2, GL_FLOAT, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, uv)));
		glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, col)));

		for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.size(); cmd_i++)
		{
			const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
			if (pcmd->UserCallback)
			{
				pcmd->UserCallback(cmd_list, pcmd);
			}
			else
			{
				glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
				glScissor((int)pcmd->ClipRect.x, (int)(fb_height - pcmd->ClipRect.w), (int)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));
				glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, idx_buffer);
			}
			idx_buffer += pcmd->ElemCount;
		}
	}
#undef OFFSETOF

	// Restore modified state
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D, (GLuint)last_texture);
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPopAttrib();
	glViewport(last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2], (GLsizei)last_viewport[3]);
	// Enable back the current program
	for (std::vector<GLint>::iterator it = enabledAttribs.begin(); it != enabledAttribs.end(); ++it)
	{
		glEnableVertexAttribArray(*it);
		if (*it == 2)
			glVertexAttrib4f(2, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	glUseProgram((GLuint)last_program);
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

bool CreateDeviceObjects()
{
	// Init glad
	if (!g_gladInit)
	{
		if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
		{
			//std::cout << "Failed to initialize OpenGL context" << std::endl;
			return false;
		}
	}
	g_gladInit = true;

	// Build texture atlas
	ImGuiIO& io = ImGui::GetIO();
	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsAlpha8(&pixels, &width, &height);

	// Upload texture to graphics system
	GLint last_texture;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
	glGenTextures(1, &g_FontTexture);
	glBindTexture(GL_TEXTURE_2D, g_FontTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, pixels);

	// Store our identifier
	io.Fonts->TexID = (void *)(intptr_t)g_FontTexture;

	// Restore state
	glBindTexture(GL_TEXTURE_2D, last_texture);

	return true;
}

void    InvalidateDeviceObjects()
{
	if (g_FontTexture)
	{
		glDeleteTextures(1, &g_FontTexture);
		ImGui::GetIO().Fonts->TexID = 0;
		g_FontTexture = 0;
	}
}

bool    Init(const char *path)
{
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

	ImGuiIO& io = ImGui::GetIO();
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

	g_iniPath = std::string(path) + std::string("/imgui.ini");
	io.IniFilename = g_iniPath.c_str();
	return true;
}

void ShutDown()
{
	InvalidateDeviceObjects();
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
		InvalidateDeviceObjects();
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

	if (!g_FontTexture)
		CreateDeviceObjects();

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
