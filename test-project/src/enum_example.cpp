extern int MUTANT_NR;
#ifndef schemata_h
#define schemata_h
#include <cstdlib>

extern int MUTANT_NR;
/*
static void __SchemataInit() __attribute__(( constructor ));

static void __SchemataInit(){
  MUTANT_NR = std::atoi(getenv("MUTANT_NR"));
  }*/
#endif

int enum_example(int x){
    enum Enum {
        Off,
        Ready,
        Steady,
        Go,
    };

    Enum module = Off;

    switch (x) {
        case 0:
            module = Off;
            break;
        case 1:
            module = Ready;
            break;
        case 2:
            module = Steady;
            break;
        case 3:
            module = Go;
            break;
        default:
            break;
    };

    if((MUTANT_NR == 18 ? module <= Off: (MUTANT_NR == 18 ? module >= Off: (MUTANT_NR == 18 ? false: module == Off)))){
        return 3;
    }
    else if((MUTANT_NR == 18 ? module <= Ready: (MUTANT_NR == 18 ? module >= Ready: (MUTANT_NR == 18 ? false: module == Ready)))){
        return 4;
    }
    else if((MUTANT_NR == 18 ? module <= Steady: (MUTANT_NR == 18 ? module >= Steady: (MUTANT_NR == 18 ? false: module == Steady)))){
        return 7;
    }
    else{
        return 1;
    }
}
