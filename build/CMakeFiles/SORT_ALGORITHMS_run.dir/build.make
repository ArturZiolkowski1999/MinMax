# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ziolko/sort_algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ziolko/sort_algorithms/build

# Include any dependencies generated for this target.
include CMakeFiles/SORT_ALGORITHMS_run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SORT_ALGORITHMS_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SORT_ALGORITHMS_run.dir/flags.make

CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.o: CMakeFiles/SORT_ALGORITHMS_run.dir/flags.make
CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziolko/sort_algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.o -c /home/ziolko/sort_algorithms/src/main.cpp

CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziolko/sort_algorithms/src/main.cpp > CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.i

CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziolko/sort_algorithms/src/main.cpp -o CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.s

# Object files for target SORT_ALGORITHMS_run
SORT_ALGORITHMS_run_OBJECTS = \
"CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.o"

# External object files for target SORT_ALGORITHMS_run
SORT_ALGORITHMS_run_EXTERNAL_OBJECTS =

SORT_ALGORITHMS_run: CMakeFiles/SORT_ALGORITHMS_run.dir/src/main.cpp.o
SORT_ALGORITHMS_run: CMakeFiles/SORT_ALGORITHMS_run.dir/build.make
SORT_ALGORITHMS_run: CMakeFiles/SORT_ALGORITHMS_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziolko/sort_algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SORT_ALGORITHMS_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SORT_ALGORITHMS_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SORT_ALGORITHMS_run.dir/build: SORT_ALGORITHMS_run

.PHONY : CMakeFiles/SORT_ALGORITHMS_run.dir/build

CMakeFiles/SORT_ALGORITHMS_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SORT_ALGORITHMS_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SORT_ALGORITHMS_run.dir/clean

CMakeFiles/SORT_ALGORITHMS_run.dir/depend:
	cd /home/ziolko/sort_algorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziolko/sort_algorithms /home/ziolko/sort_algorithms /home/ziolko/sort_algorithms/build /home/ziolko/sort_algorithms/build /home/ziolko/sort_algorithms/build/CMakeFiles/SORT_ALGORITHMS_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SORT_ALGORITHMS_run.dir/depend
