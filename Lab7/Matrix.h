

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

template<class T>		//Create a template
class Matrix
{
	private:
		int rows;
		int cols;
		//int **array;
		T **array;				//Creates and array with data type T (any)

	public:
		Matrix(int rows, int cols);			//Overloaded Constructor
		~Matrix();							//Destructor
		T get(int i, int j);				//Accessor
		void set(int i, int j, T k);		//Mutator
		void display();						//Accessor for output
};

#endif

