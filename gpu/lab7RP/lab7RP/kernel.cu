#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/transform.h>
#include <thrust/sequence.h>/*Thrust is a C++ template library for CUDA based on the Standard Template Library (STL). 
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
#include <cstdio>
#include <cmath>

struct range_functor {
    float h;
    range_functor(float _h) :h(_h) {}
    __host__ __device__//In CUDA function type qualifiers __device__ and __host__ can be used together in which case the function is compiled for both the host and the device. This allows to eliminate copy-paste.
        float operator()(float x) {
        return h * x;
    }
};

struct sin_functor {
    __device__
        float operator()(float x) {
        return __sinf(x);//Calculate the fast approximate sine of the input argument.(single precision intrinsic functions that are only supported in device code)
    }
};

int main() {
    range_functor R(0.02);
    sin_functor Sin;
    fprintf(stderr, "%g\n", R(30.0f));
    //fprintf(stderr, "%g\n", Sin(3141592.0f/6.0f));
    thrust::host_vector<float> h1(1 << 8);//created an array of 1<<8 floats
    thrust::host_vector<float> h2(1 << 8);
    thrust::device_vector<float> d1(1 << 8);
    thrust::device_vector<float> d2(1 << 8);
    thrust::sequence(thrust::device, d1.begin(), d1.end());
    thrust::transform(d1.begin(), d1.end(), d1.begin(), R);
    thrust::transform(d1.begin(), d1.end(), d2.begin(), Sin);
    h2 = d2;
    h1 = d1;
    for (int i = 0; i < (1 << 8); i++) {
        printf("%g\t%g\n", h1[i], h2[i]);
    }
    return 0;
}