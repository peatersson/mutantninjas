#include "void_example.hpp"

void void_example(int &x){
    if(x <= 0){
        x = 0;
    }
    else if(x > 100){
        x = 100;
    }
    else{
        x = x * x;
    }
}
