cmake_minimum_required(VERSION 3.25.1 FATAL_ERROR)

project(
    cpp_code 
    VERSION 0.1.0
    DESCRIPTION "cpp_code description"
)

# Standarts
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest) # We include CTest which is part of CMake

# Dirs
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/my_lib")

# Headers files
set(
    HEADERS 
    ${PROJECT_INCLUDE_DIR}/file_hrader.h
)

# Source files
set(
    SOURCE
    ${PROJECT_SOURCE_DIR}/file_src.cpp
)

# Add library
add_library(
    ${PROJECT_NAME}
    SHARED
    # STATIC   
    ${HEADERS}
    ${SOURCE}
)

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC  include/)

# # OpenMP
find_package(CUDAToolkit REQUIRED)
if(NOT CUDAToolkit_CXX_FOUND)
	message(SEND_ERROR "Failed to find CUDAToolkit.")
	return()
else()
	include_directories(${CUDAToolkit_INCLUDE_DIRS})
    message("CUDAToolkit FOUND dir is ${CUDAToolkit_INCLUDE_DIRS}.")
endif()

# Указание подключаемых библиотек
target_link_libraries(
    ${projectName} 
    CUDA::cudart 
)

# Tests dirs
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(tests)
endif ()

enable_testing()