#include "Cd.h"

Classic::Classic(const char* sAdd, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	int lenAdd = strlen(sAdd);
	main_track = new char[lenAdd + 1];
	strcpy_s(main_track, lenAdd + 1, sAdd);
}


Classic::Classic() :Cd()
{

	int lenAdd = strlen("no name");
	main_track = new char[lenAdd + 1];
	strcpy_s(main_track, lenAdd + 1, "no name");
}


void Classic::Report() const
{
	std::cout << "\nMain track : " << main_track;
	Cd::Report();
}


Classic::~Classic()
{
	std::cout << "classic dect\n";
	delete[] main_track;
}


//+
Classic& Classic::operator= (const Classic& d) // operator overload = with dynamic memory allocation for pointers
{

	if (this == &d)
		return *this;

	delete[] main_track;
	Cd::operator=(d);

	int lenAdd = strlen(d.main_track);
	main_track = new char[lenAdd + 1];
	strcpy_s(main_track, lenAdd + 1, d.main_track);

	return *this;
}




