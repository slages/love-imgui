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
const char* wrenExGetSlotStringDefault(WrenVM* vm, int slotIdx, const char* d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenGetSlotString(vm, slotIdx);
	} else {
		return d;
	}
}

bool wrenExGetSlotBoolDefault(WrenVM* vm, int slotIdx, bool d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenGetSlotBool(vm, slotIdx);
	} else {
		return d;
	}
}

int wrenExGetSlotInt(WrenVM* vm, int slotIdx)
{
	// TODO: check integralness
	return static_cast<int>(wrenGetSlotDouble(vm, slotIdx));
}

int wrenExGetSlotIntDefault(WrenVM* vm, int slotIdx, int d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenExGetSlotInt(vm, slotIdx);
	} else {
		return d;
	}
}

double wrenExGetSlotDoubleDefault(WrenVM* vm, int slotIdx, double d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenGetSlotDouble(vm, slotIdx);
	} else {
		return d;
	}
}

float wrenExGetSlotFloat(WrenVM* vm, int slotIdx)
{
	return static_cast<float>(wrenGetSlotDouble(vm, slotIdx));
}

float wrenExGetSlotFloatDefault(WrenVM* vm, int slotIdx, float d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenExGetSlotFloat(vm, slotIdx);
	} else {
		return d;
	}
}

unsigned int wrenExGetSlotUInt(WrenVM* vm, int slotIdx)
{
	// TODO: check integralness
	return static_cast<unsigned int>(wrenGetSlotDouble(vm, slotIdx));
}

unsigned int wrenExGetSlotUIntDefault(WrenVM* vm, int slotIdx, unsigned int d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenExGetSlotUInt(vm, slotIdx);
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
T wrenExGetSlotEnum(U fromString, WrenVM* vm, int slotIdx)
{
	const char* s = wrenGetSlotString(vm, slotIdx);
	std::optional<T> opt = fromString(s);
	if(!opt) {
		wrenExAbortf(vm, "Invalid enum as argument %d, received \"%s\"", slotIdx, s);
	}
	return *opt;
}

template<typename T, typename U>
T wrenExGetSlotEnumsDefault(U fromString, WrenVM* vm, int slotIdx, T d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenExGetSlotEnum<T, U>(fromString, vm, slotIdx);
	} else {
		return d;
	}
}

template<typename T, typename U>
T wrenExGetSlotFlags(U fromString, WrenVM* vm, int slotIdx)
{
	T out{};
	WrenType type = wrenGetSlotType(vm, slotIdx);
	if (type == WREN_TYPE_NUM) {
		// variant A: raw number
		out = static_cast<T>(wrenExGetSlotInt(vm, slotIdx));
	} else if (type == WREN_TYPE_STRING) {
		// variant B: string, split by '|'
		const char* s = wrenGetSlotString(vm, slotIdx);
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);
		while (std::getline(tokenStream, token, '|')) {
			std::optional<T> opt = fromString(token.c_str());
			if (!opt) {
				wrenExAbortf(vm, "Unrecognized value in flags parameter %d: %s", slotIdx, token.c_str());
			}
			out = out | *opt;
		}
	} else {
		wrenExAbortf(vm, "Unrecognized flag parameter %d: must be int, string, or table", slotIdx);
	}

	return out;
}

template<typename T, typename U>
T wrenExGetSlotFlagsDefault(U fromString, WrenVM* vm, int slotIdx, T d)
{
	if(wrenGetSlotCount(vm) > slotIdx) {
		return wrenExGetSlotFlags<T, U>(fromString, vm, slotIdx);
	} else {
		return d;
	}
}

// End Helpers }}}

// Helper classes {{{
using WrenNull = std::monostate;
void setSlotGeneric(WrenVM* vm, int slotIdx, WrenNull v)
{
	(void)v;
	wrenSetSlotNull(vm, slotIdx);
}

void setSlotGeneric(WrenVM* vm, int slotIdx, bool v)
{
	wrenSetSlotBool(vm, slotIdx, v);
}

