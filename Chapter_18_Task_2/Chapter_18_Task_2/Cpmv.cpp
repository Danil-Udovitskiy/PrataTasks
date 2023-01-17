#include <iostream>
#include "Cpmv.h"

Cpmv::Cpmv() // default constructor
{
	std::cout << "\n-Default constructor  - obj\n";
	pi = nullptr;
}

Cpmv::Cpmv(std::string q, std::string z) // constructor with arguments
{
	std::cout << "\n-Constructor with arguments - obj (first, second)\n";
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}




void Cpmv::Display() const // Show data
{
	std::cout << "\n-Display function- obj.Display()\n";

	if (pi == nullptr) 
	{
		std::cout << "(object empty)" << std::endl;
	}
	else
	{
		std::cout << pi->qcode << "\n";
		std::cout << pi->zcode << "\n";
	}
}


Cpmv::~Cpmv()
{
	std::cout << "destructor\n";
}
