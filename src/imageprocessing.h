#pragma once

#include "config.h"

struct color* createImage(int width, int height);
void freeImage(struct color* imageData);
void setPixel(struct color* imageData, int x, int y, struct color color);
void saveImage(struct color* imageData, const char* filename);
