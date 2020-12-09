//
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
//
#include <stdio.h>
#include <cuda.h>
#include <Windows.h>
#include <time.h> 
#include <iostream>
//определил kernel для device
__global__ void sum(int* a, int* b, int N) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;//если координаты потока в блоке потоков в сумме с координатами блока потоков в сетке,
	//умноженными на размер блока потоков меньше N, то return
	if (i >= N) return;
	a[i] += b[i];
}
int main() {
	//выбрал device
	cudaSetDevice(0);//установил девайс для исполнения ГПУ команд
	//выделил память на device
	int N = 10000000;//размер векторов
	int* src_a, * src_b; int* dev_a, * dev_b;
	/*
	__host____device__cudaError_t cudaMalloc (void **devPtr, size_t size) Allocate memory on the device.
Parameters: devPtr - Pointer to allocated DEVICE memory; size - Requested allocation size in bytes
Returns cudaSuccess, cudaErrorInvalidValue, cudaErrorMemoryAllocation
Description: Allocates size bytes of linear memory on the device and returns in *devPtr a pointer to the allocated memory. 
The allocated memory is suitably aligned for any kind of variable. The memory is not cleared. 
cudaMalloc() returns cudaErrorMemoryAllocation in case of failure.
Modules
www.nvidia.com CUDA Runtime API vRelease Version | 127
The device version of cudaFree cannot be used with a *devPtr allocated using the host API, and vice versa.
	*/
	cudaMalloc(&dev_a, sizeof(int) * N);//выделил память на девайсе. //sizeof(int) = 4. Короче выделил памяти на N интов(1024)
	cudaMalloc(&dev_b, sizeof(int) * N);//Второй параметр - размер в байтах. причём память не обнулённая
	src_a = (int*)malloc(sizeof(int) * N); src_b = (int*)malloc(sizeof(int) * N);
	//for (int i = 0; i < N; i++) { src_a[i] = i; src_b[i] = N - i; }
	for (int i = 0; i < N; i++) { src_a[i] = rand(); src_b[i] = rand(); }
	//следующая функция копирует данные между хостом и девайсом:(в нашем случае с хоста на девайс)
	//Первый параметр - место назначения, второй - источник,
	//третий - размер для копирования в байтах, четвертый - тип передачи.
	/*
	__host__cudaError_t cudaMemcpy 
	(void *dst, const void *src, size_t count, cudaMemcpyKind kind)
Копирует count байт из памяти, на которую указывает src в память, на которую указывает
dst. kind определяет направление копирования и может быть только: cudaMemcpyHostToHost, cudaMemcpyHostToDevice, cudaMemcpyDeviceToHost, 
cudaMemcpyDeviceToDevice, or cudaMemcpyDefault. Рекомендовано использовать cudaMemcpyDefault, при котором направление определяется 
(угадывается) по значениям указателей.
	*/
	/*
	__host__cudaError_t cudaMemcpy (void *dst, const void *src, size_t count, cudaMemcpyKind kind) Copies data between host and device.
Parameters dst - Destination memory address src - Source memory address count - Size in bytes to copy kind - Type of transfer
Modules
www.nvidia.com CUDA Runtime API vRelease Version | 144
Returns cudaSuccess, cudaErrorInvalidValue, cudaErrorInvalidMemcpyDirection
Description: Copies ##count## bytes from the memory area pointed to by ###src### to the memory area pointed to by ###dst###, 
where ##kind## specifies the direction of the copy, and must be one of cudaMemcpyHostToHost, cudaMemcpyHostToDevice, cudaMemcpyDeviceToHost, 
cudaMemcpyDeviceToDevice, or cudaMemcpyDefault. Passing cudaMemcpyDefault is recommended, in which case the type of transfer 
is inferred from the pointer values. However, cudaMemcpyDefault is only allowed on systems that support unified 
virtual addressing. Calling cudaMemcpy() with dst and src pointers that do not match the direction of the copy results 
in an undefined behavior.
	*/
	////скопировал данные с host на device:
	cudaMemcpy(dev_a, src_a, sizeof(int) * N, cudaMemcpyHostToDevice);//выделяю память
	cudaMemcpy(dev_b, src_b, sizeof(int) * N, cudaMemcpyHostToDevice);

	//FILETIME createTime;
	//FILETIME exitTime;
	//FILETIME kernelTime;
	//FILETIME userTime;
	//if (GetProcessTimes(GetCurrentProcess(),
	//	&createTime, &exitTime, &kernelTime, &userTime) != -1)
	//{
	//	SYSTEMTIME userSystemTime;
	//	if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1)
	//		return (double)userSystemTime.wHour * 3600.0 +
	//		(double)userSystemTime.wMinute * 60.0 +
	//		(double)userSystemTime.wSecond +
	//		(double)userSystemTime.wMilliseconds / 1000.0;
	//}

	//time_t start, end;
	//time(&start);
	////getchar();//action	
	//time(&end);
	//double milliseconds = difftime(end, start);
	//printf("The time: %f seconds\n", milliseconds);

	LARGE_INTEGER t1, t2, f;
	QueryPerformanceCounter(&t1);
	int kernell_calls = 1000;
	//for (int i = 0; i < kernell_calls; i++)
	//{
		//sum << < (N + 255) / 256, 256 >> > (dev_a, dev_b, N);
		sum << < 1, N >> > (dev_a, dev_b, N);//как можно получить разное время для сложения двух векторов? Ведь в ГПУ это 
		//в любом случае выполнится за одно действие... Хотя походу нет... оно разделит таки на потоки все элементы по сколько-то там
	//}


		 // Launch the Vector Add CUDA Kernel
		int threadsPerBlock = 256;
		int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
		printf("CUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
		sum << <blocksPerGrid, threadsPerBlock >> > (dev_a, dev_b, N);
		


	
	QueryPerformanceCounter(&t2);
	QueryPerformanceFrequency(&f);
	double tm = double(t2.QuadPart - t1.QuadPart);// / f.QuadPart;
	std::cout << "\ntime " << tm;

// // Launch a kernel on the GPU with one thread for each element.
//    addKernel<<<1, size>>>(dev_c, dev_a, dev_b);//size здесь - это моё N
	
	/*
	__host____device__cudaError_t cudaDeviceSynchronize (void) Wait for compute device to finish.
Returns cudaSuccess
Description: Blocks until the device has completed all preceding requested tasks. 
cudaDeviceSynchronize() returns an error if one of the preceding tasks has failed. 
If the cudaDeviceScheduleBlockingSync flag was set for this device, the host thread will block until the device has finished its work.

	*/
	cudaDeviceSynchronize();
	cudaMemcpy(src_a, dev_a, sizeof(int) * N, cudaMemcpyDeviceToHost);
	
	
	//printf("sizeof(int) = %d", sizeof(int));
	//for (int i = 0; i < N; i++)//just to assure, that it works
	//	printf("\nsrc_a[%d] = %d", i, src_a[i]);
		
}
//
//cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size);
//
//__global__ void addKernel(int *c, const int *a, const int *b)
//{
//    int i = threadIdx.x;
//    c[i] = a[i] + b[i];
//}
//
//int main()
//{
//    const int arraySize = 5;
//    const int a[arraySize] = { 1, 2, 3, 4, 5 };
//    const int b[arraySize] = { 10, 20, 30, 40, 50 };
//    int c[arraySize] = { 0 };
//
//    // Add vectors in parallel.
//    cudaError_t cudaStatus = addWithCuda(c, a, b, arraySize);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "addWithCuda failed!");
//        return 1;
//    }
//
//    printf("{1,2,3,4,5} + {10,20,30,40,50} = {%d,%d,%d,%d,%d}\n",
//        c[0], c[1], c[2], c[3], c[4]);
//
//    // cudaDeviceReset must be called before exiting in order for profiling and
//    // tracing tools such as Nsight and Visual Profiler to show complete traces.
//    cudaStatus = cudaDeviceReset();
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaDeviceReset failed!");
//        return 1;
//    }
//
//    return 0;
//}
//
//// Helper function for using CUDA to add vectors in parallel.
//cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size)
//{
//    int *dev_a = 0;
//    int *dev_b = 0;
//    int *dev_c = 0;
//    cudaError_t cudaStatus;
//
//    // Choose which GPU to run on, change this on a multi-GPU system.
//    cudaStatus = cudaSetDevice(0);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
//        goto Error;
//    }
//
//    // Allocate GPU buffers for three vectors (two input, one output)    .
//    cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(int));
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMalloc failed!");
//        goto Error;
//    }
//
//    cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(int));
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMalloc failed!");
//        goto Error;
//    }
//
//    cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(int));
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMalloc failed!");
//        goto Error;
//    }
//
//    // Copy input vectors from host memory to GPU buffers.
//    cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMemcpy failed!");
//        goto Error;
//    }
//
//    cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(int), cudaMemcpyHostToDevice);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMemcpy failed!");
//        goto Error;
//    }
//
//    // Launch a kernel on the GPU with one thread for each element.
//    addKernel<<<1, size>>>(dev_c, dev_a, dev_b);
//
//    // Check for any errors launching the kernel
//    cudaStatus = cudaGetLastError();
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
//        goto Error;
//    }
//    
//    // cudaDeviceSynchronize waits for the kernel to finish, and returns
//    // any errors encountered during the launch.
//    cudaStatus = cudaDeviceSynchronize();
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
//        goto Error;
//    }
//
//    // Copy output vector from GPU buffer to host memory.
//    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMemcpy failed!");
//        goto Error;
//    }
//
//Error:
//    cudaFree(dev_c);
//    cudaFree(dev_a);
//    cudaFree(dev_b);
//    
//    return cudaStatus;
//}
