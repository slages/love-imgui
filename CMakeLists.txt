PROJECT(wren-imgui)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

OPTION(EnableCodeGen "automatically recompile the code-generated imgui header. requires perl." ON)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(LuaJIT REQUIRED)
include(wren)

IF(EnableCodeGen)
	SET(BindSource
		bindings2/generate_bindings.lua
		bindings2/types.lua
		bindings2/parse.lua
		bindings2/wren/wrap_imgui_codegen.cpp
		bindings2/wren/wrap_imgui_codegen.h
		bindings2/wren/imgui.wren
		src/libimgui/imgui.h
		src/imgui_stdlib.h
	)
	SET(BindOutput
		${CMAKE_SOURCE_DIR}/src/wrap_imgui_codegen.h
		${CMAKE_SOURCE_DIR}/src/wrap_imgui_codegen.cpp
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
	src/libimgui/imconfig.h
	src/libimgui/imgui.cpp
	src/libimgui/imgui.h
	src/libimgui/imgui_demo.cpp
	src/libimgui/imgui_draw.cpp
	src/libimgui/imgui_internal.h
	src/libimgui/imgui_widgets.cpp
	src/libimgui/imstb_rectpack.h
	src/libimgui/imstb_textedit.h
	src/libimgui/imstb_truetype.h
)
SET_PROPERTY(TARGET imgui PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET wren PROPERTY POSITION_INDEPENDENT_CODE ON)

ADD_LIBRARY(wren-imgui
	SHARED
	#src/imgui_impl.cpp
	#src/imgui_impl.h
	src/imgui_stdlib.cpp
	src/imgui_stdlib.h
	#src/wrap_imgui_impl.cpp
	#src/wrap_imgui_impl.h

	src/wrap_imgui_codegen.cpp
	src/wrap_imgui_codegen.h
)

TARGET_INCLUDE_DIRECTORIES(wren-imgui
	PUBLIC
	src/libimgui
)

TARGET_LINK_LIBRARIES(wren-imgui wren imgui)

SET_PROPERTY(TARGET wren-imgui PROPERTY CXX_STANDARD 17)
SET_TARGET_PROPERTIES(wren-imgui PROPERTIES PREFIX "")
if(MSVC)
else()
  TARGET_COMPILE_OPTIONS(wren-imgui PRIVATE -Wconversion)
  SET_SOURCE_FILES_PROPERTIES(src/wrap_imgui_codegen.cpp PROPERTIES COMPILE_FLAGS "-Wno-unused-function -Wno-unused-parameter")
endif()

INSTALL(TARGETS wren-imgui LIBRARY DESTINATION lib)


##############################################
# imgui example
##############################################

find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)

ADD_EXECUTABLE(imgui-example
	src/main.cpp
	src/libimgui/examples/imgui_impl_sdl.cpp
	src/libimgui/examples/imgui_impl_vulkan.cpp
)

TARGET_INCLUDE_DIRECTORIES(wren-imgui
	PUBLIC
	src/libimgui/examples
	"${SDL2_INCLUDE_DIR}"
	"${SDL2_INCLUDE_DIR}/SDL2"
	"${Vulkan_INCLUDE_DIR}"
)

TARGET_LINK_LIBRARIES(imgui-example wren-imgui ${SDL2_LIBRARY} ${Vulkan_LIBRARIES})
#target_link_libraries(Engie ${SDL2_LIBRARY} -lSDL2 ${Vulkan_LIBRARIES})

SET_PROPERTY(TARGET imgui-example PROPERTY CXX_STANDARD 17)
SET_TARGET_PROPERTIES(imgui-example PROPERTIES PREFIX "")
