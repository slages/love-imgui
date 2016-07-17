// ImGui SDL2 binding with OpenGL3
// In this binding, ImTextureID is used to store an OpenGL 'GLuint' texture identifier. Read the FAQ about ImTextureID in imgui.cpp.

// You can copy and use unmodified imgui_impl_* files in your project. See main.cpp for an example of using this.
// If you use this binding you'll need to call 4 functions: ImGui_ImplXXXX_Init(), ImGui_ImplXXXX_NewFrame(), ImGui::Render() and ImGui_ImplXXXX_Shutdown().
// If you are new to ImGui, see examples/README.txt and documentation at the top of imgui.cpp.
// https://github.com/ocornut/imgui

// LOVE
#include "common/Module.h"
#include "window/Window.h"
#include "keyboard/Keyboard.h"
#include "filesystem/Filesystem.h"
#include "graphics/opengl/OpenGL.h"
#include "graphics/opengl/Shader.h"
// SDL
#include <SDL.h>
#include <SDL_syswm.h>
// IMGUI
#include "imgui/imgui_impl.h"
#include <imgui/libimgui/imgui.h>
// STD
#include <string>
//#include <iostream>

using namespace glad;
using namespace love::graphics::opengl;

// Data
static double       g_Time = 0.0f;
static bool         g_MousePressed[3] = { false, false, false };
static float        g_MouseWheel = 0.0f;
static GLuint       g_FontTexture = 0;
static int			g_window = -1;
static std::string	g_iniPath;

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
	gl.useProgram(0); // You may want this if using this code in an OpenGL 3+ context
	gl.useVertexAttribArrays(0);

	// Setup viewport, orthographic projection matrix
	gl.setViewport({ 0, 0, (GLsizei)fb_width, (GLsizei)fb_height });
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
				gl.bindTexture((GLuint)(intptr_t)pcmd->TextureId);
				glScissor((int)pcmd->ClipRect.x, (int)(fb_height - pcmd->ClipRect.w), (int)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));
				gl.drawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, idx_buffer);
			}
			idx_buffer += pcmd->ElemCount;
		}
	}
#undef OFFSETOF

	// Restore modified state
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	gl.bindTexture((GLuint)last_texture);
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPopAttrib();
	gl.setViewport({ last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2], (GLsizei)last_viewport[3] });
	gl.useProgram(Shader::current->getProgram());
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
	// Build texture atlas
	ImGuiIO& io = ImGui::GetIO();
	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsAlpha8(&pixels, &width, &height);

	// Upload texture to graphics system
	GLint last_texture;
	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
	glGenTextures(1, &g_FontTexture);
	gl.bindTexture(g_FontTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, pixels);

	// Store our identifier
	io.Fonts->TexID = (void *)(intptr_t)g_FontTexture;

	// Restore state
	gl.bindTexture(last_texture);

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

