/*--------------------------------------------------------------------------------------------------
FILE NAME:          encode.cpp
DESCRIPTION:        Financial Portifolio Program
USAGE:              ./encode fileName
USAGE:              ./decode fileName
COMPILER:           GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-06          1.0.0        Created File
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "encode.h"      // Libraries, Prototypes & Structs

using namespace std;

//////////////////////////////////////
// Constant Variables
//////////////////////////////////////
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        start of the program
RETURNS:            0
--------------------------------------------------------------------------------------------------*/
int main()
{
    EndOfProgram(cout);
    return 0;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           EndOfProgram()
DESCRIPTION:        Signature and date stamp
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void EndOfProgram(ostream &out)
{
    out << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    out << __DATE__ << "  " __TIME__ << endl;
    out << endl;

    return;
}