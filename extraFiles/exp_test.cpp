/* -----------------------------------------------------------------------------

FILE:              exp_test.cpp

DESCRIPTION:       Tests the display of exponents using Unicode characters

COMPILER:          g++ under Linux

NOTES:             To display properly in PuTTY, you need to set
		   Change Settings > Translation:  UTF-8
		   Change Settings > Appearance > Font: Consolas or DejaVu Sans Mono

MODIFICATION HISTORY:

Author             Date           Version
---------------    ----------     --------------
Ed Corbett         2017-03-29     1.0  original
Ed Corbett         2018-03-27     1.1  corrected format and comments  
Ed Corbett         2019-03-27     1.2  Spring 2019 updates
----------------------------------------------------------------------------- */
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/* -----------------------------------------------------------------------------
FUNCTION:       main()
DESCRIPTION:    The program's entry point
RETURNS:        0
NOTES:          
----------------------------------------------------------------------------- */

int main()
{
    int i;
    const char* exp[10] = {		// Array of Unicode characters
		"\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074",
		"\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};

    cout << endl;

    for (i=0; i<10; i++) 
    {
	cout << " x";
	cout << exp[i];
    }
    cout << endl;
    cout << endl;
}
