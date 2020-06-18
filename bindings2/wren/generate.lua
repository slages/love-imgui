local util = require 'bindings2.util'
local Buffer = require 'bindings2.buffer'
local Types = require 'bindings2.wren.types'
local etlua = require 'bindings2.etlua'

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

	local isOverride = false
	if fnElement.overrides[qualifiedName] then
		for index, iData in ipairs(fnElement.overrides[qualifiedName]) do
			if iData == fnData then
				cname = cname .. "_Override" .. index
				isOverride = true
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
	buf:addf("void %s(WrenVM *vm)", cname)
	buf:add("{") buf:indent() do
		-- arguments
		local realargs = {}
		local docargs = {}

		for i = #fnData.arguments, 1, -1 do
			local arg = fnData.arguments[i]
			if arg.type == "size_t" and i ~= 1 then
				-- assume previous arg is a buffer
				fnData.arguments[i-1].extraArgs = {arg}
				fnData.arguments[i-1].type = "(TODO) const buf*"
				table.remove(fnData.arguments, i)
			elseif arg.name == "user_data" and arg.type == "void*" then
				-- this is callback data, we need to reserve that for the callback generator
				arg.type = "noop"
			end
		end

		local lua_arg = 1
		if fnData.class then
			--buf:addf("auto* self_udata = static_cast<Wrap%s*>(luaL_checkudata(L, 1, %q));", fnData.class, fnData.class)
			--buf:add("if (!self_udata->isValid()) { luaL_error(L, \"Expired userdata\"); }")
			--buf:add("auto* self = self_udata->value;")
			--lua_arg = 2
			return string.format("// skipping %s due to unimplemented foreign class type: %q", cname, fnData.class)
		end

		local atLeastOneArgument = false
		local outLines = {}
		local arity = 0
		local requiredArity = 0
		for _, arg in ipairs(fnData.arguments) do
			lua_arg, stop = Types.check(buf, arg, lua_arg, outLines)
			if stop then
				helpers.addInvalidFunctions(fnElement, fnData.name)
				return string.format("// skipping %s due to unimplemented argument type: %q", cname, arg.type)
			end
			atLeastOneArgument = true

			if arg.preArgs then
				for _, preArg in ipairs(arg.preArgs) do
					table.insert(realargs, preArg.name)
					table.insert(docargs, preArg.name)
				end
			end

			if arg.type:match("%*$") and arg.isOutParam then
				table.insert(realargs, "&" .. arg.name)
			else
				table.insert(realargs, arg.name)
			end
			if arg.name == "in" then
				table.insert(docargs, "input") -- `in` is a keyword in wren
			else
				table.insert(docargs, arg.name)
			end
			arity = arity + 1
			if not arg.default then
				requiredArity = requiredArity + 1
			end

			if arg.extraArgs then
				for _, extraArg in ipairs(arg.extraArgs) do
					table.insert(realargs, extraArg.name)
					table.insert(docargs, extraArg.name)
				end
			end
		end
		realargs = table.concat(realargs, ", ")
		fnData.docArgs = docargs

		-- call
		if atLeastOneArgument then buf:add("") end
		local callname = qualifiedName
		if fnData.class then
			callname = "self->"..fnData.name
		end
		if fnData.returnType == "void" then
			buf:addf("%s(%s);", callname, realargs)
		else
			buf:addf("%s out = %s(%s);", fnData.returnType, callname, realargs)
			local name = "out"
			local ctype = fnData.returnType
			local _
			_, stop = Types.push(buf, name, ctype, 0)
			if stop then
				helpers.addInvalidFunctions(fnElement, fnData.name)
				return string.format("// skipping %s due to unimplemented return type: %q", cname, fnData.returnType)
			end
		end
		buf:add("")
		fnData.signature = ("%s(%s)"):format(fnData.name, docargs)
		fnData.arity = arity
		fnData.requiredArity = requiredArity

		-- out
		for _, line in ipairs(outLines) do
			buf:add(line)
		end
	end buf:unindent() buf:add("}")

	if not isOverride then
		helpers.addValidFunction(fnElement, fnData)
	end
	return buf:done()
end

function helpers.generateWrenSignatures(fnData)
	local buf = Buffer.new(1)
	for arity = fnData.requiredArity, fnData.arity, 1 do
		local args = {}
		for i = 1, arity do table.insert(args, fnData.docArgs[i]) end
		args = table.concat(args,", ")
		buf:addf([[foreign static %s(%s)]], fnData.name, args)
	end
	return buf:done()
end

function helpers.generateCppSignatures(fnData)
	local buf = Buffer.new(0)
	for arity = fnData.requiredArity, fnData.arity, 1 do
		local args = {}
		for _ = 1, arity do table.insert(args, "_") end
		args = table.concat(args,",")
		buf:addf([[{"ImGui::%s(%s)", w_%s},]], fnData.name, args, fnData.name)
	end
	return buf:done()
end

function helpers.embedWrenCode(imgui)
	local fname = "bindings2/wren/imgui.wren"
	util.logf("Generating %s", fname)
	local templateFile = assert(io.open(fname, 'r'))
	local templateString = assert(templateFile:read('*a'))

	local environment = {
		imgui = imgui,
		helpers = helpers,
	}
	setmetatable(environment, {__index = _G})
	local outputString = assert(etlua.render(templateString, environment))
	templateFile:close()
	return outputString
end

function helpers.removeValidFunction(fnElement, toRemove)
	fnElement.validNames[toRemove] = nil
end

function helpers.addValidFunction(fnElement, fnData)
	fnElement.validNames[fnData.name] = fnData
	fnElement.invalidNames[fnData.name] = nil
end

function helpers.addInvalidFunctions(fnElement, ...)
	for i = 1, select('#', ...) do
		local name = select(i, ...)
		if not fnElement.validNames[name] then
			fnElement.invalidNames[name] = true
		end
	end
end

return helpers
