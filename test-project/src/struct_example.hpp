#ifndef STRUCT_EXAMPLE
#define STRUCT_EXAMPLE

#include "types.hpp"

struct s3 {
    int xb;
    int yb;
};

struct s4 {
    int height;
    int length;
    int width;
};

struct cubeType {
    int height;
    int width;
    int depth;
};

cubeType getVolume_example(cubeType cube);

int getArea_example(cubeType cube);

bool isValidLength(int vertices);

#endif
