#!/bin/bash

cflags=$1
#mutantName=$1

pwd=$(pwd)
cd eqdetect_generated_files

for file_to_compile in *_klee_*;
#for file_to_compile in klee.cpp;
do
    mutant=$(ls | grep -e '_mutant_.*.cpp')
    #mutant=$(ls | grep -e 'mutant.cpp')
    echo $mutant
    #echo $mutantName

    cp $mutant ../saved_files/
    #mv ../saved_files/$mutant ../saved_files/$mutantName
    cp $file_to_compile ../saved_files/

    /usr/bin/clang -I $pwd/../klee_src/include/ -I $pwd/../src -I../$cflags -emit-llvm -c -g $file_to_compile
    file_to_run=$(ls | grep ".bc")
    if [[ $file_to_run != "" ]]
    then
        ~/Desktop/sommarjobb/klee_build_new_dir/bin/klee -exit-on-error-type=Assert -max-time=30 $file_to_run

        cd klee-out-0
        klee_fail_run=$(ls | grep ".err")

        if [[ $klee_fail_run = *".abort."* ]]
        then
            klee_fail_run=${klee_fail_run%%.*}
            klee_fail_out=$(ktest-tool --write-ints $klee_fail_run.ktest)

            echo "Abort:"$klee_fail_out >> ../../result.txt
            echo "Abort:"$klee_fail_out >> ../../results.txt

        elif [[ $klee_fail_run = *".assert."* ]]
        then
            klee_fail_run=${klee_fail_run%%.*}
            klee_fail_out=$(ktest-tool --write-ints $klee_fail_run.ktest)

            echo "Assert:"$klee_fail_out >> ../../result.txt
            echo "Assert:"$klee_fail_out >> ../../results.txt

        else
            if [[ $klee_fail_run == "" ]]
            then
                klee_fail_run=$(ls | grep ".early")
                if [[ $klee_fail_run == "" ]]
                then
                    echo "Eq:"$mutantName >> ../../result.txt
                    echo "Eq:"$mutantName >> ../../results.txt
                else
                    echo "Halt:"$file_to_compile >> ../../result.txt
                    echo "Halt:"$file_to_compile >> ../../results.txt
                fi
            else
                echo "ERROR:"$file_to_compile >> ../../result.txt
                echo "ERROR:"$file_to_compile >> ../../results.txt
            fi
        fi
    else
        echo "ERROR:"$file_to_compile >> ../result.txt
        echo "ERROR:"$file_to_compile >> ../results.txt
    fi



    cd ..
    rm $file_to_run
done

# remove the previously created temporary directory
rm -rf klee-out-* klee-last
