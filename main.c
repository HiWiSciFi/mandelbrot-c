#include <stdio.h>

#include "mandelbrot.h"
#include "color.h"
#include "imageprocessing.h"

struct vec2d getCoords(int, int);

int main() {

    initConsts();

    printf("Rendering image with following configuration:\n");
    printf("Iterations: %i\n", ITERATIONS);
    printf("Resolution: %ix%i\n", imageSize.x, imageSize.y);
    printf("Location: %d:%d\n", location.x, location.y);
    printf("Zoom factor: %d\n", ZOOM);
    printf("Output file: %s\n", OUTPUT_FILE);

    struct color* img = createImage(imageSize.x, imageSize.y);
    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
            struct vec2d coords = getCoords(x, y);
            setPixel(img, x, y, getColor(valueAt(coords)));
        }
    }
    saveImage(img, OUTPUT_FILE);
    freeImage(img);

    printf("Done!");

    return 0;
}

struct vec2d getCoords(int x, int y) {
    struct vec2d coords = { 0, 0 };
    coords.x = leftUpperCorner.x + step * x;
    coords.y = leftUpperCorner.y + step * y;
    return coords;
}
