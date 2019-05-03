/*--------------------------------------------------------------------------------------------------
FILE NAME:          Matrix.cpp
DESCRIPTION:        Program functions
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-23         1.0           Created File
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Matrix.h"

/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T>::Matrix(int n_rows, int n_cols)
{
	rows = n_rows;
	cols = n_cols;

	array = new T*[rows];

	for (int i = 0; i < rows; i++)
		array[i] = new T[cols];

	cout << " Matrix cosntructor:  ";
	cout << rows << " X " << cols << endl;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        Getter
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
T Matrix<T>::get(int i, int j) const
{
	return array[i][j];
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        Setter
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
void Matrix<T>::set(int i, int j, T k)
{
	array[i][j] = k;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
void Matrix<T>::display()
{
	cout << endl;
	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << get(i, j);
		}
		cout << endl;
	}
	cout << endl;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        Destructor
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T>::~Matrix()
{
	//delete array;                  //Wont delete the array properly
	for(int i = 0; i < rows; i++)    //Delete rows and cols
		delete [] array[i];

	delete [] array;				 //Delete pointer
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
ostream &operator << (ostream &strm, const Matrix<T> &array)
{
	cout << endl;
	for(int i = 0; i < array.rows; i++)
	{
		for(int j = 0; j < array.cols; j++)
		{
			strm << setw(4) << array.get(i,j);
		}
		cout << endl;
	}
	return strm;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
istream &operator >> (istream &strm, Matrix<T> &array)
{
	T k;
	
	for(int i = 0; i < array.rows; i++)
	{
		for(int j = 0; j < array.cols; j++)
		{
			strm >> k;
			array.set(i,j,k);
		}	
	}
	return strm;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        Defaut constructor
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T>::Matrix()
{

}
