#pragma once

//Listing 15.10
//exeption classes hmean() and gmean() 
#include <iostream>
#include <stdexcept>

class bad_hmean :public std::logic_error //derivative class from logicerror
{
private:
	double v1;
	double v2;
public:

	// change construstor with using new member - const char* what
	bad_hmean(double a = 0, double b = 0, const char* what = nullptr) : v1(a), v2(b), logic_error(what) { }
	
	//add what method what (to show third argument)
	const char* what();
};

inline const char* bad_hmean::what()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): " << "invalid arguments: a = -b\n";
	return logic_error::what();
}






class bad_gmean :public std::logic_error //derivative class from logicerror
{
public:
	double v1;
	double v2;

	//change constructor 
	bad_gmean(double a = 0, double b = 0, const char* what = nullptr) : v1(a), v2(b), logic_error(what) { }

	//add what method
	const char* what();
};

inline const char* bad_gmean::what()
{
	std::cout << "gmean() arguments should be >= 0\n"; // arguments should be >= 0
	return logic_error::what();
}