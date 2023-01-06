// Chapter 17 Task 1.cpp 

#include <iostream>

int main()
{
	char symbol;
	int counter = 0;

	std::cout << "Enter symbols : ";

	//using the peek() function, we return the next input character without extracting it from the input stream
	while (symbol = std::cin.peek() != '$') // "look" ahead
	{
		std::cin.get(symbol);
		
		//do not read one enter (only after any symbol)
		if (symbol != '\n')
		{
			counter++;
		}
		else
		{
			std::cout << "Enter next symbols : ";
		}
	}

	std::cout << "Total symbols before \"$\" = " << counter << "\n";
}