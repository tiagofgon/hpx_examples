cmake_minimum_required(VERSION 3.0)
project(section6 CXX)

find_package(HPX REQUIRED)
link_directories(${HPX_LIBRARY_DIR})

set(examples
    start_runtime_implicit
    start_runtime_explicit
    start_runtime_explicit_async
    start_runtime_suspend_resume
)

foreach(exercise ${examples})
  add_hpx_executable(${exercise}
    SOURCES ${exercise}.cpp
    COMPONENT_DEPENDENCIES iostreams)
endforeach()


if(TARGET chapter3)
  foreach(exercise ${examples})
    add_hpx_pseudo_dependencies(chapter3.section6 ${exercise})
  endforeach()
endif()