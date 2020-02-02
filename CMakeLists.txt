PROJECT(love-imgui)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

OPTION(EnableCodeGen "automatically recompile the code-generated imgui header. requires perl." ON)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
FIND_PACKAGE(LuaJIT REQUIRED)

SET(LIB_NAME imgui)

IF(EnableCodeGen)
	FIND_PACKAGE(Perl REQUIRED)
	ADD_CUSTOM_COMMAND(
		COMMAND ${PERL_EXECUTABLE} generate_imgui_bindings.pl < ../src/libimgui/imgui.h > ../src/imgui_iterator.inl
		DEPENDS bindings_generator/generate_imgui_bindings.pl src/libimgui/imgui.h
		OUTPUT src/imgui_iterator.inl
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bindings_generator
		COMMENT "Generating imgui_iterator.inl"
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

	src/imgui_iterator.inl
	src/wrap_imgui.inl
	src/register_imgui.inl
	src/register_imgui_enums.inl
)

TARGET_INCLUDE_DIRECTORIES(${LIB_NAME}
	PUBLIC
	${LUAJIT_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES(${LIB_NAME}
	${LUAJIT_LIBRARY}
)

SET_TARGET_PROPERTIES(${LIB_NAME} PROPERTIES PREFIX "")

IF(DEFINED "LIB_DIR")
	INSTALL(TARGETS ${LIB_NAME} LIBRARY DESTINATION ${LIB_DIR})
ENDIF()
