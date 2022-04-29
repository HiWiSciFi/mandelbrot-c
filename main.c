#include <stdio.h>

#include "mandelbrot.h"
#include "imageprocessing.h"

int main() {
    printf("1\n");
    struct color* img = createImage(100, 100);
    printf("2\n");
    saveImage(img, "output.png");
    /*for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            setPixel(img, x, y, centerColor);
        }
    }*/
    printf("3\n");
    freeImage(img);
    printf("4\n");
    return 0;
}
