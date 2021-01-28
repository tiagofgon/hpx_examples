cmake_minimum_required(VERSION 3.5)


project(chapter3 CXX)

#--------------------------------------------------
# setup Output directories
#--------------------------------------------------
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all Executables."
)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/lib CACHE PATH "Single Directory for all Libraries"
)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/lib CACHE PATH "Single Directory for all static libraries."
)


#------------------------------------------------------------------------------
 # Detect which machine we are running on to setup defaults for convenience
 #------------------------------------------------------------------------------
 SITE_NAME(hostname)
 if(hostname MATCHES "unknown" OR hostname MATCHES "No")
   message("unknown hostname \"${hostname}\", using ENV$ $ENV{HOSTNAME} instead")
   set(hostname $ENV{HOSTNAME})
 endif()

 if(hostname MATCHES daint)
   set(TBB_ROOT "/opt/intel/compilers_and_libraries_2017.4.196/linux/tbb/")
   message("Running on Daint")
 endif()
 message("CMAKE_SYSTEM is ${CMAKE_SYSTEM} with hostname ${hostname} and processor ${CMAKE_SYSTEM_PROCESSOR}" )


#--------------------------------------------------
# Find HPX, disable searching in user builds
#--------------------------------------------------
find_package(HPX 1.5.0 REQUIRED)
message("\n-------\nExamples using HPX from ${HPX_DIR}\n-------\n")


#--------------------------------------------------
# Each example goes into its own subdir
#--------------------------------------------------
set(SUBSECTION_DIRS
    section1
    section2
    section3
    section4
    section5
    section6
)

add_hpx_pseudo_target(chapter3)

foreach(subdir ${SUBSECTION_DIRS})
  add_hpx_pseudo_target(chapter3.${subdir})
  add_subdirectory(${subdir})
  add_hpx_pseudo_dependencies(chapter3 chapter3.${subdir})
endforeach()
