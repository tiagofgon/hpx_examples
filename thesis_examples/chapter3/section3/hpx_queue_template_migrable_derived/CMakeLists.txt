cmake_minimum_required(VERSION 3.0)
project(hpx_queue_template_migrable_derived CXX)

find_package(HPX REQUIRED)

add_hpx_executable(program_hpx_queue_template_migrable_derived
    SOURCES program_hpx_queue_template_migrable_derived.cpp container.cpp
    HEADERS myqueue.hpp myqueue_client.hpp container.hpp
    COMPONENT_DEPENDENCIES iostreams)

# add dependencies to pseudo-target
add_hpx_pseudo_dependencies(chapter3.section3.hpx_queue_template_migrable_derived program_hpx_queue_template_migrable_derived)