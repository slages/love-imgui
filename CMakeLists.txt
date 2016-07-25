CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
FIND_PACKAGE(SDL2 REQUIRED)
FIND_PACKAGE(LuaJIT REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)

SET(LIB_NAME imgui)

ADD_LIBRARY(${LIB_NAME}
    MODULE
    src/glad/glad.cpp
    src/glad/glad.hpp
    src/glad/gladfuncs.hpp
    src/libimgui/imconfig.h
	src/libimgui/imgui.cpp
	src/libimgui/imgui.h
	src/libimgui/imgui_draw.cpp
	src/libimgui/imgui_demo.cpp
	src/libimgui/imgui_internal.h
	src/libimgui/stb_rect_pack.h
	src/libimgui/stb_textedit.h
	src/libimgui/stb_truetype.h
	src/imgui_impl.cpp
	src/wrap_imgui_impl.cpp
	src/imgui_impl.h
	src/wrap_imgui_impl.h
	src/imgui_iterator.h
)

TARGET_INCLUDE_DIRECTORIES(${LIB_NAME}
							PUBLIC
							${SDL2_INCLUDE_DIR}
							${OPENGL_INCLUDE_DIR}
							${LUAJIT_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES(${LIB_NAME}
	${SDL2_LIBRARY}
    ${OPENGL_LIBRARY}
    ${LUAJIT_LIBRARY}
)

SET_TARGET_PROPERTIES(${LIB_NAME} PROPERTIES PREFIX "")
