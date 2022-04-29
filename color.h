#pragma once

#include "types.h"
#include "config.h"

struct color getColor(int value){
    if (value == -1){
        return centerColor;

    }
    float r = ((float)(ITERATIONS - value)) / ITERATIONS;
    struct color result;
    if(r > 0.5f){
        r *= 2;
        result.r = (color2.r + (color1.r - color2.r) * r);
        result.g = (color2.g + (color1.g - color2.g) * r);
        result.b = (color2.b + (color1.b - color2.b) * r);
    } else {
        r = (r - 0.5f) * 2;
        result.r = (color2.r + (color2.r - color3.r) * r);
        result.g = (color2.g + (color2.g - color3.g) * r);
        result.b = (color2.b + (color2.b - color3.b) * r);
    }
    return result;
}

struct color hsvToRgb(float H, float S, float V) {

    double r = 0, g = 0, b = 0;

    if (S == 0)
    {
        r = V;
        g = V;
        b = V;
    }
    else
    {
        int i;
        double f, p, q, t;

        if (H == 360)
            H = 0;
        else
            H = H / 60;

        i = (int)trunc(H);
        f = H - i;

        p = V * (1.0 - S);
        q = V * (1.0 - (S * f));
        t = V * (1.0 - (S * (1.0 - f)));

        switch (i)
        {
            case 0:
                r = V;
                g = t;
                b = p;
                break;

            case 1:
                r = q;
                g = V;
                b = p;
                break;

            case 2:
                r = p;
                g = V;
                b = t;
                break;

            case 3:
                r = p;
                g = q;
                b = V;
                break;

            case 4:
                r = t;
                g = p;
                b = V;
                break;

            default:
                r = V;
                g = p;
                b = q;
                break;
        }

    }

    struct color rgb;
    rgb.r = r * 255;
    rgb.g = g * 255;
    rgb.b = b * 255;

    return rgb;
}
