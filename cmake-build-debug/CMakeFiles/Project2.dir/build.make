# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project2.dir/flags.make

CMakeFiles/Project2.dir/main.cpp.obj: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project2.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project2.dir\main.cpp.obj -c "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\main.cpp"

CMakeFiles/Project2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project2.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\main.cpp" > CMakeFiles\Project2.dir\main.cpp.i

CMakeFiles/Project2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project2.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\main.cpp" -o CMakeFiles\Project2.dir\main.cpp.s

CMakeFiles/Project2.dir/ImageData.cpp.obj: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/ImageData.cpp.obj: ../ImageData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project2.dir/ImageData.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project2.dir\ImageData.cpp.obj -c "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\ImageData.cpp"

CMakeFiles/Project2.dir/ImageData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project2.dir/ImageData.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\ImageData.cpp" > CMakeFiles\Project2.dir\ImageData.cpp.i

CMakeFiles/Project2.dir/ImageData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project2.dir/ImageData.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\ImageData.cpp" -o CMakeFiles\Project2.dir\ImageData.cpp.s

# Object files for target Project2
Project2_OBJECTS = \
"CMakeFiles/Project2.dir/main.cpp.obj" \
"CMakeFiles/Project2.dir/ImageData.cpp.obj"

# External object files for target Project2
Project2_EXTERNAL_OBJECTS =

Project2.exe: CMakeFiles/Project2.dir/main.cpp.obj
Project2.exe: CMakeFiles/Project2.dir/ImageData.cpp.obj
Project2.exe: CMakeFiles/Project2.dir/build.make
Project2.exe: CMakeFiles/Project2.dir/linklibs.rsp
Project2.exe: CMakeFiles/Project2.dir/objects1.rsp
Project2.exe: CMakeFiles/Project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Project2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project2.dir/build: Project2.exe

.PHONY : CMakeFiles/Project2.dir/build

CMakeFiles/Project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project2.dir/clean

CMakeFiles/Project2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2" "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2" "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\cmake-build-debug" "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\cmake-build-debug" "C:\Users\lordr\Desktop\Project 2 - Image Processing\Project2_programming2\cmake-build-debug\CMakeFiles\Project2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project2.dir/depend

