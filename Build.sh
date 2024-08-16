#!/usr/bin/env bash

cmake -B ./build -S .
(cd build && make -j)