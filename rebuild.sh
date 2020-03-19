#!/bin/bash -x

#make distclean
#./autogen.sh
#./configure --enable-debug
make -j8
pushd test
./test_block_layout
popd

