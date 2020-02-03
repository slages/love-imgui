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
	return buf:done()
end

function helpers.genFunctionWrapper(imgui, fnData)
	local qualifiedName = fnData.namespace .. "::" .. fnData.name
	local cname = "w_" .. fnData.name
	while imgui.functionNames[cname] do
		cname = cname .. "_EX"
	end

	if fnData.isVarargs then
		return string.format("// skipping function due to having variable arguments: %s", qualifiedName)
	end

	local buf = Buffer.new(0)
	local stop

	buf:addf("static int %s(lua_State *L)", cname)
	buf:add("{") buf:indent() do
		-- arguments
		local argnames = {}
		local outParams = {}
		local lua_arg = 1
		for _, arg in ipairs(fnData.arguments) do
			lua_arg, stop = Types.check(buf, arg.name, arg.type, arg.default, lua_arg, outParams)
			if stop then
				return string.format("// skipping function due to unimplemented argument type %q: %s", arg.type, qualifiedName)
			end

			if arg.type:match("%*$") and not arg.type:match("char%*$") then
				table.insert(argnames, "&" .. arg.name)
			else
				table.insert(argnames, arg.name)
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
				return string.format("// skipping function due to unimplemented return type %q: %s", fnData.returnType, qualifiedName)
			end
		end

		buf:addf("return %d;", outArg)

		-- output
	end buf:unindent() buf:add("}")

	imgui.functionNames[cname] = fnData
	table.insert(imgui.validFunctions, fnData)
	return buf:done()
end

local function generateFile(fname, templateFname, imgui)
	util.logf("Generating %s", fname)
	local templateFile = assert(io.open(templateFname, 'r'))
	local templateString = assert(templateFile:read('*a'))

	imgui.functionNames = {}
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
	local imgui = Parse.parseHeader("src/libimgui/imgui.h")
	imgui.validFunctions = {}
	generateFile("src/wrap_imgui_codegen.cpp", "bindings2/wrap_imgui_codegen.cpp", imgui)
	generateFile("src/wrap_imgui_codegen.h",  "bindings2/wrap_imgui_codegen.h", imgui)
	util.logf("%d functions implemented, %d functions unimplemented", #imgui.validFunctions, #imgui.functions - #imgui.validFunctions)
end

main(...)
