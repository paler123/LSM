add_executable(lsm_ut
    )

target_link_libraries(lsm_ut gmock gtest_main)

add_test(lsm_ut lsm_ut)
