// Average_of_an_array(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
	int size = 0;
	int number = 0;
	double avarage = 0.0;

	std::cout << "Enter number of values : ";
	std::cin >> size;

	std::vector<int>results;

	for (int i = 0; i < size; i++)
	{
		std::vector<int> vec;
		std::cout << "Enter numbers separated by spaces:\n";
		while (std::cin >> number)
		{
			vec.push_back(number);
			if (std::cin.get() == '\n')
				break;
		}

		double sum = 0.0;
		for (int i = 0; i < vec.size(); i++)
		{
			sum = sum + vec[i];
		}

		avarage = sum / (vec.size()-1);

		results.push_back(round(avarage));
	}

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}

	std::cout << "\n";
}