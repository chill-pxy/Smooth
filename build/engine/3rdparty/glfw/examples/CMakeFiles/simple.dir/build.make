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
CMAKE_SOURCE_DIR = G:\Project\VsCode_project\Smooth.0.0.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\Project\VsCode_project\Smooth.0.0.1\build

# Include any dependencies generated for this target.
include engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/compiler_depend.make

# Include the progress variables for this target.
include engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/progress.make

# Include the compile flags for this target's objects.
include engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/flags.make

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.obj: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/flags.make
engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.obj: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/includes_C.rsp
engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.obj: ../engine/3rdparty/glfw/examples/simple.c
engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.obj: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Project\VsCode_project\Smooth.0.0.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.obj"
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && F:\QT\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.obj -MF CMakeFiles\simple.dir\simple.c.obj.d -o CMakeFiles\simple.dir\simple.c.obj -c G:\Project\VsCode_project\Smooth.0.0.1\engine\3rdparty\glfw\examples\simple.c

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/simple.c.i"
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && F:\QT\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\Project\VsCode_project\Smooth.0.0.1\engine\3rdparty\glfw\examples\simple.c > CMakeFiles\simple.dir\simple.c.i

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/simple.c.s"
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && F:\QT\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\Project\VsCode_project\Smooth.0.0.1\engine\3rdparty\glfw\examples\simple.c -o CMakeFiles\simple.dir\simple.c.s

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/flags.make
engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj: ../engine/3rdparty/glfw/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Project\VsCode_project\Smooth.0.0.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj"
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && F:\QT\Tools\mingw810_64\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) G:\Project\VsCode_project\Smooth.0.0.1\engine\3rdparty\glfw\examples\glfw.rc CMakeFiles\simple.dir\glfw.rc.obj

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/flags.make
engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/includes_C.rsp
engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: ../engine/3rdparty/glfw/deps/glad_gl.c
engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\Project\VsCode_project\Smooth.0.0.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj"
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && F:\QT\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\simple.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\simple.dir\__\deps\glad_gl.c.obj -c G:\Project\VsCode_project\Smooth.0.0.1\engine\3rdparty\glfw\deps\glad_gl.c

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/__/deps/glad_gl.c.i"
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && F:\QT\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E G:\Project\VsCode_project\Smooth.0.0.1\engine\3rdparty\glfw\deps\glad_gl.c > CMakeFiles\simple.dir\__\deps\glad_gl.c.i

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/__/deps/glad_gl.c.s"
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && F:\QT\Tools\mingw810_64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S G:\Project\VsCode_project\Smooth.0.0.1\engine\3rdparty\glfw\deps\glad_gl.c -o CMakeFiles\simple.dir\__\deps\glad_gl.c.s

# Object files for target simple
simple_OBJECTS = \
"CMakeFiles/simple.dir/simple.c.obj" \
"CMakeFiles/simple.dir/glfw.rc.obj" \
"CMakeFiles/simple.dir/__/deps/glad_gl.c.obj"

# External object files for target simple
simple_EXTERNAL_OBJECTS =

../out/simple.exe: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/simple.c.obj
../out/simple.exe: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/glfw.rc.obj
../out/simple.exe: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.obj
../out/simple.exe: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/build.make
../out/simple.exe: ../out/libglfw3.a
../out/simple.exe: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/linklibs.rsp
../out/simple.exe: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/objects1.rsp
../out/simple.exe: engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\Project\VsCode_project\Smooth.0.0.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ..\..\..\..\..\out\simple.exe"
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\simple.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/build: ../out/simple.exe
.PHONY : engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/build

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/clean:
	cd /d G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples && $(CMAKE_COMMAND) -P CMakeFiles\simple.dir\cmake_clean.cmake
.PHONY : engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/clean

engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\Project\VsCode_project\Smooth.0.0.1 G:\Project\VsCode_project\Smooth.0.0.1\engine\3rdparty\glfw\examples G:\Project\VsCode_project\Smooth.0.0.1\build G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples G:\Project\VsCode_project\Smooth.0.0.1\build\engine\3rdparty\glfw\examples\CMakeFiles\simple.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : engine/3rdparty/glfw/examples/CMakeFiles/simple.dir/depend

