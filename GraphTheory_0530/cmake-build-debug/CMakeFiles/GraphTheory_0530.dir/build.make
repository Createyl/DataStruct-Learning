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
CMAKE_SOURCE_DIR = /Users/Yichao/DataStruct-Learning/GraphTheory_0530

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Yichao/DataStruct-Learning/GraphTheory_0530/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GraphTheory_0530.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GraphTheory_0530.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GraphTheory_0530.dir/flags.make

CMakeFiles/GraphTheory_0530.dir/library.c.o: CMakeFiles/GraphTheory_0530.dir/flags.make
CMakeFiles/GraphTheory_0530.dir/library.c.o: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Yichao/DataStruct-Learning/GraphTheory_0530/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GraphTheory_0530.dir/library.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GraphTheory_0530.dir/library.c.o   -c /Users/Yichao/DataStruct-Learning/GraphTheory_0530/library.c

CMakeFiles/GraphTheory_0530.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GraphTheory_0530.dir/library.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Yichao/DataStruct-Learning/GraphTheory_0530/library.c > CMakeFiles/GraphTheory_0530.dir/library.c.i

CMakeFiles/GraphTheory_0530.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GraphTheory_0530.dir/library.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Yichao/DataStruct-Learning/GraphTheory_0530/library.c -o CMakeFiles/GraphTheory_0530.dir/library.c.s

CMakeFiles/GraphTheory_0530.dir/library.c.o.requires:

.PHONY : CMakeFiles/GraphTheory_0530.dir/library.c.o.requires

CMakeFiles/GraphTheory_0530.dir/library.c.o.provides: CMakeFiles/GraphTheory_0530.dir/library.c.o.requires
	$(MAKE) -f CMakeFiles/GraphTheory_0530.dir/build.make CMakeFiles/GraphTheory_0530.dir/library.c.o.provides.build
.PHONY : CMakeFiles/GraphTheory_0530.dir/library.c.o.provides

CMakeFiles/GraphTheory_0530.dir/library.c.o.provides.build: CMakeFiles/GraphTheory_0530.dir/library.c.o


# Object files for target GraphTheory_0530
GraphTheory_0530_OBJECTS = \
"CMakeFiles/GraphTheory_0530.dir/library.c.o"

# External object files for target GraphTheory_0530
GraphTheory_0530_EXTERNAL_OBJECTS =

libGraphTheory_0530.a: CMakeFiles/GraphTheory_0530.dir/library.c.o
libGraphTheory_0530.a: CMakeFiles/GraphTheory_0530.dir/build.make
libGraphTheory_0530.a: CMakeFiles/GraphTheory_0530.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Yichao/DataStruct-Learning/GraphTheory_0530/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libGraphTheory_0530.a"
	$(CMAKE_COMMAND) -P CMakeFiles/GraphTheory_0530.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GraphTheory_0530.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GraphTheory_0530.dir/build: libGraphTheory_0530.a

.PHONY : CMakeFiles/GraphTheory_0530.dir/build

CMakeFiles/GraphTheory_0530.dir/requires: CMakeFiles/GraphTheory_0530.dir/library.c.o.requires

.PHONY : CMakeFiles/GraphTheory_0530.dir/requires

CMakeFiles/GraphTheory_0530.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GraphTheory_0530.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GraphTheory_0530.dir/clean

CMakeFiles/GraphTheory_0530.dir/depend:
	cd /Users/Yichao/DataStruct-Learning/GraphTheory_0530/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Yichao/DataStruct-Learning/GraphTheory_0530 /Users/Yichao/DataStruct-Learning/GraphTheory_0530 /Users/Yichao/DataStruct-Learning/GraphTheory_0530/cmake-build-debug /Users/Yichao/DataStruct-Learning/GraphTheory_0530/cmake-build-debug /Users/Yichao/DataStruct-Learning/GraphTheory_0530/cmake-build-debug/CMakeFiles/GraphTheory_0530.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GraphTheory_0530.dir/depend

