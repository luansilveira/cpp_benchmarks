cmake_minimum_required(VERSION 3.10)
project(cpp_benchmarks)
set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

add_library(lsilveira_utils "utils/stop_watch.cpp")

add_executable(memory_allocation "memory_allocation/memory.cpp")
target_link_libraries(memory_allocation lsilveira_utils)
