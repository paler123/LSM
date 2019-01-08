lsm_ut_sources = ['model.cpp', 'eur_options.cpp', 'RegressionEngine.cpp'] 

lsm_test_exe = executable( 
                'lsm_ut', 
                lsm_ut_sources,
                include_directories : [lsm_private_includes, testing_framework_headers],
                link_with : [testing_framework],
                dependencies : [lsm_dep, eigen_dep])


test('lsm_ut', lsm_test_exe)              
