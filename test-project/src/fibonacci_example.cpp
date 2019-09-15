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
    if(x < 0){
        return -1;
    }
    if (x == 0){
        return 0;
    }
    if (x == 1){
        return 1;
    }

    return fibonacci(x-1)+fibonacci(x-2);
}
