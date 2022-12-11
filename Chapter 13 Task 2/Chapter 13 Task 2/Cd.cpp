#include "Cd.h"
#include <string.h>


Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	int len1 = strlen(s1) + 1;
	performers.reset(new char[len1]);
	strcpy_s(performers.get(), len1 , s1);

	int len2 = strlen(s2) + 1;
	label.reset(new char[len2]);
	strcpy_s(label.get(), len2, s2);

	selections = n;
	playtime = x;
}


Cd::Cd()
{
	int len1 = strlen("no name") + 1;
	performers.reset(new char[len1]);
	strcpy_s(performers.get(), len1, "no name");

	int len2 = strlen("no name") + 1;
	label.reset(new char[len2]);
	strcpy_s(label.get(), len2, "no name");

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
	std::cout << "cd dect\n";
}


//+
Cd& Cd::operator= (const Cd& d) // operator overload = with dynamic memory allocation for pointers
{
	if (this == &d)
		return *this;


	int len1 = strlen(d.performers.get()) + 1;
	performers.reset(new char[len1]);
	strcpy_s(performers.get(), len1, d.performers.get());

	int len2 = strlen(d.label.get()) + 1;
	label.reset(new char[len2]);
	strcpy_s(label.get(), len2, d.label.get());

	selections = d.selections;
	playtime = d.playtime;

	return *this;
}



Cd::Cd(const  Cd& d) // copy constructor
{
	int len1 = strlen(d.performers.get()) + 1;
	performers.reset(new char[len1]);
	strcpy_s(performers.get(), len1, d.performers.get());

	int len2 = strlen(d.label.get()) + 1;
	label.reset(new char[len2]);
	strcpy_s(label.get(), len2, d.label.get());

	selections = d.selections;
	playtime = d.playtime;
}





