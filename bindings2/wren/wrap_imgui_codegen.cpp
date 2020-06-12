// This is an automatically generated file!!

#include "wren.hpp"
#include "wrap_imgui_codegen.h"
#include "imgui.h"
#include "imgui_stdlib.h"

#include <codecvt>
#include <locale>
#include <optional>
#include <sstream>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace {

// Enums {{{
<% for _, enumData in ipairs(imgui.enums) do %>
<%- helpers.genEnumFromString(imgui, enumData) %>
<% end %>
// End Enums }}}

// Helpers {{{
const char* wrenExGetSlotStringDefault(WrenVM* vm, int narg, const char* d)
{
	if(wrenGetSlotCount(vm) > narg) {
		return wrenGetSlotString(vm, narg);
	} else {
		return d;
	}
}

bool wrenExGetSlotBoolDefault(WrenVM* vm, int narg, bool d)
{
	if(wrenGetSlotCount(vm) > narg) {
		return wrenGetSlotBool(vm, narg);
	} else {
		return d;
	}
}

int wrenExGetSlotInt(WrenVM* vm, int narg)
{
	// TODO: check integralness
	return static_cast<int>(wrenGetSlotDouble(vm, narg));
}

int wrenExGetSlotIntDefault(WrenVM* vm, int narg, int d)
{
	if(wrenGetSlotCount(vm) > narg) {
		return wrenExGetSlotInt(vm, narg);
	} else {
		return d;
	}
}

double wrenExGetSlotDoubleDefault(WrenVM* vm, int narg, double d)
{
	if(wrenGetSlotCount(vm) > narg) {
		return wrenGetSlotDouble(vm, narg);
	} else {
		return d;
	}
}

float wrenExGetSlotFloat(WrenVM* vm, int narg)
{
	return static_cast<float>(wrenGetSlotDouble(vm, narg));
}

float wrenExGetSlotFloatDefault(WrenVM* vm, int narg, float d)
{
	if(wrenGetSlotCount(vm) > narg) {
		return wrenExGetSlotFloat(vm, narg);
	} else {
		return d;
	}
}

unsigned int wrenExGetSlotUInt(WrenVM* vm, int narg)
{
	// TODO: check integralness
	return static_cast<unsigned int>(wrenGetSlotDouble(vm, narg));
}

unsigned int wrenExGetSlotUIntDefault(WrenVM* vm, int narg, unsigned int d)
{
	if(wrenGetSlotCount(vm) > narg) {
		return wrenExGetSlotUInt(vm, narg);
	} else {
		return d;
	}
}

void wrenExAbortf(WrenVM* vm, const char* fmt, ...)
{
	char buf[1000]; // arbitrary size

	va_list arglist;
    va_start(arglist, fmt);
    vsnprintf(buf, 1000, fmt, arglist);
    va_end(arglist);

	int slotIdx = wrenGetSlotCount(vm);
	wrenEnsureSlots(vm, slotIdx + 1);
	wrenSetSlotString(vm, slotIdx, buf);
	wrenAbortFiber(vm, slotIdx);
}

template<typename T, typename U>
T wrenExGetSlotEnum(U fromString, WrenVM* vm, int narg)
{
	const char* s = wrenGetSlotString(vm, narg);
	std::optional<T> opt = fromString(s);
	if(!opt) {
		wrenExAbortf(vm, "Invalid enum as argument %d, received \"%s\"", narg, s);
	}
	return *opt;
}

template<typename T, typename U>
T wrenExGetSlotEnumsDefault(U fromString, WrenVM* vm, int narg, T d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	return wrenExGetSlotEnum<T, U>(fromString, vm, narg);
}

template<typename T, typename U>
T wrenExGetSlotFlags(U fromString, WrenVM* vm, int narg)
{
	T out{};
	WrenType type = wrenGetSlotType(vm, narg);
	if (type == WREN_TYPE_NUM) {
		// variant A: raw number
		out = static_cast<T>(wrenExGetSlotInt(vm, narg));
	} else if (type == WREN_TYPE_STRING) {
		// variant B: string, split by '|'
		const char* s = wrenGetSlotString(vm, narg);
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);
		while (std::getline(tokenStream, token, '|')) {
			std::optional<T> opt = fromString(token.c_str());
			if (!opt) {
				wrenExAbortf(vm, "Unrecognized value in flags parameter %d: %s", narg, token.c_str());
			}
			out = out | *opt;
		}
	} else {
		wrenExAbortf(vm, "Unrecognized flag parameter %d: must be int, string, or table", narg);
	}

	return out;
}

