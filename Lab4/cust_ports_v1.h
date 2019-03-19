/*----------------------------------------------------------------------------------------
FILE NAME:              cust_ports.h
DESCRIPTIONS:           Header file for cust_ports_v1.cpp
COMPILER:               g++ under Linux
NOTES:                  cust_ports_v1

MODIFICATION HISTORY:
Author                 Date            Version    Details
-----------------      ----------      -------    ----------------------------------------
Luiz Diego Garcia      2019-02-26      0.0.1      Created file
Luiz Diego Garcia      2019-02-28      0.0.2      Added <include> files
Luiz Diego Garcia      2019-02-28      0.0.3      Added Strucst and prototypes
Luiz Diego Garcia      2019-03-02      0.0.4      Changed customer structure into to char
Luiz Diego Garcia      2019-03-03      0.0.5      Created empty future prototypes
----------------------------------------------------------------------------------------*/

//#pragma once
#ifndef __CUST_PORTS_H__
#define __CUST_PORTS_H__


//////////////////////////////////////
// Libraries
//////////////////////////////////////
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <limits>


//////////////////////////////////////
// Prototypes
//////////////////////////////////////
void FileCheck(std::ostream &out, std::fstream &);
void EndOfProgram(std::ostream &out);
void CloseFile(std::fstream &);
void NewCustomer(std::ostream &out, std::fstream &);


//////////////////////////////////////
// Structures(Blueprints)
//////////////////////////////////////
struct AccInfo 
{
    char ACC_ID[7];
    char ACC_BALANCE[13];
    char GROWTH_RATE[7];
    char COMP_PER_YEAR[3];
    char EMPTY_LINE[5];
};
struct Customer
{
    char CUSTOMER_ID[7];
    char LAST_NAME[21];
    char FIRST_NAME[21];
    char MIDDLE_NAME[21];
    char TAX_ID_NUMBER[13];
    char PHONE_NUMBER[20];
    AccInfo ACC_IN[5];
};


#endif /* __CUST_PORTS_H_ */