

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

class Matrix
{
	private:
		int rows;
		int cols;
		int **array;

	public:
		Matrix(int rows, int cols);			//Overloaded Constructor
		~Matrix();							//Destructor
		int get(int i, int j);				//Accessor
		void set(int i, int j, int k);		//Mutator
		void display();						//Accessor for output
};

#endif

