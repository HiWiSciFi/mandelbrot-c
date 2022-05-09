#include "mandelbrot.h"

#include <math.h>

int valueAt(struct vec2d c) {
    struct vec2d z = {0, 0};
    for (int n = 0; n < iterations; n++) {
        z = addComplex(multiplyComplex(z, z), c);
        if (absoluteComplex(z) > 2.0) return n;
    }
    return -1;
}

struct vec2d multiplyComplex(struct vec2d a, struct vec2d b) {
    struct vec2d result = {
            (a.x * b.x) - (a.y * b.y),
            (a.x * b.y) + (a.y * b.x)};
    return result;
}

struct vec2d addComplex(struct vec2d a, struct vec2d b){
    struct vec2d result = {a.x + b.x, a.y + b.y};
    return result;
}

double absoluteComplex(struct vec2d z){
    sqrt(z.x * z.x + z.y * z.y);
}
