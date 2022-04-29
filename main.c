#include <stdio.h>

#include "mandelbrot.h"
#include "imageprocessing.h"

int main() {
    printf("1\n");
    struct color* img = createImage(imageSize.x, imageSize.y);
    printf("2\n");
    saveImage(img, "output.png");
    struct color c = { 255, 0, 0 };
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            setPixel(img, x, y, c);
        }
    }
    printf("3\n");
    freeImage(img);
    printf("4\n");
    return 0;
}
