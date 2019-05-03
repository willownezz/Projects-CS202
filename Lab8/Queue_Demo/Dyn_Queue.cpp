/*--------------------------------------------------------------------------------------------------
FILE NAME:          Dyn_Queue.cpp
DESCRIPTION:        Implementation File
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-05-02         1.0           Created File
Luiz Diego Garcia           2019-05-02         2.0           Created Destructor
Luiz Diego Garcia           2019-05-02         3.0           Created Constructor
Luiz Diego Garcia           2019-05-02         4.0           Created enqueue
Luiz Diego Garcia           2019-05-02         5.0           Created dequeue
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Dyn_Queue.h"

/*--------------------------------------------------------------------------------------------------
FUNCTION:           DynQueue<T>::DynQueue()
DESCRIPTION:        Constructor
RETURNS:      		N\A
--------------------------------------------------------------------------------------------------*/
template<class T>
DynQueue<T>::DynQueue()
{
	first = nullptr;
	last = nullptr;
	num = 0;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           DynQueue<T>::~DynQueue()
DESCRIPTION:        Destructor
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
DynQueue<T>::~DynQueue()
{
	clear();
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           DynQueue<T>::clear();
DESCRIPTION:        Clear dequeues of its elements
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
void DynQueue<T>::clear()
{
	T value;

	while(!isEmpty())
		dequeue(value);
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           bool DynQueue<T>::isEmpty()
DESCRIPTION:        
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
bool DynQueue<T>::isEmpty()
{
	bool status;

	if(num > 0)
	{
		status = false;
	}
	else
	{
		status = true;
	}

	return status;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           bool DynQueue<T>::isFull()
DESCRIPTION:        
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
bool DynQueue<T>::isFull()
{
	cout << "isFull" << endl;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           DynQueue<T>::dequeue(T &numb)
DESCRIPTION:        Removes first values and copies it.
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
void DynQueue<T>::dequeue(T &numb)
{
	QueueNode *temp = nullptr;

	if(isEmpty())
	{
		cout << "Nothing in queue." << endl;
	}
	else
	{
		numb = first->value;

		temp = first;
		first = first->next;
		delete temp;

		num--;
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           DynQueue<T>::enqueue(T numb)
DESCRIPTION:        Inserts value in last item.
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
void DynQueue<T>::enqueue(T numb)
{
	QueueNode *newNode = nullptr;

	newNode = new QueueNode;
	newNode->value = numb;
	newNode->next = nullptr;

	if(isEmpty())
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
	num++;
}