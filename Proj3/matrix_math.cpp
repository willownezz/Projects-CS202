/*--------------------------------------------------------------------------------------------------
FILE NAME:          matrix_math.cpp
DESCRIPTION:        main(); -- Driver function
COMPILER:           GNU g++ compiler on Linux
USAGE:              ./matrix_math -inp *file* -out outFile...
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-23         1.0           Created File
Luiz Diego Garcia           2019-04-23         1.1           Added EndOfProgram function
Luiz Diego Garcia           2019-04-23         1.2           include matrix.cpp
Luiz Diego Garcia           2019-04-23         1.3           Fixed open file check 
Luiz Diego Garcia           2019-04-23         1.4           Changed 'not enough args' from 3 to 2
Luiz Diego Garcia           2019-04-23         1.5           Created defaut constructor
Luiz Diego Garcia           2019-04-23         1.6           created typdef
Luiz Diego Garcia           2019-04-23         1.7           changed Matrix from INT to double
Luiz Diego Garcia           2019-04-23         1.8           added arg -inp to read files
Luiz Diego Garcia           2019-04-23         1.9           added arg -out to save data
Luiz Diego Garcia           2019-04-23         1.10          Created ifstream / ofstream
Luiz Diego Garcia           2019-04-23         1.11          Added -h help file (argv)         
--------------------------------------------------------------------------------------------------*/

// ... change input operator

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Matrix.cpp"

typedef unsigned char byte;

//////////////////////////////////////
// Constant Variables
//////////////////////////////////////
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        start of the program - Driver function
RETURNS:            0
--------------------------------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	byte k;
	int m,n;
	char let_x;
	char file1[20];
	ifstream infile;
	ofstream outfile;
	string cmd;

	//Checks if user user enough arguments
	if(argc<2)
	{
		cout << " Not enough Arguments ? \n\n";
		return 0;
	}
	
	cmd = *++argv;					//Saves arg into string 'cmd'
	
	// Calls help file
	if(cmd == "-h")
	{
		HelpFile();
		return 0;
	}

	if(cmd == "-inp")
	{
		strcpy(file1, *++argv);
		strcat(file1, ".mtx");
		infile.open(file1);

		if(!infile)	
		{
			cout << "\n Error opening file: " << file1 << "\n\n";
			return 0;
		}
	}
	
	infile >> m >> let_x >> n;

	// Matrix<int>  mat1(m, n);
	// Matrix<double>  mat1(m, n);		//Read numbers
	Matrix<byte>  mat1(m, n);		//Read chars

	infile >> mat1;

	
	infile.close();	

	if(argc > 4) cmd = *++argv;

	if(cmd == "-out")
	{
		strcpy(file1, *++argv);
		strcat(file1, ".mtx");
		outfile.open(file1);

		if(!outfile)
		{
			cout << "\nError opening file: " << file1 << "\n\n";
			return 0;
		} 
		outfile << mat1;
		outfile.close();
	}
	mat1.display();

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
FUNCTION:           HelpFile()
DESCRIPTION:        Help file
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void HelpFile()
{
	cout << " ____________________________________________________________________________________" << 	endl;
	cout << "| ./matrix_math -inp *file*                          Open file matrix & displays it  |"<< 	endl;
	cout << "| ./matrix_math -inp *file* -out *outFileName*       Open and saves to a new file    |"<< 	endl;
	cout << "|                                                                                    |"<< 	endl;
	cout << "| ./matrix_math -h                                   Open help files                 |"<< 	endl;
	cout << "|                                                                                    |"<< 	endl;
	cout << "|                                                                                    |"<< 	endl;
	cout << "|                                                                                    |"<< 	endl;
	cout << "|____________________________________________________________________________________|"<<  endl;
}