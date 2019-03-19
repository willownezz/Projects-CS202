/*--------------------------------------------------------------------------------------------------
FILE NAME:          cust_ports_v1.cpp
DESCRIPTION:        Financial Portifolio Program
USAGE:              ./cust_ports_v1
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
Luiz Diego Garcia           2019-02-28         0.0.7         Added include for .h file
Luiz Diego Garcia           2019-02-28         0.0.8         yanked prototypes/strucs to .h file
Luiz Diego Garcia           2019-02-28         0.0.9         operator overloading ostream &out
Luiz Diego Garcia           2019-02-28         0.0.10        getline to upload file into struct
Luiz Diego Garcia           2019-02-28         0.0.11        cleaned unused code
Luiz Diego Garcia           2019-02-28         0.0.12        fixed loop error
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "cust_ports_v1.h"      // Libraries, Prototypes & Structs

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
    //Removes unused warning
    char *prog = argv[0];
    (void)argc;
    cout << endl;

    fstream dataBaseFile;
    fstream outputFile;

    dataBaseFile.open("TestDB.dat", ios::in); // Open database file
    outputFile.open("testout.dat", ios::out); // Saves data into a new .dat file
    
    // Check if files were correctly opened
    FileCheck(cout, dataBaseFile);
    FileCheck(cout, outputFile);

    // Reads file into structure
    NewCustomer(cout, dataBaseFile);
    NewCustomer(outputFile, dataBaseFile);
   

    // Close file
    CloseFile(dataBaseFile);
    CloseFile(outputFile);

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
/*--------------------------------------------------------------------------------------------------
FUNCTION:           NewCustomer()
DESCRIPTION:        Creates a new Customer file
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void NewCustomer(ostream &out, fstream &dataBaseFile)
{
    int moneyAccs = 2;
    int counter = 0;
    int index = 1;
    int numCust = 0;
    int numOfAccs = 3;
    char blank[80];

    struct Customer newCust[20];

    // while(!dataBaseFile.eof())
    for(int accIndex0 = 0; accIndex0 < 3; accIndex0++)
    {
        dataBaseFile.getline(newCust[accIndex0].CUSTOMER_ID,7,'\n');
        dataBaseFile.getline(newCust[accIndex0].LAST_NAME,21,',');
        dataBaseFile.getline(newCust[accIndex0].FIRST_NAME,21,',');
        dataBaseFile.getline(newCust[accIndex0].MIDDLE_NAME,21,'\n');
        dataBaseFile.getline(newCust[accIndex0].TAX_ID_NUMBER,13,'\n');
        dataBaseFile.getline(newCust[accIndex0].PHONE_NUMBER,18,'\n');
    

        for(int accIndex1 = 0; accIndex1 < 3; accIndex1++)
        {       //FIXME: detect blank lines / count customer and accounts per customer
            dataBaseFile.getline(newCust[accIndex1].ACC_IN[accIndex1].ACC_ID,7,' ');
            dataBaseFile.getline(newCust[accIndex1].ACC_IN[accIndex1].ACC_BALANCE,13,' ');
            dataBaseFile.getline(newCust[accIndex1].ACC_IN[accIndex1].GROWTH_RATE,7,' ');
            dataBaseFile.getline(newCust[accIndex1].ACC_IN[accIndex1].COMP_PER_YEAR,3,'\n');
            // dataBaseFile.getline(newCust[accIndex1].ACC_IN[accIndex1].EMPTY_LINE,5,'\n');
            // if(dataBaseFile.getline == "")
            // {
            //     out << "Hey empty" << endl;
            // }
        }
            out << left << " " << setw(8) << setfill(' ')
                << "Customer ID: "  << newCust[accIndex0].CUSTOMER_ID   << setw(14) << setfill(' ') << endl
                << " Last   Name: " << newCust[accIndex0].LAST_NAME     << setw(10) << setfill(' ') << endl
                << " First  Name:"  << newCust[accIndex0].FIRST_NAME    << setw(12) << setfill(' ') << endl
                << " Middle Name:"  << newCust[accIndex0].MIDDLE_NAME   << setw(13) << setfill(' ') << endl
                << " Tax ID  Num: " << newCust[accIndex0].TAX_ID_NUMBER << setw(9)  << setfill(' ') << endl
                << " Phone   Num: " << newCust[accIndex0].PHONE_NUMBER  << setw(1)  << setfill(' ') << right << endl;

            out << setfill(' ') << setw(22) << "Accounts" 
                << setfill(' ') << setw(15) << "Balance"
                << setfill(' ') << setw(15) << "% Rate" 
                << setfill(' ') << setw(5)  << "C/Y" << endl;

            out << setfill(' ') << setw(22) << "--------"
                << setfill(' ') << setw(17) << "-----------"
                << setfill(' ') << setw(13) << "------" 
                << setfill(' ') << setw(5)  << "---" << endl; 
            
            for(int accIndex2 = 0; accIndex2 < 3; accIndex2++)
            {
                out << " Acct Num. " << index << "  ";
                out << setfill(' ') << setw(5)   << newCust[accIndex2].ACC_IN[accIndex2].ACC_ID
                    << setfill(' ') << setw(18)  << newCust[accIndex2].ACC_IN[accIndex2].ACC_BALANCE 
                    << setfill(' ') << setw(14)  << newCust[accIndex2].ACC_IN[accIndex2].GROWTH_RATE
                    << setfill(' ') << setw(5)   << newCust[accIndex2].ACC_IN[accIndex2].COMP_PER_YEAR << endl;
                    index++;
            }
            index = 1; 
            out << endl;
            numCust++;
     }
    out << " Num. of records written: " << numCust << endl;
    out << endl;
    return;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           FileCheck()
DESCRIPTION:        Creates a new database file
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void FileCheck(ostream &out, fstream &)
{
    fstream filesCheck;

    if(!filesCheck.fail())
    {
        // out << "File " << "file.txt" <<" open" << endl;
    }
    else
    {
        out << "Error opening file" << endl;
    }

    return;
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
