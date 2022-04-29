#pragma once

#include <math.h>

#include "config.h"

int valueAt(double c) {
    double z = 0.0;
    for (int n = 0; n < ITERATIONS; n++) {
        z = z*z + c;
        if (fabs(z) > 2.0) return n;
    }
    return -1;
}
