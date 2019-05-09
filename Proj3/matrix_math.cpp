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

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Matrix.cpp"

typedef unsigned char byte;

//////////////////////////////////////
// Prototypes
//////////////////////////////////////
void ReadFile(char * fname, Matrix_ops<double> &);

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
	char file1[20];				//First matrix
	char file2[20];				//Second matrix
	ifstream infile;
	ofstream outfile;
	string cmd;

	//Checks if user user enough arguments
	cout << endl << endl;
	if(argc<2)
	{
		cout << " Not enough Arguments ? \n\n";
		return 0;
	}

	Matrix_ops<double> test1, test2;
	Matrix<double> mat1;
	
	for(int i = 1; i < argc; i++)
	{
		cmd = argv[i];

		// Calls help file
		if(cmd == "-h")
		{
			HelpFile();
			return 0;
		}

		if(cmd == "-inp") // Input File
		{
			ReadFile(argv[i+1], test1);

			cout << " Matrix 1: \n" << test1;
			mat1 = test1;
		}

		else if(cmd == "-add") // Add matrix
		{
			ReadFile(argv[i+1], test1);
			ReadFile(argv[i+2], test2);

			cout << " Matrix 1: " << test1 << endl;
			cout << "\n Matrix 2: " << test2 << endl;

			try
			{
				test1 + test2;
				cout << "\n New matrix "<< test1;
			}
			catch(const char* fail)
				{cout << fail;}
			
			mat1 = test1;
		}

		else if(cmd == "-sub")
		{
			ReadFile(argv[i+1], test1);
			ReadFile(argv[i+2], test2);

			cout << " Matrix 1: " << test1 << endl;
			cout << "\n Matrix 2: " << test2 << endl;

			try
			{
				test1 - test2;
				cout << "\n New matrix "<< test1;
			}
			catch(const char* fail)
				{cout << fail;}

				mat1 = test1;
		}
		else if(cmd == "-mul")
		{
			ReadFile(argv[i+1], test1);
			ReadFile(argv[i+2], test2);

			cout << " Matrix 1: " << test1 << endl;
			cout << "\n Matrix 2: " << test2 << endl;
			try
			{
				test1 * test2;
		 		cout << "\n New matrix "<< test1;
			}
			catch(const char* fail)
				{cout << fail;}

				mat1 = test1;
		}
		else if(cmd == "-smul")
		{
			ReadFile(argv[i+1], test1);

			double temp;
			temp = atof(argv[i+2]);
	
			cout << " Matrix : " << test1 << endl;
			test1 * temp;
			cout << "\n New matrix "  << test1;

			mat1 = test1;
		}
		else if(cmd == "-sdiv")
		{
			ReadFile(argv[i+1], test1);

			double temp;
			temp = atof(argv[i+2]);

			if(temp == 0)
			{
				cout << " Can't divide by 0" << endl;
				return 0;
			}

			cout << " Matrix : " << test1 << endl;
			test1 / temp;
			cout << "\n New matrix "  << test1;

			mat1 = test1;
		}
		else if(cmd == "-eq")
		{
			ReadFile(argv[i+1], test1);
			ReadFile(argv[i+2], test2);

			bool hold;
			hold = test1 == test2;

			if(!hold)
				cout<<" Matrices are NOT equal";
			if(hold)
				cout<<" Matrices are equal";
		}
		if(cmd == "-out")
		{
			strcpy(file1, argv[i+1]);
			strcat(file1, ".mtx");
			outfile.open(file1);

			if(!outfile )
			{
				cout << "\n Error opening file: " << file1 << "\n\n";
				return 0;
			} 
			outfile << mat1;
			outfile.close();
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
FUNCTION:           HelpFile()
DESCRIPTION:        Help file
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void HelpFile()
{
	cout << " ____________________________________________________________________________________" << 	endl;
	cout << "|------------------------------------------------------------------------------------|"<< 	endl;
	cout << "|                                    HELP FILE                                       |"<< 	endl;
	cout << "|------------------------------------------------------------------------------------|"<< 	endl;
	cout << "|                                                                                    |"<< 	endl;
	cout << "|  ./matrix_math -inp   A                           Open and saves to a new file     |"<< 	endl;
	cout << "|  ./matrix_math cmds... -out fileOutput                                             |"<< 	endl;
	cout << "|                                                                                    |"<< 	endl;
	cout << "|  ./matrix_math -h                                  Open help files                 |"<< 	endl;
	cout << "|                                                                                    |"<< 	endl;
	cout << "|  ./matrix_math -add  A B                                                           |"<< 	endl;
	cout << "|  ./matrix_math -sub  A B                                                           |"<< 	endl;
	cout << "|  ./matrix_math -mul  A B                                                           |"<< 	endl;
	cout << "|  ./matrix_math -smul A n                                                           |"<< 	endl;
	cout << "|  ./matrix_math -sdiv A n                                                           |"<< 	endl;
	cout << "|  ./matrix_math -eq   A B                                                           |"<< 	endl;
	cout << "|____________________________________________________________________________________|"<<  endl;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           ReadFile()
DESCRIPTION:        Read Files
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void ReadFile(char* fname, Matrix_ops<double> &test1)
{
	ifstream infile;
	char array[20];

	strcpy(array, fname);
	strcat(array, ".mtx");
	infile.open(array);

	if(!infile)	
	{
		cout << "\n Error opening file: " << array << "\n\n";
	}
	else 
	{
		infile >> test1;
		infile.close();
	}
}