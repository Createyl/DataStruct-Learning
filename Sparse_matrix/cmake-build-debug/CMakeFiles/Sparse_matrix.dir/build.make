# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Yichao/DataStruct-Learning/Sparse_matrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Yichao/DataStruct-Learning/Sparse_matrix/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sparse_matrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sparse_matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sparse_matrix.dir/flags.make

CMakeFiles/Sparse_matrix.dir/main.cpp.o: CMakeFiles/Sparse_matrix.dir/flags.make
CMakeFiles/Sparse_matrix.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Yichao/DataStruct-Learning/Sparse_matrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sparse_matrix.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sparse_matrix.dir/main.cpp.o -c /Users/Yichao/DataStruct-Learning/Sparse_matrix/main.cpp

CMakeFiles/Sparse_matrix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sparse_matrix.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Yichao/DataStruct-Learning/Sparse_matrix/main.cpp > CMakeFiles/Sparse_matrix.dir/main.cpp.i

CMakeFiles/Sparse_matrix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sparse_matrix.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Yichao/DataStruct-Learning/Sparse_matrix/main.cpp -o CMakeFiles/Sparse_matrix.dir/main.cpp.s

CMakeFiles/Sparse_matrix.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Sparse_matrix.dir/main.cpp.o.requires

CMakeFiles/Sparse_matrix.dir/main.cpp.o.provides: CMakeFiles/Sparse_matrix.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Sparse_matrix.dir/build.make CMakeFiles/Sparse_matrix.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Sparse_matrix.dir/main.cpp.o.provides

CMakeFiles/Sparse_matrix.dir/main.cpp.o.provides.build: CMakeFiles/Sparse_matrix.dir/main.cpp.o


# Object files for target Sparse_matrix
Sparse_matrix_OBJECTS = \
"CMakeFiles/Sparse_matrix.dir/main.cpp.o"

# External object files for target Sparse_matrix
Sparse_matrix_EXTERNAL_OBJECTS =

Sparse_matrix: CMakeFiles/Sparse_matrix.dir/main.cpp.o
Sparse_matrix: CMakeFiles/Sparse_matrix.dir/build.make
Sparse_matrix: CMakeFiles/Sparse_matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Yichao/DataStruct-Learning/Sparse_matrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sparse_matrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sparse_matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sparse_matrix.dir/build: Sparse_matrix

.PHONY : CMakeFiles/Sparse_matrix.dir/build

CMakeFiles/Sparse_matrix.dir/requires: CMakeFiles/Sparse_matrix.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Sparse_matrix.dir/requires

CMakeFiles/Sparse_matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Sparse_matrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Sparse_matrix.dir/clean

CMakeFiles/Sparse_matrix.dir/depend:
	cd /Users/Yichao/DataStruct-Learning/Sparse_matrix/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Yichao/DataStruct-Learning/Sparse_matrix /Users/Yichao/DataStruct-Learning/Sparse_matrix /Users/Yichao/DataStruct-Learning/Sparse_matrix/cmake-build-debug /Users/Yichao/DataStruct-Learning/Sparse_matrix/cmake-build-debug /Users/Yichao/DataStruct-Learning/Sparse_matrix/cmake-build-debug/CMakeFiles/Sparse_matrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sparse_matrix.dir/depend

