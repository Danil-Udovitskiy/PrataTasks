// Sum_of_digits(CodeAbbey).cpp 

//number to string conversion
#include <iostream>
#include <sstream> // stringstream
#include <string>
#include <vector>

int main()
{
	int size = 0, a = 0, b = 0, c = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;

	std::vector<int> results;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter 3 values : ";
		std::cin >> a >> b >> c;

		int result = (a * b) + c;

		std::stringstream stream;
		stream << result;
		std::string str;
		stream >> str;

		int sum = 0;
		for (int i = 0; i < str.size(); i++)
		{
			int number = (str[i] - 48);
			sum += number;
		}

		results.push_back(sum);
	}

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}
}