void setSlotGeneric(WrenVM* vm, int slotIdx, double v)
{
	wrenSetSlotDouble(vm, slotIdx, v);
}

void setSlotGeneric(WrenVM* vm, int slotIdx, const std::string& v)
{
	wrenSetSlotString(vm, slotIdx, v.c_str());
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

template<>
std::string getSlotGeneric<std::string>(WrenVM* vm, int slotIdx)
{
	return std::string(wrenGetSlotString(vm, slotIdx));
}

class Box {
	using Field = std::variant<WrenNull, bool, double, std::string>;
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
		case WREN_TYPE_STRING:
			{
				*field = getSlotGeneric<std::string>(vm, 1);
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

class WrapImVec2 {
	public:
	static void alloc(WrenVM* vm)
	{
		void* memory = wrenSetSlotNewForeign(vm, 0, 0, sizeof(ImVec2));
		ImVec2* field = new (memory) ImVec2(0.0f, 0.0f);
	}
	static void finalize(void* memory)
	{
		ImVec2* field = (ImVec2*)memory;
		field->~ImVec2();
	}
	static void init(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to X is not a number");
		}
		field->x = static_cast<float>(getSlotGeneric<double>(vm, 1));

		if(!wrenGetSlotType(vm, 2) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Y is not a number");
		}
		field->y = static_cast<float>(getSlotGeneric<double>(vm, 2));
	}
	static void getX(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		setSlotGeneric(vm, 0, field->x);
	}
	static void setX(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to X is not a number");
		}
		field->x = static_cast<float>(getSlotGeneric<double>(vm, 1));
	}
	static void getY(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		setSlotGeneric(vm, 0, field->y);
	}
	static void setY(WrenVM* vm)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Y is not a number");
		}
		field->y = static_cast<float>(getSlotGeneric<double>(vm, 1));
	}

	static ImVec2 getSlot(WrenVM* vm, int slotIdx)
	{
		ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, slotIdx);
		return *field;
	}

	static ImVec2 getSlotDefault(WrenVM* vm, int slotIdx, const ImVec2 d)
	{
		if(wrenGetSlotCount(vm) > slotIdx) {
			ImVec2* field = (ImVec2*)wrenGetSlotForeign(vm, 0);
			return *field;
		} else {
			return d;
		}
	}

	static ImVec2* setSlot(WrenVM* vm, int slotIdx, const ImVec2 d = ImVec2(0, 0))
	{
		wrenGetVariable(vm, "ImGui", "ImVec2", slotIdx);
		void* memory = wrenSetSlotNewForeign(vm, slotIdx, slotIdx, sizeof(ImVec2));
		ImVec2* field = (ImVec2*) memory;
		*field = d;
		return field;
	}
};

class WrapImVec4 {
	public:
	static void alloc(WrenVM* vm)
	{
		void* memory = wrenSetSlotNewForeign(vm, 0, 0, sizeof(ImVec4));
		ImVec4* field = new (memory) ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
	}
	static void finalize(void* memory)
	{
		ImVec4* field = (ImVec4*)memory;
		field->~ImVec4();
	}
	static void init(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to X is not a number");
		}
		field->x = static_cast<float>(getSlotGeneric<double>(vm, 1));

