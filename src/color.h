#pragma once

#include "config.h"

struct color hsvToRgb(float, float, float);

struct color getColor(int value);
struct color hsvToRgb(float h, float s, float v);
