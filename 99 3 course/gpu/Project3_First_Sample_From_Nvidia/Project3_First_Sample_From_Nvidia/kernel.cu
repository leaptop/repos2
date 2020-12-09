#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <cstdlib> //добавил для malloc
#include <algorithm>
#include <iostream>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))//это пришлось загуглить и вставить, чтобы max работало

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

__global__//так мы объявляем kernel - функцию для выполнения ГПУ
void saxpy(int n, float a, float* x, float* y)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) y[i] = a * x[i] + y[i];
}

int main(void)
{
    int N = 1 << 20;
    //The main function declares two pairs of arrays.
    float* x, * y, * d_x, * d_y;
    //указатели икс и игрек указывают на host массивы, выделенные с помощью 
    //malloc в обычном виде 
    // а d_x, d_y указывают на device массивы(в видюхе)
    x = (float*)malloc(N * sizeof(float));
    y = (float*)malloc(N * sizeof(float));

    cudaMalloc(&d_x, N * sizeof(float));
    cudaMalloc(&d_y, N * sizeof(float));

    for (int i = 0; i < N; i++) {
        x[i] = 1.0f;
        y[i] = 2.0f;
    }

    cudaMemcpy(d_x, x, N * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, N * sizeof(float), cudaMemcpyHostToDevice);

    // Perform SAXPY on 1M elements
    saxpy << <(N + 255) / 256, 256 >> > (N, 2.0f, d_x, d_y);//эта ошибка на удивление съедается компилятором и всё работает в примерах от нвидиа

    cudaMemcpy(y, d_y, N * sizeof(float), cudaMemcpyDeviceToHost);

    float maxError = 0.0f;
    for (int i = 0; i < N; i++)
        maxError = MAX(maxError, abs(y[i] - 4.0f));
    printf("Max error: %f\n", maxError);

    cudaFree(d_x);
    cudaFree(d_y);
    free(x);
    free(y);
}