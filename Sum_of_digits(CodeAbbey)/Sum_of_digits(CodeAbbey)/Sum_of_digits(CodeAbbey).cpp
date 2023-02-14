// Sum_of_digits(CodeAbbey).cpp 

#include <iostream>
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

		int sum = 0;
		int remainder = 0;

		while (result != 0) 
		{
			remainder = result % 10; //remainder from dividing the number by 10
			result = result / 10;
			sum += remainder; //the remainder is the last digit in the number
		}
		
		results.push_back(sum);
	}

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}
}





//Old problem solution
//number to string conversion

//#include <sstream> // stringstream
//#include <string>

/*int main()
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
}*/