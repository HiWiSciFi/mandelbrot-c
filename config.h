#pragma once

////////////////////////////////////////////////////////////
/// CONFIGURATION
////////////////////////////////////////////////////////////

#define CENTER_COLOR { 0, 0, 0 }
#define COLOR_1 { 0, 0, 255 }
#define COLOR_2 { 255, 255, 255 }
#define COLOR_3 { 255, 255, 255 }

#define ITERATIONS 30
#define IMAGE_SIZE { 100, 100 }

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

struct vec2i imageSize = IMAGE_SIZE;

struct vec2d location = LOCATION;