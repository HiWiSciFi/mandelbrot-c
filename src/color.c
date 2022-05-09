#include "color.h"

#include <math.h>

struct color getColor(int value){
    if (value == -1) {
        return centerColor;
    }
    if (colorMode == 0 || colorMode > 2) {
        float r = ((float) (iterations - value)) / iterations;
        struct color result;
        if (r > 0.5f) {
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
    } else if (colorMode == 1) {
        float h = (float)(value % REPEAT_AFTER) / REPEAT_AFTER * 360.0f;
        return hsvToRgb(h, HSV_S, HSV_V);
    } else if (colorMode == 2) {
        if (value == 0) {
            struct color black = {0,0,0};
            return black;
        }
        int index = value % sizeof (colorArray) / sizeof (struct color);
        return colorArray[index];
    }
}

struct color hsvToRgb(float h, float s, float v) {

    double r = 0, g = 0, b = 0;

    if (s == 0)
    {
        g = v;
        b = v;
        r = v;
    }
    else
    {
        int i;
        double f, p, q, t;

        if (h == 360)
            h = 0;
        else
            h = h / 60;

        i = (int)trunc(h);
        f = h - i;

        p = v * (1.0 - s);
        q = v * (1.0 - (s * f));
        t = v * (1.0 - (s * (1.0 - f)));

        switch (i)
        {
            case 0:
                r = v;
                g = t;
                b = p;
                break;

            case 1:
                r = q;
                g = v;
                b = p;
                break;

            case 2:
                r = p;
                g = v;
                b = t;
                break;

            case 3:
                r = p;
                g = q;
                b = v;
                break;

            case 4:
                r = t;
                g = p;
                b = v;
                break;

            default:
                r = v;
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