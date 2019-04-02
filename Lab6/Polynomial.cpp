//Polynomial.cpp
//Implementation file for Polynomial Class
// Derived from tail end of "poly_class_v1.cpp"
// Modified to work with "poly_class_v2.cpp"

#include "Polynomial.h"

Polynomial::Polynomial()                            // Constructor
{                                                   // Initialize all values to 0
    degree = 0;

    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
}


void Polynomial::get_poly()
{
    cout << "\nDegree of polynomial: ";
    cin >> degree;

    cout << "\nEnter " << degree+1 << " coefficients: ";


    for (int i = degree; i >= 0; i--)
        cin >> coef[i];
}

void Polynomial::display_poly()
{
//    cout << "\n\t";         // Display polynomial

    for (int i = degree; i >= 0; i--)
        {
            if (i < degree)
            {
                if (coef[i] >= 0) cout << " +";
                else cout << " ";
            }
            cout << coef[i];

            if (i>1) cout << "x^" << i;
            if (i==1) cout << "x";
        }

        cout << endl;
        cout << endl;
}


// Passes & returns polynomial structures

void Polynomial::Add_2_Polynomials(Polynomial p0, Polynomial p1)
{
    cout << "\nAdding the 2 polynomials: \n\n";

    degree = MAX(p0.degree, p1.degree);

    for (int i = degree; i >= 0; i--)
        coef[i] = p0.coef[i] + p1.coef[i];
}
//--------------------------------------------------|
//         Overloaded binary + operator             |
//__________________________________________________|

Polynomial Polynomial::operator + (const Polynomial &p1)
{
        Polynomial p2;

        cout << "\nAdding 2 polynomials: ";

        p2.degree = MAX(degree, p1.degree);

        for (int i = p2.degree; i >= 0; i--)
                p2.coef[i] = coef[i] + p1.coef[i];

        return p2;      
}
