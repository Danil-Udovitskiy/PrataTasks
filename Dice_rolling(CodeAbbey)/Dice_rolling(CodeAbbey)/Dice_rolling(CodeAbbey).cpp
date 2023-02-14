// Dice_rolling(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;

	double value = 0.0;

	std::vector<int>results;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter value : ";
		std::cin >> value;
		int result = (value * 6) + 1;
		results.push_back(result);
	}

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}
}