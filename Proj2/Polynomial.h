/*----------------------------------------------------------------------------------------
FILE NAME:              Polynomial.h
DESCRIPTIONS:           Header file for encode.cpp
COMPILER:               g++ under Linux

MODIFICATION HISTORY:
Author                 Date            Version    Details
-----------------      ----------      -------    ----------------------------------------
Luiz Diego Garcia      2019-04-10       1.0       Created file
Luiz Diego Garcia      2019-04-12       1.1       Added end of program prototype
Luiz Diego Garcia      2019-04-13       1.2       Added prototypes / libraries
Luiz Diego Garcia      2019-04-17       1.3       Removed get.poly()
Luiz Diego Garcia      2019-04-17       1.4       Added destructor
Luiz Diego Garcia      2019-04-17       1.5       Added == Overload
Luiz Diego Garcia      2019-04-17       1.6       Added - Overload
Luiz Diego Garcia      2019-04-17       1.7       Added + Overload
Luiz Diego Garcia      2019-04-17       1.8       Added * Overload
Luiz Diego Garcia      2019-04-17       1.9       Added = Overload
Luiz Diego Garcia      2019-04-17       1.10      Added Constructor overload
Luiz Diego Garcia      2019-04-17       1.11      Added istream >> overload
Luiz Diego Garcia      2019-04-17       1.12      Added ostream << overload
----------------------------------------------------------------------------------------*/

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

//////////////////////////////////////
// Libraries
//////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

//////////////////////////////////////
// Prototypes
//////////////////////////////////////
void EndOfProgram(ostream &out);

//////////////////////////////////////
// Classes
//////////////////////////////////////
class Polynomial
{
    private:
        int degree;         // Degree of the polynomial
        int coef[99];       // Array of coefficients
        int x = 0;

    public:
        Polynomial();               // Constructor
        ~Polynomial();              // Destructor
        Polynomial(int,int*);       // Constructor Overloaded


        Polynomial operator +  (const Polynomial &);      // Overloaded +  operator
        Polynomial operator -  (const Polynomial &);      // Overloaded -  operator
        Polynomial operator *  (const Polynomial &);      // Overloaded *  operator
        Polynomial operator =  (const Polynomial &);      // Overloaded =  operator

        bool operator == (Polynomial &);                  // Overloaded == operator
        double operator () (double x);                    // Overloaded () operator
        
        
        friend ostream &operator  << (ostream &, const Polynomial &);         // Overloaded << operator 
        friend istream &operator  >> (istream &, Polynomial &);               // Overloaded >> operator 
};


#endif /* __POLYNOMAIL_H__ */