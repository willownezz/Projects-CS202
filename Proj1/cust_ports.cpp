/*--------------------------------------------------------------------------------------------------
FILE NAME:          cust_ports.cpp
DESCRIPTION:        Financial Portifolio Program
USAGE:              ./cust_ports
COMPILER:           GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-02-21         0.0.1         Created File
Luiz Diego Garcia           2019-02-21         0.0.2         Changed description / missing headers
Luiz Diego Garcia           2019-02-24         0.0.3         Added missing coments
Luiz Diego Garcia           2019-02-24         0.0.4         Created new function for new customers
Luiz Diego Garcia           2019-02-24         0.0.5         ofstream function to start cust. file
Luiz Diego Garcia           2019-02-24         0.0.6         Created strucs for customer ACCs
Luiz Diego Garcia           2019-02-09         0.0.7         Added include for .h file
Luiz Diego Garcia           2019-03-09         0.0.8         yanked prototypes/strucs to .h file
Luiz Diego Garcia           2019-03-11         0.0.9         operator overloading ostream &out
Luiz Diego Garcia           2019-03-12         0.0.10        getline to upload file into struct
Luiz Diego Garcia           2019-03-12         0.0.11        cleaned unused code
Luiz Diego Garcia           2019-03-13         0.0.12        fixed loop error
Luiz Diego Garcia           2019-03-13         0.0.13        Added MenuInteractive()
Luiz Diego Garcia           2019-03-14         0.0.14        Added InfoCustomer()
Luiz Diego Garcia           2019-03-14         0.0.15        Created a function to read n load file
Luiz Diego Garcia           2019-03-14         0.0.16        Changed customer to dynamic
Luiz Diego Garcia           2019-03-16         0.0.17        Created function for command line args
Luiz Diego Garcia           2019-03-16         0.0.18        Created -h help file
Luiz Diego Garcia           2019-03-16         0.0.19        Created Deposit function
Luiz Diego Garcia           2019-03-16         0.0.20        Created -info
Luiz Diego Garcia           2019-03-16         0.0.21                        
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "cust_ports.h"                          // Libraries, Prototypes & Structs

using namespace std;

//////////////////////////////////////
// Constant Variables
//////////////////////////////////////
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";
const int NUM_CUSTOMERS = 1;        //FIXME: create variable for num

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        start of the program
RETURNS:            0
--------------------------------------------------------------------------------------------------*/
int main(int argc, char *argv[]) //Command-line arguments
{
	//Removes unused warning
	char *prog = argv[0];
	(void)argc;

	fstream dataBaseFile;
	fstream outputFile;
	char choice;

	//Dynamic memory
	Customer *newCust = new Customer[99];

	//Variable storing name of input and output files
	char inFile[] = "testDB.dat"; //FIXME: make it changable by the user if not use "TestDB.dat"
	char outFile[] = "testout.dat";

	//Open files
	dataBaseFile.open(inFile, ios::in | ios::binary);    // Open database file
	outputFile.open(outFile, ios::out);                  // Saves data into a new .dat file

	cout << endl;

	ReadCustFile(newCust, dataBaseFile);
	// Jumps to menu if no extra arguments are added
	if (argc == 1)
			MenuInteractive(cout, choice, dataBaseFile, outputFile, newCust);
	if (argc == 2)
	{
		for(int i = 0; i < argc; ++i)
		{
			if (i)   
			check_arg(argv[i], cout, dataBaseFile, newCust);
			else
			{
				cout << endl;
			}
		}
	}
	// Close file
	CloseFile(dataBaseFile);
	CloseFile(outputFile);

	delete[] newCust;

	// Program signature and date stamp
	EndOfProgram(cout);

	cin.get();
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
/* -----------------------------------------------------------------------------
FUNCTION:          check_arg()
DESCRIPTION:       Checks arg for flags
RETURNS:           void
----------------------------------------------------------------------------- */
void check_arg(char arg[], ostream &out, fstream &dataBaseFile, Customer *newCust)
{
    char buf[100];
    const char DASH = '-';
    char valid_options[] = "fcorih";
    char *p = valid_options;

    bool first_char = arg[0] == DASH;       //Test 1st arg's char
    bool second_char = false;               //Test parameter's 2nd char

    for(; *p != 0; ++p)
    {
        second_char = arg[1] == *p;
        if (second_char == true) break;
    }

    if (!first_char || !second_char)
        cout << "Invalid argument" << endl;

    else
    {
        if(*p == 'h')
				{
					HelpFile();
				}
				else if(*p == 'i')
				{
					CustomerInfoDisp(cout, dataBaseFile, newCust);
				}
				else if(*p == 'f')
				{
					UserFileChoice(cout, dataBaseFile, newCust);
				}
        cout << endl;
    }
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           HelpFile()
DESCRIPTION:        Help file for command line
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void UserFileChoice(ostream &out, std::fstream &, Customer newCust[])
	{
		char cFile[10];
		
		out << " Enter the name of the file to load into the system." << endl;
		out << " Database file: ";
		cin >> cFile;
		out << endl;
		out << " ---------------------------------" << endl;
		out << " File chosen is: " << cFile << endl;
		out << " ---------------------------------" << endl;
		cin.clear();

	}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           HelpFile()
DESCRIPTION:        Help file for command line
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void HelpFile()
{
	cout << "#--------------------------------------------------------------------------------#" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#                            Welcome to the help file                            #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#--------------------------------------------------------------------------------#" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#   ./cust_ports -h" 	 	  	<< setw(63) << setfill(' ') << " Help File #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#   ./cust_ports -info" 		  << setw(60) << setfill(' ') 
								<< " Display portifolio information #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#   ./cust_ports -rpt"		 		<< setw(61) << setfill(' ') 
								<< " Writes report on the screen #" << endl;
	cout << "#    ----------------------------------------------                              #" << endl;
	cout << "#    Ex: cust_ports -f CustDB.dat -rpt Cust_Rpt.txt                              #" << endl;
	cout << "#    ----------------------------------------------                              #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#   ./cust_ports -f" 	 			<< setw(63) << setfill(' ') 	
								<< " Opens a file of customers #" << endl;
	cout << "#    --------------------------------------                                      #" << endl;
	cout << "#    cust_ports -f CustDB.dat                                                    #" << endl;
	cout << "#    --------------------------------------                                      #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#   ./cust_ports -cust" 			<< setw(60) << setfill(' ')
								 << " Opens an customer account #" << endl;
	cout << "#    ----------------------------------------                                    #" << endl;
	cout << "#    cust_ports -f CustDB.dat -cust VG003 -12                                    #" << endl;
	cout << "#    ----------------------------------------                                    #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#   ./cust_ports -out" 			<< setw(37) << setfill(' ')
			 << "                               Read and write an input file #" << endl;
	cout << "#    ---------------------------------------                                     #" << endl;
	cout << "#    cust_ports -f CustDB.dat -out NewDB.dat                                     #" << endl;
	cout << "#    ---------------------------------------                                     #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#   ./cust_ports -num_years" << setw(55) << setfill(' ') 
								<< " Number in years for projections #" << endl;
	cout << "#    ---------------------------------------                                     #" << endl;
	cout << "#    cust_ports -f db_file.dat -cust cust_ID -num_years                          #" << endl;
	cout << "#    ---------------------------------------                                     #" << endl;
	cout << "#                                                                                #" << endl;
	cout << "#--------------------------------------------------------------------------------#" << endl;
	cout << endl << endl;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           MenuInteractive()
DESCRIPTION:        Menu
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
char MenuInteractive(ostream &out, char &choice, fstream &dataBaseFile, fstream &outputFile, Customer *newCust)
	{
		cout << endl << endl;
		cout << " Enter input file name [Default: TestDB.dat]: " << endl;  //FIXME: remove endl
		

		//FIXME: code that ask uses which file to open

		cout << " Opening: " << "TestDB.dat" << " for input" << endl;
		cout << endl;
		cout << " Input file: " << "TestDB.dat" << endl;
		cout << endl;
		cout << " No. Records Read: " << "6" << endl;
		cout << endl;

		do
		{
			cout << " " << setw(55) << setfill('-') << " " << endl;
			cout << " " << setw(32) << setfill(' ') << "Cust_Ports Program" << endl;
			cout << " " << setw(23) << setfill(' ') << "Main Menu" << endl;
			cout << " " << setw(55) << setfill('-') << " " << endl;
			cout << right << endl;
			cout << setw(40) << setfill(' ') << "1.   Create customer portfolio" << endl;
			cout << setw(28) << setfill(' ') << "2.   Deposit funds" << endl;
			cout << setw(36) << setfill(' ') << "3.   Display customer info" << endl;
			cout << setw(37) << setfill(' ') << "4.   Show funds projections" << endl;
			cout << setw(26) << setfill(' ') << "5.   Write to DB" << endl;
			cout << setw(26) << setfill(' ') << "6.   Report file" << endl;
			cout << setw(19) << setfill(' ') << "7.   Quit" << endl;
			cout << endl;
			cout << " Enter your choice: ";
			
			cin >> choice;

			// Clears extra input
			cin.ignore(numeric_limits<int>::max(), '\n');
			out << endl;

			// Menu switch
			switch (choice)
			{
				case '1':
					NewCustomer(cout, newCust);
					break;
				case '2':
					DepositFunds(cout, newCust);
					break;
				case '3':
					CustomerInfoDisp(cout, dataBaseFile, newCust);
					break;
				case '4':
					ShowFundsProj(cout, newCust);
					break;
				case '5':
					out << " --------------------------" << endl;
					out << " Writting into DB file" << endl;
					out << " --------------------------" << endl;
					out << endl << endl;
					CustomerInfoDisp(outputFile, dataBaseFile, newCust);
					break;
				case '6':
					ReportFile(cout, newCust);
					break;
				case '7':
					break;
				default:
					cout << " Not an option, try again" << endl << endl;
					// QuestWriteFile();
					break;
				}
		}while(choice != '7');
		cout << endl;

		return choice;
	}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           NewCustomer()
DESCRIPTION:        Creates new customer
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void ShowFundsProj(ostream &out, Customer newCust[])
	{
		out << " The Projections for customer: " << "RS001" << " From account: " << "WF0342" << " are: ";
		out << " $78452.58" << endl;
		out << endl << endl;
	}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           NewCustomer()
DESCRIPTION:        Creates new customer
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void NewCustomer(ostream &out, Customer newCust[])
	{
		char data[30];
		int accIndex0 = 0;

		out << "Customer first  name: ";
		cin >> data;
		// data >> newCust[accIndex0].last_name;
		// out << " " << newCust[accIndex0].last_name << endl;
		out << "Customer last   name: ";
		cin >> data;

		out << "Customer middle name: ";
		cin >> data;

		out << "Customer Tax-ID: ";
		cin >> data;

		out << "Customer phone number: ";
		cin >> data;
		out << endl;
	}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           DepositFunds()
DESCRIPTION:        Deposit funds into customer acc
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void DepositFunds(ostream &out, Customer newCust[])
	{
		char custID[6];
		char deposit[19];
		int accIndex0 = 0;
		int i = 0;

		out << " Enter Customer ID:  ";
		// cin >> custID;
		out << "RS001" << endl << endl;

		out << " Enter amount to deposit ";
		cin.getline(deposit,10,'\n');

		cout << " $" << deposit << " will be added into account " << newCust[accIndex0].acc_info[i].acc_id << endl;
	}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           ReadCustFile()
DESCRIPTION:        Reads customer data into structure
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void ReadCustFile(Customer newCust[], fstream &dataBaseFile)
{
	int accIndex1 = 0;
  // cout << endl;

  for(int accIndex0 = 0; accIndex0 < NUM_CUSTOMERS; accIndex0++)
  {
   dataBaseFile.getline(newCust[accIndex0].customer_id,7,'\n');
   dataBaseFile.getline(newCust[accIndex0].last_name,21,',');
   dataBaseFile.ignore(numeric_limits<int>::max(), ' ');             //Ignores space after ','
   dataBaseFile.getline(newCust[accIndex0].first_name,21,',');
   dataBaseFile.ignore(numeric_limits<int>::max(), ' ');
   dataBaseFile.getline(newCust[accIndex0].middle_name,21,'\n');
   dataBaseFile.getline(newCust[accIndex0].tax_id_num,19,'\n');
   dataBaseFile.getline(newCust[accIndex0].phone_num,20,'\n');
    
   for(int i = 0; i < 3; i++)          //FIXME: change to num_ACCs
   {
       dataBaseFile.getline(newCust[accIndex1].acc_info[i].acc_id,7);
      //  dataBaseFile.ignore(numeric_limits<int>::max(), ' ');
       dataBaseFile.getline(newCust[accIndex1].acc_info[i].acc_balance,19,' ');
       dataBaseFile.getline(newCust[accIndex1].acc_info[i].growth_rate,9,' ');
       dataBaseFile.getline(newCust[accIndex1].acc_info[i].comp_per_year,9, '\n');
   }
   accIndex1++;
  }
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           ReportFile()
DESCRIPTION:        Creates a report file
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void ReportFile(std::ostream &out, Customer newCust[])
{
	int accIndex1 = 0;

	for(int i = 0; i < NUM_CUSTOMERS; i++)
	{
		out << setfill(' ') <<  setw(7)  << "CustID" 
				<< setfill(' ') <<  setw(11) << "Last_Name"
				<< setfill(' ') <<  setw(17) << "First_Name"
				<< setfill(' ') <<  setw(12) << "Middle"
				<< setfill(' ') <<  setw(12) << "TAX ID" 
				<< setfill(' ') <<  setw(12) << "Phone" 
				<< endl;

		out << setfill(' ') << setw(7)  << "------" 
				<< setfill(' ') << setw(16) << "--------------" 
				<< setfill(' ') << setw(16) << "--------------"
				<< setfill(' ') << setw(12) << "----------"  
				<< setfill(' ') << setw(13) << "-----------" 
				<< setfill(' ') << setw(17) << "---------------" 
				<< endl;

		out << left << " " << setw(8) << setfill(' ')
				<< newCust[i].customer_id   << setw(16) << setfill(' ')
				<< newCust[i].last_name     << setw(16) << setfill(' ')
				<< newCust[i].first_name    << setw(12) << setfill(' ')
				<< newCust[i].middle_name   << setw(13) << setfill(' ')
				<< newCust[i].tax_id_num    << setw(15) << setfill(' ')
				<< newCust[i].phone_num     << setw(1)  << setfill(' ') << right << endl;

		out << setfill(' ') << setw(1) << " --------------------------"
				<< "------------------------------------------------------" << endl;

		out << setfill(' ') << setw(17) << "Accounts" 
				<< setfill(' ') << setw(15) << "Balance"
				<< setfill(' ') << setw(15) << "% Rate" 
				<< setfill(' ') << setw(5)  << "C/Y"
				<< setfill(' ') << setw(24) << "Projections (1 yr)" << endl;

		out << setfill(' ') << setw(17) << "--------"
				<< setfill(' ') << setw(17) << "-----------"
				<< setfill(' ') << setw(13) << "------" 
				<< setfill(' ') << setw(5)  << "---" 
				<< setfill(' ') << setw(17) << "------------" << endl;
		
		for(int i = 0; i < 3; i++)
		{
				out << "         " << setfill('X') << setw(90);
				out << left
						<< setfill(' ') << setw(14) << newCust[accIndex1].acc_info[i].acc_id
						<< setfill(' ') << setw(18) << newCust[accIndex1].acc_info[i].acc_balance 
						<< setfill(' ') << setw(8)  << newCust[accIndex1].acc_info[i].growth_rate
						<< setfill(' ') << setw(8) 	<< newCust[accIndex1].acc_info[i].comp_per_year
						<< setfill(' ') << setw(12) << "78719.46" << endl;
		}
		accIndex1++;

		out << setw(9) << " " << "-------" << endl
				<< right;
		out << setfill(' ') << setw(16) << "Totals:"
				<< setfill(' ') << setw(16) << "19788.88" 
				<< setfill(' ') << setw(37) << "108127.36" << endl;
		out << endl;
	}
	return ;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           CustomerInfoDisp()
DESCRIPTION:        Display customer info (-info)
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void CustomerInfoDisp(ostream &out, fstream &dataBaseFile, Customer newCust[])
{
	char accChoice[6];
	bool wrongAcc = false;
	int noMatch = false;

	do
	{
		out << "(5-char) Customer ID: RS001" << endl << endl;
		// cin >> (accChoice);

		if(strlen(accChoice) > 6)
		{
			out << "Wrong customer ID" << endl;
		}

		//Looks if user input matches ACCs in Struct
		noMatchFun();							//Creat function
		if(noMatch == true)
			out << "Wrong customer ID" << endl;
		else if(noMatch == false)
		{

		}

	 }while (wrongAcc == true);
	
	for(int accIndex0 = 0; accIndex0 < NUM_CUSTOMERS; accIndex0++)
	{
			out << left << " " << setw(8) << setfill(' ')
					<< "Customer ID: "  << newCust[accIndex0].customer_id   << setw(14) << setfill(' ') << endl
					<< " Last   Name: " << newCust[accIndex0].last_name     << setw(10) << setfill(' ') << endl
					<< " First  Name: " << newCust[accIndex0].first_name   << setw(12) << setfill(' ') << endl
					<< " Middle Name: " << newCust[accIndex0].middle_name  << setw(13) << setfill(' ') << endl
					<< " Tax ID  Num: " << newCust[accIndex0].tax_id_num    << setw(9)  << setfill(' ') << endl
					<< " Phone   Num: " << newCust[accIndex0].phone_num     << setw(1)  << setfill(' ') << right << endl;

			out << setfill(' ') << setw(22) << "Accounts" 
					<< setfill(' ') << setw(15) << "Balance"
					<< setfill(' ') << setw(15) << "% Rate" 
					<< setfill(' ') << setw(5)  << "C/Y" << endl;

			out << setfill(' ') << setw(22) << "--------"
					<< setfill(' ') << setw(17) << "-----------"
					<< setfill(' ') << setw(13) << "------" 
					<< setfill(' ') << setw(5)  << "---" << endl; 
			
			for(int i = 0; i < 3; i++)
			{
					out << " Acct Num. " << i+1 << "  ";
					out << setfill(' ') << setw(5)   << newCust[accIndex0].acc_info[i].acc_id
							<< setfill(' ') << setw(18)  << newCust[accIndex0].acc_info[i].acc_balance 
							<< setfill(' ') << setw(14)  << newCust[accIndex0].acc_info[i].growth_rate
							<< setfill(' ') << setw(5)   << newCust[accIndex0].acc_info[i].comp_per_year << endl;
			}
			out << endl;
	} 
	out << endl;

	out << " Num. of records written: " << "1" << endl;   // Change so it counts records
	out << endl;
	return;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           noMatchFun()
DESCRIPTION:        Searches for ACC in database
RETURNS:            bool
--------------------------------------------------------------------------------------------------*/
bool noMatchFun()
{
	bool status = false;


	return status;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           CloseFile()
DESCRIPTION:        Closes files inside program
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void CloseFile(fstream &)
{
    fstream filesCheck;
    filesCheck.close();
    return;
}