--[[
  Generates a set of CPP binding functions for use in love-imgui
]]

local Parse = require 'bindings2.parse'
local Types = require 'bindings2.types'
local etlua = require 'bindings2.etlua'
local util = require 'bindings2.util'

local Buffer = {}
local Buffer_mt = {__index = Buffer}
function Buffer.new(indent)
	local obj = setmetatable({indentL=indent, data={}}, Buffer_mt)
	return obj
end

function Buffer:indent(amount)
	self.indentL = self.indentL + (amount or 1)
end

function Buffer:unindent(amount)
	self:indent(amount and -amount or -1)
end

function Buffer:add(s)
	local indent = string.rep("\t", self.indentL)
	table.insert(self.data, indent .. s)
end

function Buffer:addf(f, ...)
	self:add(string.format(f, ...))
end

function Buffer:done()
	return table.concat(self.data, "\n")
end

local helpers = {}

function helpers.genEnumFromString(_, enumData)
	local buf = Buffer.new(0)
	local cleanName = enumData.name:gsub("%_+$", "")
	buf:addf("std::optional<%s> get%sFromString(const char* in)", enumData.name, cleanName)
	do buf:add("{") buf:indent()
		for valueName, valueData in pairs(enumData.values) do
			buf:addf("if (strcmp(in, %q) == 0) { return %s; }", valueName, valueData.cname)
		end
		buf:add("return std::nullopt;")
	end buf:unindent() buf:add("}")

	buf:addf("const char* getStringFrom%s(%s in)", cleanName, cleanName)
	do buf:add("{") buf:indent()
		buf:add("switch (in) {") buf:indent()
		for valueName, valueData in pairs(enumData.values) do
			if not tostring(valueData.value):match("%a") then
				buf:addf("case %s: return %q;", valueData.value, valueName)
			else
				buf:addf("// skipping // case %s: return %q;", valueData.value, valueName)
			end
		end
		buf:unindent() buf:add("}")
		buf:add("return \"\";")
	end buf:unindent() buf:add("}")

	return buf:done()
end

