cmake_minimum_required(VERSION 3.25.1 FATAL_ERROR)

project(
  CudaExample 
  VERSION 0.1.0
  DESCRIPTION "CudaExample description"
)

# Standarts
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if (NOT TARGET cpp_code)
  add_subdirectory(cpp)
endif() 

include_directories(cpp/include)

add_executable(${PROJECT_NAME} main.cpp)

