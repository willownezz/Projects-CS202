/*--------------------------------------------------------------------------------------------------
FILE NAME:          Int_List.h
DESCRIPTION:        Specification File
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-29         1.0           Created File
Luiz Diego Garcia           2019-05-01         2.0           Added libraries
Luiz Diego Garcia           2019-05-01         3.0           Created EndOfProgram prototyper
Luiz Diego Garcia           2019-05-01         4.0           Created Destructor
Luiz Diego Garcia           2019-05-01         5.0           Created Constructor
Luiz Diego Garcia           2019-05-01         6.0           Created Class/Template
--------------------------------------------------------------------------------------------------*/

#ifndef __INT_LIST_H__
#define __INT_LIST_H__

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
class ListNode
{
	public:
		T value;
		ListNode<T> *next;

		ListNode(T nodeValue)
			{value = nodeValue;
			  next = nullptr;}
};

template<class T>
class LinkList
{
	private:
		ListNode<T> *head;
		
	public:
		LinkList()              			//Constructor
			{head = nullptr;}

		~LinkList();						//Destructor

		void appendNode(T);
		void insertNode(T);
		void deleteNode(T);
		void displayList() const;
		int &operator[](int &);
		
};

#endif
