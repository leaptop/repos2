#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cufft.h>
#include <stdio.h>
#include <fstream>
#include <thrust\host_vector.h>
#include <thrust\device_vector.h>
#include <malloc.h>
#include <thrust\functional.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define NX 4856
#define BATCH 1
#define pi 3.141592

int main() {
	cufftHandle plan;
	cufftComplex* data;
	cufftComplex* data_h = (cufftComplex*)calloc(NX * BATCH,
		sizeof(cufftComplex));

	std::ifstream in("wolfData.txt");

	float val;
	for (int index = 0; index < NX; ++index)
	{
		in >> val >> val >> val;
		if (val != 999) {
			data_h[index].x = val;
			data_h[index].y = 0.0f;
		}
		in >> val;
	}

	cudaMalloc((void**)&data, sizeof(cufftComplex) * NX * BATCH);
	if (cudaGetLastError() != cudaSuccess) {
		fprintf(stderr, "Cuda error: Failed to allocate\n");
		return -1;
	}

	cudaMemcpy(data, data_h, sizeof(cufftComplex) * NX * BATCH,
		cudaMemcpyHostToDevice);

	if (cufftPlan1d(&plan, NX, CUFFT_C2C, BATCH) != CUFFT_SUCCESS) {
		fprintf(stderr, "CUFFT error: Plan creation failed");
		return -1;
	}
	if (cufftExecC2C(plan, data, data, CUFFT_FORWARD) !=
		CUFFT_SUCCESS) {
		fprintf(stderr, "CUFFT error: ExecC2C Forward failed");
		return -1;
	}
	if (cudaDeviceSynchronize() != cudaSuccess) {
		fprintf(stderr, "Cuda error: Failed to synchronize\n");
		return -1;
	}

	cudaMemcpy(data_h, data, NX * sizeof(cufftComplex),
		cudaMemcpyDeviceToHost);

	for (int i = 0; i < NX; i++)
		printf("%f\t%g\n", data_h[i].x, data_h[i].y);
	cufftDestroy(plan);
	cudaFree(data);
	free(data_h);

	return 0;
}

/*
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <thrust\host_vector.h>
#include <thrust\device_vector.h>
#include <malloc.h>
#include <thrust\functional.h>
#include <cublas_v2.h>

void print_array(float * data1,
	float * data2,
	int num_elem,
	const char * prefix) {
	printf("\n%s", prefix);
	for (int i = 0; i < num_elem; i++) {
		printf("\n%2d: %2.4f %2.4f ", i + 1, data1[i],
data2[i]);
	}
}

struct func
{
	float alpha;
	func(float _alpha) :
		alpha(_alpha) {};

	__host__ __device__
		float operator() (const float &x, const float &y) const
	{
		return x * alpha + y;
	}
};

int main() {
	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	float time;

	/*const int num_elem = 1 << 16;
	const size_t size_in_bytes = (num_elem * sizeof(float));
	float * A_dev;
	cudaMalloc((void **)&A_dev, size_in_bytes);
	float * B_dev;
	cudaMalloc((void **)&B_dev, size_in_bytes);
	float * A_h;
	cudaMallocHost((void **)&A_h, size_in_bytes);
	float * B_h;
	cudaMallocHost((void **)&B_h, size_in_bytes);
	memset(A_h, 0, size_in_bytes);
	memset(B_h, 0, size_in_bytes);
	// Èíèöèàëèçàöèÿ áèáëèîòåêè CUBLAS
	cublasHandle_t cublas_handle;
	cublasCreate(&cublas_handle);
	for (int i = 0; i < num_elem; i++) {
		A_h[i] = (float)i;
		B_h[i] = i + 2;
	}
	//print_array(A_h, B_h, num_elem, "Before Set");
	const int num_rows = num_elem;
	const int num_cols = 1;
	const size_t elem_size = sizeof(float);

	//Êîïèðîâàíèå ìàòðèöû ñ ÷èñëîì ñòðîê num_elem è îäíèì ñòîëáöîì ñ
	//õîñòà íà óñòðîéñòâî
		cublasSetMatrix(num_rows, num_cols, elem_size, A_h,
			num_rows, A_dev, num_rows);
	//Î÷èùàåì ìàññèâ íà óñòðîéñòâå
	cudaMemcpy(B_dev, B_h, num_elem * sizeof(float),
		cudaMemcpyHostToDevice);
	//cudaMemset(B_dev, 0, size_in_bytes);
	// âûïîëíåíèå SingleAlphaXPlusY
	const int stride = 1;
	float alpha = 2.0F;
	cudaEventRecord(start, 0);
	cublasSaxpy(cublas_handle, num_elem, &alpha, A_dev,
		stride, B_dev, stride);
	//Êîïèðîâàíèå ìàòðèö ñ ÷èñëîì ñòðîê num_elem è îäíèì ñòîëáöîì ñ
	//óñòðîéñòâà íà õîñò
		cublasGetMatrix(num_rows, num_cols, elem_size, A_dev,
			num_rows, A_h, num_rows);
	cublasGetMatrix(num_rows, num_cols, elem_size, B_dev,
		num_rows, B_h, num_rows);
	//print_array(A_h, B_h, num_elem, "Intermediate Set");
	const int default_stream = 0;
	cudaStreamSynchronize(default_stream);

	// Print out the arrays
	//print_array(A_h, B_h, num_elem, "After Set");
	//printf("\n");
	// Îñâîáîæäàåì ðåñóðñû íà óñòðîéñòâå
	cublasDestroy(cublas_handle);
	cudaFree(A_dev);
	cudaFree(B_dev);
	// Îñâîáîæäàåì ðåñóðñû íà õîñòå
	cudaFreeHost(A_h);
	cudaFreeHost(A_h);
	cudaFreeHost(B_h);
	//ñáðîñ óñòðîéñòâà, ïîäãîòîâêà äëÿ âûïîëíåíèÿ íîâûõ ïðîãðàìì
	//cudaDeviceReset();
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&time, start, stop);
	printf("%f\n", time);


	cudaEventRecord(start, 0);
	thrust::host_vector<float> A(1 << 16), B(1 << 16);
	for (int i = 0; i < A.size(); ++i)
	{
		A[i] = i;
		B[i] = i + 2;
	}
	thrust::device_vector<float> A_d(1 << 16), B_d(1 << 16);
	thrust::copy(A.begin(), A.end(), A_d.begin());
	thrust::transform(A_d.begin(), A_d.end(), B_d.begin(),
B_d.begin(), func(2));
	thrust::copy(B.begin(), B.end(), B_d.begin());
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&time, start, stop);
	printf("%f\n", time);
}
*/
