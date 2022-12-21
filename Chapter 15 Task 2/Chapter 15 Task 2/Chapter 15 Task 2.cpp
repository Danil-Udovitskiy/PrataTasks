// Chapter 15 Task 2.cpp 

//Listing 15.11
#include <iostream> 
#include <cmath>
#include "Exc_mean.h" 


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


		catch (bad_hmean& bg)		// begin of block - catch 
		{
			//++
			cout << bg.what();
			cout << "\nTry again.\n"; // retry
			continue;
		}

		catch (bad_gmean& hg)
		{
			cout << hg.mesg();
			cout << "Values used: " << hg.vl << ", "
				<< hg.v2 << endl; // used values
			cout << "Sorry, you don't get to play any more.\n"; // end of session 

		}							// end of block - catch 
	}

	cout << "Bye!\n";
	return 0;
}
	
double hmean(double a, double b)
{
	if (a == -b)
	{
		//++
		throw bad_hmean(a, b, "bad arguments to hmean()");
		//you can also pass 2 arguments, so logic_error::what initialized to nullptr - throw bad_hmean(a, b), but in this case exeption will not be thrown
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

