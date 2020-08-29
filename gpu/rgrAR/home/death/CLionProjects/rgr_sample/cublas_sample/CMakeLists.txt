cmake_minimum_required(VERSION 3.13)
project(cublas_sample CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(cublas_sample main.cu)

target_link_libraries(cublas_sample -lcublas)

set_target_properties(
        cublas_sample
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)