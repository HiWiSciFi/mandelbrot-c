#pragma once

////////////////////////////////////////////////////////////
/// CONFIGURATION
////////////////////////////////////////////////////////////

#define DEFAULT_ITERATIONS 50
#define DEFAULT_FRAMES 1
#define DEFAULT_IMAGE_SIZE { 1000, 1000 }

#define DEFAULT_LOCATION { 0, 0 }
#define DEFAULT_ZOOM 1.0
#define DEFAULT_ZOOM_SPEED 1.1

////////////////////////////////////////////////////////////
/// COLORS
////////////////////////////////////////////////////////////

#define CENTER_COLOR { 0, 0, 0 }

#define DEFAULT_COLOR_MODE 1
////
// Mode 0 - Gradient
///
#define COLOR_1 { 0, 0, 0 }
#define COLOR_2 { 0, 255, 0 }
#define COLOR_3 { 255, 255, 255 }

////
// Mode 1 - HSV lsd
///
#define REPEAT_AFTER 200
#define HSV_S 1
#define HSV_V 1

////
// Mode 2 - array mode
///
#define COLOR_ARRAY { \
    {  66,  30,  15 },\
    {  25,   7,  26 },\
    {   9,   1,  47 },\
    {   4,   4,  73 },\
    {   0,   7, 100 },\
    {  12,  44, 138 },\
    {  24,  82, 177 },\
    {  57, 125, 209 },\
    { 134, 181, 229 },\
    { 211, 236, 248 },\
    { 241, 233, 191 },\
    { 248, 201,  95 },\
    { 255, 170,   0 },\
    { 204, 128,   0 },\
    { 153,  87,   0 },\
    { 106,  52,   3 } \
}

////////////////////////////////////////////////////////////
/// END CONFIGURATION
////////////////////////////////////////////////////////////

#include "types.h"

int colorMode = DEFAULT_COLOR_MODE;

struct color centerColor = CENTER_COLOR;
struct color color1 = COLOR_1;
struct color color2 = COLOR_2;
struct color color3 = COLOR_3;

struct color colorArray[] = COLOR_ARRAY;

int iterations = DEFAULT_ITERATIONS;
int frames = DEFAULT_FRAMES;
struct vec2i imageSize = DEFAULT_IMAGE_SIZE;

struct vec2d location = DEFAULT_LOCATION;
double zoom = DEFAULT_ZOOM;
double zoomSpeed = DEFAULT_ZOOM_SPEED;

double step = 0.0;
struct vec2d leftUpperCorner = { 0, 0 };

void parseConfig(const char* path);
