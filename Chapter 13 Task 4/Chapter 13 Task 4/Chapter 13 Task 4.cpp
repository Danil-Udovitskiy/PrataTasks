// Chapter 13 Task 4.cpp 

#include <iostream>
#include "Port.h"


int main()
{
	
	Port shirt("Gallo", "tawny", 8); //constructor with arguments
	shirt.Show();					 // Show function
	std::cout << shirt;				 // operator<<


	Port pants; // default values of constructor
	pants.Show();
	std::cout << pants;

	//operation = 
	pants = shirt;
	pants.Show();
	std::cout << pants;


	//copy constructor
	Port copy = Port(shirt);
	copy.Show();
	std::cout << copy;


	//operator +=
	copy.operator+=(5);
	copy.Show();

	//operator -=
	copy.operator-=(2);
	copy.Show();
	
}



