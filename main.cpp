#include <iostream>
#include <cuda_runtime.h>

#include "my_lib/file_header.h"

int main()
{
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);
    std::cout << deviceCount << std::endl;
    run_function();
    return 0;
}