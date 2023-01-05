// Chapter 17 Task 1.cpp 

#include <iostream>

int main()
{

	char symbol;
	int counter = 0;


	std::cout << "Enter symbol : ";
	while (std::cin >> symbol && symbol != '$')
	{
		counter++;
		std::cout << "Enter next symbol : ";
	}

	std::cout << "Total symbols = " << counter << "\n";

}
