#include <stdio.h>

__global__ void hello_from_gpu(){
    printf("Hello world from gpu!\n");
}

int main(){
    hello_from_gpu<<<1,1>>>();
    cudaDeviceSynchronize();
    return 0;
}