#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

#include <cuda.h>
#include <Windows.h>
#include <time.h> 
#include <iostream>
#include <fstream>

//КОД ИЗ ЛЕКЦИИ №4
#define N 3
#define M 512
__global__ void gTest() {
	__shared__ float s[N][M];
	//.....................
}

extern __shared__ float s[];
__global__ void gTest2() {
	float* a = (float*)s;
	float* b = (float*)&s[512];
	float* c = (float*)&s[1024];
	//.....................
}
//gTest2 << <100, 32, N* M * sizeof(float) >> > ();// 3-й параметр - размер разделяемой памяти
//ВЫВОД МАТРИЦЫ:
#include <stdio.h>
void Output(float* a, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			fprintf(stdout, "%g\t", a[j + i * N]);
		fprintf(stdout, "\n");		
	}
	fprintf(stdout, "\n\n\n");
}
cudaError_t addWithCuda(int* c, const int* a, const int* b, unsigned int size);

__global__ void addKernel(int* c, const int* a, const int* b)
{
	int i = threadIdx.x;
	c[i] = a[i] + b[i];
}
// КОД ИЗ ЛЕКЦИИ №3:
__global__ void gTest1(float* a) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	int j = threadIdx.y + blockIdx.y * blockDim.y;
	int I = gridDim.x * blockDim.x;
	//int J=gridDim.y*blockDim.y;    
	a[i + j * I] = (float)(threadIdx.x + blockDim.y * blockIdx.x);
}

__global__ void gTest2(float* a) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	int j = threadIdx.y + blockIdx.y * blockDim.y;
	//int I=gridDim.x*blockDim.x;  
	int J = gridDim.y * blockDim.y;
	a[j + i * J] = (float)(threadIdx.y + threadIdx.x * blockDim.y);
}
//КОД ИЗ ЛЕКЦИИ №4:
cudaDeviceSetCacheConfig(cudaFuncCachePreferL1);
__global__void gTest(...) {
	........
		return;
}
int main() {
	cudaFuncSetCacheConfig(gTest, cudaFuncCachePreferL1);
	//.............................................
	gTest << <num_th, num_bl >> > (...);
	return 0;
}

