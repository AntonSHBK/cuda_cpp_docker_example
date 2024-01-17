# Example for c++ project with cuda support
The project is still in development. This is just a framework project to be used in conjunction with Cuda.

# Interesting article
- [CMake settings](https://lindevs.com/build-cuda-cpp-program-using-cmake)
- [Simple example cuda](https://dev.to/elemarjr/getting-started-with-cuda-using-vs2017-56ba)
- [CudaToolKit Install](https://developer.nvidia.com/cuda-downloads)
- [Cuda docker example](https://ruddra.com/use-cuda-in-docker/)
- [Cuda docker images](https://hub.docker.com/r/nvidia/cuda#!)

## What is Cuda?
CUDA is a parallel computing platform and application programming interface that allows software to use certain types of graphics processing unit for general purpose processing, an approach called general-purpose computing on GPUs.

Make sure to have GPU Drivers installed
In your machine, make sure you have the GPU drivers installed. Finally, check if the driver is installed by either terminal or powershell (in windows) by running the command:
```bush
nvidia-smi
```

## Installing
You can use the docker or install it yourself, but upon completion you need to make sure that it is available.
## Docker run
```bush
cd docker
docker-compose up --build
```
