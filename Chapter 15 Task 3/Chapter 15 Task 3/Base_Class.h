#pragma once

//Listing 15.10
//Base class and exeption class bad_hmean
#include <iostream>
#include <stdexcept>


//base class (child of logic_error)
class Base :public std::logic_error
{
private:
	//2 argument values
	double v1;
	double v2;

public:
	//base class constructor
	Base(double a = 0.0, double b = 0.0, const char* what = nullptr) :v1(a), v2(b), logic_error(what) {};

	// the method is virtual, since it will be overridden in the descendant classes
	virtual const char* what();

};

inline const char* Base::what()
{
	std::cout << "Base Class(" << v1 << ", " << v2 << ")\n";
	return logic_error::what();
}




class bad_hmean :public Base //class of exception derived from base
{

public:

	//initialize bad_hmean class values with base class values
	bad_hmean(double a = 0, double b = 0, const char* what = nullptr) : Base(a, b, what) { };

	// display method (overridden)
	const char* what();
};

inline const char* bad_hmean::what()
{
	std::cout << "hmean() invalid arguments: a = -b\n";
	return Base::what(); //output data from the what() method of the base class
}




class bad_gmean :public Base //class of exception derived from base
{
public:

	//initialize bad_gmean class values with base class values
	bad_gmean(double a = 0, double b = 0, const char* what = nullptr) : Base(a, b, what) { };

	// display method (overridden)
	const char* what();
};

inline const char* bad_gmean::what()
{
	std::cout << "gmean() arguments should be >= 0\n"; // arguments should be >= 0
	return Base::what(); //output data from the what() method of the base class
}