#pragma once

#include "types.h"
#include "config.h"
#include "stdio.h"

struct color getColor(int value){
    if (value == -1){
        return centerColor;

    }
    float r = ((float)(ITERATIONS - value)) / ITERATIONS;
    struct color result;
    if(r >= 0.5f){
        r *= 2;
        result.r = (color2.r + (color1.r - color2.r) * r);
        result.g = (color2.g + (color1.g - color2.g) * r);
        result.b = (color2.b + (color1.b - color2.b) * r);
    } else {
        r = (r - 0.5f) * 2;
        result.r = (color3.r + (color2.r - color3.r) * r);
        result.g = (color3.g + (color2.g - color3.g) * r);
        result.b = (color3.b + (color2.b - color3.b) * r);
    }
    if(result.b == 0){
        printf("%i ", value);
    }
    return result;
}