local util = require 'bindings2.util'

local Types = {}

do
	-- Check argument types
	local function simple_arg(getter, defaultGetter)
		return function(buf, name, default, i)
			if default then
				buf:addf("auto %s = %s(L, %d, %s);", name, defaultGetter, i, default)
			else
				buf:addf("auto %s = %s(L, %d);", name, getter, i)
			end
			return i + 1
		end
	end

	local function static_cast_arg(ctype, getter, defaultGetter)
		return function(buf, name, default, i)
			if default then
				buf:addf("auto %s = static_cast<%s>(%s(L, %d, %s));", name, ctype, defaultGetter, i, default)
			else
				buf:addf("auto %s = static_cast<%s>(%s(L, %d));", name, ctype, getter, i)
			end
			return i + 1
		end
	end

	local function enum_arg(ctype, fromstring)
		return function(buf, name, default, i)
			if default then
				buf:addf("auto %s = luax_optenum<%s>(%s, L, %d, %s);", name, ctype, fromstring, i, default)
			else
				buf:addf("auto %s = luax_checkenum<%s>(%s, L, %d);", name, ctype, fromstring, i)
			end
			return i + 1
		end
	end

	local function flags_arg(ctype, fromstring)
		return function(buf, name, default, i)
			if default then
				buf:addf("auto %s = luax_optflags<%s>(%s, L, %d, %s);", name, ctype, fromstring, i, default)
			else
				buf:addf("auto %s = luax_checkflags<%s>(%s, L, %d);", name, ctype, fromstring, i)
			end
			return i + 1
		end
	end

	local function simple_out_arg(ctype, getter, defaultGetter)
		return function(buf, name, default, i, outParams)
			if default then
				buf:addf("auto %s = %s(L, %d, %s);", name, defaultGetter, i, default)
			else
				buf:addf("auto %s = %s(L, %d);", name, getter, i)
			end
			table.insert(outParams, {name, ctype})
			return i + 1
		end
	end

	local function static_cast_out_arg(ctype, getter, defaultGetter)
		return function(buf, name, default, i, outParams)
			if default then
				buf:addf("auto %s = static_cast<%s>(%s(L, %d, %s));", name, ctype, defaultGetter, i, default)
			else
				buf:addf("auto %s = static_cast<%s>(%s(L, %d));", name, ctype, getter, i)
			end
			table.insert(outParams, {name, ctype})
			return i + 1
		end
	end

	local function array_out_arg(size, ctype, getter)
		return function(buf, name, default, i, outParams)
			assert(not default, "defaults unimplemented")
			buf:addf("%s %s[%d];", ctype, name, size)
			for ai = 0, size-1 do
				local element = string.format("%s[%d]", name, ai)
				buf:addf("%s = static_cast<%s>(%s(L, %d));", element, ctype, getter, i+ai)
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
		["unsigned int"] = static_cast_arg("unsigned int", "luaL_checklong", "luaL_optlong"),
		["float"] = static_cast_arg("float", "luaL_checknumber", "luaL_optnumber"),
		["ImU32"] = static_cast_arg("unsigned int", "luaL_checklong", "luaL_optlong"),
		["ImGuiID"] = static_cast_arg("ImGuiID", "luaL_checkint", "luaL_optint"),
		["const ImVec2&"] = function(buf, name, default, i, _)
			if default then
				buf:addf("auto %s = %s;", name, default)
				buf:addf("%s.x = luaL_optnumber(L, %d, %s.x);", name, i, name)
				buf:addf("%s.y = luaL_optnumber(L, %d, %s.y);", name, i+1, name)
			else
				buf:addf("ImVec2 %s;", name)
				buf:addf("%s.x = luaL_checknumber(L, %d);", name, i)
				buf:addf("%s.y = luaL_checknumber(L, %d);", name, i+1)
			end
			return i+2
		end,
		["const ImVec4&"] = function(buf, name, default, i, _)
			if default then
				buf:addf("ImVec4 %s = %s;", name, default)
				buf:addf("%s.x = luaL_optnumber(L, %d, %s.x);", name, i, name)
				buf:addf("%s.y = luaL_optnumber(L, %d, %s.y);", name, i+1, name)
				buf:addf("%s.z = luaL_optnumber(L, %d, %s.z);", name, i+1, name)
				buf:addf("%s.w = luaL_optnumber(L, %d, %s.w);", name, i+1, name)
			else
				buf:addf("ImVec4 %s;", name)
				buf:addf("%s.x = luaL_checknumber(L, %d);", name, i)
				buf:addf("%s.y = luaL_checknumber(L, %d);", name, i+1)
				buf:addf("%s.z = luaL_checknumber(L, %d);", name, i+1)
				buf:addf("%s.w = luaL_checknumber(L, %d);", name, i+1)
			end
			return i+4
		end,
		["ImGuiDir"] = enum_arg("ImGuiDir", "getImGuiDirFromString"),
		["ImGuiCol"] = enum_arg("ImGuiCol", "getImGuiColFromString"),
		["ImGuiMouseCursor"] = enum_arg("ImGuiMouseCursor", "getImGuiMouseCursorFromString"),
		["ImGuiMouseButton"] = enum_arg("ImGuiMouseButton", "getImGuiMouseButtonFromString"),
		["ImGuiCond"] = enum_arg("ImGuiCond", "getImGuiCondFromString"),
		["ImGuiStyleVar"] = enum_arg("ImGuiStyleVar", "getImGuiStyleVarFromString"),
		["ImGuiKey"] = enum_arg("ImGuiKey", "getImGuiKeyFromString"),

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
		-- edit input
		["bool*"] = simple_out_arg("bool", "luax_checkboolean", "luax_optboolean"),
		["int*"] = simple_out_arg("int", "luaL_checkint", "luaL_optint"),
		["double*"] = simple_out_arg("double", "luaL_checknumber", "luaL_optnumber"),
		["unsigned int*"] = static_cast_out_arg("unsigned int", "luaL_checkint", "luaL_optint"),
		["float*"] = static_cast_out_arg("float", "luaL_checknumber", "luaL_optnumber"),
		["int[2]"] = array_out_arg(2, "int", "luaL_checkint"),
		["int[3]"] = array_out_arg(3, "int", "luaL_checkint"),
		["int[4]"] = array_out_arg(4, "int", "luaL_checkint"),
		["float[2]"] = array_out_arg(2, "float", "luaL_checknumber"),
		["float[3]"] = array_out_arg(3, "float", "luaL_checknumber"),
		["float[4]"] = array_out_arg(4, "float", "luaL_checknumber"),
	}
	typeCheckers["ImVec2"] = typeCheckers["const ImVec2&"]
	local unrecognizedCheckType = {}
	function Types.check(buf, name, ctype, default, i, outParams)
		if typeCheckers[ctype] then
			return typeCheckers[ctype](buf, name, default, i, outParams)
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
	local typePushers = {
		["bool"] = simple_return("lua_pushboolean"),
		["int"] = simple_return("lua_pushinteger"),
		["unsigned int"] = simple_return("lua_pushinteger"),
		["ImU32"] = simple_return("lua_pushinteger"),
		["ImGuiID"] = simple_return("lua_pushinteger"),
		["float"] = simple_return("lua_pushnumber"),
		["double"] = simple_return("lua_pushnumber"),
		["const char*"] = simple_return("lua_pushstring"),
		-- custom
		["ImVec2"] = function(buf, name, i)
			buf:addf("lua_pushnumber(L, %s.x);", name)
			buf:addf("lua_pushnumber(L, %s.y);", name)
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
