# ---------------------------------------------------------------------------------------
# FILE NAME:         Makefile
# DESCRIPTION:
# USAGE:             make
# COMPILER:          GNU g++ compiler on Linux
#
# MODIFICATION HISTORY:
# Author               Date            Version             Description
# ---------------      ----------      ------------        ------------
# Luiz Diego Garcia    2019-04-12      1.0                 Created File
# Luiz Diego Garcia    2019-04-12      1.1                 Added poly_class
# Luiz Diego Garcia    2019-04-13      1.2                 added Polynomial and po_class.o
# Luiz Diego Garcia    2019-04-13      1.2                 added %.o
# Luiz Diego Garcia    2019-04-18      1.3                 Changed to Matrix
# ---------------------------------------------------------------------------------------
#
#           This is out original generic makefile command that will build
#           any stand alone ".cpp" source file.
#           Usage: e.g., make hello
#

.cpp :
	g++ -o $* $*.cpp -std=c++11
	
#
#           This will build the two object files required for "matrix_test1"
#           and link them into a single executable.
#           Usage: make matrix_test1
#

matrix_test2 : Matrix.o matrix_test2.o
	g++ -o $@ $@.o Matrix.o  -std=c++11

#
#			This will build the two object files required for "matrix_test1"
#			which are dependent on Matrix.h
#

%.o : %.cpp Matrix.h
	g++ -c $< -std=c++11

# ---------------------------------------------------------------------------------------
