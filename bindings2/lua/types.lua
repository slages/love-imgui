local util = require 'bindings2.util'

local Types = {}

do
	-- Check argument types
	local function simple_arg(getter, defaultGetter, luaType)
		return function(buf, fnData, arg, i)
			if arg.default then
				buf:addf("auto %s = %s(L, %d, %s);", arg.name, defaultGetter, i, arg.default)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = luaType, default = arg.default})
			else
				buf:addf("auto %s = %s(L, %d);", arg.name, getter, i)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = luaType})
			end
			return i + 1
		end
	end

	local function static_cast_arg(ctype, getter, defaultGetter, luaType)
		return function(buf, fnData, arg, i)
			if arg.default then
				buf:addf("auto %s = static_cast<%s>(%s(L, %d, %s));", arg.name, ctype, defaultGetter, i, arg.default)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = luaType, default = arg.default})
			else
				buf:addf("auto %s = static_cast<%s>(%s(L, %d));", arg.name, ctype, getter, i)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = luaType})
			end
			return i + 1
		end
	end

	local function enum_arg(ctype, fromstring)
		return function(buf, fnData, arg, i)
			if arg.default then
				buf:addf("auto %s = luax_optenum<%s>(%s, L, %d, %s);", arg.name, ctype, fromstring, i, arg.default)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = "enum", enum = ctype, default = arg.default})
			else
				buf:addf("auto %s = luax_checkenum<%s>(%s, L, %d);", arg.name, ctype, fromstring, i)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = "enum", enum = ctype})
			end
			return i + 1
		end
	end

	local function flags_arg(ctype, fromstring)
		return function(buf, fnData, arg, i)
			if arg.default then
				buf:addf("auto %s = luax_optflags<%s>(%s, L, %d, %s);", arg.name, ctype, fromstring, i, arg.default)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = "flags", enum = ctype, default = arg.default})
			else
				buf:addf("auto %s = luax_checkflags<%s>(%s, L, %d);", arg.name, ctype, fromstring, i)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = "flags", enum = ctype})
			end
			return i + 1
		end
	end

	local function skip_arg()
		return function(buf, _, arg, i)
			if arg.default then
				buf:addf("%s %s = %s; // skipping", arg.type, arg.name, arg.default)
			else
				-- unimplemented required param
				return i, "stop"
			end
			return i
		end
	end

	local function simple_out_arg(ctype, getter, defaultGetter, luaType)
		return function(buf, fnData, arg, i, outParams)
			if arg.default then
				buf:addf("%s %s = %s(L, %d, %s);", ctype, arg.name, defaultGetter, i, arg.default)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = luaType, default = arg.default})
			else
				buf:addf("%s %s = %s(L, %d);", ctype, arg.name, getter, i)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = luaType})
			end
			arg.isOutParam = true
			table.insert(outParams, {arg.name, ctype})
			return i + 1
		end
	end

	local function static_cast_out_arg(ctype, getter, defaultGetter, luaType)
		return function(buf, fnData, arg, i, outParams)
			if arg.default then
				buf:addf("auto %s = static_cast<%s>(%s(L, %d, %s));", arg.name, ctype, defaultGetter, i, arg.default)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = luaType, default = arg.default})
			else
				buf:addf("auto %s = static_cast<%s>(%s(L, %d));", arg.name, ctype, getter, i)
				table.insert(fnData.luaArgumentTypes, {name = arg.name, type = luaType})
			end
			arg.isOutParam = true
			table.insert(outParams, {arg.name, ctype})
			return i + 1
		end
	end

	local function array_out_arg(size, ctype, getter)
		return function(buf, fnData, arg, i, outParams)
			assert(not arg.default, "defaults unimplemented")
			buf:addf("%s %s[%d];", ctype, arg.name, size)
			for ai = 0, size-1 do
				local element = string.format("%s[%d]", arg.name, ai)
				buf:addf("%s = static_cast<%s>(%s(L, %d));", element, ctype, getter, i+ai)
				arg.isOutParam = true
				table.insert(outParams, {element, ctype})
			end
			table.insert(fnData.luaArgumentTypes, {name = arg.name, type = "table"})
			return i + size
		end
	end

	local function getImVecDefaults(defaultStr)
		if defaultStr == "NULL" then
			return "NULL", "NULL", "NULL", "NULL"
		end
		local o = {}
		local args = defaultStr:match("(%b())"):sub(2, -2)
		for s in args:gmatch("[^,]+") do
			table.insert(o, s)
		end
		return unpack(o)
	end

	local typeCheckers = {
		-- static input
		["const char*"] = simple_arg("luaL_checkstring", "luaL_optstring", "string"),
		["bool"] = simple_arg("luax_checkboolean", "luax_optboolean", "boolean"),
		["int"] = simple_arg("luaL_checkint", "luaL_optint", "number"),
		["double"] = simple_arg("luaL_checknumber", "luaL_optnumber", "number"),
		["ImTextureID"] = simple_arg("luax_checkTextureID", "luax_checkTextureID", "Image"),
		["ImGuiContext*"] = static_cast_arg("ImGuiContext*", "luax_checklightuserdata", "luax_optlightuserdata", "unknown"),
		["ImGuiStyle*"] = static_cast_arg("ImGuiStyle*", "luax_checklightuserdata", "luax_optlightuserdata", "unknown"),
		["unsigned int"] = static_cast_arg("unsigned int", "luaL_checklong", "luaL_optlong", "number"),
		["float"] = simple_arg("luax_checkfloat", "luax_optfloat", "number"),
		["ImU32"] = static_cast_arg("ImU32", "luaL_checklong", "luaL_optlong", "number"),
		["ImGuiID"] = static_cast_arg("ImGuiID", "luaL_checkint", "luaL_optint", "number"),
		["const fmt*"] = function(buf, fnData, arg, i)
			-- get format string
			buf:addf("auto %s = luax_formatargs(L, %s);", arg.name, i)
			table.insert(fnData.luaArgumentTypes, {name = "fmt", type = "string"})
			return i + 1
		end,
		["const ImVec2*"] = function(buf, fnData, arg, i, _)
			local name = arg.name
			if arg.default then
				local x, y = getImVecDefaults(arg.default)
				buf:addf("ImVec2* %s = %s;", name, arg.default)
				buf:addf("ImVec2 %s_buf;", name)
				buf:addf("if(!lua_isnoneornil(L, %d)) {", i+1) buf:indent()
					buf:addf("%s_buf.x = luax_checkfloat(L, %d);", name, i)
					buf:addf("%s_buf.y = luax_checkfloat(L, %d);", name, i+1)
				buf:unindent() buf:add("}")
				table.insert(fnData.luaArgumentTypes, {name = name.."_x", type = "number", default = x})
				table.insert(fnData.luaArgumentTypes, {name = name.."_y", type = "number", default = y})
				return i + 2
			else
				return i, "stop"
			end
		end,
		["const ImVec2&"] = function(buf, fnData, arg, i, _)
			local name = arg.name
			if arg.default then
				local x, y = getImVecDefaults(arg.default)
				buf:addf("auto %s = %s;", name, arg.default)
				buf:addf("%s.x = luax_optfloat(L, %d, %s.x);", name, i, name)
				buf:addf("%s.y = luax_optfloat(L, %d, %s.y);", name, i+1, name)
				table.insert(fnData.luaArgumentTypes, {name = name.."_x", type = "number", default = x})
				table.insert(fnData.luaArgumentTypes, {name = name.."_y", type = "number", default = y})
			else
				buf:addf("ImVec2 %s;", name)
				buf:addf("%s.x = luax_checkfloat(L, %d);", name, i)
				buf:addf("%s.y = luax_checkfloat(L, %d);", name, i+1)
				table.insert(fnData.luaArgumentTypes, {name = name.."_x", type = "number"})
				table.insert(fnData.luaArgumentTypes, {name = name.."_y", type = "number"})
			end
			return i+2
		end,
		["const ImVec4&"] = function(buf, fnData, arg, i, _)
			local name = arg.name
			if arg.default then
				local x, y, z, w = getImVecDefaults(arg.default)
				buf:addf("ImVec4 %s = %s;", name, arg.default)
				buf:addf("%s.x = luax_optfloat(L, %d, %s.x);", name, i, name)
				buf:addf("%s.y = luax_optfloat(L, %d, %s.y);", name, i+1, name)
				buf:addf("%s.z = luax_optfloat(L, %d, %s.z);", name, i+2, name)
				buf:addf("%s.w = luax_optfloat(L, %d, %s.w);", name, i+3, name)
				table.insert(fnData.luaArgumentTypes, {name = name.."_x", type = "number", default = x})
				table.insert(fnData.luaArgumentTypes, {name = name.."_y", type = "number", default = y})
				table.insert(fnData.luaArgumentTypes, {name = name.."_z", type = "number", default = z})
				table.insert(fnData.luaArgumentTypes, {name = name.."_w", type = "number", default = w})
			else
				buf:addf("ImVec4 %s;", name)
				buf:addf("%s.x = luax_checkfloat(L, %d);", name, i)
				buf:addf("%s.y = luax_checkfloat(L, %d);", name, i+1)
				buf:addf("%s.z = luax_checkfloat(L, %d);", name, i+2)
				buf:addf("%s.w = luax_checkfloat(L, %d);", name, i+3)
				table.insert(fnData.luaArgumentTypes, {name = name.."_x", type = "number"})
				table.insert(fnData.luaArgumentTypes, {name = name.."_y", type = "number"})
				table.insert(fnData.luaArgumentTypes, {name = name.."_z", type = "number"})
				table.insert(fnData.luaArgumentTypes, {name = name.."_w", type = "number"})
			end
			return i + 4
		end,
		["const std::vector<const char*>&"] = function(buf, fnData, arg, i, _)
			buf:addf("auto %s = luax_checkstringvector(L, %d);", arg.name, i)
			table.insert(fnData.luaArgumentTypes, {name = arg.name, type = "table"})
			return i + 1
		end,
		["const std::vector<float>&"] = function(buf, fnData, arg, i, _)
			buf:addf("std::vector<float> %s = luax_checkfloatvector(L, %d);", arg.name, i)
			table.insert(fnData.luaArgumentTypes, {name = arg.name, type = "table"})
			return i+1
		end,
		["ImGuiInputTextCallback"] = function(buf, fnData, arg, i, _)
			local name = arg.name
			buf:addf("ImGuiInputTextCallback %s = callLuaInputTextCallback;", name)
			buf:addf("void* user_data = luax_getImguiInputTextCallback(L, %d);", i)
			buf:addf("if (!user_data) { %s = nullptr; }", name)
			table.insert(fnData.luaArgumentTypes, {name = arg.name, type = "function"})
		end,

		-- TODO
		["ImFontAtlas*"] = skip_arg(),
		["ImGuiViewport*"] = skip_arg(),
		["const ImGuiWindowClass*"] = skip_arg(),
		["noop"] = function(_, _, _, i)
			return i
		end,

		-- edit input
		["bool*"] = simple_out_arg("bool", "luax_checkboolean", "luax_optboolean", "boolean"),
		["int*"] = simple_out_arg("int", "luaL_checkint", "luaL_optint", "number"),
		["double*"] = simple_out_arg("double", "luaL_checknumber", "luaL_optnumber", "number"),
		["unsigned int*"] = static_cast_out_arg("unsigned int", "luaL_checkint", "luaL_optint", "number"),
		["float*"] = static_cast_out_arg("float", "luaL_checknumber", "luaL_optnumber", "number"),
		["std::string*"] = simple_out_arg("std::string", "luaL_checkstring", "luaL_optstring", "string"),
		["int[2]"] = array_out_arg(2, "int", "luaL_checkint"),
		["int[3]"] = array_out_arg(3, "int", "luaL_checkint"),
		["int[4]"] = array_out_arg(4, "int", "luaL_checkint"),
		["float[2]"] = array_out_arg(2, "float", "luaL_checknumber"),
		["float[3]"] = array_out_arg(3, "float", "luaL_checknumber"),
		["float[4]"] = array_out_arg(4, "float", "luaL_checknumber"),
	}
	typeCheckers["ImVec2"] = typeCheckers["const ImVec2&"]
	local unrecognizedCheckType = {}
	function Types.check(buf, fnData, arg, i, outParams)
		local ctype = arg.type
		if typeCheckers[ctype] then
			return typeCheckers[ctype](buf, fnData, arg, i, outParams)
		end

		-- failure
		if not unrecognizedCheckType[ctype] then
			util.logf("unrecognized type: %s", ctype)
			unrecognizedCheckType[ctype] = true
		end
		return i, "stop"
	end

	function Types.generateTypeCheckers(imgui)
		for _, enumData in ipairs(imgui.enums) do
			local cleanName = enumData.name:gsub("%_+$", "")
			local getter = ("get%sFromString"):format(cleanName)
			if cleanName:match("Flags$") then
				typeCheckers[cleanName] = flags_arg(cleanName, getter)
			else
				typeCheckers[cleanName] = enum_arg(cleanName, getter)
			end
		end
	end
