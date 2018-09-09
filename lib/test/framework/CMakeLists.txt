add_library(testing_framework
    Comparators.cpp)

target_link_libraries(testing_framework
    gmock
    lsm_lib)

message(${CMAKE_CURRENT_LIST_DIR})
target_include_directories(testing_framework PUBLIC
    ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(testing_framework PUBLIC
    ${PROJECT_SOURCE_DIR}/lib/src)

target_compile_options(testing_framework PUBLIC
    ${project_warnings})

