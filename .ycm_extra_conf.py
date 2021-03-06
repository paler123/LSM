import os
import ycm_core

# list of include flags obtained by running: echo | clang -E -v -x c++ -
flags = [
    '-isystem/usr/local/include/c++/8.1.0',
    '-isystem/usr/lib/gcc/x86_64-linux-gnu/7.3.0/../../../../include/c++/7.3.0',
    '-isystem/usr/lib/gcc/x86_64-linux-gnu/7.3.0/../../../../include/x86_64-linux-gnu/c++/7.3.0',
    '-isystem/usr/lib/gcc/x86_64-linux-gnu/7.3.0/../../../../include/c++/7.3.0/backward',
    '-isystem/usr/include/clang/6.0.0/include',
    '-isystem/usr/local/include',
    '-isystem/usr/include/x86_64-linux-gnu',
    '-isystem/usr/include',
]


# points to build directory where compile_commands.json will be generated
# assumes standard project structure
compilation_database_folder = os.path.join(os.path.abspath(os.path.dirname(__file__)), "build")

if os.path.exists( compilation_database_folder ):
  database = ycm_core.CompilationDatabase( compilation_database_folder )
else:
  database = None

SOURCE_EXTENSIONS = [ '.C', '.cpp', '.cxx', '.cc', '.c', '.m', '.mm' ]

# copy pasted from other .ycm_extra_conf.py files
# does not seem very pretty but kind of works with compile db output
def MakeRelativePathsInFlagsAbsolute( flags, working_directory ):
  if not working_directory:
    return list( flags )
  new_flags = []
  make_next_absolute = False
  path_flags = [ '-isystem', '-I', '-iquote', '--sysroot=' ]
  for flag in flags:
    new_flag = flag

    if make_next_absolute:
      make_next_absolute = False
      if not flag.startswith( '/' ):
        new_flag = os.path.join( working_directory, flag )

    for path_flag in path_flags:
      if flag == path_flag:
        make_next_absolute = True
        break

      if flag.startswith( path_flag ):
        path = flag[ len( path_flag ): ]
        new_flag = path_flag + os.path.join( working_directory, path )
        break

    if new_flag:
      new_flags.append( new_flag )
  return new_flags


def IsHeaderFile( filename ):
  extension = os.path.splitext( filename )[ 1 ]
  return extension in [ '.H', '.h', '.hxx', '.hpp', '.hh' ]

def is_public_header(header_file):
    return os.path.basename(
            os.path.abspath(
             os.path.join(os.path.dirname(header_file), "../"))) == "include"

# does nothing for private headers,
# for public headers goes to the impl directory: see the project structure docs
def find_matching_source_dir(header_file):
    if is_public_header(header_file): # public headers in root/lib/include/lib
        return os.path.join(os.path.dirname(header_file), "../../src")
    return os.path.dirname(header_file)


def GetCompilationInfoForFile( filename ):
  # The compilation_commands.json file generated by CMake does not have entries
  # for header files. So we do our best by asking the db for flags for a
  # corresponding source file, if any. If one exists, the flags for that file
  # should be good enough.
  if IsHeaderFile( filename ):
      base_dir = find_matching_source_dir(filename)
      file_without_ext = os.path.splitext(os.path.basename(filename))[0]
      for extension in SOURCE_EXTENSIONS:
        replacement_file = os.path.join(base_dir, file_without_ext + extension)
        if os.path.exists( replacement_file ):
          compilation_info = database.GetCompilationInfoForFile(
            replacement_file )
          if compilation_info.compiler_flags_:
            return compilation_info
      return None
  return database.GetCompilationInfoForFile( filename )

# returns union of compilation db flags for file + default ones
def FlagsForFile( filename, **kwargs ):
  final_flags = []
  if database:
    # Bear in mind that compilation_info.compiler_flags_ does NOT return a
    # python list, but a "list-like" StringVec object
    compilation_info = GetCompilationInfoForFile( filename )
    if(compilation_info):
      final_flags = MakeRelativePathsInFlagsAbsolute(
        compilation_info.compiler_flags_,
        compilation_info.compiler_working_dir_ )
      if(final_flags):
        final_flags = final_flags[:1] + flags + final_flags[1:]
  if not final_flags: # default the flags so that at least boost / stl works`
    final_flags = flags
  return {
    'flags': final_flags,
    'do_cache': True
  }

