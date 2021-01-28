set(subdirs
    hpx_queue
    hpx_queue_template
    hpx_queue_template_migrable
    hpx_queue_template_migrable_derived
   )

foreach(subdir ${subdirs})
    add_hpx_pseudo_target(chapter3.section3.${subdir})
    add_subdirectory(${subdir})
    add_hpx_pseudo_dependencies(chapter3.section3 chapter3.section3.${subdir})
endforeach()