#!/bin/bash
FILE=${1?Error: No file given}
KTEST_FILE=$FILE ./a.out
echo $?
