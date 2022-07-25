cmake_minimum_required(VERSION 3.22)
project(ASCIIExperiments)
set(CMAKE_CXX_STANDARD 17)

set(EasyBMP
        lib/EasyBMP/EasyBMP.cpp
        lib/EasyBMP/EasyBMP.h
        lib/EasyBMP/EasyBMP_BMP.h
        lib/EasyBMP/EasyBMP_DataStructures.h
        lib/EasyBMP/EasyBMP_VariousBMPutilities.h)

add_executable(untitled src/main.cpp ${EasyBMP})