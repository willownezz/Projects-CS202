/*--------------------------------------------------------------------------------------------------
FILE NAME:          Dny_Queue.h
DESCRIPTION:        Specification File
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-29         1.0           Created File
Luiz Diego Garcia           2019-04-29         2.0           Created queue class
--------------------------------------------------------------------------------------------------*/
#ifndef __DYN_QUEUE_H__
#define __DYN_QUEUE_H__

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

//////////////////////////////////////
// Prototypes
//////////////////////////////////////
void EndOfProgram(ostream &out);

//////////////////////////////////////
//Classes
//////////////////////////////////////
template<class T>
class DynQueue
{
private:
	struct QueueNode
	{
		T value;
		QueueNode *next;
	};

	QueueNode *first;
	QueueNode *last;
	int num;

public:
	DynQueue();			//Constructor
	~DynQueue();		//Destructor

	void clear();
	void enqueue(T);
	void dequeue(T &);
	bool isEmpty();
	bool isFull();
};


#endif