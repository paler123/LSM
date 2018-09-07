cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(lsm_pricing)
enable_testing()

include(cmake/warnings.cmake)
include(cmake/boost.cmake)
include(cmake/gmock.cmake)
if(USE_YCM) 
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "to export compile commands" FORCE)
endif()

add_subdirectory(lib)



