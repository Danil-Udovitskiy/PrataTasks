#include "Cd.h"
#include <string.h>


Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	//dynamic memory allocation
	int len1 = strlen(s1);
	performers = new char[len1 + 1];
	strcpy_s(performers, len1 + 1, s1);

	int len2 = strlen(s2);
	label = new char[len2 + 1];
	strcpy_s(label, len2 + 1, s2);

	selections = n;
	playtime = x;
}


Cd::Cd()
{
	int len1 = strlen("no name");
	performers = new char[len1 + 1];
	strcpy_s(performers, len1 + 1, "no name");


	int len2 = strlen("no label");
	label = new char[len2 + 1];
	strcpy_s(label, len2 + 1, "no label");

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
	delete[] performers;
	delete[] label;
}


//+
Cd& Cd::operator= (const Cd& d) // operator overload = with dynamic memory allocation for pointers
{
	if (this == &d)
		return *this;

	delete[]performers;
	delete[]label;


	int len1 = strlen(d.performers);
	performers = new char[len1 + 1];
	strcpy_s(performers, len1 + 1, d.performers);

	int len2 = strlen(d.label);
	label = new char[len2 + 1];
	strcpy_s(label, len2 + 1, d.label);

	selections = d.selections;
	playtime = d.playtime;

	return *this;
}




