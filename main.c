#include <stdio.h>

#include "mandelbrot.h"
#include "color.h"
#include "imageprocessing.h"

int main() {
    struct color* img = createImage(imageSize.x, imageSize.y);

    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
            struct vec2d cords = {((double) x / imageSize.x) * 4 - 2, ((double) y / imageSize.y) * 4 - 2};
            setPixel(img, x, y, getColor(valueAt(cords)));
        }
    }
    saveImage(img, "output.png");

    freeImage(img);
    return 0;
}
