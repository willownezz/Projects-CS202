/*--------------------------------------------------------------------------------------------------
FILE NAME:          Int_List.cpp
DESCRIPTION:        Implementation File
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-29         1.0           Created File
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Int_List.h"

/*--------------------------------------------------------------------------------------------------
FUNCTION:           LinkList<T>::appendNode(T newValue)
DESCRIPTION:        Appends a node containing the value
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
void LinkList<T>::appendNode(T newValue)
{
	ListNode<T> *newNode;		//To point to a new node
	ListNode<T> *nodePtr;		//To move through the list

	//Allocates a new node and store num there
	newNode = new ListNode<T>(newValue);

	//If there are no nodes make newNode first node
	if(!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while(nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           LinkList<T>::appendNode(T newValue)
DESCRIPTION:        Appends a node containing the value
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
void LinkList<T>::displayList() const
{
	ListNode<T> *nodePtr;		//Move through the list

	nodePtr = head;

	while(nodePtr)
	{
		cout << nodePtr->value << endl;		//Display value in this node

		nodePtr = nodePtr->next;			//Move to next node
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           LinkList<T>::appendNode(T newValue)
DESCRIPTION:        Appends a node containing the value
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
void LinkList<T>::insertNode(T newValue)
{
	ListNode<T> *newNode;					//A new node
	ListNode<T> *nodePtr;					//To traverse list
	ListNode<T> *previousNode = nullptr;	//Previous node

	newNode = new ListNode<T>(newValue);

	if(!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;					//Position nodePtr to head of list
		previousNode = nullptr;			//init previousNode to null

		//Skip nodes whose value is less than num
		while(nodePtr != nullptr && nodePtr->value < newValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//If is 1st in list insert before all node
		if(previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           LinkList<T>::appendNode(T newValue)
DESCRIPTION:        Appends a node containing the value
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
void LinkList<T>::deleteNode(T searchValue)
{
	ListNode<T> *nodePtr;			//Traverse list
	ListNode<T> *previousNode;		//Point to previous node

	//If empty do nothing
	if(!head)
		return;

	//Determine if first node is the one
	if(head->value == searchValue)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while(nodePtr != nullptr && nodePtr->value != searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if(nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           LinkList<T>::appendNode(T newValue)
DESCRIPTION:        Appends a node containing the value
RETURNS:      		void      
--------------------------------------------------------------------------------------------------*/
template<class T>
LinkList<T>::~LinkList()
{
	ListNode<T> *nodePtr;
	ListNode<T> *nextNode;

	nodePtr = head;

	while(nodePtr != nullptr)
	{
		nextNode = nodePtr->next;		//Save pointer to next node
		delete nodePtr;					//Delete current node

		nodePtr = nextNode;
	}
}