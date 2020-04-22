// Сравнение двух матриц
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

__global__ void createMatrix(int* A, const int n)
{
	// Создание элементов матрицы на GPU
	A[threadIdx.y * n + threadIdx.x] = 10 * threadIdx.y + threadIdx.x;
}
int main()
{

	// кол-во строк и столбцов матрицы
	const int n = 32;
	// размер матрицы
	size_t size = n * n * sizeof(int);
	// выделяем память для матрицы на CPU
	int* h_A = (int*)malloc(size);
	// инициализируем матрицу
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			h_A[j * n + i] = 10 * j + i;

	int* d_B = NULL;
	// выделяем память для матрицы на GPU
	cudaMalloc((void**)&d_B, size);

	int* d_C = NULL;
	// выделяем память для матрицы на GPU
	cudaMalloc((void**)&d_C, size);

	int* d_D = NULL;
	// выделяем память для матрицы на GPU
	cudaMalloc((void**)&d_D, size);

	// определение размеров сетки и блоков
	dim3 threadsPerBlock = dim3(4, 25);
	dim3 threadsPerBlock2 = dim3(10, 10);
	dim3 blocksPerGrid = dim3(1);
	// вызов ядра

	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	// Начать отсчет времени
	cudaEventRecord(start, 0);
	createMatrix << <blocksPerGrid, threadsPerBlock2>> > (d_B, n);
	// Окончание работы ядра, остановка времени
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	float KernelTime;
	cudaEventElapsedTime(&KernelTime, start, stop);
	printf("KernelTime: %.10f milliseconds\n", KernelTime);


	cudaEvent_t start2, stop2;
	cudaEventCreate(&start2);
	cudaEventCreate(&stop2);
	cudaEventRecord(start2, 0);
	createMatrix << <blocksPerGrid, threadsPerBlock >> > (d_C, n);
	// Окончание работы ядра, остановка времени
	cudaEventRecord(stop2, 0);
	cudaEventSynchronize(stop2);
	float KernelTime2;
	cudaEventElapsedTime(&KernelTime2, start2, stop2);
	printf("KernelTime: %.10f milliseconds\n", KernelTime2);

	cudaEvent_t start3, stop3;
	cudaEventCreate(&start3);
	cudaEventCreate(&stop3);
	cudaEventRecord(start3, 0);
	createMatrix << <blocksPerGrid, threadsPerBlock2 >> > (d_D, n);
	// Окончание работы ядра, остановка времени
	cudaEventRecord(stop3, 0);
	cudaEventSynchronize(stop3);
	float KernelTime3;
	cudaEventElapsedTime(&KernelTime3, start3, stop3);
	printf("KernelTime: %.10f milliseconds\n", KernelTime3);


	//// выделяем память для матрицы B, чтобы скопировать из GPU на CPU
	//int* h_B = (int*)malloc(size);
	//// копируем матрицу из GPU на CPU
	//cudaMemcpy(h_B, d_B, size,
	//	cudaMemcpyDeviceToHost);
	//// проверяем совпадение матрицы А и матрицы В
	//for (int i = 0; i < n; i++)
	//	for (int j = 0; j < n; j++)
	//		if (h_A[j * n + i] != h_B[j * n + i]) {
	//			printf("h_A[%d] != h_B[%d]\n", j * n
	//				+ i, j * n + i);
	//		}
	// освобождаем память на GPU
	cudaFree(d_B);
	// освобождаем память на CPU
	free(h_A);
	//free(h_B);
	return 0;
}