# Require a recent version of cmake
cmake_minimum_required(VERSION 3.3.2 FATAL_ERROR)

# This project is C++ based.
project(dynamic_libraries CXX)

# Instruct cmake to find the HPX settings
find_package(HPX)

add_library(module SHARED module.cpp)
target_link_libraries(module PUBLIC HPX::hpx)

add_hpx_executable(program
    SOURCES program.cpp
    COMPONENT_DEPENDENCIES iostreams)