		if(!wrenGetSlotType(vm, 2) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Y is not a number");
		}
		field->y = static_cast<float>(getSlotGeneric<double>(vm, 2));
	}
	static void getX(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		setSlotGeneric(vm, 0, field->x);
	}
	static void setX(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to X is not a number");
		}
		field->x = static_cast<float>(getSlotGeneric<double>(vm, 1));
	}
	static void getY(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		setSlotGeneric(vm, 0, field->y);
	}
	static void setY(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Y is not a number");
		}
		field->y = static_cast<float>(getSlotGeneric<double>(vm, 1));
	}
	static void getZ(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		setSlotGeneric(vm, 0, field->y);
	}
	static void setZ(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to Z is not a number");
		}
		field->y = static_cast<float>(getSlotGeneric<double>(vm, 1));
	}
	static void getW(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		setSlotGeneric(vm, 0, field->y);
	}
	static void setW(WrenVM* vm)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
		if(!wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) {
			wrenExAbortf(vm, "value passed to W is not a number");
		}
		field->y = static_cast<float>(getSlotGeneric<double>(vm, 1));
	}

	static ImVec4 getSlot(WrenVM* vm, int slotIdx)
	{
		ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, slotIdx);
		return *field;
	}

	static ImVec4 getSlotDefault(WrenVM* vm, int slotIdx, const ImVec4 d)
	{
		if(wrenGetSlotCount(vm) > slotIdx) {
			ImVec4* field = (ImVec4*)wrenGetSlotForeign(vm, 0);
			return *field;
		} else {
			return d;
		}
	}

	static ImVec4* setSlot(WrenVM* vm, int slotIdx, const ImVec4 d = ImVec4(0, 0, 0, 0))
	{
		wrenGetVariable(vm, "ImGui", "ImVec4", slotIdx);
		void* memory = wrenSetSlotNewForeign(vm, slotIdx, slotIdx, sizeof(ImVec4));
		ImVec4* field = (ImVec4*) memory;
		*field = d;
		return field;
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

// {{{ Function overrides
// }}}

const std::unordered_map<std::string, WrenForeignClassMethods> foreignAllocators = {
{"Box", {Box::alloc, Box::finalize}},
{"ImVec2", {WrapImVec2::alloc, WrapImVec2::finalize}},
{"ImVec4", {WrapImVec4::alloc, WrapImVec4::finalize}},
};

const std::unordered_map<std::string, WrenForeignMethodFn> foreignMethods = {
{"Box::init new(_)", Box::init},
{"Box::value", Box::get},
{"Box::value=(_)", Box::set},

{"ImVec2::init new(_,_)", WrapImVec2::init},
{"ImVec2::x", WrapImVec2::getX},
{"ImVec2::x=(_)", WrapImVec2::setX},
{"ImVec2::y", WrapImVec2::getY},
{"ImVec2::y=(_)", WrapImVec2::setY},

{"ImVec4::init new(_,_,_,_)", WrapImVec4::init},
{"ImVec4::x", WrapImVec4::getX},
{"ImVec4::x=(_)", WrapImVec4::setX},
{"ImVec4::y", WrapImVec4::getY},
{"ImVec4::y=(_)", WrapImVec4::setY},
{"ImVec4::z", WrapImVec4::getZ},
{"ImVec4::z=(_)", WrapImVec4::setZ},
{"ImVec4::w", WrapImVec4::getW},
{"ImVec4::w=(_)", WrapImVec4::setW},

<% for name, data in util.sortedPairs(imgui.functions.ImGui.validNames) do -%>
<%- helpers.generateCppSignatures(data) %>
<% end -%>

{"ImGui::IsRectVisible(_)", w_IsRectVisible_Override1},
{"ImGui::IsRectVisible(_,_)", w_IsRectVisible_Override2},

{"ImGui::InputText(_,_,_,_)", w_InputText_Override2},
{"ImGui::InputText(_,_,_)", w_InputText_Override2},
{"ImGui::InputText(_,_)", w_InputText_Override2},

{"ImGui::InputTextMultiline(_,_,_,_)", w_InputTextMultiline_Override2},
{"ImGui::InputTextMultiline(_,_,_)", w_InputTextMultiline_Override2},
{"ImGui::InputTextMultiline(_,_)", w_InputTextMultiline_Override2},

{"ImGui::InputTextWithHint(_,_,_,_,_)", w_InputTextWithHint_Override2},
{"ImGui::InputTextWithHint(_,_,_,_)", w_InputTextWithHint_Override2},
{"ImGui::InputTextWithHint(_,_,_)", w_InputTextWithHint_Override2},
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
	auto pair = foreignAllocators.find(className);

	if(pair != foreignAllocators.end()) {
		const WrenForeignClassMethods& methods2 = pair->second;
		methods.allocate = methods2.allocate;
		methods.finalize = methods2.finalize;
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
