// Chapter_18_Task_2.cpp 

#include <iostream>
#include "Cpmv.h"

int main()
{
	Cpmv first;
	first.Display();

	std::string word1 = "hi";
	std::string word2 = "bye";

	std::cout << "\n-------------------------\n";
	Cpmv second(word1, word2);
	second.Display();

	std::cout << "\n-------------------------\n";
	Cpmv third = second; //copy constructor
	third.Display();

	std::cout << "\n-------------------------\n";
	Cpmv fourth; 
	fourth = second; // assignment operation with copy
	fourth.Display();

	std::cout << "\n-------------------------\n";
	Cpmv five = (second + third); //operator+() function
	five.Display();

	std::cout << "\n-------------------------\n";
}
