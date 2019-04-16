/*--------------------------------------------------------------------------------------------------
FILE NAME:          poly_class.cpp
DESCRIPTION:        main(); -- Driver function
COMPILER:           GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-10         1.0           Created File
Luiz Diego Garcia           2019-04-13         1.1           Addded signature function
Luiz Diego Garcia           2019-04-13         1.2           Added polynomial subtraction
Luiz Diego Garcia           2019-04-13         1.3           Added polynomial multiplication
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
    Polynomial poly[3];

    for (int n=0; n < 2; n++)
    {
        poly[n].get_poly();
        cout << endl;
        cout << "\n             Polynomial   # " << n+1 << " is: ";
        poly[n].display_poly();
    }

    poly[2] = poly[0] + poly[1];
    poly[2].display_poly();

    poly[2] = poly[0] - poly[1];
    poly[2].display_poly();

    poly[2] = poly[0] * poly[1];
    poly[2].display_poly();

    cout << endl;
    cout << " << Operator overload: ";
    // poly[0] = poly[1];
    // cout << poly[0] << endl;
    // cout << poly[1] << endl;

    cout << endl;
    cout << " >> Operator overload: ";

    // Copy Constructor
    cout << endl;
    cout << " Copy Constructor: ";
    Polynomial cpTest = poly[1];
    cpTest.display_poly();

    // Assignement operator overload
    cout << endl;
    cout << " Assignement operator overloaded: ";
    cpTest = poly[0];
    cpTest.display_poly();

    cout << endl;
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