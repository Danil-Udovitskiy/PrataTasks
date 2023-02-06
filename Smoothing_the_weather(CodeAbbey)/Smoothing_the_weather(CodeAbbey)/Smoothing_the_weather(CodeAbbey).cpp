// Smoothing_the_weather(CodeAbbey).cpp 

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 

int main()
{
	int size = 0;
	std::cout << "Enter number of values(temp): ";
	std::cin >> size;

	double temp = 0.0;

	std::vector<double> temperatures;

	for (int i = 0; i < size; i++)
	{
		std::cin >> temp;
		temperatures.push_back(temp);
	}


	std::vector<double> temperatures_temp(size);
	temperatures_temp[0] = temperatures[0];
	temperatures_temp.back() = temperatures.back();

	for (int i = 1; i < temperatures.size() - 1; i++)
	{
		temperatures_temp[i] = (temperatures[i - 1] + temperatures[i] + temperatures[i + 1]) / 3;
	}

	for (int i = 0; i < temperatures_temp.size(); i++)
	{
		std::cout << std::setprecision(12) << temperatures_temp[i] << " ";
	}
}