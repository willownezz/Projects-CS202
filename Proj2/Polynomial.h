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

    public:
        Polynomial();       // Constructor
        ~Polynomial();      // Destructor


        void get_poly();
        void display_poly();
        void Add_2_Polynomials(Polynomial, Polynomial);
		void Sub_2_Polynomials(Polynomial, Polynomial);
		void Mul_2_Polynomials(Polynomial, Polynomial);

        Polynomial operator + (const Polynomial &);      // Overloaded +  operator
        Polynomial operator - (const Polynomial &);      // Overloaded -  operator
        Polynomial operator * (const Polynomial &);      // Overloaded *  operator
        Polynomial operator = (const Polynomial &);      // Overloaded *  operator
        ostream& operator  << (const ostream &);         // Overloaded << operator 
};


#endif /* __POLYNOMAIL_H__ */