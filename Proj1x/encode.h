/*----------------------------------------------------------------------------------------
FILE NAME:              encode.h
DESCRIPTIONS:           Header file for encode.cpp
COMPILER:               g++ under Linux

MODIFICATION HISTORY:
Author                 Date            Version    Details
-----------------      ----------      -------    ----------------------------------------
Luiz Diego Garcia      2019-04-06       1.0       Created file
Luiz Diego Garcia      2019-04-07       1.1       Added end of program prototype
Luiz Diego Garcia      2019-04-12       1.2       Added prototypes / libraries
----------------------------------------------------------------------------------------*/

//#pragma once
#ifndef __ENCODE_H__
#define __ENCODE_H__


//////////////////////////////////////
// Libraries
//////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>


//////////////////////////////////////
// Prototypes
//////////////////////////////////////
void EndOfProgram(std::ostream &out);
void OpenFiles(std::string &);
void CheckFile(std::string &, std::fstream &);
int FileSize(std::fstream &);
void ReadIntoBinary(std::fstream &);
void Decode(char *);


#endif /* __ENCODE_H__ */