cmake_minimum_required(VERSION 3.0)
project(hpx_queue_template CXX)

find_package(HPX REQUIRED)

add_hpx_executable(program_hpx_queue_template
    SOURCES program_hpx_queue_template.cpp
    HEADERS myqueue.hpp myqueue_client.hpp
    COMPONENT_DEPENDENCIES iostreams)

# add dependencies to pseudo-target
add_hpx_pseudo_dependencies(chapter3.section3.hpx_queue_template program_hpx_queue_template)