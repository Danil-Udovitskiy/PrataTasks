// Chapter 13 Task 2.cpp 

#include <iostream>
#include "Cd.h"

void Bravo(const Cd& disk);

int main()
{
	Cd no_name_obj;
	std::cout << "-Using default constructor to create object-:";
	no_name_obj.Report();


	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	// Direct use of objects
	std::cout << "Using object directly:\n";
	c1.Report(); // using the CD method
	c2.Report(); // using the Classic method


	// Using a pointer to objects of type cd *
	std::cout << "\n-Using type cd * pointer to objects-:\n";
	pcd->Report(); // using Сd method on cd object


	pcd = &c2;
	pcd->Report(); // using the Classic method on a classic object


	// Calling a function with a reference argument to Cd
	std::cout << "\n-Calling a function with a Cd reference argument-:\n";
	Bravo(c1);
	Bravo(c2);


	// Testing assignment
	//We cant assign different types because the methods are not virtual (task didn't mention it)
	std::cout << "\n-Testing assignment for Classic type:- ";
	Classic copy; //first use - Classic operator overload =  then - Cd operator overload 
	copy = c2;
	copy.Report();

	
	std::cout << "\n-Testing assignment for Cd type:- ";
	no_name_obj = c1; //use of Cd operator overload =
	no_name_obj.Report();

	return 0;
}


void Bravo(const Cd& disk)
{
	disk.Report();
}