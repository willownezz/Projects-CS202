/*--------------------------------------------------------------------------------------------------
FILE NAME:          poly_class.cpp
DESCRIPTION:        main(); -- Driver function
COMPILER:           GNU g++ compiler on Linux
USAGE:              ./poly_class
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-10         1.0           Created File
Luiz Diego Garcia           2019-04-13         1.1           Addded signature function
Luiz Diego Garcia           2019-04-13         1.2           Added polynomial subtraction
Luiz Diego Garcia           2019-04-13         1.3           Added polynomial multiplication
Luiz Diego Garcia           2019-04-13         1.4           Removed display();
Luiz Diego Garcia           2019-04-14         1.5           Added ostream overloaded
Luiz Diego Garcia           2019-04-14         1.6           Called copy constructor
Luiz Diego Garcia           2019-04-15         1.7           Called Equality overloaded
Luiz Diego Garcia           2019-04-15         1.8           Changed adi, sub, mult for overload
Luiz Diego Garcia           2019-04-16         1.9           Changed constructor overload
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Polynomial.h"

//////////////////////////////////////
// Constant Variables
//////////////////////////////////////
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";


/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        start of the program
RETURNS:            0
--------------------------------------------------------------------------------------------------*/
int main ()
{
    Polynomial poly[4];

    //Overload Constructor test
    int degree = 5;
    int coefficients[10] = {1,4,4,5,7,8};
    int i;

    for (int n=0; n < 2; n++)
    {
        cin >> poly[n];
        cout << endl;
        cout << "\n             Polynomial   # " << n+1 << " is: ";
        cout << poly[n];
    }
    
    cout << endl;
	cout << "\n Adding      2 polynomials: ";
    poly[2] = poly[0] + poly[1];
    cout << poly[2];

    cout << "\n Subtracting 2 polynomials: ";
    poly[2] = poly[0] - poly[1];
    cout << poly[2];

    cout << "\n Multiplying 2 polynomials: ";
    poly[2] = poly[0] * poly[1];
    cout << poly[2];


    // Copy Constructor
    cout << endl;
    cout << " Copy Polynomial    #2 " << " is: ";
    Polynomial cpTest = poly[2];
    cout << cpTest;
    cout << endl;


    // Equality overload
    bool saveBool = poly[1] == poly[2];
    cout << " Polynomial #1 == Polynomial #2 : ";
    if(saveBool == 1)
        cout << " True" << endl;
    else
        cout << " False" << endl;

    saveBool = poly[2] == cpTest;
    cout << " Polynomial #2 == Copy       #2 : ";
    if(saveBool == 1)
        cout << " True" << endl;
    else
        cout << " False" << endl;;

    cout << endl;
    cout << " Testing Overloaded Constructor:" << endl;
    // Polynomial polyOver = Polynomial(degree, coefficients);
    Polynomial polyOver = Polynomial(poly[0]);
    cout << " " << polyOver <<endl;

    cin >> (i);
    cout << " f(" << "x" << ") = " << poly[1] << endl; 
    cout << " f(" << i << ") = " << poly[1] << endl; 


	EndOfProgram(cout);
    return 0;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           EndOfProgram()
DESCRIPTION:        Signature and date stamp
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void EndOfProgram(ostream &out)
{
	out << endl << endl;
	out << " Programmed by: " << PROGRAMMER_NAME << " -- ";
	out << __DATE__ << "  " __TIME__ << endl;
	out << endl;

	return;
}
