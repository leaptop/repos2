
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

#include <cublas_v2.h>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstddef>

int main()
{
    size_t Nx = 1 << 10;
    size_t Ny = 1 << 10;
    size_t N = 1 << 20;
    clock_t start = clock();
    cublasHandle_t handle;
    cublasCreate(&handle);
    float* matrix;
    cudaMallocHost((void**)&matrix, N * sizeof(float));
    for (int i = 0; i < N; ++i)
        matrix[i] = (float)i;
    float* matrix_in_dev;
    cudaMalloc((void**)&matrix_in_dev, N * sizeof(float));
    float* matrix_out_dev;
    cudaMalloc((void**)&matrix_out_dev, N * sizeof(float));
    cublasSetMatrix(Ny, Nx, sizeof(float), matrix, Ny, matrix_in_dev, Ny);
    float alpha = 1.;
    float beta = 0.;
    cublasSgeam(handle, CUBLAS_OP_T, CUBLAS_OP_T, Nx, Ny, &alpha, matrix_in_dev, Ny, &beta, matrix_in_dev, Ny, matrix_out_dev, Nx);
    cublasGetMatrix(Ny, Nx, sizeof(float), matrix_out_dev, Ny, matrix, Ny);
    cudaStreamSynchronize(NULL);
    //        for (int i = 0; i < Ny; ++i)
    //        {
    //            for (int j = 0; j < Nx; ++j)
    //                printf("%f\t", matrix[j + i * Ny]);
    //            printf("\n");
    //        }
    cudaFreeHost(matrix);
    cudaFree(matrix_in_dev);
    cudaFree(matrix_out_dev);
    cublasDestroy(handle);
    printf("%ld\n", (clock() - start));
    start = clock();
    cublasHandle_t handle1;
    cublasCreate(&handle1);
    float* vecA;
    cudaMallocHost((void**)&vecA, N * sizeof(float));
    float* vecB;
    cudaMallocHost((void**)&vecB, N * sizeof(float));
    for (int i = 0; i < N; ++i)
    {
        vecA[i] = (float)i;
        vecB[i] = (float)(i * 2 - 1);
    }
    float* vec_A_dev;
    cudaMalloc((void**)&vec_A_dev, N * sizeof(float));
    float* vec_B_dev;
    cudaMalloc((void**)&vec_B_dev, N * sizeof(float));
    cublasSetMatrix(N, 1, sizeof(float), vecA, N, vec_A_dev, N);
    cublasSetMatrix(N, 1, sizeof(float), vecB, N, vec_B_dev, N);
    float alpha1 = 2.25;
    cublasSaxpy(handle1, N, &alpha1, vec_A_dev, 1, vec_B_dev, 1);
    cublasGetMatrix(N, 1, sizeof(float), vec_B_dev, N, vecB, N);
    cudaStreamSynchronize(NULL);
    //for (int i = 0; i < N; ++i)
    //	printf("%f\n", vecB[i]);
    cublasDestroy(handle1);
    cudaFreeHost(vecA);
    cudaFreeHost(vecB);
    cudaFree(vec_A_dev);
    cudaFree(vec_B_dev);
    printf("%d", (clock() - start));
}
