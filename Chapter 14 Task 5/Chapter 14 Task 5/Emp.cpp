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

	std::cout << "Enter last name :";
	std::cin >> lname;

	std::cout << "Enter job :";
	std::cin >> job;
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


//++
//manager
manager::manager() : Abstr_emp()
{
	inchargeof = 0;
}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : Abstr_emp(fn, ln, j)
{
	inchargeof = ico;
}

manager::manager(const Abstr_emp& e, int ico): Abstr_emp(e)
{
	inchargeof = ico;
}

manager::manager(const manager& m) :Abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	Abstr_emp::ShowAll();
	//std::cout << "Number of managed abstr_emp : " << inchargeof << "\n";
	std::cout << "Number of managed abstr_emp : " << InChargeOf() << "\n";
}


void manager::SetAll()
{
	Abstr_emp::SetAll();
	std::cout << "Number of managed abstr_emp : ";
	//std::cin >> inchargeof;
	std::cin >> InChargeOf();
}


//++
//fink
fink::fink() : Abstr_emp()
{
}


fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : Abstr_emp(fn, ln, j)
{
	reportsto = rpo;
}

fink::fink(const Abstr_emp& e, const std::string& rpo) : Abstr_emp(e)
{
	reportsto = rpo;
}

fink::fink(const fink& e) : Abstr_emp(e)
{
	reportsto = e.reportsto;
}


void fink::ShowAll() const
{
	Abstr_emp::ShowAll();
	//std::cout << "Report to : " << reportsto << "\n";
	std::cout << "Report to : " << ReportsTo() << "\n";
}


void fink::SetAll()
{
	Abstr_emp::SetAll();
	std::cout << "Report to : ";
	//std::cin >> reportsto;
	std::cin >> ReportsTo();
}

