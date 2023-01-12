#!/bin/bash

cmake -H. -Bbuild/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_CXX_COMPILER=clang++-14
cd build/
make
cd ../
