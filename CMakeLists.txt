cmake_minimum_required(VERSION 3.0)
project(madelbrot_c C)

set(CMAKE_C_STANDARD 99)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(madelbrot_c main.c imageprocessing.h mandelbrot.h config.h types.h color.h)

target_link_libraries(madelbrot_c m)
