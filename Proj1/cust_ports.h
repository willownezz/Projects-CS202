/*----------------------------------------------------------------------------------------
FILE NAME:              cust_ports.h
DESCRIPTIONS:           Header file for cust_ports_v1.cpp
COMPILER:               g++ under Linux
NOTES:                  cust_ports

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
#include <istream>
#include <cstdio>
#include <cctype>
#include <limits>
#include <cstdlib>

//////////////////////////////////////
// Structures(Blueprints)
//////////////////////////////////////
struct AccInfo 
{
    char acc_id[7];
    char acc_balance[19];
    char growth_rate[9];
    char comp_per_year[9];
};
struct Customer
{
    char customer_id[7];
    char last_name[21];
    char first_name[21];
    char middle_name[21];
    char tax_id_num[19];
    char phone_num[20];
    AccInfo acc_info[5];
};

//////////////////////////////////////
// Prototypes
//////////////////////////////////////
void EndOfProgram(std::ostream &out);
void CloseFile(std::fstream &);
void CustomerInfoDisp(std::ostream &out, std::fstream &, Customer newCust[]);
void ReportFile(std::ostream &out, Customer newCust[]);
char MenuInteractive(std::ostream &out, char &choice, std::fstream &, std::fstream &, Customer newCust[]);
bool noMatchFun();
void check_arg(char [],std::ostream &out,std::fstream &, Customer newCust[]);
void HelpFile();
void ReadCustFile(Customer newCust[], std::fstream &);
void DepositFunds(std::ostream &out, Customer newCust[]);
void NewCustomer(std::ostream &out, Customer newCust[]);
void ShowFundsProj(std::ostream &out, Customer newCust[]);
void UserFileChoice(std::ostream &out, std::fstream &, Customer newCust[]);

#endif /* __CUST_PORTS_H_ */
