Here be the lua bindings.

to use, copy [wrap_imgui_codegen.cpp](wrap_imgui_codegen.cpp) and [wrap_imgui_codegen.h](wrap_imgui_codegen.h), and imgui itself, into your project.

you can then access a table with every wrapper using 
```cpp
// creates a new table with imgui functions, and pushes it to top of the stack.
wrap_imgui::createImguiTable(L);
```

or add it to your own table:
```cpp
wrap_imgui::addImguiWrappers(L); // adds to table on top of stack
```

You should also provide a definition for:
```cpp
ImTextureID luax_checkTextureID(lua_State* L, int narg);
```
which should peek at a lua value at the given location on the stack and return
a handle to your texture type. From there, you can now integrate imgui as you
would integrate imgui into a C++ library.

## API docs
An automated listing of all supported functions can be found at [api_details.md](api_details.md). the output for each function should fairly closely match the
signatures in [imgui.h](deps/libimgui/imgui.h), except for the ones that are
not implemented :p
Some mechanical notes:
* return types are ordered by out parameter, then function return value.
```lua
	local outValue, changed = imgui.DragFloat("my float", inValue)
```
* We're taking a maximalist approach to enums and enum flags. All of these are valid and interchangable with no configuration necessary:
```lua
imgui.Begin("MyWindow", true, "AlwaysAutoResize|NoTitleBar")
imgui.Begin("MyWindow", true, {"AlwaysAutoResize", "NoTitleBar"})
imgui.Begin("MyWindow", true, {AlwaysAutoResize = true, NoTitleBar = true})
```

We are also generating autocomplete definitions at
[autocomplete.json](autocomplete.json). this file matches the
atom-autocomplete-lua format.
