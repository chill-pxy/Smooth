# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_SOURCE_DIR = G:\Project\VsCode_project\Smooth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\Project\VsCode_project\Smooth\build

# Utility rule file for SmoothPreCompile.

# Include any custom commands dependencies for this target.
include engine/CMakeFiles/SmoothPreCompile.dir/compiler_depend.make

# Include the progress variables for this target.
include engine/CMakeFiles/SmoothPreCompile.dir/progress.make

engine/CMakeFiles/SmoothPreCompile:
	cd /d G:\Project\VsCode_project\Smooth\build\engine && "C:\Program Files\CMake\bin\cmake.exe" -E echo "************************************************************* "
	cd /d G:\Project\VsCode_project\Smooth\build\engine && "C:\Program Files\CMake\bin\cmake.exe" -E echo "**** [Precompile] BEGIN "
	cd /d G:\Project\VsCode_project\Smooth\build\engine && "C:\Program Files\CMake\bin\cmake.exe" -E echo "************************************************************* "
	cd /d G:\Project\VsCode_project\Smooth\build\engine && ..\..\engine\bin\SmoothParser.exe  G:/Project/VsCode_project/Smooth/build/parser_header.h G:/Project/VsCode_project/Smooth/engine/source * Piccolo 0
	cd /d G:\Project\VsCode_project\Smooth\build\engine && "C:\Program Files\CMake\bin\cmake.exe" -E echo "+++ Precompile finished +++"

SmoothPreCompile: engine/CMakeFiles/SmoothPreCompile
SmoothPreCompile: engine/CMakeFiles/SmoothPreCompile.dir/build.make
.PHONY : SmoothPreCompile

# Rule to build all files generated by this target.
engine/CMakeFiles/SmoothPreCompile.dir/build: SmoothPreCompile
.PHONY : engine/CMakeFiles/SmoothPreCompile.dir/build

engine/CMakeFiles/SmoothPreCompile.dir/clean:
	cd /d G:\Project\VsCode_project\Smooth\build\engine && $(CMAKE_COMMAND) -P CMakeFiles\SmoothPreCompile.dir\cmake_clean.cmake
.PHONY : engine/CMakeFiles/SmoothPreCompile.dir/clean

engine/CMakeFiles/SmoothPreCompile.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Project\VsCode_project\Smooth G:\Project\VsCode_project\Smooth\engine G:\Project\VsCode_project\Smooth\build G:\Project\VsCode_project\Smooth\build\engine G:\Project\VsCode_project\Smooth\build\engine\CMakeFiles\SmoothPreCompile.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : engine/CMakeFiles/SmoothPreCompile.dir/depend
