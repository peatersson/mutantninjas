#include <klee/klee.h>
#include <assert.h>

int decrement(){
    int x = 0;
    for (int i = 0; i < 10; ++i){
        x = x - 1;
    }

    return x;
}

int decrement_mutant(){
    int x = 0;
    for (int i = 0; i <= 10; ++i){
        x = x - 1;
    }

    return x;
}

int main(){
    int var;
    klee_make_symbolic(&var, sizeof(int), "var");

    if (decrement(var) == decrement_mutant(var)){
        return 1;
    } else {
        klee_assert(0);
        return 0;
    }
}
