#include <klee/klee.h>
#include <assert.h>

int get_sign(int x){
  if (x == 0){
    return 0;
  } else if (x < 0){
    return -1;
  } else {
    return 1;
  }
}

int get_sign_mut(int x){
  if (x >= 0){
    return 0;
  } else if (x < 0){
    return -1;
  } else {
    return 1;
  }
}

int main(){
  int var;
  klee_make_symbolic(&var, sizeof(int), "var");

  if (get_sign(var) == get_sign_mut(var)){
    return 1;
  } else {
    klee_assert(0);
    return 0;
  }
}
