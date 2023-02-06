// Median_of_three(CodeAbbey).cpp

#include <iostream>

int main()
{
	int size = 0, first = 0, second = 0, third = 0;

	std::cout << "Enter numbers of pairs to get middle: ";
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter 3 values :";
		std::cin >> first >> second >> third;

		if (first > second && first < third || first < second && first > third)
		{
			std::cout << "Middle is " << first << "\n";
		}

		else if (second > first && second < third || second < first && second > third)
		{
			std::cout << "Middle is " << second << "\n";
		}

		else
		{
			std::cout << "Middle is " << third << "\n";
		}
	}
}