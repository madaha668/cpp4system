#!/bin/bash

clang++-19  -stdlib=libc++ -fexperimental-library -I$HOME/src/include $1.cpp -o $1.exe -Wall -std=c++23 -g
