lsm_sources = ['option_types.cpp',
               'Model.cpp',
               'OptionEvaluation.cpp',
               'RegressionEngine.cpp',
               'PolynomialWalk.cpp',
               'eur_options.cpp']


lsm_lib = shared_library(
               'lsm_lib',
               lsm_sources,
               cpp_args : used_warnings,
               include_directories : [lsm_headers, lsm_private_includes],
               dependencies : [eigen_dep],
               install : true)

lsm_dep = declare_dependency(
    link_with : lsm_lib,
    include_directories : lsm_headers,
    dependencies : eigen_dep)
