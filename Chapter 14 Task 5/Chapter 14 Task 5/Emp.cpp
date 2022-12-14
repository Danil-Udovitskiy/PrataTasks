#include "Emp.h"

Abstr_emp::Abstr_emp()
{
}

Abstr_emp::Abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
{
	fname = fn;
	lname = ln;
	job = j;
}

void Abstr_emp::ShowAll() const
{
	std::cout << "First name : " << fname << "\n";
	std::cout << "Last name : " << lname << "\n";
	std::cout << "Job : " << job << "\n";
}

void Abstr_emp::SetAll()
{
	std::cout << "Enter name :";
	std::cin >> fname;
	//std::getline(std::cin, fname);
	std::cout << "Enter last name :";
	std::cin >> lname;
	//std::getline(std::cin, lname);
	std::cout << "Enter job :";
	std::cin >> job;
	//std::getline(std::cin, job);
}

std::ostream& operator<<(std::ostream& os, const Abstr_emp& e)
{
	os << "First name : " << e.fname << "\n";
	os << "Last name : " << e.lname << "\n";
	os << "Job : " << e.job << "\n";
	return os;
}

Abstr_emp::~Abstr_emp()
{
}



//++
//employee
employee::employee() : Abstr_emp()
{
}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j): Abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
	Abstr_emp::ShowAll();
}


void employee::SetAll()
{
	Abstr_emp::SetAll();
}
