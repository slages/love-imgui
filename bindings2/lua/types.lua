local util = require 'bindings2.util'

local Types = {}

do
	-- Check argument types
	local function simple_arg(getter, defaultGetter)
		return function(buf, arg, i)
			if arg.default then
				buf:addf("auto %s = %s(L, %d, %s);", arg.name, defaultGetter, i, arg.default)
			else
				buf:addf("auto %s = %s(L, %d);", arg.name, getter, i)
			end
			return i + 1
		end
	end

	local function static_cast_arg(ctype, getter, defaultGetter)
		return function(buf, arg, i)
			if arg.default then
				buf:addf("auto %s = static_cast<%s>(%s(L, %d, %s));", arg.name, ctype, defaultGetter, i, arg.default)
			else
				buf:addf("auto %s = static_cast<%s>(%s(L, %d));", arg.name, ctype, getter, i)
			end
			return i + 1
		end
	end

	local function enum_arg(ctype, fromstring)
		return function(buf, arg, i)
			if arg.default then
				buf:addf("auto %s = luax_optenum<%s>(%s, L, %d, %s);", arg.name, ctype, fromstring, i, arg.default)
			else
				buf:addf("auto %s = luax_checkenum<%s>(%s, L, %d);", arg.name, ctype, fromstring, i)
			end
			return i + 1
		end
	end

	local function flags_arg(ctype, fromstring)
		return function(buf, arg, i)
			if arg.default then
				buf:addf("auto %s = luax_optflags<%s>(%s, L, %d, %s);", arg.name, ctype, fromstring, i, arg.default)
			else
				buf:addf("auto %s = luax_checkflags<%s>(%s, L, %d);", arg.name, ctype, fromstring, i)
			end
			return i + 1
		end
	end

	local function skip_arg()
		return function(buf, arg, i)
			if arg.default then
				buf:addf("%s %s = %s; // skipping", arg.type, arg.name, arg.default)
			else
				-- unimplemented required param
				return i, "stop"
			end
			return i
		end
	end

	local function simple_out_arg(ctype, getter, defaultGetter)
		return function(buf, arg, i, outParams)
			if arg.default then
				buf:addf("%s %s = %s(L, %d, %s);", ctype, arg.name, defaultGetter, i, arg.default)
			else
				buf:addf("%s %s = %s(L, %d);", ctype, arg.name, getter, i)
			end
			arg.isOutParam = true
			table.insert(outParams, {arg.name, ctype})
			return i + 1
		end
	end

	local function static_cast_out_arg(ctype, getter, defaultGetter)
		return function(buf, arg, i, outParams)
			if arg.default then
				buf:addf("auto %s = static_cast<%s>(%s(L, %d, %s));", arg.name, ctype, defaultGetter, i, arg.default)
			else
				buf:addf("auto %s = static_cast<%s>(%s(L, %d));", arg.name, ctype, getter, i)
			end
			arg.isOutParam = true
			table.insert(outParams, {arg.name, ctype})
			return i + 1
		end
	end

	local function array_out_arg(size, ctype, getter)
		return function(buf, arg, i, outParams)
			assert(not arg.default, "defaults unimplemented")
			buf:addf("%s %s[%d];", ctype, arg.name, size)
			for ai = 0, size-1 do
				local element = string.format("%s[%d]", arg.name, ai)
				buf:addf("%s = static_cast<%s>(%s(L, %d));", element, ctype, getter, i+ai)
				arg.isOutParam = true
				table.insert(outParams, {element, ctype})
			end
			return i + size
		end
	end

	local typeCheckers = {
		-- static input
		["const char*"] = simple_arg("luaL_checkstring", "luaL_optstring"),
		["bool"] = simple_arg("luax_checkboolean", "luax_optboolean"),
		["int"] = simple_arg("luaL_checkint", "luaL_optint"),
		["double"] = simple_arg("luaL_checknumber", "luaL_optnumber"),
		["ImTextureID"] = simple_arg("luax_checkTextureID", "luax_checkTextureID"),
		["ImGuiContext*"] = static_cast_arg("ImGuiContext*", "luax_checklightuserdata", "luax_optlightuserdata"),
		["ImGuiStyle*"] = static_cast_arg("ImGuiStyle*", "luax_checklightuserdata", "luax_optlightuserdata"),
		["unsigned int"] = static_cast_arg("unsigned int", "luaL_checklong", "luaL_optlong"),
		["float"] = simple_arg("luax_checkfloat", "luax_optfloat"),
		["ImU32"] = static_cast_arg("ImU32", "luaL_checklong", "luaL_optlong"),
		["ImGuiID"] = static_cast_arg("ImGuiID", "luaL_checkint", "luaL_optint"),
		["const fmt*"] = function(buf, arg, i)
			-- get format string
			buf:addf("auto %s = luax_formatargs(L, %s);", arg.name, i)
			return i + 1
		end,
		["const ImVec2*"] = function(buf, arg, i, _)
			local name = arg.name
			if arg.default then
				buf:addf("ImVec2* %s = %s;", name, arg.default)
				buf:addf("ImVec2 %s_buf;", name)
				buf:addf("if(!lua_isnoneornil(L, %d)) {", i+1) buf:indent()
					buf:addf("%s_buf.x = luax_checkfloat(L, %d);", name, i)
					buf:addf("%s_buf.y = luax_checkfloat(L, %d);", name, i+1)
				buf:unindent() buf:add("}")
				return i + 2
			else
				return i, "stop"
			end
		end,
		["const ImVec2&"] = function(buf, arg, i, _)
			local name = arg.name
			if arg.default then
				buf:addf("auto %s = %s;", name, arg.default)
				buf:addf("%s.x = luax_optfloat(L, %d, %s.x);", name, i, name)
				buf:addf("%s.y = luax_optfloat(L, %d, %s.y);", name, i+1, name)
			else
				buf:addf("ImVec2 %s;", name)
				buf:addf("%s.x = luax_checkfloat(L, %d);", name, i)
				buf:addf("%s.y = luax_checkfloat(L, %d);", name, i+1)
			end
			return i+2
		end,
		["const ImVec4&"] = function(buf, arg, i, _)
			local name = arg.name
			if arg.default then
				buf:addf("ImVec4 %s = %s;", name, arg.default)
				buf:addf("%s.x = luax_optfloat(L, %d, %s.x);", name, i, name)
				buf:addf("%s.y = luax_optfloat(L, %d, %s.y);", name, i+1, name)
				buf:addf("%s.z = luax_optfloat(L, %d, %s.z);", name, i+2, name)
				buf:addf("%s.w = luax_optfloat(L, %d, %s.w);", name, i+3, name)
			else
				buf:addf("ImVec4 %s;", name)
				buf:addf("%s.x = luax_checkfloat(L, %d);", name, i)
				buf:addf("%s.y = luax_checkfloat(L, %d);", name, i+1)
				buf:addf("%s.z = luax_checkfloat(L, %d);", name, i+2)
				buf:addf("%s.w = luax_checkfloat(L, %d);", name, i+3)
			end
			return i + 4
		end,
		["const std::vector<const char*>&"] = function(buf, arg, i, _)
			buf:addf("auto %s = luax_checkstringvector(L, %d);", arg.name, i)
			return i + 1
		end,
		["const std::vector<float>&"] = function(buf, arg, i, _)
			buf:addf("std::vector<float> %s = luax_checkfloatvector(L, %d);", arg.name, i)
			return i+1
		end,
		["ImGuiInputTextCallback"] = function(buf, arg, i, _)
			local name = arg.name
			buf:addf("ImGuiInputTextCallback %s = callLuaInputTextCallback;", name)
			buf:addf("void* user_data = luax_getImguiInputTextCallback(L, %d);", i)
			buf:addf("if (!user_data) { %s = nullptr; }", name)
		end,

		["ImGuiDir"] = enum_arg("ImGuiDir", "getImGuiDirFromString"),
		["ImGuiCol"] = enum_arg("ImGuiCol", "getImGuiColFromString"),
		["ImGuiMouseCursor"] = enum_arg("ImGuiMouseCursor", "getImGuiMouseCursorFromString"),
		["ImGuiMouseButton"] = enum_arg("ImGuiMouseButton", "getImGuiMouseButtonFromString"),
		["ImGuiCond"] = enum_arg("ImGuiCond", "getImGuiCondFromString"),
		["ImGuiStyleVar"] = enum_arg("ImGuiStyleVar", "getImGuiStyleVarFromString"),
		["ImGuiKey"] = enum_arg("ImGuiKey", "getImGuiKeyFromString"),
		["ImDrawCornerFlags"] = enum_arg("ImDrawCornerFlags", "getImDrawCornerFlagsFromString"),

		["ImGuiWindowFlags"] = flags_arg("ImGuiWindowFlags", "getImGuiWindowFlagsFromString"),
		["ImGuiFocusedFlags"] = flags_arg("ImGuiFocusedFlags", "getImGuiFocusedFlagsFromString"),
		["ImGuiHoveredFlags"] = flags_arg("ImGuiFocusedFlags", "getImGuiFocusedFlagsFromString"),
		["ImGuiComboFlags"] = flags_arg("ImGuiComboFlags", "getImGuiComboFlagsFromString"),
		["ImGuiInputTextFlags"] = flags_arg("ImGuiInputTextFlags", "getImGuiInputTextFlagsFromString"),
		["ImGuiColorEditFlags"] = flags_arg("ImGuiColorEditFlags", "getImGuiColorEditFlagsFromString"),
		["ImGuiTreeNodeFlags"] = flags_arg("ImGuiTreeNodeFlags", "getImGuiTreeNodeFlagsFromString"),
		["ImGuiSelectableFlags"] = flags_arg("ImGuiSelectableFlags", "getImGuiSelectableFlagsFromString"),
		["ImGuiTabBarFlags"] = flags_arg("ImGuiTabBarFlags", "getImGuiTabBarFlagsFromString"),
		["ImGuiTabItemFlags"] = flags_arg("ImGuiTabItemFlags", "getImGuiTabItemFlagsFromString"),
		["ImGuiDragDropFlags"] = flags_arg("ImGuiDragDropFlags", "getImGuiDragDropFlagsFromString"),
		["ImGuiDockNodeFlags"] = flags_arg("ImGuiDockNodeFlags", "getImGuiDockNodeFlagsFromString"),

		-- TODO
		["ImFontAtlas*"] = skip_arg(),
		["ImGuiViewport*"] = skip_arg(),
		["const ImGuiWindowClass*"] = skip_arg(),
		["noop"] = function(_, _, i)
			return i
		end,

		-- edit input
		["bool*"] = simple_out_arg("bool", "luax_checkboolean", "luax_optboolean"),
		["int*"] = simple_out_arg("int", "luaL_checkint", "luaL_optint"),
		["double*"] = simple_out_arg("double", "luaL_checknumber", "luaL_optnumber"),
		["unsigned int*"] = static_cast_out_arg("unsigned int", "luaL_checkint", "luaL_optint"),
		["float*"] = static_cast_out_arg("float", "luaL_checknumber", "luaL_optnumber"),
		["std::string*"] = simple_out_arg("std::string", "luaL_checkstring", "luaL_optstring"),
		["int[2]"] = array_out_arg(2, "int", "luaL_checkint"),
		["int[3]"] = array_out_arg(3, "int", "luaL_checkint"),
		["int[4]"] = array_out_arg(4, "int", "luaL_checkint"),
		["float[2]"] = array_out_arg(2, "float", "luaL_checknumber"),
		["float[3]"] = array_out_arg(3, "float", "luaL_checknumber"),
		["float[4]"] = array_out_arg(4, "float", "luaL_checknumber"),
	}
	typeCheckers["ImVec2"] = typeCheckers["const ImVec2&"]
	local unrecognizedCheckType = {}
	function Types.check(buf, arg, i, outParams)
		local ctype = arg.type
		if typeCheckers[ctype] then
			return typeCheckers[ctype](buf, arg, i, outParams)
		end

		-- failure
		if not unrecognizedCheckType[ctype] then
			util.logf("unrecognized type: %s", ctype)
			unrecognizedCheckType[ctype] = true
		end
		return i, "stop"
	end
