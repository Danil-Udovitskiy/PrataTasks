// Fibonacci_sequence(CodeAbbey).cpp

#include <iostream>
#include <vector>
#include <cmath> 

int main()
{
	double number = 0;

	std::vector<double>Fibonachi(2);
	Fibonachi[0] = 0;
	Fibonachi[1] = 1;

	for (int i = 2; i < 1000; i++)
	{
		number = (Fibonachi[i - 2] + Fibonachi[i - 1]);
		Fibonachi.push_back(number);
	}

	double value = 0.0;
	int size = 0;
	std::vector<int>Indexes;

	std::cout << "Enter size : ";
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter value : ";
		std::cin >> value;

		for (int i = 0; i < Fibonachi.size(); i++)
		{
			if (std::abs(value - Fibonachi[i]) <= value * 0.00001)
			{
				Indexes.push_back(i);
				break;
			}
		}
	}

	for (int i = 0; i < Indexes.size(); i++)
	{
		std::cout << Indexes[i] << " ";
	}
}