add_executable(lsm_ut
    model.cpp
    eur_options.cpp)

target_include_directories(lsm_ut PUBLIC 
    ${PROJECT_SOURCE_DIR}/lib/src)
target_link_libraries(lsm_ut lsm_lib gmock gtest_main)

add_test(lsm_ut lsm_ut)
