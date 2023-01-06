// Chapter 17 Task 1.cpp 

#include <iostream>

int main()
{
	int counter = 0;

	std::cout << "Enter symbols :\n";

	//using the peek() function, we return the next input character without extracting it from the input stream
	while (std::cin.peek() != '$') // "look" ahead
	{
		//read all symbols (read enter like symbol too)
		std::cin.get();
		counter++;
	}

	std::cout << "Total symbols before \"$\" = " << counter << "\n";
}