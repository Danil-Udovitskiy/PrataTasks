// Collatz_sequence(CodeAbbey).cpp

#include <iostream>
#include <vector>

int main()
{
	int size = 0;
	std::cout << "Enter size : ";
	std::cin >> size;

	std::vector<int>results;

	for (int i = 0; i < size; i++)
	{
		//std::cout << "Enter number : ";
		int number = 0;
		std::cin >> number;

		int counter = 0;

		while (number != 1)
		{
			if (number % 2 == 0)
			{
				number = number / 2;
			}
			else
			{
				number = 3 * number + 1;
			}
			counter++;
		}
		results.push_back(counter);
	}

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}
}