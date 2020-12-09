
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

#include <stdlib.h>
#include <math.h>
/*«адание 2: Х примен€€ двумерную индексацию нитей в блоке и блоков в гриде написать программу инициализации матрицы, сравнить эффективность кода €дра при двух различных линейных индексаци€х массива; Х написать программу транспонировани€ матрицы. ѕримечание: дл€ профилировани€ программы использовать nvprof и nvpp.
÷ель: изучить модель выполнени€ CUDA, варпы, совместный доступ к глобальной пам€ти. */
cudaError_t addWithCuda(int* c, const int* a, const int* b, unsigned int size);

__global__ void addKernel(int* c, const int* a, const int* b)
{
	int i = threadIdx.x;
	c[i] = a[i] + b[i];
}
//удобнее наверное всЄ таки одномерный массив использовать и вместе с ним передавать число - размер строки или столбца
__global__ void matrInit(int** a, int** b)
{
	//b[blockDim.x * blockIdx.x +  ]
}
__global__ void createMatrix(int* A, const int n)
{
	A[threadIdx.y * n + threadIdx.x] = 10 * threadIdx.y + threadIdx.x;
}

int main()
{/*
 *///задал переменные дл€ определени€ размеров двумерного массива на хосте и девайсе:
	const int dimThreadX = 6, dimThreadY = 6, dimBlockX = 4, dimBlockY = 4,
		sizeX = dimThreadX * dimBlockX, sizeY = dimThreadY * dimBlockY, sizeTotal = sizeX * sizeY;
	//int a_h[sizeX][sizeY];
	//int* h_a = (int*)malloc(sizeTotal * sizeof(int));
	int** h_a = new int* [sizeY];
	for (int i = 0; i < sizeX; i++)
	{//заполнил массив на хосте
		h_a[i] = new int[sizeX];
		for (int j = 0; j < sizeY; j++)
		{
			h_a[i][j] = (i + j);
		}
	}
	int** dev_a = 0;//сюда скопируем с хоста
	int** dev_b = 0;//сюда скопируем с девайса(на девайс)
	dim3 gridSize1 = dim3{ dimBlockX, dimBlockY, 1 };//задаю двумерную сетку блоков 4 на 4 - по блоку на мультипроцессор(в моей видеокарте 16)
	dim3 blockSize1 = dim3{ dimThreadX, dimThreadY, 1 };//MAX_THREADS_PER_BLOCK = 1024 дл€ моей видеокарты
	cudaError_t cudaStatus;
	cudaStatus = cudaSetDevice(0);//запускаю видеокарту
	if (cudaStatus != cudaSuccess) {//провер€ю есть ли ошибки
		fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
		//goto Error;
	}
	cudaStatus = cudaMalloc((void**)&dev_a, sizeTotal * sizeof(int));
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMalloc failed!");
		//goto Error;
	}
	cudaStatus = cudaMalloc((void**)&dev_b, sizeTotal * sizeof(int));
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMalloc failed!");
		//goto Error;
	}

	// Copy input vectors from host memory to GPU buffers.
	cudaStatus = cudaMemcpy(dev_a, h_a, sizeTotal * sizeof(int), cudaMemcpyHostToDevice);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMemcpy failed!");
		//goto Error;
	}

	matrInit << <gridSize1, blockSize1 >> > (dev_a, dev_a);


	//int x1 = 1024;//размер икс матрицы(по горизонтали)32*32. 
// int y1 = 1024;//размер игрек матрицы(по вертикали)

	const int arraySize = 5;
	const int a[arraySize] = { 1, 2, 3, 4, 5 };
	const int b[arraySize] = { 10, 20, 30, 40, 50 };
	int c[arraySize] = { 0 };

	// Add vectors in parallel.
	//cudaError_t cudaStatus = addWithCuda(c, a, b, arraySize);
	/*if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "addWithCuda failed!");
		return 1;
	}*/

	/*printf("{1,2,3,4,5} + {10,20,30,40,50} = {%d,%d,%d,%d,%d}\n",
		c[0], c[1], c[2], c[3], c[4]);*/

		// cudaDeviceReset must be called before exiting in order for profiling and
		// tracing tools such as Nsight and Visual Profiler to show complete traces.
	cudaStatus = cudaDeviceReset();
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaDeviceReset failed!");
		return 1;
	}

	return 0;
}

// Helper function for using CUDA to add vectors in parallel.
cudaError_t addWithCuda(int* c, const int* a, const int* b, unsigned int size)
{
	int* dev_a = 0;
	int* dev_b = 0;
	int* dev_c = 0;
	cudaError_t cudaStatus;

	// Choose which GPU to run on, change this on a multi-GPU system.
	cudaStatus = cudaSetDevice(0);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
		goto Error;
	}

	// Allocate GPU buffers for three vectors (two input, one output)    .
	cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(int));
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMalloc failed!");
		goto Error;
	}

	cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(int));
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMalloc failed!");
		goto Error;
	}

	cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(int));
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMalloc failed!");
		goto Error;
	}

	// Copy input vectors from host memory to GPU buffers.
	cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMemcpy failed!");
		goto Error;
	}

	cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(int), cudaMemcpyHostToDevice);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMemcpy failed!");
		goto Error;
	}

	// Launch a kernel on the GPU with one thread for each element.
	addKernel << <1, size >> > (dev_c, dev_a, dev_b);

	// Check for any errors launching the kernel
	cudaStatus = cudaGetLastError();
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
		goto Error;
	}

	// cudaDeviceSynchronize waits for the kernel to finish, and returns
	// any errors encountered during the launch.
	cudaStatus = cudaDeviceSynchronize();
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
		goto Error;
	}

	// Copy output vector from GPU buffer to host memory.
	cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMemcpy failed!");
		goto Error;
	}

Error:
	cudaFree(dev_c);
	cudaFree(dev_a);
	cudaFree(dev_b);

	return cudaStatus;
}
