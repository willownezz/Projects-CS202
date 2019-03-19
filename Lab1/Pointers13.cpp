/* -----------------------------------------------------------------------------
FILE NAME:         Pointers13.cpp
DESCRIPTION:       This program stores the address of a variable in a pointer. 
USAGE:             ./Prog9-2
COMPILER:          GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author               Date            Version             Description
---------------      ----------      ------------        ------------
Luiz Diego Garcia    02/07/19        0.0.1               Created File
Luiz Diego Garcia    02/07/19        0.0.2               Added My_Name[] 
Luiz Diego Garcia    02/12/19        0.0.3               loop stepping trrough index, char, address and dec value 
Luiz Diego Garcia    02/13/19        0.0.4               loop with pointers added 
----------------------------------------------------------------------------- */
//Libraries
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<cctype>

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
	char My_Name[] = "Luiz Diego Garcia";
	char *charPtr = nullptr;

	ptr = &x;		//Store the address of x in ptr
    charPtr = My_Name;

	cout << endl << endl;
	cout << "The hex address of x is: " << ptr << endl;
	cout << "The dec address of x is: " << (long long) ptr << endl;
	cout << "The size of ptr is " << sizeof(ptr) << " bytes\n";
	cout << endl;

	cout << "The  size of x is " << sizeof(x) << " bytes\n";
    cout << "The value in x is " << x << endl;
    cout << endl;

    cout << "My name is " << My_Name << endl;
    cout << "The   size of My_Name is: " << sizeof(charPtr) << " bytes" << endl;
    cout << "The lenght of My_Name is: " << strlen(My_Name) << " bytes" << endl;
    cout << endl;

    for(int i = 0; i <= strlen(My_Name); i++)
        {
            cout << "Char " << i << " is " << My_Name[i] << " at address: "<< (long long) &My_Name[i];
            cout << " with a value of: " << (long long) My_Name[i] << endl;
        }
    cout << endl << endl;

    for(int i = 0; i <= strlen(My_Name); i++)
        {
            cout << "Char " << i << " is " << charPtr[i] << " at address: "<< (long long) &charPtr[i];
            cout << " with a value of: " << (long long) charPtr[i] << endl;
        }

	//Programmer signature and time stamp.
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}
