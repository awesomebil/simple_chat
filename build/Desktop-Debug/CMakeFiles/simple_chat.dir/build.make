# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/belol/repos/simple_chat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/belol/repos/simple_chat/build/Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/simple_chat.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/simple_chat.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_chat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_chat.dir/flags.make

simple_chat_autogen/timestamp: /usr/bin/moc
simple_chat_autogen/timestamp: /usr/bin/uic
simple_chat_autogen/timestamp: CMakeFiles/simple_chat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/belol/repos/simple_chat/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target simple_chat"
	/usr/bin/cmake -E cmake_autogen /home/belol/repos/simple_chat/build/Desktop-Debug/CMakeFiles/simple_chat_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/belol/repos/simple_chat/build/Desktop-Debug/simple_chat_autogen/timestamp

CMakeFiles/simple_chat.dir/codegen:
.PHONY : CMakeFiles/simple_chat.dir/codegen

CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o: CMakeFiles/simple_chat.dir/flags.make
CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o: simple_chat_autogen/mocs_compilation.cpp
CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o: CMakeFiles/simple_chat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/belol/repos/simple_chat/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o -MF CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o -c /home/belol/repos/simple_chat/build/Desktop-Debug/simple_chat_autogen/mocs_compilation.cpp

CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/belol/repos/simple_chat/build/Desktop-Debug/simple_chat_autogen/mocs_compilation.cpp > CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.i

CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/belol/repos/simple_chat/build/Desktop-Debug/simple_chat_autogen/mocs_compilation.cpp -o CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.s

CMakeFiles/simple_chat.dir/main.cpp.o: CMakeFiles/simple_chat.dir/flags.make
CMakeFiles/simple_chat.dir/main.cpp.o: /home/belol/repos/simple_chat/main.cpp
CMakeFiles/simple_chat.dir/main.cpp.o: CMakeFiles/simple_chat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/belol/repos/simple_chat/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/simple_chat.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simple_chat.dir/main.cpp.o -MF CMakeFiles/simple_chat.dir/main.cpp.o.d -o CMakeFiles/simple_chat.dir/main.cpp.o -c /home/belol/repos/simple_chat/main.cpp

CMakeFiles/simple_chat.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/simple_chat.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/belol/repos/simple_chat/main.cpp > CMakeFiles/simple_chat.dir/main.cpp.i

CMakeFiles/simple_chat.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/simple_chat.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/belol/repos/simple_chat/main.cpp -o CMakeFiles/simple_chat.dir/main.cpp.s

CMakeFiles/simple_chat.dir/chatsession.cpp.o: CMakeFiles/simple_chat.dir/flags.make
CMakeFiles/simple_chat.dir/chatsession.cpp.o: /home/belol/repos/simple_chat/chatsession.cpp
CMakeFiles/simple_chat.dir/chatsession.cpp.o: CMakeFiles/simple_chat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/belol/repos/simple_chat/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/simple_chat.dir/chatsession.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simple_chat.dir/chatsession.cpp.o -MF CMakeFiles/simple_chat.dir/chatsession.cpp.o.d -o CMakeFiles/simple_chat.dir/chatsession.cpp.o -c /home/belol/repos/simple_chat/chatsession.cpp

CMakeFiles/simple_chat.dir/chatsession.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/simple_chat.dir/chatsession.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/belol/repos/simple_chat/chatsession.cpp > CMakeFiles/simple_chat.dir/chatsession.cpp.i

CMakeFiles/simple_chat.dir/chatsession.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/simple_chat.dir/chatsession.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/belol/repos/simple_chat/chatsession.cpp -o CMakeFiles/simple_chat.dir/chatsession.cpp.s

CMakeFiles/simple_chat.dir/message_server.cpp.o: CMakeFiles/simple_chat.dir/flags.make
CMakeFiles/simple_chat.dir/message_server.cpp.o: /home/belol/repos/simple_chat/message_server.cpp
CMakeFiles/simple_chat.dir/message_server.cpp.o: CMakeFiles/simple_chat.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/belol/repos/simple_chat/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/simple_chat.dir/message_server.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/simple_chat.dir/message_server.cpp.o -MF CMakeFiles/simple_chat.dir/message_server.cpp.o.d -o CMakeFiles/simple_chat.dir/message_server.cpp.o -c /home/belol/repos/simple_chat/message_server.cpp

CMakeFiles/simple_chat.dir/message_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/simple_chat.dir/message_server.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/belol/repos/simple_chat/message_server.cpp > CMakeFiles/simple_chat.dir/message_server.cpp.i

CMakeFiles/simple_chat.dir/message_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/simple_chat.dir/message_server.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/belol/repos/simple_chat/message_server.cpp -o CMakeFiles/simple_chat.dir/message_server.cpp.s

# Object files for target simple_chat
simple_chat_OBJECTS = \
"CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/simple_chat.dir/main.cpp.o" \
"CMakeFiles/simple_chat.dir/chatsession.cpp.o" \
"CMakeFiles/simple_chat.dir/message_server.cpp.o"

# External object files for target simple_chat
simple_chat_EXTERNAL_OBJECTS =

simple_chat: CMakeFiles/simple_chat.dir/simple_chat_autogen/mocs_compilation.cpp.o
simple_chat: CMakeFiles/simple_chat.dir/main.cpp.o
simple_chat: CMakeFiles/simple_chat.dir/chatsession.cpp.o
simple_chat: CMakeFiles/simple_chat.dir/message_server.cpp.o
simple_chat: CMakeFiles/simple_chat.dir/build.make
simple_chat: CMakeFiles/simple_chat.dir/compiler_depend.ts
simple_chat: /usr/lib/libQt5Widgets.so.5.15.16
simple_chat: /usr/lib/libQt5Gui.so.5.15.16
simple_chat: /usr/lib/libQt5Core.so.5.15.16
simple_chat: CMakeFiles/simple_chat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/belol/repos/simple_chat/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable simple_chat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_chat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_chat.dir/build: simple_chat
.PHONY : CMakeFiles/simple_chat.dir/build

CMakeFiles/simple_chat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_chat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_chat.dir/clean

CMakeFiles/simple_chat.dir/depend: simple_chat_autogen/timestamp
	cd /home/belol/repos/simple_chat/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/belol/repos/simple_chat /home/belol/repos/simple_chat /home/belol/repos/simple_chat/build/Desktop-Debug /home/belol/repos/simple_chat/build/Desktop-Debug /home/belol/repos/simple_chat/build/Desktop-Debug/CMakeFiles/simple_chat.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/simple_chat.dir/depend

