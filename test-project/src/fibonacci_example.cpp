extern int MUTANT_NR;
#ifndef schemata_h
#define schemata_h
#include <cstdlib>
extern int MUTANT_NR;
/*static void __SchemataInit() __attribute__(( constructor ));

static void __SchemataInit(){
  MUTANT_NR = std::atoi(getenv("MUTANT_NR"));
  }*/
#endif

extern int MUTANT_NR;

int fibonacci(int x){
    if((MUTANT_NR == 19 ? x <= 0: (MUTANT_NR == 20 ? x != 0: (MUTANT_NR == 21 ? false: x < 0)))){
        return -1;
    }
    if ((MUTANT_NR == 22 ? x <= 0: (MUTANT_NR == 23 ? x >= 0: (MUTANT_NR == 24 ? false: x == 0)))){
        return 0;
    }
    if ((MUTANT_NR == 25 ? x <= 1: (MUTANT_NR == 26 ? x >= 1: (MUTANT_NR == 27 ? false: x == 1)))){
        return 1;
    }

    return (MUTANT_NR == 28 ? fibonacci(x - 1) - fibonacci(x - 2): (MUTANT_NR == 29 ? fibonacci(x - 1) * fibonacci(x - 2): (MUTANT_NR == 30 ? fibonacci(x - 1) / fibonacci(x - 2): (MUTANT_NR == 31 ? fibonacci(x - 1) % fibonacci(x - 2): (MUTANT_NR == 32 ? fibonacci(x - 1): (MUTANT_NR == 33 ? fibonacci(x - 2): fibonacci((MUTANT_NR == 34 ? x + 1: (MUTANT_NR == 35 ? x * 1: (MUTANT_NR == 36 ? x / 1: (MUTANT_NR == 37 ? x % 1: (MUTANT_NR == 38 ? x: (MUTANT_NR == 39 ? 1: x-1)))))))+fibonacci((MUTANT_NR == 40 ? x + 2: (MUTANT_NR == 41 ? x * 2: (MUTANT_NR == 42 ? x / 2: (MUTANT_NR == 43 ? x % 2: (MUTANT_NR == 44 ? x: (MUTANT_NR == 45 ? 2: x-2)))))))))))));
}
