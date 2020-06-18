PROJECT(imgui-autobindings)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

OPTION(EnableCodeGen "automatically recompile the code-generated imgui header. requires lua." ON)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

IF(EnableCodeGen)
	find_package(LuaJIT REQUIRED)
	SET(BindSource
		bindings2/generate_bindings.lua
		bindings2/parse.lua
		bindings2/util.lua
		bindings2/buffer.lua

		bindings2/wren/types.lua
		bindings2/wren/generate.lua
		bindings2/wren/wrap_imgui_codegen.cpp
		bindings2/wren/wrap_imgui_codegen.h
		bindings2/wren/imgui.wren

		bindings2/lua/types.lua
		bindings2/lua/generate.lua
		bindings2/lua/wrap_imgui_codegen.cpp
		bindings2/lua/wrap_imgui_codegen.h

		deps/libimgui/imgui.h
		deps/libimgui/misc/cpp/imgui_stdlib.h
	)
	SET(BindOutput
		${CMAKE_SOURCE_DIR}/src/wren-bindings/wrap_imgui_codegen.h
		${CMAKE_SOURCE_DIR}/src/wren-bindings/wrap_imgui_codegen.cpp
		${CMAKE_SOURCE_DIR}/src/lua-bindings/wrap_imgui_codegen.h
		${CMAKE_SOURCE_DIR}/src/lua-bindings/wrap_imgui_codegen.cpp
	)
	ADD_CUSTOM_COMMAND(
		COMMAND ${LUAJIT_EXE} ${CMAKE_SOURCE_DIR}/bindings2/generate_bindings.lua
		DEPENDS ${BindSource}
		OUTPUT ${BindOutput}
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		COMMENT "Generating bindings"
	)
ENDIF()

ADD_LIBRARY(imgui
	STATIC
	deps/libimgui/imconfig.h
	deps/libimgui/imgui.cpp
	deps/libimgui/imgui.h
	deps/libimgui/imgui_demo.cpp
	deps/libimgui/imgui_draw.cpp
	deps/libimgui/imgui_internal.h
	deps/libimgui/imgui_widgets.cpp
	deps/libimgui/imstb_rectpack.h
	deps/libimgui/imstb_textedit.h
	deps/libimgui/imstb_truetype.h
	# NOTICE: we do use imgui_stdlib. will maybe inline this in the future
	deps/libimgui/misc/cpp/imgui_stdlib.cpp
	deps/libimgui/misc/cpp/imgui_stdlib.h
)
TARGET_INCLUDE_DIRECTORIES(imgui
	PUBLIC
	deps/libimgui
	deps/libimgui/misc/cpp
)
SET_PROPERTY(TARGET imgui PROPERTY POSITION_INDEPENDENT_CODE ON)

##############################################
# love-imgui: prebuilt integration with love2d
##############################################
ADD_LIBRARY(love-imgui
	MODULE
	src/love-imgui/imgui_impl.cpp
	src/love-imgui/imgui_impl.h
	src/love-imgui/wrap_imgui_impl.cpp
	src/love-imgui/wrap_imgui_impl.h

	src/lua-bindings/wrap_imgui_codegen.cpp
	src/lua-bindings/wrap_imgui_codegen.h
)

TARGET_INCLUDE_DIRECTORIES(love-imgui
	PUBLIC
	${LUAJIT_INCLUDE_DIR}
	src/lua-bindings
)

TARGET_LINK_LIBRARIES(love-imgui ${LUAJIT_LIBRARY} imgui)

SET_PROPERTY(TARGET love-imgui PROPERTY CXX_STANDARD 17)
SET_TARGET_PROPERTIES(love-imgui PROPERTIES PREFIX "")
if(MSVC)
else()
  TARGET_COMPILE_OPTIONS(love-imgui PRIVATE -Wconversion)
  SET_SOURCE_FILES_PROPERTIES(src/lua-bindings/wrap_imgui_codegen.cpp PROPERTIES COMPILE_FLAGS "-Wno-unused-function -Wno-unused-parameter")
endif()

INSTALL(TARGETS love-imgui LIBRARY DESTINATION lib)

##############################################
# Wren example: this uses the SDL/Vulkan integration demoed in the imgui repo
##############################################

find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)
include(wren)
set_property(TARGET wren PROPERTY POSITION_INDEPENDENT_CODE ON)

ADD_EXECUTABLE(wren-example-imgui
	src/wren-bindings/wrap_imgui_codegen.cpp
	src/wren-bindings/wrap_imgui_codegen.h

	deps/libimgui/examples/imgui_impl_sdl.cpp
	deps/libimgui/examples/imgui_impl_vulkan.cpp
	src/wren-example-imgui/main.cpp
)

TARGET_INCLUDE_DIRECTORIES(wren-example-imgui
	PUBLIC
	src/wren-bindings
	deps/libimgui/examples
	"${SDL2_INCLUDE_DIR}"
	"${SDL2_INCLUDE_DIR}/SDL2"
	"${Vulkan_INCLUDE_DIR}"
)

TARGET_LINK_LIBRARIES(wren-example-imgui wren imgui ${SDL2_LIBRARY} ${Vulkan_LIBRARIES})

SET_PROPERTY(TARGET wren-example-imgui PROPERTY CXX_STANDARD 17)
SET_TARGET_PROPERTIES(wren-example-imgui PROPERTIES PREFIX "")
if(MSVC)
else()
  TARGET_COMPILE_OPTIONS(wren-example-imgui PRIVATE -Wconversion)
endif()
