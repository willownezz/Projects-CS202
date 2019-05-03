/*--------------------------------------------------------------------------------------------------
FILE NAME:          queue_demo.cpp
DESCRIPTION:        main(); -- Driver File
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-29         1.0           Created File
Luiz Diego Garcia           2019-04-29         2.0           Added EndOfProgram function
Luiz Diego Garcia           2019-04-29         3.0           Created queue
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Dyn_Queue.cpp"


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
	DynQueue<int> queue;
	int numList[] = {1,2,3};
	int *ptr = NULL;
	int size = sizeof(numList)/sizeof(numList[0]);
	ptr = numList;
	cout << "test" << endl;

	for(int i = 0; i < size; i++)
	{
		queue.enqueue(*(ptr+i));
	}
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