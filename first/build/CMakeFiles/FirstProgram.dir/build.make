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
CMAKE_SOURCE_DIR = /home/david/Desktop/project/first

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/Desktop/project/first/build

# Include any dependencies generated for this target.
include CMakeFiles/FirstProgram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FirstProgram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FirstProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FirstProgram.dir/flags.make

CMakeFiles/FirstProgram.dir/main.cpp.o: CMakeFiles/FirstProgram.dir/flags.make
CMakeFiles/FirstProgram.dir/main.cpp.o: ../main.cpp
CMakeFiles/FirstProgram.dir/main.cpp.o: CMakeFiles/FirstProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Desktop/project/first/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FirstProgram.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FirstProgram.dir/main.cpp.o -MF CMakeFiles/FirstProgram.dir/main.cpp.o.d -o CMakeFiles/FirstProgram.dir/main.cpp.o -c /home/david/Desktop/project/first/main.cpp

CMakeFiles/FirstProgram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstProgram.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Desktop/project/first/main.cpp > CMakeFiles/FirstProgram.dir/main.cpp.i

CMakeFiles/FirstProgram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstProgram.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Desktop/project/first/main.cpp -o CMakeFiles/FirstProgram.dir/main.cpp.s

CMakeFiles/FirstProgram.dir/thread_obj.cpp.o: CMakeFiles/FirstProgram.dir/flags.make
CMakeFiles/FirstProgram.dir/thread_obj.cpp.o: ../thread_obj.cpp
CMakeFiles/FirstProgram.dir/thread_obj.cpp.o: CMakeFiles/FirstProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/Desktop/project/first/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FirstProgram.dir/thread_obj.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FirstProgram.dir/thread_obj.cpp.o -MF CMakeFiles/FirstProgram.dir/thread_obj.cpp.o.d -o CMakeFiles/FirstProgram.dir/thread_obj.cpp.o -c /home/david/Desktop/project/first/thread_obj.cpp

CMakeFiles/FirstProgram.dir/thread_obj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstProgram.dir/thread_obj.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/Desktop/project/first/thread_obj.cpp > CMakeFiles/FirstProgram.dir/thread_obj.cpp.i

CMakeFiles/FirstProgram.dir/thread_obj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstProgram.dir/thread_obj.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/Desktop/project/first/thread_obj.cpp -o CMakeFiles/FirstProgram.dir/thread_obj.cpp.s

# Object files for target FirstProgram
FirstProgram_OBJECTS = \
"CMakeFiles/FirstProgram.dir/main.cpp.o" \
"CMakeFiles/FirstProgram.dir/thread_obj.cpp.o"

# External object files for target FirstProgram
FirstProgram_EXTERNAL_OBJECTS =

FirstProgram: CMakeFiles/FirstProgram.dir/main.cpp.o
FirstProgram: CMakeFiles/FirstProgram.dir/thread_obj.cpp.o
FirstProgram: CMakeFiles/FirstProgram.dir/build.make
FirstProgram: CMakeFiles/FirstProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/Desktop/project/first/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FirstProgram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FirstProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FirstProgram.dir/build: FirstProgram
.PHONY : CMakeFiles/FirstProgram.dir/build

CMakeFiles/FirstProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FirstProgram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FirstProgram.dir/clean

CMakeFiles/FirstProgram.dir/depend:
	cd /home/david/Desktop/project/first/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/Desktop/project/first /home/david/Desktop/project/first /home/david/Desktop/project/first/build /home/david/Desktop/project/first/build /home/david/Desktop/project/first/build/CMakeFiles/FirstProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FirstProgram.dir/depend

