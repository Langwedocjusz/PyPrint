#!/usr/bin/env bash

for dir in "include" "tests"; do
    for file in $(find $dir -iname '*.h' -o -iname '*.cpp'); do
        clang-format -i $file
    done
done