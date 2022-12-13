#include "Person.h"

Person::Person()
{
}

Person::Person(const std::string n, const std::string s_n)
{
	name = n;
	second_name = s_n;
}



Person::~Person()
{
}


void Person::Show()
{
	std::cout << "Name - " << name << "\n";
	std::cout << "Second name - " << second_name << "\n";
}



//+++
// Gunslinger
Gunslinger::Gunslinger() : Person()
{
	number_of_notches_on_rifle = 0;
	combat_readiness_time = 0;
}


Gunslinger::Gunslinger(const std::string n, const std::string s_n, int notches_on_rifle, double readiness_time) : Person(n, s_n)
{
	number_of_notches_on_rifle = notches_on_rifle;
	combat_readiness_time = readiness_time;
}


Gunslinger::~Gunslinger()
{
}


double Gunslinger::Draw()
{
	return combat_readiness_time;
}


void Gunslinger::Show()
{
	Person::Show();

	std::cout << "Number of notches on a rifle " << number_of_notches_on_rifle << "\n";
	std::cout << "Combat readiness time " << combat_readiness_time << "\n";
}
