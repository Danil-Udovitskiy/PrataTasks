// Chapter 15 Task 3.cpp 

#include <iostream> 
#include <cmath>
#include  "Base_Class.h"


double hmean(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y) // enter 2 numbers
	{
		try {						// begin of block - try 

			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl; // harmonic mean

			cout << "Enter next set of numbers <q to quit>: "; // enter next 2 numbers

		}							// end of block - try 

		
		// +++ 
		// use base class type to catch hmean exception
		catch (Base& base_obj)		// begin of block - catch 
		{
			cout << base_obj.what();
			cout << "\nEnd.\n";
			break;
		}

	}

	cout << "Bye!\n";
	return 0;
}


double hmean(double a, double b)
{
	if (a == -b)
	{
		throw bad_hmean(a, b, "bad arguments to hmean()");
		//you can also pass 2 arguments, so logic_error::what initialized to nullptr - throw bad_hmean(a, b), but in this case exeption will not be thrown
	}

	return 2.0 * a * b / (a + b);
}

