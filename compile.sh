#!/bin/sh

CUR_DIR=`pwd`
echo $CUR_DIR

if [ -d $(${CUR_DIR}/build)]; then
    mkdir $CUR_DIR/build
    cd $CUR_DIR/build && cmake ..
else
    cd $CUR_DIR/build && cmake ..
fi

make
./src/main
