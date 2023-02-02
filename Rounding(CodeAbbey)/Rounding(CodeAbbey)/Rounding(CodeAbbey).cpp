// Rounding(CodeAbbey).cpp 

#include <iostream>

int main()
{
	int size = 0;
	double	first = 0, second = 0;

	std::cout << "Enter numbers of pairs to get min: ";
	std::cin >> size;

	double result = 0;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter 2 values :";
		std::cin >> first >> second;

		result = first / second;
		std::cout << round(result) << "\n";
	}
}