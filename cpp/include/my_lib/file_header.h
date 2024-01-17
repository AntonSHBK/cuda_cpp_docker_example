#ifndef FILE_HEADER_H
#define FILE_HEADER_H

#include <stdio.h>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void add_arrays_gpu(int* a, int *b, int* c)
{
    c[threadIdx.x] = a[threadIdx.x] + b[threadIdx.x];
}

// https://dev.to/elemarjr/getting-started-with-cuda-using-vs2017-56ba
int run_function();

#endif // FILE_HEADER_H