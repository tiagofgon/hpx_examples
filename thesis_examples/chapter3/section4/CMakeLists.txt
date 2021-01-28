cmake_minimum_required(VERSION 3.0)
project(section4 CXX)

find_package(HPX REQUIRED)
link_directories(${HPX_LIBRARY_DIR})

set(examples
  local_channel
  local_channel_two_threads
  distributed_channel
)

foreach(exercise ${examples})
  add_hpx_executable(${exercise}
    SOURCES ${exercise}.cpp
    COMPONENT_DEPENDENCIES iostreams)
endforeach()


if(TARGET chapter3)
  foreach(exercise ${examples})
    add_hpx_pseudo_dependencies(chapter3.section4 ${exercise})
  endforeach()
endif()