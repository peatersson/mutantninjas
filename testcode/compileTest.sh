#!/bin/bash
export LD_LIBRARY_PATH=klee_build/klee/lib/:$LD_LIBRARY_PATH
FILE=${1?Error: No file given}
clang -I klee_src/include/ -L klee_build/klee/lib/ $FILE -lkleeRuntest
