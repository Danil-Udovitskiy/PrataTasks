// Sums_in_loop(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
	int size = 0;
	std::cout << "Enter number of pairs: ";
	std::cin >> size;

	int first = 0, second = 0, sum = 0;

	std::vector<int> sums;


	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter 2 values to add :";
		std::cin >> first >> second;
		sum = first + second;
		sums.push_back(sum);
	}


	for (int a = 0; a < sums.size(); a++)
	{
		std::cout << sums[a] << "\n";
	}
}