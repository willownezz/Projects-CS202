/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v1.cpp
DESCRIPTION:       This program stores the address of a variable in a pointer.
USAGE:             ./command_line_v1
COMPILER:          GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author               Date            Version             Description
---------------      ----------      ------------        ------------
Luiz Diego Garcia    02/18/19        0.0.1               Created File
Luiz Diego Garcia    02/19/19        0.0.2               Added headers  
Luiz Diego Garcia    02/20/19        1.0.0               Release
----------------------------------------------------------------------------- */

// Command_line_v1.cpp
// Test program for reading command-line parameters

//Libraries
#include <iostream>

using namespace std;

//Function prototypes go here
void clear_screen();

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
    clear_screen();

    for(int i = 0; i < argc; ++i)
    {
        cout << "Command line parameter " << i;
        cout << " = " << argv[i] << endl;
    }

    cout << endl;

    return 0;         // 0 = Success
}
/* -----------------------------------------------------------------------------
FUNCTION:          clear_screen()
DESCRIPTION:       Function to clear the screen
RETURNS:           void
----------------------------------------------------------------------------- */
void clear_screen()
{
    for(int i = 0; i < 50; ++i)
      cout << endl;
}
