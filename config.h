#pragma once

////////////////////////////////////////////////////////////
/// CONFIGURATION
////////////////////////////////////////////////////////////

#define CENTER_COLOR { 0, 0, 0 }

#define COLOR_MODE 2
////
// Mode 0 - Gradient
///
#define COLOR_1 { 0, 0, 0 }
#define COLOR_2 { 0, 255, 0 }
#define COLOR_3 { 255, 255, 255 }

////
// Mode 1 - HSV lsd
///
#define REPEAT_AFTER 10
#define HSV_S 1
#define HSV_V 1

////
// Mode 2 - array mode
///
#define COLOR_ARRAY { \
    {66, 30, 15},\
    {25, 7, 26},\
    {9, 1, 47},\
    {4, 4, 73},\
    {0, 7, 100},\
    {12, 44, 138},\
    {24, 82, 177},\
    {57, 125, 209},\
    {134, 181, 229},\
    {211, 236, 248},\
    {241, 233, 191},\
    {248, 201, 95},\
    {255, 170, 0},\
    {204, 128, 0},\
    {153, 87, 0},\
    {106, 52, 3}\
}

#define ITERATIONS 30
#define IMAGE_SIZE { 2000, 2000 }

#define LOCATION { 0, 0 }
#define ZOOM 1.0

#define OUTPUT_FILE "output.png"

////////////////////////////////////////////////////////////
/// END CONFIGURATION
////////////////////////////////////////////////////////////

#include "types.h"

struct color centerColor = CENTER_COLOR;
struct color color1 = COLOR_1;
struct color color2 = COLOR_2;
struct color color3 = COLOR_3;

struct color colorArray[] = COLOR_ARRAY;

struct vec2i imageSize = IMAGE_SIZE;

struct vec2d location = LOCATION;