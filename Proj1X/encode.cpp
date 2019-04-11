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
	string fileName = "null";  
	string OutFileName = "output.bin";      //Output binary compressed file.
	int numBytes = 0;                       //Saves the size of file.
	const int SIZE = 66;					//n5=45 rn16=66
	char data[SIZE];
	
	//Removes unused warning
	char *prog = argv[0];
	(void)argc;

	string checkArg[1];
	checkArg[0] = "./decode";
	// cout << checkArg[0] << " 1 " << endl;
	// cout << checkArg[1] << " 2 " << endl;
	
	// cout << argv[1] << " 3 " << endl;
	// cout << argv[0] << " 4 " << endl;

	//Read file - ./encode n3.dat ------ line arguments
	if (argc == 2)
	{
		if(argv[0] == checkArg[0])
		{
			cout << endl;
			cout << " Heyyyy BOIIIIIIII" << endl;
			cout << endl;
		}
		else
		{
			fileName = argv[1];
			cout << "File name: " << fileName << endl;
	// 	}
		
	// }

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
	file.seekg(0L, ios::end); // Goes to end of file
	numBytes = file.tellg();
	cout << "File size: " << numBytes << " bytes." << endl;
	cout << endl;
	file.seekg(0L, ios::beg);	//Goes to begging of file

	
		//Reading file
		char temp;
		int counter = 0;
		int size = 0;

		while(file.get(temp))
		{
			// cout << "Writting..." << endl;
			if(isspace((int)temp))
				continue;
				data[counter++] = temp;

				OutFile.write((char*) &temp, sizeof(char));

			++size;
		}
		cout << size <<endl;

		
		for(int i = 0; i < size; i++)
		{
			cout << data[i];
		}
		
		


	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	cout << endl << endl;

	//Copies number to find magic square
	char aStr[3] = {data[2], 0};
	int n = atoi(aStr);
	int square = n * n;

	//Shows number in file and finds magic square value
	cout << "n= " << n << "   num= " << square << endl;
	

	//output compressed file
	cout << "File name: " << OutFileName << endl;

	//Calculates size of file
	OutFile.seekg(0L, ios::end);
	numBytes = OutFile.tellg();
	cout << "File size: " << numBytes << " bytes." << endl;
	OutFile.seekg(0L, ios::beg);
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

	
		}
		
	}
	cout << "File name: " << OutFileName << endl;
	cout << "File size: " << numBytes << " bytes." << endl;


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
