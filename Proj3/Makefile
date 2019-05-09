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
# Luiz Diego Garcia    2019-04-13      1.3                 added %.o
# Luiz Diego Garcia    2019-04-18      1.4                 changed to matrix_test3 
# Luiz Diego Garcia    2019-05-06      1.5                 changed to matrix_math 
# ---------------------------------------------------------------------------------------
#
#           This is out original generic makefile command that will build
#           any stand alone ".cpp" source file.
#           Usage: e.g., make hello
#

.cpp :
	g++ -o $* $*.cpp -std=c++11
	
#
#           This will build the two object files required for "matrix_math"
#           and link them into a single executable.
#           Usage: make matrix_math
#

matrix_math : Matrix.o matrix_math.o
	g++ -o $@ $@.o Matrix.o  -std=c++11

#
#			This will build the two object files required for "matrix_math"
#			which are dependent on Matrix.h
#

%.o : %.cpp Matrix.h
	g++ -c -o $@ $< -std=c++11

matrix_math : Matrix.cpp Matrix.h
matrix_math.o : Matrix.o
# ---------------------------------------------------------------------------------------
