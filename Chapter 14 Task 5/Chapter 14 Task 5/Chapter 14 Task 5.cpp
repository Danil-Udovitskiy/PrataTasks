// Chapter 14 Task 5.cpp 

#include <iostream>
#include "Emp.h"

int main()
{
	employee em("Trip", "Harris", "Thumper");
	std::cout << em << "\n";
	em.ShowAll();
	em.SetAll();
	em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	std::cout << ma << "\n";
	ma.ShowAll();
	ma.SetAll();
	ma.ShowAll();
}
