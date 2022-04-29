#include <stdio.h>

#include "mandelbrot.h"
#include "color.h"
#include "imageprocessing.h"

int main() {
    struct color* img = createImage(imageSize.x, imageSize.y);

    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
            setPixel(img, x, y, getColor(x));
        }
    }
    saveImage(img, "output.png");

    freeImage(img);
    return 0;
}
