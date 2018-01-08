#!/bin/zsh
cd ..
uic pclviewer.ui > ui_pclviewer.h
cp ui_pclviewer.h build/
cd build
make -j4
./pcl_visualizer
