# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sawert/qtprojects/pars

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal

# Include any dependencies generated for this target.
include CMakeFiles/pars.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pars.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pars.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pars.dir/flags.make

CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o: CMakeFiles/pars.dir/flags.make
CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o: pars_autogen/mocs_compilation.cpp
CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o: CMakeFiles/pars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o -MF CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o -c /home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal/pars_autogen/mocs_compilation.cpp

CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal/pars_autogen/mocs_compilation.cpp > CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.i

CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal/pars_autogen/mocs_compilation.cpp -o CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.s

# Object files for target pars
pars_OBJECTS = \
"CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o"

# External object files for target pars
pars_EXTERNAL_OBJECTS =

pars: CMakeFiles/pars.dir/pars_autogen/mocs_compilation.cpp.o
pars: CMakeFiles/pars.dir/build.make
pars: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
pars: /usr/lib/x86_64-linux-gnu/libcurl.so
pars: /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.74.0
pars: /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so
pars: CMakeFiles/pars.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pars"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pars.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pars.dir/build: pars
.PHONY : CMakeFiles/pars.dir/build

CMakeFiles/pars.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pars.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pars.dir/clean

CMakeFiles/pars.dir/depend:
	cd /home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sawert/qtprojects/pars /home/sawert/qtprojects/pars /home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal /home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal /home/sawert/qtprojects/pars/home/sawert/qtprojects/pars/lalal/CMakeFiles/pars.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pars.dir/depend
