#include "Cd.h"
#include <string.h>


Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	//int len1 = 50;
	//std::strlen(s1);
	//strcpy_s(performers, strlen(s1) + 1, s1);
	//strcpy_s(performers, len1, s1);

	strcpy_s(performers, 50, s1);

	int len2 = 20;
	strcpy_s(label, len2, s2);
	
	selections = n;
	playtime = x;
}


Cd::Cd()
{
	int len1 = 50;
	strcpy_s(performers, len1, "no name");
	
	int len2 = 20;
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