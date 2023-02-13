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
				int even = number / 2;
				number = even;
				counter++;
			}
			else
			{
				int odd = 3 * number + 1;
				number = odd;
				counter++;
			}
		}
		results.push_back(counter);
	}

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}
}