#include "Port.h"

//Port + VintagePort

Port::Port(const char* br, const char* st, int b) // constructor with arguments
{
	int len = strlen(br);
	brand = new char[len + 1];
	strcpy_s(brand, len + 1, br);

	strcpy_s(style, 20, st);

	bottles = b;
}


Port::Port(const Port& p) // copy constructor
{
	int len = strlen(p.brand);
	brand = new char[len + 1];
	strcpy_s(brand, len + 1, p.brand);

	strcpy_s(style, 20, p.style);

	bottles = p.bottles;
}



Port& Port::operator= (const Port& p) //operation =
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



Port& Port::operator+=(int b)  // adds b to bottles
{
	bottles += b;
	return *this;
}


Port& Port::operator-= (int b) // subtracts b from bottles if possible
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


void Port::Show() const // function Show
{
	std::cout << "Brand : " << brand << "\n";
	std::cout << "Kind : " << style << "\n";
	std::cout << " bottles : " << bottles << "\n";
}


std::ostream& operator<<(std::ostream& os, const Port& p) //operation = 
{
	os << p.brand << ", ";
	os << p.style << ", ";
	os << p.bottles << "\n";

	return os;
}



//Vintage Port 
VintagePort::VintagePort() : Port("no name", "vintage", 0) // default constructor 
{
	int len = strlen("no name");
	nickname = new char[len + 1];
	strcpy_s(nickname, len + 1, "no name");
	year = 0000;
}


VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b) // constructor with arguments
{

	int len = strlen(nn);
	nickname = new char[len + 1];
	strcpy_s(nickname, len + 1, nn);

	year = y;
}


VintagePort::VintagePort(const VintagePort& vp) :Port(vp) // copy constructor 
{
	int len = strlen(vp.nickname);
	nickname = new char[len + 1];
	strcpy_s(nickname, len + 1, vp.nickname);

	year = vp.year;
}


VintagePort& VintagePort::operator=(const VintagePort& vp) // operation =

{
	if (this == &vp)
		return *this;

	Port::operator=(vp); // copy of base part 
	delete[]nickname;

	int len = strlen(vp.nickname);
	nickname = new char[len + 1];
	strcpy_s(nickname, len + 1, vp.nickname);
	year = vp.year;

	return *this;
}


void VintagePort::Show() const // funtion Show
{
	Port::Show();
	std::cout << "Nickname : " << nickname << "\n";
	std::cout << "Year : " << year << "\n";
}


std::ostream& operator<<(std::ostream& os, const VintagePort& vp) //operator <<
{
	// Cast to match operator<< (ostream & , const VintagePort &)
	os << (const Port&)vp << ", ";
	os << vp.nickname << ", ";
	os << vp.year;

	return os;
}
