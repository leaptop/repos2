//
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
//
#include <stdio.h>
#include <cuda.h>
#include <Windows.h>
#include <time.h> 
#include <iostream>
#include <fstream>///��� � ���� ������? (��� �� ������ 2)
__global__ void sum(int* a, int* b, int N) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;//���� ���������� ������ � ����� ������� � ����� � ������������ ����� ������� � �����,
	//����������� �� ������ ����� ������� ������ N, �� return
	if (i >= N) return;
	a[i] += b[i];
}
	//const char* cudaGetErrorString(cudaError_t error)- ���������� ��������� � ����� ������ error. 
//����� ���������� �����-�� ���� ���������...
#define CUDA_CHECK_RETURN(value) {\
cudaError_t _m_cudaStat=value;\ 
if(_m_cudaStat != cudaSuccess) {\
fprintf(stderr, "Error %s at line %d in file %s\n",\
cudaGetErrorString(_m_cudaStat), __LINE__, __FILE__);\
exit(1);\
}}

//��������� kernel ��� device

int N = 0;//������ ��������
int* src_a, * src_b; int* dev_a, * dev_b;
LARGE_INTEGER t1, t2, f, t3, t4, t5, t6, t7, t8;
int* blocksPerGrid_gl, * threadsPerBlock_gl, * N_gl;
float* time_gl;
int i_gl = 1;
int num = 15;
void allocateMemory(int N) {
	CUDA_CHECK_RETURN(cudaMalloc(&dev_a, sizeof(int) * N));
	//cudaMalloc(&dev_a, sizeof(int) * N);
	cudaMalloc(&dev_b, sizeof(int) * N);
	src_a = (int*)malloc(sizeof(int) * N); src_b = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) { src_a[i] = rand(); src_b[i] = rand(); }
	cudaMemcpy(dev_a, src_a, sizeof(int) * N, cudaMemcpyHostToDevice);
	cudaMemcpy(dev_b, src_b, sizeof(int) * N, cudaMemcpyHostToDevice);
}
void launchKernel(int N, int threadsPerBlock, float* time_gl, int* N_gl) {
	int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
	printf("\nCUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
	//QueryPerformanceCounter(&t3);//������������ ����� ������(������ ��������) - 1024
	float elapsedTime;  cudaEvent_t    start, stop; // ���������� ��� ������ � ���������, ���     // �������� ����������� �����    
	cudaEventCreate(&start); // �������������  
	cudaEventCreate(&stop); // �������
	cudaEventRecord(start, 0); // �������� (�����������) ������� start  
	sum << <blocksPerGrid, threadsPerBlock >> > (dev_a, dev_b, N);
	cudaEventRecord(stop, 0); // �������� ������� stop  
	cudaEventSynchronize(stop); // ������������� �� �������  
								//CUDA_CHECK_RETURN(cudaDeviceSynchronize());  
	//CUDA_CHECK_RETURN(cudaGetLastError());  
	cudaEventElapsedTime(&elapsedTime, start, stop); // ���������� ������������ 
	fprintf(stderr, "gTest took %g\n", elapsedTime);
	cudaEventDestroy(start); // ������������  cudaEventDestroy(stop); // ������
	//sum << <blocksPerGrid, threadsPerBlock >> > (dev_a, dev_b, N);
	cudaDeviceSynchronize();
	//QueryPerformanceCounter(&t4);
	//double tm = double(t4.QuadPart - t3.QuadPart);// / f.QuadPart;
	float tm = elapsedTime;
	std::cout << "threadsPerBlock: " << threadsPerBlock << ", time: " << tm << "\n";
	time_gl[i_gl] = tm;
	N_gl[i_gl] = N; i_gl++;
}
void testFunction() {
	int threadsPerblock_local = 1;
	std::ofstream out;          // ����� ��� ������
	out.open("..\\results.txt"); // �������� ���� ��� ������
	for (int i_thr = threadsPerblock_local; i_thr <= 1024; i_thr *= 2)//�������� �.�. �������, ������� � ���� ������������ ����� - 10
	{
		if (out.is_open())
		{
			out << "\n\n" << std::endl;
		}
		N_gl = (int*)std::malloc(num * sizeof(int));
		time_gl = (float*)std::malloc(num * sizeof(float));
		//���  ����� ������: ...
		for (int i_N = 1 << 10; i_N <= 1 << 23; i_N *= 2)//������� �� ������������� ����� �������// �� ���� �� ������� �������� ���� �� �������� ��������
		{//��� ���� ����� ����� ������ ������������ �����... ����� �� ����� 3
			allocateMemory(i_N);// �� ������� ������ ������� ����� ���� �� 1<<10 �� 1<<23
			launchKernel(i_N, i_thr, time_gl, N_gl);
		}
		std::cout << "\n\narrSize N   time , threadsPerblock_local = " << i_thr;
		out << std::endl << "arrSizeN time threadsPerblock=" << i_thr;
		for (int ipi = 1; ipi < num; ipi++)
		{
			std::cout << std::endl << N_gl[ipi] << "    " << time_gl[ipi];
			out << std::endl << N_gl[ipi] << " " << time_gl[ipi];
		}
		free(N_gl);
		free(time_gl);
		i_gl = 1;

	}
}
int main() {
	setlocale(LC_ALL, "US");

	cudaSetDevice(0);//��������� ������ ��� ���������� ��� ������
	int size0 = 1024;//���� ����� �����?
	//launchKernel(100000, 1025, time_gl, N_gl);
	testFunction();
	//launchKernel(1024, 10000, time_gl, N_gl);


	//out.open("..\\results.txt"); // �������� ���� ��� ������











	/*std::ofstream out;          // ����� ��� ������
	out.open("C:\\Users\\stepa\\repos2\\gpu\\lab1_01\\lab1_01\\results.txt"); // �������� ���� ��� ������
	if (out.is_open())
	{
		out << "A new test: " << size0 << std::endl;
	}
	N_gl = (int*)std::malloc(num * sizeof(int));
	time_gl = (int*)std::malloc(num * sizeof(int));
	//���  ����� ������: 256
	for (int i_N = 1  << 10; i_N < 1 << 23; i_N *= 2)//������� �� ������������� ����� �������// �� ���� �� ������� �������� ���� �� �������� ��������
	{//��� ���� ����� ����� ������ ������������ �����... ����� �� ����� 3
		allocateMemory(i_N);// �� ������� ������ ������� ����� ���� �� 1<<10 �� 1<<23
		launchKernel(i_N, 256, time_gl,  N_gl);
	}
	std::cout << "size N   time ";
	for (int ipi = 0; ipi < num; ipi++)
	{
		std::cout << 256 <<"    " <<   time_gl[ipi] << std::endl;
	}
	//��� ����� ������: 512
	for (int i_N = 1 << 10; i_N < 1 << 23; i_N *= 2)//������� �� ������������� ����� �������// �� ���� �� ������� �������� ���� �� �������� ��������
	{//��� ���� ����� ����� ������ ������������ �����... ����� �� ����� 3
		allocateMemory(i_N);// �� ������� ������ ������� ����� ���� �� 1<<10 �� 1<<23
		launchKernel(i_N, 512, time_gl, N_gl);
	}
	std::cout << "size N   time ";
	for (int ipi = 0; ipi < num; ipi++)
	{
		std::cout << 512 << "    " << time_gl[ipi] << std::endl;
	}
	//��� ����� ������: 1024
	for (int i_N = 1 << 10; i_N < 1 << 23; i_N *= 2)//������� �� ������������� ����� �������// �� ���� �� ������� �������� ���� �� �������� ��������
	{//��� ���� ����� ����� ������ ������������ �����... ����� �� ����� 3
		allocateMemory(i_N);// �� ������� ������ ������� ����� ���� �� 1<<10 �� 1<<23
		launchKernel(i_N, 1024, time_gl, N_gl);
	}
	std::cout << "size N   time ";
	for (int ipi = 0; ipi < num; ipi++)
	{
		std::cout << 1024 << "    " << time_gl[ipi] << std::endl;
	}

	//int ff = 1 << 23;
	//std::cout << "ff = " << ff;
	//int a = 16 << 1;//� ����������� ��������
	//std::cout << "\na = " << a;

	*/
}

