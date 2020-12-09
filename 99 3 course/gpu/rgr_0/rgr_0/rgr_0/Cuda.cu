#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const size_t N = 1 << 20;//миллион
const size_t Nx = 1 << 10;//тысяча
const size_t Ny = 1 << 10;

__global__ void transpose(float* matrixOrigin, float* matrixRes)//транспонируем матрицу
{

	size_t x = blockIdx.x * blockDim.x + threadIdx.x;
	size_t y = blockIdx.y * blockDim.y + threadIdx.y;
	size_t width = gridDim.x * blockDim.x;

	matrixRes[x + y * width] = matrixOrigin[y + x * width];
}

__global__ void saxpy(float* vectorA, float* vectorB, float alpha)//
{
	size_t index = blockIdx.x * blockDim.x + threadIdx.x;
	vectorA[index] = vectorA[index] * alpha + vectorB[index];
}

int main()
{
	clock_t start = clock();
	for (int j = 0; j < 10; ++j)
	{

		cudaStream_t stream0;
		cudaStreamCreate(&stream0);
		float* matrix, * matrix_dev_origin, * matrix_dev_res;
		cudaHostAlloc((void**)&matrix, N * sizeof(float), cudaHostAllocDefault);
		for (int i = 0; i < N; ++i)
			matrix[i] = i;

		cudaMalloc((void**)&matrix_dev_origin, sizeof(float) * N);
		cudaMalloc((void**)&matrix_dev_res, sizeof(float) * N);

		cudaMemcpyAsync(matrix_dev_origin, matrix, sizeof(float) * N, cudaMemcpyHostToDevice, stream0);
		transpose << <dim3(Nx / 32, Ny / 32), dim3(32, 32) >> > (matrix_dev_origin, matrix_dev_res);
		cudaMemcpyAsync(matrix, matrix_dev_res, sizeof(float) * N, cudaMemcpyDeviceToHost, stream0);
		cudaStreamSynchronize(stream0);

		for (int i = 0; i < Ny; ++i)
		{
			for (int j = 0; j < Nx; ++j)
				printf("%f\t", matrix[i * Nx + j]);
			printf("\n");
		}

		cudaFree(matrix_dev_origin);
		cudaFree(matrix_dev_res);
		cudaFreeHost(matrix);
	}
	printf("transpose: ");
	printf("%d\n", clock() - start);
	start = clock();

	for (int j = 0; j < 10; ++j)
	{
		float* vecA, * vecB, * vecA_device, * vecB_device;
		cudaStream_t stream0;
		cudaStreamCreate(&stream0);
		cudaStream_t stream1;
		cudaStreamCreate(&stream1);
		cudaHostAlloc((void**)&vecA, N * sizeof(float), cudaHostAllocDefault);
		cudaHostAlloc((void**)&vecB, N * sizeof(float), cudaHostAllocDefault);

		for (int i = 0; i < N; ++i)
		{
			vecA[i] = i;
			vecB[i] = i * 2 - 1;
		}

		cudaMalloc((void**)&vecA_device, sizeof(float) * N);
		cudaMalloc((void**)&vecB_device, sizeof(float) * N);

		cudaMemcpyAsync(vecA_device, vecA, sizeof(int) * N, cudaMemcpyHostToDevice, stream0);
		cudaMemcpyAsync(vecB_device, vecB, sizeof(int) * N, cudaMemcpyHostToDevice, stream1);
		saxpy << <N / 2 / 1024, 1024, 0, stream0 >> > (vecA_device, vecB_device, 2.25);
		saxpy << <N / 2 / 1024, 1024, 0, stream1 >> > (vecA_device + N / 2, vecB_device + N / 2, 2.25);
		cudaMemcpyAsync(vecA, vecA_device, sizeof(float) * N / 2, cudaMemcpyDeviceToDevice, stream0);
		cudaMemcpyAsync(vecA + N / 2, vecA_device + N / 2, sizeof(float) * N / 2, cudaMemcpyDeviceToDevice, stream1);
		cudaStreamSynchronize(stream0);
		cudaStreamSynchronize(stream1);

		//for (int i = 0; i < N; ++i)
		//	printf("%f\t", vecA[i]);

		cudaFree(vecA_device);
		cudaFree(vecB_device);
		cudaFreeHost(vecA);
		cudaFreeHost(vecB);
	}
	printf("saxpy: ");
	printf("%d\n", clock() - start);
}
/*
transpose: 491044
saxpy: 89
*/