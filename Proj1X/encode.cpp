/*--------------------------------------------------------------------------------------------------
FILE NAME:          encode.cpp
DESCRIPTION:        Financial Portifolio Program
USAGE:              ./encode "fileName"
USAGE:              ./decode "fileName"
COMPILER:           GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-06         1.0           Created File
Luiz Diego Garcia           2019-04-07         1.1           
Luiz Diego Garcia           2019-04-07         1.2           
Luiz Diego Garcia           2019-04-07         1.3           
Luiz Diego Garcia           2019-04-08         1.4           
Luiz Diego Garcia           2019-04-08         1.5           
Luiz Diego Garcia           2019-04-08         1.6           
Luiz Diego Garcia           2019-04-08         1.7           
Luiz Diego Garcia           2019-04-09         1.8           
Luiz Diego Garcia           2019-04-10         1.9           
Luiz Diego Garcia           2019-04-10         1.10          
Luiz Diego Garcia           2019-04-10         1.11          
Luiz Diego Garcia           2019-04-10         1.12           
Luiz Diego Garcia           2019-04-11         1.13           
Luiz Diego Garcia           2019-04-11         1.14          
Luiz Diego Garcia           2019-04-11         1.15         
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "encode.h"      // Libraries, Prototypes & Structs

using namespace std;

//////////////////////////////////////
// Alias
//////////////////////////////////////
typedef unsigned char byte;

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
	string fileName = "null";  				//Initialize fileName
	string OutFileName = "output.bin";      //Output binary compressed file.

	const int SIZE = 99;					
    // byte data[SIZE];
	char data[SIZE];

	OpenFiles(cout, fileName, OutFileName);
	
	//Check for ./decode
	string checkArg[1];
	checkArg[0] = "./decode";
	
	//Read file - ./encode n3.dat ------ line arguments
	if (argc == 2)
	{
		// If ./decode goes to decode();
		if(argv[0] == checkArg[0])
		{
			cout << endl;
			cout << " INSIDE DECODE" << endl;
			cout << endl;
		}
		else
		{
			fileName = argv[1];
			cout << "File name: " << fileName << endl;
		}
		
	}
	

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
/*--------------------------------------------------------------------------------------------------
FUNCTION:           OpenFiles()
DESCRIPTION:        Open files that user choose/output file
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void OpenFiles(ostream &out, string &, string &)
{
	string fName;
	string oFile;

	//Opens file that user will pick
	fstream file(fName, ios::in);
	CheckFile(fName, file);

	//Creates a output binary file
	fstream OutFile(oFile, ios::out | ios::binary);
	CheckFile(oFile, OutFile);
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           CheckFile()
DESCRIPTION:        Check if files are open
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void CheckFile(string &, fstream &file)
{

	// File test -- CHANGE TO file.is_open()
	if(!file.is_open())
	{
		cout << "ERROR: Cannot open the file." << endl << endl;
	}
	else
	{
		cout << "Test File ok " << endl;
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           FileSize()
DESCRIPTION:        identify file size and output to screen
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void FileSize()
{
	int numBytes = 0;                       //Saves the size of file.

	//Calculates size of file
	file.seekg(0L, ios::end); // Goes to end of file
	numBytes = file.tellg();
	cout << "File size: " << numBytes << " bytes." << endl;
	cout << endl;
	file.seekg(0L, ios::beg);	//Goes to begging of file

	cout << "File name: " << OutFileName << endl;
	cout << "File size: " << numBytes << " bytes." << endl;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           ReadIntoBinary()
DESCRIPTION:        Reads file into binary after identifying magic square size
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void ReadIntoBinary()
{
	//Reading file  -- CHANGE to INT so it can save as numbers instead of chars
	//Read first line "n=3" but only save square

	// int temp;
	char temp;
	int counter = 0;
	int size = 0;

	while(file.get(temp))
	{
		if(isspace((int)temp))
		{
			continue;
		}

		data[counter++] = temp;

		OutFile.write((char*) &temp, sizeof(char));			//copy as binary into outputfile

		++size;
	}
	cout << size <<endl;

	
	//Test to print what is inside data
	for(int i = 0; i < size; i++)
	{
		cout << data[i];
	}

	cout << endl << endl;

	//Copies number to find magic square
	char aStr[3] = {data[2], 0};
	int n = atoi(aStr);
	int square = n * n;

	//Shows number in file and finds magic square value
	cout << "n= " << n << "   num= " << square << endl;
	

	//output compressed file
	cout << "File name: " << OutFileName << endl;


	//close files
	OutFile.close();
	file.close();
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           EncodeDecode()
DESCRIPTION:        Checks if encode or decode is been used
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void EncodeDecode()
{
	
}