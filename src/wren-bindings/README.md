Here be the wren bindings.

to use, copy [wrap_imgui_codegen.cpp](src/wren-bindings/wrap_imgui_codegen.cpp) and [wrap_imgui_codegen.h](src/wren-bindings/wrap_imgui_codegen.h), and [imgui](deps/libimgui) itself, into your project.

Then, yout can expose it to wren's import system:
```
#include "wrap_imgui_codegen.h"
char* loadModule(WrenVM* vm, const char* name)
{
	if(strcmp(name, "imgui") == 0) {
		return wrap_imgui::loadModule(vm);
	}
	return nullptr;
}

WrenForeignClassMethods bindForeignClass(
    WrenVM* vm, const char* module, const char* className)
{
	WrenForeignClassMethods methods = { NULL, NULL };
	if(strcmp(module, "imgui") == 0) {
		if(wrap_imgui::bindForeignClass(vm, className, methods))
		{
			return methods;
		}
	}

	return methods;
}

WrenForeignMethodFn bindForeignMethodFn(
    WrenVM* vm,
    const char* module,
    const char* className,
    bool isStatic,
    const char* signature)
{
	if(strcmp(module, "imgui") == 0) {
		return wrap_imgui::bindForeignMethod(vm, className, isStatic, signature);
	}

	return nullptr;
}
```

## API docs
TODO, sorry. the output for each function should fairly closely match the
signatures in [imgui.h](deps/libimgui/imgui.h), except for the ones that are
not implemented :p
Some mechanical notes:
* out parameters are handled by a helper "Box" class. compound data types, like
  ImVec2, does not need to be boxed, but primitive types like numbers and
  strings do.
```wren
	var numBox = Box.new(10)
	var changed = ImGui.DragFloat("my float", numBox)
	System.print(numBox.value)
```
* Enums can either be provided as numbers, or strings
```wren
ImGui.Begin("MyWindow", Box.new(true), 0) // number
ImGui.Begin("MyWindow", Box.new(true), "NoTitleBar") // single enum
ImGui.Begin("MyWindow", Box.new(true), "AlwaysAutoResize|NoTitleBar") // enum flags
```

