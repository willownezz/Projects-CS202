/* -----------------------------------------------------------------------------
FILE NAME:         Pointers.cpp
DESCRIPTION:       This program stores the address of a variable in a pointer. 
USAGE:             ./Prog9-2
COMPILER:          GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author               Date            Version             Description
---------------      ----------      ------------        ------------
Luiz Diego Garcia    02/07/19        0.0.1               Created File. 
Luiz Diego Garcia    02/08/19        0.0.2               Added Hex and Dec values of variable 'x'
Luiz Diego Garcia    02/08/19        0.0.3               Added sizeof and created pointer  
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

	cout << endl << endl;
	cout << "The hex address of x is: " << ptr << endl;
	cout << "The dec address of x is: " << (long long) ptr << endl;
	cout << "The size of ptr is " << sizeof(ptr) << " bytes\n";

	cout << endl;

	cout << "The size of x is " << sizeof(x) << " bytes\n";
	cout << "The value in x is " << x << endl;
	cout << endl << endl;

	//Programmer signature and time stamp.
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}
