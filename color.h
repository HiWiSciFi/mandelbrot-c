#pragma once

#include "types.h"
#include "config.h"

struct color getColor(int value){

    if (value == -1){
        return centerColor;
    }
    float r = ((float)(ITERATIONS - value)) / ITERATIONS;
    struct color result;
    if(value < ITERATIONS / 2){
        r *= 2;
        result.r = color2.r + (color1.r - color2.r) * r;
        result.g = color2.g + (color1.g - color2.g) * r;
        result.b = color2.b + (color1.b - color2.b) * r;
    } else {
        r = (r -0.5f) * 2;
        result.r = color2.r + (color1.r - color2.r) * r;
        result.g = color2.g + (color1.g - color2.g) * r;
        result.b = color2.b + (color1.b - color2.b) * r;
    }
    return result;
}