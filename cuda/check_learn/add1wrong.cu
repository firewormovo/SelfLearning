#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "error.cuh"

const double EPLISION = 1.0e-15;
const double a = 1.23;
const double b = 2.34;
const double c = 3.57;

__global__ void add(const double *x, const double *y, double *z, const int N);
void check(const double *z, const int N);

int main()
{
    // 这里的N超过1e7就会报错，我认为这应该与gpu的计算能力相关
    //
    const int N = 1e8;
    const int M = sizeof(double) * N;
    double *h_x = new double[N];
    double *h_y = new double[N];
    double *h_z = new double[N];

    for (int n = 0; n < N; ++n)
    {
        h_x[n] = a;
        h_y[n] = b;
    }

    double *d_x, *d_y, *d_z;

    cudaMalloc((void **)&d_x, M);
    cudaMalloc((void **)&d_y, M);
    cudaMalloc((void **)&d_z, M);
    cudaMemcpy(d_x, h_x, M, cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, h_y, M, cudaMemcpyHostToDevice);

    const int block_size = 128;
    const int gride_size = (N % block_size == 0 ? N / block_size
                                                : N / block_size + 1);
    add<<<gride_size, block_size>>>(d_x, d_y, d_z, N);
    cudaDeviceSynchronize();

    cudaMemcpy(h_z, d_z, M, cudaMemcpyDeviceToHost);
    check(h_z, N);
    delete[] h_x;
    delete[] h_y;
    delete[] h_z;
    CHECK(cudaFree(d_x));
    CHECK(cudaFree(d_y));
    CHECK(cudaFree(d_z));
    return 0;
}

__global__ void add(const double *x, const double *y, double *z, const int N)
{
    // get index
    const int n = blockDim.x * blockIdx.x + threadIdx.x;

    // base index to compute
    if (n < N)
    {
        z[n] = x[n] + y[n];
    }
    //printf("z[%d]=%f\n", n,z[n]);
}

void check(const double *z, const int N)
{
    bool has_error = false;
    for (int n = 0; n < N; ++n)
    {
        // printf("%f\n",z[n]);
        if (fabs(z[n] - c) > EPLISION)
        {
            printf("z[%d]=%f,c=%f\n", n, z[n], c);
            has_error = true;
            break;
        }
    }
    printf("%s\n", has_error ? "Has errors" : "No errors");
}