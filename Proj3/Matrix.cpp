/*--------------------------------------------------------------------------------------------------
FILE NAME:          Matrix.cpp
DESCRIPTION:        Program functions (Implementation file)
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
Luiz Diego Garcia           2019-05-03         1.5           Added destructor
Luiz Diego Garcia           2019-05-03         1.6           Created ofstream overloaded ope.
Luiz Diego Garcia           2019-05-05         1.7           Created ifstream overloaded ope.
Luiz Diego Garcia           2019-05-05         1.8           Created defaut constructor
Luiz Diego Garcia           2019-05-06         1.9           Changed library include
Luiz Diego Garcia           2019-05-07         1.10          Removed .display - old code
Luiz Diego Garcia           2019-05-07         1.11          Fixed indentations
Luiz Diego Garcia           2019-05-08         1.12          >> operator changed outlook
Luiz Diego Garcia           2019-05-08         1.13          Fixed ostream couts
Luiz Diego Garcia           2019-05-08         1.14          Created = overloaded templated class
Luiz Diego Garcia           2019-05-08         1.15          Fixed default constructor
Luiz Diego Garcia           2019-05-08         1.16          Created a copy constructor
Luiz Diego Garcia           2019-05-08         1.17          Created + operator
Luiz Diego Garcia           2019-05-09         1.18          Created - operator
Luiz Diego Garcia           2019-05-09         1.19          Fix bug in + print diff matrices sizes
Luiz Diego Garcia           2019-05-09         1.20          Created * operator
Luiz Diego Garcia           2019-05-09         1.21          Created / operator
Luiz Diego Garcia           2019-05-09         1.22          Created == operator
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Matrix.h"

/*--------------------------------------------------------------------------------------------------
FUNCTION:           Matrix<T>::Matrix(int,int)
DESCRIPTION:        Constructor
RETURNS:            N/A
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
FUNCTION:           T Matrix<T>::get(int,int)
DESCRIPTION:        Getter
RETURNS:            N/A
--------------------------------------------------------------------------------------------------*/
template<class T>
T Matrix<T>::get(int i, int j) const
{
	return array[i][j];
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           void Matrix<T>::set(int,int,T)
DESCRIPTION:        Setter
RETURNS:            N/A
--------------------------------------------------------------------------------------------------*/
template<class T>
void Matrix<T>::set(int i, int j, T k)
{
	array[i][j] = k;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Matrix<T>::~Matrix()
DESCRIPTION:        Destructor
RETURNS:            N/A
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
FUNCTION:           ostream &operator << (ostream &,const Matrix<T> &)
DESCRIPTION:   	    Ostream    
RETURNS:            N/A
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
			strm << setw(7) << setprecision(3) << array.array[i][j];
		}
		strm << endl;
	}
	return strm;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           istream &operator >> (istream &,Matrix<T> &)
DESCRIPTION:        Istream
RETURNS:            N/A
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
FUNCTION:           Matrix<T>::Matrix()
DESCRIPTION:        Defaut constructor - sets to 0/NULL
RETURNS:            N/A
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T>::Matrix()
{
	rows = 0;
	cols = 0;
	array = NULL;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Matrix<T>::Matrix(const Matrix<T> &)
DESCRIPTION:        Copy constructor
RETURNS:            N/A
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T>::Matrix(const Matrix<T> &temp)
{
	rows = temp.rows;
	cols = temp.cols;

	array = new T*[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
		for(int j = 0; j < cols; j++)
		{
			array[i][j] = temp.array[i][j];
		}
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Matrix<T> & Matrix<T>::operator = (const Matrix<T> &)
DESCRIPTION:        = operator
RETURNS:            N/A
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix<T> & Matrix<T>::operator = (const Matrix<T> &temp)
{
	for(int i = 0; i < rows; i++)
	{
		delete [] array[i];
	}
	delete [] array;

	rows = temp.rows;
	cols = temp.cols;

	array = new T*[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
			for(int j = 0; j < cols; j++)
			{
				array[i][j] = temp.array[i][j];
			}
	}
	return *this;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Matrix_ops<T>& Matrix_ops<T>::operator + (const Matrix_ops<T> &)
DESCRIPTION:        + Overloaded Operator
RETURNS:            N/A
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix_ops<T>& Matrix_ops<T>::operator + (const Matrix_ops<T> &temp)
{
	if(rows != temp.rows || cols != temp.cols)
	{
		throw " Invalid Dimentions";
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
FUNCTION:           Matrix_ops<T>& Matrix_ops<T>::operator - (const Matrix_ops<T> &)
DESCRIPTION:        - Overloaded Operator
RETURNS:            N/A
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix_ops<T>& Matrix_ops<T>::operator - (const Matrix_ops<T> &temp)
{
	if(rows != temp.rows || cols != temp.cols)
	{
		throw " Invalid Dimentions";
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
FUNCTION:           Matrix_ops<T>& Matrix_ops<T>::operator * (const Matrix_ops<T> &)
DESCRIPTION:        * Overloaded Operator
RETURNS:            N/A
--------------------------------------------------------------------------------------------------*/
template<class T>
Matrix_ops<T>& Matrix_ops<T>::operator * (const Matrix_ops<T> &test)
{
	if(cols != test.rows)
	{
		throw " Invalid Dimentions";
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
FUNCTION:           Matrix_ops<T>& Matrix_ops<T>::operator * (double&)
DESCRIPTION:        Multiplicantion Scalar
RETURNS:            N/A
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
FUNCTION:           Matrix_ops<T>& Matrix_ops<T>::operator / (double& )
DESCRIPTION:        Division Scalar
RETURNS:            N/A
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
FUNCTION:           bool Matrix_ops<T>::operator == (const Matrix_ops<T> &)
DESCRIPTION:        Equality Operator
RETURNS:            N/A
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