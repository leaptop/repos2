
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cuda.h>

#define M_PI 3.14159265358979323846
#define COEF 64
#define VERTCOUNT COEF* COEF * 2
#define RADIUS 10.0f
#define FGSIZE 23
#define FGSHIFT FGSIZE / 2
#define IMIN(A, B) (A < B ? A : B)
#define THREADSPERBLOCK 256
#define BLOCKSPERGRID IMIN(32, (VERTCOUNT + THREADSPERBLOCK - 1) / THREADSPERBLOCK)

typedef float (*ptr_f)(float, float, float);

struct Vertex
{
    float x, y, z;
};

__constant__ Vertex vert[VERTCOUNT];
texture<float, 3, cudaReadModeElementType> df_tex;
cudaArray* df_Array = 0;

float func(float x, float y, float z)
{
    return(0.5 * sqrtf(15.0 / M_PI)) * (0.5 * sqrtf(15.0 / M_PI)) * z * z * y * y * sqrtf(1.0f - z * z / RADIUS / RADIUS) / RADIUS / RADIUS / RADIUS / RADIUS;
}

float check(Vertex* v, ptr_f f)
{
    float sum = 0.0f;
    for (int i = 0; i < VERTCOUNT; ++i)
    {
        sum += f(v[i].x, v[i].y, v[i].z);
    }
    return sum;
}

void calc_f(float* arr_f, int x_size, int y_size, int z_size, ptr_f f)
{
    for (int x = 0; x < x_size; ++x)
    {
        for (int y = 0; y < y_size; ++y)
        {
            for (int z = 0; z < z_size; ++z)
            {
                arr_f[z_size * (x * y_size + y) + z] = f(x - FGSHIFT, y - FGSHIFT, z - FGSHIFT);
            }
        }
    }
}

void init_vertexes()
{
    // куча точек, лежащих на сфере
    // координаты из сферических конвертируются в декартовы
    Vertex* temp_vert = (Vertex*)malloc(sizeof(Vertex) * VERTCOUNT);
    int i = 0;
    for (int iphi = 0; iphi < 2 * COEF; ++iphi)
    {
        for (int ipsi = 0; ipsi < COEF; ++ipsi, ++i)
        {
            float phi = iphi * M_PI / COEF;
            float psi = ipsi * M_PI / COEF;
            temp_vert[i].x = RADIUS * sinf(psi) * cosf(phi);
            temp_vert[i].y = RADIUS * sinf(psi) * sinf(phi);
            temp_vert[i].z = RADIUS * cosf(psi);
        }
    }
    printf("sumcheck = %f\n", check(temp_vert, &func) * M_PI * M_PI / COEF / COEF);
    cudaMemcpyToSymbol(vert, temp_vert, sizeof(Vertex) * VERTCOUNT, 0, cudaMemcpyHostToDevice);
    free(temp_vert);
}

void init_texture(float* df_h)
{
    const cudaExtent volumeSize = make_cudaExtent(FGSIZE, FGSIZE, FGSIZE);
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<float>();
    cudaMalloc3DArray(&df_Array, &channelDesc, volumeSize);
    cudaMemcpy3DParms cpyParams = { 0 };
    cpyParams.srcPtr = make_cudaPitchedPtr((void*)df_h, volumeSize.width * sizeof(float), volumeSize.width, volumeSize.height);
    cpyParams.dstArray = df_Array;
    cpyParams.extent = volumeSize;
    cpyParams.kind = cudaMemcpyHostToDevice;
    cudaMemcpy3D(&cpyParams);
    df_tex.normalized = false;
    df_tex.filterMode = cudaFilterModeLinear;
    df_tex.addressMode[0] = cudaAddressModeClamp;
    df_tex.addressMode[1] = cudaAddressModeClamp;
    df_tex.addressMode[2] = cudaAddressModeClamp;
    cudaBindTextureToArray(df_tex, df_Array, channelDesc);
}

void release_texture()
{
    cudaUnbindTexture(df_tex);
    cudaFreeArray(df_Array);
}

__global__ void kernel(float* a)
{
    __shared__ float cache[THREADSPERBLOCK];
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    int cacheIndex = threadIdx.x;
    float x = vert[tid].x + FGSHIFT + 0.5f;
    float y = vert[tid].y + FGSHIFT + 0.5f;
    float z = vert[tid].z + FGSHIFT + 0.5f;
    cache[cacheIndex] = tex3D(df_tex, z, y, x);
    __syncthreads();
    for (int s = blockDim.x / 2; s > 0; s >>= 1)
    {
        if (cacheIndex < s)
        {
            cache[cacheIndex] += cache[cacheIndex + s];
        }
        __syncthreads();
    }
    if (cacheIndex == 0)
    {
        a[blockIdx.x] = cache[0];
    }
}

int main(void)
{
    float* arr = (float*)malloc(sizeof(float) * FGSIZE * FGSIZE * FGSIZE);
    float* sum = (float*)malloc(sizeof(float) * BLOCKSPERGRID);
    float* sum_dev;
    cudaMalloc((void**)&sum_dev, sizeof(float) * BLOCKSPERGRID);
    init_vertexes();
    calc_f(arr, FGSIZE, FGSIZE, FGSIZE, &func);
    init_texture(arr);
    kernel << <BLOCKSPERGRID, THREADSPERBLOCK >> > (sum_dev);
    cudaThreadSynchronize();
    cudaMemcpy(sum, sum_dev, sizeof(float) * BLOCKSPERGRID, cudaMemcpyDeviceToHost);
    float s = 0.0f;
    for (int i = 0; i < BLOCKSPERGRID; ++i)
    {
        s += sum[i];
    }
    printf("sum = %f\n", s * M_PI * M_PI / COEF / COEF);
    cudaFree(sum_dev);
    free(sum);
    release_texture();
    free(arr);
    return 0;
}


/*
struct cudaExtent
{
    size_t width;
    size_t height;
    size_t depth;
};

struct cudaExtent make_cudaExtent(size_t w, size_t h, size_t d);

struct cudaChannelFormatDesc
{
    int x, y, z, w;
    enum cudaChannelFormatKind f;
};

struct textureReference
{
    enum cudaTextureAddressMode addressMode[3];
    struct cudaChannelFormatDesc channelDesc;
    enum cudaTextureFilterMode filterMode;
    int normalized;
    int sRGB;
};

cudaError_t cudaMalloc3DArray(struct cudaArray** array, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent, unsigned int flags = 0);

struct cudaMemcpy3DParms
{
    struct cudaArray* srcArray;
    struct cudaPos srcPos;
    struct cudaPitchedPtr srcPtr;
    struct cudaArray* dstArray;
    struct cudaPos dstPos;
    struct cudaPitchedPtr dstPtr;
    struct cudaExtent extent;
    enum cudaMemcpyKind kind;
};
*/





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
