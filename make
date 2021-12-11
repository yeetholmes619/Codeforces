#!/bin/bash

args=("$@")
contest=${args[0]}
mkdir $contest
cd $contest
cp ../basic.cpp a.cpp
cp ../basic.cpp b.cpp
cp ../basic.cpp c.cpp
cp ../basic.cpp d.cpp
cp ../basic.cpp e.cpp
cp ../basic.cpp f.cpp
cp ../compile compile
cp ../compile debug
chmod +x compile
chmod +x debug
./debug a.cpp
./compile a.cpp
