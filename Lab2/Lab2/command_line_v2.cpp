/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v2.cpp
DESCRIPTION:       This program stores the address of a variable in a pointer.
USAGE:             ./command_line_v2
COMPILER:          GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author               Date            Version             Description
---------------      ----------      ------------        ------------
Luiz Diego Garcia    02/18/19        0.0.1               Created File
Luiz Diego Garcia    02/19/19        0.0.2               Created headers 
Luiz Diego Garcia    02/20/19        1.0.0               Release 
----------------------------------------------------------------------------- */

// Command_line_v2.cpp
// This program demonstrates how to display command-line arguments
// Using argc and argv in a while loop

//Libraries
#include <iostream>

using namespace std;

//    "main() " function --- the program's entry point
//    int argc        // Number of parameters on the command line
//    char *argv[]    // An array of pointers to C-strings

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       function that starts the program (main function)
RETURNS:           0
----------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
    int i = 0;

    cout << endl;

    if(argc == 1) cout << "Arguments ?\n\n";

    cout << "argc = " << argc << endl;

    while(argc--)
    {
      cout << "argc = " << argc << "   ";
      cout << "Argument #" << i++ << "  is:  ";
      cout << *argv++ << endl;
    }
    cout << endl;

    return 0;         // 0 = Success
}
