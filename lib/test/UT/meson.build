lsm_ut_sources = [
    'model.cpp', 
    'eur_options.cpp', 
    'PolynomialWalk.cpp',
    'RegressionEngine.cpp'
] 

lsm_test_exe = executable( 
    'lsm_ut', 
    lsm_ut_sources,
    include_directories : [lsm_private_includes],
    dependencies : [lsm_testing_dep]
)


test('lsm_ut', lsm_test_exe)              
