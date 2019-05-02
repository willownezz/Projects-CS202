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
# ---------------------------------------------------------------------------------------
#
#           This is out original generic makefile command that will build
#           any stand alone ".cpp" source file.
#           Usage: e.g., make hello
#

.cpp :
	g++ -o $* $*.cpp -std=c++11
	
#
#           This will build the two object files required for "linked_list_demo"
#           and link them into a single executable.
#           Usage: make linked_list_demo
#

linked_list_demo : Int_List.o linked_list_demo.o
	g++ -o $@ $@.o Int_List.o  -std=c++11

#
#			This will build the two object files required for "linked_list_demo"
#			which are dependent on Int_List.h
#

%.o : %.cpp Int_List.h
	g++ -c $< -std=c++11


linked_list_demo: Int_List.cpp Int_List.h
# ---------------------------------------------------------------------------------------
