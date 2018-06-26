#!/bin/bash
FILE=${1?Error: No file given}
ktest-tool --write-ints $FILE
