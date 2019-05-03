# ---------------------------------------------------------------------------------------
# FILE NAME:         Makefile
# DESCRIPTION:
# USAGE:             make
# COMPILER:          GNU g++ compiler on Linux
#
# MODIFICATION HISTORY:
# Author               Date            Version             Description
# ---------------      ----------      ------------        ------------
# Luiz Diego Garcia    2019-04-29      1.0                 Created File
# Luiz Diego Garcia    2019-04-29      2.0                 Added standard build .cpp
# Luiz Diego Garcia    2019-04-29      3.0                 changed file names to Lab8
# Luiz Diego Garcia    2019-05-02      4.0                 Removed unused links
# Luiz Diego Garcia    2019-05-02      5.0                 Changed to stack files
# ---------------------------------------------------------------------------------------
#
#           This is out original generic makefile command that will build
#           any stand alone ".cpp" source file.
#           Usage: e.g., make hello
#

.cpp :
	g++ -o $* $*.cpp -std=c++11
	
#
#           This will build the two object files required for "stack_demo"
#           and link them into a single executable.
#           Usage: make stack_demo
#

stack_demo : Dyn_Stack.o stack_demo.o
	g++ -o $@ $@.o Dyn_Stack.o  -std=c++11

#
#			This will build the two object files required for "stack_demo"
#			which are dependent on Dyn_Stack.h
#

%.o : %.cpp Dyn_Stack.h
	g++ -c $< -std=c++11


stack_demo: Dyn_Stack.cpp Dyn_Stack.h
# ---------------------------------------------------------------------------------------
