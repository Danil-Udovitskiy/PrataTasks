// Chapter 14 Task 4.cpp 

#include <iostream>
#include "Person.h"
#include <cstring>
const int SIZE = 3;
int main()
{
	/*
	//Testing Person class
	Person Andy;
	Andy.Show();

	Person Jack("Jack", "Pet");
	Jack.Show();


	//Testing Gunslinger class
	std::cout << "\nGunslinger\n";
	Gunslinger sniper1;
	sniper1.Show();

	Gunslinger sniper2("Roko", "One", 5, 1.08);
	sniper2.Show();


	//Testing PokerPlayer class
	std::cout << "\nPokerPlayer\n";
	PokerPlayer player1;
	player1.Show();

	PokerPlayer player2("Flesh", "Poker");
	player2.Show();


	//Testing BadDude class
	std::cout << "\nBadDude\n";
	BadDude dude1;
	dude1.Show();

	BadDude dude2("Kiko", "Po", 6, 3.10, 1.2);
	dude2.Show();*/



	//Листинг 14.12
// workmi.срр — множественное наследование
//Listing 14.12
//multiple inheritance

	using std::strchr;
	Person* lolas[SIZE]; //создал очередь указателей на Person


	//тестирую создание объекта Waiter от АБС Worker
	//testing the creation of the Waiter object from the ABS Worker
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;

		std::cout << "Enter the employee category:\n" // enter the employee category;
			<< "p: person  G: gunslinger "
			<< " P: poker B: bad dude (q - exit) ";
		std::cin >> choice;
		while (strchr("PGPPBD", choice) == NULL)
		{
			std::cout << "Please enter P / G / PP / BD (q - exit) : ";
			std::cin >> choice;
		}
		if (choice == 'q')

			switch (choice)
			{
			case 'P': lolas[ct] = new Person;
				break;

			case 'G': lolas[ct] = new Gunslinger;
				break;

			case 'PP': lolas[ct] = new PokerPlayer;
				break;

			case 'BD': lolas[ct] = new BadDude;
				break;
			}

	}
	std::cin.get();
	//lolas[ct]->Set();

	std::cout << "\nHere is your staff:\n"; // вывод списка работников 
	std::cout << "\nHere is your staff:\n"; // output the list of employees
	int i;
	for (i = 0; i < ct; i++)
	{
		std::cout << "\n";
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	"Bye.\n";
}
