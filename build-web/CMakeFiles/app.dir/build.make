# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\_Code\_Hobby\Web\webgpu-cross-platform-app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\_Code\_Hobby\Web\webgpu-cross-platform-app\build-web

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/main.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/main.cpp.o: D:/_Code/_Hobby/Web/webgpu-cross-platform-app/main.cpp
CMakeFiles/app.dir/main.cpp.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\_Code\_Hobby\Web\webgpu-cross-platform-app\build-web\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/main.cpp.o"
	C:\emsdk\upstream\emscripten\em++.bat $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/app.dir/main.cpp.o -MF CMakeFiles\app.dir\main.cpp.o.d -o CMakeFiles\app.dir\main.cpp.o -c D:\_Code\_Hobby\Web\webgpu-cross-platform-app\main.cpp

CMakeFiles/app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/app.dir/main.cpp.i"
	C:\emsdk\upstream\emscripten\em++.bat $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\_Code\_Hobby\Web\webgpu-cross-platform-app\main.cpp > CMakeFiles\app.dir\main.cpp.i

CMakeFiles/app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/app.dir/main.cpp.s"
	C:\emsdk\upstream\emscripten\em++.bat $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\_Code\_Hobby\Web\webgpu-cross-platform-app\main.cpp -o CMakeFiles\app.dir\main.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/main.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app.html: CMakeFiles/app.dir/main.cpp.o
app.html: CMakeFiles/app.dir/build.make
app.html: CMakeFiles/app.dir/objects1.rsp
app.html: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\_Code\_Hobby\Web\webgpu-cross-platform-app\build-web\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable app.html"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\app.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app.html
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\app.dir\cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\_Code\_Hobby\Web\webgpu-cross-platform-app D:\_Code\_Hobby\Web\webgpu-cross-platform-app D:\_Code\_Hobby\Web\webgpu-cross-platform-app\build-web D:\_Code\_Hobby\Web\webgpu-cross-platform-app\build-web D:\_Code\_Hobby\Web\webgpu-cross-platform-app\build-web\CMakeFiles\app.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/app.dir/depend

