project('lsm_pricing', 'cpp',
    version : '0.1',
    default_options : ['warning_level=3', 'cpp_std=c++17', 'werror=true']
)

warnings = [
    '-Werror',
    '-Wall',
    '-Wextra', 
#    '-Wshadow', 
    '-Wnon-virtual-dtor', 
    '-Wcast-align', 
    '-Wunused', 
    '-Woverloaded-virtual', 
    '-Wpedantic', 
    '-Wmisleading-indentation',
    '-Wduplicated-cond',
    '-Wlogical-op',
    '-Wnull-dereference',
    '-Wdouble-promotion',
    '-Wformat=2',
    '-Wlifetime'
]

used_warnings = []
cxx = meson.get_compiler('cpp')
if cxx.get_argument_syntax() == 'gcc'
    foreach warn : warnings
        if cxx.has_argument(warn)
            used_warnings += warn
        endif
    endforeach
endif

gmock_dep = dependency('gmock', main : false, fallback : ['gtest', 'gmock_dep'])
gmock_main_dep = dependency('gmock', main : true, fallback : ['gtest', 'gmock_main_dep'])
eigen_dep = dependency('Eigen3', modules : ['Eigen3::Eigen'], fallback : ['eigen', 'eigen_dep'])
boost_dep = dependency('boost')

subdir('lib')
