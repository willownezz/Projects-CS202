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
# ---------------------------------------------------------------------------------------
#
#           This is out original generic makefile command that will build
#           any stand alone ".cpp" source file.
#           Usage: e.g., make hello
#

.cpp :
	g++ -o $* $*.cpp -std=c++11
	
#
#           This will build the two object files required for "poly_class"
#           and link them into a single executable.
#           Usage: make poly_class
#

poly_class : Polynomial.o poly_class.o
	g++ -o $@ $@.o Polynomial.o  -std=c++11

#
#			This will build the two object files required for "poly_class"
#			which are dependent on Polynomial.h
#

%.o : %.cpp Polynomial.h
	g++ -c $< -std=c++11

# ---------------------------------------------------------------------------------------