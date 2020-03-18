#!/bin/bash -x

make distclean
./autogen.sh
./configure --enable-debug
make -j8

