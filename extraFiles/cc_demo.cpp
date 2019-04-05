#include <iostream>
#include <stdio.h>
 
using namespace std;
 
class Test
{
    private:
	static int objectCount;    // Static member variable.
	int num;

    public:
	Test() 
	{
	    num = ++objectCount;
	    cout << "Constructor called for object:  " << num << endl;
	}

	Test(const Test &t)
	{
	    num = ++objectCount;
	    cout << "Copy Cstrtr called for object:  " << num << endl;
	}

	Test(const Test &&t)
	{
	    num = ++objectCount;
	    cout << "Move Cstrtr called for object:  " << num << endl;
	}

	Test operator = (const Test &t)
	{
	    cout << " = operator called." << endl;
	    return t;
	}

	~Test()
	{
	    cout << "Destructor  called for object:  " << num << endl;
	}
};
// Definition of the static member variable, written  outside the class.
    int Test::objectCount = 0;

 
int main()
{
    Test t1, t2;
    Test t3 = t1;

    t2 = t1;

    cout << endl;

    return 0;
}
