#include "Matrix.h"

int main()
{
	int m, n;

	cout << " Input rows and cols: ";
	cin >> m >> n;

	Matrix mat1(m, n);

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			mat1.set(i, j, (i+1)*(j+1));
	}

	mat1.display();
	return 0;
}
