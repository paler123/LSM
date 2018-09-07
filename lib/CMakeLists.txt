add_library(my_lib
   ) 

target_compile_options(my_lib PRIVATE ${project_warnings})

target_include_directories(my_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

add_subdirectory(test)
