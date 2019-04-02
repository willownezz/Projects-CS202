//Polynomial.h
//Header file and Specification for Polynomial.cpp
//Derived from beginning of "poly_class_v1.pp"
//Modified to work with "poly_class_v2.pp"

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream>

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

class Polynomial
{
    private:
        int degree;         // Degree of the polynomial
        int coef[9];        // Array of coefficients

    public:
        Polynomial();       // Constructor
        void get_poly();
        void display_poly();
        void Add_2_Polynomials(Polynomial, Polynomial);

        Polynomial operator + (const Polynomial &);      // Overloaded + operator
};

#endif /* __POLYNOMAIL_H__ */
