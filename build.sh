#!/bin/bash
/home/dev/Qt/5.14.2/gcc_64/bin/qmake TestApp.pro
make clean
make -j4
