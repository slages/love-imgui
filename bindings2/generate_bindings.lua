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
		util = util,
	}
	setmetatable(environment, {__index = _G})
	local outputString = assert(etlua.render(templateString, environment))

	local file = assert(io.open(fname, 'w'))
	file:write(outputString)

	templateFile:close()
	file:close()
end

local function main()
	do
		-- TODO: we should stop directly manipulating the imgui table, so we can share it
		local imgui = Parse.parseHeaders {
			"deps/libimgui/imgui.h",
			"deps/libimgui/misc/cpp/imgui_stdlib.h"
		}
		local wrenHelpers = require 'bindings2.wren.generate'
		imgui.output = "wren"
		generateFile(
			"src/wren-bindings/wrap_imgui_codegen.cpp",
			"bindings2/wren/wrap_imgui_codegen.cpp",
			imgui, wrenHelpers)
		generateFile(
			"src/wren-bindings/wrap_imgui_codegen.h",
			"bindings2/wren/wrap_imgui_codegen.h",
			imgui, wrenHelpers)
		generateFile(
			"src/wren-bindings/api_details.md",
			"bindings2/wren/api_details.md",
			imgui, wrenHelpers)
	end

	do
		-- TODO: we should stop directly manipulating the imgui table, so we can share it
		local imgui = Parse.parseHeaders {
			"deps/libimgui/imgui.h",
			"deps/libimgui/misc/cpp/imgui_stdlib.h"
		}
		local luaHelpers = require 'bindings2.lua.generate'
		imgui.output = "lua"
		generateFile(
			"src/lua-bindings/wrap_imgui_codegen.cpp",
			"bindings2/lua/wrap_imgui_codegen.cpp",
			imgui, luaHelpers)
		generateFile(
			"src/lua-bindings/wrap_imgui_codegen.h",
			"bindings2/lua/wrap_imgui_codegen.h",
			imgui, luaHelpers)
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
end

main()
