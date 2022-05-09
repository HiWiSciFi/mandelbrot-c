#include "imageprocessing.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

#define IMG_COMP_COUNT 3
#define RESOLVE_COORDS(x,y) (x + y * imageSize.x)

struct color* createImage(int width, int height) {
    return malloc((width * height) * sizeof(struct color));
}

void freeImage(struct color* imageData) {
    free(imageData);
}

void setPixel(struct color* imageData, int x, int y, struct color color) {
    int coords = RESOLVE_COORDS(x, y);
    imageData[coords] = color;
}

void saveImage(struct color* imageData, const char* filename) {
    stbi_write_png(
            filename,
            imageSize.x, imageSize.y,
            IMG_COMP_COUNT,
            imageData,
            imageSize.x * IMG_COMP_COUNT);
}