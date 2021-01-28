cmake_minimum_required(VERSION 3.0)
project(section2 CXX)

find_package(HPX REQUIRED)
link_directories(${HPX_LIBRARY_DIR})

set(examples
  async_without_synchronization
  async_with_synchronization
  sync
  async_without_synchronization_with_continuation_I
  async_without_synchronization_with_continuation_II
  async_without_synchronization_with_continuation_III
)

foreach(exercise ${examples})
  add_hpx_executable(${exercise}
    SOURCES ${exercise}.cpp
    COMPONENT_DEPENDENCIES iostreams)
endforeach()


if(TARGET chapter3)
  foreach(exercise ${examples})
    add_hpx_pseudo_dependencies(chapter3.section2 ${exercise})
  endforeach()
endif()