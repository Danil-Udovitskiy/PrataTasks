// Chapter 14 Task 4.cpp 


#include <iostream>
#include "Person.h"
#include <cstring>

//Listing 14.12
//multiple inheritance

const int SIZE = 5;
int main()
{

	using std::strchr;
	Person* lolas[SIZE]; //array of pointers to Person


	//testing the creation of the Person, Gunslinger, PokerPlayer, BadDude objects
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;

		std::cout << "Enter the category:\n"
			<< "p: person  g: gunslinger  o: poker  b: bad dude  (q - exit) ";
		std::cin >> choice;
		while (strchr("pgobq", choice) == NULL)
		{
			std::cout << "Please enter p / g / o / b  (q - exit) : ";
			std::cin >> choice;
		}
		if (choice == 'q')
			break;

		switch (choice)
		{
		case 'p': lolas[ct] = new Person;
			break;

		case 'g': lolas[ct] = new Gunslinger;
			break;

		case 'o': lolas[ct] = new PokerPlayer;
			break;

		case 'b': lolas[ct] = new BadDude;
			break;
		}


		std::cin.get();
		lolas[ct]->Set();
	}

	std::cout << "\nHere is persons:\n"; // output the list of objects
	int i;
	for (i = 0; i < ct; i++)
	{
		std::cout << "\n";
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	
	std::cout << "Bye.\n";
	return 0;
}
