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


Cpmv& Cpmv::operator=(const Cpmv& cp) // assignment operation with copy
{
	std::cout << "\n-Automatic assignment with copy - obj2 = obj1\n";
	if (this == &cp)
		return *this;
	delete pi;

	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}


Cpmv Cpmv::operator+(const Cpmv& obj) const // operator+() function
{
	std::cout << "\n- operator+() - (obj1 + obj2)\n";
	Cpmv temp = Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);

	//temp.pi->qcode + pi->qcode;
	//temp.pi->zcode + pi->zcode;

	return temp;
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


//++
Cpmv::Cpmv(Cpmv&& mv) noexcept  // transfer constructor 
{
	std::cout << "\n-Transfer constructor - Cpmv obj2 (obj1)\n";
	pi = mv.pi; // borrow address 
	mv.pi = nullptr; // set old object to null pointer
}


Cpmv& Cpmv::operator=(Cpmv&& mv) noexcept  // assignment with transfer
{
	std::cout << "\n-Automatic assignment with transfer - obj1 + obj2\n";
	if (this == &mv)
		return *this;
	
	delete pi;
	pi = mv.pi; // borrow address 
	mv.pi = nullptr; // set old object to null pointer
	return *this;

}
