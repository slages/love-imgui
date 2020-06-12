// This is an automatically generated file!!
#pragma once
#include "wren.hpp"

namespace wrap_imgui {
char* loadModule(WrenVM* vm);
bool bindForeignClass(WrenVM* vm, const char* className, WrenForeignClassMethods& methods);
WrenForeignMethodFn bindForeignMethod(WrenVM* vm, const char* className, bool isStatic, const char* signature);
}

