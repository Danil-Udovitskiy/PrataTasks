#include "Person.h"
#include <stdlib.h> // rand
#include <time.h> // time


Person::Person()
{
}

Person::Person(const std::string n, const std::string s_n)
{
	name = n;
	second_name = s_n;
}


void Person::Get()
{
	std::cout << "Enter name : ";
	std::getline(std::cin, name);
	std::cout << "Enter second name : ";
	std::getline(std::cin, second_name);
}


void Person::Set()
{
	Get();
}


Person::~Person()
{
}


void Person::Show()const
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


double Gunslinger::Draw()const
{
	return combat_readiness_time;
}


void Gunslinger::Show()const
{
	Person::Show();

	std::cout << "Number of notches on a rifle " << number_of_notches_on_rifle << "\n";
	std::cout << "Combat readiness time " << combat_readiness_time << "\n";
}


void Gunslinger::Get()
{
	Person::Get();
	std::cout << "Enter number of notches on rifle : ";
	std::cin >> number_of_notches_on_rifle;
	std::cout << "Enter combat readiness time ";
	std::cin >> combat_readiness_time;
}


void Gunslinger::Set()
{
	Get();
}



//+++
//PokerPlayer
PokerPlayer::PokerPlayer() : Person()
{
}

PokerPlayer::~PokerPlayer()
{
}


unsigned int PokerPlayer::Draw()const
{
	// To get different initial values in the srand() function, use the time() function
	// Set the starting point for generating the sequence
	// use the function time(nullptr)
	srand(time(nullptr)); 
	return (0 + rand() % 52); // return unsigned int 1-52
}

void PokerPlayer::Show()const
{
	Person::Show();
	std::cout << "Random card number: " << Draw() << "\n";
}


void PokerPlayer::Set()
{
	Person::Get();
}



//+++
//BadDude
BadDude::BadDude() : Person(), Gunslinger(), PokerPlayer()
{
	weapon_draw_time = 0.0;
}


BadDude::~BadDude()
{
}


double BadDude::Gdraw()const
{
	return weapon_draw_time;
}


unsigned int BadDude::Cdraw()const
{
	// To get different initial values in the srand() function, use the time() function
	// Set the starting point for generating the sequence
	// use the function time(nullptr)
	srand(time(nullptr));
	return (0 + rand() % 52); // return unsigned int 1-52
}


void BadDude::Show()const
{
	Gunslinger::Show();
	std::cout << "Next random card number: " << Cdraw() + 1 << "\n";
	std::cout << "Weapon drawtime " << weapon_draw_time << "\n";
}


void BadDude::Get()
{
	Gunslinger::Get();
	std::cout << "Enter weapon drawtime : ";
	std::cin >> weapon_draw_time;
}


void BadDude::Set()
{
	Get();
}




