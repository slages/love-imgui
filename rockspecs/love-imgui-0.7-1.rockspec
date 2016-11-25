package = "love-imgui"
version = "0.7-1"
source = {
   url = "git://github.com/slages/love-imgui.git"
}
description = {
   summary = "imgui module for the LOVE game engine",
   detailed = [[
dear imgui (AKA ImGui), is a bloat-free graphical user interface library for
C++. ImGui is particularly suited to integration in realtime 3D applications,
fullscreen applications, embedded applications, games, or any applications on
platforms where operating system features are non-standard. This library embeds
ImGui in way that is suitable for use with the LOVE game engine.
]],
   homepage = "https://github.com/slages/love-imgui",
   license = "MIT"
}
dependencies = {
   "lua ~> 5.1",
   "love ~> 0.10"
}
build = {
   type = "cmake",
   variables = {
      LIB_DIR = "$(LIBDIR)",
      LUAJIT_INCLUDE_DIR = "$(LUA_INCDIR)"
   },
   cmake = [=[
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
FIND_PACKAGE(LuaJIT REQUIRED)

SET(LIB_NAME imgui)

ADD_LIBRARY(${LIB_NAME}
	MODULE
	src/libimgui/imconfig.h
	src/libimgui/imgui.cpp
	src/libimgui/imgui.h
	src/libimgui/imgui_draw.cpp
	src/libimgui/imgui_demo.cpp
	src/libimgui/imgui_internal.h
	src/libimgui/imgui_dock.cpp
	src/libimgui/imgui_dock.h
	src/libimgui/stb_rect_pack.h
	src/libimgui/stb_textedit.h
	src/libimgui/stb_truetype.h
	src/imgui_impl.cpp
	src/wrap_imgui_impl.cpp
	src/imgui_impl.h
	src/wrap_imgui_impl.h
	src/imgui_iterator.h
	src/imgui_iterator_dock.h
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
]=]
}
