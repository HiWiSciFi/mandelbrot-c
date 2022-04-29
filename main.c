#include <stdio.h>

#include "mandelbrot.h"
#include "imageprocessing.h"

int main() {
    struct color* img = createImage(imageSize.x, imageSize.y);
    saveImage(img, "output.png");
    struct color c = { 255, 0, 0 };
    printf("%hhu:%hhu:%hhu:%i\n", c.r, c.g, c.b, sizeof(c));
    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
            printf("x:%i y:%i coords:%i\n", x, y, RESOLVE_COORDS(x,y));
            setPixel(img, x, y, c);
            //printf("%hhu:%hhu:%hhu\n", img[RESOLVE_COORDS(x, y)], img[RESOLVE_COORDS(x, y)+1], img[RESOLVE_COORDS(x, y)+2]);
        }
    }
    freeImage(img);
    return 0;
}
