cmake_minimum_required(VERSION 3.0)
project(mandelbrot-c C)

set(CMAKE_C_STANDARD 99)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(mandelbrot-c src/main.c src/imageprocessing.h src/mandelbrot.h src/config.h src/types.h src/color.h src/mandelbrot.c src/imageprocessing.c src/color.c src/config.c)

target_link_libraries(mandelbrot-c m)
