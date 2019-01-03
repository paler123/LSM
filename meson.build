project('lsm_pricing', 'cpp',
    version : '0.1',
    default_options : ['warning_level=3', 'cpp_std=c++17', 'werror=true'])

gtest_dep = dependency('gtest', main : true)
gmock_dep = dependency('gmock')
eigen_dep = dependency('Eigen3', modules : ['Eigen3::Eigen'])
boost_dep = dependency('boost')

subdir('lib')
