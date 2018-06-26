#!/bin/bash
FILE=${1?Error: No file given}
clang -I klee_src/include/ -emit-llvm -c -g $FILE
