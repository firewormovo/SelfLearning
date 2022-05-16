#include <stdio.h>

__global__ void hello_from_gpu(){
    printf("hello world from gpu\n");
}

void __global__ hello_from_other_gpu(){
    printf("hello from other gpu\n");
}

int main(void){
    hello_from_gpu<<<1,1>>>();
    hello_from_other_gpu<<<1,1>>>();
    cudaDeviceSynchronize();
    return 0;
}