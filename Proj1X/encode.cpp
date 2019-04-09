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
Luiz Diego Garcia           2019-04-07          1.0.1        Created header file
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
int main(int argc, char *argv[])
{
	
	cout << endl;
	string fileName = "null";               //file chosen by the user to be opened and compressed
	string OutFileName = "output.bin";      //Output binary compressed file.
	int numBytes = 0;                       //Saves the size of file.
	const int SIZE = 10;

	//Removes unused warning
	char *prog = argv[0];
	(void)argc;


	//Read file - ./encode n3.dat ------ line arguments
	if (argc == 2)
	{
		fileName = argv[1];
		cout << "File name: " << fileName << endl;
	}

	fstream file(fileName, ios::in);
	
	if(file.fail())
	{
		cout << "ERROR: Cannot open the file." << endl << endl;
	}

	fstream OutFile(OutFileName, ios::out | ios::binary);
	
	if(OutFile.fail())
	{
		cout << "ERROR: Cannot open the file." << endl << endl;
	}

	//Calculates size of file
	file.seekg(0L, ios::end);
	numBytes = file.tellg();
	cout << "File size: " << numBytes << " bytes." << endl;
	cout << endl;

	//Shows number of col and square size
	// n= 3     num= 9
 
	string name1;
	string name2;
	string name3;
	if(file.is_open())
	{
		while(file >> name1 >> name2 >> name3)
		{
			
		}








	//output compressed file
	cout << "File name: " << OutFileName << endl;

	//Calculates size of file
	OutFile.seekg(0L, ios::end);
	numBytes = OutFile.tellg();
	cout << "File size: " << numBytes << " bytes." << endl;
	cout << endl;

	//close file
	OutFile.close();
	file.close();

	

	
	
	

	//read file into buffer
	//read "n= 3" separately to get square size

	

	//compress file into .bin ----- output.bin (compress by 3 times)




	//Read the output.bin display as text ------ identical as the original (decode)
	//create DECODE function ------- ./decode output.bin
	//symbolic links




	//compress file even more {EXTRA}

	
	



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
	out << endl << endl;
	out << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	out << __DATE__ << "  " __TIME__ << endl;
	out << endl;

	return;
}
