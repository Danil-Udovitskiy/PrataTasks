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
	Base(double a = 0.0, double b = 0.0) :v1(a), v2(b), logic_error(nullptr) { };

	// the method is virtual, since it will be overridden in the descendant classes
	virtual void what();

};

inline void Base::what()
{
	std::cout << "Arguments(" << v1 << ", " << v2 << ")\n";
}




class bad_hmean :public Base //class of exception derived from base
{

public:

	//initialize bad_hmean class values with base class values
	bad_hmean(double a = 0, double b = 0) : Base(a, b) { };

	// display method (overridden)
	void what();
};

inline void bad_hmean::what()
{
	Base::what(); //output data from the what() method of the base class
	std::cout << "hmean() invalid arguments: a = -b\n";
}




class bad_gmean :public Base //class of exception derived from base
{
public:

	//initialize bad_gmean class values with base class values
	bad_gmean(double a = 0, double b = 0) : Base(a, b) { };

	// display method (overridden)
	void what();
};

inline void bad_gmean::what()
{
	Base::what(); //output data from the what() method of the base class
	std::cout << "gmean() arguments should be >= 0\n"; // arguments should be >= 0
}