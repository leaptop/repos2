#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
// ������ �����
#define BLOCK_SIZE 16
// ���, ������� ����� ����� �������� ������
#define BASE_TYPE float
// ����
// ������� ���������������� �������
__global__ void matrixTranspose(const BASE_TYPE* A,  BASE_TYPE* AT, int rows, int cols)
{
    // ������ �������� � �������� �������
    int iA = cols * (blockDim.y * blockIdx.y + threadIdx.y) + blockDim.x * blockIdx.x + threadIdx.x;
    // ������ ���������������� �������� � ����������������� �������
    int iAT = rows * (blockDim.x * blockIdx.x +
        threadIdx.x) + blockDim.y * blockIdx.y +
        threadIdx.y;
  
        AT[iAT] = A[iA];
}
// ������� ���������� �����, ������� ������ ����� � � ������� ����� b
int toMultiple(int a, int b)
{
    int mod = a % b;
    if (mod != 0)
    {
        mod = b - mod;
        return a + mod;
    }
    return a;
}
int main()
{
    // ������� �������
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    // ���������� ����� � �������� �������
    int rows = 1000;
    int cols = 2000;
    // ������ ���������� ����� � �������� ������� �� �����, ������� ������� ����� (16)
    rows = toMultiple(rows, BLOCK_SIZE);
    printf("rows = %d\n", rows);
    cols = toMultiple(cols, BLOCK_SIZE);
    printf("cols = %d\n", cols);
    size_t size = rows * cols * sizeof(BASE_TYPE);
    // ��������� ������ ��� ������� �� ����� �������� �������
    BASE_TYPE* h_A = (BASE_TYPE*)malloc(size);

    // ����������������� �������
    BASE_TYPE* h_AT = (BASE_TYPE*)malloc(size);
    // ������������� �������
    for (int i = 0; i < rows * cols; ++i)
    {
        h_A[i] = rand() / (BASE_TYPE)RAND_MAX;
    }
    // ��������� ���������� ������ �� �������
    // ��� �������� �������
    BASE_TYPE* d_A = NULL;
    cudaMalloc((void**)&d_A, size);
    // ��������� ���������� ������ �� ������� ��� ����������������� �������
    BASE_TYPE* d_AT = NULL;
    cudaMalloc((void**)&d_AT, size);
    // �������� ������� �� CPU �� GPU
    cudaMemcpy(d_A, h_A, size,
        cudaMemcpyHostToDevice);
    // ���������� ������ ����� � �����
    dim3 threadsPerBlock = dim3(BLOCK_SIZE,
        BLOCK_SIZE);
    dim3 blocksPerGrid = dim3(cols / BLOCK_SIZE,
        rows / BLOCK_SIZE);
    // ������ ������ �������
    cudaEventRecord(start, 0);
    // ������ ����
    matrixTranspose << <blocksPerGrid,  threadsPerBlock >> > (d_A, d_AT, rows, cols);
    // ��������� ������ ����, ��������� �������
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    float KernelTime;
    cudaEventElapsedTime(&KernelTime, start, stop);
    printf("KernelTime: %.2f milliseconds\n", KernelTime);
    // �������� ������� �� GPU �� CPU
    cudaMemcpy(h_AT, d_AT, size,
        cudaMemcpyDeviceToHost);
    // �������� ������������ ������ ����
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            if (h_A[i * cols + j] != h_AT[j * rows + i]) {
                fprintf(stderr, "Result verification    failed at element[% d, % d]!\n", i, j);
                exit(EXIT_FAILURE);
            }
            printf("Test PASSED\n");
            // ����������� ������ �� GPU
            cudaFree(d_A);
            // ����������� ������ �� GPU
            cudaFree(d_AT);
            // ����������� ������ �� CPU
            free(h_A);
            free(h_AT);
            // ������� ������� �������
            cudaEventDestroy(start);
            cudaEventDestroy(stop);
            printf("Done\n");
            return 0;
        }
}