//
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
//
#include <stdio.h>
#include <cuda.h>
#include <Windows.h>
#include <time.h> 
#include <iostream>
#include <fstream>
//��������� kernel ��� device
__global__ void sum(int* a, int* b, int N) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;//���� ���������� ������ � ����� ������� � ����� � ������������ ����� ������� � �����,
	//����������� �� ������ ����� ������� ������ N, �� return
	if (i >= N) return;
	a[i] += b[i];
}
int N = 0;//������ ��������
int* src_a, * src_b; int* dev_a, * dev_b;
LARGE_INTEGER t1, t2, f, t3, t4, t5, t6, t7, t8;
int* blocksPerGrid_gl, * threadsPerBlock_gl, * N_gl, * time_gl;
int i_gl =1;
int num = 15;
void allocateMemory(int N) {
	cudaMalloc(&dev_a, sizeof(int) * N);
	cudaMalloc(&dev_b, sizeof(int) * N);
	src_a = (int*)malloc(sizeof(int) * N); src_b = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) { src_a[i] = rand(); src_b[i] = rand(); }
	cudaMemcpy(dev_a, src_a, sizeof(int) * N, cudaMemcpyHostToDevice);
	cudaMemcpy(dev_b, src_b, sizeof(int) * N, cudaMemcpyHostToDevice);
}
void launchKernel(int N, int threadsPerBlock, int * time_gl, int * N_gl ) {
	int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
	printf("\nCUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
	QueryPerformanceCounter(&t3);//������������ ����� ������(������ ��������) - 1024
	sum << <blocksPerGrid, threadsPerBlock >> > (dev_a, dev_b, N);
	cudaDeviceSynchronize();
	QueryPerformanceCounter(&t4);
	double tm = double(t4.QuadPart - t3.QuadPart);// / f.QuadPart;
	std::cout << "threadsPerBlock: " << threadsPerBlock << ", time: " << tm << "\n";
	time_gl[i_gl] = tm;
	N_gl[i_gl] = N; i_gl++;
}
void testFunction() {
	int threadsPerblock_local = 1;
	std::ofstream out;          // ����� ��� ������
	out.open("C:\\Users\\stepa\\repos2\\gpu\\lab1_01\\lab1_01\\results.txt"); // �������� ���� ��� ������

	for (int i_thr = threadsPerblock_local; i_thr < 1024; i_thr *= 2)
	{
		if (out.is_open())
		{
			out << "\n\nA new test: " << std::endl;
		}
		N_gl = (int*)std::malloc(num * sizeof(int));
		time_gl = (int*)std::malloc(num * sizeof(int));
		//���  ����� ������: ...
		for (int i_N = 1 << 10; i_N <= 1 << 23; i_N *= 2)//������� �� ������������� ����� �������// �� ���� �� ������� �������� ���� �� �������� ��������
		{//��� ���� ����� ����� ������ ������������ �����... ����� �� ����� 3
			allocateMemory(i_N);// �� ������� ������ ������� ����� ���� �� 1<<10 �� 1<<23
			launchKernel(i_N, i_thr, time_gl, N_gl);
		}
		std::cout << "\n\narrSize N   time , threadsPerblock_local = " << i_thr;
		out << std::endl << "arrSizeN  time , threadsPerblock_local = " << i_thr;
		for (int ipi = 1; ipi < num; ipi++)
		{
			std::cout << std::endl << N_gl[ipi] << "    " << time_gl[ipi];
			out << std::endl << N_gl[ipi] << "     " << time_gl[ipi];
		}
		free(N_gl);
		free(time_gl);
		i_gl = 1;
		
	}
}
int main() {
	cudaSetDevice(0);//��������� ������ ��� ���������� ��� ������
	int size0 = 1024;//���� ����� �����?
	testFunction();
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

