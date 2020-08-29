
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

#include <thrust/sequence.h>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <ctime>

struct fun
{
    float alpha;
    fun(float _alpha) : alpha(_alpha)
    {}
    __host__ __device__
        float operator()(float x, float y)
    {
        return x * alpha + y;
    }
};

int main()
{
    size_t N = 1 << 20;
    size_t Nx = 1 << 10;
    size_t Ny = 1 << 10;

    clock_t start = clock();
    thrust::device_vector<float> matrix_origin_dev(N);
    thrust::device_vector<float> matrix_res_dev(N);
    thrust::sequence(matrix_origin_dev.begin(), matrix_origin_dev.end());
    thrust::counting_iterator<size_t> indices(0);
    thrust::device_vector<float> temp(Ny);
    for (size_t i = 0; i < Nx; ++i)
    {
        thrust::sequence(temp.begin(), temp.end(), 0 + i, Nx);
        thrust::copy(thrust::make_permutation_iterator(matrix_origin_dev.begin(), temp.begin()), thrust::make_permutation_iterator(matrix_origin_dev.begin(), temp.end()), matrix_res_dev.begin() + i * Ny);
    }
    thrust::host_vector<float> host_result = matrix_res_dev;
    printf("Transpose time (s) - %f\n", double(clock() - start) / CLOCKS_PER_SEC);
    //        for (int i = 0; i < Ny; ++i) {
    //            for (int j = 0; j < Nx; ++j)
                    //printf("%f\t", host_result[i * Ny + j]);
    //            printf("\n");
    //        }

    start = clock();
    fun alpha(2.25);
    thrust::device_vector<float> vectorA(N);
    thrust::device_vector<float> vectorB(N);
    thrust::sequence(vectorA.begin(), vectorA.end());
    thrust::sequence(vectorB.begin(), vectorB.end(), -1, 2);
    thrust::transform(vectorA.begin(), vectorA.end(), vectorB.begin(), vectorA.begin(), alpha);
    thrust::host_vector<float> resVector = vectorA;
    printf("SAXPY time (s) - %f\n", double(clock() - start) / CLOCKS_PER_SEC);
    //for (auto i : resVector)
    //	printf("%f\t", i);
}

