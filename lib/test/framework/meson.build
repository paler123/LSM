framework_sources = ['Comparators.cpp']

testing_framework_headers = include_directories('.')

testing_framework = shared_library(
               'testing_framework',
               framework_sources,
               include_directories : [lsm_private_includes],
               dependencies : [lsm_dep, gmock_dep, gtest_dep, eigen_dep])
