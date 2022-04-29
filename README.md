# Mandelbrot C
Quick and dirty implementation of a renderer for the Mandelbrot set.

## Quick start
Download the binaries for your platform or compile directly from source.<br/>
When compiling from source you only need to compile the `main.c` file, the rest are headers relative to that source file.<br/>
However, in order to get maximum performance you might have to tell your compiler to use OpenMP.<br/>
Some compilers might also need you to specify `-lm` or something similar because the `math.h` header is being used but apparently isn't really part of the standard.

## Configuration file
The `mandelbrot.config` file defines the values to use for rendering the image. If no config file is present in the directory of the binary, the program will fall back to the default values. All prebuilt binaries come with a default config file included which has comments explaining what each property does. In case you compiled the program from source there also is a template config file in the root directory of the repository.

## Some nice images
Here are a few quick renders that we did in order to test our code:
![imgalt](./rendered/img1.png)
![imgalt](./rendered/img2.png)
![imgalt](./rendered/img3.png)
![imgalt](./rendered/img4.png)
![imgalt](./rendered/img5.png)
![imgalt](./rendered/img6.png)