function helpers.genFunctionWrapper(fnElement, fnData)
	local qualifiedName = fnData.qualifiedName
	local cname = "w_" .. fnData.name

	if fnData.class then
		cname = "w_" .. fnData.class .. "_" .. fnData.name
	end

	if fnElement.overrides[qualifiedName] then
		for index, iData in ipairs(fnElement.overrides[qualifiedName]) do
			if iData == fnData then
				cname = cname .. "_Override" .. index
				break
			end
		end
	elseif fnElement.validNames[fnData.name] then
		return string.format("// skipping %s: already implemented", cname)
	end

	local buf = Buffer.new(0)
	local stop

	if fnData.comment then
		buf:addf("/* %s */", fnData.comment)
	end
	buf:addf("int %s(lua_State *L)", cname)
	buf:add("{") buf:indent() do
		-- arguments
		local argnames = {}
		local outParams = {}

		for i = #fnData.arguments, 1, -1 do
			local arg = fnData.arguments[i]
			if arg.type == "size_t" and i ~= 1 then
				-- assume previous arg is a buffer
				fnData.arguments[i-1].extraArgs = {arg}
				fnData.arguments[i-1].type = "(TODO) const buf*"
				table.remove(fnData.arguments, i)
			elseif arg.name == "fmt" and fnData.isVarargs then
				-- assume format string
				-- insert dummy format string, we'll be using lua's instead
				arg.preArgs = {{name = '"%s"'}}
				arg.type = "const fmt*"
			elseif arg.name == "user_data" and arg.type == "void*" then
				-- this is callback data, we need to reserve that for the callback generator
				arg.type = "noop"
			end
		end

		local lua_arg = 1
		if fnData.class then
			buf:addf("auto* self_udata = static_cast<Wrap%s*>(luaL_checkudata(L, 1, %q));", fnData.class, fnData.class)
			buf:add("if (!self_udata->isValid()) { luaL_error(L, \"Expired userdata\"); }")
			buf:add("auto* self = self_udata->value;")
			lua_arg = 2
		end

		local atLeastOneArgument = false
		for _, arg in ipairs(fnData.arguments) do
			lua_arg, stop = Types.check(buf, arg, lua_arg, outParams)
			if stop then
				helpers.addInvalidFunctions(fnElement, fnData.name)
				return string.format("// skipping %s due to unimplemented argument type: %q", cname, arg.type)
			end
			atLeastOneArgument = true

			if arg.preArgs then
				for _, preArg in ipairs(arg.preArgs) do
					table.insert(argnames, preArg.name)
				end
			end

			if arg.type:match("%*$") and arg.isOutParam then
				table.insert(argnames, "&" .. arg.name)
			else
				table.insert(argnames, arg.name)
			end

			if arg.extraArgs then
				for _, extraArg in ipairs(arg.extraArgs) do
					table.insert(argnames, extraArg.name)
				end
			end
		end
		argnames = table.concat(argnames, ", ")

		-- call
		if atLeastOneArgument then buf:add("") end
		local callname = qualifiedName
		if fnData.class then
			callname = "self->"..fnData.name
		end
		if fnData.returnType == "void" then
			buf:addf("%s(%s);", callname, argnames)
		else
			buf:addf("%s out = %s(%s);", fnData.returnType, callname, argnames)
			table.insert(outParams, {"out", fnData.returnType})
		end
		buf:add("")

		-- out
		local outArg = 0
		for _, param in ipairs(outParams) do
			local name, ctype = unpack(param)
			outArg, stop = Types.push(buf, name, ctype, outArg)
			if stop then
				helpers.addInvalidFunctions(fnElement, fnData.name)
				return string.format("// skipping %s due to unimplemented return type: %q", cname, fnData.returnType)
			end
		end

		buf:addf("return %d;", outArg)

		-- output
	end buf:unindent() buf:add("}")

	helpers.addValidFunctions(fnElement, fnData.name)
	return buf:done()
end

function helpers.removeValidFunction(fnElement, toRemove)
	fnElement.validNames[toRemove] = nil
end

function helpers.addValidFunctions(fnElement, ...)
	for i = 1, select('#', ...) do
		local name = select(i, ...)
		fnElement.validNames[name] = true
		fnElement.invalidNames[name] = nil
	end
end

function helpers.addInvalidFunctions(fnElement, ...)
	for i = 1, select('#', ...) do
		local name = select(i, ...)
		if not fnElement.validNames[name] then
			fnElement.invalidNames[name] = true
		end
	end
end

function helpers.count(tbl)
	local count = 0
	for _ in pairs(tbl) do
		count = count + 1
	end
	return count
end

local function generateFile(fname, templateFname, imgui)
	util.logf("Generating %s", fname)
	local templateFile = assert(io.open(templateFname, 'r'))
	local templateString = assert(templateFile:read('*a'))

	local environment = {
		imgui = imgui,
		helpers = helpers,
	}
	setmetatable(environment, {__index = _G})
	local outputString = assert(etlua.render(templateString, environment))

	local file = assert(io.open(fname, 'w'))
	file:write(outputString)

	templateFile:close()
	file:close()
end

local function main()
	local imgui = Parse.parseHeaders{"src/libimgui/imgui.h", "src/imgui_stdlib.h"}
	generateFile("src/wrap_imgui_codegen.cpp", "bindings2/wrap_imgui_codegen.cpp", imgui)
	generateFile("src/wrap_imgui_codegen.h",  "bindings2/wrap_imgui_codegen.h", imgui)
	for elementName, fnElement in pairs(imgui.functions) do
		for name in pairs(fnElement.invalidNames) do
			util.logf("unimplemented function: %s", name)
		end
		util.logf("%s: %d functions implemented, %d functions unimplemented",
			elementName,
			helpers.count(fnElement.validNames),
			helpers.count(fnElement.invalidNames))
	end
end

main(...)
