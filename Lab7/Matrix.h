/*--------------------------------------------------------------------------------------------------
FILE NAME:          Matrix.h
DESCRIPTION:        Header file
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-23         1.0           Created File
--------------------------------------------------------------------------------------------------*/

#ifndef __MATRIX_H__
#define __MATRIX_H__

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
template<class T>		//Create a template
class Matrix
{
	private:    //protected ??
		int rows;
		int cols;
		//int **array;
		T **array;				//Creates and array with data type T (any)

	public:
		Matrix(int rows, int cols);			//Overloaded Constructor
		~Matrix();							//Destructor
		T get(int i, int j) const ;			//Accessor
		void set(int i, int j, T k);		//Mutator
		void display();						//Accessor for output
		
		template<class T1>
		friend ostream &operator << (ostream &, const Matrix<T1> &);
		template<class T1>
		friend istream &operator >> (istream &, Matrix<T1> &);
};

#endif
