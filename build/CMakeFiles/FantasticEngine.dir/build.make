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
CMAKE_SOURCE_DIR = /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/build

# Include any dependencies generated for this target.
include CMakeFiles/FantasticEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FantasticEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FantasticEngine.dir/flags.make

CMakeFiles/FantasticEngine.dir/src/main.cpp.o: CMakeFiles/FantasticEngine.dir/flags.make
CMakeFiles/FantasticEngine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FantasticEngine.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FantasticEngine.dir/src/main.cpp.o -c /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/src/main.cpp

CMakeFiles/FantasticEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FantasticEngine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/src/main.cpp > CMakeFiles/FantasticEngine.dir/src/main.cpp.i

CMakeFiles/FantasticEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FantasticEngine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/src/main.cpp -o CMakeFiles/FantasticEngine.dir/src/main.cpp.s

CMakeFiles/FantasticEngine.dir/src/shader.cpp.o: CMakeFiles/FantasticEngine.dir/flags.make
CMakeFiles/FantasticEngine.dir/src/shader.cpp.o: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FantasticEngine.dir/src/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FantasticEngine.dir/src/shader.cpp.o -c /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/src/shader.cpp

CMakeFiles/FantasticEngine.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FantasticEngine.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/src/shader.cpp > CMakeFiles/FantasticEngine.dir/src/shader.cpp.i

CMakeFiles/FantasticEngine.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FantasticEngine.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/src/shader.cpp -o CMakeFiles/FantasticEngine.dir/src/shader.cpp.s

# Object files for target FantasticEngine
FantasticEngine_OBJECTS = \
"CMakeFiles/FantasticEngine.dir/src/main.cpp.o" \
"CMakeFiles/FantasticEngine.dir/src/shader.cpp.o"

# External object files for target FantasticEngine
FantasticEngine_EXTERNAL_OBJECTS =

FantasticEngine: CMakeFiles/FantasticEngine.dir/src/main.cpp.o
FantasticEngine: CMakeFiles/FantasticEngine.dir/src/shader.cpp.o
FantasticEngine: CMakeFiles/FantasticEngine.dir/build.make
FantasticEngine: Dependencies/GLFW/src/libglfw3.a
FantasticEngine: Dependencies/GLAD/libglad.a
FantasticEngine: /usr/lib/x86_64-linux-gnu/librt.so
FantasticEngine: /usr/lib/x86_64-linux-gnu/libm.so
FantasticEngine: CMakeFiles/FantasticEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FantasticEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FantasticEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FantasticEngine.dir/build: FantasticEngine

.PHONY : CMakeFiles/FantasticEngine.dir/build

CMakeFiles/FantasticEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FantasticEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FantasticEngine.dir/clean

CMakeFiles/FantasticEngine.dir/depend:
	cd /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/build /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/build /home/hobyr/Documents/CODING/999-PROJECTS/GameEngine/build/CMakeFiles/FantasticEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FantasticEngine.dir/depend
