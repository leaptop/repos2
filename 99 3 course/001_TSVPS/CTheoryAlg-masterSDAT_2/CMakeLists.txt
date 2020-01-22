cmake_minimum_required(VERSION 3.15)
project(CTheoryAlg_masterSDAT_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CTheoryAlg_masterSDAT_2
        Complex.cpp
        Complex.h
        conv.cpp
        DFT.cpp
        DFT.h
        Furier.cpp)
