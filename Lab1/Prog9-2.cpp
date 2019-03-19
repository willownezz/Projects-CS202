/* -----------------------------------------------------------------------------
FILE NAME:         Prog9-2.cpp
DESCRIPTION:       This program stores the address of a variable in a pointer.
USAGE:             ./Prog9-2
COMPILER:          GNU g++ compiler on Linux
NOTES:             ...

MODIFICATION HISTORY:
Author               Date            Version             Description
---------------      ----------      ------------        ------------
Luiz Diego Garcia    02/07/19        0.0.1               Created File. 
----------------------------------------------------------------------------- */
//Libraries
#include<iostream>

using  namespace std;

// Global constant
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";	

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       main function
RETURNS:           0
------------------------------------------------------------------------------- */
int main()
{
	int x = 25;		//int variable
	int *ptr = nullptr;	//Pointer variable, can point to an int

	ptr = &x;		//Store the address of x in ptr

	cout << "The value in x is " << x << endl;
	cout << "The address of x is " << ptr << endl;

	//Programmer signature and time stamp.
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}
