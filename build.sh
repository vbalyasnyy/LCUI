#!/bin/bash -x

# sudo apt-get install libx11-dev libjpeg9-dev libpng-dev libxml2-dev

make distclean
./autogen.sh
./configure --with-jpeg --with-png --with-pthread --enable-debug --enable-video-output --enable-lcui-builder --with-x
make

#./configure --with-pthread --with-jpeg --enable-debug --enable-lcui-builder --enable-font-engine --with-x
