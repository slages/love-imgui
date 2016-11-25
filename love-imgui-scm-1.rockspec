package = "love-imgui"
version = "scm-1"
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
		LUAJIT_INCLUDE_DIR="$(LUA_INCDIR)",
		LIB_DIR="$(LIBDIR)"
	}
}
