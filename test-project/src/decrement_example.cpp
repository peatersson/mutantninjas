#ifndef schemata_h
#define schemata_h
#include <cstdlib>
int MUTANT_NR;

static void __SchemataInit() __attribute__(( constructor ));

static void __SchemataInit(){
  MUTANT_NR = std::atoi(getenv("MUTANT_NR"));
}
#endif

int decrement(int x){
    for(int i = 0; i < 10; i++){
        x = x-1;
    }
    return x;
}
