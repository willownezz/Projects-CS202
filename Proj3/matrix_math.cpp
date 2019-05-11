/*--------------------------------------------------------------------------------------------------
FILE NAME:          matrix_math.cpp
DESCRIPTION:        main(); (Driver file)
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
Luiz Diego Garcia           2019-05-01         1.6           created typdef
Luiz Diego Garcia           2019-05-03         1.7           changed Matrix from INT to double
Luiz Diego Garcia           2019-05-05         1.8           added arg -inp to read files
Luiz Diego Garcia           2019-05-07         1.9           added arg -out to save data
Luiz Diego Garcia           2019-05-08         1.10          Created ifstream / ofstream
Luiz Diego Garcia           2019-05-08         1.11          Added -h help file (argv)         
Luiz Diego Garcia           2019-05-08         1.12          Changed how argv is handle
Luiz Diego Garcia           2019-05-08         1.13          else if for -sub  access
Luiz Diego Garcia           2019-05-08         1.14          else if for -add  access
Luiz Diego Garcia           2019-05-08         1.15          else if for -mul  access    
Luiz Diego Garcia           2019-05-08         1.16          else if for -sdiv access
Luiz Diego Garcia           2019-05-09         1.17          Fixed -out where works with -inp now
Luiz Diego Garcia           2019-05-09         1.18          else if for -eq access 
Luiz Diego Garcia           2019-05-09         1.19          Created read file function
Luiz Diego Garcia           2019-05-09         1.20          else if for -smul access
Luiz Diego Garcia           2019-05-09         1.21          added args to help -h
Luiz Diego Garcia           2019-05-09         1.22          moved help file prototype
Luiz Diego Garcia           2019-05-09         1.23          moved end of program prototype
Luiz Diego Garcia           2019-05-09         1.24          remove unused variable byte
Luiz Diego Garcia           2019-05-11         1.25          Added couts defining each step
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Matrix.cpp"


//////////////////////////////////////
// Prototypes
//////////////////////////////////////
void EndOfProgram(ostream &out);
void HelpFile();
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

			cout << " Displaying matrix test: " << endl;
			cout << " Matrix 1: \n" << test1;
			mat1 = test1;
		}

		else if(cmd == "-add") // Add matrix
		{
			ReadFile(argv[i+1], test1);
			ReadFile(argv[i+2], test2);

			cout << " Addition test......................... " << endl;
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

			cout << " Subtraction test......................... " << endl;
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
			
			cout << " Multiplication test......................... " << endl;
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
	
			cout << " Scalar Multiplication test.................. " << endl;
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

			cout << " Scalar Division test.................. " << endl;

			if(temp == 0)
			{
				cout << " Can't divide by 0" << endl << endl;
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

			cout << " Comparison matrices test.................. " << endl;


			if(!hold)
				cout<<" Matrices are NOT equal" << endl;
			if(hold)
				cout<<" Matrices are equal" << endl;
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
			cout << endl << endl;
			cout << " Saving matrix to file " << file1 << endl;
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
	cout << " _____________________________________________________________________________________________" << 	endl;
	cout << "|--------------------------------------------------------------------------------------------|"<< 	endl;
	cout << "|                                           HELP FILE                                        |"<< 	endl;
	cout << "|--------------------------------------------------------------------------------------------|"<< 	endl;
	cout << "|                                                                                            |"<< 	endl;
	cout << "|  ./matrix_math -inp   A                            Open and saves to a new file (A.mtx)    |"<< 	endl;
	cout << "|  ./matrix_math cmds... -out ZZ                     Saves matrix to a file (e.g., ZZ.mtx)   |"<< 	endl;
	cout << "|                                                                                            |"<< 	endl;
	cout << "|  ./matrix_math -h                                  Open help files screen                  |"<< 	endl;
	cout << "|                                                                                            |"<< 	endl;
	cout << "|  ./matrix_math -add  A B                           Adds matrix A to B        (A+B)         |"<< 	endl;
	cout << "|  ./matrix_math -sub  A B                           Subtracts matrix A from B (A-B)         |"<< 	endl;
	cout << "|  ./matrix_math -mul  A B                           Multiplys matrix A and B  (A*B)         |"<< 	endl;
	cout << "|  ./matrix_math -smul A n                           Multiply matrix A by n    (A*n)         |"<< 	endl;
	cout << "|  ./matrix_math -sdiv A n                           Divide matrix A by n      (A/n)         |"<< 	endl;
	cout << "|  ./matrix_math -eq   A B                           Compare matrix A to B     (A==n)        |"<< 	endl;
	cout << "|____________________________________________________________________________________________|"<<  endl;
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
