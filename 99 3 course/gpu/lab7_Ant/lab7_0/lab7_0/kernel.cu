#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>
/*Thrust is a C++ template library for CUDA based on the Standard Template Library (STL).
Thrust allows you to implement high performance parallel applications with minimal programming effort through a high-level
interface that is fully interoperable with CUDA C.

Thrust provides a rich collection of data parallel primitives such as scan, sort, and reduce, which can be composed
together to implement complex algorithms with concise, readable source code. By describing your computation in terms
of these high-level abstractions you provide Thrust with the freedom to select the most efficient implementation
automatically. As a result, Thrust can be utilized in rapid prototyping of CUDA applications, where programmer
productivity matters most, as well as in production, where robustness and absolute performance are crucial.

Thrust provides two vector containers, host_vector and device_vector. As the names suggest, host_vector is stored in
host memory while device_vector lives in GPU device memory. Thrust’s vector containers are just like std::vector
in the C++ STL. Like std::vector, host_vector and device_vector are generic containers (able to store any data type)
that can be resized dynamically.*/
#include <thrust\device_vector.h>
#include <thrust\host_vector.h>
#include <thrust\functional.h>

struct func // структура для использования математической формулы из задания
{
	float u, t, h;
	func(float _u, float _t, float _h) :
		u(_u), t(_t), h(_h) {};

	__host__ __device__//In CUDA function type qualifiers __device__ and __host__ can be used together in which case the 
		//function is compiled for both the host and the device. This allows to eliminate copy-paste.
		float operator() (const float& x, const float& y) const
	{
		return x + (y - x) * u * t / h;
	}
};

__global__ void funcCUDA(float* x, float* y, float u, float t, float h) // самопальная функция, по сути тож самое
{
	int offset = threadIdx.x + blockDim.x * blockIdx.x;
	y[offset + 1] = x[offset + 1] + (x[offset] - x[offset + 1]) * u
		* t / h;
}

int main()
{
	float elapsedTime; // объява счетчика
	cudaEvent_t start, stop;
	cudaEventCreate(&start); // создание эвента, таймера крч
	cudaEventCreate(&stop);

	cudaEventRecord(start, 0); // старт
	int size = 1 << 8;
	thrust::host_vector<float> A_host(size); // выделение вектора при помощи библиотеки ТРАСТ, тоже самое что СТЛ в С++
	for (int i = 0; i < A_host.size(); ++i)
		A_host[i] = exp(-powf((i / 100.0 - 4.5), 2)) * 100 / (2 * sqrtf(2 * M_PI)); // считаем матан
	thrust::device_vector<float> A(size); // объявление вектора, куда все сложится
	thrust::copy(A_host.begin(), A_host.end(), A.begin()); // копирование вектора как в СТЛ
	for (int i = 0; i < size; ++i)
		thrust::transform(A.begin() + 1, A.end(), A.begin(), A.begin(), func(1.1, 0.9, 1.4)); //Интересная функция, принимающая структуру как аргумент; опять матан, 1.1 - шаг, самое главное что нужно знать, вектор А трансформируется циклом, пересчитывая по сути сам себя
	cudaEventRecord(stop, 0); // стоп таймера
	cudaEventSynchronize(stop); // синх. времени таймера
	cudaEventElapsedTime(&elapsedTime, start, stop); // запись времени в переменную elapsedTime
	printf("Thrust time: ");
;	printf("%f\n", elapsedTime); // вывод времени
	// print Y
	thrust::copy(A.begin(), A.end(), std::ostream_iterator<float>(std::cout, "\n"));

	cudaEventRecord(start, 0); // опять время
	float* vect, * vectRes, * vect_GPU, * vectRes_GPU; // выделение объектов типа флоат, вопрос, почему не дабл? Ответ - потому что видеокарты работают с типом данных флоат быстрее, отсюда кстати и мера измерения  ФЛОПСЫ
	vect = (float*)malloc((size) * sizeof(float)); // память выделяется
	vectRes = (float*)malloc((size) * sizeof(float)); // опять память
	cudaMalloc((void**)&vect_GPU, ((size) + 1) * sizeof(float)); // память)
	cudaMalloc((void**)&vectRes_GPU, ((size) + 1) * sizeof(float)); // и снова память
	for (int i = 0; i < (size); ++i)
		vect[i] = exp(-powf((i / 100.0 - 4.5), 2)) * 100 / (2 * sqrtf(2 * M_PI)); // этот цикл идентичен тому что выше, строка 46, просто это так скажем голый куда-код для просчета математики, который на маленьком размере элементов конечно куда быстрее, чем большая либа с горой ненужных действий
	cudaMemcpy(vect_GPU, vect, (size) * sizeof(float), // куда мем спу - копирование байтов из памяти функция по сути проверки копирования, в некотором роде
		cudaMemcpyHostToDevice);
	for (int i = 0; i < size; ++i) {
		funcCUDA << <1, 256 >> > (vect_GPU, vectRes_GPU, 1.1, 0.9, 1.4); // прогонка матана, все идентично с циклами выше
		cudaMemcpy(vect_GPU, vectRes_GPU + 1, (size) * sizeof(float), cudaMemcpyDeviceToDevice);
	}
	cudaMemcpy(vectRes, vectRes_GPU + 1, (size) * sizeof(float),	cudaMemcpyDeviceToHost);
	cudaEventRecord(stop, 0); // стоп таймера
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&elapsedTime, start, stop);
	printf("Cuda time: ");
	printf("%f\n", elapsedTime); // опять вывод в ту же переменную
	for (int i = 0; i < size; i++)
	{
		printf("%f\n", vectRes[i]);
	}
	

}
// вывод - голый куда-код для данных размеров гораздо быстрее, связано с тем что меньше телодвижений, нежели в либе, + она не так уж часто и обновляется, и 
//опять же-таки сишный код всегда будет каплю быстрее чем СТЛ функции, поэтому на таких числах разница оч существенна.
