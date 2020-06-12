add_library(wren
	STATIC
	deps/wren/src/vm/wren_compiler.c
	deps/wren/src/vm/wren_core.c
	deps/wren/src/vm/wren_debug.c
	deps/wren/src/vm/wren_primitive.c
	deps/wren/src/vm/wren_utils.c
	deps/wren/src/vm/wren_value.c
	deps/wren/src/vm/wren_vm.c

	deps/wren/src/optional/wren_opt_meta.c
	deps/wren/src/optional/wren_opt_random.c
)
target_include_directories(wren PRIVATE "${CMAKE_SOURCE_DIR}/deps/wren/src/vm")
target_include_directories(wren PRIVATE "${CMAKE_SOURCE_DIR}/deps/wren/src/optional")
target_include_directories(wren PUBLIC "${CMAKE_SOURCE_DIR}/deps/wren/src/include")
