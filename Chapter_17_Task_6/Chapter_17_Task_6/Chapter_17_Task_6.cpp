// Chapter_17_Task_6.cpp 


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


	std::cout << "\n\nPress a key for next phase:\n";

	std::cin.get();
	highfink hf2;
	hf2.SetAll();
	std::cout << "Using an abstr_emp * pointer:\n";
	// Using a pointer abstr_emp * 
	Abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();




	return 0;

}