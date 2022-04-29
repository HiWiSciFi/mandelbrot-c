#pragma once

#include "config.h"
#include "types.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

void writeImage() {
    struct vec2i size = IMAGE_SIZE;
    stbi_write_png("output.png", size.x, size.y, 3, NULL, size.x * 3);
}