cmake_minimum_required(VERSION 3.13)
project(trust_sample CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(trust_sample main.cu)

set_target_properties(
        trust_sample
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)