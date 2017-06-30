// Lua
extern "C" {
#define LUA_COMPAT_ALL
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

bool Init(lua_State *L);
void ShutDown();
void NewFrame();
// Inputs
void MouseMoved(int x, int y);
void MousePressed(int button);
void MouseReleased(int button);
void WheelMoved(int y);
void KeyPressed(const char *key);
void KeyReleased(const char *key);
void TextInput(const char *text);
// Inputs state
bool GetWantCaptureMouse();
bool GetWantCaptureKeyboard();
bool GetWantTextInput();
// Fonts
void SetGlobalFontFromFileTTF(const char *path, float size_pixels,
        float spacing_x, float spacing_y, float oversample_x, float oversample_y);
