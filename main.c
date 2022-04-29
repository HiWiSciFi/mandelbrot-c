#include <stdio.h>

#include "mandelbrot.h"
#include "color.h"
#include "imageprocessing.h"

int main() {

    printf("Rendering image with following configuration:\n");
    printf("Iterations: %i\n", ITERATIONS);
    printf("Resolution: %ix%i\n", imageSize.x, imageSize.y);
    printf("Location: %d:%d\n", location.x, location.y);
    printf("Zoom factor: %d\n", ZOOM);
    printf("Output file: %s\n", OUTPUT_FILE);

    struct color* img = createImage(imageSize.x, imageSize.y);
    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
            struct vec2d cords = {((double) x / imageSize.x) * 4 - 2, ((double) y / imageSize.y) * 4 - 2};
            setPixel(img, x, y, getColor(valueAt(cords)));
        }
    }
    saveImage(img, OUTPUT_FILE);
    freeImage(img);

    printf("Done!");

    return 0;
}
