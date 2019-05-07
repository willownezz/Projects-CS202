/*--------------------------------------------------------------------------------------------------
FILE NAME:          Matrix.h
DESCRIPTION:        Header file
COMPILER:           GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-23         1.0           Created File
Luiz Diego Garcia           2019-04-29         1.1           Added EndOfProgram
Luiz Diego Garcia           2019-05-04         1.2           Added includes / ifndefs
Luiz Diego Garcia           2019-05-04         1.3           Added HelpFile prototype
Luiz Diego Garcia           2019-05-05         1.4           Created matrix class
Luiz Diego Garcia           2019-05-05         1.5           Added template <T>
Luiz Diego Garcia           2019-05-05         1.6           Added constructor / destruc.
Luiz Diego Garcia           2019-05-06         1.7           added default
Luiz Diego Garcia           2019-05-06         1.8           Added ifstream and ofstream
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
void HelpFile();

//////////////////////////////////////
//Classes
//////////////////////////////////////
template<class T>		//Create a template
class Matrix
{
	private:    //protected ??
		int rows;
		int cols;
		T **array;				//Creates and array with data type T (any)

	public:
		Matrix(int rows, int cols);			//Overloaded Constructor
		Matrix();							//Defaut
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
