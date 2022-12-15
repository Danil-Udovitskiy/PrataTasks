// Chapter 14 Task 5.cpp 

#include <iostream>
#include "Emp.h"

int main()
{
	std::cout << "Employee\n\n";
	employee em("Trip", "Harris", "Thumper");
	std::cout << em << "\n";
	em.ShowAll();


	std::cout << "\n\nManager\n\n";
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	std::cout << ma << "\n";
	ma.ShowAll();


	std::cout << "\n\nFink\n\n";
	fink fi("Matt", "Oggs", "Oiler", "JunoBarr");
	std::cout << fi << "\n";
	fi.ShowAll();


	std::cout << "\n\nHighfink\n\n";
	highfink hf(ma, "Curly Kew");
	hf.ShowAll();
	hf.SetAll();
	hf.ShowAll();

	return 0;

}
