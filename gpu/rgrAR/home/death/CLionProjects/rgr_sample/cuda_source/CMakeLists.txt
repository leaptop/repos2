cmake_minimum_required(VERSION 3.13)
project(cuda_source CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(cuda_source main.cu)

set_target_properties(
        cuda_source
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)