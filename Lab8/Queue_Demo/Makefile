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
# Luiz Diego Garcia    2019-05-02      5.0                 Changed to Queue files
# ---------------------------------------------------------------------------------------
#
#           This is out original generic makefile command that will build
#           any stand alone ".cpp" source file.
#           Usage: e.g., make hello
#

.cpp :
	g++ -o $* $*.cpp -std=c++11
	
#
#           This will build the two object files required for "queue_demo"
#           and link them into a single executable.
#           Usage: make queue_demo
#

queue_demo : Dyn_Queue.o queue_demo.o
	g++ -o $@ $@.o Dyn_Queue.o  -std=c++11

#
#			This will build the two object files required for "queue_demo"
#			which are dependent on Dyn_Queue.h
#

%.o : %.cpp Dyn_Queue.h
	g++ -c $< -std=c++11


queue_demo: Dyn_Queue.cpp Dyn_Queue.h
# ---------------------------------------------------------------------------------------
