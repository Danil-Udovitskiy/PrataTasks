#include <iostream>
#include <cstring>
#include "Cow.h"


Cow::Cow() // default constructor
{
	name[0] = '\0'; //initialize 0 array element - '\0' or name[0] = {};

	std::unique_ptr<char[]> hobby; // std::unique_ptr<char[]> hobby = nullptr;
	hobby.reset(nullptr);

	weight = 0.0;  // initialize weight to 0.0 

	std::cout << "Default constructor\n"; // for debug purposes
}



Cow::Cow(const char* nm, const char* ho, double wt) // constructor with parameters std::unique_ptr<char[]> 
{
	// strlen() returns the length of the string, but does not contain null characters at the end of the string, it is equal to +1
	strcpy_s(name, strlen(nm) + 1, nm); //+1 place for '\0' to the end of char array (perform string copy)


	int len = std::strlen(ho) + 1; // variable that takes the length of the string
	//.get() returns a pointer to the char
	hobby.reset(new char[len]); // allocate memory for a new string
	strcpy_s(hobby.get(), strlen(ho) + 1, ho); // copying a string
	//pass pointer to char hobby.get() - raw, to pass a pointer, you need to pull it out of unique_ptr
	

	weight = wt; // assign wt value to weight field

	std::cout << "Constructor with arguments\n";  // for debug purposes 
}



Cow::Cow(const Cow& c) // copy constructor
{
	strcpy_s(name, strlen(c.name) + 1, c.name); // copying a string

	int len = std::strlen(c.hobby.get()) + 1; // variable that takes the length of the string
	hobby.reset(new char[len]); // allocate memory for a new string
	strcpy_s(hobby.get(), len, c.hobby.get()); // copying a string


	weight = c.weight;  // copying value to weight

	std::cout << "Copy constructor\n"; // for debug purposes
}



Cow::~Cow() // destructor
{
	std::cout << "Destructor with delete operation for hobby\n"; // for debug purposes
}



Cow& Cow::operator= (const Cow& c) // class assignment operation
{
	if (this == &c) // assigning an object to itself
		return *this; // all is ready 


	strcpy_s(name, strlen(c.name) + 1, c.name); // copying a string

	int len = std::strlen(c.hobby.get()) + 1; // variable that takes the length of the string
	hobby.reset(new char[len]); // allocate memory for a new string
	strcpy_s(hobby.get(), len, c.hobby.get()); // copying a string (there was an extra byte len+1)


	weight = c.weight; // assign value to weight

	return *this; // returning a reference to the caller
}



void Cow::ShowCow() const // output
{
	if (hobby !=nullptr)
	{
		std::cout << hobby << " - hobby\n";
	}
	else
	{
		std::cout << "no - hobby\n";
	}

	std::cout << name << " - name\n";
	std::cout << weight << " - weight\n";
}

