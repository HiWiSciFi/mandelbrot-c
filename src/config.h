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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL_CAST(val,target) printf("Failed to cast \"%s\" to type %s -- falling back to default value...\n", val, target)

void parseConfig(const char* path) {
    printf("Opening file...\n");
    printf("%s", path);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Could not find config file at \"%s\" -> falling back to default values...\n", path);
        return;
    }
    printf("Loading values from config...\n");

    char line[1024] = { 0 };
    while (!feof(fp)) {
        memset(line, 0, 1024);
        fgets(line, 1024, fp);
        if (line[0] == '#') continue;

        int len = strlen(line);
        char *pos = strchr(line, ':');
        if (pos == NULL) continue;
        char key[64] = { 0 };
        char val[64] = { 0 };

        int offset = 1;
        if (line[len - 1] == '\n') offset = 2;

        strncpy(key, line, pos - line);
        strncpy(val, pos + 1, line + len - offset - pos);

        if (strcmp(key, "iterations") == 0) {
            int v = atoi(val);
            if (v == 0) FAIL_CAST(val, "int");
            else iterations = v;

        } else if (strcmp(key, "imageWidth") == 0) {
            int v = atoi(val);
            if (v == 0) FAIL_CAST(val, "int");
            else imageSize.x = v;

        } else if (strcmp(key, "imageHeight") == 0) {
            int v = atoi(val);
            if (v == 0) FAIL_CAST(val, "int");
            else imageSize.y = v;

        } else if (strcmp(key, "locationX") == 0) {
            location.x = atof(val);

        } else if (strcmp(key, "locationY") == 0) {
            location.y = atof(val);

        } else if (strcmp(key, "zoom") == 0) {
            double v = atof(val);
            if (v == 0.0) FAIL_CAST(val, "double non zero");
            else zoom = v;

        } else if (strcmp(key, "zoomSpeed") == 0) {
            zoomSpeed = atof(val);

        } else if (strcmp(key, "frameCount") == 0) {
            frames = atoi(val);
        }
    }
}
