lsm_ut_sources = ['model.cpp', 'eur_options.cpp'] 

lsm_test_exe = executable( 
                'lsm_ut', 
                lsm_ut_sources,
                include_directories : [lsm_headers, lsm_private_includes, testing_framework_headers],
                link_with : [lsm_lib, testing_framework],
                dependencies : [eigen_dep])


test('lsm_ut', lsm_test_exe)              
