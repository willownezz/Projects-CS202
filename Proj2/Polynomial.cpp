/*--------------------------------------------------------------------------------------------------
FILE NAME:          Polynomial.cpp
DESCRIPTION:        File with functions
USAGE:              ./test.poly.sh
COMPILER:           GNU g++ compiler on Linux

MODIFICATION HISTORY:
Author                      Date               Version       Details
-----------------           ----------         --------      ---------------------------------------
Luiz Diego Garcia           2019-04-10         1.0           Created File
Luiz Diego Garcia           2019-04-13         1.1           Fixed headers and comments
Luiz Diego Garcia           2019-04-13         1.2 			 Created + Overload          
Luiz Diego Garcia           2019-04-13         1.3           Created - Overload
Luiz Diego Garcia           2019-04-13         1.4           Created * Overload
Luiz Diego Garcia           2019-04-13         1.5           Created = Overload
Luiz Diego Garcia           2019-04-13         1.6           Created == Overload
Luiz Diego Garcia           2019-04-13         1.7           Created Destructor
Luiz Diego Garcia           2019-04-13         1.8           Removed display();
Luiz Diego Garcia           2019-04-14         1.9           Added ostream overloaded <<
Luiz Diego Garcia           2019-04-14         1.10          Added Unicode chars for exponets
Luiz Diego Garcia           2019-04-14         1.11          Fixed multiplication overload
Luiz Diego Garcia           2019-04-14         1.12          Fixed == not showing right bool
Luiz Diego Garcia           2019-04-15         1.13          Fix constructor default init
Luiz Diego Garcia           2019-04-15         1.14          Moved couts to driver
Luiz Diego Garcia           2019-04-16         1.15          Created istream overloaded >>
Luiz Diego Garcia           2019-04-16         1.16          Removed get.poly()
Luiz Diego Garcia           2019-04-17         1.17          Fixed ostream segm. error
Luiz Diego Garcia           2019-04-17         1.18          Fixed headers
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
FUNCTION:           Polynomial::Polynomial(int,int)
DESCRIPTION:        Overload Constructor
RETURNS:            
--------------------------------------------------------------------------------------------------*/
Polynomial::Polynomial(int deg, int *arr)              // Overload Constructor
{
	this->degree = deg;
	for(int i = deg; i >= 0; i--)
	{
		this->coef[i] = arr[i];
	}
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial Polynomial::operator + ()
DESCRIPTION:        Overloaded binary + operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator + (const Polynomial &p1)
{
	Polynomial p2;

	p2.degree = MAX(degree, p1.degree);

	for (int i = p2.degree; i >= 0; i--)
		p2.coef[i] = coef[i] + p1.coef[i];

	return p2;      
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial Polynomial::operator - ()
DESCRIPTION:        Overloaded binary - operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator - (const Polynomial &p1)
{
	Polynomial p2;

	p2.degree = MAX(degree, p1.degree);

	for (int i = p2.degree; i >= 0; i--)
		p2.coef[i] = coef[i] - p1.coef[i];

	return p2;      
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial Polynomial::operator * ()
DESCRIPTION:        Overloaded binary * operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator * (const Polynomial &p1)
{
	Polynomial p2;

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
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial::~Polynomial()
DESCRIPTION:        Destructor
RETURNS:            
--------------------------------------------------------------------------------------------------*/
Polynomial::~Polynomial(){}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial Polynomial::operator = ()
DESCRIPTION:        Overloaded binary = operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator = (const Polynomial &assign)
{
	this->degree = assign.degree;

	for(int i = 0; i < degree+1; i++)
	{
		this->coef[i] = assign.coef[i];
	}

	return *this;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial Polynomial::operator << ()
DESCRIPTION:        ostream binary << operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
ostream& operator << (ostream &out, const Polynomial &poly)
{
	const char* exp[10] = {		// Array of Unicode characters
		"\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074",
		"\u2075", "\u2076", "\u2077", "\u2078", "\u2079"};

	
	for (int i = poly.degree; i >= 0; i--)
        {
			if(poly.coef[i] == 0) //Excludes coefs 0
			{}
			else
			{
				if (i < poly.degree)
				{
					if (poly.coef[i] >= 0) out << " +";
					else out << " ";
				}
				out << poly.coef[i];
					
				if (i <= 9 && i != 1 && i != 0) 
				{
					out << "x" << exp[i];
				}
				else if (i==1) 
				{
					out << "x";
				}
				else // If above exponent 9
				{
					if (i>1) out << "x^" << i;
					if (i==1) out << "x";
				}
			}
        }
        out << endl;
	return out;
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial Polynomial::operator >> ()
DESCRIPTION:        istream& >> operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
istream& operator >> (istream &, Polynomial &poly) 
{
	cout << endl;
    cout << "\n Degree of polynomial: ";
    cin >> poly.degree;

    cout << "\n Enter " << poly.degree+1 << " coefficients: ";

    for (int i = poly.degree; i >= 0; i--)
        cin >> poly.coef[i];
}
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial Polynomial::operator () ()
DESCRIPTION:        Overloaded binary () operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
// double Polynomial::operator () (double x)
// {
// 	double polyTemp = 0;
// 	int deg = this->degree;
// 	for(int i = deg; i >= 0; i--)
// 	{
// 	}
// 	return polyTemp;
// }
/*--------------------------------------------------------------------------------------------------
FUNCTION:           Polynomial Polynomial::operator == ()
DESCRIPTION:        Overloaded binary == operator
RETURNS:            
--------------------------------------------------------------------------------------------------*/
bool Polynomial::operator == (Polynomial &poly) 
{
    if(this->degree != poly.degree)
	{
		return false;
	}
	else
	{	
		for(int i = this->degree; i >= 0 ; i--)
		{
			if(this->coef[i] != poly.coef[i])
			return false;
		}
	}
	return true;
}