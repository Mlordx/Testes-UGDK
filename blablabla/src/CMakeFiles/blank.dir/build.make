# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/uspgamedev/pikachu/Testes-UGDK/blablabla

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uspgamedev/pikachu/Testes-UGDK/blablabla

# Include any dependencies generated for this target.
include src/CMakeFiles/blank.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/blank.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/blank.dir/flags.make

src/CMakeFiles/blank.dir/playerfoca.cc.o: src/CMakeFiles/blank.dir/flags.make
src/CMakeFiles/blank.dir/playerfoca.cc.o: src/playerfoca.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/uspgamedev/pikachu/Testes-UGDK/blablabla/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/blank.dir/playerfoca.cc.o"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blank.dir/playerfoca.cc.o -c /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/playerfoca.cc

src/CMakeFiles/blank.dir/playerfoca.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blank.dir/playerfoca.cc.i"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/playerfoca.cc > CMakeFiles/blank.dir/playerfoca.cc.i

src/CMakeFiles/blank.dir/playerfoca.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blank.dir/playerfoca.cc.s"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/playerfoca.cc -o CMakeFiles/blank.dir/playerfoca.cc.s

src/CMakeFiles/blank.dir/playerfoca.cc.o.requires:
.PHONY : src/CMakeFiles/blank.dir/playerfoca.cc.o.requires

src/CMakeFiles/blank.dir/playerfoca.cc.o.provides: src/CMakeFiles/blank.dir/playerfoca.cc.o.requires
	$(MAKE) -f src/CMakeFiles/blank.dir/build.make src/CMakeFiles/blank.dir/playerfoca.cc.o.provides.build
.PHONY : src/CMakeFiles/blank.dir/playerfoca.cc.o.provides

src/CMakeFiles/blank.dir/playerfoca.cc.o.provides.build: src/CMakeFiles/blank.dir/playerfoca.cc.o
.PHONY : src/CMakeFiles/blank.dir/playerfoca.cc.o.provides.build

src/CMakeFiles/blank.dir/foca.cc.o: src/CMakeFiles/blank.dir/flags.make
src/CMakeFiles/blank.dir/foca.cc.o: src/foca.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/uspgamedev/pikachu/Testes-UGDK/blablabla/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/blank.dir/foca.cc.o"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blank.dir/foca.cc.o -c /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/foca.cc

src/CMakeFiles/blank.dir/foca.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blank.dir/foca.cc.i"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/foca.cc > CMakeFiles/blank.dir/foca.cc.i

src/CMakeFiles/blank.dir/foca.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blank.dir/foca.cc.s"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/foca.cc -o CMakeFiles/blank.dir/foca.cc.s

src/CMakeFiles/blank.dir/foca.cc.o.requires:
.PHONY : src/CMakeFiles/blank.dir/foca.cc.o.requires

src/CMakeFiles/blank.dir/foca.cc.o.provides: src/CMakeFiles/blank.dir/foca.cc.o.requires
	$(MAKE) -f src/CMakeFiles/blank.dir/build.make src/CMakeFiles/blank.dir/foca.cc.o.provides.build
.PHONY : src/CMakeFiles/blank.dir/foca.cc.o.provides

src/CMakeFiles/blank.dir/foca.cc.o.provides.build: src/CMakeFiles/blank.dir/foca.cc.o
.PHONY : src/CMakeFiles/blank.dir/foca.cc.o.provides.build

src/CMakeFiles/blank.dir/main.cc.o: src/CMakeFiles/blank.dir/flags.make
src/CMakeFiles/blank.dir/main.cc.o: src/main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/uspgamedev/pikachu/Testes-UGDK/blablabla/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/blank.dir/main.cc.o"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/blank.dir/main.cc.o -c /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/main.cc

src/CMakeFiles/blank.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blank.dir/main.cc.i"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/main.cc > CMakeFiles/blank.dir/main.cc.i

src/CMakeFiles/blank.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blank.dir/main.cc.s"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/main.cc -o CMakeFiles/blank.dir/main.cc.s

src/CMakeFiles/blank.dir/main.cc.o.requires:
.PHONY : src/CMakeFiles/blank.dir/main.cc.o.requires

src/CMakeFiles/blank.dir/main.cc.o.provides: src/CMakeFiles/blank.dir/main.cc.o.requires
	$(MAKE) -f src/CMakeFiles/blank.dir/build.make src/CMakeFiles/blank.dir/main.cc.o.provides.build
.PHONY : src/CMakeFiles/blank.dir/main.cc.o.provides

src/CMakeFiles/blank.dir/main.cc.o.provides.build: src/CMakeFiles/blank.dir/main.cc.o
.PHONY : src/CMakeFiles/blank.dir/main.cc.o.provides.build

# Object files for target blank
blank_OBJECTS = \
"CMakeFiles/blank.dir/playerfoca.cc.o" \
"CMakeFiles/blank.dir/foca.cc.o" \
"CMakeFiles/blank.dir/main.cc.o"

# External object files for target blank
blank_EXTERNAL_OBJECTS =

blank: src/CMakeFiles/blank.dir/playerfoca.cc.o
blank: src/CMakeFiles/blank.dir/foca.cc.o
blank: src/CMakeFiles/blank.dir/main.cc.o
blank: /usr/lib/libugdk0.4.so
blank: /usr/lib/libGLU.so
blank: /usr/lib/libGL.so
blank: /usr/lib/libSM.so
blank: /usr/lib/libICE.so
blank: /usr/lib/libX11.so
blank: /usr/lib/libXext.so
blank: /usr/lib/libSDLmain.a
blank: /usr/lib/libSDL.so
blank: /usr/lib/libSDL_mixer.so
blank: /usr/lib/libSDL_ttf.so
blank: /usr/lib/libSDL_image.so
blank: /usr/lib/liblua5.1.so
blank: /usr/lib/libm.so
blank: /usr/lib/libpython2.6.so
blank: src/CMakeFiles/blank.dir/build.make
blank: src/CMakeFiles/blank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../blank"
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/blank.dir/build: blank
.PHONY : src/CMakeFiles/blank.dir/build

src/CMakeFiles/blank.dir/requires: src/CMakeFiles/blank.dir/playerfoca.cc.o.requires
src/CMakeFiles/blank.dir/requires: src/CMakeFiles/blank.dir/foca.cc.o.requires
src/CMakeFiles/blank.dir/requires: src/CMakeFiles/blank.dir/main.cc.o.requires
.PHONY : src/CMakeFiles/blank.dir/requires

src/CMakeFiles/blank.dir/clean:
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src && $(CMAKE_COMMAND) -P CMakeFiles/blank.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/blank.dir/clean

src/CMakeFiles/blank.dir/depend:
	cd /home/uspgamedev/pikachu/Testes-UGDK/blablabla && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uspgamedev/pikachu/Testes-UGDK/blablabla /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src /home/uspgamedev/pikachu/Testes-UGDK/blablabla /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src /home/uspgamedev/pikachu/Testes-UGDK/blablabla/src/CMakeFiles/blank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/blank.dir/depend

