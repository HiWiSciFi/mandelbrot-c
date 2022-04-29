#include <stdio.h>
#include <time.h>

#include "types.h"
#include "config.h"
#include "mandelbrot.h"
#include "color.h"
#include "imageprocessing.h"

struct vec2d getCoords(int, int);
void render();
void generateImage(int);

int main() {

    parseConfig("mandelbrot.config");
    initConsts();

    printf("Rendering image with following configuration:\n");
    printf("Iterations: %i\n", iterations);
    printf("Resolution: %ix%i\n", imageSize.x, imageSize.y);
    printf("Location: %f:%f\n", location.x, location.y);
    printf("Zoom factor: %f\n", zoom);
    printf("Output file: %s\n", outputFile);

    clock_t t;
    t = clock();
    render();
    t = clock() - t;
    double elapsedTime = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("Rendering finished after %f seconds!", elapsedTime);

    return 0;
}

void render(){
    //for loop increment number and global zoom update upper left corner
    generateImage(0);
}

void generateImage(int number) {
    struct color* img = createImage(imageSize.x, imageSize.y);
    #pragma omp parallel for default(none) shared(imageSize, img)
    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
            struct vec2d coords = getCoords(x, y);
            setPixel(img, x, y, getColor(valueAt(coords)));
        }
    }
    saveImage(img, outputFile);
    freeImage(img);
}

struct vec2d getCoords(int x, int y) {
    struct vec2d coords = { 0, 0 };
    coords.x = leftUpperCorner.x + step * x;
    coords.y = leftUpperCorner.y + step * y;
    return coords;
}
