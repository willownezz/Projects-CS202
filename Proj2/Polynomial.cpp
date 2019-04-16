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
			if(coef[i] == 0)
			{}
			else
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
        }
        cout << endl;
        // cout << endl;
} 
//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary + operator                    |
// |_______________________________________________________________|
//
Polynomial Polynomial::operator + (const Polynomial &p1)
{
	Polynomial p2;

	cout << endl;
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

	cout << "\n Multiplying 2 polynomials: ";

	p2.degree = degree + p1.degree;

	for(int i = 0; i < degree+1; i++)
	{
		for(int j = 0; j < p1.degree+1; j++)
		{
			p2.coef[i+j] += coef[i]*p1.coef[j];
		}
	}

	return p2;  
}
//  _______________________________________________________________
// |                                                               |
// |                         Destructor                            |
// |_______________________________________________________________|
//
Polynomial::~Polynomial(){}
//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary = operator                    |
// |_______________________________________________________________|
//
Polynomial Polynomial::operator = (const Polynomial &assign)
{
	this->degree = assign.degree;

	for(int i = 0; i < degree+1; i++)
	{
		this->coef[i] = assign.coef[i];
	}

	return *this;
}
//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary << operator                   |
// |_______________________________________________________________|
//
ostream& operator<<(ostream &lhs, const Polynomial &rhs)
{
    // return lhs << rhs.print();

	// return out;
}
//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary >> operator                   |
// |_______________________________________________________________|
//


//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary == operator                   |
// |_______________________________________________________________|
//


//  _______________________________________________________________
// |                                                               |
// |               Overloaded binary () operator                   |
// |_______________________________________________________________|
//