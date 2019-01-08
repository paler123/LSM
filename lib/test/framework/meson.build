framework_sources = ['Comparators.cpp']

testing_framework_headers = include_directories('.')

testing_framework = shared_library(
               'testing_framework',
               framework_sources,
               include_directories : [lsm_private_includes, testing_framework_headers],
               dependencies : [lsm_dep, gmock_dep, gtest_dep])

lsm_testing_dep = declare_dependency(
    link_with : testing_framework,
    include_directories : [lsm_private_includes, testing_framework_headers],
    dependencies : lsm_dep)
