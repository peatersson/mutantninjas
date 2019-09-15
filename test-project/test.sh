#!/bin/bash
set -e

pushd build/
ctest --output-on-failure -j4
popd
