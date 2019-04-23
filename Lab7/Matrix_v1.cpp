

#include "Matrix.h"

Matrix::Matrix(int n_rows, int n_cols)
{
	rows = n_rows;
	cols = n_cols;

	array = new int*[rows];

	for (int i = 0; i < rows; i++)
		array[i] = new int[cols];

	cout << " Matrix cosntructor:  ";
	cout << rows << " X " << cols << endl;
}
//Getter
int Matrix::get(int i, int j)
{
	return array[i][j];
}
//Setter
void Matrix::set(int i, int j, int k)
{
	array[i][j] = k;
}

void Matrix::display()
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
Matrix::~Matrix()
{
	//delete array;                  //Wont delete the array properly
	for(int i = 0; i < rows; i++)    //Delete rows and cols
		delete [] array[i];

	delete [] array;				 //Delete pointer
}
