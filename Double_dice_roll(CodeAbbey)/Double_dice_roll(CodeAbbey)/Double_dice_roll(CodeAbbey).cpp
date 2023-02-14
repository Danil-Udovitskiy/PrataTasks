// Double_dice_roll(CodeAbbey).cpp 

#include <iostream>
#include <vector>
int main()
{
	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;

	int random_value1 = 0;
	int random_value2 = 0;

	std::vector<int>sums;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter value : ";
		std::cin >> random_value1 >> random_value2;

		//get the remainder after dividing the random number by 6
		int result1 = (random_value1 % 6) + 1;
		int result2 = (random_value2 % 6) + 1;

		int sum = result1 + result2;

		sums.push_back(sum);
	}

	for (int i = 0; i < sums.size(); i++)
	{
		std::cout << sums[i] << " ";
	}
}