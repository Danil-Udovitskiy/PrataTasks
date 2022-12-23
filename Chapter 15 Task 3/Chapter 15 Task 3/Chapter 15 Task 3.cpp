// Chapter 15 Task 3.cpp 

#include <iostream> 
#include <cmath>
#include  "Base_Class.h"


double hmean(double a, double b);
double gmean(double a, double b);

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
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << endl; // geometric mean 
			cout << "Enter next set of numbers <q to quit>: "; // enter next 2 numbers

		}							// end of block - try 

		
		// +++ 
		// use base class type to catch hmean and gmean exception (2 exception)
		catch (Base& base_obj)		// begin of block - catch 
		{
			base_obj.what();
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
		throw bad_hmean(a, b);
	}

	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw bad_gmean(a, b);
	}

	return std::sqrt(a * b);
}

