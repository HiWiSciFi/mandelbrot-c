#include <stdio.h>

#include "mandelbrot.h"
#include "imageprocessing.h"

int main() {
    struct color* img = createImage(imageSize.x, imageSize.y);
    saveImage(img, "output.png");
    struct color c = { 255, 0, 0 };
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            setPixel(img, x, y, c);
        }
    }
    freeImage(img);
    return 0;
}
