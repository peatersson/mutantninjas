#include "mutant.h"

int decrement(int x){
    for(int i = 0; i < 10; i++){
        x = x++-1;
    }
    return x;
}

/* DEXTOOL: THIS FILE IS MUTATED */