//#include "Matrix.h"
#include "Matrix.cpp"

typedef unsigned char byte;

int main(int argc, char *argv[])
{
//	int k;
//  double k;
	byte k;
	int m,n;
	char let_x;
	char file1[20];
	ifstream infile;
	string cmd;

	if(argc<3)
	{
		cout << " Not enough Arguments ? \n\n";
		return 0;
	}
	
	cmd = *++argv;
	
	if(cmd == "-inp")
	{
		strcpy(file1, *++argv);
		strcat(file1, ".mtx");
		infile.open(file1);
		if(!infile)	
		{
			cout << "\n Error opening file: " << file1 << "\n\n";
			return 0;
		}
	}
	
	infile >> m >> let_x >> n;

//  Matrix<int>  mat1(m, n);
//  Matrix<double>  mat1(m, n);
	Matrix<byte>  mat1(m, n);

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			infile >> k;
			mat1.set(i, j, k);
		}
	}

	mat1.display();
	infile.close();

	return 0;
}
