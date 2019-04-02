//poly_class_v2.cpp
//Test program for polynomials implemented as classes

//Version 1 ... poly_struct.cpp converted to a class implementation
//Version 2 ... poly_class broken into 3 files
//              This is the driver function
//Version 3 ... Replaces .Add_2_Polynomials() with overloaded + operator

#include "Polynomial.h"

// "main()" function --- the program's entry point

int main ()
{
    Polynomial poly[3];

    for (int n=0; n < 2; n++)
    {
        poly[n].get_poly();
        cout << "\nPolynomial   # " << n+1 << " is: ";
        poly[n].display_poly();
    }


    poly[2].Add_2_Polynomials(poly[0], poly[1]);
    poly[2] = poly[0] + poly[1];
    poly[2].display_poly();

    cout << endl;
    return 0;
}
