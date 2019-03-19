# ------------------------------------------------------------------------------
# FILE NAME:         Makefile
# DESCRIPTION:
# USAGE:             make
# COMPILER:          GNU g++ compiler on Linux
#
# MODIFICATION HISTORY:
# Author               Date            Version             Description
# ---------------      ----------      ------------        ------------
# Luiz Diego Garcia    02/18/19        0.0.1               Created File
# Luiz Diego Garcia    02/26/19        0.0.2               Changed to Makefile2
# ------------------------------------------------------------------------------

#           This is out original generic makefile command that will build
#           any stand alone ".cpp" source file.
#           Usage: e.g., make hello

.cpp :
	g++ -o $* $*.cpp -std=c++11

#           This will build the files that have dependencies on .h files
#           Usage: make -f Makefile2 structures_v14

structures_v13 : structures_v13.h
structures_v14 : structures_v14.h
