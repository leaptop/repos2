#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <algorithm>
#include <cuda.h>
#include <stdio.h>

__global__ void gpuAdd(float* gpuA, float* gpuB, float* gpuC)
{
	int id = threadIdx.x + blockDim.x * blockIdx.x;
	gpuC[id] = gpuA[id] * gpuB[id];
}

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		printf("Usage: %s [2^size] [tpb]\n", argv[0]);
		exit(1);
	}

	int size = 1 << atoi(argv[1]);//int atoi(const char *str) Функция atoi() конвертирует строку, на которую указывает параметр str, в величину типа int. Строка должна содержать корректную запись целого числа. В противном случае возвращается 0.
	int threads = atoi(argv[2]);
	if (size <= 0 || size >= 1000000000000000)
	{
		printf("Bad size (%d).\n", size);
		exit(1);
	}
	if (threads <= 0 || threads > 1024 || threads % 32 != 0)
	{
		printf("Bad threads-per-block (%d).\n", threads);
		exit(1);
	}

	// Создаем обычный огромный массив в оперативной памяти.
	float* cpuFilled = (float*)malloc(size * sizeof(float));
	float* cpuEmpty = (float*)calloc(size, sizeof(float));
	float* cpuResult = (float*)malloc(size * sizeof(float));
	if (cpuFilled == NULL || cpuEmpty == NULL || cpuResult == NULL)
	{
		printf("malloc error.\n");
		exit(1);
	}

	// Заполняем этот массив.
	for (int i = 0; i < size; ++i)
	{
		cpuFilled[i] = float(i);
	}

	// Создаем три огромных массива на видеокарте.
	float* gpuA;
	float* gpuB;
	float* gpuC;
	int test1 = cudaMalloc((void**)&gpuA, size * sizeof(float));
	int test2 = cudaMalloc((void**)&gpuB, size * sizeof(float));
	int test3 = cudaMalloc((void**)&gpuC, size * sizeof(float));
	if (test1 == cudaErrorMemoryAllocation ||
		test2 == cudaErrorMemoryAllocation ||
		test3 == cudaErrorMemoryAllocation)
	{
		printf("cudaMalloc error (%d %d %d).\n", test1, test2, test3);
		exit(1);
	}

	// Два из них - копии того же массива из оперативы.
	// В третьем будет храниться текущий результат.
	cudaMemcpy(gpuA, cpuFilled, size * sizeof(float),
		cudaMemcpyHostToDevice);
	cudaMemcpy(gpuB, cpuFilled, size * sizeof(float),
		cudaMemcpyHostToDevice);

	// Запускаем цикл по числу элементов от минимума до максимума.
	//считаем число блоков исходя из размера одного блока, заданного в командной строке
	int blockCount = std::max(1, size / threads);//std::max - Определён в заголовочном файле <algorithm> - Возвращает большее из двух значений.
	//printf(" %6d blocks x %4d threads: ", blockCount, threads);
	if (blockCount < 1 && blockCount > 65535)
	{
		printf("Bad block count (%d).\n", blockCount);
		exit(1);
	}
	if (threads < 1 && threads > 1024)
	{
		printf("Bad threads-per-block count (%d).\n", threads);
		exit(1);
	}

	cudaMemcpy(gpuC, cpuEmpty, size * sizeof(float),
		cudaMemcpyHostToDevice);

	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	cudaEventRecord(start, 0);
	cudaEventSynchronize(start);
	gpuAdd << < dim3(blockCount), dim3(threads) >> > (gpuA, gpuB, gpuC);
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);

	float elapsedTime = 0.0f;
	cudaEventElapsedTime(&elapsedTime, start, stop);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);

	//cudaDeviceReset();
	cudaMemcpy(cpuResult, gpuC, size * sizeof(float),
		cudaMemcpyDeviceToHost);

	// Освобождаем память.
	cudaFree(gpuA);
	cudaFree(gpuB);
	cudaFree(gpuC);
	free(cpuFilled);
	free(cpuEmpty);
	free(cpuResult);

	return 0;
}
