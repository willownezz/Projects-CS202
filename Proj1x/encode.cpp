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
Luiz Diego Garcia           2019-04-07         1.1           Created function that reads file
Luiz Diego Garcia           2019-04-07         1.2           File is now saved to an array
Luiz Diego Garcia           2019-04-07         1.3           Fork where user can encode or decode
Luiz Diego Garcia           2019-04-08         1.4           Check is file is open
Luiz Diego Garcia           2019-04-08         1.5           Check file size and output
Luiz Diego Garcia           2019-04-08         1.6           grabs file that user input
Luiz Diego Garcia           2019-04-08         1.7           read file - first line into .bin
Luiz Diego Garcia           2019-04-09         1.8           modularizing main function
Luiz Diego Garcia           2019-04-10         1.9           fixing references in all functions
Luiz Diego Garcia           2019-04-10         1.10          fix bug in square variable
Luiz Diego Garcia           2019-04-10         1.11          fix where file goes to END and stays
Luiz Diego Garcia           2019-04-10         1.12          changed char array to byte array
Luiz Diego Garcia           2019-04-11         1.13          file that decodes and reads back
Luiz Diego Garcia           2019-04-11         1.14          fix bug where file only read one line
Luiz Diego Garcia           2019-04-11         1.15          fix file only reading the same number
Luiz Diego Garcia           2019-04-12         1.16          cleaning up unused code
Luiz Diego Garcia           2019-04-12         1.17          removed unused function checkfile
Luiz Diego Garcia           2019-04-12         1.18          changed size in cons int
Luiz Diego Garcia           2019-04-12         1.19          fix when file is not present in folder
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "encode.h"      // Libraries, Prototypes & Structs

using namespace std;

typedef unsigned char byte;						//Creates a new data type with unsigned char size (1 byte)

//////////////////////////////////////
// Constant Variables
//////////////////////////////////////
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";
const int SIZE = 99;

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        start of the program
RETURNS:            0
--------------------------------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	string fileName = "null";  				//Initialize fileName
	
	//Check for ./decode
	string checkArg[1];
	checkArg[0] = "./decode";

	//line arguments 
	if (argc == 2)
	{
		// If ./decode or ./encode
		if(argv[0] == checkArg[0])
		{
			Decode(argv[1]);
		}
		else
		{
			fileName = argv[1];
			OpenFiles(fileName);
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
	out << " Programmed by: " << PROGRAMMER_NAME << " -- ";
	out << __DATE__ << "  " __TIME__ << endl;
	out << endl;

	return;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           OpenFiles()
DESCRIPTION:        Open files that user choose/output file
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void OpenFiles(string &fileName)
{
	//Opens file that user will pick
	fstream file(fileName, ios::in);
	cout << endl;
	cout << " File name: " << fileName << endl;
	if(!file)
	{
		cout << " ERROR: Cannot open the file." << endl << endl;
	}
	else
	{
		// CheckFile(fileName, file);
		ReadIntoBinary(file);
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           FileSize()
DESCRIPTION:        identify file size and output to screen
RETURNS:            int
--------------------------------------------------------------------------------------------------*/
int FileSize(fstream &file)
{
	int numBytes = 0;                       //Saves the size of file.

	//Calculates size of file
	file.seekg(0L, ios::end); // Goes to end of file
	numBytes = file.tellg();
	cout << " File size: " << numBytes << " bytes" << endl;
	cout << endl;
	file.seekg(0L, ios::beg);	//Goes to begging of file

	return numBytes;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           ReadIntoBinary()
DESCRIPTION:        Reads file into binary after identifying magic square size
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void ReadIntoBinary(fstream &file)
{
	//Reading file  -- CHANGE to INT so it can save as numbers instead of chars
	//Read first line "n=3" but only save square

	string OutFileName = "output.bin";      //Output binary compressed file.
	int n, square, tempNum;

	//Creates a output binary file
	fstream OutFile(OutFileName, ios::out | ios::binary);
	

	// File test -- CHANGE TO file.is_open()
	if(!OutFile)
	{
		cout << " ERROR: Cannot open the file." << endl << endl;
	}
	else
	{
		FileSize(file);

		byte data[SIZE];

		char dataTemp[4];
		
		file >> dataTemp;
		file >> n;
		square = n * n;


		for(int i = 0; i < square; i++)
		{
			file >> tempNum;
			data[i] = tempNum;
		}

		OutFile.write((char*) &data, square);	

		//Shows number in file and finds magic square value
		cout << " n= " << n << "   num= " << square << endl << endl;

		//output compressed file
		cout << " File name: " << OutFileName << endl;
		
		//Checks binary file size
		FileSize(OutFile);

		//close files
		file.close();
		OutFile.close();
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Decode()
DESCRIPTION:        Decodes file
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void Decode(char *OutFileName)
{
	
	fstream OutFile;
	byte data[SIZE];
	// string OutFileName = "output.bin";
	OutFile.open(OutFileName, ios::in | ios::binary);

	cout << endl;
	cout << " File name: " << OutFileName << endl;
	if(!OutFile)
	cout << " ERROR: Cannot open the file." << endl << endl;
	else
	{
		int square = FileSize(OutFile);

		// Decode file
		OutFile.read(reinterpret_cast<char *>(&data), square);

		int k = 0;
		cout << " n= " << sqrt(square) << endl;

		for(int i = 0; i < sqrt(square); i++)
		{
			for(int j = 0; j < sqrt(square); j++)
			{
				cout << " " << static_cast<int>(data[k]) << " ";
				k++;
			}
			cout<< endl;
		}
		OutFile.close();
	}
}