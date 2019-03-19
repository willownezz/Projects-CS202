/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v4.cpp
DESCRIPTION:       This program stores the address of a variable in a pointer.
USAGE:             ./command_line_v4
COMPILER:          GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author               Date            Version             Description
---------------      ----------      ------------        ------------
Luiz Diego Garcia    02/16/19        0.0.1               Created File
Luiz Diego Garcia    02/20/19        0.0.2               Added headers 
Luiz Diego Garcia    02/20/19        0.0.3               fixed typo in loop 
Luiz Diego Garcia    02/20/19        1.0.0               release
----------------------------------------------------------------------------- */

// Command_line_v4.cpp
// Test program for parsing a command line

//Libraries
#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

//Prototypes
void check_arg(char []);

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
    cout << endl;
    for(int i = 0; i < argc; ++i)
    {
        cout << "Argument " << i << ": " << left << setw(16) << argv[i];
        if (i)   check_arg(argv[i]);
        else     cout << endl;
    }
    cout << endl;

    return 0;
}
/* -----------------------------------------------------------------------------
FUNCTION:          check_arg()
DESCRIPTION:       Checks arg
RETURNS:           void
----------------------------------------------------------------------------- */
void check_arg(char arg[])
{
    char buf[100];
    const char DASH = '-';
    char valid_options[] = "?hifap";
    char *p = valid_options;

    bool first_char = arg[0] == DASH;       //Test 1st arg's char
    bool second_char = false;               //Test parameter's 2nd char

    for(; *p != 0; ++p)
    {
        second_char = arg[1] == *p;
        if (second_char == true) break;
    }

    if (!first_char || !second_char)
        cout << "Invalid argument" << endl;

    else
    {
        cout << "Option: " << *p;

        if(arg[2] != 0)                     // Look for a string
        {
            strcpy(buf, arg+2);             // Save string to buffer
            cout << " Value: " << buf;
        }
        cout << endl;
    }
}