end

do
	-- Push return types
	local function simple_return(pusher)
		return function(buf, name, i)
			buf:addf("%s(L, %s);", pusher, name)
			return i + 1
		end
	end
	local function enum_return(stringFromEnum)
		return function(buf, name, i)
			buf:addf("lua_pushstring(L, %s(%s));", stringFromEnum, name)
			return i + 1
		end
	end
	local function udata_return(cppClass, luaClass)
		return function(buf, name, i)
			-- TODO: could we cache this userdata off somehow?
			buf:addf("auto* %s_udata = static_cast<%s*>(lua_newuserdata(L, sizeof(%s)));", name, cppClass, cppClass)
			buf:addf("%s_udata->value = %s;", name, name)
			buf:addf("%s_udata->init();", name)
			buf:addf("luaL_getmetatable(L, %q);", luaClass)
			buf:add("lua_setmetatable(L, -2);")
			return i + 1
		end
	end
	local typePushers = {
		["bool"] = simple_return("lua_pushboolean"),
		["int"] = simple_return("lua_pushinteger"),
		["unsigned int"] = simple_return("lua_pushinteger"),
		["ImU32"] = simple_return("lua_pushinteger"),
		["ImGuiID"] = simple_return("lua_pushinteger"),
		["float"] = simple_return("lua_pushnumber"),
		["double"] = simple_return("lua_pushnumber"),
		["const char*"] = simple_return("lua_pushstring"),
		["ImGuiContext*"] = simple_return("lua_pushlightuserdata"),
		["ImDrawList*"] = udata_return("WrapImDrawList", "ImDrawList"),
		["ImGuiStyle&"] = function(buf, name, i)
			buf:addf("lua_pushlightuserdata(L, &%s);", name)
			return i + 1
		end,
		["ImGuiMouseCursor"] = enum_return("getStringFromImGuiMouseCursor"),
		-- custom
		["std::string"] = function(buf, name, i)
			buf:addf("lua_pushlstring(L, %s.c_str(), %s.size());", name, name)
			return i + 1
		end,
		["ImVec2"] = function(buf, name, i)
			buf:addf("lua_pushnumber(L, %s.x);", name)
			buf:addf("lua_pushnumber(L, %s.y);", name)
			return i + 2
		end,
		["ImVec4"] = function(buf, name, i)
			buf:addf("lua_pushnumber(L, %s.x);", name)
			buf:addf("lua_pushnumber(L, %s.y);", name)
			buf:addf("lua_pushnumber(L, %s.z);", name)
			buf:addf("lua_pushnumber(L, %s.w);", name)
			return i + 2
		end,
		["const ImVec4&"] = function(buf, name, i)
			buf:addf("lua_pushnumber(L, %s.x);", name)
			buf:addf("lua_pushnumber(L, %s.y);", name)
			buf:addf("lua_pushnumber(L, %s.z);", name)
			buf:addf("lua_pushnumber(L, %s.w);", name)
			return i + 2
		end,
	}
	local unrecognizedReturnType = {}
	function Types.push(buf, name, ctype, i)
		if typePushers[ctype] then
			return typePushers[ctype](buf, name, i)
		else
			if not unrecognizedReturnType[ctype] then
				util.logf("unrecognized return type: %s", ctype)
				unrecognizedReturnType[ctype] = true
			end
			return i, "stop"
		end
	end
end

return Types
