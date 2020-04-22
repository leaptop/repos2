
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

#include <cuda.h>
#include <stdio.h>

//#include <device_functions.h>
//#include <cuda_runtime_api.h>
#define SH_DIM 32

__global__ void gInitializeStorage(float* storage_d, int N)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    // цикл позволяет выбирать произвольное значение N, меньше
    // количества потоков в блоке, и больше общего количества потоков
    for (int iy = j; iy < N; iy += gridDim.y * blockDim.y)
    {
        for (int ix = i; ix < N; ix += gridDim.x * blockDim.x)
        {
            storage_d[ix + iy * N] = ix + iy * N;
        }
    }
}

__global__ void gTranspose0(float* storage_d, float* storage_d_t, int N)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    for (int iy = j; iy < N; iy += gridDim.y * blockDim.y)
    {
        for (int ix = i; ix < N; ix += gridDim.x * blockDim.x)
        {
            storage_d_t[iy + ix * N] = storage_d[ix + iy * N];
        }
    }
    __syncthreads();
}

__global__ void gTranspose1(float* storage_d, float* storage_d_t, int N)
{
    __shared__ float buffer[SH_DIM][SH_DIM];
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    for (int iy = j; iy < N; iy += gridDim.y * blockDim.y)
    {
        for (int ix = i; ix < N; ix += gridDim.x * blockDim.x)
        {
            buffer[threadIdx.y][threadIdx.x] = storage_d[ix + iy * N];
        }
    }
    __syncthreads();
    i = threadIdx.x + blockIdx.y * blockDim.x;
    j = threadIdx.y + blockIdx.x * blockDim.y;
    for (int iy = j; iy < N; iy += gridDim.y * blockDim.y)
    {
        for (int ix = i; ix < N; ix += gridDim.x * blockDim.x)
        {
            storage_d_t[ix + iy * N] = buffer[threadIdx.x][threadIdx.y];
        }
    }
    __syncthreads();
}

__global__ void gTranspose2(float* storage_d, float* storage_d_t, int N)
{
    __shared__ float buffer[SH_DIM][SH_DIM + 1];
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;
    for (int iy = j; iy < N; iy += gridDim.y * blockDim.y)
    {
        for (int ix = i; ix < N; ix += gridDim.x * blockDim.x)
        {
            buffer[threadIdx.y][threadIdx.x] = storage_d[ix + iy * N];
        }
    }
    __syncthreads();
    i = threadIdx.x + blockIdx.y * blockDim.x;
    j = threadIdx.y + blockIdx.x * blockDim.y;
    for (int iy = j; iy < N; iy += gridDim.y * blockDim.y)
    {
        for (int ix = i; ix < N; ix += gridDim.x * blockDim.x)
        {
            storage_d_t[ix + iy * N] = buffer[threadIdx.x][threadIdx.y];
        }
    }
    __syncthreads();
}

void Output(float* a, int N)
{
    for (int i = 0; i < N; i += N / 4)
    {
        for (int j = 0; j < N; j += N / 4)
        {
            printf("%10.0f\t", a[j + i * N]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "USAGE: matrix <dimension>\n");
        return -1;
    }
    int N = atoi(argv[1]);
    const int max_size = 1024;
    int size = N / 32 + (N % 32 > 0);
    int dim_of_blocks = (size > max_size) ? max_size : size;
    int dim_of_threads = 32;

    float* storage_d, * storage_d_t, * storage_h;
    cudaMalloc((void**)&storage_d, N * N * sizeof(float));
    cudaMalloc((void**)&storage_d_t, N * N * sizeof(float));
    storage_h = (float*)calloc(N * N, sizeof(float));

    gInitializeStorage << <dim3(dim_of_blocks, dim_of_blocks), dim3(dim_of_threads, dim_of_threads) >> > (storage_d, N);
    cudaThreadSynchronize();
    // cudaMemcpy(storage_h, storage_d, N * N * sizeof(float), cudaMemcpyDeviceToHost);
    // Output(storage_h, N);

    gTranspose0 << <dim3(dim_of_blocks, dim_of_blocks), dim3(dim_of_threads, dim_of_threads) >> > (storage_d, storage_d_t, N);
    cudaThreadSynchronize();
    // cudaMemcpy(storage_h, storage_d_t, N*N*sizeof(float), cudaMemcpyDeviceToHost);
    // Output(storage_h, N);

    gTranspose1 << <dim3(dim_of_blocks, dim_of_blocks), dim3(dim_of_threads, dim_of_threads) >> > (storage_d, storage_d_t, N);
    cudaThreadSynchronize();
    // cudaMemcpy(storage_h, storage_d_t, N*N*sizeof(float), cudaMemcpyDeviceToHost);
    // Output(storage_h, N);

    gTranspose2 << <dim3(dim_of_blocks, dim_of_blocks), dim3(dim_of_threads, dim_of_threads) >> > (storage_d, storage_d_t, N);
    cudaThreadSynchronize();
    // cudaMemcpy(storage_h, storage_d_t, N * N * sizeof(float), cudaMemcpyDeviceToHost);
    // Output(storage_h, N);

    cudaFree(storage_d);
    cudaFree(storage_d_t);
    free(storage_h);

    return 0;
}
