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
Luiz Diego Garcia           2019-04-12         1.16         
Luiz Diego Garcia           2019-04-12         1.17         
Luiz Diego Garcia           2019-04-12         1.18         
Luiz Diego Garcia           2019-04-12         1.19         
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
FUNCTION:           CheckFile()
DESCRIPTION:        Check if files are open
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void CheckFile(string &, fstream &file)
{

	// // File test -- CHANGE TO file.is_open()
	// if(!file)
	// {
	// 	cout << " ERROR: Cannot open the file." << endl << endl;
	// }
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           FileSize()
DESCRIPTION:        identify file size and output to screen
RETURNS:            void
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
		square = pow(n,2);

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
FUNCTION:           EncodeDecode()
DESCRIPTION:        Checks if encode or decode is been used
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