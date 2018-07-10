#!/bin/bash

pwd=$(pwd)
cd mounted/eqdetect_generated_files

for file_to_compile in *_klee_*;
do
    clang -I $pwd/klee_src/include/ -emit-llvm -c -g $file_to_compile
    file_to_run=$(ls | grep ".bc")
    klee $file_to_run

    klee_fail_run=$(ls klee-last | grep ".err")
    klee_fail_run=${klee_fail_run%%.*}

    if [ $klee_fail_run ]
    then
        cd klee-last
        klee_fail_out=$(ktest-tool --write-ints $klee_fail_run.ktest)
        echo $klee_fail_out >> ../../errors.txt
        cd ..
    fi

    rm $file_to_run
done

# remove the previously created temporary directory
rm -rf klee-out-* klee-last
