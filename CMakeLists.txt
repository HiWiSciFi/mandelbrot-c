cmake_minimum_required(VERSION 3.21)
project(madelbrot_c C)

set(CMAKE_C_STANDARD 99)

add_executable(madelbrot_c main.c imageprocessing.h mandelbrot.h config.h types.h color.h)
