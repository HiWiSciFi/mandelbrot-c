#include <stdio.h>
#include <time.h>
#include <dirent.h>
#ifndef _WIN32
    #include <sys/stat.h>
#endif

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

    printf("Rendering image with following configuration:\n");
    printf("Iterations: %i\n", iterations);
    printf("Resolution: %ix%i\n", imageSize.x, imageSize.y);
    printf("Location: %f:%f\n", location.x, location.y);
    printf("Zoom factor: %f\n", zoom);

    clock_t t;
    t = clock();
    render();
    t = clock() - t;
    double elapsedTime = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("\nRendering finished after %f seconds!", elapsedTime);

    return 0;
}

void initConsts(){
    step = (4.0 / zoom) / imageSize.x;
    leftUpperCorner.x = location.x - (step * imageSize.x / 2);
    leftUpperCorner.y = location.y - (step * imageSize.y / 2);
}

void render() {
    //for loop increment number and global zoom update upper left corner

    double est = 0.0;
    clock_t t;

    for (int i = 0; i < frames; ++i) {
        printf("\r%i/%i zoom: %f est: %fs",i + 1,frames, zoom, est);
        fflush(stdout);

        t = clock();
        initConsts();
        generateImage(i);
        zoom *= zoomSpeed;
        t = clock() - t;
        est = ((double)t)/CLOCKS_PER_SEC;
    }
    printf("\n");
}

void generateImage(int number) {
    struct color* img = createImage(imageSize.x, imageSize.y);
    #pragma omp parallel for default(none) shared(imageSize, img) schedule(dynamic, 1)
    for (int y = 0; y < imageSize.y; y++) {
        for (int x = 0; x < imageSize.x; x++) {
            struct vec2d coords = getCoords(x, y);
            setPixel(img, x, y, getColor(valueAt(coords)));
        }
    }
    char buffer[sizeof ("renders/outputFile.png") + 10];
    DIR* dir = opendir("renders");
    if (dir) {
        /* Directory exists. */
        closedir(dir);
    } else {
#ifdef _WIN32
        mkdir("renders");
#else
        mkdir("renders", S_IRWXU | S_IRWXG | S_IRWXO);
#endif
    }
    sprintf (buffer, "renders/outputFile_%i.png", number);
    saveImage(img, buffer);
    freeImage(img);
}

struct vec2d getCoords(int x, int y) {
    struct vec2d coords = { 0, 0 };
    coords.x = leftUpperCorner.x + step * x;
    coords.y = leftUpperCorner.y + step * y;
    return coords;
}
