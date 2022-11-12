// Chapter 12 Task 1.cpp 

#include <iostream>
#include "Cow.h"

int main()
{
	std::cout << "Constructors:__________________________\n";

	std::cout << "\nObject 1\n";
	Cow obj1;

	std::cout << "\nObject 2\n";
	Cow obj2("Hello", "Car", 22.6);
	
	std::cout << "\nObject 3 by copy constructor\n";
	Cow obj3 = Cow(obj2);

	std::cout << "\nObject 4 by assignment operation\n";
	Cow obj4;
	obj4 = obj2;


	std::cout << "\nShow:________________________________\n";

	std::cout << "\nObject 1\n";
	obj1.ShowCow();

	std::cout << "\nObject 2\n";
	obj2.ShowCow();

	std::cout << "\nObject 3 by copy constructor\n";
	obj3.ShowCow();

	std::cout << "\nObject 4 by assignment operation\n";
	obj4.ShowCow();

	std::cout << "\nDestructors:_____________________________\n\n"; //reverse calls from 4 to 1 object

	return 0;
}







