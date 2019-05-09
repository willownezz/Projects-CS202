/*--------------------------------------------------------------------------------------------------
FILE NAME:          Matrix.cpp
DESCRIPTION:        Program functions
COMPILER:           GNU g++ compiler on Linux
USAGE:              
MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-23         1.0           Created File
Luiz Diego Garcia           2019-05-01         1.1           Created constructor
Luiz Diego Garcia           2019-05-01         1.2           Added getter
Luiz Diego Garcia           2019-05-01         1.3           Added setter
Luiz Diego Garcia           2019-05-02         1.4           Created display()
Luiz Diego Garcia           2019-05-03         1.5           Addde destructor
Luiz Diego Garcia           2019-05-03         1.6           Created ofstream overloaded ope.
Luiz Diego Garcia           2019-05-05         1.7           Created ifstream overloaded ope.
Luiz Diego Garcia           2019-05-05         1.8           Created defaut constructor
Luiz Diego Garcia           2019-05-06         1.9           Changed library include
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Matrix.h"

/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        CONSTRUCTOR
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T>::Matrix(int n_rows, int n_cols)
{
	rows = n_rows;
	cols = n_cols;

	array = new T*[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
		for(int j =0;j<cols;j++)
		{
			array[i][j] = 0;
		}
	}
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
DESCRIPTION:        DISPLAY
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
	for(int i = 0; i < rows; i++)    //Delete rows and cols
	{
		delete [] array[i];
	}

	delete [] array;				 //Delete pointer
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:   	OSTREAM     
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
ostream &operator << (ostream &strm, const Matrix<T> &array)
{
	strm << " " << array.rows << " X " << array.cols << endl;
	strm << endl;
	for(int i = 0; i < array.rows; i++)
	{
		for(int j = 0; j < array.cols; j++)
		{
			strm << setw(5) << setprecision(3) << array.array[i][j];
		}
		strm << endl;
	}
	return strm;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        ISTREAM
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
istream &operator >> (istream &strm, Matrix<T> &array)
{
	int m, n;
	char let_x;
	strm >> m >> let_x >> n;
	Matrix<T> math0 (m, n);

	for(int i = 0; i < math0.rows; i++)
	{
		for(int j = 0; j < math0.cols; j++)
		{
			strm >> math0.array[i][j];
		}	
	}

	array = math0;
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
	rows = 0;
	cols = 0;
	array = NULL;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        Copy constructor
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T>::Matrix(const Matrix<T> &old)
{
	rows = old.rows;
	cols = old.cols;

	array = new T*[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
		for(int j = 0; j < cols; j++)
		{
			array[i][j] = old.array[i][j];
		}
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        = operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T> & Matrix<T>::operator = (const Matrix<T> &old)
{
	for(int i = 0; i < rows; i++)
	{
		delete [] array[i];
	}
	delete [] array;

	rows = old.rows;
	cols = old.cols;

	array = new T*[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
			for(int j = 0; j < cols; j++)
			{
				array[i][j] = old.array[i][j];
			}
	}
	return *this;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        + Overloaded Operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix_ops<T>& Matrix_ops<T>::operator + (const Matrix_ops<T> &temp)
{
	if(rows != temp.rows || cols != temp.cols)
	{
		throw " Wrong size matrices";
	}
	else
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				array[i][j] += temp.array[i][j];
			}	
		}
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        - Overloaded Operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix_ops<T>& Matrix_ops<T>::operator - (const Matrix_ops<T> &temp)
{
	if(rows != temp.rows || cols != temp.cols)
	{
		throw " Wrong size matrices";
	}
	else
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				array[i][j] -= temp.array[i][j];
			}	
		}
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        * Overloaded Operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix_ops<T>& Matrix_ops<T>::operator * (const Matrix_ops<T> &test)
{
	if(cols != test.rows)
	{
		throw " Wrong size matrices";
	}
	else
	{
		Matrix_ops<T> temp(rows, test.cols);
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < test.cols; j++)
			{
				for(int k = 0; k < cols; k++)
				{
					temp.array[i][j] += array[i][k] * test.array[k][j];
				}
			}
		}
		*this = temp;
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        * scalar
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix_ops<T>& Matrix_ops<T>::operator * (double& temp)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			array[i][j] *= temp;
		}
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        / scalar
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix_ops<T>& Matrix_ops<T>::operator / (double& temp)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			array[i][j] /= temp;
		}
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           
DESCRIPTION:        == operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
template<class T>
bool Matrix_ops<T>::operator == (const Matrix_ops<T> &temp)
{
	bool isFlip = true;

	if(rows != temp.rows || cols != temp.cols)
	{
		isFlip = false;
		return isFlip;
	} 
	else
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(array[i][j] != temp.array[i][j])
				{
					isFlip = false;
					
				}
				return isFlip;
			}
		}
	}	
}