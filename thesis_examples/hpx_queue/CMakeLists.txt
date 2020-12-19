# Require a recent version of cmake
cmake_minimum_required(VERSION 3.3.2 FATAL_ERROR)

# This project is C++ based.
project(Example_1 CXX)

# Instruct cmake to find the HPX settings
find_package(HPX)

add_hpx_executable(program
    SOURCES program.cpp myqueue.cpp
    HEADERS myqueue.hpp myqueue_client.hpp
    COMPONENT_DEPENDENCIES iostreams)

