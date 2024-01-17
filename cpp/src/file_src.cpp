#include <stdio.h>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "my_lib/file_headeer.h"


// https://dev.to/elemarjr/getting-started-with-cuda-using-vs2017-56ba
int run_function()
{
    const auto count = 5;
    int host_a[] = { 1, 2, 3, 4, 5 };
    int host_b[] = { 10, 20, 30, 40, 60 };
    int host_c[count];

    int *device_a, *device_b, *device_c;
    const int size = count * sizeof(int);
    cudaMalloc(&amp;device_a, size);
    cudaMalloc(&amp;device_b, size);
    cudaMalloc(&amp;device_c, size);

    cudaMemcpy(
        device_a, host_a,
        size,
        cudaMemcpyHostToDevice
    );

    cudaMemcpy(
        device_b, host_b,
        size,
        cudaMemcpyHostToDevice
    );

    add_arrays_gpu <<< 1, count >>> (device_a, device_b, device_c);

    cudaMemcpy(
        host_c, device_c,
        size,
        cudaMemcpyDeviceToHost
    );


    for (auto i = 0; i < count; i ++)
    {
        printf("%d ", host_c[i]);
    }

    getchar();
}