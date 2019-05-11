/*--------------------------------------------------------------------------------------------------
FILE NAME:          Matrix.h
DESCRIPTION:        Header file (Specification file)
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
Luiz Diego Garcia           2019-05-06         1.7           added default constructor
Luiz Diego Garcia           2019-05-07         1.8           Added ifstream and ofstream
Luiz Diego Garcia           2019-05-08         1.9           Moved HelpFile prototype
Luiz Diego Garcia           2019-05-08         1.10          Moved EndOfProgram prototype
Luiz Diego Garcia           2019-05-08         1.11          Changed class Matrix from private to protected
Luiz Diego Garcia           2019-05-09         1.12          Added = operator
Luiz Diego Garcia           2019-05-09         1.13          Added copy constructor
Luiz Diego Garcia           2019-05-09         1.14          removed display()
Luiz Diego Garcia           2019-05-09         1.15          added setter and getter
Luiz Diego Garcia           2019-05-09         1.16          Created inherited class Matrix_ope
Luiz Diego Garcia           2019-05-09         1.17          Added + operator overloaded
Luiz Diego Garcia           2019-05-09         1.18          Added - operator overloaded
Luiz Diego Garcia           2019-05-09         1.19          Added * operator overloaded
Luiz Diego Garcia           2019-05-09         1.20          Added / operator overloaded
Luiz Diego Garcia           2019-05-09         1.21          Added * Scalar operator
Luiz Diego Garcia           2019-05-09         1.22          Added == operator overloaded
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
//Classes
//////////////////////////////////////
template<class T>		//Create a template
class Matrix
{  
	protected:
		int rows;
		int cols;
		T **array;				//Creates and array with data type T (any)

	public:
		Matrix(int rows, int cols);						//Overloaded Constructor
		Matrix();										//Default Constructor
		Matrix(const Matrix<T> &);						//Copy Constructor
		~Matrix();										//Destructor
		T get(int i, int j) const ;						//Accessor
		void set(int i, int j, T k);					//Mutator

		Matrix<T>& operator = (const Matrix<T> &);		// '=' Assigment operator
		
		template<class T1>
		friend ostream &operator << (ostream &, const Matrix<T1> &);		//Overloaded output operator
		template<class T1>
		friend istream &operator >> (istream &, Matrix<T1> &);				//Overloaded input operator
};

template<class T>
class Matrix_ops : public Matrix<T>
{
	private:
		using Matrix<T> :: rows;
		using Matrix<T> :: cols;
		using Matrix<T> :: array;

	public:
		using Matrix<T> :: Matrix;
		using Matrix<T> :: operator=;
		
		Matrix_ops<T>& operator + (const Matrix_ops<T> &);
		Matrix_ops<T>& operator - (const Matrix_ops<T> &);

		Matrix_ops<T>& operator * (const Matrix_ops<T> &test);
		Matrix_ops<T>& operator * (double& temp);
		Matrix_ops<T>& operator / (double& temp);

		bool operator == (const Matrix_ops<T> &);
	
};

#endif
