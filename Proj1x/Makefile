# ---------------------------------------------------------------------------------------
# FILE NAME:         Makefile
# DESCRIPTION:
# USAGE:             make
# COMPILER:          GNU g++ compiler on Linux
#
# MODIFICATION HISTORY:
# Author               Date            Version             Description
# ---------------      ----------      -------             ------------
# Luiz Diego Garcia    04/06/19        1.0                 Created File
# Luiz Diego Garcia    04/12/19        1.1                 Addded header file
# Luiz Diego Garcia    04/12/19        1.2                 Added symbolic link
# ---------------------------------------------------------------------------------------
#
#           This is out original generic makefile command that will build
#           any stand alone ".cpp" source file.
#           Usage: e.g., make hello
#
.cpp :
	g++ -o $* $*.cpp -std=c++11
	ln -sf encode decode
#
#           This will build the files that have dependencies on .h files
#           Usage: make -f Makefile encode
#
encode  : encode.h
# ---------------------------------------------------------------------------------------