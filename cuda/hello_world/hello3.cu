#include <stdio.h>

__global__ void hello_from_gpu() {
  const int block_id = blockIdx.x;
  const int thread_id = threadIdx.x;
  printf("hello world from gpu , block id is %d ,thread id is %d \n", block_id,
         thread_id);
}

int main() {
  hello_from_gpu<<<3, 12>>>();
  cudaDeviceSynchronize();
  return 0;
}