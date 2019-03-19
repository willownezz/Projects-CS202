/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v11.cpp
DESCRIPTION:       This program stores the address of a variable in a pointer.
USAGE:             ./command_line_v11
COMPILER:          GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author               Date            Version             Description
---------------      ----------      ------------        ------------
Luiz Diego Garcia    02/18/19        0.0.1               Created File
----------------------------------------------------------------------------- */

// Command_line_v11.cpp
// Test program for reading command-line parameters

//Libraries
#include<iostream>
#include<iomanip>

using namespace std;

// "main()" function --- the program's entry point
//      int argc,       // Number of parameters on the command line
//      char *argv[])   // An array of pointers to C-string

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       function that starts the program (main function)
RETURNS:           0
----------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
    char c;

    for(int i = 0; i < argc; ++i)
    {
      cout << "Command line parameter " << i;
      cout << " = " << left << setw(20) << argv[i];
      cout << " at address: " << (long) argv[i];
      cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << "argv = " << endl;

    for(int i = 0; i < 250; ++i)
    {
      c = *(*argv+i);
      if(c) cout << c;
      else cout << '0';
    }
    cout << endl;

    return 0;           // 0 = Success
}
