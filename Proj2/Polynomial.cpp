/*--------------------------------------------------------------------------------------------------
FILE NAME:          Polynomial.cpp
DESCRIPTION:        
USAGE:              
COMPILER:           GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-10         1.0           Created File
Luiz Diego Garcia           2019-04-13         1.1           Fixed headers and comments
--------------------------------------------------------------------------------------------------*/

//////////////////////////////////////
//Libraries
//////////////////////////////////////
#include "Polynomial.h"

/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial::Polynomial()
DESCRIPTION:        Constructor - init values to 0
RETURNS:            
--------------------------------------------------------------------------------------------------*/
Polynomial::Polynomial()                            // Constructor
{                                                   // Initialize all values to 0
    degree = 0;

    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial::get_poly()
DESCRIPTION:        
RETURNS:            
--------------------------------------------------------------------------------------------------*/
void Polynomial::get_poly()
{
	cout << endl;
    cout << "\n Degree of polynomial: ";
    cin >> degree;

    cout << "\n Enter " << degree+1 << " coefficients: ";


    for (int i = degree; i >= 0; i--)
        cin >> coef[i];
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial::display_poly()
DESCRIPTION:        Display polynomial
RETURNS:            void
--------------------------------------------------------------------------------------------------*/
void Polynomial::display_poly()
{
	const char* exp[10] = {		// Array of Unicode characters
		"\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074",
		"\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};

	for (int i = degree; i >= 0; i--)
        {
            if (i < degree)
            {
                if (coef[i] >= 0) cout << " +";
                else cout << " ";
            }
            cout << coef[i];
				
				if (i <= 9 && i != 1 && i != 0) 
				{
					cout << "x" << exp[i];
				}
				else if (i==1) 
				{
					cout << "x";
				}
				else
				{
					if (i>1) cout << "x^" << i;
					if (i==1) cout << "x";
				}
        }
        cout << endl;
        cout << endl;
} 
//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary + operator                    |
// |_______________________________________________________________|
//
Polynomial Polynomial::operator + (const Polynomial &p1)
{
	Polynomial p2;

	cout << "\n Adding 2 polynomials: ";

	p2.degree = MAX(degree, p1.degree);

	for (int i = p2.degree; i >= 0; i--)
		p2.coef[i] = coef[i] + p1.coef[i];

	return p2;      
}
//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary - operator                    |
// |_______________________________________________________________|
//
Polynomial Polynomial::operator - (const Polynomial &p1)
{
	Polynomial p2;

	cout << "\n Subtracting 2 polynomials: ";

	p2.degree = MAX(degree, p1.degree);

	for (int i = p2.degree; i >= 0; i--)
		p2.coef[i] = coef[i] - p1.coef[i];

	return p2;      
}
//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary * operator                    |
// |_______________________________________________________________|
//
Polynomial Polynomial::operator * (const Polynomial &p1)
{
	Polynomial p2;
	Polynomial p3;
	Polynomial p4;

	cout << "\n Multiplying 2 polynomials: " << endl;

	p2.degree = MAX(degree, p1.degree);
	int mult = (p2.degree+1) * (p2.degree+1);
	int j = p2.degree;
	int h = p2.degree;
	int i2 = 0;
	int l = 0;

	// int i = p2.degree;
	for(int k = p2.degree; k >= 0; k--)
	{	
		// cout << k << "LA ";
		for(int i = p2.degree; i >= 0; i--)
		// for( ; i >= 0; i--)
		{
			// cout << i << "KA  ";
			p3.coef[i2] = coef[j] * p1.coef[i];
			// cout << i2 << ") " << p3.coef[i2] << " (" << j << ") " << coef[j] << " (" << i << ") " << p1.coef[i] << " " << endl;
			i2++;
			
		}
		i2++;
		// i = p2.degree;
		j--;
	}

	cout << endl;
	for(int p = 0; p <= 10; p++)
	cout << p3.coef[p];
	cout << endl;
	cout << " lll " << endl;
	
	int k = 1;
	int o = 1;
	for(int i = 0; i <= 3; i++)
	{
		for(int j = 0; j <= 4; j++)
		{
			// cout << " j " << j << " i " << i << endl;
			p2.coef[k] = p3.coef[k] + p3.coef[o];
			
			
			// cout << p2.coef[k] << " " << endl;
			cout << " ppp ";
			cout << p2.coef[k] << " " << endl;
			k++;
			o++;
		}
	}

	// p2.coef[0] = p3.coef[0];
	// p2.coef[4] = p3.coef[8];

	// cout << endl;
	// for(int p = 0; p <= 4; p++)
	// cout << p2.coef[p];
	cout << endl;

	return p2;      
	// return p3;      
}