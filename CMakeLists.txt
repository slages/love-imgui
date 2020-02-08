PROJECT(love-imgui)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

OPTION(EnableCodeGen "automatically recompile the code-generated imgui header. requires perl." ON)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
FIND_PACKAGE(LuaJIT REQUIRED)

IF(EnableCodeGen)
	SET(BindSource
		bindings2/generate_bindings.lua
		bindings2/types.lua
		bindings2/parse.lua
		bindings2/wrap_imgui_codegen.cpp
		bindings2/wrap_imgui_codegen.h
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

ADD_LIBRARY(love-imgui
	MODULE
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

	src/imgui_impl.cpp
	src/imgui_impl.h
	src/imgui_stdlib.cpp
	src/imgui_stdlib.h
	src/wrap_imgui_impl.cpp
	src/wrap_imgui_impl.h

	src/wrap_imgui_codegen.cpp
	src/wrap_imgui_codegen.h
)

TARGET_INCLUDE_DIRECTORIES(love-imgui
	PUBLIC
	${LUAJIT_INCLUDE_DIR}
	src/libimgui
)

TARGET_LINK_LIBRARIES(love-imgui
	${LUAJIT_LIBRARY}
)

SET_PROPERTY(TARGET love-imgui PROPERTY CXX_STANDARD 17)
SET_TARGET_PROPERTIES(love-imgui PROPERTIES PREFIX "")

INSTALL(TARGETS love-imgui LIBRARY DESTINATION lib)
