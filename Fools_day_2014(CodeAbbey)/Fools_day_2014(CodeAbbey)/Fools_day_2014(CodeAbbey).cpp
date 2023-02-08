// Fools_day_2014(CodeAbbey).cpp

//converting a(numeric) string to numbers
#include <iostream>
#include <sstream> // stringstream
#include <string>
#include <vector>

int main()
{
	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;
	std::cin.ignore();

	std::string str;

	std::vector<int> results;

	for (int i = 0; i < size; i++)
	{
		std::getline(std::cin, str);

		std::stringstream stream;
		stream << str; // insert a (numeric) article into the stream

		std::vector<int> converted_data;

		int number = 0;
		while (stream >> number)
		{
			converted_data.push_back(number);
		}

		int sum = 0;

		for (int i = 0; i < converted_data.size(); i++)
		{
			sum += (converted_data[i] * converted_data[i]);
		}

		results.push_back(sum);
	}

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}
}