#include <stdio.h>

__global__ void hello_from_gpu()
{
    const int bid = blockIdx.x;
    const int tid = threadIdx.x;
    printf("girdm.x: %d ,blockdim.x: %d \n",gridDim.x - 1,blockDim.x - 1);
    printf("Hello from block %d and thread %d\n", bid, tid);
}

int main(){
    hello_from_gpu<<<5,6>>>();
    cudaDeviceSynchronize();
    return 0;
}