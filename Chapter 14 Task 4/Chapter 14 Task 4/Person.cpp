#include "Person.h"

Person::Person()
{
}

Person::Person(const std::string n, const std::string s_n)
{
	name = n;
	second_name = s_n;
}



Person::~Person()
{
}


void Person::Show()
{
	std::cout << "Name - " << name << "\n";
	std::cout << "Second name - " << second_name << "\n";
}