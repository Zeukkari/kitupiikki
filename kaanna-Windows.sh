#!/bin/bash

#
#   Windows release 
#

BUILD_DIR=build-windows
DIST_DIR=dist

mkdir -p $BUILD_DIR
cd $BUILD_DIR

export PATH=/opt/mxe/usr/bin:$PATH

touch ../kitupiikki/versio.h

/opt/mxe/usr/i686-w64-mingw32.static/qt5/bin/qmake ../kitupiikki/kitupiikki.pro  "CONFIG += release"
make -j 6
cp release/kitupiikki.exe ../$DIST_DIR

cd ../$DIST_DIR

upx -9 -f -o kitupiikkiX.X.exe kitupiikki.exe
