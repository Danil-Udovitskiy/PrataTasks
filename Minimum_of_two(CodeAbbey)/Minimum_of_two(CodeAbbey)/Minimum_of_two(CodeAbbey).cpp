// Minimum_of_two(CodeAbbey).cpp 

#include <iostream>

int main()
{
	int size = 0, first = 0, second = 0;

	std::cout << "Enter numbers of pairs to get min: ";
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter 2 values :";
		std::cin >> first >> second;
		if (first < second)
		{
			std::cout << "Min is " << first << "\n";
		}
		else
		{
			std::cout << "Min is " << second << "\n";
		}
	}
}
