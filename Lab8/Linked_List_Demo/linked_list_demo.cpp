/*--------------------------------------------------------------------------------------------------
FILE NAME:          linked_list_demo.cpp
DESCRIPTION:        main(); -- Driver File
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-29         1.0           Created File
Luiz Diego Garcia           2019-04-29         1.0           Added EndOfProgram function
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Int_List.cpp"

// typedef unsigned char byte;

//////////////////////////////////////
// Constant Variables
//////////////////////////////////////
const char PROGRAMMER_NAME[] = "Luiz Diego Garcia";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        start of the program - Driver function
RETURNS:            0
--------------------------------------------------------------------------------------------------*/
int main()
{
	LinkList<int> list;
	int numList[] {1, 2, 3};
	int *ptr = NULL;
	int size;
	ptr = numList;
	size = (sizeof(numList)/sizeof(numList[0]));

	for(int i = 0; i < size; i++)
	{
		list.insertNode((*ptr+i));
	}

	cout << "Stored numbers are: " << endl;
	list.displayList();
	cout << endl;
	cout << "Inserting numbers 6, 7 and 9 " << endl;
	list.insertNode(6);
	list.insertNode(7);
	list.insertNode(9);
	
	cout << "Stored numbers are: " << endl;
	list.displayList();
	cout << endl;

	cout << "Appending number 4" << endl;
	cout << "Stored numbers are: " << endl;
	list.appendNode(4);
	list.displayList();
	cout << endl;

	cout << "Deleting second number" << endl;
	list.deleteNode(*(ptr+1));
	list.displayList();

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