#!/bin/bash
set -e

pushd build/
make -j$(nproc)
popd
