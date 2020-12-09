
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <iostream>
using namespace std;

#define SIZE 1024

__global__ void kernel(int* a, int* b, int* c)
{
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	//c[idx] = (2 * 1024 * a[idx]) / 1024 * b[idx];
	c[idx] =  a[idx] + b[idx];
}

float run(int chunk_size, int FULL_DATA_SIZE, bool use_pages, bool check_result)
{
	cout << endl << endl;
	cout << "Running on states:" << endl;
	cout << "CHUNK_SIZE     : " << chunk_size << endl;
	cout << "FULL_DATA_SIZE : " << FULL_DATA_SIZE << "; k = " << FULL_DATA_SIZE / chunk_size * 1.0f << endl;
	cout << "USE_PAGES      : " << use_pages << endl;
	cout << "CHECK_RESULT   : " << check_result << endl;
	cudaDeviceProp prop;
	int whichDevice;
	/*cudaGetDevice	(	int * 	device	 ) 	
Returns in *device the device on which the active host thread executes the device code.

Parameters:
device 	- Returns the device on which the active host thread executes the device code.
*/
	cudaGetDevice(&whichDevice);
	cudaGetDeviceProperties(&prop, whichDevice);

	if (!prop.deviceOverlap)
	{
		printf("Device does not support overlapping\n");//проверка на способность девайса работать с перекрытием(overlapping)
		return 0;
	}

	cudaEvent_t start, stop;
	float elapsedTime;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaStream_t stream0;/*
	cudaStreamCreate	(	cudaStream_t * 	pStream	 ) 	
	Creates a new asynchronous stream.
		Parameters:
	pStream - Pointer to new stream identifier*/
	cudaStream_t stream1;
	cudaStreamCreate(&stream0);
	cudaStreamCreate(&stream1);

	int* host_a, * host_b, * host_c;
	int* dev_a0, * dev_b0, * dev_c0;
	int* dev_a1, * dev_b1, * dev_c1;
	cudaMalloc((void**)&dev_a0, chunk_size * sizeof(int));
	cudaMalloc((void**)&dev_b0, chunk_size * sizeof(int));
	cudaMalloc((void**)&dev_c0, chunk_size * sizeof(int));
	cudaMalloc((void**)&dev_a1, chunk_size * sizeof(int));
	cudaMalloc((void**)&dev_b1, chunk_size * sizeof(int));
	cudaMalloc((void**)&dev_c1, chunk_size * sizeof(int));
	if (use_pages)//1.	Выделение памяти на хосте
	{/*cudaHostAlloc	(	void ** 	ptr, size_t 	size, unsigned int 	flags)			
Allocates size bytes of host memory that is page-locked and accessible to the device. The driver tracks the virtual 
memory ranges allocated with this function and automatically accelerates calls to functions such as cudaMemcpy(). 
Since the memory can be accessed directly by the device, it can be read or written with much higher bandwidth than 
pageable memory obtained with functions such as malloc(). Allocating excessive amounts of pinned memory may degrade 
system performance, since it reduces the amount of memory available to the system for paging. As a result, this 
function is best used sparingly to allocate staging areas for data exchange between host and device.

The flags parameter enables different options to be specified that affect the allocation, as follows.

cudaHostAllocDefault: This flag's value is defined to be 0 and causes cudaHostAlloc() to emulate cudaMallocHost().*/
		cudaHostAlloc((void**)&host_a, FULL_DATA_SIZE * sizeof(int), cudaHostAllocDefault);
		cudaHostAlloc((void**)&host_b, FULL_DATA_SIZE * sizeof(int), cudaHostAllocDefault);
		cudaHostAlloc((void**)&host_c, FULL_DATA_SIZE * sizeof(int), cudaHostAllocDefault);
	}
	else
	{
		host_a = (int*)calloc(FULL_DATA_SIZE, sizeof(int));
		host_b = (int*)calloc(FULL_DATA_SIZE, sizeof(int));
		host_c = (int*)calloc(FULL_DATA_SIZE, sizeof(int));
	}

	for (int i = 0; i < FULL_DATA_SIZE; i++)
	{
		host_a[i] = 1;//заполнил массивы для сложения
		host_b[i] = 1;
	}

	cudaEventRecord(start, 0);
	for (int i = 0; i < FULL_DATA_SIZE; i += chunk_size * 2)
	{
		//cout << "     CYCLE     : " << i << endl;
		if (use_pages)//2.	Копирование памяти на устройство
		{/*cudaMemcpyAsync() is asynchronous with respect to the host, so the call may return before the copy is complete. 
		 It only works on page-locked host memory and returns an error if a pointer to pageable memory is passed as input. 
		 The copy can optionally be associated to a stream by passing a non-zero stream argument. If kind is 
		 cudaMemcpyHostToDevice or cudaMemcpyDeviceToHost and the stream is non-zero, the copy may overlap with operations 
		 in other streams.*/
			cudaMemcpyAsync(dev_a0, host_a + i, chunk_size * sizeof(int), cudaMemcpyHostToDevice, stream0);//создал массивы в разных потоках
			cudaMemcpyAsync(dev_a1, host_a + i + chunk_size, chunk_size * sizeof(int), cudaMemcpyHostToDevice, stream1);
			cudaMemcpyAsync(dev_b0, host_b + i, chunk_size * sizeof(int), cudaMemcpyHostToDevice, stream0);
			cudaMemcpyAsync(dev_b1, host_b + i + chunk_size, chunk_size * sizeof(int), cudaMemcpyHostToDevice, stream1);
			kernel << <chunk_size / 256, 256, 0, stream0 >> > (dev_a0, dev_b0, dev_c0);//3.	Выполнение кода на устройстве
			kernel << <chunk_size / 256, 256, 0, stream1 >> > (dev_a1, dev_b1, dev_c1);
			cudaMemcpyAsync(host_c + i, dev_c0, chunk_size * sizeof(int), cudaMemcpyDeviceToHost, stream0);//4.	Копирование памяти на хост
			cudaMemcpyAsync(host_c + i + chunk_size, dev_c1, chunk_size * sizeof(int), cudaMemcpyDeviceToHost, stream1);
		}
		else
		{
			cudaMemcpy(dev_a0, host_a + i, chunk_size * sizeof(int), cudaMemcpyHostToDevice);
			cudaMemcpy(dev_a1, host_a + i + chunk_size, chunk_size * sizeof(int), cudaMemcpyHostToDevice);
			cudaMemcpy(dev_b0, host_b + i, chunk_size * sizeof(int), cudaMemcpyHostToDevice);
			cudaMemcpy(dev_b1, host_b + i + chunk_size, chunk_size * sizeof(int), cudaMemcpyHostToDevice);
			kernel << <chunk_size / 256, 256, 0 >> > (dev_a0, dev_b0, dev_c0);
			kernel << <chunk_size / 256, 256, 0 >> > (dev_a1, dev_b1, dev_c1);
			cudaMemcpy(host_c + i, dev_c0, chunk_size * sizeof(int), cudaMemcpyDeviceToHost);
			cudaMemcpy(host_c + i + chunk_size, dev_c1, chunk_size * sizeof(int), cudaMemcpyDeviceToHost);
		}
	}
	/*cudaStreamSynchronize	(	cudaStream_t 	stream	 ) 	
Blocks until stream has completed all operations. If the cudaDeviceBlockingSync flag was set for this device, the host thread will 
block until the stream is finished with all of its tasks.

Parameters:
stream 	- Stream identifier
*/
	cudaStreamSynchronize(stream0);
	cudaStreamSynchronize(stream1);
	cudaEventRecord(stop, 0);
	/*cudaEventSynchronize	(	cudaEvent_t 	event	 ) 	
Blocks until the event has actually been recorded. If cudaEventRecord() has not been called on this event, the function returns 
cudaErrorInvalidValue.*/
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&elapsedTime, start, stop);
	cout << "ELAPSED_TIME   : " << elapsedTime << "ms" << endl;//вывел время сложения/умножения

	if (check_result)
	{
		int sum = 0;
		for (int i = 0; i < FULL_DATA_SIZE; i++) {
			sum += host_c[i];
		}
		cout << "CHECKING_RESULT: " << sum / (FULL_DATA_SIZE * 2.0f)
			<< ((sum == FULL_DATA_SIZE * 2) ? " = SUCCESS" : " = FAIL") << endl;
	}

	cudaFreeHost(host_a);
	cudaFreeHost(host_b);
	cudaFreeHost(host_c);

	cudaFree(dev_a0);
	cudaFree(dev_b0);
	cudaFree(dev_c0);
	cudaFree(dev_a1);
	cudaFree(dev_b1);
	cudaFree(dev_c1);

	cudaStreamDestroy(stream0);
	cudaStreamDestroy(stream1);
	return elapsedTime;
}

int main()
{
	int FULL_DATA_SIZE = SIZE * SIZE * 64;
	//for (int n = SIZE; n < FULL_DATA_SIZE; n *= 2)//n - размер чанков
	//{
	//	run(n, FULL_DATA_SIZE, true, true);
	//}
	for (int i = 2; i <= 64; i*=2) {
		int N = SIZE * SIZE;
		int FULL_DATA_SIZE = SIZE * SIZE * i;
		run(N, FULL_DATA_SIZE, true, true);
		run(N, FULL_DATA_SIZE, false, true);
	}
	system("pause");
	return 0;
}