template<typename T, typename U>
T wrenExGetSlotFlagsDefault(U fromString, WrenVM* vm, int narg, T d)
{
	if(wrenGetSlotType(vm, narg) == WREN_TYPE_NULL) {
		return d;
	}
	return wrenExGetSlotFlags<T, U>(fromString, vm, narg);
}

// End Helpers }}}

// Helper classes {{{
using WrenNull = std::monostate;
void setSlotGeneric(WrenVM* vm, int slotIdx, bool v)
{
	wrenSetSlotBool(vm, slotIdx, v);
}

void setSlotGeneric(WrenVM* vm, int slotIdx, double v)
{
	wrenSetSlotDouble(vm, slotIdx, v);
}

void setSlotGeneric(WrenVM* vm, int slotIdx, WrenNull v)
{
	(void)v;
	wrenSetSlotNull(vm, slotIdx);
}

template<typename T>
T getSlotGeneric(WrenVM* vm, int slotIdx);

template<>
bool getSlotGeneric<bool>(WrenVM* vm, int slotIdx)
{
	return wrenGetSlotBool(vm, slotIdx);
}

template<>
double getSlotGeneric<double>(WrenVM* vm, int slotIdx)
{
	return wrenGetSlotDouble(vm, slotIdx);
}

class Box {
	using Field = std::variant<WrenNull, bool, double>;
	public:
	static void alloc(WrenVM* vm)
	{
		void* memory = wrenSetSlotNewForeign(vm, 0, 0, sizeof(Field));
		Field* field = new (memory) Field();
	}
	static void finalize(void* memory)
	{
		Field* field = (Field*)memory;
		field->~Field();
	}
	static void init(WrenVM* vm)
	{
		set(vm);
	}
	static void get(WrenVM* vm)
	{
		Field* field = (Field*)wrenGetSlotForeign(vm, 0);
		std::visit([&](auto&&arg){setSlotGeneric(vm, 0, arg);}, *field);
	}
	template<typename T>
	static T getCPP(WrenVM* vm, int slotIdx)
	{
		Field* field = (Field*)wrenGetSlotForeign(vm, slotIdx);
		return std::get<T>(*field);
	}
	static void set(WrenVM* vm)
	{
		Field* field = (Field*)wrenGetSlotForeign(vm, 0);
		switch(wrenGetSlotType(vm, 1))
		{
		case WREN_TYPE_BOOL:
			{
				*field = getSlotGeneric<bool>(vm, 1);
			}
			break;
		case WREN_TYPE_NUM:
			{
				*field = getSlotGeneric<double>(vm, 1);
			}
			break;
		default:
			{
				wrenExAbortf(vm, "Invalid box type");
			}
			break;
		}
	}
	template<typename T>
	static void setCPP(WrenVM* vm, int slotIdx, T v)
	{
		Field* field = (Field*)wrenGetSlotForeign(vm, slotIdx);
		*field = v;
	}
};
// }}}

// Functions {{{
<% for _, fnElement in pairs(imgui.functions) do -%>
<% for _, fnData in ipairs(fnElement.fnData) do -%>
<%- helpers.genFunctionWrapper(fnElement, fnData) %>

<% end -%>
<% end -%>
// End Functions }}}

const std::unordered_map<std::string, WrenForeignMethodFn> foreignMethods = {
{"Box::init new(_)", Box::init},
{"Box::value", Box::get},
{"Box::value=(_)", Box::set},
<% for name, data in pairs(imgui.functions.toplevel.validNames) do -%>
<%- helpers.generateCppSignatures(data) %>
<% end -%>
};

const char* foreignModuleString = R"MODULE(
<%- helpers.embedWrenCode(imgui) %>
)MODULE";

}

char* wrap_imgui::loadModule(WrenVM* vm)
{
	char* buf = (char*)malloc(strlen(foreignModuleString));
	strcpy(buf, foreignModuleString);
	return buf;
}

bool wrap_imgui::bindForeignClass(WrenVM* vm, const char* className, WrenForeignClassMethods& methods)
{
	if(strcmp("Box", className) == 0) {
		methods.allocate = Box::alloc;
		methods.finalize = Box::finalize;
		return true;
	}
	return false;
}

WrenForeignMethodFn wrap_imgui::bindForeignMethod(WrenVM* vm, const char* className, bool isStatic, const char* signature)
{
	char buf[255];
	snprintf(buf, 255, "%s::%s", className, signature);
	auto pair = foreignMethods.find(buf);

	if(pair != foreignMethods.end()) {
		return pair->second;
	}
	return nullptr;
}
