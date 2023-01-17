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


Cpmv::Cpmv(const Cpmv& cp) //copy constructor
{
	std::cout << "\n-Copy constructor - Cpmv obj2 = obj1\n";

	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
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
	delete pi;
}
