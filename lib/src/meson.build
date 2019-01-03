lsm_sources = ['option_types.cpp',
               'Model.cpp',
               'OptionEvaluation.cpp',
               'eur_options.cpp']

lsm_lib = shared_library(
               'lsm_lib',
               lsm_sources,
               include_directories : [lsm_headers, lsm_private_includes],
               dependencies : eigen_dep,
               install : true)

