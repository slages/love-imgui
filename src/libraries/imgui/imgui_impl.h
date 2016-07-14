// ImGui SDL2 binding with OpenGL
// In this binding, ImTextureID is used to store an OpenGL 'GLuint' texture identifier. Read the FAQ about ImTextureID in imgui.cpp.

// You can copy and use unmodified imgui_impl_* files in your project. See main.cpp for an example of using this.
// If you use this binding you'll need to call 4 functions: ImGui_ImplXXXX_Init(), ImGui_ImplXXXX_NewFrame(), ImGui::Render() and ImGui_ImplXXXX_Shutdown().
// If you are new to ImGui, see examples/README.txt and documentation at the top of imgui.cpp.
// https://github.com/ocornut/imgui

typedef union SDL_Event SDL_Event;

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
