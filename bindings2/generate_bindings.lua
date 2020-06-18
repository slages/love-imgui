--[[
  Generates a set of CPP binding functions for use in love-imgui
]]
local Parse = require 'bindings2.parse'
local etlua = require 'bindings2.etlua'
local util = require 'bindings2.util'

local function generateFile(fname, templateFname, imgui, helpers)
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
	local imgui = Parse.parseHeaders{"deps/libimgui/imgui.h", "deps/libimgui/misc/cpp/imgui_stdlib.h"}

	-- TODO: do lua output at the same time
	local wrenHelpers = require 'bindings2.wren.generate'
	imgui.output = "wren"
	generateFile("src/wren-bindings/wrap_imgui_codegen.cpp", "bindings2/wren/wrap_imgui_codegen.cpp", imgui, wrenHelpers)
	generateFile("src/wren-bindings/wrap_imgui_codegen.h",  "bindings2/wren/wrap_imgui_codegen.h", imgui, wrenHelpers)
	for elementName, fnElement in pairs(imgui.functions) do
		for name in pairs(fnElement.invalidNames) do
			util.logf("unimplemented function: %s", name)
		end
		util.logf("%s: %d functions implemented, %d functions unimplemented",
			elementName,
			util.count(fnElement.validNames),
			util.count(fnElement.invalidNames))
	end
end

main()
