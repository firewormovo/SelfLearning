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
CMAKE_SOURCE_DIR = /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/build

# Include any dependencies generated for this target.
include CMakeFiles/test_thread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_thread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_thread.dir/flags.make

CMakeFiles/test_thread.dir/main.cpp.o: CMakeFiles/test_thread.dir/flags.make
CMakeFiles/test_thread.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_thread.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_thread.dir/main.cpp.o -c /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/main.cpp

CMakeFiles/test_thread.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_thread.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/main.cpp > CMakeFiles/test_thread.dir/main.cpp.i

CMakeFiles/test_thread.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_thread.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/main.cpp -o CMakeFiles/test_thread.dir/main.cpp.s

CMakeFiles/test_thread.dir/src/data_recv.cpp.o: CMakeFiles/test_thread.dir/flags.make
CMakeFiles/test_thread.dir/src/data_recv.cpp.o: ../src/data_recv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_thread.dir/src/data_recv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_thread.dir/src/data_recv.cpp.o -c /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/src/data_recv.cpp

CMakeFiles/test_thread.dir/src/data_recv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_thread.dir/src/data_recv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/src/data_recv.cpp > CMakeFiles/test_thread.dir/src/data_recv.cpp.i

CMakeFiles/test_thread.dir/src/data_recv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_thread.dir/src/data_recv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/src/data_recv.cpp -o CMakeFiles/test_thread.dir/src/data_recv.cpp.s

# Object files for target test_thread
test_thread_OBJECTS = \
"CMakeFiles/test_thread.dir/main.cpp.o" \
"CMakeFiles/test_thread.dir/src/data_recv.cpp.o"

# External object files for target test_thread
test_thread_EXTERNAL_OBJECTS =

test_thread: CMakeFiles/test_thread.dir/main.cpp.o
test_thread: CMakeFiles/test_thread.dir/src/data_recv.cpp.o
test_thread: CMakeFiles/test_thread.dir/build.make
test_thread: CMakeFiles/test_thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_thread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_thread.dir/build: test_thread

.PHONY : CMakeFiles/test_thread.dir/build

CMakeFiles/test_thread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_thread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_thread.dir/clean

CMakeFiles/test_thread.dir/depend:
	cd /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/build /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/build /Data/tianxya/Workspace/SelfLearning/C_PlusLearn/multi_thread/test_trhread/build/CMakeFiles/test_thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_thread.dir/depend
