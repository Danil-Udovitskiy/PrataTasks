// Weighted_sum_of_digits(CodeAbbey).cpp 
#include <iostream>
#include <vector>
#include <string>


int main()
{
	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;

	std::cin.ignore();

	std::string number;

	std::vector<int>weighted_sums;


	for (int i = 0; i < size; i++)
	{
		int wsd = 0; //weighted sum of digits

		//std::cout << "Enter number : ";
		std::cin >> number;

		// int position = 1 serial number in the number
		for (int j = 0, position = 1; j < number.size(); j++, position++)
		{
			wsd += ((int)number[j] - 48) * position; //char 1 = cod 49(then remainder of subtract convert to int)
		}

		weighted_sums.push_back(wsd);
	}

	for (int i = 0; i < weighted_sums.size(); i++)
	{
		std::cout << weighted_sums[i] << " ";
	}
}