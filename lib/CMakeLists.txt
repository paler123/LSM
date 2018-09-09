add_library(lsm_lib
   src/Model.cpp
   src/OptionEvaluation.cpp
   src/eur_options.cpp) 

target_compile_options(lsm_lib PRIVATE ${project_warnings})
target_compile_features(lsm_lib PUBLIC cxx_std_17)
target_link_libraries(lsm_lib Eigen3::Eigen)

target_include_directories(lsm_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

add_subdirectory(test)
