#!/bin/sh
INSTALL_DIR=/usr/local/lib
CUR_DIR=`pwd`
echo $CUR_DIR

if [ ! -d  $(${CUR_DIR}/libsnark)]; then
    git clone https://github.com/scipr-lab/libsnark/
    cd $CUR_DIR/libsnark && git submodule init && git submodule update

else
    cd $CUR_DIR/libsnark
fi

# if build dir is not exist
if [ ! -d $(${CUR_DIR}/libsnark/build)];then
    echo "create a build directory"
    mkdir ${CUR_DIR}/libsnark/build && cd $CUR_DIR/libsnark/build && cmake ..
else 
    mkdir ${CUR_DIR}/libsnark/build
    cd $CUR_DIR/libsnark/build && cmake ..
fi

make 
make check

