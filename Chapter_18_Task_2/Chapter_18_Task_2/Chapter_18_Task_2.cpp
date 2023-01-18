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
	//if we have transfer constructor it calls first
	//but if we have nat transfer constructor - calls copy constructor without transfer
	five.Display();

	std::cout << "\n-------------------------\n";
	//if we have transfer constructor it calls first
	//but if we have not transfer constructor - calls copy constructor without transfer
	Cpmv six(third + second); // call the transfer constructor 
	six.Display();

	std::cout << "\n-------------------------\n";
	//if we have assignment with transfer it calls first
	//but if we have not assignment with transfer - calls assignment operation with copy
	Cpmv seven;
	seven = third + second; // automatic assignment with transfer
	seven.Display();
	std::cout << "\n-------------------------\n";
}
