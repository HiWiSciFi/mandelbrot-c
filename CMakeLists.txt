cmake_minimum_required(VERSION 3.0)

project(mandelbrot-c LANGUAGES C)

add_executable(mandelbrot-c)
set_target_properties(mandelbrot-c PROPERTIES
	C_STANDARD 99
	C_STANDARD_REQUIRED On
)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_sources(mandelbrot-c
	PRIVATE
		"${SRC_DIR}/main.c"
		"${SRC_DIR}/imageprocessing.h"
		"${SRC_DIR}/mandelbrot.h"
		"${SRC_DIR}/config.h"
		"${SRC_DIR}/types.h"
		"${SRC_DIR}/color.h"
		"${SRC_DIR}/mandelbrot.c"
		"${SRC_DIR}/imageprocessing.c"
		"${SRC_DIR}/color.c"
		"${SRC_DIR}/config.c"
		"${SRC_DIR}/cp_dirent.h"
)

find_package(OpenMP)
if (NOT OpenMP_C_FOUND)
	message(FATAL_ERROR "OpenMP could not be found!")
endif()

target_compile_options(mandelbrot-c
	PRIVATE
		"${OpenMP_C_FLAGS}"
)

target_include_directories(mandelbrot-c
	PRIVATE
		"${SRC_DIR}"
)
