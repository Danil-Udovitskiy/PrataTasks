#include "Cd.h"

Classic::Classic(const char* sAdd, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	int lenAdd = 50;
	strcpy_s(main_track, lenAdd, sAdd);
}


Classic::Classic():Cd()
{
	int lenAdd = 50;
	strcpy_s(main_track, lenAdd, "no name");
}


void Classic::Report() const
{
	std::cout << "\nMain track : " << main_track;
	Cd::Report();
}



