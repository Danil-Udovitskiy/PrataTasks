#include "Port.h"

Port::Port(const char* br, const char* st, int b)
{
	int len = strlen(br);
	brand = new char[len + 1];
	strcpy_s(brand, len + 1, br);

	strcpy_s(style, 20, st);

	bottles = b;
}


Port::Port(const Port& p) // конструктор копирования 
{
	int len = strlen(p.brand);
	brand = new char[len + 1];
	strcpy_s(brand, len + 1, p.brand);

	strcpy_s(style, 20, p.style);

	bottles = p.bottles;
}



Port& Port::operator= (const Port& p) //операция присваивания
{
	if (this == &p)
		return *this;

	delete[]brand;

	int len = strlen(p.brand);
	brand = new char[len + 1];
	strcpy_s(brand, len + 1, p.brand);

	strcpy_s(style, 20, p.style);

	bottles = p.bottles;
	return *this;

}



Port& Port::operator+=(int b)  // добавляет b к bottles 
{
	bottles += b;
	return *this;
}


Port& Port::operator-= (int b) // вычитает b из bottles, если это возможно 
{
	if (bottles - b >= 0)
	{
		bottles -= b;
		return *this;
	}
	else
	{
		std::cout << "You cant subtract more than you have.\n";
		return *this;
	}

}


void Port::Show() const
{
	std::cout << "Brand : " << brand << "\n";
	std::cout << "Kind : " << style << "\n";
	std::cout << " bottles : " << bottles << "\n";
}


std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << ", ";
	os << p.style << ", ";
	os << p.bottles << "\n";

	return os;
}

