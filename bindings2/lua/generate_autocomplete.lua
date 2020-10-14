local json = require 'bindings2.dkjson'
local util = require 'bindings2.util'

local function jsonObject(t)
	return setmetatable(t or {}, {__jsontype = "object"})
end

local function createTableType()
	return { type = 'table', fields = jsonObject() }
end

local function createFunctionType()
	return {type = 'function'}
end

local g_usedRefs = {}
local function createDataRefType(name)
	g_usedRefs[name] = createTableType()
	return {type = 'ref', name = name}
end

local function createEnumRefType(name)
	g_usedRefs[name] = { type = "string" }
	return {type = 'ref', name = name}
end

local function addFunctions(tableType, imguiFunctions)
	for name, fnData in util.sortedPairs(imguiFunctions.validNames) do
		local fn = createFunctionType()

		fn.args = {}
		fn.argTypes = {}
		if fnData.class then
			local arg = {name = "self"}
			table.insert(fn.args, arg)
			table.insert(fn.argTypes, createDataRefType(fnData.class))
		end

		if fnData.luaArgumentTypes and fnData.luaArgumentTypes[1] then
			for _, argData in ipairs(fnData.luaArgumentTypes) do
				if argData.type == 'userdata' or argData.type == 'lightuserdata' then
					table.insert(fn.argTypes, createDataRefType(argData.class))
				elseif argData.type == 'enum' or argData.type == 'flags' then
					table.insert(fn.argTypes, createEnumRefType(argData.enum))
				else
					table.insert(fn.argTypes, {type = argData.type})
				end
				local arg = {name = argData.name}
				if argData.default then
					arg.displayName = string.format("%s = %s", argData.name, argData.default)
				end
				table.insert(fn.args, arg)
			end
		end

		if fnData.isVarArgs then
			table.insert(fn.args, {name = "", displayName = "..."})
			table.insert(fn.argTypes, {type = "unknown"})
		end

		if fnData.luaReturnTypes and fnData.luaReturnTypes[1] then
			fn.returnTypes = {}
			for _, returnData in ipairs(fnData.luaReturnTypes) do
				if returnData.type == 'userdata' or returnData.type == 'lightuserdata' then
					table.insert(fn.returnTypes, createDataRefType(returnData.class))
				else
					table.insert(fn.returnTypes, {type = returnData.type})
				end
			end
		end

		if fnData.comment then
			fn.descriptionPlain = fnData.comment
		end

		if fnData.sourceFileLine then
			fn.link = util.createGithubLink(fnData.sourceFilePath, fnData.sourceFileLine)
		end

		tableType.fields[name] = fn
	end
end

local function generate(imgui)
	local data = {}
	data.global = createTableType()
	data.global.fields.ImGui = createTableType()
	addFunctions(data.global.fields.ImGui, imgui.functions.ImGui)

	data.namedTypes = {}
	data.namedTypes["ImDrawList"] = createTableType()
	addFunctions(data.namedTypes["ImDrawList"], imgui.functions.ImDrawList, "ImDrawList")

	for refName, refData in pairs(g_usedRefs) do
		if not data.namedTypes[refName] then
			data.namedTypes[refName] = refData
		end
	end

	return data
end

local helpers = {}

function helpers.generateAutocomplete(imgui)
	local keyOrder = {
		'luaVersion',
		'packagePath',
		'global',
		'namedTypes',
		'type',
		'description',
		'descriptionPlain',
		'link',
		'fields',
		'args',
		'argTypes',
		'returnTypes',
		'variants',
	}

	local api = generate(imgui)
	return json.encode(api, {indent=true, keyOrder = keyOrder})
end

return helpers
