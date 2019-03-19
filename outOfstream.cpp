// test_fun
// OSTREAM as a variable to send in two places


//Libraries
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//Prototypes

// void Test_Func(ostream &out);
void Writ_Out(ostream &out);

//Global constant
const string PROGRAMMER_NAME = "Luiz Diego Garcia";

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       function that starts the program (main function)
RETURNS:           0
----------------------------------------------------------------------------- */
int main()
{
	
	ofstream outputFile;
	outputFile.open("testing.txt");
	
	
	Writ_Out(cout);
	Writ_Out(outputFile);

	
	cout << endl;

	cout << "                                                                        " << endl;
	cout << "      ,ad8888ba,    ad88888ba     88   ad888888b,  8888888888           " << endl;
	cout << "     d8\"'    `\"8b  d8\"     \"8b  ,d88  d8\"     \"88  88             " << endl;
	cout << "    d8'            Y8,        888888          a8P  88  ____             " << endl;
	cout << "    88             `Y8aaaaa,      88       aad8\"   88a8PPPP8b,         " << endl;
	cout << "    88               `\"\"\"\"\"8b,    88       \"\"Y8,   PP\"     `8b  " << endl;
	cout << "    Y8,                    `8b    88          \"8b           d8         " << endl;
	cout << "     Y8a.    .a8P  Y8a     a8P    88  Y8,     a88  Y8a     a8P          " << endl;
	cout << "      `\"Y8888Y\"'    \"Y88888P\"     88   \"Y888888P\'   \"Y88888P\"   " << endl;
	cout << "	                                                                     " << endl;
	cout << "                                 |||~ Terminating Program ~|||" 		   << endl;
	cout << "                                                       Goodbye"   << endl << endl;

	cout << right << setw(20) << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
	cin.get();

	return 0;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Writ_Out()
DESCRIPTION:       ...
RETURNS:           ostream
----------------------------------------------------------------------------- */
void Writ_Out(ostream &out)
{

	out << "This is here hey" << endl;
	out << "This is here hey2" << endl;
	out << "This is here hey3" << endl;
	out << "This is here hey4" << endl;
	out << "This is here hey5" << endl;
	out << "This is here hey9999" << endl;
}
