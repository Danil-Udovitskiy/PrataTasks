#include "Cd.h"
#include <string.h>

//Cd + Classic

Cd::Cd(const char* s1, const char* s2, int n, double x) 
{
	//different copy options
	//int len1 = 50;
	//std::strlen(s1);
	//strcpy_s(performers, strlen(s1) + 1, s1);
	//strcpy_s(performers, len1, s1);

	strcpy_s(performers, 50, s1);

	strcpy_s(label, len2, s2);
	
	selections = n;
	playtime = x;
}


Cd::Cd()
{
	strcpy_s(performers, len1, "no name");

	strcpy_s(label, len2, "no label");

	selections = 0;
	playtime = 0.0;
}


void Cd::Report() const
{
	std::cout << "\nPerformer : " << performers << "\n";
	std::cout << "Label : " << label << "\n";
	std::cout << "Number of selections : " << selections << "\n";
	std::cout << "Total playtime : " << playtime << "\n";
}


Cd::~Cd()
{
}


Cd& Cd::operator= (const Cd& d)
{
	strcpy_s(performers, len1, d.performers);

	strcpy_s(label, len2, d.label);
	
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}




//Classic

Classic::Classic(const char* sAdd, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
	strcpy_s(main_track, len1, sAdd);
}


Classic::Classic() :Cd()
{
	strcpy_s(main_track, len1, "no name");
}


void Classic::Report() const
{
	std::cout << "\nMain track : " << main_track;
	Cd::Report();
}