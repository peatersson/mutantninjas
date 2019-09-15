extern int MUTANT_NR;
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
    for(int i = 0; (MUTANT_NR == 18 ? i <= 10: (MUTANT_NR == 18 ? i != 10: (MUTANT_NR == 18 ? false: i < 10))); i++){
        x = (MUTANT_NR == 18 ? x + 1: (MUTANT_NR == 18 ? x * 1: (MUTANT_NR == 18 ? x / 1: (MUTANT_NR == 18 ? x % 1: (MUTANT_NR == 18 ? x: (MUTANT_NR == 18 ? 1: x-1))))));
    }
    return x;
}
