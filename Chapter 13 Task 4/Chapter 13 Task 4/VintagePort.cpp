#include "Port.h"


VintagePort::VintagePort() : Port("no name", "vintage", 0) // default constructor 
{
	int len = strlen("no name");
	nickname = new char[len+1];
	strcpy_s(nickname, len + 1, "no name");
}



VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b) // constructor with arguments
{

	int len = strlen(nn);
	nickname = new char[len + 1];
	strcpy_s(nickname, len + 1, nn);

	year = y;
}



VintagePort::VintagePort(const VintagePort& vp):Port(vp) // copy constructor 
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
	os << vp.year << ", ";

	return os;
}