end

do
	-- Push return types
	local function simple_return(pusher, luaType)
		return function(buf, fnData, name, i)
			buf:addf("%s(L, %s);", pusher, name)
			table.insert(fnData.luaReturnTypes, { name = name, type = luaType })
			return i + 1
		end
	end
	local function enum_return(enumName, stringFromEnum)
		return function(buf, fnData, name, i)
			buf:addf("lua_pushstring(L, %s(%s));", stringFromEnum, name)
			table.insert(fnData.luaReturnTypes, { name = name, type = "string", enum = enumName })
			return i + 1
		end
	end
	local function udata_return(cppClass, luaClass)
		return function(buf, fnData, name, i)
			-- TODO: could we cache this userdata off somehow?
			buf:addf("auto* %s_udata = static_cast<%s*>(lua_newuserdata(L, sizeof(%s)));", name, cppClass, cppClass)
			buf:addf("%s_udata->value = %s;", name, name)
			buf:addf("%s_udata->init();", name)
			buf:addf("luaL_getmetatable(L, %q);", luaClass)
			buf:add("lua_setmetatable(L, -2);")
			table.insert(fnData.luaReturnTypes, { name = name, type = "userdata", class = luaClass })
			return i + 1
		end
	end
	local typePushers = {
		["bool"] = simple_return("lua_pushboolean", "boolean"),
		["int"] = simple_return("lua_pushinteger", "number"),
		["unsigned int"] = simple_return("lua_pushinteger", "number"),
		["ImU32"] = simple_return("lua_pushinteger", "number"),
		["ImGuiID"] = simple_return("lua_pushinteger", "number"),
		["float"] = simple_return("lua_pushnumber", "number"),
		["double"] = simple_return("lua_pushnumber", "number"),
		["const char*"] = simple_return("lua_pushstring", "number"),
		["ImGuiContext*"] = function(buf, fnData, name, i)
			buf:addf("lua_pushlightuserdata(L, %s);", name)
			table.insert(fnData.luaReturnTypes, { name = name, type = "lightuserdata", class = "ImGuiContext" })
			return i + 1
		end,
		["ImDrawList*"] = udata_return("WrapImDrawList", "ImDrawList"),
		["ImGuiStyle&"] = function(buf, fnData, name, i)
			buf:addf("lua_pushlightuserdata(L, &%s);", name)
			table.insert(fnData.luaReturnTypes, { name = name, type = "lightuserdata", class = "ImGuiStyle" })
			return i + 1
		end,
		["ImGuiMouseCursor"] = enum_return("ImGuiMouseCursor", "getStringFromImGuiMouseCursor"),
		-- custom
		["std::string"] = function(buf, fnData, name, i)
			buf:addf("lua_pushlstring(L, %s.c_str(), %s.size());", name, name)
			table.insert(fnData.luaReturnTypes, { name = name, type = "string" })
			return i + 1
		end,
		["ImVec2"] = function(buf, fnData, name, i)
			buf:addf("lua_pushnumber(L, %s.x);", name)
			buf:addf("lua_pushnumber(L, %s.y);", name)
			table.insert(fnData.luaReturnTypes, { name = name.."_x", type = "number" })
			table.insert(fnData.luaReturnTypes, { name = name.."_y", type = "number" })
			return i + 2
		end,
		["ImVec4"] = function(buf, fnData, name, i)
			buf:addf("lua_pushnumber(L, %s.x);", name)
			buf:addf("lua_pushnumber(L, %s.y);", name)
			buf:addf("lua_pushnumber(L, %s.z);", name)
			buf:addf("lua_pushnumber(L, %s.w);", name)
			table.insert(fnData.luaReturnTypes, { name = name.."_x", type = "number" })
			table.insert(fnData.luaReturnTypes, { name = name.."_y", type = "number" })
			table.insert(fnData.luaReturnTypes, { name = name.."_z", type = "number" })
			table.insert(fnData.luaReturnTypes, { name = name.."_w", type = "number" })
			return i + 4
		end,
		["const ImVec4&"] = function(buf, fnData, name, i)
			buf:addf("lua_pushnumber(L, %s.x);", name)
			buf:addf("lua_pushnumber(L, %s.y);", name)
			buf:addf("lua_pushnumber(L, %s.z);", name)
			buf:addf("lua_pushnumber(L, %s.w);", name)
			table.insert(fnData.luaReturnTypes, { name = name.."_x", type = "number" })
			table.insert(fnData.luaReturnTypes, { name = name.."_y", type = "number" })
			table.insert(fnData.luaReturnTypes, { name = name.."_z", type = "number" })
			table.insert(fnData.luaReturnTypes, { name = name.."_w", type = "number" })
			return i + 4
		end,
	}
	local unrecognizedReturnType = {}
	function Types.push(buf, fnData, name, ctype, i)
		if typePushers[ctype] then
			return typePushers[ctype](buf, fnData, name, i)
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