//int n = 1000000;
//float* a;
//
//int N = 0;//размер векторов
//int* src_a, * src_b; int* dev_a, * dev_b;
//LARGE_INTEGER t1, t2, f, t3, t4, t5, t6, t7, t8;
//int* blocksPerGrid_gl, * threadsPerBlock_gl, * N_gl;
//double* time_gl;
//int i_gl = 1;
//int num = 15;
//void allocateMemory(int n) {
//	cudaMalloc(&a, sizeof(float) * n);
//	a = (float*)malloc(sizeof(float) * n);
//	//src_b = (int*)malloc(sizeof(int) * N);
//	for (int i = 0; i < n; i++) { a[i] = rand(); // b[i] = rand(); 
//	}
//}
//void launchKernel(int N, int threadsPerBlock, double* time_gl, int* N_gl) {
//	int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
//	printf("\nCUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
//	QueryPerformanceCounter(&t3);//максимальное число тредов(второй параметр) - 1024
//	//sum << <blocksPerGrid, threadsPerBlock >> > (dev_a, dev_b, N);
//	gTest1 << <blocksPerGrid, threadsPerBlock >> > (a);
//	cudaDeviceSynchronize();
//	QueryPerformanceCounter(&t4);
//	double tm = double((t4.QuadPart - t3.QuadPart) / (double)2600);// / f.QuadPart;// TRANSLATING TACTS TO MILLISECONDS
////	std::cout << "threadsPerBlock: " << threadsPerBlock << ", time: " << tm << "\n";
//	time_gl[i_gl] = tm;
//	N_gl[i_gl] = N; i_gl++;
//}
//void testFunction() {
//	int threadsPerblock_local = 1;
//	std::ofstream out;          // поток для записи
//
//	//out.open("C:\\Users\\stepa\\repos2\\gpu\\lab1_01\\lab1_01\\results.txt"); // окрываем файл для записи
//	out.open("..\\results.txt"); // окрываем файл для записи
//
//	for (int i_thr = threadsPerblock_local; i_thr < 1024; i_thr *= 2)//графиков д.б. столько, сколько у меня конфигураций нитей - 10
//	{
//		if (out.is_open())
//		{
//			//out << "\n\n" << std::endl;
//		}
//		N_gl = (int*)std::malloc(num * sizeof(int));
//		time_gl = (double*)std::malloc(num * sizeof(double));
//		//для  числа тредов: ...
//		for (int i_N = 1 << 10; i_N <= 1 << 23; i_N *= 2)//доходим до максимального числа потоков// всё таки по заданию пройтись надо по размерам векторов
//		{//при этом также взять разные конфигурации нитей... пусть их будут 3
//			allocateMemory(i_N);// по заданию размер массива может быть от 1<<10 до 1<<23
//			launchKernel(i_N, i_thr, time_gl, N_gl);
//		}
//		//std::cout << "\n\narrSize N   time , threadsPerblock_local = " << i_thr;
//		//out << std::endl << "arrSizeN time threadsPerblock_local=" << i_thr;
//		//for (int ipi = 1; ipi < num; ipi++)
//		//{
//		//	std::cout << std::endl << N_gl[ipi] << "    " << time_gl[ipi];
//		//	out << std::endl << N_gl[ipi] << " " << time_gl[ipi];
//		//}
//		free(N_gl);
//		free(time_gl);
//		i_gl = 1;
//
//	}
//}
//
//int main()
//{
//	cudaSetDevice(0);//установил девайс для исполнения ГПУ команд
//	int size0 = 1024;//макс число нитей?
//	//allocateMemory(n);
//
//	testFunction();
//
//	/*const int arraySize = 5;
//	const int a[arraySize] = { 1, 2, 3, 4, 5 };
//	const int b[arraySize] = { 10, 20, 30, 40, 50 };
//	int c[arraySize] = { 0 };*/
//
//	// Add vectors in parallel.
//	/*cudaError_t cudaStatus = addWithCuda(c, a, b, arraySize);
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "addWithCuda failed!");
//		return 1;
//	}*/
//
//	//printf("{1,2,3,4,5} + {10,20,30,40,50} = {%d,%d,%d,%d,%d}\n",
//		//c[0], c[1], c[2], c[3], c[4]);
//
//	// cudaDeviceReset must be called before exiting in order for profiling and
//	// tracing tools such as Nsight and Visual Profiler to show complete traces.
//	/*cudaStatus = cudaDeviceReset();
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaDeviceReset failed!");
//		return 1;
//	}*/
//
//	return 0;
//}
//
//// Helper function for using CUDA to add vectors in parallel.
//cudaError_t addWithCuda(int* c, const int* a, const int* b, unsigned int size)
//{
//	int* dev_a = 0;
//	int* dev_b = 0;
//	int* dev_c = 0;
//	cudaError_t cudaStatus;
//
//	// Choose which GPU to run on, change this on a multi-GPU system.
//	cudaStatus = cudaSetDevice(0);
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
//		goto Error;
//	}
//
//	// Allocate GPU buffers for three vectors (two input, one output)    .
//	cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(int));
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaMalloc failed!");
//		goto Error;
//	}
//
//	cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(int));
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaMalloc failed!");
//		goto Error;
//	}
//
//	cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(int));
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaMalloc failed!");
//		goto Error;
//	}
//
//	// Copy input vectors from host memory to GPU buffers.
//	cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaMemcpy failed!");
//		goto Error;
//	}
//
//	cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(int), cudaMemcpyHostToDevice);
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaMemcpy failed!");
//		goto Error;
//	}
//
//	// Launch a kernel on the GPU with one thread for each element.
//	//addKernel << <1, size >> > (dev_c, dev_a, dev_b);
//
//	// Check for any errors launching the kernel
//	cudaStatus = cudaGetLastError();
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
//		goto Error;
//	}
//
//	// cudaDeviceSynchronize waits for the kernel to finish, and returns
//	// any errors encountered during the launch.
//	cudaStatus = cudaDeviceSynchronize();
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
//		goto Error;
//	}
//
//	// Copy output vector from GPU buffer to host memory.
//	cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
//	if (cudaStatus != cudaSuccess) {
//		fprintf(stderr, "cudaMemcpy failed!");
//		goto Error;
//	}
//
//Error:
//	cudaFree(dev_c);
//	cudaFree(dev_a);
//	cudaFree(dev_b);
//
//	return cudaStatus;
//}
