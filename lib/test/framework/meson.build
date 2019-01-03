framework_sources = ['Comparators.cpp']

testing_framework_headers = include_directories('.')

testing_framework = shared_library(
               'testing_framework',
               framework_sources,
               include_directories : [lsm_headers, lsm_private_includes],
               dependencies : [gmock_dep, gtest_dep, eigen_dep],
               link_with : lsm_lib)
