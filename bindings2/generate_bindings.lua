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

function helpers.genFunctionWrapper(imgui, fnData)
	local qualifiedName = fnData.qualifiedName
	local cname = "w_" .. fnData.name
	if imgui.functionOverrides[qualifiedName] then
		for index, iData in ipairs(imgui.functionOverrides[qualifiedName]) do
			if iData == fnData then
				cname = cname .. "_Override" .. index
				break
			end
		end
	end

	local buf = Buffer.new(0)
	local stop

	if fnData.comment then
		buf:addf("/* %s */", fnData.comment)
	end
	buf:addf("static int %s(lua_State *L)", cname)
	buf:add("{") buf:indent() do
		-- arguments
		local argnames = {}
		local outParams = {}
		local lua_arg = 1

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

		for _, arg in ipairs(fnData.arguments) do
			lua_arg, stop = Types.check(buf, arg, lua_arg, outParams)
			if stop then
				return string.format("// skipping %s due to unimplemented argument type: %q", qualifiedName, arg.type)
			end

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
		buf:add("")
		if fnData.returnType == "void" then
			buf:addf("%s(%s);", qualifiedName, argnames)
		else
			buf:addf("%s out = %s(%s);", fnData.returnType, qualifiedName, argnames)
			table.insert(outParams, {"out", fnData.returnType})
		end
		buf:add("")

		-- out
		local outArg = 0
		for _, param in ipairs(outParams) do
			local name, ctype = unpack(param)
			outArg, stop = Types.push(buf, name, ctype, outArg)
			if stop then
				return string.format("// skipping %s due to unimplemented return type: %q", qualifiedName, fnData.returnType)
			end
		end

		buf:addf("return %d;", outArg)

		-- output
	end buf:unindent() buf:add("}")

	table.insert(imgui.validFunctions, fnData)
	return buf:done()
end

function helpers.cleanValidFunctions(imgui)
	local exists = {}
	for index = #imgui.validFunctions, 1, -1 do
		local name = imgui.validFunctions[index].name
		if exists[name] then
			table.remove(imgui.validFunctions, index)
		else
			exists[name] = true
		end
	end
end

function helpers.removeValidFunction(imgui, toRemove)
	for index = #imgui.validFunctions, 1, -1 do
		if imgui.validFunctions[index].name == toRemove then
			table.remove(imgui.validFunctions, index)
		end
	end
end

function helpers.addValidFunctions(imgui, ...)
	for i = 1, select('#', ...) do
		local name = select(i, ...)
		table.insert(imgui.validFunctions, {name = name})
	end
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
	local imgui = Parse.parseHeaders{"src/libimgui/imgui.h", "src/libimgui/misc/cpp/imgui_stdlib.h"}
	imgui.validFunctions = {}
	generateFile("src/wrap_imgui_codegen.cpp", "bindings2/wrap_imgui_codegen.cpp", imgui)
	generateFile("src/wrap_imgui_codegen.h",  "bindings2/wrap_imgui_codegen.h", imgui)
	util.logf("%d functions implemented, %d functions unimplemented", #imgui.validFunctions, #imgui.functions - #imgui.validFunctions)
end

main(...)
