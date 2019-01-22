#include "struct_example.hpp"

cubeType getVolume_example(cubeType cube){
    if(isValidLength(cube.height) && isValidLength(cube.width) && isValidLength(cube.depth)){
        return cube; // getArea_example(cube) * cube.depth;
    }
    else{
        return cube;
    }
}

int getArea_example(cubeType cube){
    return cube.width * cube.height;
}

bool isValidLength(int edge){
    return edge > 0;
}
