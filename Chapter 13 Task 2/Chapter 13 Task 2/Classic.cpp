#include "Cd.h"

Classic::Classic(const char* sAdd, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	int lenAdd = strlen(sAdd)+1;
	main_track.reset(new char[lenAdd]);
	strcpy_s(main_track.get(), lenAdd, sAdd);
}


Classic::Classic() :Cd()
{
	int lenAdd = strlen("no name") + 1;
	main_track.reset(new char[lenAdd]);
	strcpy_s(main_track.get(), lenAdd, "no name");
}


void Classic::Report() const
{
	std::cout << "\nMain track : " << main_track;
	Cd::Report();
}


Classic::~Classic()
{
	std::cout << "classic dect\n";
}


//+
Classic& Classic::operator= (const Classic& d) // operator overload = with dynamic memory allocation for pointers
{

	if (this == &d)
		return *this;

	Cd::operator=(d);

	int lenAdd = strlen(d.main_track.get()) + 1;
	main_track.reset(new char[lenAdd]);
	strcpy_s(main_track.get(), lenAdd, d.main_track.get());

	return *this;
}


Classic::Classic(const  Classic& d) // copy constructor
{
	int lenAdd = strlen(d.main_track.get()) + 1;
	main_track.reset(new char[lenAdd]);
	strcpy_s(main_track.get(), lenAdd, d.main_track.get());
}