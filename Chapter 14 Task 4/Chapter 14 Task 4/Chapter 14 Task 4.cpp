// Chapter 14 Task 4.cpp 

#include <iostream>
#include "Person.h"


int main()
{
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

}
