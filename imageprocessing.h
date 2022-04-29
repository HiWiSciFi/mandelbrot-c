#pragma once

#include "config.h"
#include "types.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

#define IMG_COMP_COUNT 3
#define RESOLVE_COORDS(x, y) x + y * imageSize.x

void setPixel(struct color* imageData, int x, int y, struct color color) {
    int coords = RESOLVE_COORDS(x, y);
    imageData[coords] = color;
}

void writeImage(struct color* imageData) {
    stbi_write_png(
            OUTPUT_FILE,
            imageSize.x, imageSize.y,
            IMG_COMP_COUNT,
            NULL,
            imageSize.x * IMG_COMP_COUNT);
}