bool    Init()
{
	ImGuiIO& io = ImGui::GetIO();
	io.KeyMap[ImGuiKey_Tab] = love::keyboard::Keyboard::KEY_TAB;                     // Keyboard mapping. ImGui will use those indices to peek into the io.KeyDown[] array.
	io.KeyMap[ImGuiKey_LeftArrow] = love::keyboard::Keyboard::KEY_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = love::keyboard::Keyboard::KEY_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = love::keyboard::Keyboard::KEY_UP;
	io.KeyMap[ImGuiKey_DownArrow] = love::keyboard::Keyboard::KEY_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = love::keyboard::Keyboard::KEY_PAGEUP;
	io.KeyMap[ImGuiKey_PageDown] = love::keyboard::Keyboard::KEY_PAGEDOWN;
	io.KeyMap[ImGuiKey_Home] = love::keyboard::Keyboard::KEY_HOME;
	io.KeyMap[ImGuiKey_End] = love::keyboard::Keyboard::KEY_END;
	io.KeyMap[ImGuiKey_Delete] = love::keyboard::Keyboard::KEY_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = love::keyboard::Keyboard::KEY_BACKSPACE;
	io.KeyMap[ImGuiKey_Enter] = love::keyboard::Keyboard::KEY_RETURN;
	io.KeyMap[ImGuiKey_Escape] = love::keyboard::Keyboard::KEY_ESCAPE;
	io.KeyMap[ImGuiKey_A] = love::keyboard::Keyboard::KEY_A;
	io.KeyMap[ImGuiKey_C] = love::keyboard::Keyboard::KEY_C;
	io.KeyMap[ImGuiKey_V] = love::keyboard::Keyboard::KEY_V;
	io.KeyMap[ImGuiKey_X] = love::keyboard::Keyboard::KEY_X;
	io.KeyMap[ImGuiKey_Y] = love::keyboard::Keyboard::KEY_Y;
	io.KeyMap[ImGuiKey_Z] = love::keyboard::Keyboard::KEY_Z;

	io.RenderDrawListsFn = ImGui_ImplSdl_RenderDrawLists;   // Alternatively you can set this to NULL and call ImGui::GetDrawData() after ImGui::Render() to get the same ImDrawData pointer.
	io.SetClipboardTextFn = ImGui_ImplSdl_SetClipboardText;
	io.GetClipboardTextFn = ImGui_ImplSdl_GetClipboardText;

	// Disable the ini file
	io.IniFilename = NULL;
	love::filesystem::Filesystem *fs = love::Module::getInstance<love::filesystem::Filesystem>(love::Module::M_FILESYSTEM);
	if (fs)
	{
		fs->createDirectory(fs->getSaveDirectory());
		g_iniPath = std::string(fs->getSaveDirectory()) + std::string("/imgui.ini");
		io.IniFilename = g_iniPath.c_str();
	}

#ifdef _WIN32
	SDL_Window *window = (SDL_Window *)love::Module::getInstance<love::window::Window>(love::Module::M_WINDOW)->getHandle();
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(window, &wmInfo);
	io.ImeWindowHandle = wmInfo.info.win.window;
#endif

	return true;
}

void ShutDown()
{
	InvalidateDeviceObjects();
	ImGui::Shutdown();
}

void NewFrame()
{
	love::window::Window *module = love::Module::getInstance<love::window::Window>(love::Module::M_WINDOW);
	if (!module)
		return;

	SDL_Window *window = (SDL_Window *)module->getHandle();
	if (!window)
		return;

	if (SDL_GetWindowID(window) != g_window)
	{
		InvalidateDeviceObjects();
		if (g_window == -1)
			Init();
		g_window = SDL_GetWindowID(window);
	}

	if (!g_FontTexture)
		CreateDeviceObjects();

	ImGuiIO& io = ImGui::GetIO();

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
	SDL_Window *window = (SDL_Window *)love::Module::getInstance<love::window::Window>(love::Module::M_WINDOW)->getHandle();
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
	love::keyboard::Keyboard *module = love::Module::getInstance<love::keyboard::Keyboard>(love::Module::M_KEYBOARD);
	if (module)
	{
		love::keyboard::Keyboard::Key k;
		module->getConstant(key, k);
		if (k == love::keyboard::Keyboard::KEY_KP_ENTER)
			k = love::keyboard::Keyboard::KEY_RETURN;
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[k] = true;
		io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
		io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
		io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
		io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
	}
}

void KeyReleased(const char *key)
{
	love::keyboard::Keyboard *module = love::Module::getInstance<love::keyboard::Keyboard>(love::Module::M_KEYBOARD);
	if (module)
	{
		love::keyboard::Keyboard::Key k;
		module->getConstant(key, k);
		if (k == love::keyboard::Keyboard::KEY_KP_ENTER)
			k = love::keyboard::Keyboard::KEY_RETURN;
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[k] = false;
		io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
		io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
		io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
		io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
	}
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
