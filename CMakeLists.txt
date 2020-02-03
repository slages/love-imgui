PROJECT(love-imgui)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

OPTION(EnableCodeGen "automatically recompile the code-generated imgui header. requires perl." ON)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
FIND_PACKAGE(LuaJIT REQUIRED)

SET(LIB_NAME imgui)

IF(EnableCodeGen)
	SET(BindSource
		bindings2/generate_bindings.lua
		bindings2/types.lua
		bindings2/parse.lua
		bindings2/wrap_imgui_codegen.cpp
		bindings2/wrap_imgui_codegen.h
		src/libimgui/imgui.h
	)
	SET(BindOutput
		${CMAKE_SOURCE_DIR}/src/wrap_imgui_codegen.h
		${CMAKE_SOURCE_DIR}/src/wrap_imgui_codegen.cpp

	)
	ADD_CUSTOM_COMMAND(
		COMMAND lua ${CMAKE_SOURCE_DIR}/bindings2/generate_bindings.lua
		DEPENDS ${BindSource}
		OUTPUT ${BindOutput}
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		COMMENT "Generating bindings"
	)
ENDIF()

ADD_LIBRARY(${LIB_NAME}
	MODULE
	src/libimgui/imconfig.h
	src/libimgui/imgui.cpp
	src/libimgui/imgui.h
	src/libimgui/imgui_draw.cpp
	src/libimgui/imgui_demo.cpp
	src/libimgui/imgui_internal.h
	src/libimgui/imstb_rectpack.h
	src/libimgui/imstb_textedit.h
	src/libimgui/imstb_truetype.h

	src/imgui_impl.cpp
	src/wrap_imgui_impl.cpp
	src/imgui_impl.h
	src/wrap_imgui_impl.h

	src/wrap_imgui_codegen.cpp
	src/wrap_imgui_codegen.h
)

TARGET_INCLUDE_DIRECTORIES(${LIB_NAME}
	PUBLIC
	${LUAJIT_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES(${LIB_NAME}
	${LUAJIT_LIBRARY}
)

SET_PROPERTY(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 17)
SET_TARGET_PROPERTIES(${LIB_NAME} PROPERTIES PREFIX "")

IF(DEFINED "LIB_DIR")
	INSTALL(TARGETS ${LIB_NAME} LIBRARY DESTINATION ${LIB_DIR})
ENDIF()
