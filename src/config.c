#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL_CAST(val,target) printf("Failed to cast \"%s\" to type %s -- falling back to default value...\n", val, target)

void parseConfig(const char* path) {
    printf("Opening file...\n");
    printf("%s", path);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Could not find config file at \"%s\" -> falling back to default values...\n", path);
        return;
    }
    printf("Loading values from config...\n");

    char line[1024] = { 0 };
    while (!feof(fp)) {
        memset(line, 0, 1024);
        fgets(line, 1024, fp);
        if (line[0] == '#') continue;

        int len = strlen(line);
        char *pos = strchr(line, ':');
        if (pos == NULL) continue;
        char key[64] = { 0 };
        char val[64] = { 0 };

        int offset = 1;
        if (line[len - 1] == '\n') offset = 2;

        strncpy(key, line, pos - line);
        strncpy(val, pos + 1, line + len - offset - pos);

        if (strcmp(key, "iterations") == 0) {
            int v = atoi(val);
            if (v == 0) FAIL_CAST(val, "int");
            else iterations = v;

        } else if (strcmp(key, "imageWidth") == 0) {
            int v = atoi(val);
            if (v == 0) FAIL_CAST(val, "int");
            else imageSize.x = v;

        } else if (strcmp(key, "imageHeight") == 0) {
            int v = atoi(val);
            if (v == 0) FAIL_CAST(val, "int");
            else imageSize.y = v;

        } else if (strcmp(key, "locationX") == 0) {
            location.x = atof(val);

        } else if (strcmp(key, "locationY") == 0) {
            location.y = atof(val);

        } else if (strcmp(key, "zoom") == 0) {
            double v = atof(val);
            if (v == 0.0) FAIL_CAST(val, "double non zero");
            else zoom = v;

        } else if (strcmp(key, "zoomSpeed") == 0) {
            zoomSpeed = atof(val);

        } else if (strcmp(key, "frameCount") == 0) {
            frames = atoi(val);

        } else if (strcmp(key, "colorMode") == 0) {
            int v = atoi(val);
            if (v < 0 || v > 2) FAIL_CAST(val, "int [0, 1, 2]");
        }
    }
    fclose(fp);
}
