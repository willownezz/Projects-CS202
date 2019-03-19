/*-----------------------------------------------------------------------------------------
FILE NAME:          Proj1.cpp
DESCRIPTION:
USAGE:              ./Proj1
COMPILER:           GNU g++ compiler on Linux
NOTED:

MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ----------------------------
Luiz Diego Garcia           2019-02-21         0.0.1         Created File
Luiz Diego Garcia           2019-02-21         0.0.2         Added main() header
-----------------------------------------------------------------------------------------*/

//Libraries
#include <iostream>

using namespace std;

//Constant Variables
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";


/*-----------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        start of the program
RETURNS:            0
-----------------------------------------------------------------------------------------*/
int main()
{


    cout << endl;
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << "  " __TIME__ << endl;
    cout << endl;

    return 0;
}
