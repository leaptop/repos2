cmake_minimum_required(VERSION 3.15)
project(CTheoryAlg_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CTheoryAlg_master
        Complex.cpp
        Complex.h
        conv.cpp
        DFT.cpp
        DFT.h
        Furier.cpp)
