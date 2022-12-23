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

	// construstor
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b), logic_error(nullptr) { }

	//add method what
	void what();
};

inline void bad_hmean::what()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): " << "invalid arguments: a = -b\n";
}






class bad_gmean :public std::logic_error //derivative class from logicerror
{
public:
	double v1;
	double v2;

	//constructor 
	bad_gmean(double a = 0, double b = 0) : v1(a), v2(b), logic_error(nullptr) { }

	//add what method
	void what();
};

inline void bad_gmean::what()
{
	std::cout << "gmean() arguments should be >= 0\n"; // arguments should be >= 0
}