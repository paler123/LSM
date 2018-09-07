# cmake_template_project
Starting point for my cpp projects.
Contains a compilation of stuff I find useful to have when working on cpp development:
- setup for gmock (fetched from github, based on: https://crascit.com/2015/07/25/cmake-gtest/ , with added cache variable indicating if it was already downloaded)
- boost
- convenient (for me :)) directory layout
- .ycm_extra_conf.py working with compilation database
- .gitignored build directory (I tend to build in subdirectories of project_root/build. Having fixed build directory is very convenient for YCM support.

## Prerequisites
- working c++ compiler
- git (for retrieving gmock)
- sufficiently new (>= 3.0 is good enough) cmake
- to take advantage of .ycm_extra_conf.py : vim with YouCompleteMe plugin (https://github.com/Valloric/YouCompleteMe for download, install guide, etc.)
- boost, installed in a way that cmake can find it by default, if you want the project to work out of the box.
