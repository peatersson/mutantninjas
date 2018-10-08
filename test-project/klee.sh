#!/bin/bash

pwd=$(pwd)
cd mounted/eqdetect_generated_files

for file_to_compile in *_klee_*;
do
    clang -I $pwd/klee_src/include/ -emit-llvm -c -g $file_to_compile
    file_to_run=$(ls | grep ".bc")
    klee -max-time=100 $file_to_run

    cd klee-out-0
    klee_fail_run=$(ls | grep ".err")

    if [[ $klee_fail_run = *".abort."* ]]
    then
        klee_fail_run=${klee_fail_run%%.*}
        klee_fail_out=$(ktest-tool --write-ints $klee_fail_run.ktest)

        echo "Abort:"$klee_fail_out >> ../../result.txt

    elif [[ $klee_fail_run = *".assert."* ]]
    then
        klee_fail_run=${klee_fail_run%%.*}
        klee_fail_out=$(ktest-tool --write-ints $klee_fail_run.ktest)

        echo "Assert:"$klee_fail_out >> ../../result.txt
    else
        klee_fail_run=$(ls | grep ".early")

        if [ $klee_fail_run ]
        then
            echo "Halt:"$file_to_compile >> ../../result.txt
        else
            echo "Eq:"$file_to_compile >> ../../result.txt
        fi

    fi

    cd ..
    rm $file_to_run
done

# remove the previously created temporary directory
rm -rf klee-out-* klee-last
