/* -----------------------------------------------------------------------------
FILE NAME:         Pointers14.cpp
DESCRIPTION:       This program stores the address of a variable in a pointer. 
USAGE:             ./Pointers14
COMPILER:          GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author               Date            Version             Description
---------------      ----------      ------------        ------------
Luiz Diego Garcia    02/07/19        0.0.1               Created File
Luiz Diego Garcia    02/07/19        0.0.2               Added My_Name[] 
Luiz Diego Garcia    02/12/19        0.0.3               loop stepping trrough index, char, address and dec value 
Luiz Diego Garcia    02/12/19        0.0.4               loop with pointers added 
Luiz Diego Garcia    02/12/19        0.0.5               Created newFile and opened "Pointers.txt" 
Luiz Diego Garcia    02/12/19        0.0.6               Added chmod read only after file is populated with data
Luiz Diego Garcia    02/12/19        0.0.7               Transfered 'cout' lines to ostream function 
Luiz Diego Garcia    02/12/19        0.0.8               Created fail-safe warning for edditing file 
Luiz Diego Garcia    02/12/19        0.0.9               Fixed forloop pointer no showing address 
Luiz Diego Garcia    02/12/19        0.0.10              Changed (long long) to (int) in array notation  
Luiz Diego Garcia    02/12/19        0.0.11              Fixed indentation in loop 
Luiz Diego Garcia    02/14/19        1.0.0               Release v1                
----------------------------------------------------------------------------- */
//Libraries
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cctype>
#include<cstdlib>
#include<fstream>
#include<stdlib.h>

using namespace std;

//Prototypes
void Output_File(ostream &out);

// Global constant
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";	
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       main function
RETURNS:           0
------------------------------------------------------------------------------- */
int main()
{
    ofstream newFile;
    newFile.open("Pointers.txt",std::ios::out);

    Output_File(cout);
    Output_File(newFile);
    cout << endl;

    newFile.close();
    system("chmod 400 Pointers.txt");

    if(newFile.fail())
    {
        cout << "####### File cannot be overwritten #######" << endl;   
        cout << endl << endl;
    }
    else
    {
        cout << "@@@@@@@ File created with success  @@@@@@@" << endl;
        cout << endl << endl;
    }    

	//Programmer signature and time stamp.
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl << endl;

	return 0;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Output_File()
DESCRIPTION:       Write cout into a .txt file
RETURNS:           void
------------------------------------------------------------------------------- */
void Output_File(ostream &out)
{
	int x = 25;	            	            //int variable
	char My_Name[] = "Luiz Diego Garcia";
    char *charPtr = nullptr;
	int *ptr = nullptr;	                    //Pointer variable, can point to an int
    
    charPtr = My_Name;
	ptr = &x;		                        //Store the address of x in ptr

	out << endl << endl;
	out << "The hex address of x is: " << ptr << endl;
	out << "The dec address of x is: " << (long long) ptr << endl;
	out << "The size of ptr is " << sizeof(ptr) << " bytes\n";
	out << endl;

	out << "The  size of x is " << sizeof(x) << " bytes\n";
    out << "The value in x is " << x << endl;
    out << endl;

    out << "My name is " << My_Name << endl;
    out << "The   size of My_Name is: " << sizeof(charPtr) << " bytes" << endl;
    out << "The lenght of My_Name is: " << strlen(My_Name) << " bytes" << endl;
    out << endl;

    for(int i = 0; i <= strlen(My_Name); i++)
        {
            out << "Char "<< setw(2) << i << " is " << My_Name[i];
            if(*(charPtr + i) == '\0')      //Fix alignment issue due to '\0'
            {
                out << "  at address: "<< (long long) &My_Name[i];
            }   
            else
            {
                out << " at address: "<< (long long) &My_Name[i];
            }
            out << " with a value of: " << (int) My_Name[i] << endl;
        }
    out << endl << endl;

    for(int i = 0; i <= strlen(charPtr); i++)
        {
            out << "Char " << setw(2) << i << " is " << *(charPtr + i);
            if(*(charPtr + i) == '\0')      //Fix alignment issue due to '\0'
            {
                out << "  at address: "<< (long long) (charPtr + i);
            }   
            else
            {
                out << " at address: "<< (long long) (charPtr + i);
            }
            out << " with a value of: " << (int)*(charPtr + i) << endl;
        }
    out << endl;

}
