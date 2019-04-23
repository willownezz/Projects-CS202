

#include "Matrix.h"

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
//Getter
template<class T>
T Matrix<T>::get(int i, int j)
{
	return array[i][j];
}
//Setter
template<class T>
void Matrix<T>::set(int i, int j, T k)
{
	array[i][j] = k;
}

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
//Destructor
template<class T>
Matrix<T>::~Matrix()
{
	//delete array;                  //Wont delete the array properly
	for(int i = 0; i < rows; i++)    //Delete rows and cols
		delete [] array[i];

	delete [] array;				 //Delete pointer
}
